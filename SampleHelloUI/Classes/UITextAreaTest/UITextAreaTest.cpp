

#include "UITextAreaTest.h"

const char* font_UITextAreaTest =
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
"Marker Felt";
#else
"cocosgui/Marker Felt.ttf";
#endif

// UITextAreaTest

bool UITextAreaTest::init()
{
    if (UIScene::init())
    {
        CCSize widgetSize = m_pWidget->getSize();
        
        UILabel *alert = UILabel::create();
        alert->setText("TextArea");
        alert->setFontName(font_UITextAreaTest);
        alert->setFontSize(30);
        alert->setColor(ccc3(159, 168, 176));
        alert->setPosition(ccp(widgetSize.width / 2.0f, widgetSize.height / 2.0f - alert->getSize().height * 1.75));
        m_pUiLayer->addWidget(alert);        
        
        // Create the text area
        UILabel* textArea = UILabel::create();
        textArea->setTextAreaSize(CCSizeMake(280, 150));
        textArea->setTextHorizontalAlignment(kCCTextAlignmentCenter);
        textArea->setText("TextArea widget can line wrap");
        textArea->setFontName("AmericanTypewriter");
        textArea->setFontSize(32);
        textArea->setPosition(ccp(widgetSize.width / 2, widgetSize.height / 2 - textArea->getSize().height / 8));
        m_pUiLayer->addWidget(textArea);        
        
        return true;
    }
    return false;
}