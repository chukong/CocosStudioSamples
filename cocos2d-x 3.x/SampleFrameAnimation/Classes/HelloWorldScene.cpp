#include "HelloWorldScene.h"
#include "Fishes.h"


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
	// 3. add your codes below...
	//create a fish without action
	Fish01* fish1 = new Fish01();
	this->addChild(fish1,2);

	//create a fish rotate forever
	Fish02* fish2 = new Fish02();
	this->addChild(fish2,2);

	//create a fish swim around
	Fish06* fish6 = new Fish06();
	this->addChild(fish6,1);

	//create a fish fade out
	Fish07* fish7 = new Fish07();
	this->addChild(fish7,2);

	//create a fish group
	Fish05* fish5 = new Fish05();
	this->addChild(fish5,1);

	Fish05* fish51 = new Fish05();
	fish51->setPosition(ccp(30,30));
	this->addChild(fish51,1);

	Fish05* fish52 = new Fish05();
	fish52->setPosition(ccp(30,-30));
	this->addChild(fish52,1);

	//create a fish with a call back
	Fish04* fish40 = new Fish04();
	this->addChild(fish40,2);

	Fish04* fish41 = new Fish04();
	fish41->setPosition(ccp(0,-70));
	this->addChild(fish41,2);

	Fish04* fish42 = new Fish04();
	fish42->setPosition(ccp(0,-140));
	this->addChild(fish42,2);

	Fish04* fish43 = new Fish04();
	fish43->setPosition(ccp(0,-210));
	this->addChild(fish43,2);
	// add a label shows "Hello World"
	// create and initialize a label

	// add backGround splash screen"
	CCSprite* pSprite = CCSprite::create("2048.png");
	//scale background
	pSprite->setScaleX(visibleSize.width/2048);
	pSprite->setScaleY(visibleSize.height/1536);
	// position the sprite on the center of the screen
	pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
