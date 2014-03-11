

#include "CocosGUIExamplesRegisterScene.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

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
    
    m_pUILayer = TouchGroup::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    // register root from json
    m_pLayout = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("cocosgui/gui_examples/DemoLogin/DemoLogin.json"));
    m_pUILayer->addWidget(m_pLayout);
    
    TextField* comfirm_textfield = static_cast<TextField*>(m_pUILayer->getWidgetByName("confirm_TextField"));
    comfirm_textfield->addEventListenerTextField(this, textfieldeventselector(CocosGUIExamplesRegisterScene::textFieldEvent));
    
    // close button
    Button* close_button = static_cast<Button*>(m_pUILayer->getWidgetByName("close_Button"));
    close_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesRegisterScene::menuCloseCallback));
}     

void CocosGUIExamplesRegisterScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    SceneReader::sharedSceneReader()->purge();
    GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();
    
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
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            TextField* textField = dynamic_cast<TextField*>(pSender);
            
            if (strcmp(textField->getName(), "confirm_TextField") == 0)
            {
                CCMoveBy* moveBy = CCMoveBy::create(0.1f, ccp(0, textField->getContentSize().height * 2.5));
                m_pLayout->runAction(moveBy);
            }
#endif
        }
            break;
            
        case TEXTFIELD_EVENT_DETACH_WITH_IME:
        {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            TextField* textField = dynamic_cast<TextField*>(pSender);
            
            if (strcmp(textField->getName(), "confirm_TextField") == 0)
            {
                CCMoveBy* moveBy = CCMoveBy::create(0.1f, ccp(0, -textField->getContentSize().height * 2.5));
                m_pLayout->runAction(moveBy);
            }
#endif
        }
            break;
            
        default:
            break;
    }
}
