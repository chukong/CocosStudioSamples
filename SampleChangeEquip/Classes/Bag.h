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
		cocos2d::gui::TouchEventType type);
	void closeCallback(cocos2d::CCObject* pSender, cocos2d::gui::TouchEventType type);
private:
	void touchBeganEvent(cocos2d::gui::UIWidget* pEquip);
    void touchMoveEvent(cocos2d::gui::UIWidget* pEquip);
    void touchEndedEvent(cocos2d::gui::UIWidget* pEquip);
	void initUILayer();
	void initArmature();
	void initArmatureOriginEquips();
	void initEquips();
	void initEquipID(cocos2d::gui::UIWidget* pEeuip,int type,int num);
	cocos2d::gui::UIWidget* getBagGrid(int count);

	void initPlayerEquipGrid();

	bool hitTestPanel(cocos2d::gui::UIPanel* pPanel,
		cocos2d::gui::UIWidget* pEquip);
	bool equipAndGridInSameType(cocos2d::gui::UIWidget* pEquip,
		cocos2d::gui::UIWidget* pGrid);
	void swapEquipGrid(cocos2d::gui::UIWidget* pExistEquip,
		cocos2d::gui::UIWidget* newEquip);

	void changeEquip(cocos2d::gui::UIWidget* pWeapon,
		cocos2d::gui::UIWidget* pGrid);
	void unequipEquip();

	void changeParent(cocos2d::gui::UIWidget* pGrid,
		cocos2d::gui::UIWidget* pEquip);

	cocos2d::gui::UILayer* uiLayer;
	cocos2d::gui::UIWidget* startGrid;
    cocos2d::gui::UIWidget* targetGrid;
	cocos2d::extension::CCArmature* armature;
};


#endif