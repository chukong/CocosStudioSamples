#ifndef __PARTICLE_COWBOY_H__
#define __PARTICLE_COWBOY_H__
#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class ParticleCowboy : public CCLayer
{
public:
	virtual void onEnter();
	virtual void onExit();

private:
	void animationEvent(CCArmature *armature, MovementEventType movementType, const char *movementID);
	void callback1();
	void callback2();

	CCArmature* armature;
	CCSize size;
};

#endif