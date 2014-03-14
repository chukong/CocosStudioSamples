#ifndef __MYCONTROLLER_H__
#define __MYCONTROLLER_H__

#include "./include/CCJoyStick.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Player.h"
#include "PlayerHeadUI.h"

class MyController : public cocos2d::CCLayer
{
public:
	public:
    /**
     *  create a joy stick and two buttons
     */
    static MyController* create();
    virtual bool init();
	~MyController(){}

	void bindPlayer(Player* pPlayer);
private:
	CCJoystick* createJoystick();
	cocos2d::ui::UILayer* createButton();
    /**
     *  call back for button
     */
    void touchEvent(cocos2d::CCObject* pSender,cocos2d::ui::TouchEventType type);
	void bindPlayerStateMachine();

	Player* player;
	PlayerStateMachine* playerStateMachine;
	CCJoystick* joyStick;
	PlayerHeadUI* headUI;
};

class MyJoyStickDelegate : public CCJoyStickDelegate
{
public:
    /**
     *  Get joystick info update to use joystick
     *  @param sender this CCJoyStick
     *  @param angle  the angle of joystick button
     *  @param direction the direction of joystick button
     *  @param power the power of player to hold joystick
     */
    void onCCJoyStickUpdate(cocos2d::CCNode* sender,float angle,cocos2d::CCPoint direction,float power);
    /**
     *  to active joystick
     */
    void onCCJoyStickActivated(cocos2d::CCNode* sender);
    /**
     *  to deactive joystick
     */
    void onCCJoyStickDeactivated(cocos2d::CCNode* sender);
	
	void bindPlayerStateMachine(PlayerStateMachine* pMachine)
		{playerStateMachine = pMachine;}
private:
	PlayerStateMachine* playerStateMachine;
};


#endif