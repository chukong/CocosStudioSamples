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
	m_pGameScene = NULL;
    
	CCNode *pGameScene = CCSSceneReader::sharedSceneReader()->createNodeWithSceneFile("ComponentTest.json");
	m_pGameScene = pGameScene;
	this->addChild(pGameScene);

	CCComRender *pUIRender = static_cast<CCComRender*>(pGameScene->getChildByTag(10014)->getComponent("GUIComponent"));
	UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());

	UIButton *pExitButton = static_cast<UIButton*>(pUILayer->getWidgetByName("Button"));
	pExitButton->addReleaseEvent(this, coco_releaseselector(HelloWorld::menuCloseCallback));

	UILabel *pLabel = NULL;
	pLabel = static_cast<UILabel*>(pUILayer->getWidgetByName("SpriteComponentTest"));
	pLabel->addReleaseEvent(this, coco_releaseselector(HelloWorld::menuSpriteComponentTestCallback));


	pLabel = static_cast<UILabel*>(pUILayer->getWidgetByName("UIComponentTest"));
	pLabel->addReleaseEvent(this, coco_releaseselector(HelloWorld::menuUIComponentTestCallback));
    
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

// a selector callback
void HelloWorld::menuSpriteComponentTestCallback(CCObject* pSender)
{
	/*CCSprite *pNartoIcon = static_cast<CCSprite*>(m_pGameScene->getChildByTag(10003)->getChildByTag(10004)->getComponent("CCSprite")->getNode());
	CCSprite *pSaukeIcon = static_cast<CCSprite*>(m_pGameScene->getChildByTag(10003)->getChildByTag(10005)->getComponent("CCSprite")->getNode());
	pNartoIcon->runAction(CCRotateBy::create(0.5, 3));*/
	
}

// a selector callback
void HelloWorld::menuMapComponentTestCallback(CCObject* pSender)
{

}

// a selector callback
void HelloWorld::menuParticleComponentTestCallback(CCObject* pSender)
{

}

// a selector callback
void HelloWorld::menuArmatureTestCallback(CCObject* pSender)
{

}

// a selector callback
void HelloWorld::menuEffectComponentTestCallback(CCObject* pSender)
{

}

// a selector callback
void HelloWorld::menuUIComponentTestCallback(CCObject* pSender)
{
	CCComRender *pUIRender = static_cast<CCComRender*>(m_pGameScene->getChildByTag(10003)->getComponent("GUIComponent"));
	UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());
	UILoadingBar *pHPLoadingBar = static_cast<UILoadingBar*>(pUILayer->getWidgetByName("HP"));
	pHPLoadingBar->setPercent(30);
}

// a selector callback
void HelloWorld::menuAttributeComponentCallback(CCObject* pSender)
{

}

// a selector callback
void HelloWorld::menuBackgroundMusicComponentTestCallback(CCObject* pSender)
{

}