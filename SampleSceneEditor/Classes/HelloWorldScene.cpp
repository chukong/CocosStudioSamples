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
	m_fTime = 0.0f;
	m_bStart = false;
	m_bDead = false;
	m_fPercentage = 100.0f;
	m_fSpeed = 4.0f;
	m_fAttackDis = 120.0f;

	m_pGameScene = NULL;
    
	CCNode *pGameScene = SceneReader::sharedSceneReader()->createNodeWithSceneFile("FightScene.json");
	m_pGameScene = pGameScene;
	this->addChild(pGameScene);

    CCComRender *render = (CCComRender*)(m_pGameScene->getChildByTag(10005)->getComponent("CCArmature"));
                                         
    CCArmature *pArmature = (CCArmature*)(render->getNode());
	
    pArmature->getAnimation()->play("run");
	
    m_bStart = true;

    CCMenuItemFont *itemBack = CCMenuItemFont::create("End", this, menu_selector(HelloWorld::menuCloseCallback));
    itemBack->setColor(ccc3(255, 255, 255));
    itemBack->setPosition(ccp(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
    CCMenu *menuBack = CCMenu::create(itemBack, NULL);
    menuBack->setPosition(CCPointZero);
    menuBack->setZOrder(4);
    
    this->addChild(menuBack);

	scheduleUpdate();

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	CCArmatureDataManager::purge();
	SceneReader::sharedSceneReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();
    GUIReader::shareReader()->purge();
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::animationEvent(CCArmature *pArmature,
					MovementEventType movementType, const char *movementID)
{
    CCComRender *render = (CCComRender*)(m_pGameScene->getChildByTag(10006)->getComponent("CCArmature"));
	CCArmature *pEnemy = (CCArmature*)(render->getNode());

	if (movementType == COMPLETE)
	{
		pEnemy->getAnimation()->play("death");
		pArmature->getAnimation()->setMovementEventCallFunc(NULL, NULL);
		m_bDead = true;
	}
	
}

void HelloWorld::update(float delta)
{
	if(m_bStart)
	{
        CCComRender *pHeroRender = (CCComRender*)(m_pGameScene->getChildByTag(10005)->getComponent("CCArmature"));
		CCArmature *pHero = (CCArmature*)(pHeroRender->getNode());
		pHero->getParent()->setPositionX(pHero->getParent()->getPositionX() + m_fSpeed);
        
        CCComRender *pEnemyRender = (CCComRender*)(m_pGameScene->getChildByTag(10006)->getComponent("CCArmature"));
		CCArmature *pEnemy = (CCArmature*)(pEnemyRender->getNode());

		if(ccpDistance(ccp(pHero->getParent()->getPositionX(), 0), ccp(pEnemy->getParent()->getPositionX(), 0)) < m_fAttackDis)
		{	
			pHero->getAnimation()->play("attack");
			pHero->getAnimation()->setMovementEventCallFunc(this,
                                                        movementEvent_selector(HelloWorld::animationEvent));
			m_bStart = false;
		}
	}

	if(m_bDead)
	{
		CCComRender *pUIRender = static_cast<CCComRender*>(m_pGameScene->getChildByTag(10007)->getComponent("GUIComponent"));
		cocos2d::ui::TouchGroup *pUILayer = static_cast<cocos2d::ui::TouchGroup*>(pUIRender->getNode());
		cocos2d::ui::LoadingBar *pHPLoadingBar = static_cast<cocos2d::ui::LoadingBar*>(pUILayer->getWidgetByName("hp02_LoadingBar"));
		cocos2d::ui::LoadingBar *pMPLoadingBar = static_cast<cocos2d::ui::LoadingBar*>(pUILayer->getWidgetByName("mp02_LoadingBar"));

		pHPLoadingBar->setPercent(m_fPercentage);
		pMPLoadingBar->setPercent(m_fPercentage);

		m_fPercentage -= 2.0f;
        if (m_fPercentage < 0.0f) {
            unscheduleUpdate();
        }
	}
	
}
