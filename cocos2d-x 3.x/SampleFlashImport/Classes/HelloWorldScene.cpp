#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	/////////////////////////////
	// init info
	setTouchEnabled(true);
	countTauren = 0;
	countHero = 0;
	//load armature data
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("tauren0.png","tauren0.plist","tauren.ExportJson");
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("girl0.png","girl0.plist","girl.ExportJson");
	//createa tauren flash armature
	tauren = CCArmature::create("tauren");
	tauren->setPosition(ccp(visibleSize.width * 0.7,visibleSize.height * 0.5));
	tauren->getAnimation()->playByIndex(0);
	tauren->setScale(0.7);
	this->addChild(tauren,1);
	//create hero flash armature
	hero = CCArmature::create("girl");
	hero->setPosition(ccp(visibleSize.width * 0.3,visibleSize.height * 0.5));
	hero->getAnimation()->playByIndex(0);
	this->addChild(hero,1);


	// create and initialize a label
	CCLabelTTF* pLabel = CCLabelTTF::create("Touch Screen to Change Animation", "Arial", 30);

	// position the label on the center of the screen
	pLabel->setPosition(ccp(origin.x + visibleSize.width*0.5,
		origin.y + visibleSize.height * 0.1));
	this->addChild(pLabel,0);

	// touch event added
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this );

	return true;
}

bool HelloWorld::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	//change animation index
	countTauren++;
	countTauren = countTauren % tauren->getAnimation()->getMovementCount();
	countHero++;
	countHero = countHero % hero->getAnimation()->getMovementCount();
	//set change to armature
	tauren->getAnimation()->playByIndex(countTauren);
	hero->getAnimation()->playByIndex(countHero);
	return false;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
