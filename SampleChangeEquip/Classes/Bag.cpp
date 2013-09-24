#include "Bag.h"

using namespace cocos2d;
using namespace cocos2d::extension;

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
	UIWidget* widget = dynamic_cast<Layout*>(CCUIHELPER->
		createWidgetFromJsonFile("SampleChangeEquip_UI_1/SampleChangeEquip_UI_1.ExportJson"));
	uiLayer = UILayer::create();
	uiLayer->addWidget(widget);
	this->addChild(uiLayer);

	UIWidget* closeButton = dynamic_cast<UIWidget*>(uiLayer->getWidgetByName("closebutton"));
	closeButton->addPushDownEvent(this,coco_pushselector(Bag::closeCallback));
}
void Bag::initArmature()
{
	CCArmatureDataManager::sharedArmatureDataManager()->
		addArmatureFileInfo("ArmatureAndEquip/EquipArmature.ExportJson");
	armature = CCArmature::create("EquipArmature");
	armature->getAnimation()->playByIndex(0);
	armature->setScale(0.28);
	armature->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width * 0.28,
		CCDirector::sharedDirector()->getVisibleSize().height * 0.55));

	UIWidget* root = dynamic_cast<UIWidget*>(uiLayer->getWidgetByName("ImageView"));

	UIWidget* armatureWidget = UIWidget::create();
	uiLayer->addWidget(armatureWidget);
	armatureWidget->addCCNode(armature);

	initArmatureOriginEquips();
}
void Bag::initArmatureOriginEquips()
{
	armature->getBone("beltbone")->changeDisplayByIndex(-1,true);
	armature->getBone("necklacebone")->changeDisplayByIndex(-1,true);
	armature->getBone("weaponbone")->changeDisplayByIndex(-1,true);
	armature->getBone("helmetbone")->changeDisplayByIndex(-1,true);
}

void Bag::initEquips()
{
	UIPanel* equipPanel = dynamic_cast<UIPanel*>(uiLayer->getWidgetByName("equippanel"));
	CCArray* equips = equipPanel->getChildren();
	CCObject* object = NULL;

	int bagGridCount = 1;

	int equipType = EQUIP_TYPE_HELMET;		//the first type of equip

	CCARRAY_FOREACH(equips,object)
	{
		UIPanel* equipChildPanel = (UIPanel*)object;
		CCArray* equips = equipChildPanel->getChildren();

		int equipStartNum = 1;

		CCARRAY_FOREACH_REVERSE(equips, object)
		{
			UIWidget* equip = dynamic_cast<UIWidget*>(object);
			equip->addTouchEventListener(this,toucheventselector(Bag::touchEvent));
			initEquipID(equip,equipType,equipStartNum);
			
			UIWidget* bagGrid = getBagGrid(bagGridCount++);
			changeParent(bagGrid,equip);

			equipStartNum++;
		}
		equipType++;
	}
}

UIWidget* Bag::getBagGrid(int count)
{
	CCString* ccstring = CCString::createWithFormat("baggrid%d",count);
	UIWidget* bagGrid = dynamic_cast
				<UIWidget*>(uiLayer->getWidgetByName(ccstring->getCString()));
	return bagGrid;
}

void Bag::initEquipID(UIWidget* pEquip,int type,int num)
{
	pEquip->setTag(type*100 + num *10);
}

void Bag::initPlayerEquipGrid()
{
	UIPanel* playerPanel = dynamic_cast<UIPanel*>(uiLayer->getWidgetByName("playerpanel"));

	CCArray* equipGrids = playerPanel->getChildren();
	CCObject* object = NULL;

	int gridType = EQUIP_TYPE_HELMET;
	CCARRAY_FOREACH(equipGrids,object)
	{
		UIWidget* equipGrid = (UIWidget*)object;
		equipGrid->setTag(gridType * 100);
		gridType++;
	}
}

void Bag::touchEvent(CCObject* pSender,TouchEventType type)
{
	UIWidget* equip = (UIWidget*)pSender;
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

void Bag::touchBeganEvent(UIWidget* pEquip)
{
	startWidget = (UIWidget*)pEquip->getParent();
	
	pEquip->retain();
	pEquip->removeFromParent();
	pEquip->setPosition(CCPointZero);
	pEquip->setPosition(pEquip->getTouchStartPos());
	uiLayer->addWidget(pEquip);
	pEquip->release();

	pEquip->setZOrder(2);
}
void Bag::touchMoveEvent(UIWidget* pEquip)
{
	CCPoint point = pEquip->getTouchMovePos();

	pEquip->setPosition(point);
}
void Bag::touchEndedEvent(UIWidget* pEquip)
{
	UIPanel* bagPanel = dynamic_cast<UIPanel*>(uiLayer->getWidgetByName("bagpanel"));
	UIPanel* playerPanel = dynamic_cast<UIPanel*>(uiLayer->getWidgetByName("playerpanel"));

	if(hitTestPanel(bagPanel,pEquip)) return;
	if(hitTestPanel(playerPanel,pEquip)) return;

	changeParent(startWidget,pEquip);

}
bool Bag::hitTestPanel(UIPanel* pPanel,UIWidget* pEquip)
{
	CCObject* object = NULL;
	CCARRAY_FOREACH(pPanel->getChildren(),object)
	{
		UIWidget* grid = (UIWidget*)object;

		if(grid->hitTest(pEquip->getPosition()))
		{
			if(!equipAndGridInSameType(pEquip,grid)) continue;

			if(grid->getChildren()->count()>0) 
				swapEquipGrid((UIWidget*)grid->getChildren()->objectAtIndex(0),pEquip);
			else 
			{
				changeParent(grid,pEquip);
				//if gird is a baggird and startWidget is a equip grid ,unequip euip
				if((startWidget->getTag()>= 100)&&(grid->getTag()<100)) unequipEquip();
			}
			

			return true;
		}
	}
	return false;
}
bool Bag::equipAndGridInSameType(UIWidget* pEquip,UIWidget* pGrid)
{
	int gridType = pGrid->getTag()*0.01;
	//pGrid is bagGrid
	if(pGrid->getTag() < 100) return true;
	else
	{
		if(gridType == (int(pEquip->getTag()*0.01)))
		{
			if((gridType == EQUIP_TYPE_SKILL) ||
				(gridType ==	EQUIP_TYPE_SHIELD) ||
					(gridType ==EQUIP_TYPE_OTHER));
			else
			{
				changeEquip(pEquip,pGrid);
			}
			return true;
		}
	}
	return false;
}

void Bag::swapEquipGrid(UIWidget* pExistEquip,UIWidget* newEquip)
{

	UIWidget* parentGrid = (UIWidget*)pExistEquip->getParent();	

	changeParent(startWidget,pExistEquip);
	changeParent(parentGrid,newEquip);
}

void Bag::changeEquip(UIWidget* pWeapon,UIWidget* pGrid)
{
	CCString* weaponName = CCString::createWithFormat("%stex.png",pWeapon->getName());
	CCString* boneName = CCString::createWithFormat("%sbone",pGrid->getName());

	CCSkin* weaponSkin = CCSkin::createWithSpriteFrameName(weaponName->getCString());
	armature->getBone(boneName->getCString())->addDisplay(weaponSkin,0);
	armature->getBone(boneName->getCString())->changeDisplayByIndex(0,true);
}
void Bag::unequipEquip()
{
	int equipType = startWidget->getTag() * 0.01;
	CCString* boneName = CCString::createWithFormat("%sbone",startWidget->getName());
	switch (equipType)
	{
	case EQUIP_TYPE_WEAPON:
	case EQUIP_TYPE_BELT:
	case EQUIP_TYPE_HELMET:
	case EQUIP_TYPE_NECKLACE:
		armature->getBone(boneName->getCString())->changeDisplayByIndex(-1,true);
		break;
	case	EQUIP_TYPE_SKILL:
	case	EQUIP_TYPE_SHIELD:
	case	EQUIP_TYPE_OTHER:
		break;
	default:
		{
			CCString* equipName = CCString::createWithFormat("%s0tex.png",startWidget->getName());
			CCSkin* equipDefaultSkin = CCSkin::createWithSpriteFrameName(equipName->getCString());
			armature->getBone(boneName->getCString())->addDisplay(equipDefaultSkin,0);
			break;
		}
	}
}

void Bag::changeParent(UIWidget* pGrid,UIWidget* pEquip)
{
	pEquip->retain();
	pEquip->removeFromParent();
	pEquip->setPosition(CCPointZero);
	pGrid->addChild(pEquip);
	pEquip->release();
}




void Bag::closeCallback(CCObject* pSender)
{
	CCArmatureDataManager::purge();
	CCSSceneReader::sharedSceneReader()->purgeSceneReader();
	UIActionManager::shareManager()->purgeUIActionManager();
	UIHelper::instance()->purgeUIHelper();
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

Bag::~Bag(void)
{
}
