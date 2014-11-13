


#include "CocosGUIExamplesEquipScene.h"
#include "cocostudio/CCSSceneReader.h"
#include "cocostudio/CCSGUIReader.h"
#include "cocostudio/CCActionManagerEx.h"

CocosGUIExamplesEquipScene::CocosGUIExamplesEquipScene()
{
//    CCScene::init();
}

CocosGUIExamplesEquipScene::~CocosGUIExamplesEquipScene()
{
    
}

void CocosGUIExamplesEquipScene::onEnter()
{
    CCScene::onEnter();
    
    m_pUILayer = Layer::create();
    addChild(m_pUILayer);
    
    // equip initialize
    EquipInit();
    
    // exit button
    Button* exit_button = Button::create();
    exit_button->setTouchEnabled(true);
    exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    exit_button->setPosition(Point(m_pUILayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
    exit_button->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::menuCloseCallback));
    m_pUILayer->addChild(exit_button);
}

void CocosGUIExamplesEquipScene::onExit()
{
    m_pUILayer->removeFromParent();
    
    cocostudio::SceneReader::destroyInstance();
    cocostudio::GUIReader::destroyInstance();
    cocostudio::ActionManagerEx::destroyInstance();
    
    CCScene::onExit();
}

void CocosGUIExamplesEquipScene::menuCloseCallback(Ref* pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
            CCDirector::getInstance()->end();
            
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
#endif
            break;
            
        default:
            break;
    }
}

// equip
void CocosGUIExamplesEquipScene::EquipInit()
{
    m_eEquipType = EQUIP_TYPE_CLOTHES;
    
    m_dicBeUsedSlot = __Dictionary::create();
    CC_SAFE_RETAIN(m_dicBeUsedSlot);
    m_dicClothesSlot = __Dictionary::create();
    CC_SAFE_RETAIN(m_dicClothesSlot);
    m_dicWeaponsSlot = __Dictionary::create();
    CC_SAFE_RETAIN(m_dicWeaponsSlot);
    m_dicPetsSlot = __Dictionary::create();
    CC_SAFE_RETAIN(m_dicPetsSlot);
    
    m_dicClothes = __Dictionary::create();
    CC_SAFE_RETAIN(m_dicClothes);
    m_dicWeapons = __Dictionary::create();
    CC_SAFE_RETAIN(m_dicWeapons);
    m_dicPets = __Dictionary::create();
    CC_SAFE_RETAIN(m_dicPets);
    
    container_1_Zorder = 0;
    container_2_Zorder = 0;
    container_3_Zorder = 0;
    container_1_Position = Point::ZERO;
    container_2_Position = Point::ZERO;
    container_3_Position = Point::ZERO;
    movePoint = Point::ZERO;
    lastPoint = Point::ZERO;
    
    widgetLastWorldSpace = Point::ZERO;
    widgetLastNodeSpace = Point::ZERO;
    lastWidgetParent = NULL;
    //        
    
    // equip root from json
    Layout* equipe_root = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosgui/gui_examples/equip_1/equip_1.json"));
    equipe_root->setTag(EQUIP_LAYOUT_TAG_ROOT);
    m_pUILayer->addChild(equipe_root);
    
    // title layout
    Layout* title_layout = dynamic_cast<Layout*>(equipe_root->getChildByName("title_panel"));
    // close button
    Button* close_btn = dynamic_cast<Button*>(title_layout->getChildByName("close_button"));
    close_btn->setVisible(false);
//    close_btn->addReleaseEvent(this, coco_releaseselector(CocosGUIExamplesEquipScene::close));
    
    // up layout
    Layout* up_layout = dynamic_cast<Layout*>(equipe_root->getChildByName("up_panel"));
    up_layout->setTag(EQUIP_LAYOUT_TAG_UP);
    
    // switch button
    // close button
    Button* clothes_btn = dynamic_cast<Button*>(up_layout->getChildByName("clothes_button"));
    clothes_btn->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::switchBtnCallBack));
    clothes_btn->setTag(EQUIP_SWITCH_LAYOUT_BUTTON_TAG_CLOTHES);
    clothes_btn->setBright(false);
    
    // weapons button
    Button* weapons_btn = dynamic_cast<Button*>(up_layout->getChildByName("weapons_button"));
    weapons_btn->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::switchBtnCallBack));
    weapons_btn->setTag(EQUIP_SWITCH_LAYOUT_BUTTON_TAG_WEAPONS);
    
    // pets button
    Button* pets_btn = dynamic_cast<Button*>(up_layout->getChildByName("pets_button"));
    pets_btn->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::switchBtnCallBack));
    pets_btn->setTag(EQUIP_SWITCH_LAYOUT_BUTTON_TAG_PETS);
    
    // repertories
    // clothes layout
    Layout* clothes_layout = dynamic_cast<Layout*>(equipe_root->getChildByName("clothes_panel"));
    clothes_layout->setTag(EQUIP_LAYOUT_TAG_CLOTHES);
    
    // weapons layout
    Layout* weapons_layout = dynamic_cast<Layout*>(equipe_root->getChildByName("weapons_panel"));
    weapons_layout->setTag(EQUIP_LAYOUT_TAG_WEAPONS);
    
    // pets layout
    Layout* pets_layout = dynamic_cast<Layout*>(equipe_root->getChildByName("pets_panel"));
    pets_layout->setTag(EQUIP_LAYOUT_TAG_PETS);
    
    container_1_Zorder = clothes_layout->getZOrder();
    container_2_Zorder = weapons_layout->getZOrder();
    container_3_Zorder = pets_layout->getZOrder();
    
    container_1_Position = clothes_layout->getPosition();
    container_2_Position = weapons_layout->getPosition();
    container_3_Position = pets_layout->getPosition();
    
    // clothes repertory slot
    for (auto& obj : clothes_layout->getChildren())
    {
        Widget* child = dynamic_cast<Widget*>(obj);
        m_dicClothesSlot->setObject(child, child->getName());
    }
    // weapons repertory slot
    for (auto& obj : weapons_layout->getChildren())
    {
        Widget* child = dynamic_cast<Widget*>(obj);
        m_dicWeaponsSlot->setObject(child, child->getName());
    }
    // pets repertory slot
    for (auto& obj : pets_layout->getChildren())
    {
        Widget* child = dynamic_cast<Widget*>(obj);
        m_dicPetsSlot->setObject(child, child->getName());
    }
    
    // actor
    ImageView* wallBG_iv = dynamic_cast<ImageView*>(up_layout->getChildByName("wall"));
    ImageView* wal_iv = ImageView::create();
    wal_iv->loadTexture("cocosgui/gui_examples/equip_1/equip/eg/1.png");
    wal_iv->setAnchorPoint(Point(0.5, 0.5));
    float wal_x = wallBG_iv->getSize().width / 2.04;
    float wal_y = wallBG_iv->getSize().height / 2.4;
    wal_iv->setPosition(Point((-wallBG_iv->getSize().width / 2) +  wal_x,
                            (-wallBG_iv->getSize().height / 2) + wal_y));
    wallBG_iv->addChild(wal_iv);
    
    // original clothes be used slot
    ImageView* originalClothesSlot_iv = dynamic_cast<ImageView*>(up_layout->getChildByName("1"));
    ImageView* originalClothes_iv = ImageView::create();
    originalClothes_iv->loadTexture("cocosgui/gui_examples/equip_1/equip/eg/6.png");
    originalClothesSlot_iv->addChild(originalClothes_iv);
    m_dicBeUsedSlot->setObject(originalClothesSlot_iv, originalClothesSlot_iv->getName());
    
    // other be used slot
    ImageView* slot_2_iv = dynamic_cast<ImageView*>(up_layout->getChildByName("2"));
    m_dicBeUsedSlot->setObject(slot_2_iv, slot_2_iv->getName());
    ImageView* slot_3_iv = dynamic_cast<ImageView*>(up_layout->getChildByName("3"));
    m_dicBeUsedSlot->setObject(slot_3_iv, slot_3_iv->getName());
    ImageView* slot_4_iv = dynamic_cast<ImageView*>(up_layout->getChildByName("4"));
    m_dicBeUsedSlot->setObject(slot_4_iv, slot_4_iv->getName());
    ImageView* slot_5_iv = dynamic_cast<ImageView*>(up_layout->getChildByName("5"));
    m_dicBeUsedSlot->setObject(slot_5_iv, slot_5_iv->getName());
    ImageView* slot_6_iv = dynamic_cast<ImageView*>(up_layout->getChildByName("6"));
    m_dicBeUsedSlot->setObject(slot_6_iv, slot_6_iv->getName());
    
    // equip create
    create();
    
    // initialize touch able and influence children
    DictElement* element = NULL;
    clothes_layout->setTouchEnabled(true);
    CCDICT_FOREACH(m_dicClothesSlot, element)
    {
        Widget* child = dynamic_cast<Widget*>(element->getObject());
        child->setTouchEnabled(true);
    }
    CCDICT_FOREACH(m_dicClothes, element)
    {
        Widget* child = dynamic_cast<Widget*>(element->getObject());
        child->setTouchEnabled(true);
    }
    weapons_layout->setTouchEnabled(false);
    CCDICT_FOREACH(m_dicWeaponsSlot, element)
    {
        Widget* child = dynamic_cast<Widget*>(element->getObject());
        child->setTouchEnabled(false);
    }
    CCDICT_FOREACH(m_dicWeapons, element)
    {
        Widget* child = dynamic_cast<Widget*>(element->getObject());
        child->setTouchEnabled(false);
    }
    pets_layout->setTouchEnabled(false);
    CCDICT_FOREACH(m_dicPetsSlot, element)
    {
        Widget* child = dynamic_cast<Widget*>(element->getObject());
        child->setTouchEnabled(false);
    }
    CCDICT_FOREACH(m_dicPets, element)
    {
        Widget* child = dynamic_cast<Widget*>(element->getObject());
        child->setTouchEnabled(false);
    }
}

void CocosGUIExamplesEquipScene::create()
{
    createClothes();
    createWeapons();
    createPets();
}

void CocosGUIExamplesEquipScene::createClothes()
{
    Layout* equipe_root = dynamic_cast<Layout*>(m_pUILayer->getChildByTag(EQUIP_LAYOUT_TAG_ROOT));
    Layout* clothes_layout = dynamic_cast<Layout*>(Helper::seekWidgetByTag(equipe_root, EQUIP_LAYOUT_TAG_CLOTHES));
    
    // clothes
    float parent_w = clothes_layout->getSize().width;
    float parent_h = clothes_layout->getSize().height;
    float offest_x = parent_w / 10;
    float offest_y = parent_h / 6;
    
    const short columnMax = 3;
    
    // jacket
    const char* jacket_png[columnMax] =
    {
        "cocosgui/gui_examples/equip_1/equip/eg/3.png",
        "cocosgui/gui_examples/equip_1/equip/eg/4.png",
        "cocosgui/gui_examples/equip_1/equip/eg/5.png",
    };
    const char* jacket_name[columnMax] =
    {
        "jacket_taenia",
        "jacket_suit",
        "jacket_shoes",
    };
    // jacket imageview add to clothes slot
    for (int i = 0; i < columnMax; ++i)
    {
        ImageView* jacket_iv = ImageView::create();
        jacket_iv->loadTexture(jacket_png[i]);
        jacket_iv->setAnchorPoint(Point(0.5, 0.5));
        jacket_iv->setPosition(Point(offest_x + i * offest_x * 4, parent_h - offest_y));
        Node* node = clothes_layout->getChildren().back();
        Widget* lastChild = dynamic_cast<Widget*>(node);
        if (lastChild)
        {
            jacket_iv->setZOrder(lastChild->getZOrder() + 1);
        }
        jacket_iv->setName(jacket_name[i]);
        jacket_iv->setTouchEnabled(true);
        jacket_iv->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::touch));
        
        for (auto& obj : clothes_layout->getChildren())
        {
            Widget* slot = dynamic_cast<Widget*>(obj);
            slot->setCascadeColorEnabled(false);
            if (slot->boundingBox().containsPoint(jacket_iv->getPosition()))
            {
                jacket_iv->setPosition(Point::ZERO);
                slot->addChild(jacket_iv);
                break;
            }
        }
        /**/
        
        m_dicClothes->setObject(jacket_iv, jacket_iv->getName());
    }
    
    // kimono
    const char* kimono_png[columnMax] =
    {
        "cocosgui/gui_examples/equip_1/equip/eg/8.png",
        "cocosgui/gui_examples/equip_1/equip/eg/10.png",
        "cocosgui/gui_examples/equip_1/equip/eg/9.png",
    };
    const char* kimono_name[columnMax] =
    {
        "kimono_strawhat",
        "kimono_suit",
        "kimono_shoes",
    };
    // kimono imageview add to clothes slot
    for (int i = 0; i < columnMax; ++i)
    {
        ImageView* kimono_iv = ImageView::create();
        kimono_iv->loadTexture(kimono_png[i]);
        kimono_iv->setPosition(Point(offest_x + i * offest_x * 4, parent_h - offest_y * 3));
        Node* node = clothes_layout->getChildren().back();
        Widget* lastChild = dynamic_cast<Widget*>(node);
        if (lastChild)
        {
            kimono_iv->setZOrder(lastChild->getZOrder() + 1);
        }
        kimono_iv->setName(kimono_name[i]);
        kimono_iv->setTouchEnabled(true);
        kimono_iv->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::touch));
        
        for (auto& obj : clothes_layout->getChildren())
        {
            Widget* slot = dynamic_cast<Widget*>(obj);
            slot->setCascadeColorEnabled(false);
            if (slot->boundingBox().containsPoint(kimono_iv->getPosition()))
            {
                kimono_iv->setPosition(Point::ZERO);
                slot->addChild(kimono_iv);
                break;
            }            
        }
        
        m_dicClothes->setObject(kimono_iv, kimono_iv->getName());
    }
}

void CocosGUIExamplesEquipScene::createWeapons()
{
    Layout* equipe_root = dynamic_cast<Layout*>(m_pUILayer->getChildByTag(EQUIP_LAYOUT_TAG_ROOT));
    Layout* weapons_panel = dynamic_cast<Layout*>(Helper::seekWidgetByTag(equipe_root, EQUIP_LAYOUT_TAG_WEAPONS));
    
    // weapons
    float parent_w = weapons_panel->getSize().width;
    float parent_h = weapons_panel->getSize().height;
    float offest_x = parent_w / 10;
    float offest_y = parent_h / 6;
    
    // sword
    const short swordAmount = 3;
    const char* sword_png[swordAmount] =
    {
        "cocosgui/gui_examples/equip_1/equip/eg/train.png",
        "cocosgui/gui_examples/equip_1/equip/eg/research.png",
        "cocosgui/gui_examples/equip_1/equip/eg/upgrade.png",
    };
    const char* sword_name[swordAmount] =
    {
        "sword_sword",
        "sword_plus",
        "sword_hammer",
    };
    // sword imageview add to weapons slot
    for (int i = 0; i < swordAmount; ++i)
    {
        ImageView* sword_iv = ImageView::create();
        sword_iv->loadTexture(sword_png[i]);
        sword_iv->setPosition(Point(offest_x, parent_h - offest_y - i * (offest_y * 2)));
        Node* node = weapons_panel->getChildren().back();
        Widget* lastChild = dynamic_cast<Widget*>(node);
        if (lastChild)
        {
            sword_iv->setZOrder(lastChild->getZOrder() + 1);
        }
        sword_iv->setName(sword_name[i]);
        sword_iv->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::touch));
        
        for (auto& obj : weapons_panel->getChildren())
        {
            Widget* slot = dynamic_cast<Widget*>(obj);
            slot->setCascadeColorEnabled(false);
            if (slot->boundingBox().containsPoint(sword_iv->getPosition()))
            {
                sword_iv->setPosition(Point::ZERO);
                slot->addChild(sword_iv);
                break;
            }
        }
        
        m_dicWeapons->setObject(sword_iv, sword_iv->getName());
    }
    
    // arrow
    const short arrowAmount = 3;
    const char* arrow_png[arrowAmount] =
    {
        "cocosgui/gui_examples/equip_1/equip/eg/shop_shield_1.png",
        "cocosgui/gui_examples/equip_1/equip/eg/shop_shield_2.png",
        "cocosgui/gui_examples/equip_1/equip/eg/shop_shield_3.png",
    };
    const char* arrow_name[arrowAmount] =
    {
        "arraw_normal",
        "arraw_hard",
        "arraw_devil",
    };
    // arrow imageview add to weapons slot
    for (int i = 0; i < arrowAmount; ++i)
    {
        ImageView* arrow_iv = ImageView::create();
        arrow_iv->loadTexture(arrow_png[i]);
        arrow_iv->setPosition(Point(offest_x * 5, parent_h - offest_y - i * (offest_y * 2)));
        Node* node = weapons_panel->getChildren().back();
        Widget* lastChild = dynamic_cast<Widget*>(node);
        if (lastChild)
        {
            arrow_iv->setZOrder(lastChild->getZOrder() + 1);
        }
        arrow_iv->setName(arrow_name[i]);
        arrow_iv->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::touch));
        
        for (auto& obj : weapons_panel->getChildren())
        {
            Widget* slot = dynamic_cast<Widget*>(obj);
            slot->setCascadeColorEnabled(false);
            if (slot->boundingBox().containsPoint(arrow_iv->getPosition()))
            {
                arrow_iv->setPosition(Point::ZERO);
                slot->addChild(arrow_iv);
                break;
            }
        }
        
        m_dicWeapons->setObject(arrow_iv, arrow_iv->getName());
    }
    
    // bomb
    const short bombAmount = 1;
    const char* bomb_png[bombAmount] =
    {
        "cocosgui/gui_examples/equip_1/equip/eg/sell.png",
    };
    const char* bomb_name[bombAmount] =
    {
        "bomb_normal",
    };
    // bomo imageview add to weapons slot
    for (int i = 0; i < bombAmount; ++i)
    {
        ImageView* bomb_iv = ImageView::create();
        bomb_iv->loadTexture(bomb_png[i]);
        bomb_iv->setPosition(Point(offest_x * 9, parent_h - offest_y - i * (offest_y * 2)));
        Node* node = weapons_panel->getChildren().back();
        Widget* lastChild = dynamic_cast<Widget*>(node);
        if (lastChild)
        {
            bomb_iv->setZOrder(lastChild->getZOrder() + 1);
        }
        bomb_iv->setName(bomb_name[i]);
        bomb_iv->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::touch));
        
        for (auto& obj : weapons_panel->getChildren())
        {
            Widget* slot = dynamic_cast<Widget*>(obj);
            slot->setCascadeColorEnabled(false);
            if (slot->boundingBox().containsPoint(bomb_iv->getPosition()))
            {
                bomb_iv->setPosition(Point::ZERO);
                slot->addChild(bomb_iv);
                break;
            }
        }
        
        m_dicWeapons->setObject(bomb_iv, bomb_iv->getName());
    }
}

void CocosGUIExamplesEquipScene::createPets()
{
    Layout* equipe_root = dynamic_cast<Layout*>(m_pUILayer->getChildByTag(EQUIP_LAYOUT_TAG_ROOT));
    Layout* pets_layout = dynamic_cast<Layout*>(Helper::seekWidgetByTag(equipe_root, EQUIP_LAYOUT_TAG_PETS));
    
    // pets
    float parent_w = pets_layout->getSize().width;
    float parent_h = pets_layout->getSize().height;
    float offest_x = parent_w / 10;
    float offest_y = parent_h / 6;
    
    // dragon
    const short dragonAmount = 1;
    const char* dragon_png[dragonAmount] =
    {
        "cocosgui/gui_examples/equip_1/equip/eg/7.png",
    };
    const char* dragon_name[dragonAmount] =
    {
        "pet_dragon",
    };
    // dragon imageview add to pets slot
    for (int i = 0; i < dragonAmount; ++i)
    {
        ImageView* dragon_iv = ImageView::create();
        dragon_iv->loadTexture(dragon_png[i]);
        dragon_iv->setPosition(Point(offest_x, parent_h - offest_y - i * (offest_y * 2)));
        Node* node = pets_layout->getChildren().back();
        Widget* lastChild = dynamic_cast<Widget*>(node);
        if (lastChild)
        {
            dragon_iv->setZOrder(lastChild->getZOrder() + 1);
        }
        dragon_iv->setName(dragon_name[i]);
        dragon_iv->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::touch));
        
        for (auto& obj : pets_layout->getChildren())
        {
            Widget* slot = dynamic_cast<Widget*>(obj);
            slot->setCascadeColorEnabled(false);            
            if (slot->boundingBox().containsPoint(dragon_iv->getPosition()))
            {
                dragon_iv->setPosition(Point::ZERO);
                slot->addChild(dragon_iv);
                break;
            }
        }
        
        m_dicPets->setObject(dragon_iv, dragon_iv->getName());
    }
    
    // crab
    const short crabAmount = 1;
    const char* crab_png[crabAmount] =
    {
        "cocosgui/gui_examples/equip_1/equip/eg/crab.png",
    };
    const char* crab_name[crabAmount] =
    {
        "pet_crab",
    };
    // crab imageview add to pets slot
    for (int i = 0; i < crabAmount; ++i)
    {
        ImageView* crab_iv = ImageView::create();
        crab_iv->loadTexture(crab_png[i]);
        crab_iv->setPosition(Point(offest_x * 5, parent_h - offest_y - i * (offest_y * 2)));
        Node* node = pets_layout->getChildren().back();
        Widget* lastChild = dynamic_cast<Widget*>(node);
        if (lastChild)
        {
            crab_iv->setZOrder(lastChild->getZOrder() + 1);
        }
        crab_iv->setName(crab_name[i]);
        crab_iv->addTouchEventListener(this, toucheventselector(CocosGUIExamplesEquipScene::touch));
        
        for (auto& obj : pets_layout->getChildren())
        {
            Widget* slot = dynamic_cast<Widget*>(obj);
            slot->setCascadeColorEnabled(false);
            if (slot->boundingBox().containsPoint(crab_iv->getPosition()))
            {
                crab_iv->setPosition(Point::ZERO);
                slot->addChild(crab_iv);
                break;
            }                        
        }
        
        m_dicPets->setObject(crab_iv, crab_iv->getName());
    }
    
}

void CocosGUIExamplesEquipScene::switchBtnCallBack(Ref *pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_ENDED:
        {
            // switch button
            Button* button = dynamic_cast<Button*>(pSender);
            
            // equip root
            /* for 2.0 */
            Layout* root = dynamic_cast<Layout*>(m_pUILayer->getChildByTag(EQUIP_LAYOUT_TAG_ROOT));
            // before
//            Layout* root = dynamic_cast<Layout*>(m_pUILayer->getWidgetByTag(EQUIP_LAYOUT_TAG_ROOT));
            /**/
            
            // equip repertory
            Layout* clothes_layout = dynamic_cast<Layout*>(root->getChildByTag(EQUIP_LAYOUT_TAG_CLOTHES));
            Layout* weapons_layout = dynamic_cast<Layout*>(root->getChildByTag(EQUIP_LAYOUT_TAG_WEAPONS));
            Layout* pets_layout = dynamic_cast<Layout*>(root->getChildByTag(EQUIP_LAYOUT_TAG_PETS));
            
            Layout* up_layout = dynamic_cast<Layout*>(root->getChildByTag(EQUIP_LAYOUT_TAG_UP));
            Button* clothes_btn = dynamic_cast<Button*>(up_layout->getChildByTag(EQUIP_SWITCH_LAYOUT_BUTTON_TAG_CLOTHES));
            Button* weapons_btn = dynamic_cast<Button*>(up_layout->getChildByTag(EQUIP_SWITCH_LAYOUT_BUTTON_TAG_WEAPONS));
            Button* pets_btn = dynamic_cast<Button*>(up_layout->getChildByTag(EQUIP_SWITCH_LAYOUT_BUTTON_TAG_PETS));
            
            clothes_btn->setBright(true);
            weapons_btn->setBright(true);
            pets_btn->setBright(true);
            
            DictElement* element = NULL;
            
            // switch slot
            switch (button->getTag())
            {
                case EQUIP_SWITCH_LAYOUT_BUTTON_TAG_CLOTHES:
                {
                    m_eEquipType = EQUIP_TYPE_CLOTHES;
                    
                    clothes_btn->setBright(false);
                    
                    clothes_layout->setZOrder(container_1_Zorder);
                    weapons_layout->setZOrder(container_2_Zorder);
                    pets_layout->setZOrder(container_3_Zorder);
                    
                    clothes_layout->setPosition(container_1_Position);
                    weapons_layout->setPosition(container_2_Position);
                    pets_layout->setPosition(container_3_Position);
                    
                    // equip slot touch able
                    clothes_layout->setTouchEnabled(true);
                    CCDICT_FOREACH(m_dicClothesSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(true);
                    }
                    CCDICT_FOREACH(m_dicClothes, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(true);
                    }
                    weapons_layout->setTouchEnabled(false);
                    CCDICT_FOREACH(m_dicWeaponsSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    CCDICT_FOREACH(m_dicWeapons, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    pets_layout->setTouchEnabled(false);
                    CCDICT_FOREACH(m_dicPetsSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    CCDICT_FOREACH(m_dicPets, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                }
                    break;
                    
                case EQUIP_SWITCH_LAYOUT_BUTTON_TAG_WEAPONS:
                {
                    m_eEquipType = EQUIP_TYPE_WEAPONS;
                    
                    weapons_btn->setBright(false);
                    
                    clothes_layout->setZOrder(container_3_Zorder);
                    weapons_layout->setZOrder(container_1_Zorder);
                    pets_layout->setZOrder(container_2_Zorder);
                    
                    weapons_layout->setPosition(container_1_Position);
                    pets_layout->setPosition(container_2_Position);
                    clothes_layout->setPosition(container_3_Position);
                    
                    // equip slot touch able
                    weapons_layout->setTouchEnabled(true);
                    CCDICT_FOREACH(m_dicWeaponsSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(true);
                    }
                    CCDICT_FOREACH(m_dicWeapons, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(true);
                    }
                    clothes_layout->setTouchEnabled(false);
                    DictElement* element = NULL;
                    CCDICT_FOREACH(m_dicClothesSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    CCDICT_FOREACH(m_dicClothes, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    pets_layout->setTouchEnabled(false);
                    CCDICT_FOREACH(m_dicPetsSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    CCDICT_FOREACH(m_dicPets, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                }
                    break;
                    
                case EQUIP_SWITCH_LAYOUT_BUTTON_TAG_PETS:
                {
                    m_eEquipType = EQUIP_TYPE_PETS;
                    
                    pets_btn->setBright(false);
                    
                    pets_layout->setZOrder(container_1_Zorder);
                    clothes_layout->setZOrder(container_2_Zorder);
                    weapons_layout->setZOrder(container_3_Zorder);
                    
                    pets_layout->setPosition(container_1_Position);
                    clothes_layout->setPosition(container_2_Position);
                    weapons_layout->setPosition(container_3_Position);
                    
                    // equip slot touch able
                    pets_layout->setTouchEnabled(true);
                    CCDICT_FOREACH(m_dicPetsSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(true);
                    }
                    CCDICT_FOREACH(m_dicPets, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(true);
                    }
                    clothes_layout->setTouchEnabled(false);
                    CCDICT_FOREACH(m_dicClothesSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    CCDICT_FOREACH(m_dicClothes, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    weapons_layout->setTouchEnabled(false);
                    CCDICT_FOREACH(m_dicWeaponsSlot, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }
                    CCDICT_FOREACH(m_dicWeapons, element)
                    {
                        Widget* child = dynamic_cast<Widget*>(element->getObject());
                        child->setTouchEnabled(false);
                    }            
                }
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
        default:
            break;
    }
}

void CocosGUIExamplesEquipScene::touch(Ref *pSender, TouchEventType type)
{
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
        {
            Widget* widget = dynamic_cast<Widget*>(pSender);
            Point worldSpace = widget->convertToWorldSpace(Point::ZERO);
            
            widgetLastWorldSpace = worldSpace;
            widgetLastNodeSpace = widget->getPosition();
            
            lastWidgetParent = static_cast<Widget*>(widget->getParent());
            widget->removeFromParentAndCleanup(false);
            
            m_pUILayer->addChild(widget);
            
            widget->setPosition(widget->getTouchStartPos());
            movePoint = widget->getTouchStartPos();
        }
            break;
            
        case TOUCH_EVENT_MOVED:
        {
            Widget* widget = dynamic_cast<Widget*>(pSender);
            
            lastPoint = movePoint;
            movePoint = widget->getTouchMovePos();
            Point offset = movePoint - lastPoint;
            Point toPoint = widget->getPosition() + offset;
            widget->setPosition(toPoint);
        }
            break;
            
        case TOUCH_EVENT_ENDED:
        {
            bool isInUsedSlot = false;
            bool isInEquipSlot = false;
            
            Widget* widget = dynamic_cast<Widget*>(pSender);
            
            DictElement* element = NULL;
            
            // drop into used slot
            CCDICT_FOREACH(m_dicBeUsedSlot, element)
            {
                Widget* usedSlot_wigt = dynamic_cast<Widget*>(element->getObject());
                if (usedSlot_wigt->getChildren().size() > 0)
                {
                    continue;
                }
                
                if (usedSlot_wigt->hitTest(widget->getPosition()))
                {
                    widget->removeFromParentAndCleanup(false);
                    widget->setPosition(Point::ZERO);
                    usedSlot_wigt->addChild(widget);
                    
                    isInUsedSlot = true;
                    break;
                }
            }
            
            // drop into equip slot
            __Dictionary* equipSlot_dic = NULL;
            __Dictionary* equip_dic = NULL;
            switch (m_eEquipType)
            {
                case EQUIP_TYPE_CLOTHES:
                    equipSlot_dic = m_dicClothesSlot;
                    equip_dic = m_dicClothes;
                    break;
                    
                case EQUIP_TYPE_WEAPONS:
                    equipSlot_dic = m_dicWeaponsSlot;
                    equip_dic = m_dicWeapons;
                    break;
                    
                case EQUIP_TYPE_PETS:
                    equipSlot_dic = m_dicPetsSlot;
                    equip_dic = m_dicPets;
                    break;
                    
                default:
                    break;
            }
            
            CCDICT_FOREACH(equipSlot_dic, element)
            {
                Widget* equipSlot = dynamic_cast<Widget*>(element->getObject());
                if (equipSlot->getChildren().size() > 0)
                {
                    continue;
                }
                
                if (equipSlot->hitTest(widget->getPosition()))
                {
                    Ref* obj = equip_dic->objectForKey(widget->getName());
                    if (obj)
                    {
                        widget->removeFromParentAndCleanup(false);
                        widget->setPosition(Point::ZERO);
                        equipSlot->addChild(widget);
                        
                        isInEquipSlot = true;
                    }
                    break;
                }
            }
            
            // back to last position if cannot drop other slot
            if (!isInUsedSlot && !isInEquipSlot)
            {
                Point point = widgetLastWorldSpace;
                MoveTo* moveTo = MoveTo::create(1.0f, point);
                EaseExponentialOut* ease = EaseExponentialOut::create(moveTo);
                __CCCallFuncO* calllFunc0 = __CCCallFuncO::create(this, callfuncO_selector(CocosGUIExamplesEquipScene::backOver), widget);
                Sequence* seq = Sequence::create(ease, calllFunc0, NULL);
                widget->runAction(seq);
                
                // widget in equip slot
                CCDICT_FOREACH(equip_dic, element)
                {
                    Widget* widget = dynamic_cast<Widget*>(element->getObject());
                    widget->setTouchEnabled(false);
                }
                
                // equip up layout
                Layout* equipe_root = dynamic_cast<Layout*>(m_pUILayer->getChildByTag(EQUIP_LAYOUT_TAG_ROOT));
                Layout* up_layout = dynamic_cast<Layout*>(equipe_root->getChildByName("up_panel"));
                up_layout->setTouchEnabled(false);
                for (auto& obj : up_layout->getChildren())
                {
                    Widget* child = dynamic_cast<Widget*>(obj);
                    child->setTouchEnabled(false);
                }
            }
        }
            break;
            
        default:
            break;
    }
}

void CocosGUIExamplesEquipScene::backOver(Ref *pObject)
{
    Widget* widget = dynamic_cast<Widget*>(pObject);
    
    widget->removeFromParentAndCleanup(false);
    lastWidgetParent->addChild(widget);
    widget->setPosition(widgetLastNodeSpace);
    
    DictElement* element = NULL;
    
    // equip
    __Dictionary* equip_dic = NULL;
    switch (m_eEquipType)
    {
        case EQUIP_TYPE_CLOTHES:
            equip_dic = m_dicClothes;
            break;
            
        case EQUIP_TYPE_WEAPONS:
            equip_dic = m_dicWeapons;
            break;
            
        case EQUIP_TYPE_PETS:
            equip_dic = m_dicPets;
            break;
            
        default:
            break;
    }
    CCDICT_FOREACH(equip_dic, element)
    {
        Widget* widget = dynamic_cast<Widget*>(element->getObject());
        widget->setTouchEnabled(true);
    }
    
    // equip up layout
    Layout* equip_root = dynamic_cast<Layout*>(m_pUILayer->getChildByTag(EQUIP_LAYOUT_TAG_ROOT));
    Layout* up_layout = dynamic_cast<Layout*>(equip_root->getChildByName("up_panel"));
    up_layout->setTouchEnabled(true);
    for (auto& obj : up_layout->getChildren())
    {
        Widget* child = dynamic_cast<Widget*>(obj);
        child->setTouchEnabled(true);
    }
}

void CocosGUIExamplesEquipScene::close(Ref* pObject)
{
    
    // equip
    Layout* equip_root = dynamic_cast<Layout*>(m_pUILayer->getChildByTag(EQUIP_LAYOUT_TAG_ROOT));
    equip_root->setVisible(false);
}