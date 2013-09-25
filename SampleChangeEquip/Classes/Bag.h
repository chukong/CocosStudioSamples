#ifndef __BAG_H__
#define __BAG_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class Bag : public cocos2d::CCLayer
{
public:
	static Bag* create();
	virtual bool init();
	virtual ~Bag(void);

	void touchEvent(cocos2d::CCObject* pSender,
		cocos2d::extension::TouchEventType type);
	void closeCallback(cocos2d::CCObject* pSender);
private:
	void touchBeganEvent(cocos2d::extension::UIWidget* pEquip);
    void touchMoveEvent(cocos2d::extension::UIWidget* pEquip);
    void touchEndedEvent(cocos2d::extension::UIWidget* pEquip);
	void initUILayer();
	void initArmature();
	void initArmatureOriginEquips();
	void initEquips();
	void initEquipID(cocos2d::extension::UIWidget* pEeuip,int type,int num);
	cocos2d::extension::UIWidget* getBagGrid(int count);

	void initPlayerEquipGrid();

	bool hitTestPanel(cocos2d::extension::UIPanel* pPanel,
		cocos2d::extension::UIWidget* pEquip);
	bool equipAndGridInSameType(cocos2d::extension::UIWidget* pEquip,
		cocos2d::extension::UIWidget* pGrid);
	void swapEquipGrid(cocos2d::extension::UIWidget* pExistEquip,
		cocos2d::extension::UIWidget* newEquip);

	void changeEquip(cocos2d::extension::UIWidget* pWeapon,
		cocos2d::extension::UIWidget* pGrid);
	void unequipEquip();

	void changeParent(cocos2d::extension::UIWidget* pGrid,
		cocos2d::extension::UIWidget* pEquip);

	cocos2d::extension::UILayer* uiLayer;
	cocos2d::extension::UIWidget* startGrid;
    cocos2d::extension::UIWidget* targetGrid;
	cocos2d::extension::CCArmature* armature;
};


#endif