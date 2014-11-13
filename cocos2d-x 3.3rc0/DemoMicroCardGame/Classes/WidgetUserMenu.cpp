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

#include "WidgetUserMenu.h"
#include "CocosGUI.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "StageLevelSelect.h"
#include "StageHome.h"

USING_NS_CC;
using namespace ui;

void WidgetUserMenu::initialize(Node* menuNode, StageType stageType) {
    auto container = dynamic_cast<Layout*>(menuNode->getChildByName("BottomBar"));
    auto buttonHome = dynamic_cast<Button*>(Helper::seekWidgetByName(container, "BtnAltar"));
    auto buttonTask = dynamic_cast<Button*>(Helper::seekWidgetByName(container, "BtnLvl"));
    auto buttonShop = dynamic_cast<Button*>(Helper::seekWidgetByName(container, "BtnShop"));
    auto buttonSetting = dynamic_cast<Button*>(Helper::seekWidgetByName(container, "BtnSetting"));

    if (stageType != StageType::HOME) {
        buttonHome->addClickEventListener([](Ref*) {
            Director::getInstance()->replaceScene(TransitionCrossFade::create(.2f, StageHome::createScene()));
        });
        buttonTask->addClickEventListener([](Ref*){});
    } 
    else {
        buttonTask->addClickEventListener([](Ref*) {
            Director::getInstance()->replaceScene(TransitionCrossFade::create(.2f, StageLevelSelect::createScene()));
        });
        buttonHome->addClickEventListener([](Ref*) {});
    }

    buttonShop->addClickEventListener([menuNode](Ref*) {
        auto bag = CSLoader::createNode("Inventory.csb");
        auto bkg = LayerColor::create(Color4B(0, 0, 0, 128));
        bkg->addChild(bag);

        menuNode->getParent()->addChild(bkg);


        auto modelDialogListener = EventListenerTouchOneByOne::create();
        modelDialogListener->onTouchBegan = [](Touch *touch, Event *event){
            return true;
        };
        modelDialogListener->setSwallowTouches(true);
        bkg->getEventDispatcher()->addEventListenerWithSceneGraphPriority(modelDialogListener, bkg);

        //This may be a bug of cocos2d-x, the fade animation can't run on bag node.
//         bag->setOpacity(122);
//         bag->runAction(FadeIn::create(1.0f));
//         bkg->runAction(FadeIn::create(4.0f));

        auto btnClose = dynamic_cast<Button*>(bag->getChildByName("Button_Close"));
        btnClose->addClickEventListener([menuNode, bkg](Ref*) {
            menuNode->getParent()->removeChild(bkg);
        });
    });

    buttonSetting->addClickEventListener([menuNode](Ref*) {
        auto setting = CSLoader::createNode("Setting.csb");

        auto bkg = LayerColor::create(Color4B(0, 0, 0, 128));
        bkg->addChild(setting);
        menuNode->getParent()->addChild(bkg);

        auto modelDialogListener = EventListenerTouchOneByOne::create();
        modelDialogListener->onTouchBegan = [](Touch *touch, Event *event){
            return true;
        };
        modelDialogListener->setSwallowTouches(true);
        bkg->getEventDispatcher()->addEventListenerWithSceneGraphPriority(modelDialogListener, bkg);

        auto btnContinue = dynamic_cast<Button*>(setting->getChildByName("Button_9_Copy"));
        btnContinue->addClickEventListener([menuNode, bkg](Ref*) {
            menuNode->getParent()->removeChild(bkg);
        });
    });
}


