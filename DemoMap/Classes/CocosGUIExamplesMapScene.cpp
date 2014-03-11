

#include "CocosGUIExamplesMapScene.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

const char* buildPngPaths[4] =
{
    "cocosgui/gui_examples/DemoMap/purple_ball1.png",
    "cocosgui/gui_examples/DemoMap/blue1.png",
    "cocosgui/gui_examples/DemoMap/orange1.png",
    "cocosgui/gui_examples/DemoMap/blue_ball1.png",
};

const char* buildNames[4] =
{
    "purple",
    "blue star",
    "orange",
    "blue ball",
};

CocosGUIExamplesMapScene::CocosGUIExamplesMapScene()
{
    CCScene::init();
}

CocosGUIExamplesMapScene::~CocosGUIExamplesMapScene()
{
    
}

void CocosGUIExamplesMapScene::onEnter()
{
    CCScene::onEnter();
    
    m_pUILayer = TouchGroup::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    MapInit();
    MapAlertInit();
}

void CocosGUIExamplesMapScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    SceneReader::sharedSceneReader()->purge();
    GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();
    
    CCScene::onExit();
}

void CocosGUIExamplesMapScene::menuCloseCallback(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        CCDirector::sharedDirector()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void CocosGUIExamplesMapScene::MapInit()
{
    // map root from json
    Layout* map_root = static_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("cocosgui/gui_examples/DemoMap/DemoMap.json"));
    m_pUILayer->addWidget(map_root);    
    
    // build button on map root
    Layout* button_layout = static_cast<Layout*>(UIHelper::seekWidgetByName(map_root, "button_Panel"));
//    Layout* button_layout = static_cast<Layout*>(map_root->getChildByName("button_Panel"));
    
    for (int i = 0; i < button_layout->getChildren()->count(); ++i)
    {
        Button* build_button = static_cast<Button*>(button_layout->getChildren()->objectAtIndex(i));
        build_button->setTag(MAP_BUTTON_TAG + i);
        build_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesMapScene::buildTouchEvent));
    }
    
    // back button
    Button* back_button = static_cast<Button*>(m_pUILayer->getWidgetByName("back_Button"));
    back_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesMapScene::menuCloseCallback));    
}

void CocosGUIExamplesMapScene::buildTouchEvent(CCObject *pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        Button* build_button = dynamic_cast<Button*>(pSender);
        
        Layout* alert_panel = dynamic_cast<Layout*>(m_pUILayer->getWidgetByName("alert_Panel"));
        alert_panel->setVisible(true);
        
        ImageView* alert_imageview = dynamic_cast<ImageView*>(alert_panel->getChildByName("alert_ImageView"));
        int index = build_button->getTag() - MAP_BUTTON_TAG;
        alert_imageview->loadTexture(buildPngPaths[index]);
        
        Label* alert_label = dynamic_cast<Label*>(alert_panel->getChildByName("alert_Label"));
        alert_label->setColor(ccBLACK);
        alert_label->setTextHorizontalAlignment(kCCTextAlignmentCenter);
        alert_label->setTextVerticalAlignment(kCCVerticalTextAlignmentCenter);
        alert_label->setText(buildNames[index]);
        
        // drag panel
        ScrollView* dragPanel = static_cast<ScrollView*>(m_pUILayer->getWidgetByName("DragPanel"));
        dragPanel->setTouchEnabled(false);
        
        // build button on map root
        Layout* button_layout = static_cast<Layout*>(m_pUILayer->getWidgetByName("button_Panel"));
        CCObject* obj = NULL;
        CCARRAY_FOREACH(button_layout->getChildren(), obj)
        {
            Button* build_button = static_cast<Button*>(obj);
            build_button->setTouchEnabled(false);
        }
    }
}

void CocosGUIExamplesMapScene::MapAlertInit()
{
    // map alert from json
    Layout* alert_panel = static_cast<Layout*>(m_pUILayer->getWidgetByName("alert_Panel"));
    
    Button* close_button = static_cast<Button*>(alert_panel->getChildByName("close_Button"));
    close_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesMapScene::MapAlertClose));
}

void CocosGUIExamplesMapScene::MapAlertClose(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        Layout* map_alert_root = static_cast<Layout*>(m_pUILayer->getWidgetByName("alert_Panel"));
        map_alert_root->setVisible(false);
        
        // drag panel
        ScrollView* dragPanel = static_cast<ScrollView*>(m_pUILayer->getWidgetByName("DragPanel"));
        dragPanel->setTouchEnabled(true);
        
        // build button on map root
        Layout* button_layout = static_cast<Layout*>(m_pUILayer->getWidgetByName("button_Panel"));
        CCObject* obj = NULL;
        CCARRAY_FOREACH(button_layout->getChildren(), obj)
        {
            Button* build_button = static_cast<Button*>(obj);
            build_button->setTouchEnabled(true);
        }
    }
}
