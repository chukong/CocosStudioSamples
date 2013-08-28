#include "TestColliderDetector.h"



TestColliderDetector::~TestColliderDetector()
{
	CCArmatureDataManager::purge();
}
void TestColliderDetector::onEnter()
{
	CCLayer::onEnter();
	scheduleUpdate();
    
	//! load data
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Cowboy.ExportJson");

	//! create armature
	armature = cocos2d::extension::CCArmature::create("Cowboy");
	armature->getAnimation()->play("FireWithoutBullet");
	armature->getAnimation()->setSpeedScale(0.2f);
	armature->setScaleX(-0.2f);
	armature->setScaleY(0.2f);
	armature->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width * 0.2, CCDirector::sharedDirector()->getVisibleSize().height * 0.5));
    
	//! bind armature's frame event to onFrameEvent
	armature->getAnimation()->setFrameEventCallFunc(this, frameEvent_selector(TestColliderDetector::onFrameEvent));
    
	addChild(armature);
    
	//! create armature2
	armature2 = cocos2d::extension::CCArmature::create("Cowboy");
	armature2->getAnimation()->play("Walk");
	armature2->setScaleX(-0.2f);
	armature2->setScaleY(0.2f);
	armature2->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width * 0.8, CCDirector::sharedDirector()->getVisibleSize().height * 0.5));
	addChild(armature2);
	
	//! add a CCPhysicsSprite,will show in FrameEvent
	bullet = CCPhysicsSprite::createWithSpriteFrameName("25.png");
	addChild(bullet);
    
	initWorld();
}

void TestColliderDetector::onFrameEvent(CCBone *bone, const char *evt, int originFrameIndex, int currentFrameIndex)
{
    //! get position of gun(layer126)
	CCPoint p = armature->getBone("Layer126")->getDisplayRenderNode()->convertToWorldSpaceAR(ccp(0, 0));
    
	//! add position and action to bullet
	bullet->setPosition(ccp(p.x + 60, p.y));
	bullet->stopAllActions();
	bullet->runAction(CCMoveBy::create(1.5f, ccp(350, 0)));
}



#if ENABLE_PHYSICS_BOX2D_DETECT

class Contact
{
public:
	b2Fixture *fixtureA;
	b2Fixture *fixtureB;
};

class ContactListener : public b2ContactListener
{
	//! Callbacks for derived classes.
	virtual void BeginContact(b2Contact *contact)
	{
		if (contact)
		{
            //! add contact's fixture into list
			Contact c;
			c.fixtureA = contact->GetFixtureA();
			c.fixtureB = contact->GetFixtureB();
            
			contact_list.push_back(c);
		}
		B2_NOT_USED(contact);
	}
	virtual void EndContact(b2Contact *contact)
	{
        //! clear list at end
		contact_list.clear();
		B2_NOT_USED(contact);
	}
	virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(oldManifold);
	}
	virtual void PostSolve(const b2Contact *contact, const b2ContactImpulse *impulse)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(impulse);
	}
    
public:
	std::list<Contact> contact_list;
};


void TestColliderDetector::onExit()
{
	CC_SAFE_DELETE(world);
	CC_SAFE_DELETE(listener);
	CC_SAFE_DELETE(debugDraw);
    
	CCLayer::onExit();
}
void TestColliderDetector::draw()
{
	ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
	kmGLPushMatrix();
	world->DrawDebugData();
	kmGLPopMatrix();
}
void TestColliderDetector::update(float delta)
{
	armature2->setVisible(true);
    
	world->Step(delta, 0, 0);
    
	for (std::list<Contact>::iterator it = listener->contact_list.begin(); it != listener->contact_list.end(); ++it)
	{
		Contact &contact = *it;
        //! get armature by fixtrue's user data
		CCBone *ba = (CCBone *)contact.fixtureA->GetUserData();
		CCBone *bb = (CCBone *)contact.fixtureB->GetUserData();

		bb->getArmature()->setVisible(false);
	}
}
void TestColliderDetector::initWorld()
{
    //! init physic world
	b2Vec2 noGravity(0, 0);
    
	world = new b2World(noGravity);
	world->SetAllowSleeping(true);
    
	listener = new ContactListener();
	world->SetContactListener(listener);
    
	debugDraw = new GLESDebugDraw( PT_RATIO );
	world->SetDebugDraw(debugDraw);
    
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	//        flags += b2Draw::e_jointBit;
	//        flags += b2Draw::e_aabbBit;
	//        flags += b2Draw::e_pairBit;
	//        flags += b2Draw::e_centerOfMassBit;
	debugDraw->SetFlags(flags);
    
    
	//! Define the dynamic body.
	//! Set up a 1m squared box in the physics world
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
    
	b2Body *body = world->CreateBody(&bodyDef);
    
	//! Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
    //define bullet's body shape
	dynamicBox.SetAsBox(.5f, .5f);
    
	//! Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.isSensor = true;
	body->CreateFixture(&fixtureDef);
    
    //! set body to bullet and add it to world
	bullet->setB2Body(body);
	bullet->setPTMRatio(PT_RATIO);
	bullet->setPosition( ccp( -100, -100) );
    
	body = world->CreateBody(&bodyDef);
	armature2->setB2Body(body);
}

#elif ENABLE_PHYSICS_CHIPMUNK_DETECT

enum ColliderType
{
	eBulletTag,
	eEnemyTag
};


int TestColliderDetector::beginHit(cpArbiter *arb, cpSpace *space, void *unused)
{
	CP_ARBITER_GET_SHAPES(arb, a, b);
    
	CCBone *bone = (CCBone*)a->data;
	bone->getArmature()->setVisible(false);
    
	return 0;
}

void TestColliderDetector::endHit(cpArbiter *arb, cpSpace *space, void *unused)
{
	CP_ARBITER_GET_SHAPES(arb, a, b);
    
	CCBone *bone = (CCBone*)a->data;
	bone->getArmature()->setVisible(true);
}

void TestColliderDetector::destroyCPBody(cpBody *body)
{
	cpShape *shape = body->shapeList_private;
	while(shape)
	{
		cpShape *temp = shape->next_private;
        
		cpSpaceRemoveShape(space, shape);
		cpShapeFree(shape);
        
		shape = temp;
	}
    
	cpSpaceRemoveBody(space, body);
	cpBodyFree(body);
}

void TestColliderDetector::onExit()
{
	destroyCPBody(armature2->getCPBody());
	destroyCPBody(bullet->getCPBody());
    
	cpSpaceFree(space);
    
	CCLayer::onExit();
}

void TestColliderDetector::update(float delta)
{
	cpSpaceStep(space, delta);
}
void TestColliderDetector::initWorld()
{
    //! create physic space
	space = cpSpaceNew();
    //! set space gravity as no gravity
	space->gravity = cpv(0, 0);
    
	//! Physics debug layer
	CCPhysicsDebugNode *debugLayer = CCPhysicsDebugNode::create(space);
	this->addChild(debugLayer, INT_MAX);
    
    //! get size of bullet
	CCSize size = bullet->getContentSize();
    
    //! define bullet's collider body
	int num = 4;
	cpVect verts[] = {
		cpv(-size.width/2,-size.height/2),
		cpv(-size.width/2,size.height/2),
		cpv(size.width/2,size.height/2),
		cpv(size.width/2,-size.height/2),
	};
    
    //! build body as verts' shape
	cpBody *body = cpBodyNew(1.0f, cpMomentForPoly(1.0f, num, verts, cpvzero));
	cpSpaceAddBody(space, body);
    
	cpShape* shape = cpPolyShapeNew(body, num, verts, cpvzero);
	shape->collision_type = eBulletTag;
	cpSpaceAddShape(space, shape);
    
	bullet->setCPBody(body);
    
    //! define armature2's body,get shape from armature data
	body = cpBodyNew(INFINITY, INFINITY);
	cpSpaceAddBody(space, body);
	armature2->setCPBody(body);
    
	shape = body->shapeList_private;
	while(shape){
		cpShape *next = shape->next_private;
		shape->collision_type = eEnemyTag;
		shape = next;
	}
    
	cpSpaceAddCollisionHandler(space, eEnemyTag, eBulletTag, beginHit, NULL, NULL, endHit, NULL);
}
#endif