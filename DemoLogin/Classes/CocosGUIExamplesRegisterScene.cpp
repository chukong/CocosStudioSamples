

#include "CocosGUIExamplesRegisterScene.h"

CocosGUIExamplesRegisterScene::CocosGUIExamplesRegisterScene(bool bPortrait)
: m_pUILayer(NULL)
, m_pLayout(NULL)
{
    CCScene::init();
}

CocosGUIExamplesRegisterScene::~CocosGUIExamplesRegisterScene()
{
    
}

void CocosGUIExamplesRegisterScene::onEnter()
{
    CCScene::onEnter();
    
    m_pUILayer = UILayer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    // register root from json
    m_pLayout = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/gui_examples/DemoLogin/DemoLogin.json"));
    m_pUILayer->addWidget(m_pLayout);
    
    UITextField* comfirm_textfield = static_cast<UITextField*>(m_pUILayer->getWidgetByName("confirm_TextField"));
    comfirm_textfield->addEventListener(this, textfieldeventselector(CocosGUIExamplesRegisterScene::textFieldEvent));
    
    // close button
    UIButton* close_button = static_cast<UIButton*>(m_pUILayer->getWidgetByName("close_Button"));
    close_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesRegisterScene::menuCloseCallback));
}     

void CocosGUIExamplesRegisterScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    CCSSceneReader::sharedSceneReader()->purgeSceneReader();
    UIHelper::purgeUIHelper();
	cocos2d::extension::ActionManager::shareManager()->purgeActionManager();
    
    CCScene::onExit();
}

void CocosGUIExamplesRegisterScene::menuCloseCallback(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        CCDirector::sharedDirector()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void CocosGUIExamplesRegisterScene::textFieldEvent(CCObject *pSender, TextFiledEventType type)
{
    switch (type)
    {
        case TEXTFIELD_EVENT_ATTACH_WITH_IME:
        {
            UITextField* textField = dynamic_cast<UITextField*>(pSender);
            
            if (strcmp(textField->getName(), "confirm_TextField") == 0)
            {
                CCMoveBy* moveBy = CCMoveBy::create(0.1f, ccp(0, textField->getContentSize().height * 2.5));
                m_pLayout->runAction(moveBy);
            }
        }
            break;
            
        case TEXTFIELD_EVENT_DETACH_WITH_IME:
        {
            UITextField* textField = dynamic_cast<UITextField*>(pSender);
            
            if (strcmp(textField->getName(), "confirm_TextField") == 0)
            {
                CCMoveBy* moveBy = CCMoveBy::create(0.1f, ccp(0, -textField->getContentSize().height * 2.5));
                m_pLayout->runAction(moveBy);
            }
        }
            break;
            
        default:
            break;
    }
}
