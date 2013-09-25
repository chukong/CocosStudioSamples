#include "MyController.h"

using namespace cocos2d;
using namespace cocos2d::extension;

MyController* MyController::create()
{
	MyController *pRet = new MyController();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool MyController::init()
{
	if(!CCLayer::init())	return false;
    do 
    {
		playerStateMachine = NULL;
		//create a joystick delegate for joystick
		joyStick = createJoystick();
		this->addChild(joyStick,4);

		UILayer* uiLayer = createButton();
		this->addChild(uiLayer,4);

		headUI = new PlayerHeadUI();
		headUI->bindPlayer(player);
		this->addChild(headUI);
	} while(0);
    return true;
}
CCJoystick* MyController::createJoystick()
{
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();

	CCJoystick* joyStick = CCJoystick::create(20, 50, true, true, false, false);
	joyStick->setPosition(ccp(0.2 * size.width,0.2 * size.height));
	joyStick->setBallTexture("ui/joystick.png");
	joyStick->setStickTexture("ui/stick.png");
	joyStick->setDockTexture("ui/joystickbg.png");

	return joyStick;
}
UILayer* MyController::createButton()
{
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();

	UIButton* button = UIButton::create();

	button->setTouchEnable(true);
	button->loadTextures("ui/buttonrelease.png","ui/buttonpress.png","");
	button->setPosition(ccp(0.9 * size.width,0.2 * size.height));
	button->setScale(0.5);
	button->addTouchEventListener(this, toucheventselector(MyController::touchEvent));

	UILayer* uiLayer = UILayer::create();
    uiLayer->addWidget(button);

	return uiLayer;
}

void MyController::bindPlayer(Player* pPlayer)
{
	player = pPlayer;
	bindPlayerStateMachine();
	headUI->bindPlayer(pPlayer);
}


void MyController::bindPlayerStateMachine()
{
	playerStateMachine = player->getStateMachine();

	MyJoyStickDelegate* joystickDelegate = new MyJoyStickDelegate();
	joystickDelegate->bindPlayerStateMachine(playerStateMachine);
	joyStick->setDelegate(joystickDelegate);
}

void MyController::touchEvent(CCObject* pSender,TouchEventType type)
{
	if (type == TOUCH_EVENT_BEGAN)
	{
		playerStateMachine->updatePressButton(true);
	}
	if (type == TOUCH_EVENT_MOVED)
	{
		playerStateMachine->updatePressButton(false);
	}
	if (type == TOUCH_EVENT_ENDED)
	{
		playerStateMachine->updatePressButton(false);
	}
}

void MyJoyStickDelegate::onCCJoyStickUpdate(CCNode* sender, float angle, CCPoint direction, float power)
{
	playerStateMachine->updateMoving(direction);
}
void MyJoyStickDelegate::onCCJoyStickActivated(CCNode *sender)
{
    playerStateMachine->updateActiveJoystick(true);
}
void MyJoyStickDelegate::onCCJoyStickDeactivated(CCNode *sender)
{
    playerStateMachine->updateActiveJoystick(false);
	playerStateMachine->updateMoving(ccp(0,0));
}