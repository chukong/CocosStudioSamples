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
#include "CocosGUI.h"


#define EQUIP_LAYOUT_TAG_ROOT                            1000
#define EQUIP_LAYOUT_TAG_UP                              1001
#define EQUIP_LAYOUT_TAG_CLOTHES                         1002
#define EQUIP_LAYOUT_TAG_WEAPONS                         1003
#define EQUIP_LAYOUT_TAG_PETS                            1004

#define EQUIP_SWITCH_LAYOUT_BUTTON_TAG_CLOTHES           1005
#define EQUIP_SWITCH_LAYOUT_BUTTON_TAG_WEAPONS           1006
#define EQUIP_SWITCH_LAYOUT_BUTTON_TAG_PETS              1007

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class CocosGUIExamplesEquipScene : public Scene
{
public:
    CocosGUIExamplesEquipScene();
    ~CocosGUIExamplesEquipScene();
    
    virtual void onEnter();
    virtual void onExit();
    
protected:
    // a selector callback
    void menuCloseCallback(Ref* pSender, TouchEventType type);
    
    // equip                                            original function name
    void EquipInit();                                   // EquipInit
    void create();                                      // EquipCreate
    void createClothes();                               // EquipCreateClothes
    void createWeapons();                               // EquipCreateWeapons
    void createPets();                                  // EquipCreatePets
    
    void switchBtnCallBack(Ref* pSender, TouchEventType type);          // EquipSwitchBtnCallBack
    
    void touch(Ref* pSender, TouchEventType type);                      // EquipTouch    
    
    void backOver(Ref* pObject);                   // EquipBackOver
    
    void close(Ref* pObject);                      // EquipClose
    
protected:
    enum EQUIP_TYPE
    {
        EQUIP_TYPE_NONE,
        EQUIP_TYPE_CLOTHES,
        EQUIP_TYPE_WEAPONS,
        EQUIP_TYPE_PETS,
    };
    
protected:
    Layer* m_pUILayer;
    
    // equip
    EQUIP_TYPE m_eEquipType;
    
    __Dictionary* m_dicBeUsedSlot;
    __Dictionary* m_dicClothesSlot;
    __Dictionary* m_dicWeaponsSlot;
    __Dictionary* m_dicPetsSlot;
    
    __Dictionary* m_dicClothes;
    __Dictionary* m_dicWeapons;
    __Dictionary* m_dicPets;
    
    int container_1_Zorder;
    int container_2_Zorder;
    int container_3_Zorder;
    
    Point container_1_Position;
    Point container_2_Position;
    Point container_3_Position;
    
    Point movePoint;
    Point lastPoint;
    
    Point widgetLastWorldSpace;
    Point widgetLastNodeSpace;
    Widget* lastWidgetParent;
};

#endif /* defined(__TestCpp__CocosGUIExamplesEquipScene__) */
