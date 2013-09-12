

#include "CocosGUIExamplesPageScene.h"
/*
#include "CocosGUIExamplesMapScene.h"
#include "CocosGUIExamplesPageSpecialScene.h"
 */

const char* page_image_textures[4] =
{
    "cocosgui/gui_examples/page_1/page_content/CocoStudio_AnimationEditor.png",
    "cocosgui/gui_examples/page_1/page_content/CocoStudio_DataEditor.png",
    "cocosgui/gui_examples/page_1/page_content/CocoStudio_SceneEditor.png",
    "cocosgui/gui_examples/page_1/page_content/CocoStudio_UIEditor.png",
};

CocosGUIExamplesPageScene::CocosGUIExamplesPageScene()
{
    CCScene::init();
}

CocosGUIExamplesPageScene::~CocosGUIExamplesPageScene()
{
    
}

void CocosGUIExamplesPageScene::onEnter()
{
    CCScene::onEnter();
    
    m_pUILayer = UILayer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    PageInit();
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    UILabel* label = UILabel::create();
    label->setText("Move by horizontal direction");
    const char* font =
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // custom ttf files are defined in Test-info.plist
    "Marker Felt";
#else
    "fonts/Marker Felt.ttf";
#endif
    label->setFontName(font);
    label->setFontSize(32);
    label->setAnchorPoint(ccp(0.5f, -1));
    label->setPosition(ccp(winSize.width / 2.0f, winSize.height / 2.0f + label->getContentSize().height * 1.5));
    m_pUILayer->addWidget(label);
    
    /*
    // left button
    UIButton* left_button = UIButton::create();
    left_button->setTouchEnable(true);
    left_button->loadTextures("cocosgui/UITest/b1.png", "cocosgui/UITest/b2.png", "");
    float left_button_width = left_button->getContentSize().width;
    left_button->setPosition(ccp(left_button_width - left_button_width / 2, m_pUILayer->getContentSize().height / 2));
    left_button->addReleaseEvent(this, coco_releaseselector(CocosGUIExamplesPageScene::toCocosGUIExamplesMapScene));
    m_pUILayer->addWidget(left_button);
    
    // right button
    UIButton* right_button = UIButton::create();
    right_button->setTouchEnable(true);
    right_button->loadTextures("cocosgui/UITest/f1.png", "cocosgui/UITest/f2.png", "");
    right_button->setPosition(ccp(m_pUILayer->getContentSize().width - right_button->getContentSize().width / 2, m_pUILayer->getContentSize().height / 2));
    right_button->addReleaseEvent(this, coco_releaseselector(CocosGUIExamplesPageScene::toCocosGUIExamplesPageSpecialScene));
    m_pUILayer->addWidget(right_button);
     */
    
    // exit button
    UIButton* exit_button = UIButton::create();
    exit_button->setTouchEnabled(true);
    exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    exit_button->setPosition(ccp(m_pUILayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
    exit_button->addReleaseEvent(this, coco_releaseselector(CocosGUIExamplesPageScene::menuCloseCallback));
    m_pUILayer->addWidget(exit_button);
}

void CocosGUIExamplesPageScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    CCSSceneReader::sharedSceneReader()->purgeSceneReader();
    UIHelper::purgeUIHelper();
    UIActionManager::purgeUIActionManager();
    
    CCScene::onExit();
}

void CocosGUIExamplesPageScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/*
void CocosGUIExamplesPageScene::runThisTest()
{
    CCDirector::sharedDirector()->replaceScene(this);
}

void CocosGUIExamplesPageScene::toCocosGUIExamplesMapScene(CCObject *pSender)
{
    CocosGUIExamplesMapScene* pScene = new CocosGUIExamplesMapScene();
    pScene->runThisTest();
    pScene->release();    
}

void CocosGUIExamplesPageScene::toCocosGUIExamplesPageSpecialScene(CCObject *pSender)
{
    CocosGUIExamplesPageSpecialScene* pScene = new CocosGUIExamplesPageSpecialScene();
    pScene->runThisTest();
    pScene->release();
}
 */

void CocosGUIExamplesPageScene::PageInit()
{
    // page root from json
    Layout* page_root = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/gui_examples/page_1/page_1.json"));
    m_pUILayer->addWidget(page_root);
    
    // page layout
    Layout* page_layout = dynamic_cast<Layout*>(page_root->getChildByName("page_panel"));
    
    // page view add to page layout
    UIPageView* pageView = UIPageView::create();
    pageView->setTouchEnabled(true);
    pageView->setSize(page_layout->getContentSize());
    
    // layout add to page view
    for (int i = 0; i < 4; ++i)
    {
        Layout* layout = Layout::create();
        layout->setSize(pageView->getContentSize());
        
        UIImageView* imageView = UIImageView::create();
        imageView->setTouchEnabled(true);
        imageView->loadTexture(page_image_textures[i]);
        imageView->setPosition(ccp(layout->getContentSize().width / 2, layout->getContentSize().height / 2));
        layout->addChild(imageView);                
        
        pageView->addPage(layout);
    }    
    pageView->addPageTurningEvent(this, coco_PageView_PageTurning_selector(CocosGUIExamplesPageScene::pageTurningEvent));
    page_layout->addChild(pageView);
}

void CocosGUIExamplesPageScene::pageTurningEvent(CCObject* pSender)
{
    UIPageView* pageView = dynamic_cast<UIPageView*>(pSender);
    int page = pageView->getPage() + 1;
    
    Layout* page_root = dynamic_cast<Layout*>(m_pUILayer->getWidgetByName("page_root"));
    
    // set current page number for text
    UILabel* page_alert_label = dynamic_cast<UILabel*>(page_root->getChildByName("page_alert_label"));
    page_alert_label->setText(CCString::createWithFormat("page %d", page)->getCString());
    
    // set current page for image
    Layout* page_alert_bottom_layout = dynamic_cast<Layout*>(page_root->getChildByName("page_alert_bottom_panel"));
    int count = page_alert_bottom_layout->getChildren()->count();
    for (int i = count / 2; i < count; ++i)
    {
        UIWidget* child = dynamic_cast<UIWidget*>(page_alert_bottom_layout->getChildren()->objectAtIndex(i));
        child->setVisible(false);
    }    
    UIImageView* page_imageview = dynamic_cast<UIImageView*>(page_root->getChildByName(CCString::createWithFormat("page_%d_imageview", page)->getCString()));
    page_imageview->setVisible(true);
}