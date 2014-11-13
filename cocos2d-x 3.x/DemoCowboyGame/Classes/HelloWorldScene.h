#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "CocosGUI.h"
using namespace cocos2d;
using namespace cocos2d::ui;

class HelloWorld : public cocos2d::Layer
{
private:

	Player* player;
public:
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* createScene();

	// a selector callback
	void menuCloseCallback(Ref* pSender);
	void onMoveLeft(CCObject* pSender, TouchEventType type);
	void onMoveRight(CCObject* pSender, TouchEventType type);
	void onFire(CCObject* pSender, TouchEventType type);

	// implement the "static node()" method manually
	CREATE_FUNC(HelloWorld);

	virtual void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
