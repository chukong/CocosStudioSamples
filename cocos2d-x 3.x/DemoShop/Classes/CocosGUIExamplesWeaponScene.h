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

#ifndef __TestCpp__CocosGUIExamplesWeaponScene__
#define __TestCpp__CocosGUIExamplesWeaponScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CocosGUI.h"
//#include "../../testBasic.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

#define WEAPON_ITEM_LAYOUT_TAG  1

#define SHOP_ITEM_LAYOUT_TAG        100
#define RANKING_ITEM_LAYOUT_TAG     200

#define COUPON_MAX                  300
#define BINDING_MAX                 400
#define MEDAL_MAX                   500

class CocosGUIExamplesWeaponScene : public Scene
{        
public:
    CocosGUIExamplesWeaponScene();
    ~CocosGUIExamplesWeaponScene();
    
    virtual void onEnter();
    virtual void onExit();
    
protected:
    // a selector callback
    void menuCloseCallback(Ref* pSender, TouchEventType type);
    
    // shop
    void ShopInit();
    
    // popup
    void popupInit();
    void popupClose(Ref* pSender, TouchEventType type);
    void popupLogic(Ref* pSender, TouchEventType type);
    void popupCalculate(Ref* pSender, TouchEventType type);    
    
protected:
    Layer* m_pUILayer;
    Layout* _root;
    
    int m_nIndex;
    int m_nCount;
    int m_nCoupon;
    int m_nBinding;
    int m_nMedal;
};

#endif /* defined(__TestCpp__CocosGUIExamplesWeaponScene__) */
