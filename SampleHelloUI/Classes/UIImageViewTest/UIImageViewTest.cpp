

#include "UIImageViewTest.h"

const char* font_UIImageViewTest =
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
"Marker Felt";
#else
"cocosgui/Marker Felt.ttf";
#endif

// UIImageViewTest

bool UIImageViewTest::init()
{
    if (UIScene::init())
    {
        CCSize widgetSize = m_pWidget->getSize();
        
        UILabel *alert = UILabel::create();
        alert->setText("ImageView");
        alert->setFontName(font_UIImageViewTest);
        alert->setFontSize(30);
        alert->setColor(ccc3(159, 168, 176));
        alert->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f - alert->getSize().height * 1.75));
        m_pUiLayer->addWidget(alert);        
        
        // Create the imageview
        UIImageView *imageView = UIImageView::create();
        imageView->loadTexture("cocosgui/ccicon.png");
        imageView->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f + imageView->getSize().height / 4.0f));
        m_pUiLayer->addWidget(imageView);
        
        return true;
    }
    return false;
}


// UIImageViewTest_Scale9

bool UIImageViewTest_Scale9::init()
{
    if (UIScene::init())
    {
        CCSize widgetSize = m_pWidget->getSize();
        
        UILabel *alert = UILabel::create();
        alert->setText("ImageView scale9 render");
        alert->setFontName(font_UIImageViewTest);
        alert->setFontSize(30);
        alert->setColor(ccc3(159, 168, 176));
        alert->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f - alert->getSize().height * 1.75));
        m_pUiLayer->addWidget(alert);        
        
        // Create the imageview
        UIImageView *imageView = UIImageView::create();
        imageView->setScale9Enabled(true);
        imageView->loadTexture("cocosgui/buttonHighlighted.png");
        imageView->setSize(CCSizeMake(200, 85));
        imageView->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f + imageView->getSize().height / 4.0f));
        m_pUiLayer->addWidget(imageView);
        
        return true;
    }
    return false;
}