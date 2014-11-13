#include "Bag.h"
#include "UIHelper.h"
//#include "UIScene.h"



enum
{
	EQUIP_TYPE_HELMET = 1,
	EQUIP_TYPE_NECKLACE,
	EQUIP_TYPE_ARMOUR,

	EQUIP_TYPE_WEAPON,
	EQUIP_TYPE_SKILL,
	EQUIP_TYPE_SHIELD,

	EQUIP_TYPE_OTHER,
	EQUIP_TYPE_BELT,
	EQUIP_TYPE_GLOVE
};


Bag* Bag::create()
{
	Bag *pRet = new Bag();
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

bool Bag::init()
{
	if(!CCLayer::init()) return false;

	initUILayer();
	initArmature();
	initEquips();
	initPlayerEquipGrid();

	return true;
}
void Bag::initUILayer()
{
	Widget* widget = dynamic_cast<Widget*>(GUIReader::shareReader()->widgetFromJsonFile("SampleChangeEquip_UI_1/SampleChangeEquip_UI_1.ExportJson"));
	widget->setTag(10001);
	uiLayer = Layer::create();
	uiLayer->addChild(widget);
	this->addChild(uiLayer);


	Widget* root = static_cast<Widget*>(uiLayer->getChildByTag(10001));

	Button* closeButton = static_cast<Button*>(ui::Helper::seekWidgetByName(root, "closebutton"));
	closeButton->addTouchEventListener(this,toucheventselector(Bag::closeCallback));

}
void Bag::initArmature()
{
	ArmatureDataManager::sharedArmatureDataManager()->
		addArmatureFileInfo("ArmatureAndEquip/newbaganimation.ExportJson");
	armature = CCArmature::create("newbaganimation");
	armature->getAnimation()->play("loading");
	// call "loading" back after any animation
	armature->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(Bag::loading));
	armature->setScale(0.16);
	armature->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width * 0.28,
		CCDirector::sharedDirector()->getVisibleSize().height * 0.40));
	Widget* armatureWidget = Widget::create();
	uiLayer->addChild(armatureWidget);
	armatureWidget->addChild(armature);

	initArmatureOriginEquips();
}
void Bag::initArmatureOriginEquips()
{
	armature->getBone("beltbone")->changeDisplayByIndex(-1,true);
	armature->getBone("necklacebone")->changeDisplayByIndex(-1,true);
	armature->getBone("weaponbone")->changeDisplayByIndex(-1,true);
	armature->getBone("helmetbone")->changeDisplayByIndex(-1,true);
	armature->getBone("armourbone")->changeDisplayByIndex(-1,true);
}

void Bag::initEquips()
{
	Widget* root = static_cast<Widget*>(uiLayer->getChildByTag(10001));
	Layout* equipPanel = static_cast<Layout*>(ui::Helper::seekWidgetByName(root,"equippanel"));
	Vector<Node*> equips = equipPanel->getChildren();
	Vector<Node*>::iterator object;

	int bagGridCount = 1;

	int equipType = EQUIP_TYPE_HELMET;		//the first type of equip

	for (object=equips.begin();object != equips.end(); object++)
	{
		Vector<Node*> equipchildren = (*object)->getChildren();
		int equipStartNum = 1;
		Vector<Node*>::iterator objectchild;
		for (objectchild=equipchildren.begin();objectchild != equipchildren.end(); objectchild++)
		{
			Widget* equip = static_cast<Widget*>(*objectchild);
			equip->addTouchEventListener(this,toucheventselector(Bag::touchEvent));
			initEquipID(equip,equipType,equipStartNum);

			Widget* bagGrid = getBagGrid(bagGridCount++);
			changeParent(bagGrid,equip);

			equipStartNum++;
		}
		equipType++;
	}
}

Widget* Bag::getBagGrid(int count)
{
	Widget* root = static_cast<Widget*>(uiLayer->getChildByTag(10001));
	CCString* ccstring = CCString::createWithFormat("baggrid%d",count);
	Widget* bagGrid = static_cast<Widget*>(ui::Helper::seekWidgetByName(root, ccstring->getCString()));
	return bagGrid;
}

void Bag::initEquipID(Widget* pEquip,int type,int num)
{
	pEquip->setTag(type*100 + num *10);
}

void Bag::initPlayerEquipGrid()
{
	Widget* root = static_cast<Widget*>(uiLayer->getChildByTag(10001));
	Layout* playerPanel = static_cast<Layout*>(ui::Helper::seekWidgetByName(root, "playerpanel"));

	Vector<Node*> equipGrids = playerPanel->getChildren();
	Vector<Node*>::iterator object;

	int gridType = EQUIP_TYPE_HELMET;
	for (object=equipGrids.begin();object != equipGrids.end(); object++)
	{
		Widget* equipGrid = (Widget*)(*object);
		equipGrid->setTag(gridType * 100);
		gridType++;
	}
}

void Bag::touchEvent(CCObject* pSender,TouchEventType type)
{
	Widget* equip = (Widget*)pSender;
	if (type == TOUCH_EVENT_BEGAN)
	{
		touchBeganEvent(equip);
	}
	if (type == TOUCH_EVENT_MOVED)
	{
		touchMoveEvent(equip);
	}
	if (type == TOUCH_EVENT_ENDED)
	{
		touchEndedEvent(equip);
	}
}

void Bag::touchBeganEvent(Widget* pEquip)
{
	startGrid = (Widget*)pEquip->getParent();

	pEquip->retain();
	pEquip->removeFromParent();
	pEquip->setPosition(CCPointZero);
	pEquip->setPosition(pEquip->getTouchStartPos());
	uiLayer->addChild(pEquip);
	pEquip->release();

	pEquip->setZOrder(2);
}
void Bag::touchMoveEvent(Widget* pEquip)
{
	CCPoint point = pEquip->getTouchMovePos();

	pEquip->setPosition(point);
}
void Bag::touchEndedEvent(Widget* pEquip)
{
	Widget* root = static_cast<Widget*>(uiLayer->getChildByTag(10001));
	Layout* bagPanel = static_cast<Layout*>(ui::Helper::seekWidgetByName(root, "bagpanel"));
	Layout* playerPanel  = static_cast<Layout*>(ui::Helper::seekWidgetByName(root, "playerpanel"));

	if(hitTestPanel(bagPanel,pEquip))
	{
		if (targetGrid->getChildren().size()>0)
		{
			Widget* originEquip = (Widget*)targetGrid->getChildren().at(0);
			changeParent(startGrid, originEquip);
			if(startGrid->getTag() >= 100) changeEquip(originEquip, startGrid);
		}
		else if(startGrid->getTag()>=100) unequipEquip();
		changeParent(targetGrid, pEquip);
		return;
	}
	if(hitTestPanel(playerPanel,pEquip))
	{
		if (targetGrid->getChildren().size()>0)
		{
			Widget* originEquip = (Widget*)targetGrid->getChildren().at(0);
			changeParent(startGrid, originEquip);
		}
		changeParent(targetGrid, pEquip);
		changeEquip(pEquip, targetGrid);
		return;
	}

	changeParent(startGrid,pEquip);

}
bool Bag::hitTestPanel(Layout* pPanel,Widget* pEquip)
{
	Vector<Node*>::iterator object;
	Vector<Node*> equips = pPanel->getChildren();
	for(object=equips.begin();object!= equips.end();object++)
	{
		Widget* grid = (Widget*)(*object);

		if(grid->hitTest(pEquip->getPosition()))
		{
			if(equipAndGridInSameType(pEquip,grid))
			{
				targetGrid = grid;
				return true;
			}
		}
	}
	return false;
}
bool Bag::equipAndGridInSameType(Widget* pEquip,Widget* pGrid)
{
	int gridType = pGrid->getTag()*0.01;
	//pGrid is bagGrid and have no children
	if((pGrid->getTag() < 100)&&(!pGrid->getChildren().size())) return true;
	//pgrid and startGrid is baggrid
	else if((pGrid->getTag() <100)&&(startGrid->getTag() <100)) return true;
	//pGrid and equip in same type
	else if(gridType == (int(pEquip->getTag()*0.01))) return true;
	else if(pGrid->getChildren().size())
	{
		int originEquipType = ((Widget*) pGrid->getChildren().at(0))->getTag()*0.01;
		int newEquip = pEquip->getTag()*0.01;
		if(originEquipType == newEquip) return true;
	}
	return false;
}

void Bag::swapEquipGrid(Widget* pExistEquip,Widget* newEquip)
{
	Widget* parentGrid = (Widget*)pExistEquip->getParent();	
	changeParent(startGrid,pExistEquip);
	changeParent(parentGrid,newEquip);
}

void Bag::changeEquip(Widget* pWeapon,Widget* pGrid)
{
	int equipType = pGrid->getTag()/100;
	CCString* weaponName ;
	switch (equipType)
	{
	case EQUIP_TYPE_SKILL:
    case EQUIP_TYPE_SHIELD:
	case EQUIP_TYPE_OTHER:
		return;
	case EQUIP_TYPE_GLOVE:
		weaponName = CCString::createWithFormat("%stex.png",pWeapon->getName());

		armature->getBone("leftglovebone")->changeDisplayByName(weaponName->getCString(),true);
		armature->getBone("rightglovebone")->changeDisplayByName(weaponName->getCString(),true);
		break;
	default:
		weaponName = CCString::createWithFormat("%stex.png",pWeapon->getName());
		CCString* boneName = CCString::createWithFormat("%sbone",pGrid->getName());
		armature->getBone(boneName->getCString())->changeDisplayByName(weaponName->getCString(),true);
		break;
	}
	/// animations play
	if(equipType==EQUIP_TYPE_GLOVE || equipType== EQUIP_TYPE_WEAPON || equipType== EQUIP_TYPE_HELMET)
		armature->getAnimation()->play(pGrid->getName());

}
void Bag::unequipEquip()
{
	int equipType = startGrid->getTag() * 0.01;
	CCString* boneName = CCString::createWithFormat("%sbone",startGrid->getName());
	switch (equipType)
	{
	case EQUIP_TYPE_WEAPON:
	case EQUIP_TYPE_BELT:
	case EQUIP_TYPE_HELMET:
	case EQUIP_TYPE_NECKLACE:
		armature->getBone(boneName->getCString())->changeDisplayByIndex(-1,true);
		break;
	case EQUIP_TYPE_GLOVE:
		armature->getBone("leftglovebone")->changeDisplayByIndex(-1,true);
		armature->getBone("rightglovebone")->changeDisplayByIndex(-1,true);
		break;
	case	EQUIP_TYPE_SKILL:
	case	EQUIP_TYPE_SHIELD:
	case	EQUIP_TYPE_OTHER:
		break;
	default:
		{
			CCString* equipName = CCString::createWithFormat("%s0tex.png",startGrid->getName());
			Skin* equipDefaultSkin = Skin::createWithSpriteFrameName(equipName->getCString());
			armature->getBone(boneName->getCString())->addDisplay(equipDefaultSkin,0);
			break;
		}
	}
}

void Bag::changeParent(Widget* pGrid,Widget* pEquip)
{
	pEquip->retain();
	pEquip->removeFromParent();
	pEquip->setPosition(CCPointZero);
	pGrid->addChild(pEquip);
	pEquip->release();
}




void Bag::closeCallback(CCObject* pSender,TouchEventType type)
{

	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
	CCDirector::sharedDirector()->end();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	exit(0);
#endif
}

Bag::~Bag(void)
{
}



void Bag::loading( Armature *pArmature, MovementEventType eventType, const char *animationID )
{
	if (eventType == COMPLETE)
	{
		armature->getAnimation()->play("loading");
	}
}
