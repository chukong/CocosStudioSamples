#ifndef __PHYSICAL_WORLD_H__
#define __PHYSICAL_WORLD_H__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Player.h"
#include "EnemyListBuilder.h"
#include "ColliderToolKits.h"

#if ENABLE_PHYSICS_BOX2D_DETECT
#include "./include/GLES-Render.h"
#include "Box2D/Box2D.h"

class PhysicalWorld : public cocos2d::CCLayer
{
public:
	static PhysicalWorld* create(
		EnemyListBuilder* pBuilder=NULL,Player* pPlayer = NULL);
	~PhysicalWorld();

	virtual bool init(EnemyListBuilder* pBuilder,
		Player* pPlayer);
	virtual void update(float delta);
	virtual void draw();

	Player* getPlayer(){return player;}
	bool IsGameOver(){return player->IsGameOver();}
	bool IsPassStage() {return enemyListBuilder->IsEnemyAllDied();}

private:
	void initPhysics();
	void initPlayer(Player* pPlayer);
	void setPlayerFilterInfo(b2Body* body);

	void initEnemy(EnemyListBuilder* pBuilder);
	void addEnemyIntoWorld(Enemy* pEnemy);
	void setEnemyFilterInfo(b2Body* body,Enemy* pEnemy);

	void onFrameEvent(cocos2d::extension::CCBone *bone, const char *evt, 
		int originFrameIndex, int currentFrameIndex);
	void createBullet(cocos2d::CCPoint startPosition,cocos2d::CCActionInterval *bulletAction);
	void setBulletFilterInfo(b2Body* body,cocos2d::extension::CCPhysicsSprite* bullet);
	void destroyBullet(cocos2d::CCNode* sender,void* data);

	void processContactList();

	void processDiedEnemy();
	void destroyEnemy(Enemy* pEnemy);

	b2World* world;
	MyContactListener* contactListener;
	GLESDebugDraw* debugDraw;

	Player* player;
	EnemyListBuilder* enemyListBuilder;
};

#endif
#endif