#include "HelloWorldScene.h"


USING_NS_CC;

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
    
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...
	/*CCNode* gameScene = CCSSceneReader::sharedSceneReader()->createNodeWithSceneFile("DemoCowboy.json");*/
	CCNode* gameScene = SceneReader::getInstance()->createNodeWithSceneFile("DemoCowboy.json");
	addChild(gameScene);

	//Create player
	CCNode* playerNode = gameScene->getChildByTag(10004);
	player = new Player(playerNode);

	//Assign callbacks to the buttons
	CCNode* uiNode = gameScene->getChildByTag(10005);
	ComRender *render = static_cast<ComRender*>(uiNode->getComponent("GUIComponent"));
	Widget* ui = (Widget*)render->getNode();

	Button* btnLeft = static_cast<Button*>(Helper::seekWidgetByName(ui,"LeftButton"));
	btnLeft->addTouchEventListener(this, toucheventselector(HelloWorld::onMoveLeft));

	Button* btnRight = static_cast<Button*>(Helper::seekWidgetByName(ui,"RightButton"));
	btnRight->addTouchEventListener(this, toucheventselector(HelloWorld::onMoveRight));

	Button* btnFire = static_cast<Button*>(Helper::seekWidgetByName(ui,"FireButton"));

	btnFire->addTouchEventListener(this, toucheventselector(HelloWorld::onFire));

	//Enable update loop
	this->scheduleUpdate();

	return true;
}

void HelloWorld::update(float dt)
{
	player->update(dt);
}

void HelloWorld::onMoveLeft(cocos2d::CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_BEGAN)
	{
		player->setDirection(WALK_LEFT);
		player->setState(WALK);
	}
	if (type == TOUCH_EVENT_ENDED)
	{
		player->setState(IDLE);
	}
}

void HelloWorld::onMoveRight(cocos2d::CCObject *pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_BEGAN)
	{
		player->setDirection(WALK_RIGHT);
		player->setState(WALK);
	}
	if (type == TOUCH_EVENT_ENDED)
	{
		player->setState(IDLE);
	}
}

void HelloWorld::onFire(cocos2d::CCObject *pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_BEGAN)
	{
		player->setState(SHOOT);
	}
	if (type == TOUCH_EVENT_ENDED)
	{
		player->setState(IDLE);
	}
}

void HelloWorld::menuCloseCallback( Ref* pSender )
{
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

