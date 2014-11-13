#ifndef __BAG_H__
#define __BAG_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocos2d::ui;
using namespace cocostudio;



class Bag : public Layer
{
public:
	static Bag* create();
	virtual bool init();
	virtual ~Bag(void);

	void touchEvent(cocos2d::CCObject* pSender,
		cocos2d::ui::TouchEventType type);
	void closeCallback(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
private:
	void touchBeganEvent(cocos2d::ui::Widget* pEquip);
	void touchMoveEvent(cocos2d::ui::Widget* pEquip);
	void touchEndedEvent(cocos2d::ui::Widget* pEquip);
	void initUILayer();
	void initArmature();
	void initArmatureOriginEquips();
	void initEquips();
	void initEquipID(cocos2d::ui::Widget* pEeuip,int type,int num);
	cocos2d::ui::Widget* getBagGrid(int count);

	void initPlayerEquipGrid();

	bool hitTestPanel(cocos2d::ui::Layout* pPanel,
		cocos2d::ui::Widget* pEquip);
	bool equipAndGridInSameType(cocos2d::ui::Widget* pEquip,
		cocos2d::ui::Widget* pGrid);
	void swapEquipGrid(cocos2d::ui::Widget* pExistEquip,
		cocos2d::ui::Widget* newEquip);

	void changeEquip(cocos2d::ui::Widget* pWeapon,
		cocos2d::ui::Widget* pGrid);
	void unequipEquip();

	void changeParent(cocos2d::ui::Widget* pGrid,
		cocos2d::ui::Widget* pEquip);
	void loading(Armature *pArmature, MovementEventType eventType, const char *animationID);

	cocos2d::Layer* uiLayer;
	cocos2d::ui::Widget* startGrid;
	cocos2d::ui::Widget* targetGrid;
	cocostudio::Armature* armature;
};


#endif