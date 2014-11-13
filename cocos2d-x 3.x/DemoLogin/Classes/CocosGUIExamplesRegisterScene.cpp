

#include "CocosGUIExamplesRegisterScene.h"
#include "cocostudio/CCSSceneReader.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CCActionManagerEx.h"

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
    
    m_pUILayer = Layer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    // register root from json
    m_pLayout = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosgui/gui_examples/DemoLogin/DemoLogin.json"));
    m_pUILayer->addChild(m_pLayout);

    /* for 3.0 */
    TextField* comfirm_textfield = static_cast<TextField*>(Helper::seekWidgetByName(m_pLayout, "confirm_TextField"));
//    TextField* comfirm_textfield = static_cast<TextField*>(m_pUILayer->getWidgetByName("confirm_TextField"));
    /**/
    comfirm_textfield->addEventListenerTextField(this, textfieldeventselector(CocosGUIExamplesRegisterScene::textFieldEvent));
    
    // close button
    /* for 3.0 */
    Button* close_button = static_cast<Button*>(Helper::seekWidgetByName(m_pLayout, "close_Button"));
//    Button* close_button = static_cast<Button*>(m_pUILayer->getWidgetByName("close_Button"));
    /**/
    close_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesRegisterScene::menuCloseCallback));
}     

void CocosGUIExamplesRegisterScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    cocostudio::SceneReader::destroyInstance();
    cocostudio::GUIReader::destroyInstance();
    cocostudio::ActionManagerEx::destroyInstance();
    
    CCScene::onExit();
}

void CocosGUIExamplesRegisterScene::menuCloseCallback(Ref* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        CCDirector::getInstance()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void CocosGUIExamplesRegisterScene::textFieldEvent(Ref *pSender, TextFiledEventType type)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    switch (type)
    {
        case TEXTFIELD_EVENT_ATTACH_WITH_IME:
        {
            TextField* textField = dynamic_cast<TextField*>(pSender);
            
            if (strcmp(textField->getName(), "confirm_TextField") == 0)
            {
                MoveBy* moveBy = MoveBy::create(0.1f, Point(0, textField->getContentSize().height * 2.5));
                m_pLayout->runAction(moveBy);
            }
        }
            break;
            
        case TEXTFIELD_EVENT_DETACH_WITH_IME:
        {
            TextField* textField = dynamic_cast<TextField*>(pSender);
            
            if (strcmp(textField->getName(), "confirm_TextField") == 0)
            {
                MoveBy* moveBy = MoveBy::create(0.1f, Point(0, -textField->getContentSize().height * 2.5));
                m_pLayout->runAction(moveBy);
            }
        }
            break;
            
        default:
            break;
    }
#endif
}
