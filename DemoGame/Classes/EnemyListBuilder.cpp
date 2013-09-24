#include "EnemyListBuilder.h"

Enemy* EnemyListBuilder::GetEnemy()
{
	Enemy* pEnemy = *iter;
	iter++;
	return pEnemy;
}

bool EnemyListBuilder::IsTraverseListFinished()
{
	if(enemyList.end() != iter) return false;
	else	initIterPosition();
	return true;
}

void EnemyListBuilder::initIterPosition()
{
	iter = enemyList.begin();
}

StageOneEnemyList::StageOneEnemyList()
{

	for(int i = 0;i < 3;i++)
	{
		Enemy* pEnemy = KnightEnemy::create(ccp(i*100 + 100,50*i+50),100,0.5,0.5);
		pEnemy->defineAction();
		enemyList.push_front(pEnemy);
	}

	initIterPosition();
}

StageTwoEnemyList::StageTwoEnemyList()
{
	Enemy* pEnemy = RobotEnemy::create(ccp(200,160),500);
	enemyList.push_front(pEnemy);

	initIterPosition();
}

