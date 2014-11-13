//
//  Player.h
//  CowboyScene
//
//  Created by NiTe Luo on 10/17/13.
//
//

#ifndef __CowboyScene__Player__
#define __CowboyScene__Player__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocostudio;
using namespace std;

#define WALK_SPEED 10
#define WALK_LEFT 1
#define WALK_RIGHT -1

enum PlayerState {
    IDLE = 0,
    WALK,
    SHOOT,
    GRENADE
    };

class Player : public CCObject
{
    CCNode* playerNode;
    ArmatureAnimation* animation;
    PlayerState currentState;
    PlayerState newState;
    int direction;
    bool lockState;
    
    void onAnimationEvent(Armature *pArmature, MovementEventType eventType, const char *animationID);
    
public:
    Player(CCNode* node);
    void update(float dt);
    void updateAnimation();
    void updateMovement();
    void play(string animName);
    bool isLockState();
    
    inline void setState(PlayerState state) {newState = state;}
    void setDirection(int newDirection);
};

#endif /* defined(__CowboyScene__Player__) */
