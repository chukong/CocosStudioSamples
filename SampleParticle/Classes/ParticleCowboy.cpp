#include "ParticleCowboy.h"

void ParticleCowboy::onEnter()
{
	CCLayer::onEnter();
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Sample0.png","Sample0.plist","Sample.ExportJson");
	size = CCDirector::sharedDirector()->getVisibleSize();

	armature = cocos2d::extension::CCArmature::create("Sample");
	armature->getAnimation()->play("Fire");
	armature->setScaleX(-0.15f);
	armature->setScaleY(0.15f);
	armature->setPosition(ccp(50, size.height * 0.5));

	/*
	* Set armature's movement event callback function
	* To disconnect this event, just setMovementEventCallFunc(NULL, NULL);
	*/
	armature->getAnimation()->setMovementEventCallFunc(this, movementEvent_selector(ParticleCowboy::animationEvent));
	addChild(armature);
}

void ParticleCowboy::animationEvent(cocos2d::extension::CCArmature *armature, MovementEventType movementType, const char *movementID)
{
	std::string id = movementID;

	if (movementType == LOOP_COMPLETE)
	{
		if (id.compare("Fire") == 0)
		{
			CCActionInterval *actionToRight = CCMoveTo::create(5, ccp(size.width - 50, size.height * 0.5));
			armature->stopAllActions();
			armature->runAction(CCSequence::create(actionToRight,  CCCallFunc::create(this, callfunc_selector(ParticleCowboy::callback1)), NULL));
			armature->getAnimation()->play("Walk");
		}
		else if (id.compare("FireMax") == 0)
		{
			CCActionInterval *actionToLeft = CCMoveTo::create(5, ccp(50,size.height * 0.5));
			armature->stopAllActions();
			armature->runAction(CCSequence::create(actionToLeft,  CCCallFunc::create(this, callfunc_selector(ParticleCowboy::callback2)), NULL));
			armature->getAnimation()->play("Walk");
		}
	}
}
void ParticleCowboy::callback1()
{
	armature->runAction(CCScaleTo::create(0.3f, 0.15f, 0.15f));
	armature->getAnimation()->play("FireMax");
}
void ParticleCowboy::callback2()
{
	armature->runAction(CCScaleTo::create(0.3f, -0.15f, 0.15f));
	armature->getAnimation()->play("Fire");
}

void ParticleCowboy::onExit()
{

}