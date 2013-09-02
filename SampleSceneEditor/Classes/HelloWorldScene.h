#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	// a selector callback
	void menuSpriteComponentTestCallback(CCObject* pSender);

	// a selector callback
	void menuMapComponentTestCallback(CCObject* pSender);

	// a selector callback
	void menuParticleComponentTestCallback(CCObject* pSender);
    
	// a selector callback
	void menuArmatureTestCallback(CCObject* pSender);

	// a selector callback
	void menuEffectComponentTestCallback(CCObject* pSender);

	// a selector callback
	void menuUIComponentTestCallback(CCObject* pSender);

	// a selector callback
	void menuAttributeComponentCallback(CCObject* pSender);

	// a selector callback
	void menuBackgroundMusicComponentTestCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

private:
	cocos2d::CCNode *m_pGameScene;
};

#endif // __HELLOWORLD_SCENE_H__
