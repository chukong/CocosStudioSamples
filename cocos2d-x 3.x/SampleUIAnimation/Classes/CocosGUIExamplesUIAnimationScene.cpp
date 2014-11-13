

#include "CocosGUIExamplesUIAnimationScene.h"
#include "cocostudio/CCSSceneReader.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CCActionManagerEx.h"

CocosGUIExamplesUIAnimationScene::CocosGUIExamplesUIAnimationScene()
{
    CCScene::init();
}

CocosGUIExamplesUIAnimationScene::~CocosGUIExamplesUIAnimationScene()
{
    
}

void CocosGUIExamplesUIAnimationScene::onEnter()
{
    CCScene::onEnter();
    
    m_pUILayer = Layer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    UIAnimationInit();
    
    // exit button
    Button* exit_button = Button::create();
    exit_button->setTouchEnabled(true);
    exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    exit_button->setPosition(Point(m_pUILayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
    exit_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesUIAnimationScene::menuCloseCallback));    
    m_pUILayer->addChild(exit_button);
}

void CocosGUIExamplesUIAnimationScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    cocostudio::SceneReader::destroyInstance();
    cocostudio::GUIReader::destroyInstance();
    cocostudio::ActionManagerEx::destroyInstance();
    
    CCScene::onExit();
}

void CocosGUIExamplesUIAnimationScene::menuCloseCallback(Ref* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        cocostudio::ActionManagerEx::getInstance()->releaseActions();
        CCDirector::getInstance()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void CocosGUIExamplesUIAnimationScene::UIAnimationInit()
{
    // ui animation root from json
    Layout* uianimation_root = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosgui/gui_examples/SampleUIAnimation/SampleUIAnimation.json"));
    m_pUILayer->addChild(uianimation_root);
    
    // TextButton button
    Button* button = static_cast<Button*>(Helper::seekWidgetByName(uianimation_root, "TextButton"));
    button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesUIAnimationScene::startUIAnimation));
}

void CocosGUIExamplesUIAnimationScene::startUIAnimation(Ref* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        cocostudio::ActionManagerEx::getInstance()->playActionByName("SampleUIAnimation.json", "Animation1");
//		cocos2d::extension::ActionManager::shareManager()->playActionByName("SampleUIAnimation.json", "Animation1");        
    }
}