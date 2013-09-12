

#include "CocosGUIExamplesUIAnimationScene.h"
//#include "CocosGUIExamplesPageSpecialScene.h"

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
    
    
    // text button to start animation
    UITextButton* start_textbutton = UITextButton::create();
    start_textbutton->setTouchEnabled(true);
    start_textbutton->setTitleText("Start UIAnimation");
    start_textbutton->loadTextures("cocosgui/backtotoppressed.png", "cocosgui/backtotopnormal.png", "");
    start_textbutton->setScale9Enabled(true);
    start_textbutton->setSize(CCSizeMake(start_textbutton->getContentSize().width * 1.3, start_textbutton->getContentSize().height));
    start_textbutton->setPosition(ccp(m_pUILayer->getContentSize().width / 2, start_textbutton->getContentSize().height - start_textbutton->getContentSize().height / 4));
    start_textbutton->addReleaseEvent(this, coco_releaseselector(CocosGUIExamplesUIAnimationScene::startUIAnimation));
    m_pUILayer->addWidget(start_textbutton);
    
    /*
    // left button
    UIButton* left_button = UIButton::create();
    left_button->setTouchEnable(true);
    left_button->loadTextures("cocosgui/UITest/b1.png", "cocosgui/UITest/b2.png", "");
    float left_button_width = left_button->getContentSize().width;
    left_button->setPosition(ccp(left_button_width + left_button_width / 2, left_button->getContentSize().height / 1.5));
    left_button->addReleaseEvent(this, coco_releaseselector(CocosGUIExamplesUIAnimationScene::toCocosGUIExamplesPageSpecialScene));
    m_pUILayer->addWidget(left_button);
     */
    
    // exit button
    UIButton* exit_button = UIButton::create();
    exit_button->setTouchEnabled(true);
    exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    exit_button->setPosition(ccp(m_pUILayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
    exit_button->addReleaseEvent(this, coco_releaseselector(CocosGUIExamplesUIAnimationScene::menuCloseCallback));
    m_pUILayer->addWidget(exit_button);
}

void CocosGUIExamplesUIAnimationScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    CCSSceneReader::sharedSceneReader()->purgeSceneReader();
    UIHelper::purgeUIHelper();
    UIActionManager::purgeUIActionManager();
    
    CCScene::onExit();
}

void CocosGUIExamplesUIAnimationScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/*
void CocosGUIExamplesUIAnimationScene::runThisTest()
{
    CCDirector::sharedDirector()->replaceScene(this);
}

void CocosGUIExamplesUIAnimationScene::toCocosGUIExamplesPageSpecialScene(CCObject *pSender)
{
    CocosGUIExamplesPageSpecialScene* pScene = new CocosGUIExamplesPageSpecialScene();
    pScene->runThisTest();
    pScene->release();
}
 */

void CocosGUIExamplesUIAnimationScene::UIAnimationInit()
{
    // ui animation root from json
    Layout* uianimation_root = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("cocosgui/gui_examples/UIAction_1/UIAction_1.json"));
    m_pUILayer->addWidget(uianimation_root);
}

void CocosGUIExamplesUIAnimationScene::startUIAnimation(CCObject *pSender)
{
    UIActionManager::shareManager()->PlayActionByName("UIAction_1.json", "Animation1");
}