#include "HelloWorldScene.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

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

    CCNode *pFishJoyScene = CCSSceneReader::sharedSceneReader()->createNodeWithSceneFile("FishJoy2.json");
	this->addChild(pFishJoyScene);
    cocos2d::extension::UIActionManager::shareManager()->PlayActionByName("startMenu.json","Animation1");

	CCComRender *pUIRender = static_cast<CCComRender*>(pFishJoyScene->getChildByTag(10009)->getComponent("GUIComponent"));
	UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());
	UIButton *pButton = static_cast<UIButton*>(pUILayer->getWidgetByName("exit_button"));
	pButton->addReleaseEvent(this, coco_releaseselector(HelloWorld::menuCloseCallback));
	CCLOG("pButton name = %s", pButton->getName());

    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCArmatureDataManager::purge();
	CCSSceneReader::sharedSceneReader()->purgeSceneReader();
	cocos2d::extension::UIActionManager::shareManager()->purgeUIActionManager();
	cocos2d::extension::UIHelper::instance()->purgeUIHelper();

    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

}
