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

#ifndef __TestCpp__CocosGUIExamplesRegisterScene__
#define __TestCpp__CocosGUIExamplesRegisterScene__

#include "cocos2d.h"
#include "cocos-ext.h"
//#include "../../testBasic.h"

class CocosGUIExamplesRegisterScene : public cocos2d::CCScene
{
public:
    CocosGUIExamplesRegisterScene(bool bPortrait = false);
    ~CocosGUIExamplesRegisterScene();
    
    virtual void onEnter();
    virtual void onExit();
    
    // a selector callback
    void menuCloseCallback(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
    
    void textFieldEvent(cocos2d::CCObject* pSender, cocos2d::ui::TextFiledEventType type);
    
protected:
    cocos2d::ui::TouchGroup* m_pUILayer;
    cocos2d::ui::Layout* m_pLayout;
};

#endif /* defined(__TestCpp__CocosGUIExamplesRegisterScene__) */
