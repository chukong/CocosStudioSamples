#ifndef __BAG_H__
#define __BAG_H__

#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d::ui;


class Bag : public cocos2d::CCLayer
{
public:
	static Bag* create();
	virtual bool init();
	virtual ~Bag(void);

	void touchEvent(cocos2d::CCObject* pSender,
		TouchEventType type);
	void closeCallback(cocos2d::CCObject* pSender, TouchEventType type);
private:
	void touchBeganEvent(UIWidget* pEquip);
    void touchMoveEvent(UIWidget* pEquip);
    void touchEndedEvent(UIWidget* pEquip);
	void initUILayer();
	void initArmature();
	void initArmatureOriginEquips();
	void initEquips();
	void initEquipID(UIWidget* pEeuip,int type,int num);
	UIWidget* getBagGrid(int count);

	void initPlayerEquipGrid();

	bool hitTestPanel(UIPanel* pPanel,
		UIWidget* pEquip);
	bool equipAndGridInSameType(UIWidget* pEquip,
		UIWidget* pGrid);
	void swapEquipGrid(UIWidget* pExistEquip,
		UIWidget* newEquip);

	void changeEquip(UIWidget* pWeapon,
		UIWidget* pGrid);
	void unequipEquip();

	void changeParent(UIWidget* pGrid,
		UIWidget* pEquip);

	UILayer* uiLayer;
	UIWidget* startGrid;
    UIWidget* targetGrid;
	cocos2d::extension::CCArmature* armature;
};


#endif