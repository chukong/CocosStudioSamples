#include "ColliderToolKits.h"
#include "Enemy.h"

#include "Player.h"

using namespace cocos2d;
using namespace cocos2d::extension;

void MyContactListener::BeginContact(b2Contact* contact)
{
	if(contact)
	{
		Contact contactContainer;
		contactContainer.fixture[0] = contact->GetFixtureA();
		contactContainer.fixture[1] = contact->GetFixtureB();

		contact_list.push_front(contactContainer);
	}
	B2_NOT_USED(contact);
}


// Return true if contact calculations should be performed between these two shapes.
// If you implement your own collision filter you may want to build from this implementation.
bool MyContactFilter::ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB)
{
	m_fixtureA = fixtureA;
	m_fixtureB = fixtureB;

	filterA = fixtureA->GetFilterData();
    filterB = fixtureB->GetFilterData();

    bool collide = collideByGroupAndCatagory() && (collideBullet()||collideByZOrder());
	return collide;
}

bool MyContactFilter::collideByGroupAndCatagory()
{

    if (filterA.groupIndex == filterB.groupIndex && filterA.groupIndex != 0)
    {
        return filterA.groupIndex > 0;
    }
    bool collide = (filterA.maskBits & filterB.categoryBits) != 0 && (filterA.categoryBits & filterB.maskBits) != 0;

	return collide;
}

bool MyContactFilter::collideBullet()
{
	if ((filterA.categoryBits == BULLET) || (filterB.categoryBits == BULLET))
	{
		return true;
	}
	else return false;
}

bool MyContactFilter::collideByZOrder()
{
	int enemyZorder=0,playerZorder=0;

	if (filterA.categoryBits == PLAYER)
	{
		Player* player = (Player*)m_fixtureA->GetUserData();
		playerZorder = player->getZOrder();
	}
	if (filterB.categoryBits == PLAYER)
	{
		Player* player = (Player*)m_fixtureB->GetUserData();
		playerZorder = player->getZOrder();
	}

	if (filterA.categoryBits == ENEMY)
	{
		Enemy* enemy = (Enemy*)m_fixtureA->GetUserData();
		enemyZorder = enemy->getZOrder();
	}
	if (filterB.categoryBits == ENEMY)
	{
		Enemy* enemy = (Enemy*)m_fixtureB->GetUserData();
		enemyZorder = enemy->getZOrder();
	}
	
	if(abs(playerZorder - enemyZorder)<=30) return true;
	else return false;

}
