#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
   
	void menuCloseCallback(cocos2d::CCObject* pSender);
    
    void menuAttackCallback(cocos2d::CCObject* pSender);

	void animationEvent1(CCArmature *pArmature,
		MovementEventType movementType, const char *movementID);

	void animationEvent2(CCArmature *pArmature,
		MovementEventType movementType, const char *movementID);

	virtual void update(float delta);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

private:
	cocos2d::CCNode *m_pGameScene;

	bool m_bStart;

	float m_fPercent;
};

#endif // __HELLOWORLD_SCENE_H__
