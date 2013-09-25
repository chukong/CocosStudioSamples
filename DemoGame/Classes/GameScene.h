#ifndef __DemoGame__GameScene__
#define __DemoGame__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "PhysicalWorld.h"
#include "EnemyListBuilder.h"

class GameScene	: public cocos2d::CCScene
{
public:
	//create GameScene depend on stage
	static GameScene* create(int stage = 1);
	virtual bool init(int stage);
	~GameScene(void){}

	void menuPopSceneCallback(CCObject* pSender);

};
#if ENABLE_PHYSICS_BOX2D_DETECT
class StageBasic : public cocos2d::CCLayer
{
public:
	virtual bool init();

	virtual void update(float delta);

	virtual bool initWorld();
	/**
     *  change stage,if player died,change to gameover scene
     *  @param playerOver,if playerOver true,change to gameover
     *                  scene.If playerOver false,change to next
     *                  stage or victory scene
     */
    void overStage(bool playerDied);

	virtual void changeToNextStage() = 0;
	void changeToOverScene();

	void menuTestCallback(CCObject* pSender);

protected:
	cocos2d::CCLayer* stageLayer;
	Player* player;
	EnemyListBuilder* enemyBuilder;
#if ENABLE_PHYSICS_BOX2D_DETECT
	PhysicalWorld* physicalWorld;
#endif
};

class StageOne : public StageBasic
{
public:
	static StageOne* create();
	virtual bool init();
	virtual void changeToNextStage();

	void menuNextStageCallback(cocos2d::CCObject* pSender);
};

class StageTwo : public StageBasic
{
public:
	static StageTwo* create();
	virtual bool init();
	virtual void changeToNextStage();
};

class GameOverScene : public cocos2d::CCScene
{
public:
	static GameOverScene* create();
	virtual bool init();

	void menuCloseCallback(cocos2d::CCObject* pSender);
};

class VictoryScene : public cocos2d::CCScene
{
public:
	//create a victory scene,define pItem depend on stage
	static VictoryScene* create();
	virtual bool init();

};
#endif

#endif