#ifndef __FISHES_H__
#define __FISHES_H__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class Fishes : public CCLayer
{
public:
	virtual void onExit();
	virtual void onEnter();

	CCSize size;
};

class Fish01 : public Fishes
{
public:
	virtual void onEnter();
};

class Fish02 : public Fishes
{
public:
	virtual void onEnter();
};

class Fish03 : public Fishes
{
public:
	virtual void onEnter();
};

class Fish04 : public Fishes
{
public:
	virtual void onEnter();
private:
	void callback();
	CCArmature* armature;
};

class Fish05 : public Fishes
{
public:
	virtual void onEnter();
};

class Fish06 : public Fishes
{
public:
	virtual void onEnter();
};

class Fish07 : public Fishes
{
public:
	virtual void onEnter();
private:
	void callback();
	void removeSelf();
	CCArmature* armature;
};
#endif