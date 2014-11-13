#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
	// a selector callback about a  touch event began
	bool onTouchBegan(Touch* touch, Event* event);

	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(Object* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(HelloWorld);
private:
	cocostudio::Armature* armature;
	int count;
};

#endif // __HELLOWORLD_SCENE_H__
