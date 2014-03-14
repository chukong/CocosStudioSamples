#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Box2D/Box2D.h"

class Enemy	: public cocos2d::CCLayer
{
public:
	virtual bool init();
	virtual void update(float delta);
	virtual void onExit();
	
	virtual void beHitted() = 0;
	virtual void defineAction(cocos2d::CCAction* action = NULL) = 0;
	bool IsEnemyDied(){return hitPoints<=0;}
	cocos2d::extension::CCArmature* getArmature()
		{return enemyArmature;}

protected:
	int hitPoints;
	cocos2d::extension::CCArmature* enemyArmature;
};

class KnightEnemy : public Enemy
{
public:
	static KnightEnemy* create(cocos2d::CCPoint startPostion,
		int HP=100,float scaleX=1.0,float scaleY=1.0);
	virtual bool init(cocos2d::CCPoint startPostion,
		int HP,float scaleX,float scaleY);
	
	virtual void beHitted();
	
	void defineAction(cocos2d::CCAction* action = NULL);

};

class RobotEnemy : public Enemy
{
public:
	static RobotEnemy* create(cocos2d::CCPoint startPostion,
		int HP=100,float scaleX=1.0,float scaleY=1.0);
	virtual bool init(cocos2d::CCPoint startPostion,
		int HP,float scaleX,float scaleY);
	
	virtual void beHitted();
	virtual void defineAction(cocos2d::CCAction* action = NULL){}
};
#endif