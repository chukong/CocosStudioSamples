#include "HelloWorldScene.h"
#include "VisibleRect.h"
#include "cocos-ext.h"
#include "cocostudio/CCSSceneReader.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CCActionManagerEx.h"
#include "cocostudio/CCArmatureDataManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    Node *pFishJoyScene = cocostudio::SceneReader::getInstance()->createNodeWithSceneFile("FishJoy2.json");
	this->addChild(pFishJoyScene);
    cocostudio::ActionManagerEx::getInstance()->playActionByName("startMenu_1.json","Animation1");
    
    
    LabelTTF* label = CCLabelTTF::create("End", "Marker Felt", 40);
    auto itemBack = MenuItemLabel::create(label, CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    itemBack->setColor(Color3B(255, 255, 255));
    itemBack->setPosition(Point(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
    
    Menu* menuBack =Menu::create(itemBack, NULL);
    menuBack->setPosition( Point::ZERO );
    menuBack->setZOrder(4);
    this->addChild(menuBack);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    cocostudio::ArmatureDataManager::destroyInstance();
	cocostudio::SceneReader::destroyInstance();
    cocostudio::GUIReader::destroyInstance();
    cocostudio::ActionManagerEx::destroyInstance();
    
    CCDirector::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

}
