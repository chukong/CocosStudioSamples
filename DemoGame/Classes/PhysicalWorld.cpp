#include "PhysicalWorld.h"


using namespace cocos2d;
using namespace cocos2d::extension;

#define GLES_DEBUG_DRAW 1

PhysicalWorld* PhysicalWorld::create(EnemyListBuilder* pBuilder,
		Player* pPlayer)
{
	PhysicalWorld *pRet = new PhysicalWorld();
    if (pRet && pRet->init(pBuilder,
		pPlayer))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool PhysicalWorld::init(EnemyListBuilder* pBuilder,
		Player* pPlayer)
{
	if(!CCLayer::init()) return false;

	initPhysics();

	initPlayer(pPlayer);

	initEnemy(pBuilder);

	scheduleUpdate();
	return true;
}

void PhysicalWorld::initPhysics()
{
	//create world without gravity
	b2Vec2 gravity(0,0);
	world = new b2World(gravity);

	world->SetAllowSleeping(true);
	
	// owner contact listener
	contactListener = new MyContactListener();
	world->SetContactListener(contactListener);

	MyContactFilter* contactFilter = new MyContactFilter();
	world->SetContactFilter(contactFilter);

#if GLES_DEBUG_DRAW
	//show collision boxes

	debugDraw = new GLESDebugDraw( PT_RATIO );
	world->SetDebugDraw(debugDraw);
    
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
    
	debugDraw->SetFlags(flags);
#endif
}

void PhysicalWorld::initPlayer(Player* pPlayer)
{
	player = pPlayer;
	if(player == NULL)	player = Player::create();

	addChild(player);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world->CreateBody(&bodyDef);
	player->getArmature()->setBody(body);

	setPlayerFilterInfo(body);

	//bind frame event to player
	player->getArmature()->getAnimation()->setFrameEventCallFunc(
		this,frameEvent_selector(PhysicalWorld::onFrameEvent));
}

void PhysicalWorld::setPlayerFilterInfo(b2Body* body)
{
	b2Fixture *fixture = body->GetFixtureList();
	if(fixture != NULL) 
	{
		fixture->SetUserData(player);
		b2Filter filter = fixture->GetFilterData();
		filter.categoryBits = PLAYER;
		filter.groupIndex = PLAYER_GROUPINDEX;
		fixture->SetFilterData(filter);
	}
}


void PhysicalWorld::initEnemy(EnemyListBuilder* pBuilder)
{
	if(pBuilder == NULL) return;

	enemyListBuilder = pBuilder;

	while(!enemyListBuilder->IsTraverseListFinished())
	{
		addEnemyIntoWorld(enemyListBuilder->GetEnemy());
	}
}

void PhysicalWorld::addEnemyIntoWorld(Enemy* pEnemy)
{
	addChild(pEnemy);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world->CreateBody(&bodyDef);
	pEnemy->getArmature()->setBody(body);

	setEnemyFilterInfo(body,pEnemy);
}
void PhysicalWorld::setEnemyFilterInfo(b2Body* body,Enemy* pEnemy)
{
	b2Fixture *fixture = body->GetFixtureList();
	if(fixture != NULL) 
	{
		fixture->SetUserData(pEnemy);
		b2Filter filter = fixture->GetFilterData();
		filter.categoryBits = ENEMY;
		filter.groupIndex = ENEMY_GROUPINDEX;
		fixture->SetFilterData(filter);
	}
}

void PhysicalWorld::onFrameEvent(CCBone *bone, const char *evt, 
		int originFrameIndex, int currentFrameIndex)
{
	//define bullet action
	CCActionInterval* bulletAction;
	CCPoint startPosition = player->getArmature()->getPosition();
	if(player->getArmature()->getScaleX() > 0)
	{
		bulletAction = CCMoveBy::create(1.5f,ccp(-450,0));
		startPosition.x -= 50;	//hands length
	}
	else 
	{
		startPosition.x += 50;
		bulletAction = CCMoveBy::create(1.5f,ccp(450,0));
	}

	createBullet(startPosition,bulletAction);
}


void PhysicalWorld::createBullet(CCPoint startPosition,CCActionInterval* bulletAction)
{
	CCPhysicsSprite* bullet = CCPhysicsSprite::create("bullet.png");

	// Define the dynamic body.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Body *body = world->CreateBody(&bodyDef);
    
	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	//the collision box size of bullet
	dynamicBox.SetAsBox(0.4f, 0.4f);
	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.isSensor = true;
    fixtureDef.userData = bullet;

    
	body->CreateFixture(&fixtureDef);
    
	bullet->setB2Body(body);
	bullet->setPTMRatio(PT_RATIO);
    bullet->setPosition(ccp(startPosition.x, startPosition.y));

	setBulletFilterInfo(body,bullet);

	this->addChild(bullet);
	
	CCFiniteTimeAction* action = CCSequence::create(bulletAction,
		CCCallFuncND::create(this,callfuncND_selector(PhysicalWorld::destroyBullet),(void*)body),NULL);

	bullet->runAction(action);
}

void PhysicalWorld::setBulletFilterInfo(b2Body* body,CCPhysicsSprite* bullet)
{
	b2Fixture *fixture = body->GetFixtureList();
	if(fixture != NULL) 
	{
		fixture->SetUserData(bullet);
		b2Filter filter = fixture->GetFilterData();
		filter.categoryBits = BULLET;
		filter.groupIndex = PLAYER_GROUPINDEX;
		fixture->SetFilterData(filter);
	}
}
void PhysicalWorld::destroyBullet(CCNode* sender,void* data)
{
	world->DestroyBody((b2Body*)data);
	sender->removeFromParentAndCleanup(true);
}


void PhysicalWorld::update(float delta)
{
	world->Step(delta, 0, 0);

	processContactList();

	processDiedEnemy();
}

void PhysicalWorld::processContactList()
{
	if(contactListener->isContactListEmpty()) return;

	Contact contact = contactListener->getListFront();
	
	b2Filter filter[2];
	for(int i = 0;i<2;i++)
	{
		filter[i] = contact.fixture[i]->GetFilterData();
		if(filter[i].categoryBits == ENEMY) 
		{
			Enemy* pEnemy = (Enemy*)contact.fixture[i]->GetUserData();
			pEnemy->beHitted();
		}
		else if(filter[i].categoryBits == PLAYER)
		{
			Player* pPlayer = (Player*)contact.fixture[i]->GetUserData();
			pPlayer->beHitted();
		}
		else if(filter[i].categoryBits == BULLET)
		{
			CCPhysicsSprite* pBullet = (CCPhysicsSprite*)contact.fixture[i]->GetUserData();
			pBullet->setVisible(false);
			contact.fixture[i]->GetBody()->SetActive(false);
		}
	}
	contactListener->clearContactList();
}

void PhysicalWorld::processDiedEnemy()
{
	if(enemyListBuilder->IsEnemyAllDied()) return;
	while (!enemyListBuilder->IsTraverseListFinished())
	{
		Enemy* pEnemy = enemyListBuilder->GetEnemy();
		if(pEnemy->IsEnemyDied()) destroyEnemy(pEnemy);
	}
}

void PhysicalWorld::destroyEnemy(Enemy* pEnemy)
{
	world->DestroyBody(pEnemy->getArmature()->getBody());
	enemyListBuilder->deleteEnemy(pEnemy);
	pEnemy->removeFromParentAndCleanup(true);
}



void PhysicalWorld::draw()
{
	ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
	kmGLPushMatrix();
	world->DrawDebugData();
	kmGLPopMatrix();
}

PhysicalWorld::~PhysicalWorld(void)
{
	unscheduleUpdate();
	CC_SAFE_DELETE(enemyListBuilder);
	CC_SAFE_DELETE(world);
	CC_SAFE_DELETE(contactListener);
	CC_SAFE_DELETE(debugDraw);
}


