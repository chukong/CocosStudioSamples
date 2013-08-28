#include "TestChangeEquip.h"
#include <math.h>

using namespace std;

#define ICON_TAG 10000

enum EquipType
{
	EQUIP_GRID = -1,

	EQUIP_HERO,
	EQUIP_NECKLACE,
	EQUIP_RING,
	EQUIP_WEAPON,
	EQUIP_SHOE,
	EQUIP_FEET,
	EQUIP_TROUSERS,
	EQUIP_ARM,
	EQUIP_ARMOR,
	EQUIP_HELMET,

	EQUIP_MAX = 10000,
};

class EquipIcon : public CCSkin
{
public :
	static EquipIcon *createWithSpriteFrameName(const char *pszSpriteFrameName)
	{
		EquipIcon *icon = new EquipIcon();
		if(icon && icon->initWithSpriteFrameName(pszSpriteFrameName))
		{
			icon->autorelease();
			return icon;
		}
		CC_SAFE_DELETE(icon);
		return NULL;
	}

	CC_SYNTHESIZE(std::string, m_strIconName, IconName);
	CC_SYNTHESIZE(EquipType, m_strEquipType, EquipType);
};



TestChangeEquip::~TestChangeEquip()
{
	CCArmatureDataManager::purge();
}
void TestChangeEquip::onEnter()
{
	CCLayer::onEnter();
	setTouchEnabled(true);

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCSprite *bg = CCSprite::create("bg.jpg");
	bg->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	bg->setScale(2);
	addChild(bg);

	//! load data
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("knight.png", "knight.plist", "knight.xml");
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("weapon.png", "weapon.plist", "weapon.xml");

	//! create armature
	m_pArmature = cocos2d::extension::CCArmature::create("Knight_f/Knight");
	m_pArmature->getAnimation()->playByIndex(0);
	m_pArmature->getBone("weapon")->changeDisplayByIndex(-1, true);

	initUI();
	initEquip();
}

void TestChangeEquip::initUI()
{
	m_pSelectedGrid = m_pCurrentGrid = NULL;
	m_pCurrentIcon = NULL;

	m_pUiLayer = UILayer::create();
	m_pUiLayer->scheduleUpdate();
	addChild(m_pUiLayer);

	//! init change_equip_panel
	UIWidget *widget = CCUIHELPER->createWidgetFromJsonFile("ChangeEquipUI_1/ChangeEquipUI_1.json");
	m_pUiLayer->addWidget(widget);

	m_pChangeEquipPanel = widget->getChildByName("change_equip_panel");
	m_pEquipSlots = widget->getChildByName("equip_slots");

	//! set armature to center of change equipment panel  
	UIWidget *heroWidget = m_pChangeEquipPanel->getChildByName("equip_middle_hero");
	heroWidget->getContainerNode()->addChild(m_pArmature);

	adaptToSize(m_pArmature, m_pChangeEquipPanel->getContentSize(), 0.434f);


	//! init equip_grid_panel
	widget = CCUIHELPER->createWidgetFromJsonFile("ChangeEquipUI_2/ChangeEquipUI_2.json");
	m_pUiLayer->addWidget(widget);
	
	m_pEquipGridPanel = widget->getChildByName("equip_grid_panel");
	m_pCurrentGridPage = m_pEquipGridPanel->getChildByName("equip_page");
}

void TestChangeEquip::initEquip()
{
	CCArray *grids = m_pCurrentGridPage->getChildren();

	std::string weapon[] = {"weapon_f-sword.png", "weapon_f-sword2.png", "weapon_f-sword3.png", "weapon_f-sword4.png", "weapon_f-sword5.png", "weapon_f-knife.png", "weapon_f-hammer.png"};

	for (int i = 0; i < 7; i++)
	{
		EquipIcon *icon = EquipIcon::createWithSpriteFrameName(weapon[i].c_str());
		icon->setRotation(45);
		icon->setEquipType(EQUIP_WEAPON);
		icon->setIconName(weapon[i].c_str());

		UIWidget *grid = (UIWidget*)grids->objectAtIndex(i);
		grid->getContainerNode()->addChild(icon, 0, ICON_TAG);

		adaptToSize(icon, grid->getContentSize(), 0.9f);
	}
}

UIWidget *TestChangeEquip::getGridAtPoint(CCPoint point)
{
	CCArray *grids = m_pCurrentGridPage->getChildren();
	UIWidget *touchedGrid = NULL;

	CCObject *object = NULL;
	CCARRAY_FOREACH(grids, object)
	{
		UIWidget *grid = (UIWidget*)object;
		bool touched = grid->pointAtSelfBody(point);
		if (touched)
		{
			touchedGrid = grid;
			break;
		}
	}

	if (!touchedGrid)
	{
		CCArray *slots = m_pEquipSlots->getChildren();
		CCARRAY_FOREACH(slots, object)
		{
			UIWidget *slot = (UIWidget*)object;
			bool touched = slot->pointAtSelfBody(point);
			if (touched)
			{
				touchedGrid = slot;
				break;
			}
		}
	}

	return touchedGrid;
}

void TestChangeEquip::adaptToSize(CCNode *target, CCSize size, float sizeScale)
{
	CCSize targetize = target->boundingBox().size;
	float scaleX = size.width * sizeScale / targetize.width;
	float scaleY = size.height * sizeScale / targetize.height;
	float scale = min(scaleX, scaleY);
	target->setScale(scale);
}

void TestChangeEquip::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, INT_MIN+1, true);
}

bool TestChangeEquip::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint touchPoint = pTouch->getLocation();
	m_pSelectedGrid = m_pCurrentGrid = getGridAtPoint(touchPoint);

	if (m_pCurrentGrid)
	{
		m_pCurrentGrid->runAction(CCScaleTo::create(0.05f, 1.2f));
		m_pCurrentIcon = (EquipIcon*)(m_pSelectedGrid->getContainerNode()->getChildByTag(ICON_TAG));
		
		if (m_pCurrentIcon)
		{
			m_pCurrentIcon->retain();
			m_pCurrentIcon->removeFromParent();
			addChild(m_pCurrentIcon);
			m_pCurrentIcon->setPosition(touchPoint);
		}
	}
	return true;
}

void TestChangeEquip::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint touchPoint = pTouch->getLocation();

	UIWidget *grid = getGridAtPoint(touchPoint);

	if (grid != m_pCurrentGrid)
	{
		if (m_pCurrentGrid)
		{
			m_pCurrentGrid->runAction(CCScaleTo::create(0.05f, 1.0f));
		}
		if (grid)
		{
			grid->runAction(CCScaleTo::create(0.05f, 1.2f));
		}
		m_pCurrentGrid = grid;
	}

	if (m_pCurrentIcon)
	{
		m_pCurrentIcon->setPosition(touchPoint);
	}
}

void TestChangeEquip::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (m_pCurrentGrid)
	{
		m_pCurrentGrid->runAction(CCScaleTo::create(0.05f, 1.0f));
	}

	if (m_pCurrentIcon)
	{
		m_pCurrentIcon->removeFromParent();
		if (m_pCurrentGrid )
		{
			if ( m_pCurrentGrid->getWidgetTag() == -1 && !m_pCurrentGrid->getContainerNode()->getChildByTag(ICON_TAG))
			{
				m_pCurrentGrid->getContainerNode()->addChild(m_pCurrentIcon, 0, ICON_TAG);
			}
			else if(m_pCurrentIcon->getEquipType() == m_pCurrentGrid->getWidgetTag())
			{
				EquipIcon *icon = (EquipIcon*)m_pCurrentGrid->getContainerNode()->getChildByTag(ICON_TAG);
				if (icon)
				{
					icon->retain();
					icon->removeFromParent();
				}

				m_pCurrentGrid->getContainerNode()->addChild(m_pCurrentIcon, 0, ICON_TAG);

				if (icon)
				{
					m_pSelectedGrid->getContainerNode()->addChild(icon,  0, ICON_TAG);
					icon->release();
				}


				EquipIcon *equip = EquipIcon::createWithSpriteFrameName(m_pCurrentIcon->getIconName().c_str());
				m_pArmature->getBone("weapon")->addDisplay(equip, 0);
				m_pArmature->getBone("weapon")->changeDisplayByIndex(0, true);
			}
			else
			{
				m_pSelectedGrid->getContainerNode()->addChild(m_pCurrentIcon, 0, ICON_TAG);
			}
		}
		else
		{
			m_pSelectedGrid->getContainerNode()->addChild(m_pCurrentIcon, 0, ICON_TAG);
		}

		if (m_pSelectedGrid->getWidgetTag() == EQUIP_WEAPON && m_pCurrentGrid && m_pCurrentGrid->getWidgetTag() == -1)
		{
			m_pArmature->getBone("weapon")->changeDisplayByIndex(-1, true);
		}

		m_pCurrentIcon->release();
		m_pCurrentIcon->setPosition(ccp(0, 0));
	}

	m_pSelectedGrid = m_pCurrentGrid = NULL;
	m_pCurrentIcon = NULL;
}

