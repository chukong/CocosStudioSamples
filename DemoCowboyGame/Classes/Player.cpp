//
//  Player.cpp
//  CowboyScene
//
//  Created by NiTe Luo on 10/17/13.
//
//

#include "Player.h"


Player::Player(CCNode* playerNode)
:CCObject()
{
    this->playerNode = playerNode;
    ComRender* comRender = static_cast<ComRender*>(playerNode->getComponent("CCArmature"));
	Armature *animationNode = static_cast<Armature*>(comRender->getNode());
    this->animation = animationNode->getAnimation();
    this->animation->setMovementEventCallFunc(this, movementEvent_selector(Player::onAnimationEvent));
    currentState = IDLE;
    newState = IDLE;
    lockState = false;
}

void Player::setDirection(int newDirection)
{
    direction = newDirection;
    playerNode->setScaleX(direction * fabs(playerNode->getScaleX()));
}

void Player::update(float dt)
{
    if (currentState == newState || isLockState())
    {
        updateMovement();
    }
    else
    {
        currentState = newState;
        updateAnimation();
    }
}

void Player::updateMovement()
{
    CCPoint oldPos = playerNode->getPosition();
    if (currentState == WALK)
    {
        playerNode->setPosition(oldPos.x + -direction * WALK_SPEED, oldPos.y);
    }
}

void Player::updateAnimation()
{
    switch (currentState)
    {
        case IDLE:
            animation->play("stand");
            break;
        case SHOOT:
            animation->play("stand_fire");
            break;
        case WALK:
            animation->play("walk");
            break;
        case GRENADE:
            animation->play("grenade");
            lockState = true;
            break;
        default:
            break;
    }
}

bool Player::isLockState()
{
    return lockState;
}

void Player::onAnimationEvent(Armature *pArmature, MovementEventType eventType, const char *animationID)
{
    if (eventType == LOOP_COMPLETE)
    {
        if (strcmp(animationID, "grenade") == 0)
        {
            lockState = false;
            newState = IDLE;
        }
    }
}
