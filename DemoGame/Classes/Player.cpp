#include "Player.h"

using namespace cocos2d;
using namespace cocos2d::extension;

enum
{
	DEFAULT = -1,
	STAND = 0,		//default state
	MOVING,
	STAND_ATTACK,
	MOVING_ATTACK,
	BE_HITTED,
	DEAD
};

Player* Player::create()
{
	Player *pRet = new Player();
    if (pRet && pRet->init())
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

bool Player::init()
{
	if(!CCLayer::init()) return false;

	initArmature();
	
	playerStateMachine = new PlayerStateMachine();

	setGameOver(false);
	lifeNum = 2;
	playerState = DEFAULT;
	playerRebirth();

	scheduleUpdate();
	return true;
}

void Player::initArmature()
{
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/player/player0.png",
		"armature/player/player0.plist","armature/player/player.ExportJson");
	playerArmature = CCArmature::create("player");
	playerArmature->setScaleX(-0.1);
	playerArmature->setScaleY(0.1);
	playerArmature->getAnimation()->play("stand");
	addChild(playerArmature);
	playerArmature->getAnimation()->setMovementEventCallFunc(this, 
		movementEvent_selector(Player::animationEvent));
}


void Player::playerRebirth()
{
	hitPonts = PLAYER_MAX_HP;
	playerArmature->setPosition(ccp(50,200));
	playerStateMachine->reset();
}

bool Player::IsLock()
{
	bool lock = 
		((playerState == BE_HITTED)|| (playerState == DEAD));
	return lock;
}


void Player::update(float delta)
{
	updatePosition();

	int state = playerStateMachine->getState();
	if((playerState == state) || IsLock())	return;

	else playerState = state;
	updateAnimation();
}

void Player::updatePosition()
{
	if(IsLock()) return;
	//update face direction
	if(playerStateMachine->getMovePosition().x > 0) 
		playerArmature->setScaleX(-0.1);
	else if(playerStateMachine->getMovePosition().x < 0)
		playerArmature->setScaleX(0.1);
	//update position
	CCPoint position = playerArmature->getPosition();
	CCPoint deltaPosition = playerStateMachine->getMovePosition();
	//the edge of screen
	if(((position.x >=20) && (deltaPosition.x <0)) ||
		((position.x <=720) && (deltaPosition.x >0)))
			position.x += deltaPosition.x*2;
		
	if(((position.y <= 200) && (deltaPosition.y >0)) ||
		((position.y >=50) && (deltaPosition.y <0)))
		position.y += playerStateMachine->getMovePosition().y*2;
	
	playerArmature->setPosition(position);
	this->setZOrder((int)CCDirector::sharedDirector()->getVisibleSize().height - position.y);
}

void Player::updateAnimation()
{
	switch (playerState)
	{
	case STAND:
		playerArmature->getAnimation()->play("stand");
		break;
	case MOVING:
		playerArmature->getAnimation()->play("walk");
		break;
	case STAND_ATTACK	:
		playerArmature->getAnimation()->play("stand_fire");
		break;
	case MOVING_ATTACK:
		playerArmature->getAnimation()->play("walk_fire");
		break;
	default:
		break;
	}
}

void Player::beHitted()
{
	//player is locked or still in default init
	if(IsLock() || (playerState == DEFAULT)) return;
	
	hitPonts -= 20;
	if(hitPonts > 0)
	{
		playerState = BE_HITTED;
		playerArmature->getAnimation()->play("hitted");
	}
	else
	{
		playerState = DEAD;
		playerArmature->getAnimation()->play("dead");
	}
}
void Player::animationEvent(CCArmature *pArmature,
							MovementEventType movementType, const char *movementID)
{
	std::string id = movementID;
	if(movementType == LOOP_COMPLETE)
	{
		if(id.compare("hitted") == 0)
		{
			playerState = DEFAULT;
		}
		if(id.compare("dead") == 0)
		{
			playerState = DEFAULT;
			if(lifeNum > 0) 
			{
				lifeNum--;
				playerRebirth();
			}
			else setGameOver(true);
		}
	}
}


Player::~Player(void)
{
	CC_SAFE_DELETE(playerStateMachine);
}



PlayerStateMachine::PlayerStateMachine()
{
	playerState = 0;
	pressJoystick = 0;
	pressButton = 0;
	movePosition = ccp(0,0);
}

int PlayerStateMachine::getState()
{
	if(pressJoystick)
	{
		if(pressButton)	playerState = MOVING_ATTACK;
		else playerState = MOVING;
	}
	else
	{
		if(pressButton) playerState = STAND_ATTACK;
		else playerState = STAND;
	}

	return playerState;
}


PlayerStateMachine::~PlayerStateMachine()
{
}


