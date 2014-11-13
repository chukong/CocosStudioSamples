#include "HelloWorldScene.h"
#include "VisibleRect.h"
#include "cocos-ext.h"
#include "CocosGUI.h"
#include "cocostudio/CCSSceneReader.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CCActionManagerEx.h"
#include "cocostudio/CCArmatureDataManager.h"


USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
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
    if ( !Layer::init() )
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
    
	Node *pGameScene = cocostudio::SceneReader::getInstance()->createNodeWithSceneFile("FightScene.json");
	m_pGameScene = pGameScene;
	this->addChild(pGameScene);

    ComRender *render = (ComRender*)(m_pGameScene->getChildByTag(10005)->getComponent("CCArmature"));
                                         
    Armature *pArmature = (Armature*)(render->getNode());
	
    pArmature->getAnimation()->play("run");
	
    m_bStart = true;

    
    
    
    LabelTTF* label = CCLabelTTF::create("End", "Marker Felt", 40);
    auto itemBack = MenuItemLabel::create(label, CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    itemBack->setColor(Color3B(255, 255, 255));
    itemBack->setPosition(Point(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
    
    Menu* menuBack =Menu::create(itemBack, NULL);
    menuBack->setPosition( Point::ZERO );
    menuBack->setZOrder(4);
    this->addChild(menuBack);
    
    
//    CCMenuItemFont *itemBack = CCMenuItemFont::create("End", this, menu_selector(HelloWorld::menuCloseCallback));
//    itemBack->setColor(ccc3(255, 255, 255));
//    itemBack->setPosition(ccp(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
//    CCMenu *menuBack = CCMenu::create(itemBack, NULL);
//    menuBack->setPosition(CCPointZero);
//    menuBack->setZOrder(4);
//    
//    this->addChild(menuBack);

	scheduleUpdate();

    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	cocostudio::ArmatureDataManager::destroyInstance();
	cocostudio::SceneReader::destroyInstance();
    cocostudio::GUIReader::destroyInstance();
    cocostudio::ActionManagerEx::destroyInstance();
    
    CCDirector::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::animationEvent(Armature *pArmature,
					MovementEventType movementType, const char *movementID)
{
    ComRender *render = (ComRender*)(m_pGameScene->getChildByTag(10006)->getComponent("CCArmature"));
	Armature *pEnemy = (Armature*)(render->getNode());

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
        ComRender *pHeroRender = (ComRender*)(m_pGameScene->getChildByTag(10005)->getComponent("CCArmature"));
		Armature *pHero = (Armature*)(pHeroRender->getNode());
		pHero->getParent()->setPositionX(pHero->getParent()->getPositionX() + m_fSpeed);
        
        ComRender *pEnemyRender = (ComRender*)(m_pGameScene->getChildByTag(10006)->getComponent("CCArmature"));
		Armature *pEnemy = (Armature*)(pEnemyRender->getNode());

        /* for 3.0 */
        float distance = Point(pHero->getParent()->getPositionX(), 0).getDistance(Point(pEnemy->getParent()->getPositionX(), 0));
        if (distance < m_fAttackDis)
        {
            pHero->getAnimation()->play("attack");
			pHero->getAnimation()->setMovementEventCallFunc(this,
                                                            movementEvent_selector(HelloWorld::animationEvent));
			m_bStart = false;
        }
        // before
        /*
		if(ccpDistance(ccp(pHero->getParent()->getPositionX(), 0), ccp(pEnemy->getParent()->getPositionX(), 0)) < m_fAttackDis)
		{	
			pHero->getAnimation()->play("attack");
			pHero->getAnimation()->setMovementEventCallFunc(this,
                                                        movementEvent_selector(HelloWorld::animationEvent));
			m_bStart = false;
		}
         */
        /**/
	}

	if(m_bDead)
	{
		ComRender *pUIRender = static_cast<ComRender*>(m_pGameScene->getChildByTag(10007)->getComponent("GUIComponent"));
        
        
        /* for 3.0 */
        Node* pUILayer = static_cast<Node*>(pUIRender->getNode());
        Layout* root = static_cast<Layout*>(pUILayer->getChildren().at(2));
        LoadingBar *pHPLoadingBar = static_cast<LoadingBar*>(Helper::seekWidgetByName(root, "hp02_LoadingBar"));
        LoadingBar *pMPLoadingBar = static_cast<LoadingBar*>(Helper::seekWidgetByName(root, "mp02_LoadingBar"));
        // before
        /*
		cocos2d::ui::TouchGroup *pUILayer = static_cast<cocos2d::ui::TouchGroup*>(pUIRender->getNode());
		cocos2d::ui::LoadingBar *pHPLoadingBar = static_cast<cocos2d::ui::LoadingBar*>(pUILayer->getWidgetByName("hp02_LoadingBar"));
		cocos2d::ui::LoadingBar *pMPLoadingBar = static_cast<cocos2d::ui::LoadingBar*>(pUILayer->getWidgetByName("mp02_LoadingBar"));
         */
        /**/

		pHPLoadingBar->setPercent(m_fPercentage);
		pMPLoadingBar->setPercent(m_fPercentage);

		m_fPercentage -= 2.0f;
        if (m_fPercentage < 0.0f) {
            unscheduleUpdate();
        }
	}
	
}
