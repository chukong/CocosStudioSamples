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

#include "StagePlay.h"
#include "CocosGUI.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
#include "cocostudio/CCComAudio.h"
#include "StageMap.h"

USING_NS_CC;
using namespace ui;
USING_NS_TIMELINE;
using namespace cocostudio;

void StagePlay::initialize() {
    _rootNode = CSLoader::createNode("BattleScene.csb");
    auto shark = _rootNode->getChildByName("ProjectNode_Battle")->getChildByName("ProjectNode_Boss");
    auto tentacle = _rootNode->getChildByName("ProjectNode_Battle")->getChildByName("ProjectNode_Monster");
    auto sharkAnim = dynamic_cast<ActionTimeline*>(shark->getActionByTag(shark->getTag()));
    auto tentacleAnim = dynamic_cast<ActionTimeline*>(tentacle->getActionByTag(tentacle->getTag()));
    sharkAnim->pause();
    tentacleAnim->pause();

    auto players = _rootNode->getChildByName("ProjectNode_Bottom")->getChildByName("Panel")
        ->getChildByName("battle")->getChildByName("Sprite_Herobox");
    auto player1 = players->getChildByName("Panel_Hero_1")->getChildByName("ProjectNode_Hero_1");
    auto player2 = players->getChildByName("Panel_Hero_2")->getChildByName("ProjectNode_Hero_2");
    auto player3 = players->getChildByName("Panel_Hero_3")->getChildByName("ProjectNode_Hero_3");
    auto player4 = players->getChildByName("Panel_Hero_4")->getChildByName("ProjectNode_Hero_4");
    auto player5 = players->getChildByName("Panel_Hero_5")->getChildByName("ProjectNode_Hero_5");

    auto player1Anim = dynamic_cast<ActionTimeline*>(player1->getActionByTag(player1->getTag()));
    auto player2Anim = dynamic_cast<ActionTimeline*>(player2->getActionByTag(player2->getTag()));
    auto player3Anim = dynamic_cast<ActionTimeline*>(player3->getActionByTag(player3->getTag()));
    auto player4Anim = dynamic_cast<ActionTimeline*>(player4->getActionByTag(player4->getTag()));
    auto player5Anim = dynamic_cast<ActionTimeline*>(player5->getActionByTag(player5->getTag()));

    player1Anim->pause();
    player2Anim->pause();
    player3Anim->pause();
    player4Anim->pause();
    player5Anim->pause();

    player1Anim->gotoFrameAndPlay(0, false);

    player1Anim->setFrameEventCallFunc([player2Anim](Frame* frame) {
        auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
        if (event != "player1_end") {
            return;
        }
        player2Anim->gotoFrameAndPlay(0, false);
    });

    player2Anim->setFrameEventCallFunc([player3Anim](Frame* frame) {
        auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
        if (event != "player2_end") {
            return;
        }
        player3Anim->gotoFrameAndPlay(0, false);
    });

    player3Anim->setFrameEventCallFunc([player4Anim](Frame* frame) {
        auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
        if (event != "player3_end") {
            return;
        }
        player4Anim->gotoFrameAndPlay(0, false);
    });

    player4Anim->setFrameEventCallFunc([player5Anim](Frame* frame) {
        auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
        if (event != "player4_end") {
            return;
        }
        player5Anim->gotoFrameAndPlay(0, false);
    });

    player5Anim->setFrameEventCallFunc([sharkAnim, tentacleAnim](Frame* frame) {
        auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
        if (event != "player5_end") {
            return;
        }
        sharkAnim->gotoFrameAndPlay(0, false);
        tentacleAnim->gotoFrameAndPlay(0, false);
    });

    //the _rootNode pointer will be invalid in the lamda function because of shared_pointer feature.
    auto rootNodeBackup = _rootNode;
    sharkAnim->setFrameEventCallFunc([rootNodeBackup, this](Frame* frame) {
        auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
        if (event != "enemy_down") {
            return;
        }
        victory(rootNodeBackup);
    });
}

void StagePlay::victory(Node* rootNode) {
    auto victory = CSLoader::createNode("BattleResult.csb");

    auto audioNode = victory->getChildByName("Audio_1");
    auto comAudio = dynamic_cast<ComAudio*>(audioNode->getComponent("Audio_1"));
    comAudio->playEffect();

    auto victoryAnimPart = victory->getChildByName("Node_win");
    auto victoryUIPart = victory->getChildByName("Node_ui");
    auto btn1 = dynamic_cast<Button*>(victoryUIPart->getChildByName("Button_Gohome"));
    auto btn2 = dynamic_cast<Button*>(victoryUIPart->getChildByName("Button_Provoke"));
    struct callBackFunctor {
        void operator() (Ref* sender) const {
            Director::getInstance()->replaceScene(TransitionCrossFade::create(.2f, StageMap::createScene()));
        }
    };
    Widget::ccWidgetClickCallback callback = callBackFunctor();
    btn1->addClickEventListener(callback);
    btn2->addClickEventListener(callback);

    victoryUIPart->setVisible(false);
    rootNode->addChild(victory);
    auto victoryAnim = dynamic_cast<ActionTimeline*>(victoryAnimPart->getActionByTag(victoryAnimPart->getTag()));
    victoryAnim->pause();
    victoryAnim->gotoFrameAndPlay(0, false);
    victoryAnim->setFrameEventCallFunc([victoryUIPart, victoryAnimPart](Frame* frame) {
        auto event = dynamic_cast<EventFrame*>(frame)->getEvent();
        if (event != "show_end") {
            return;
        }

        victoryUIPart->setVisible(true);
        victoryAnimPart->setVisible(false);
    });
}
