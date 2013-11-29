#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"

class HelloWorld : public cocos2d::CCLayer
{
private:
    Player* player;
    
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void onMoveLeft(CCObject* pSender, TouchEventType type);
    void onMoveRight(CCObject* pSender, TouchEventType type);
    void onFire(CCObject* pSender, TouchEventType type);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    virtual void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
