#include "HelloWorldScene.h"
#include "VisibleRect.h"
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
	m_fPercent = 100.0f;

	m_pGameScene = NULL;
    
	CCNode *pGameScene = CCSSceneReader::sharedSceneReader()->createNodeWithSceneFile("chrosfighters.json");
	m_pGameScene = pGameScene;
	this->addChild(pGameScene);

	CCArmature *pArmature = (CCArmature*)(m_pGameScene->getChildByTag(10007)->getComponent("CCArmature")->getNode());
	pArmature->getAnimation()->play("Animation0");

	CCComRender *pUIRender = static_cast<CCComRender*>(pGameScene->getChildByTag(10004)->getComponent("GUIComponent"));
	UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());

	UIButton *pExitButton = static_cast<UIButton*>(pUILayer->getWidgetByName("Attack_Button"));
	pExitButton->addReleaseEvent(this, coco_releaseselector(HelloWorld::menuAttackCallback));

    CCMenuItemFont *itemBack = CCMenuItemFont::create("End", this, menu_selector(HelloWorld::menuCloseCallback));
    itemBack->setColor(ccc3(255, 255, 255));
    itemBack->setPosition(ccp(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
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
                                                        movementEvent_selector(HelloWorld::animationEvent1));
}

void HelloWorld::animationEvent1(CCArmature *pArmature,
					MovementEventType movementType, const char *movementID)
{
	if (movementType == COMPLETE)
	{
		CCArmature *pArmature = (CCArmature*)(m_pGameScene->getChildByTag(10008)->getComponent("CCArmature")->getNode());
		pArmature->getAnimation()->play("Animation1");
		pArmature->getAnimation()->setMovementEventCallFunc(this,
			movementEvent_selector(HelloWorld::animationEvent2));
		m_bStart = true;
		scheduleUpdate();
	}
}

void HelloWorld::animationEvent2(CCArmature *pArmature,
								 MovementEventType movementType, const char *movementID)
{
	if (movementType == COMPLETE)
	{
		CCComRender *pUIRender = static_cast<CCComRender*>(m_pGameScene->getChildByTag(10004)->getComponent("GUIComponent"));
		UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());
		UILoadingBar *pHPLoadingBar = static_cast<UILoadingBar*>(pUILayer->getWidgetByName("HP1"));
		UILoadingBar *pMPLoadingBar = static_cast<UILoadingBar*>(pUILayer->getWidgetByName("Chakras1"));
		pHPLoadingBar->setPercent(m_fPercent);
		pMPLoadingBar->setPercent(m_fPercent);

		CCArmature *pArmature = NULL;
		pArmature = (CCArmature*)(m_pGameScene->getChildByTag(10008)->getComponent("CCArmature")->getNode());
		pArmature->getAnimation()->play("Animation0");

	    pArmature = (CCArmature*)(m_pGameScene->getChildByTag(10007)->getComponent("CCArmature")->getNode());
		pArmature->getAnimation()->play("Animation0");
	
	}
}

void HelloWorld::update(float delta)
{
	if (m_bStart)
	{
		CCComRender *pUIRender = static_cast<CCComRender*>(m_pGameScene->getChildByTag(10004)->getComponent("GUIComponent"));
		UILayer *pUILayer = static_cast<UILayer*>(pUIRender->getNode());
		UILoadingBar *pHPLoadingBar = static_cast<UILoadingBar*>(pUILayer->getWidgetByName("HP1"));
		UILoadingBar *pMPLoadingBar = static_cast<UILoadingBar*>(pUILayer->getWidgetByName("Chakras1"));

		pHPLoadingBar->setPercent(m_fPercent);
		pMPLoadingBar->setPercent(m_fPercent);

		m_fPercent -= 2.0f;
        if (m_fPercent < 0.0f) {
			m_bStart = false;
			m_fPercent = 100.0f;
            unscheduleUpdate();
        }
	}
}
