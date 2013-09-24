#include "Enemy.h"

using namespace cocos2d;
using namespace cocos2d::extension;

bool Enemy::init()
{
	if(!CCLayer::init()) return false;

	scheduleUpdate();

	return true;
}

void Enemy::update(float delta)
{
	this->setZOrder((int)CCDirector::sharedDirector()->getVisibleSize().height - enemyArmature->getPosition().y);
}

void Enemy::onExit()
{
	unscheduleUpdate();
	CCLayer::onExit();
}



KnightEnemy* KnightEnemy::create(CCPoint startPostion,
		int HP,float scaleX,float scaleY)
{
	KnightEnemy *pRet = new KnightEnemy();
    if (pRet && pRet->init(startPostion,
		HP,scaleX,scaleY))
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

bool KnightEnemy::init(CCPoint startPostion,
		int HP,float scaleX,float scaleY)
{
	if(!Enemy::init()) return false;

	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/hero/Hero.ExportJson");
	enemyArmature = CCArmature::create("Hero");
	enemyArmature->getAnimation()->playByIndex(1);

	hitPoints = HP;
	enemyArmature->setPosition(startPostion);
	enemyArmature->setScaleX(scaleX);
	enemyArmature->setScaleY(scaleY);
	this->addChild(enemyArmature);
	
	return true;
}

void KnightEnemy::beHitted()
{
	hitPoints -= 10;
}

void KnightEnemy::defineAction(CCAction* action)
{
	if(action == NULL)
	{
        //define knightenemy form right to left
        CCActionInterval* actionToLeft = CCMoveBy::create(5,ccp(CCDirector::sharedDirector()->getVisibleSize().width * -1.3,0));
        CCActionInterval* actionScaleN = CCScaleTo::create(0.3, -0.5, 0.5);
        CCActionInterval* actionScaleP = CCScaleTo::create(0.3, 0.5, 0.5);
        CCActionInterval* actionToRight = CCMoveBy::create(5,ccp(CCDirector::sharedDirector()->getVisibleSize().width * 1.3,0));
        action = CCRepeatForever::create(CCSequence::create(actionToRight,actionScaleN,actionToLeft,actionScaleP,NULL));
	}
	enemyArmature->runAction(action);
}


RobotEnemy* RobotEnemy::create(CCPoint startPostion,
		int HP,float scaleX,float scaleY)
{
	RobotEnemy *pRet = new RobotEnemy();
    if (pRet && pRet->init(startPostion,
		HP,scaleX,scaleY))
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

bool RobotEnemy::init(CCPoint startPostion,
		int HP,float scaleX,float scaleY)
{
	if(!Enemy::init()) return false;
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/monster/MonsterEnemy.ExportJson");

	enemyArmature = CCArmature::create("MonsterEnemy");
	enemyArmature->getAnimation()->playByIndex(1);

	hitPoints = HP;
	enemyArmature->setPosition(startPostion);
	enemyArmature->setScaleX(scaleX);
	enemyArmature->setScaleY(scaleY);
	this->addChild(enemyArmature);
	
	return true;
}

void RobotEnemy::beHitted()
{
	hitPoints -= 10;
}