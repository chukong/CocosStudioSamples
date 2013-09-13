#ifndef __SampleChangeEquip__TestChangeEquip__
#define __SampleChangeEquip__TestChangeEquip__

#include "cocos2d.h"
#include "cocos-ext.h"

#if ENABLE_PHYSICS_BOX2D_DETECT
#include "GLES-Render.h"
#include "Box2D/Box2D.h"
#elif ENABLE_PHYSICS_CHIPMUNK_DETECT
#include "chipmunk.h"
#endif

using namespace cocos2d;
using namespace cocos2d::extension;

class EquipIcon;

class TestChangeEquip : public CCLayer
{
public:
	~TestChangeEquip();
    
	virtual void onEnter();
	virtual void initUI();
	virtual void initEquip();

	UIWidget *getGridAtPoint(CCPoint point);

	void adaptToSize(CCNode *target, CCSize size, float sizeScale);

	void registerWithTouchDispatcher();
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
private:
	CCArmature *m_pArmature;

	UILayer *m_pUiLayer;

	UIWidget *m_pChangeEquipPanel;
	UIWidget *m_pEquipSlots;

	UIWidget *m_pEquipGridPanel;
	UIWidget *m_pCurrentGridPage;

	UIWidget *m_pSelectedGrid;
	UIWidget *m_pCurrentGrid;
	
	EquipIcon *m_pCurrentIcon;

	std::map<std::string, int> indexMap;
};


#endif /* defined(__SampleChangeEquip__TestChangeEquip__) */
