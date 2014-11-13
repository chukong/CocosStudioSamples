#include "Fishes.h"

using namespace cocos2d;
using namespace cocos2d::extension;

void Fishes::onEnter()
{
	CCLayer::onEnter();

	size = CCDirector::sharedDirector()->getVisibleSize();
	//2048*1536
	this->setScaleX(size.width/2048);
	this->setScaleY(size.height/1536);
	size.height = 1536;
	size.width = 2048;
}


void Fishes::onExit()
{
	removeAllChildren();
}

void Fish01::onEnter()
{
	Fishes::onEnter();

	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("fish010.png","fish010.plist","fish01.ExportJson");

	CCArmature* armature = CCArmature::create("fish01");
	armature->getAnimation()->playByIndex(0);
	armature->setPosition(ccp(0.1 * size.width,0.8*size.height));
	addChild(armature);
}

void Fish02::onEnter()
{
	Fishes::onEnter();

	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("fish020.png","fish020.plist","fish02.ExportJson");

	CCArmature* armature = CCArmature::create("fish02");
	armature->getAnimation()->playByIndex(0);
	armature->setPosition(ccp(size.width * 0.7,size.width * 0.4));
	armature->setScaleX(2.5);
	armature->setScaleY(2.5);
	armature->runAction(CCRepeatForever::create(CCRotateBy::create(5,360)));
	addChild(armature);
}

void Fish03::onEnter()
{
	Fishes::onEnter();

	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("fish030.png","fish030.plist","fish03.ExportJson");

	CCArmature* armature = CCArmature::create("fish03");
	armature->getAnimation()->playByIndex(0);
	armature->setPosition(ccp(150,150));
	addChild(armature);
}

void Fish04::onEnter()
{
	Fishes::onEnter();
	//create a sequence with a call back
	CCActionInterval* actionToUp = CCMoveTo::create(10.0,ccp(0.3 *size.width,size.height * -0.5));
	CCSequence* seq = CCSequence::create(actionToUp,CCCallFunc::create(this,callfunc_selector(Fish04::callback)),NULL);

	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("fish040.png","fish040.plist","fish04.ExportJson");
	
	armature = CCArmature::create("fish04");
	armature->setRotation(-90);
	armature->getAnimation()->playByIndex(0);
	armature->setPosition(ccp(0.3 * size.width,1.5*size.height));
	armature->runAction(CCRepeatForever::create(seq));
	addChild(armature);
}

void Fish04::callback()
{
	armature->setPosition(ccp(0.3 * size.width,1.5*size.height));
}


void Fish05::onEnter()
{
	Fishes::onEnter();
	CCActionInterval* actionToLeft = CCMoveTo::create(5,ccp(size.width * -0.3,size.height * 0.5));
	CCActionInterval* actionRotate = CCRotateBy::create(0,180);
	CCActionInterval* actionToRight = CCMoveTo::create(5,ccp(size.width * 1.3,size.height * 0.5));
	CCAction* action = CCRepeatForever::create(CCSequence::create(actionToLeft,actionRotate,actionToRight,actionRotate,NULL));

	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("fish050.png","fish050.plist","fish05.ExportJson");

	CCArmature* armature = CCArmature::create("fish05");
	armature->getAnimation()->playByIndex(0);
	armature->setPosition(ccp(size.width * 1.3,size.height * 0.5));
	armature->runAction(action);
	addChild(armature);
}

void Fish06::onEnter()
{
	Fishes::onEnter();
	//move and change direction
	CCActionInterval* actionToLeft = CCMoveTo::create(5,ccp(size.width * 0.3,size.height * 0.7));
	CCActionInterval* actionToDown = CCMoveTo::create(5,ccp(size.width * 0.3,size.height * -0.1));
	CCActionInterval* actionRotate = CCRotateBy::create(1,-90);
	CCActionInterval* actionToRight = CCMoveTo::create(5,ccp(size.width * 1.1,size.height * 0.7));
	CCActionInterval* actionRotate1 = CCRotateBy::create(1,-135);
	CCActionInterval* actionRotate2 = CCRotateBy::create(1,225);
	CCAction* action = CCRepeatForever::create(CCSequence::create(actionToLeft,actionRotate,actionToDown,actionRotate1,actionToRight,actionRotate2,NULL));
	//create armature and action set to repeat forever
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("fish060.png","fish060.plist","fish06.ExportJson");

	CCArmature* armature = CCArmature::create("fish06");
	armature->getAnimation()->playByIndex(0);
	armature->setPosition(ccp(size.width * 1.1,size.height * 0.7));
	armature->runAction(action);
	addChild(armature);
}

void Fish07::onEnter()
{
	Fishes::onEnter();
	//when arrive fate out and remove
	CCActionInterval* actionToUp = CCMoveTo::create(8,ccp(size.width * 0.7,size.height * 0.4));
	CCSequence* seq = CCSequence::create(actionToUp,CCCallFunc::create(this,callfunc_selector(Fish07::callback)),NULL);

	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("fish070.png","fish070.plist","fish07.ExportJson");

	armature = CCArmature::create("fish07");
	armature->getAnimation()->playByIndex(0);
	armature->setRotation(90);
	armature->setPosition(ccp(0.7 * size.width,-0.3));
	armature->runAction(seq);
	addChild(armature);
}

void Fish07::callback()
{
	armature->getAnimation()->playByIndex(1);
	armature->stopAllActions();
	armature->runAction(CCSequence::create(CCFadeOut::create(3.0),CCCallFunc::create(this,callfunc_selector(Fish07::removeSelf)),NULL));
}

void Fish07::removeSelf()
{
	armature->removeFromParent();
}
