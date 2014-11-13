#include "HelloWorldScene.h"

USING_NS_CC;
using namespace cocos2d::extension;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
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
    //init info
	setTouchEnabled(true);
	count = 0;
	//add armature
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("100.png","100.plist","10.ExportJson");
	armature = CCArmature::create("10");
	armature->setPosition(ccp(visibleSize.width * 0.8,visibleSize.height * 0.5));
	armature->getAnimation()->playByIndex(0);
	armature->setScale(0.25);
	this->addChild(armature);
    
	// create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Touch Screen to Change Animation", "Arial", 30);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width*0.5,
                            origin.y + visibleSize.height * 0.2));
	this->addChild(pLabel,0);

    return true;
}

bool HelloWorld::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	count++;
	count = count% armature->getAnimation()->getMovementCount();
	armature->getAnimation()->playByIndex(count);
	return false;
}

void HelloWorld::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, INT_MIN+1, true);
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	cocos2d::extension::CCArmatureDataManager::purge();

	cocos2d::extension::ActionManager::shareManager()->purge();
	cocos2d::extension::SceneReader::sharedSceneReader()->purge();
	GUIReader::shareReader()->purge();

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    CCDirector::sharedDirector()->end();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    exit(0);
#endif
}
