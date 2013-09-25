//
//  CCJoyStick.cpp
//  GameDemo
//
//  Created by Solo on 13-8-14.
//  more info from //  see http://www.cocoachina.com/bbs/read.php?tid=122995

#ifndef __GameDemo__CCJoyStick_H_
#define __GameDemo__CCJoyStick_H_

#include "cocos2d.h"

using namespace cocos2d;

/**
 *  to build a new class for joystick
 *  then you can define joystick function
 */
class CCJoyStickDelegate {
public:
	/**
	 *  Get joystick info update to use joystick
	 *  @param sender this CCJoyStick
	 *  @param angle  the angle of joystick button
	 *  @param direction the direction of joystick button
	 *  @param power the power of player to hold joystick
	 */
	virtual void onCCJoyStickUpdate(CCNode* sender, float angle,
                                    CCPoint direction, float power) = 0;
	/**
	 *  to active joystick
	 */
	virtual void onCCJoyStickActivated(CCNode* sender) {
		CC_UNUSED_PARAM(sender);
	}
	/**
	 *  to deactive joystick
	 */
	virtual void onCCJoyStickDeactivated(CCNode* sender) {
		CC_UNUSED_PARAM(sender);
	}
};

class CCJoystick: public CCLayer 
{
public:
	/**
	 * create joystick return CCJoyStick*
	 * @param ballradius is the radius of joystick
	 * @param movearearadius is the area of joystick
	 * @param isfollowtouch true,joystick will change position when touch
	 * @param iscanvisible true,you can see the joystick
	 * @param isautohide true,joystick will hide when not using
	 * @param hasanimation,define if joystick hava animation
	 */
	static CCJoystick* create(int ballradius, int movearearadius,
                              bool isfollowtouch = true, bool iscanvisible = true,
                              bool isautohide = false, bool hasanimation = false);
	bool init(int ballradius, int movearearadius, bool isfollowtouch,
              bool iscanvisible, bool isautohide, bool hasanimation);
    
	void setDelegate(const CCJoyStickDelegate *pDelegate) {
		delegate = const_cast<CCJoyStickDelegate*>(pDelegate);
	}
	/**
	 * set joystick button texture
	 */
	void setBallTexture(const char* imageName);
	/**
	 *  set joystick base texture
	 */
	void setStickTexture(const char* imageName);
	/**
	 *  set joystick background texture
	 */
	void setDockTexture(const char* imageName);
public:
	CCJoystick(void);
	virtual ~CCJoystick(void);
private:
	//joystick info
	CCSprite* ball;
	CCSprite* stick;
	CCSprite* dock;
	int moveAreaRadius;
	int ballRadius;
	bool isFollowTouch;
	bool isCanVisible;
	bool isAutoHide;
	CCRect activeRect;
	int activeRadius;
	CCPoint currentPoint;
	bool isTouched;
	bool hasAnimation;
	float power;
	float angle;
	CCPoint direction;
	CCJoyStickDelegate *delegate;
private:
	void setHitAreaWithRadius(int radius);
	void setHitAreaWithRect(CCRect rect);
	void startTimer();
	void stopTimer();
	void timerUpdate();
	void timerUpdate(float dt);
	void onTouchBegan(CCPoint touchPoint);
	void resetTexturePosition();
	bool containsTouchLocation(CCTouch* touch);
	void updateTouchPoint(CCPoint touchPoint);
public:
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
};

class CCJoyStick {
public:
	CCJoyStick();
	virtual ~CCJoyStick();
};
#endif /* defined(__GameDemo__CCJoyStick__) */

