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

#include "StageLevelSelect.h"
#include "CocosGUI.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "WidgetUserMenu.h"
#include "StageMap.h"
#include "StageHome.h"

USING_NS_CC;
using namespace ui;

void StageLevelSelect::initialize() {
    _rootNode = CSLoader::createNode("LevelSelection.csb");
    auto menu = CSLoader::createNode("MainMenu.csb");
    WidgetUserMenu::initialize(menu, StageType::LEVEL_SELECT);
    auto info = CSLoader::createNode("PlayerStats.csb");
    menu->setPosition(StageHome::g_posMenu);
    info->setPosition(StageHome::g_posInfo);
    _rootNode->addChild(menu);
    _rootNode->addChild(info);

    auto buttonLeft = dynamic_cast<Button*>(_rootNode->getChildByName("Button_Left"));
    buttonLeft->setVisible(false);
    auto buttonRight = dynamic_cast<Button*>(_rootNode->getChildByName("Button_Right"));
    auto buttonStart = dynamic_cast<Button*>(_rootNode->getChildByName("Button_Enter"));
    auto levelSelector = dynamic_cast<PageView*>(_rootNode->getChildByName("PageView_SelectPage"));
    auto pageIndex = dynamic_cast<TextAtlas*>(_rootNode->getChildByName("LabelAtlas_CurrentScene"));

    levelSelector->addEventListener([pageIndex, levelSelector, buttonLeft, buttonRight, buttonStart]
        (Ref*, PageView::EventType) {
        auto pageIndexText = __String::createWithFormat("%d/3", levelSelector->getCurPageIndex() + 1);
        pageIndex->setString(pageIndexText->getCString());

        switch (levelSelector->getCurPageIndex()) {
        case 0:
            buttonLeft->setVisible(false);
            buttonRight->setVisible(true);
            buttonStart->setVisible(true);
            break;
        case 1:
            buttonLeft->setVisible(true);
            buttonRight->setVisible(true);
            buttonStart->setVisible(false);
            break;
        case 2:
            buttonLeft->setVisible(true);
            buttonRight->setVisible(false);
            buttonStart->setVisible(false);
            break;
        default:
            buttonLeft->setVisible(true);
            buttonRight->setVisible(true);
            buttonStart->setVisible(true);
            break;
        }
    });

    buttonLeft->addClickEventListener([levelSelector](Ref*) {
        levelSelector->scrollToPage(levelSelector->getCurPageIndex() - 1);
    });

    buttonRight->addClickEventListener([levelSelector, this](Ref*) {
        levelSelector->scrollToPage(levelSelector->getCurPageIndex() + 1);
    });

    buttonStart->addClickEventListener([](Ref*) {
        Director::getInstance()->replaceScene(TransitionCrossFade::create(.2f, StageMap::createScene()));
    });
}