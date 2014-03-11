/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __TestCpp__CocosGUIExamplesEquipScene__
#define __TestCpp__CocosGUIExamplesEquipScene__

#include "cocos2d.h"
#include "cocos-ext.h"
//#include "../../testBasic.h"


#define EQUIP_LAYOUT_TAG_ROOT                            1000
#define EQUIP_LAYOUT_TAG_UP                              1001
#define EQUIP_LAYOUT_TAG_CLOTHES                         1002
#define EQUIP_LAYOUT_TAG_WEAPONS                         1003
#define EQUIP_LAYOUT_TAG_PETS                            1004

#define EQUIP_SWITCH_LAYOUT_BUTTON_TAG_CLOTHES           1005
#define EQUIP_SWITCH_LAYOUT_BUTTON_TAG_WEAPONS           1006
#define EQUIP_SWITCH_LAYOUT_BUTTON_TAG_PETS              1007

class CocosGUIExamplesEquipScene : public cocos2d::CCScene
{
public:
    CocosGUIExamplesEquipScene();
    ~CocosGUIExamplesEquipScene();
    
    virtual void onEnter();
    virtual void onExit();
    
//	virtual void runThisTest();
    
protected:
    // a selector callback
    void menuCloseCallback(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
    /*
    void toCocosGUIExamplesRegisterScene(CCObject* pSender);
    void toCocosGUIExamplesWeaponScene(CCObject* pSender);
     */
    
    // equip                                            original function name
    void EquipInit();                                   // EquipInit
    void create();                                      // EquipCreate
    void createClothes();                               // EquipCreateClothes
    void createWeapons();                               // EquipCreateWeapons
    void createPets();                                  // EquipCreatePets
    
    void switchBtnCallBack(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);          // EquipSwitchBtnCallBack
    
    void touch(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);                      // EquipTouch
    
    void backOver(cocos2d::CCObject* pObject);                   // EquipBackOver
    
    void close(cocos2d::CCObject* pObject);                      // EquipClose
    
protected:
    enum EQUIP_TYPE
    {
        EQUIP_TYPE_NONE,
        EQUIP_TYPE_CLOTHES,
        EQUIP_TYPE_WEAPONS,
        EQUIP_TYPE_PETS,
    };
    
protected:
    cocos2d::ui::TouchGroup* m_pUILayer;
    
    // equip
    EQUIP_TYPE m_eEquipType;
    
    cocos2d::CCDictionary* m_dicBeUsedSlot;
    cocos2d::CCDictionary* m_dicClothesSlot;
    cocos2d::CCDictionary* m_dicWeaponsSlot;
    cocos2d::CCDictionary* m_dicPetsSlot;
    
    cocos2d::CCDictionary* m_dicClothes;
    cocos2d::CCDictionary* m_dicWeapons;
    cocos2d::CCDictionary* m_dicPets;
    
    int container_1_Zorder;
    int container_2_Zorder;
    int container_3_Zorder;
    
    cocos2d::CCPoint container_1_Position;
    cocos2d::CCPoint container_2_Position;
    cocos2d::CCPoint container_3_Position;
    
    cocos2d::CCPoint movePoint;
    cocos2d::CCPoint lastPoint;
    
    cocos2d::CCPoint widgetLastWorldSpace;
    cocos2d::CCPoint widgetLastNodeSpace;
    cocos2d::ui::Widget* lastWidgetParent;
};

#endif /* defined(__TestCpp__CocosGUIExamplesEquipScene__) */
