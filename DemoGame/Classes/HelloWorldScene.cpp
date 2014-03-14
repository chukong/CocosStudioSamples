#include "HelloWorldScene.h"
#include "cocos-ext.h"

#include "GameScene.h"

USING_NS_CC;
using namespace cocos2d::extension;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
	
    if ( !CCLayer::init() )
    {
        return false;
    }
#if ENABLE_PHYSICS_BOX2D_DETECT

    //create menu and it's button

	CCMenuItemFont* start = CCMenuItemFont::create("Start Game",this,menu_selector(HelloWorld::menuStartGameCallback));
	CCMenuItemFont* next = CCMenuItemFont::create("Next Stage",this,menu_selector(HelloWorld::menuStageTwoCallback));
	CCMenuItemFont* exit = CCMenuItemFont::create("Exit",this,menu_selector(HelloWorld::menuCloseCallback));

	CCMenu* menu = CCMenu::create(start,next,exit,NULL);
	menu->alignItemsVertically();

	this->addChild(menu,3);

    return true;
#else
	CCLabelTTF *pLabel = CCLabelTTF::create("Should define CC_ENABLE_BOX2D_INTEGRATION=1\n for more please read Readme",
                                            "Arial",
                                            18);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pLabel->setPosition(ccp(size.width/2, size.height/2));
    
    addChild(pLabel);
	
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width*0.9 ,
                                CCDirector::sharedDirector()->getVisibleSize().height*0.1));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	return true;
#endif
}
void HelloWorld::menuStartGameCallback(CCObject* pSender)
{
	GameScene* stageOne = GameScene::create(1);
	CCDirector::sharedDirector()->pushScene(stageOne);
}

void HelloWorld::menuStageTwoCallback(CCObject* pSender)
{
	GameScene* stageTwo = GameScene::create(2);
	CCDirector::sharedDirector()->pushScene(stageTwo);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	cocos2d::extension::CCArmatureDataManager::purge();
	cocos2d::extension::ActionManager::shareManager()->purge();
	cocos2d::extension::SceneReader::sharedSceneReader()->purge();
	cocos2d::extension::GUIReader::shareReader()->purge();

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    CCDirector::sharedDirector()->end();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    exit(0);
#endif
}
