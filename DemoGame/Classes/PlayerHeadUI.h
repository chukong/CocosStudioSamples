#ifndef __PLAYER_HEAD_UI_H__
#define __PLAYER_HEAD_UI_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Player.h"

using namespace cocos2d::gui;

class PlayerHeadUI : public cocos2d::CCLayer
{
public:
	PlayerHeadUI(void);
	~PlayerHeadUI(void);

	virtual void update(float delta);
	
	void bindPlayer(Player* pPlayer)
	{player = pPlayer;}
private:
	void initWidget();

	void processPlayerLife();
	void processPlayerHP();

	void setHPBarPercent(int percent);

	UILayer* uiLayer;

	Player* player;
	int playerLifeRecorder;
	int playerHPRecorder;
};

#endif