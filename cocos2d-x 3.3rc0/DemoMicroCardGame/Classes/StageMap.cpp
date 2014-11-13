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

#include "StageMap.h"
#include "CocosGUI.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
#include "cocostudio/ActionTimeline/CCActionTimelineCache.h"
#include "StageHome.h"
#include "StagePlay.h"
#include "WidgetUserMenu.h"

USING_NS_CC;
using namespace ui;
USING_NS_TIMELINE

void StageMap::initialize() {
    _rootNode = CSLoader::createNode("MissionSelection.csb");
    auto menu = CSLoader::createNode("MainMenu.csb");
    WidgetUserMenu::initialize(menu, StageType::MAP);
    auto info = CSLoader::createNode("PlayerStats.csb");
    menu->setPosition(StageHome::g_posMenu);
    info->setPosition(StageHome::g_posInfo);
    _rootNode->addChild(menu);
    _rootNode->addChild(info);

    ScrollView* scroller = dynamic_cast<ScrollView*>(_rootNode->getChildByName("ScrollView_2"));

    //Bug, this doen't work.
    scroller->jumpToBottom();

    auto points = scroller->getChildByName("ProjectNode_3");
    Vector<Node*> animPoints;
    animPoints.pushBack(points->getChildByName("Sprite_1_Copy_28_Copy_Copy"));
    animPoints.pushBack(points->getChildByName("Sprite_1_Copy_30_Copy_Copy"));
    animPoints.pushBack(points->getChildByName("Sprite_1_Copy_27_Copy_Copy"));
    animPoints.pushBack(points->getChildByName("Sprite_1_Copy_28_Copy"));
    animPoints.pushBack(points->getChildByName("Sprite_1_Copy_30_Copy"));
    animPoints.pushBack(points->getChildByName("Sprite_1_Copy_27_Copy"));

    for (int i = 0; i<animPoints.size(); ++i) {
        auto point = animPoints.at(i);

        auto root = CSLoader::createNode("StepAnimation.csb");
        root->setPosition(point->getPosition());
        
        point->getParent()->addChild(root);
        root->setOpacity(0);

        auto action = CSLoader::createTimeline("StepAnimation.csb");
        action->retain();

        root->scheduleOnce([root, action, point](float dt) {
            root->setOpacity(255);
            root->runAction(action);
            action->gotoFrameAndPlay(0, true);
            action->release();

            point->setVisible(false);
            action->setFrameEventCallFunc([point](Frame* frame) {
                auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
                if (event == "show_point") {
                    point->setVisible(true);
                } else if (event == "hide_point") {
                    point->setVisible(false);
                }
            });
        }, i, "run_foot_action");
    }

    auto entry1 = dynamic_cast<Sprite*>(points->getChildByName("Sprite_58"));
    auto entry2 = dynamic_cast<Sprite*>(points->getChildByName("Sprite_58_Copy"));

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch* touch, Event* event) {
        auto target = dynamic_cast<Sprite*>(event->getCurrentTarget());
        auto locationInNode = target->convertToNodeSpace(touch->getLocation());
        auto s = target->getContentSize();
        auto rect = Rect(0, 0, s.width, s.height);

        if (rect.containsPoint(locationInNode)) {
            return true;
        }
        return false;
    };

    //the _rootNode pointer will be invalid in the lamda function because of shared_pointer feature.
    auto rootNodeBackup = _rootNode;
    listener->onTouchEnded = [rootNodeBackup](Touch* touch, Event* event) {
        auto ready = CSLoader::createNode("DifficultySelection.csb");

        auto bkg = LayerColor::create(Color4B(0, 0, 0, 128));
        bkg->addChild(ready);
        rootNodeBackup->addChild(bkg);

        auto modelDialogListener = EventListenerTouchOneByOne::create();
        modelDialogListener->onTouchBegan = [](Touch *touch, Event *event){
            return true;
        };
        modelDialogListener->setSwallowTouches(true);
        bkg->getEventDispatcher()->addEventListenerWithSceneGraphPriority(modelDialogListener, bkg);

        auto btnClose = dynamic_cast<Button*>(ready->getChildByName("Button_Close"));
        btnClose->addClickEventListener(([rootNodeBackup, bkg](Ref*) {
            rootNodeBackup->removeChild(bkg);
        }));

        auto playA = dynamic_cast<Button*>(ready->getChildByName("Button_A"));
        auto playB = dynamic_cast<Button*>(ready->getChildByName("Button_B"));
        auto playC = dynamic_cast<Button*>(ready->getChildByName("Button_C"));
        auto playD = dynamic_cast<Button*>(ready->getChildByName("Button_D"));
        auto playE = dynamic_cast<Button*>(ready->getChildByName("Button_E"));
        auto playF = dynamic_cast<Button*>(ready->getChildByName("Button_F"));

        struct callBackFunctor {
            void operator() (Ref* sender) const {
                Director::getInstance()->replaceScene(TransitionCrossFade::create(.2f, StagePlay::createScene()));
            };
        };

        Widget::ccWidgetClickCallback callback = callBackFunctor();
        playA->addClickEventListener(callback);
        playB->addClickEventListener(callback);
        playC->addClickEventListener(callback);
        playD->addClickEventListener(callback);
        playE->addClickEventListener(callback);
        playF->addClickEventListener(callback);
    };

    _rootNode->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, entry1);
    _rootNode->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), entry2);

}