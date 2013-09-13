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
	m_bStart = false;
	HP = 100.0f;

	m_pGameScene = NULL;
    
	CCNode *pGameScene = CCSSceneReader::sharedSceneReader()->createNodeWithSceneFile("ComponentTest.json");
	m_pGameScene = pGameScene;
	this->addChild(pGameScene);

	CCArmature *pArmature = (CCArmature*)(m_pGameScene->getChildByTag(10007)->getComponent("CCArmature")->getNode());
	pArmature->getAnimation()->play("Animation0");

	CCComRender *pUIRender = static_cast<CCComRender*>(pGameScene->getChildByTag(10003)->getComponent("GUIComponent"));
	UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());

	UIButton *pExitButton = static_cast<UIButton*>(pUILayer->getWidgetByName("return_Button"));
	pExitButton->addReleaseEvent(this, coco_releaseselector(HelloWorld::menuAttackCallback));

    CCMenuItemFont *itemBack = CCMenuItemFont::create("End", this, menu_selector(HelloWorld::menuCloseCallback));
    itemBack->setColor(ccc3(255, 255, 255));
    itemBack->setPosition(960 - 15, 30);
    CCMenu *menuBack = CCMenu::create(itemBack, NULL);
    menuBack->setPosition(CCPointZero);
    menuBack->setZOrder(4);
    
    this->addChild(menuBack);

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

void HelloWorld::menuAttackCallback(cocos2d::CCObject* pSender)
{
    CCArmature *pArmature = (CCArmature*)(m_pGameScene->getChildByTag(10007)->getComponent("CCArmature")->getNode());
	pArmature->getAnimation()->play("Animation1");
	pArmature->getAnimation()->setMovementEventCallFunc(this,
                                                        movementEvent_selector(HelloWorld::animationEvent));
}

void HelloWorld::animationEvent(CCArmature *pArmature,
					MovementEventType movementType, const char *movementID)
{
	if (movementType == COMPLETE)
	{
		CCArmature *pArmature = (CCArmature*)(m_pGameScene->getChildByTag(10008)->getComponent("CCArmature")->getNode());
		pArmature->getAnimation()->play("Animation1");

		m_bStart = true;
		scheduleUpdate();
	}
}

void HelloWorld::update(float delta)
{
	if (m_bStart)
	{
		CCComRender *pUIRender = static_cast<CCComRender*>(m_pGameScene->getChildByTag(10003)->getComponent("GUIComponent"));
		UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());
		UILoadingBar *pHPLoadingBar = static_cast<UILoadingBar*>(pUILayer->getWidgetByName("HP1"));
		UILoadingBar *pMPLoadingBar = static_cast<UILoadingBar*>(pUILayer->getWidgetByName("Chakras1"));

		pHPLoadingBar->setPercent(HP);
		pMPLoadingBar->setPercent(HP);

		HP -= 2.0f;
        if (HP < 0.0f) {
            unscheduleUpdate();
        }
	}
}
