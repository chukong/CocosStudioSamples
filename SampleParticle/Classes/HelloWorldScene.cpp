#include "HelloWorldScene.h"
#include "CocosGUI.h"
#include "cocostudio/CocoStudio.h"



USING_NS_CC;
using namespace cocostudio;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }
    
	Size visibleSize = CCDirector::getInstance()->getVisibleSize();
	Point origin = CCDirector::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	MenuItemImage *pCloseItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));

	pCloseItem->setPosition(Point(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	Menu* pMenu = Menu::create(pCloseItem, NULL);
	pMenu->setPosition(Point::ZERO);
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	ArmatureDataManager::getInstance()->addArmatureFileInfo("hero/Hero.ExportJson");
	Armature* armature = Armature::create("Hero");
	armature->getAnimation()->play("attack");
	armature->setScale(1.5);
	armature->setPosition(Point(visibleSize.width*0.25, visibleSize.height*0.25));

	addChild(armature);

    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
