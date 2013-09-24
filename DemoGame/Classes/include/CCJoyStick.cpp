//
//  CCJoyStick.cpp
//  GameDemo
//
//  Created by Solo on 13-8-14.
//  more info from //  see http://www.cocoachina.com/bbs/read.php?tid=122995

#include "CCJoyStick.h"

CCJoystick* CCJoystick::create(int ballradius, int movearearadius,
                               bool isfollowtouch, bool iscanvisible, bool isautohide,
                               bool hasanimation) {
	CCJoystick *pRet = new CCJoystick();
	if (pRet
        && pRet->init(ballradius, movearearadius, isfollowtouch,
                      iscanvisible, isautohide, hasanimation)) {
            pRet->autorelease();
            return pRet;
        }
	CC_SAFE_DELETE(pRet);
	return NULL;
}

bool CCJoystick::init(int ballradius, int movearearadius, bool isfollowtouch,
                      bool iscanvisible, bool isautohide, bool hasanimation) {
	if (CCLayer::init()) {
		ballRadius = ballradius;
		moveAreaRadius = movearearadius;
		isFollowTouch = isfollowtouch;
		isCanVisible = iscanvisible;
		isAutoHide = isautohide;
		hasAnimation = hasanimation;
        
		power = 0;
		angle = 0;
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		setHitAreaWithRect(CCRect(0, 0, size.width / 2, size.height / 2));
        
		ball = CCSprite::create();
		stick = CCSprite::create();
		dock = CCSprite::create();
        
		addChild(dock);
		addChild(stick);
		addChild(ball);
        
		if (!isCanVisible) {
			setVisible(false);
		} else {
			if (isAutoHide) {
				setVisible(false);
			}
		}
		return true;
	}
	return false;
}

CCJoystick::CCJoystick(void) :
power(0), angle(0), delegate(NULL) {
}

CCJoystick::~CCJoystick(void) {
    
}
void CCJoystick::onEnter() {
	CCLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(
                                                                            this, 0, true);
}

void CCJoystick::onExit() {
	CCLayer::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool CCJoystick::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
	if (!containsTouchLocation(pTouch)) {
		return false;
	}
    
	CCPoint touchPoint = pTouch->getLocationInView();
	touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
	onTouchBegan(touchPoint);
    
	return true;
}

void CCJoystick::onTouchBegan(CCPoint touchPoint) {
	currentPoint = touchPoint;
	isTouched = true;
	if (isAutoHide && isCanVisible) {
		setVisible(true);
	}
    
	if (isFollowTouch) {
		setPosition(ccp(touchPoint.x,touchPoint.y));
	}
	ball->stopAllActions();
	updateTouchPoint(touchPoint);
	startTimer();
}

void CCJoystick::updateTouchPoint(CCPoint touchPoint) {
	CCPoint selfposition = getParent()->convertToWorldSpace(getPosition());
	if (ccpDistance(touchPoint, ccp(selfposition.x,selfposition.y)) > (moveAreaRadius-ballRadius))
	{
		currentPoint =ccpAdd(ccp(0,0),ccpMult(ccpNormalize(ccpSub(ccp(touchPoint.x-selfposition.x,touchPoint.y-selfposition.y), ccp(0,0))), moveAreaRadius-ballRadius));
	} else {
		currentPoint = ccp(touchPoint.x-selfposition.x,touchPoint.y-selfposition.y);
	}
	ball->setPosition(currentPoint);
    
	angle = atan2(ball->getPositionY() - 0, ball->getPositionX() - 0)
    / (3.14159 / 180);
	power = ccpDistance(ball->getPosition(), ccp(0,0))/(moveAreaRadius-ballRadius);
	direction = ccp(cos(angle * (3.14159/180)),sin(angle * (3.14159/180)));
    
	CCSprite *sticktexture = (CCSprite*) stick->getChildByTag(0);
	stick->setScaleX(ccpDistance(ball->getPosition(), ccp(0, 0))/sticktexture->getTextureRect().size.width);
	stick->setRotation(-angle);
}

void CCJoystick::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {
	CCPoint touchPoint = pTouch->getLocationInView();
	touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    
	if (isTouched) {
		updateTouchPoint(touchPoint);
	}
}

void CCJoystick::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) {
	if (isTouched) {
		if (isAutoHide && isCanVisible) {
			setVisible(false);
		}
		isTouched = false;
		stopTimer();
		resetTexturePosition();
	}
}

bool CCJoystick::containsTouchLocation(CCTouch* touch) {
	CCPoint touchPoint = touch->getLocationInView();
	touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
	if (activeRadius > 0) {
		if (ccpDistance(touchPoint,
                        getParent()->convertToWorldSpace(
                                                         ccp(getPositionX(),getPositionY()))) < activeRadius) {
                            return true;
                        }
	}
	if (activeRect.size.width > 0 && activeRect.size.height > 0) {
		if (touchPoint.x > activeRect.origin.x
            && touchPoint.x < activeRect.origin.x + activeRect.size.width
            && touchPoint.y > activeRect.origin.y
            && touchPoint.y
            < activeRect.origin.y + activeRect.size.height) {
			return true;
		}
	}
	return false;
}

void CCJoystick::resetTexturePosition() {
	power = 0;
	angle = 0;
    
	currentPoint = ccp(0,0);
	stick->setPosition(ccp(0, 0));
	stick->setScaleX(power);
    
	if (!isAutoHide && isCanVisible && hasAnimation) {
		CCActionInterval *action = CCMoveTo::create(.5, ccp(0 ,0));
		ball->runAction(CCEaseElasticOut::create(action));
	} else {
		ball->setPosition(ccp(0, 0));
	}
}

void CCJoystick::startTimer() {
	if (delegate != NULL) {
		delegate->onCCJoyStickActivated(this);
	}
	schedule(schedule_selector(CCJoystick::timerUpdate));
}

void CCJoystick::stopTimer() {
	if (delegate != NULL) {
		delegate->onCCJoyStickDeactivated(this);
	}
	unschedule(schedule_selector(CCJoystick::timerUpdate));
}

void CCJoystick::timerUpdate() {
	if (delegate != NULL) {
		delegate->onCCJoyStickUpdate(this, angle, direction, power);
	}
}

void CCJoystick::timerUpdate(float dt) {
	timerUpdate();
}

void CCJoystick::setBallTexture(const char* imageName) {
	ball->removeAllChildrenWithCleanup(true);
    
	CCSprite *balltexture = CCSprite::create(imageName);
    
	ball->addChild(balltexture);
}

void CCJoystick::setStickTexture(const char* imageName) {
	stick->removeAllChildrenWithCleanup(true);
    
	CCSprite *sticktexture = CCSprite::create(imageName);
	sticktexture->setPosition(ccp(sticktexture->getContentSize().width/2,0));
    
	stick->addChild(sticktexture, 0, 0);
    
	stick->setScaleX(ccpDistance(ball->getPosition(), ccp(0,0))/sticktexture->getTextureRect().size.width);
}

void CCJoystick::setDockTexture(const char* imageName) {
	dock->removeAllChildrenWithCleanup(true);
    
	CCSprite *docktexture = CCSprite::create(imageName);
    
	dock->addChild(docktexture);
}

void CCJoystick::setHitAreaWithRadius(int radius) {
	activeRect = CCRect(0, 0, 0, 0);
	activeRadius = radius;
}

void CCJoystick::setHitAreaWithRect(CCRect rect) {
	activeRect = rect;
	activeRadius = 0;
}

CCJoyStick::CCJoyStick() {
	// TODO Auto-generated constructor stub
    
}

CCJoyStick::~CCJoyStick() {
	// TODO Auto-generated destructor stub
}

