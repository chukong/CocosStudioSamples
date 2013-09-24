#ifndef __COLLDER_TOOL_KITS_H__
#define __COLLDER_TOOL_KITS_H__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Box2D/Box2D.h"
#include <list>

enum
{
	BULLET = 0x0002,		//bullet's catagoryBits
	PLAYER = 0x0004,		//player's catagoryBits
	ENEMY = 0x0006		//enemy's catagoryBits 
};

enum
{
	PLAYER_GROUPINDEX = -1,
	ENEMY_GROUPINDEX	= -2
};


class Contact
{
public:
	b2Fixture *fixture[2];

};

class MyContactListener : public b2ContactListener
{
public:
	~MyContactListener(){contact_list.clear();}

	virtual void BeginContact(b2Contact* pContact);
	Contact getListFront(){return contact_list.front();}
	void clearContactList(){contact_list.clear();}
	bool isContactListEmpty(){return contact_list.empty();}
private:
	std::list<Contact> contact_list;
};

class MyContactFilter : public b2ContactFilter
{
public:
	/// Return true if contact calculations should be performed between these two shapes.
    /// @warning for performance reasons this is only called when the AABBs begin to overlap.
    virtual bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB);
private:
	bool collideByGroupAndCatagory();
	bool collideBullet();
	bool collideByZOrder();

	b2Fixture* m_fixtureA;
	b2Fixture* m_fixtureB;

	b2Filter filterA;
	b2Filter filterB;
};



#endif