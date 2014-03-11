#include "GameScene.h"
#include "MyController.h"

using namespace cocos2d;
using namespace cocos2d::extension;
#if ENABLE_PHYSICS_BOX2D_DETECT
GameScene* GameScene::create(int stage)
{
	GameScene *pRet = new GameScene();
    if (pRet && pRet->init(stage))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool GameScene::init(int stage)
{
	bool bRet = false;
    do
    {
	    CCDirector * pDirector;
        CC_BREAK_IF( ! (pDirector = CCDirector::sharedDirector()) );
        this->setContentSize(pDirector->getWinSize());

        //add stage by stage number
        if(stage == 1)
        {
            this->addChild(StageOne::create());
        }
        else this->addChild(StageTwo::create());
        // success
        bRet = true;
    } while (0);
    return bRet;
}

void GameScene::menuPopSceneCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
}


bool StageBasic::init()
{
	if (!CCLayer::init()) return false;

	stageLayer = CCLayer::create();

	//create exit stage button
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png","CloseSelected.png",
                                                          this,
                                                          menu_selector(StageBasic::menuTestCallback));
    
	pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width*0.5 - pCloseItem->getContentSize().width/2 ,CCDirector::sharedDirector()->getVisibleSize().height * 0.5 - pCloseItem->getContentSize().height/2));
    this->addChild(CCMenu::create(pCloseItem,NULL),4);
	
	return true;
}

void StageBasic::menuTestCallback(CCObject* sender)
{
	overStage(false);
}


bool StageBasic::initWorld()
{
	physicalWorld = PhysicalWorld::create(enemyBuilder);
	stageLayer->addChild(physicalWorld,2);
	//set stageLayer follow player's armature
	stageLayer->runAction(CCFollow::create(physicalWorld->getPlayer()->getArmature(),CCRectMake(0,0,720,320)));

	//create controller layer
    MyController* controller = MyController::create();
    this->addChild(controller,4);
	controller->bindPlayer(physicalWorld->getPlayer());

	this->addChild(stageLayer);

	scheduleUpdate();
	
	return true;
}

void StageBasic::update(float delta)
{
	if(physicalWorld->IsGameOver()) overStage(true);
	if(physicalWorld->IsPassStage()) overStage(false);
}


void StageBasic::overStage(bool playerDied)
{
	if(playerDied)	changeToOverScene();
	else changeToNextStage();
}

void StageBasic::changeToOverScene()
{
	unscheduleUpdate();
	GameOverScene* overScene = GameOverScene::create();
	CCDirector::sharedDirector()->replaceScene(overScene);
}



StageOne* StageOne::create()
{
	StageOne* pRet = new StageOne();
    if(pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool StageOne::init()
{
	if(!StageBasic::init()) return false;
    

    CCSprite* pSprite = CCSprite::create("stage1.png");
    
    pSprite->setPosition(ccp(CCDirector::sharedDirector()->
		getVisibleSize().width * 0.5 , CCDirector::sharedDirector()->getVisibleSize().height * 0.5));
    stageLayer->addChild(pSprite, -1);
	
	enemyBuilder = new StageOneEnemyList();
    
	if(!StageBasic::initWorld()) return false;
    return true;
}

void StageOne::changeToNextStage()
{
	VictoryScene* victoryScene = VictoryScene::create();
	CCDirector::sharedDirector()->replaceScene(victoryScene);
}

void StageOne::menuNextStageCallback(CCObject* pSender)
{
	GameScene* stageTwoScene = GameScene::create(2);
	CCDirector::sharedDirector()->replaceScene(stageTwoScene);
}


StageTwo* StageTwo::create()
{
	StageTwo* pRet = new StageTwo();
    if(pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool StageTwo::init()
{
   	if(!StageBasic::init()) return false; 

    CCSprite* pSprite = CCSprite::create("stage2.png");
    
    pSprite->setPosition(ccp(CCDirector::sharedDirector()->
		getVisibleSize().width * 0.5 , CCDirector::sharedDirector()->getVisibleSize().height * 0.5));
    stageLayer->addChild(pSprite, -1);
    
	enemyBuilder = new StageTwoEnemyList();

	if(!StageBasic::initWorld()) return false;
    return true;
}

void StageTwo::changeToNextStage()
{
	VictoryScene* victoryScene = VictoryScene::create();
	CCDirector::sharedDirector()->replaceScene(victoryScene);
}


GameOverScene* GameOverScene::create()
{
	GameOverScene *pRet = new GameOverScene();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool GameOverScene::init()
{
	bool bRet = false;
    do
    {
        CCDirector * pDirector;
        CC_BREAK_IF( ! (pDirector = CCDirector::sharedDirector()) );
        this->setContentSize(pDirector->getWinSize());
        
        CCSprite* bg = CCSprite::create("gameover.png");
        bg->setPosition(ccp(pDirector->getWinSize().width * 0.5,pDirector->getWinSize().height * 0.5));
        this->addChild(bg);
        
        CCMenuItemFont* mainMenu = CCMenuItemFont::create("Back To Menu",
			this,menu_selector(GameScene::menuPopSceneCallback));
        CCMenuItemFont* close = CCMenuItemFont::create("Exit Game",
			this,menu_selector(GameOverScene::menuCloseCallback));
        CCMenu* menu = CCMenu::create(mainMenu,close,NULL);
        menu->setPosition(ccp(pDirector->getWinSize().width * 0.5,pDirector->getWinSize().height * 0.3));
        menu->alignItemsVertically();
        this->addChild(menu,1);
        // success
        bRet = true;
    } while (0);
    return bRet;
}

void GameOverScene::menuCloseCallback(CCObject* pSender)
{
    cocos2d::extension::CCArmatureDataManager::purge();
	cocos2d::extension::ActionManager::shareManager()->purge();
	cocos2d::extension::SceneReader::sharedSceneReader()->purge();
	cocos2d::extension::GUIReader::shareReader()->purge();
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
    CCDirector::sharedDirector()->end();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    exit(0);
#endif
}

VictoryScene* VictoryScene::create()
{
	    VictoryScene *pRet = new VictoryScene();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool VictoryScene::init()
{
	bool bRet = false;
    do
    {
        CCDirector * pDirector;
        CC_BREAK_IF( ! (pDirector = CCDirector::sharedDirector()) );
        this->setContentSize(pDirector->getWinSize());
        CCSprite* pSprite = CCSprite::create("victory.png");
        
        // position the sprite on the center of the screen
        pSprite->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width * 0.5 , CCDirector::sharedDirector()->getVisibleSize().height * 0.5));
        // add the sprite as a child to this layer
        addChild(pSprite, -1);
        
		//create menu for game victory
		CCMenuItemFont* backMenu = CCMenuItemFont::create("Back To Menu",this,menu_selector(GameScene::menuPopSceneCallback));
		CCMenuItemFont* exit = CCMenuItemFont::create("Exit",this,menu_selector(GameOverScene::menuCloseCallback));

		CCMenu* menu;
       /* if (pItem!= NULL)
        {
            menu = CCMenu::create(pItem,backMenu,exit,NULL);
        }
		else
		{*/
			menu = CCMenu::create(backMenu,exit,NULL);
		//}
		menu->alignItemsVertically();
		menu->setColor(ccc3(0,0,0));
		addChild(menu,3);

        
        // success
        bRet = true;
    } while (0);
    return bRet;
}

#else
GameScene* GameScene::create(int stage)
{
    return NULL;
}
bool GameScene::init(int stage)
{
    return false;
}
void GameScene::menuPopSceneCallback(cocos2d::CCObject *pSender)
{
}

#endif
