

#include "CocosGUIExamplesPageScene.h"
#include "cocostudio/CCSSceneReader.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CCActionManagerEx.h"

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
    
    m_pUILayer = Layer::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);
    
    PageInit();
    
    Size winSize = CCDirector::getInstance()->getWinSize();
    
    Text* label = Text::create();
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
    label->setAnchorPoint(Point(0.5f, -1));
    label->setPosition(Point(winSize.width / 2.0f, winSize.height / 2.0f + label->getSize().height * 1.5));
    m_pUILayer->addChild(label);
    
    // exit button
    Button* exit_button = Button::create();
    exit_button->setTouchEnabled(true);
    exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    exit_button->setPosition(Point(m_pUILayer->getContentSize().width - exit_button->getSize().width, exit_button->getSize().height));
    exit_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesPageScene::menuCloseCallback));
    m_pUILayer->addChild(exit_button);
}

void CocosGUIExamplesPageScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    cocostudio::SceneReader::destroyInstance();
    cocostudio::GUIReader::destroyInstance();
    cocostudio::ActionManagerEx::destroyInstance();
    
    CCScene::onExit();
}

void CocosGUIExamplesPageScene::menuCloseCallback(Ref* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        CCDirector::getInstance()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void CocosGUIExamplesPageScene::PageInit()
{
    // page root from json
    _root = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosgui/gui_examples/page_1/page_1.json"));
    m_pUILayer->addChild(_root);
    
    // page layout
    Layout* page_layout = dynamic_cast<Layout*>(_root->getChildByName("page_panel"));
    
    // page view add to page layout
    PageView* pageView = PageView::create();
    pageView->setTouchEnabled(true);
    pageView->setSize(page_layout->getSize());
    
    // layout add to page view
    for (int i = 0; i < 4; ++i)
    {
        Layout* layout = Layout::create();
        layout->setSize(pageView->getSize());
        
        ImageView* imageView = ImageView::create();
        imageView->setTouchEnabled(true);
        imageView->loadTexture(page_image_textures[i]);
        imageView->setPosition(Point(layout->getSize().width / 2, layout->getSize().height / 2));
        layout->addChild(imageView);                
        
        pageView->addPage(layout);
    }
    pageView->addEventListenerPageView(this, pagevieweventselector(CocosGUIExamplesPageScene::pageViewEvent));
    page_layout->addChild(pageView);
}

void CocosGUIExamplesPageScene::pageViewEvent(Ref *pSender, PageViewEventType type)
{
    PageView* pageView = dynamic_cast<PageView*>(pSender);
    int page = pageView->getCurPageIndex() + 1;
    
    // set current page number for text
    Text* page_alert_label = dynamic_cast<Text*>(Helper::seekWidgetByName(_root, "page_alert_label"));
    page_alert_label->setText(CCString::createWithFormat("page %d", page)->getCString());
    
    // set current page for image
    Layout* page_alert_bottom_layout = dynamic_cast<Layout*>(Helper::seekWidgetByName(_root, "page_alert_bottom_panel"));
    int count = page_alert_bottom_layout->getChildren().size();
    for (int i = count / 2; i < count; ++i)
    {
        Widget* child = dynamic_cast<Widget*>(page_alert_bottom_layout->getChildren().at(i));
        child->setVisible(false);
    }
    ImageView* page_imageview = dynamic_cast<ImageView*>(Helper::seekWidgetByName(_root, CCString::createWithFormat("page_%d_imageview", page)->getCString()));
    page_imageview->setVisible(true);
}
