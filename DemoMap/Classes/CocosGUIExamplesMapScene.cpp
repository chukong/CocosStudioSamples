

#include "CocosGUIExamplesMapScene.h"
#include "cocostudio/CCSSceneReader.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CCActionManagerEx.h"

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
    
    m_pUILayer = Layer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    MapInit();
    MapAlertInit();
}

void CocosGUIExamplesMapScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    cocostudio::SceneReader::destroyInstance();
    cocostudio::GUIReader::destroyInstance();
    cocostudio::ActionManagerEx::destroyInstance();
    
    CCScene::onExit();
}

void CocosGUIExamplesMapScene::menuCloseCallback(Ref* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        CCDirector::getInstance()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void CocosGUIExamplesMapScene::MapInit()
{
    // map root from json
    _root = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosgui/gui_examples/DemoMap/DemoMap.json"));
    
    m_pUILayer->addChild(_root);
    
    // build button on map root
    Layout* button_layout = static_cast<Layout*>(Helper::seekWidgetByName(_root, "button_Panel"));
    
    for (int i = 0; i < button_layout->getChildren().size(); ++i)
    {
        Button* build_button = static_cast<Button*>(button_layout->getChildren().at(i));
        build_button->setTag(MAP_BUTTON_TAG + i);
        build_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesMapScene::buildTouchEvent));
    }
    
    // back button
    Button* back_button = static_cast<Button*>(Helper::seekWidgetByName(_root, "back_Button"));
    back_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesMapScene::menuCloseCallback));
}

void CocosGUIExamplesMapScene::buildTouchEvent(Ref *pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        Button* build_button = dynamic_cast<Button*>(pSender);
    
        Layout* alert_panel = dynamic_cast<Layout*>(Helper::seekWidgetByName(_root, "alert_Panel"));
        alert_panel->setVisible(true);
        
        ImageView* alert_imageview = dynamic_cast<ImageView*>(alert_panel->getChildByName("alert_ImageView"));
        int index = build_button->getTag() - MAP_BUTTON_TAG;
        alert_imageview->loadTexture(buildPngPaths[index]);
        
        Text* alert_label = dynamic_cast<Text*>(alert_panel->getChildByName("alert_Label"));
        alert_label->setColor(Color3B::BLACK);
        alert_label->setTextHorizontalAlignment(TextHAlignment::CENTER);
        alert_label->setTextVerticalAlignment(TextVAlignment::CENTER);
        alert_label->setText(buildNames[index]);
        
        // drag panel
        ui::ScrollView* dragPanel = static_cast<ui::ScrollView*>(Helper::seekWidgetByName(_root, "DragPanel"));
        dragPanel->setTouchEnabled(false);
        
        // build button on map root
        Layout* button_layout = static_cast<Layout*>(Helper::seekWidgetByName(_root, "button_Panel"));
        for (auto& obj : button_layout->getChildren())
        {
            Button* build_button = static_cast<Button*>(obj);
            build_button->setTouchEnabled(false);
        }
    }
}

void CocosGUIExamplesMapScene::MapAlertInit()
{
    // map alert from json
    Layout* alert_panel = static_cast<Layout*>(Helper::seekWidgetByName(_root, "alert_Panel"));
    
    Button* close_button = static_cast<Button*>(alert_panel->getChildByName("close_Button"));
    close_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesMapScene::MapAlertClose));
}

void CocosGUIExamplesMapScene::MapAlertClose(Ref* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        Layout* map_alert_root = static_cast<Layout*>(Helper::seekWidgetByName(_root, "alert_Panel"));
        map_alert_root->setVisible(false);
        
        // drag panel
        ui::ScrollView* dragPanel = static_cast<ui::ScrollView*>(Helper::seekWidgetByName(_root, "DragPanel"));
        dragPanel->setTouchEnabled(true);
        
        // build button on map root
        Layout* button_layout = static_cast<Layout*>(Helper::seekWidgetByName(_root, "button_Panel"));
        for (auto& obj : button_layout->getChildren())
        {
            Button* build_button = static_cast<Button*>(obj);
            build_button->setTouchEnabled(true);
        }
    }
}
