#ifndef __ENEMY_LIST_BUILER_H__
#define __ENEMY_LIST_BUILER_H__

#include "Enemy.h"

class EnemyListBuilder
{
public:
	virtual ~EnemyListBuilder(void){enemyList.clear();}
	virtual std::list<Enemy*> GetList(){return enemyList;}
	virtual unsigned int GetEnemyNum(){return enemyList.size();}
	virtual Enemy* GetEnemy();

	bool IsTraverseListFinished();
	bool IsEnemyAllDied(){return enemyList.empty();}
	void deleteEnemy(Enemy* pEnemy){enemyList.remove(pEnemy);}

protected:
	void initIterPosition();
	std::list<Enemy*> enemyList;
	std::list<Enemy*>::iterator iter;
};

class StageOneEnemyList : public EnemyListBuilder
{
public:
	StageOneEnemyList();
};

class StageTwoEnemyList : public EnemyListBuilder
{
public:
	StageTwoEnemyList();
};

#endif