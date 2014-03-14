#include "PlayerHeadUI.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocos2d::ui;

PlayerHeadUI::PlayerHeadUI(void):
	uiLayer(NULL),player(NULL),
	playerLifeRecorder(0),playerHPRecorder(0)
{
	uiLayer = UILayer::create();

	initWidget();

	this->addChild(uiLayer);

	scheduleUpdate();
}

void PlayerHeadUI::initWidget()
{
	//UIWidget* widget = dynamic_cast<Layout*>(CCUIHELPER->createWidgetFromJsonFile("uifiles/ui_1.ExportJson"));
	UIWidget* widget = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("uifiles/ui_1.ExportJson"));

	widget->setScale(0.5);
	widget->setPosition(ccp(0,160));
	uiLayer->addWidget(widget);
}

void PlayerHeadUI::update(float delta)
{
	if(player == NULL) return;

	processPlayerLife();

	processPlayerHP();
}

void PlayerHeadUI::processPlayerLife()
{
	if(playerLifeRecorder == player->getLifeNum()) return;
	else playerLifeRecorder = player->getLifeNum();

	UIImageView* lifeOne = dynamic_cast<UIImageView*>
		(uiLayer->getWidgetByName("lifeOne"));
	UIImageView* lifeTwo = dynamic_cast<UIImageView*>
		(uiLayer->getWidgetByName("lifeTwo"));
	UIImageView* deadOne = dynamic_cast<UIImageView*>
		(uiLayer->getWidgetByName("deadOne"));
	UIImageView* deadTwo = dynamic_cast<UIImageView*>
		(uiLayer->getWidgetByName("deadTwo"));
	
	if(player->getLifeNum() == 0)
	{
		lifeOne->setVisible(false);
		lifeTwo->setVisible(false);
		deadOne->setVisible(true);
		deadTwo->setVisible(true);
	}
	if(player->getLifeNum() == 1)
	{
		lifeOne->setVisible(true);
		lifeTwo->setVisible(false);
		deadOne->setVisible(false);
		deadTwo->setVisible(true);
	}
	if(player->getLifeNum() == 2)
	{
		lifeOne->setVisible(true);
		lifeTwo->setVisible(true);
		deadOne->setVisible(false);
		deadTwo->setVisible(false);
	}
}

void PlayerHeadUI::processPlayerHP()
{
	if(playerHPRecorder == player->getHPPercent()) return;
	else if(playerHPRecorder > player->getHPPercent())
	{
		playerHPRecorder -= 2;
		setHPBarPercent(playerHPRecorder);
	}
	else
	{
		playerHPRecorder += 10;
		setHPBarPercent(playerHPRecorder);
	}
}

void PlayerHeadUI::setHPBarPercent(int percent)
{
	UILoadingBar* hpBar = dynamic_cast<UILoadingBar*>(uiLayer->getWidgetByName("redBar"));
	hpBar->setPercent(percent);
}



PlayerHeadUI::~PlayerHeadUI(void)
{
	unscheduleUpdate();
}
