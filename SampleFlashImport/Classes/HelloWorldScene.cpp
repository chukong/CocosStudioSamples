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
    // init info
	setTouchEnabled(true);
	countDragon = 0;
	countRobot = 0;
	//load armature data
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Dragon.png","Dragon.plist","Dragon.xml");
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("robot.png","robot.plist","robot.xml");
	//createa dragon flash armature
	dragon = CCArmature::create("Dragon");
	dragon->setPosition(ccp(visibleSize.width * 0.7,visibleSize.height * 0.5 -150));
	dragon->getAnimation()->playByIndex(0);
	dragon->getAnimation()->setSpeedScale(0.3);
	dragon->setScale(0.7);
	this->addChild(dragon,1);
	//create robot flash armature
	robot = CCArmature::create("robot");
	robot->setPosition(ccp(visibleSize.width * 0.3,visibleSize.height * 0.5));
	robot->getAnimation()->playByIndex(0);
	robot->setScale(0.8);
	this->addChild(robot,1);
	

    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Touch Screen to Change Animation", "Arial", 30);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width*0.5,
                            origin.y + visibleSize.height * 0.1));
	this->addChild(pLabel,0);
    
    return true;
}

bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	//change animation index
	countDragon++;
	countDragon = countDragon % dragon->getAnimation()->getMovementCount();
	countRobot++;
	countRobot = countRobot % robot->getAnimation()->getMovementCount();
	//set change to armature
	dragon->getAnimation()->playByIndex(countDragon);
	robot->getAnimation()->playByIndex(countRobot);
	return false;
}

void HelloWorld::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, INT_MIN+1, true);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCArmatureDataManager::purge();
	CCSSceneReader::sharedSceneReader()->purgeSceneReader();
	cocos2d::extension::UIActionManager::shareManager()->purgeUIActionManager();
	cocos2d::extension::UIHelper::instance()->purgeUIHelper();
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
