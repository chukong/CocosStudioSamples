

#include "CocosGUIExamplesUIAnimationScene.h"

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
    
    m_pUILayer = UILayer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    UIAnimationInit();
    
    // exit button
    UIButton* exit_button = UIButton::create();
    exit_button->setTouchEnabled(true);
    exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    exit_button->setPosition(ccp(m_pUILayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
    exit_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesUIAnimationScene::menuCloseCallback));    
    m_pUILayer->addWidget(exit_button);
}

void CocosGUIExamplesUIAnimationScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    SceneReader::sharedSceneReader()->purgeSceneReader();
    GUIReader::shareReader()->purgeGUIReader();
	cocos2d::extension::ActionManager::shareManager()->purgeActionManager();
    
    CCScene::onExit();
}

void CocosGUIExamplesUIAnimationScene::menuCloseCallback(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        CCDirector::sharedDirector()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void CocosGUIExamplesUIAnimationScene::UIAnimationInit()
{
    // ui animation root from json
    Layout* uianimation_root = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("cocosgui/gui_examples/SampleUIAnimation/SampleUIAnimation.json"));
    m_pUILayer->addWidget(uianimation_root);
    
    // TextButton button
    UIButton* button = static_cast<UIButton*>(m_pUILayer->getWidgetByName("TextButton"));
    button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesUIAnimationScene::startUIAnimation));
}

void CocosGUIExamplesUIAnimationScene::startUIAnimation(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
		cocos2d::extension::ActionManager::shareManager()->playActionByName("SampleUIAnimation.json", "Animation1");        
    }
}