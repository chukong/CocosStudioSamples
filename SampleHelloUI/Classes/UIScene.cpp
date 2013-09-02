
#include "cocos-ext.h"
#include "UIScene.h"
#include "UISceneManager.h"
//#include "../ExtensionsTest.h"
//#include "CocosGUIScene.h"

UIScene::UIScene()
: m_pSceneTitle(NULL)
, m_pUiLayer(NULL)
{
    
}

UIScene::~UIScene()
{
    m_pUiLayer->removeFromParent();	
}

bool UIScene::init()
{
    if (CCLayer::init())
    {
        m_pUiLayer = UILayer::create();
        m_pUiLayer->scheduleUpdate();
        addChild(m_pUiLayer);
        
        /*
        m_pWidget = Layout::create();
        m_pWidget->setSize(CCSizeMake(480, 320));
        m_pWidget->setBackGroundImage("cocosgui/UITest/background.png");
        //        m_pWidget->setBackGroundColorType(LAYOUT_COLOR_SOLID);
        //        m_pWidget->setBackGroundColor(ccGREEN);
        
        
        Layout* layout = Layout::create();
        layout->setName("Panel");
        layout->setAnchorPoint(CCPointZero);
        layout->setBackGroundImage("cocosgui/UITest/ribbon.png");
        layout->setBackGroundImageScale9Enabled(true);
        layout->setSize(CCSizeMake(480, 57));
        layout->setPosition(ccp(0, 263));
        m_pWidget->addChild(layout);
        
        Layout* background_layout = Layout::create();
        background_layout->setName("background_Panel");
        background_layout->setAnchorPoint(CCPointZero);
        background_layout->setBackGroundImage("cocosgui/UITest/buttonBackground.png");
        background_layout->setPosition(ccp(90, 75));
        background_layout->setBackGroundImageScale9Enabled(true);
        background_layout->setSize(CCSizeMake(300, 170));
        m_pWidget->addChild(background_layout);
        //
        m_pSceneTitle = UILabel::create();
        m_pSceneTitle->setName("UItest");
        m_pSceneTitle->setText("UI_test");
        m_pSceneTitle->setFontName("SongTypeFont");
        m_pSceneTitle->setFontSize(20);
        m_pSceneTitle->setPosition(ccp(240, 307));
        m_pWidget->addChild(m_pSceneTitle);
        //        m_pSceneTitle->ignoreContentAdaptWithSize(true);
        
        UILabel *back_label = UILabel::create();
        back_label->setName("back");
        back_label->setTouchEnabled(true);
        back_label->setFontName("SongTypeFont");
        back_label->setText("Back");
        back_label->setFontSize(24);
        back_label->setPosition(ccp(430, 30));
        back_label->addReleaseEvent(this, coco_releaseselector(UIScene::toExtensionsMainLayer));
        m_pWidget->addChild(back_label);
        //        back_label->ignoreContentAdaptWithSize(true);
        
        UIButton *left_button = UIButton::create();
        left_button->setName("left_Button");
        left_button->setTouchEnabled(true);
        left_button->setPosition(ccp(142, 23));
        left_button->loadTextures("cocosgui/UITest/b1.png", "cocosgui/UITest/b2.png", "cocosgui/UITest/b2.png");
        left_button->addReleaseEvent(this, coco_releaseselector(UIScene::previousCallback));
        m_pWidget->addChild(left_button);
        //        left_button->ignoreContentAdaptWithSize(true);
        
        UIButton *middle_button = UIButton::create();
        middle_button->setName("middle_Button");
        middle_button->setTouchEnabled(true);
        middle_button->setPosition(ccp(240, 23));
        middle_button->loadTextures("cocosgui/UITest/r1.png", "cocosgui/UITest/r2.png", "cocosgui/UITest/r2.png");
        middle_button->addReleaseEvent(this, coco_releaseselector(UIScene::restartCallback));
        m_pWidget->addChild(middle_button);
        //        middle_button->ignoreContentAdaptWithSize(true);
        
        UIButton *right_button = UIButton::create();
        right_button->setName("right_Button");
        right_button->setTouchEnabled(true);
        right_button->setPosition(ccp(338, 23));
        right_button->loadTextures("cocosgui/UITest/f1.png", "cocosgui/UITest/f2.png", "cocosgui/UITest/f2.png");
        right_button->addReleaseEvent(this, coco_releaseselector(UIScene::nextCallback));
        m_pWidget->addChild(right_button);
        
        //        right_button->ignoreContentAdaptWithSize(true);
        
        
        m_pUiLayer->addWidget(m_pWidget);
         */
        
        
//        /*
        m_pWidget = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/UITest/UITest.json"));
        m_pUiLayer->addWidget(m_pWidget);
        
        m_pSceneTitle = dynamic_cast<UILabel*>(m_pUiLayer->getWidgetByName("UItest"));
        
        UILabel *back_label = dynamic_cast<UILabel*>(m_pUiLayer->getWidgetByName("back"));
        back_label->setVisible(false);
//        back_label->addReleaseEvent(this, coco_releaseselector(UIScene::toExtensionsMainLayer));
        
        UIButton *left_button = dynamic_cast<UIButton*>(m_pUiLayer->getWidgetByName("left_Button"));
        left_button->addReleaseEvent(this, coco_releaseselector(UIScene::previousCallback));
        
        UIButton *middle_button = dynamic_cast<UIButton*>(m_pUiLayer->getWidgetByName("middle_Button"));
        middle_button->addReleaseEvent(this, coco_releaseselector(UIScene::restartCallback));
        
        UIButton *right_button = dynamic_cast<UIButton*>(m_pUiLayer->getWidgetByName("right_Button"));
        right_button->addReleaseEvent(this, coco_releaseselector(UIScene::nextCallback));
//         */
        
        // exit button
        UIButton* exit_button = UIButton::create();
        exit_button->setTouchEnabled(true);
        exit_button->setTextures("CloseNormal.png", "CloseSelected.png", "");
        exit_button->setPosition(ccp(m_pUiLayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
        exit_button->addReleaseEvent(this, coco_releaseselector(UIScene::menuCloseCallback));
        m_pUiLayer->addWidget(exit_button);
        
        return true;
    }
    return false;
}

void UIScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void UIScene::toExtensionsMainLayer(CCObject* sender)
{
    UISceneManager::purgeUISceneManager();
    UIActionManager::purgeUIActionManager();
    UIHelper::purgeUIHelper();
    CCSSceneReader::purgeSceneReader();
    
    /*
    CocosGUITestScene* pScene = new CocosGUITestScene();
    pScene->runThisTest();
    pScene->release();
     */
    
    /*
    ExtensionsTestScene* pScene = new ExtensionsTestScene();
    pScene->runThisTest();
    pScene->release();
     */
}

void UIScene::previousCallback(CCObject* sender)
{
    CCDirector::sharedDirector()->replaceScene(UISceneManager::sharedUISceneManager()->previousUIScene());
}

void UIScene::restartCallback(CCObject* sender)
{
    CCDirector::sharedDirector()->replaceScene(UISceneManager::sharedUISceneManager()->currentUIScene());
}

void UIScene::nextCallback(CCObject* sender)
{
    CCDirector::sharedDirector()->replaceScene(UISceneManager::sharedUISceneManager()->nextUIScene());
}
