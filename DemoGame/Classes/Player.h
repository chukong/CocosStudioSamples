#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "cocos-ext.h"

#define PLAYER_MAX_HP 100

class PlayerStateMachine
{
public:
	PlayerStateMachine();
	~PlayerStateMachine();

	int getState();
	cocos2d::CCPoint getMovePosition(){return movePosition;}
	void reset(){playerState = 0;}

	void updateMoving(cocos2d::CCPoint direction)
		{movePosition = direction;}
	void updateActiveJoystick(bool pressJoystick)
		{this->pressJoystick = pressJoystick;}
	void updatePressButton(bool pressButton)
		{this->pressButton = pressButton;}
private:
	int playerState;

	bool pressJoystick;
	bool pressButton;
	cocos2d::CCPoint movePosition;
};


class Player : public cocos2d::CCLayer
{
public:
	static Player* create();
	~Player(void);

	virtual bool init();
	virtual void update(float delta);

	void beHitted();

	int getHPPercent(){return hitPonts;}
	int getLifeNum()	{return lifeNum;}

	cocos2d::extension::CCArmature* getArmature(){return playerArmature;}
	PlayerStateMachine* getStateMachine()
		{return playerStateMachine;}
	bool IsGameOver(){return isGameOver;}

private:
	void updatePosition();
	void updateAnimation();
	void initArmature();
	void playerRebirth();
	void animationEvent(cocos2d::extension::CCArmature *pArmature, 
		cocos2d::extension::MovementEventType movementType, const char *movementID);

	cocos2d::extension::CCArmature* playerArmature;
	PlayerStateMachine* playerStateMachine;

	bool IsLock();

	void setGameOver(bool over){isGameOver = over;}
	bool isGameOver;

	int lifeNum;
	int hitPonts;
	int playerState;
};
#endif