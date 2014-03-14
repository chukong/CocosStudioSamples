/**
 * @module cocos2dx_studio
 */
var ccs = ccs || {};

/**
 * @class UILayoutParameter
 */
ccs.UILayoutParameter = {

/**
 * @method getLayoutType
 * @return A value converted from C/C++ "gui::LayoutParameterType"
 */
getLayoutType : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILayoutParameter*"
 */
create : function () {},

/**
 * @method UILayoutParameter
 * @constructor
 */
UILayoutParameter : function () {},

};

/**
 * @class UILinearLayoutParameter
 */
ccs.UILinearLayoutParameter = {

/**
 * @method setGravity
 * @param {gui::UILinearGravity}
 */
setGravity : function () {},

/**
 * @method getGravity
 * @return A value converted from C/C++ "gui::UILinearGravity"
 */
getGravity : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILinearLayoutParameter*"
 */
create : function () {},

/**
 * @method UILinearLayoutParameter
 * @constructor
 */
UILinearLayoutParameter : function () {},

};

/**
 * @class UIRelativeLayoutParameter
 */
ccs.UIRelativeLayoutParameter = {

/**
 * @method setAlign
 * @param {gui::UIRelativeAlign}
 */
setAlign : function () {},

/**
 * @method setRelativeToWidgetName
 * @param {const char*}
 */
setRelativeToWidgetName : function () {},

/**
 * @method getRelativeName
 * @return A value converted from C/C++ "const char*"
 */
getRelativeName : function () {},

/**
 * @method getRelativeToWidgetName
 * @return A value converted from C/C++ "const char*"
 */
getRelativeToWidgetName : function () {},

/**
 * @method setRelativeName
 * @param {const char*}
 */
setRelativeName : function () {},

/**
 * @method getAlign
 * @return A value converted from C/C++ "gui::UIRelativeAlign"
 */
getAlign : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIRelativeLayoutParameter*"
 */
create : function () {},

/**
 * @method UIRelativeLayoutParameter
 * @constructor
 */
UIRelativeLayoutParameter : function () {},

};

/**
 * @class UIWidget
 */
ccs.UIWidget = {

/**
 * @method addChild
 * @return A value converted from C/C++ "bool"
 * @param {gui::UIWidget*}
 */
addChild : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method setActionTag
 * @param {int}
 */
setActionTag : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method getChildren
 * @return A value converted from C/C++ "cocos2d::Array*"
 */
getChildren : function () {},

/**
 * @method getPositionType
 * @return A value converted from C/C++ "gui::PositionType"
 */
getPositionType : function () {},

/**
 * @method getChildByName
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {const char*}
 */
getChildByName : function () {},

/**
 * @method isEnabled
 * @return A value converted from C/C++ "bool"
 */
isEnabled : function () {},

/**
 * @method isFlipX
 * @return A value converted from C/C++ "bool"
 */
isFlipX : function () {},

/**
 * @method isFlipY
 * @return A value converted from C/C++ "bool"
 */
isFlipY : function () {},

/**
 * @method didNotSelectSelf
 */
didNotSelectSelf : function () {},

/**
 * @method setFocused
 * @param {bool}
 */
setFocused : function () {},

/**
 * @method setZOrder
 * @param {int}
 */
setZOrder : function () {},

/**
 * @method setScaleY
 * @param {float}
 */
setScaleY : function () {},

/**
 * @method setScaleX
 * @param {float}
 */
setScaleX : function () {},

/**
 * @method getLayoutParameter
 * @return A value converted from C/C++ "gui::UILayoutParameter*"
 * @param {gui::LayoutParameterType}
 */
getLayoutParameter : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getColor : function () {},

/**
 * @method isBright
 * @return A value converted from C/C++ "bool"
 */
isBright : function () {},

/**
 * @method getTag
 * @return A value converted from C/C++ "int"
 */
getTag : function () {},

/**
 * @method addRenderer
 * @param {cocos2d::Node*}
 * @param {int}
 */
addRenderer : function () {},

/**
 * @method getSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getSize : function () {},

/**
 * @method getSizeType
 * @return A value converted from C/C++ "gui::SizeType"
 */
getSizeType : function () {},

/**
 * @method getPositionPercent
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getPositionPercent : function () {},

/**
 * @method removeChild
 * @return A value converted from C/C++ "bool"
 * @param {gui::UIWidget*}
 */
removeChild : function () {},

/**
 * @method convertToWorldSpace
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
convertToWorldSpace : function () {},

/**
 * @method setSize
 * @param {const cocos2d::Size&}
 */
setSize : function () {},

/**
 * @method removeAllChildren
 */
removeAllChildren : function () {},

/**
 * @method getRotationX
 * @return A value converted from C/C++ "float"
 */
getRotationX : function () {},

/**
 * @method getRotationY
 * @return A value converted from C/C++ "float"
 */
getRotationY : function () {},

/**
 * @method getSizePercent
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getSizePercent : function () {},

/**
 * @method setPositionType
 * @param {gui::PositionType}
 */
setPositionType : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method setParent
 * @param {gui::UIWidget*}
 */
setParent : function () {},

/**
 * @method getName
 * @return A value converted from C/C++ "const char*"
 */
getName : function () {},

/**
 * @method isTouchEnabled
 * @return A value converted from C/C++ "bool"
 */
isTouchEnabled : function () {},

/**
 * @method setTouchEnabled
 * @param {bool}
 */
setTouchEnabled : function () {},

/**
 * @method setLayoutParameter
 * @param {gui::UILayoutParameter*}
 */
setLayoutParameter : function () {},

/**
 * @method clippingParentAreaContainPoint
 * @return A value converted from C/C++ "bool"
 * @param {const cocos2d::Point&}
 */
clippingParentAreaContainPoint : function () {},

/**
 * @method setPosition
 * @param {const cocos2d::Point&}
 */
setPosition : function () {},

/**
 * @method removeRenderer
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeRenderer : function () {},

/**
 * @method stopActionByTag
 * @param {int}
 */
stopActionByTag : function () {},

/**
 * @method reorderChild
 * @param {gui::UIWidget*}
 */
reorderChild : function () {},

/**
 * @method getScale
 * @return A value converted from C/C++ "float"
 */
getScale : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method getAnchorPoint
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getAnchorPoint : function () {},

/**
 * @method isFocused
 * @return A value converted from C/C++ "bool"
 */
isFocused : function () {},

/**
 * @method isVisible
 * @return A value converted from C/C++ "bool"
 */
isVisible : function () {},

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method getLeftInParent
 * @return A value converted from C/C++ "float"
 */
getLeftInParent : function () {},

/**
 * @method setPositionPercent
 * @param {const cocos2d::Point&}
 */
setPositionPercent : function () {},

/**
 * @method getRotation
 * @return A value converted from C/C++ "float"
 */
getRotation : function () {},

/**
 * @method getBottomInParent
 * @return A value converted from C/C++ "float"
 */
getBottomInParent : function () {},

/**
 * @method ignoreContentAdaptWithSize
 * @param {bool}
 */
ignoreContentAdaptWithSize : function () {},

/**
 * @method getZOrder
 * @return A value converted from C/C++ "int"
 */
getZOrder : function () {},

/**
 * @method runAction
 * @return A value converted from C/C++ "cocos2d::Action*"
 * @param {cocos2d::Action*}
 */
runAction : function () {},

/**
 * @method stopAllActions
 */
stopAllActions : function () {},

/**
 * @method getActionTag
 * @return A value converted from C/C++ "int"
 */
getActionTag : function () {},

/**
 * @method getActionByTag
 * @return A value converted from C/C++ "cocos2d::Action*"
 * @param {int}
 */
getActionByTag : function () {},

/**
 * @method setRotationX
 * @param {float}
 */
setRotationX : function () {},

/**
 * @method setRotationY
 * @param {float}
 */
setRotationY : function () {},

/**
 * @method setBrightStyle
 * @param {gui::BrightStyle}
 */
setBrightStyle : function () {},

/**
 * @method setName
 * @param {const char*}
 */
setName : function () {},

/**
 * @method setFlipY
 * @param {bool}
 */
setFlipY : function () {},

/**
 * @method setFlipX
 * @param {bool}
 */
setFlipX : function () {},

/**
 * @method setUpdateEnabled
 * @param {bool}
 */
setUpdateEnabled : function () {},

/**
 * @method setRotation
 * @param {float}
 */
setRotation : function () {},

/**
 * @method setActionManager
 * @param {cocos2d::ActionManager*}
 */
setActionManager : function () {},

/**
 * @method getPosition
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getPosition : function () {},

/**
 * @method getParent
 * @return A value converted from C/C++ "gui::UIWidget*"
 */
getParent : function () {},

/**
 * @method hitTest
 * @return A value converted from C/C++ "bool"
 * @param {const cocos2d::Point&}
 */
hitTest : function () {},

/**
 * @method setVisible
 * @param {bool}
 */
setVisible : function () {},

/**
 * @method setSizePercent
 * @param {const cocos2d::Point&}
 */
setSizePercent : function () {},

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method setScale
 * @param {float}
 */
setScale : function () {},

/**
 * @method getTouchEndPos
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getTouchEndPos : function () {},

/**
 * @method getChildByTag
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {int}
 */
getChildByTag : function () {},

/**
 * @method isIgnoreContentAdaptWithSize
 * @return A value converted from C/C++ "bool"
 */
isIgnoreContentAdaptWithSize : function () {},

/**
 * @method isUpdateEnabled
 * @return A value converted from C/C++ "bool"
 */
isUpdateEnabled : function () {},

/**
 * @method updateSizeAndPosition
 */
updateSizeAndPosition : function () {},

/**
 * @method getRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getRenderer : function () {},

/**
 * @method getWidgetType
 * @return A value converted from C/C++ "gui::WidgetType"
 */
getWidgetType : function () {},

/**
 * @method getScaleY
 * @return A value converted from C/C++ "float"
 */
getScaleY : function () {},

/**
 * @method getScaleX
 * @return A value converted from C/C++ "float"
 */
getScaleX : function () {},

/**
 * @method setCascadeColorEnabled
 * @param {bool}
 */
setCascadeColorEnabled : function () {},

/**
 * @method setOpacity
 * @param {int}
 */
setOpacity : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "int"
 */
getOpacity : function () {},

/**
 * @method getTouchMovePos
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getTouchMovePos : function () {},

/**
 * @method removeFromParent
 */
removeFromParent : function () {},

/**
 * @method getWorldPosition
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getWorldPosition : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "gui::UIWidget*"
 */
clone : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method checkChildInfo
 * @param {int}
 * @param {gui::UIWidget*}
 * @param {const cocos2d::Point&}
 */
checkChildInfo : function () {},

/**
 * @method getTopInParent
 * @return A value converted from C/C++ "float"
 */
getTopInParent : function () {},

/**
 * @method getRightInParent
 * @return A value converted from C/C++ "float"
 */
getRightInParent : function () {},

/**
 * @method setTag
 * @param {int}
 */
setTag : function () {},

/**
 * @method getTouchStartPos
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getTouchStartPos : function () {},

/**
 * @method setSizeType
 * @param {gui::SizeType}
 */
setSizeType : function () {},

/**
 * @method stopAction
 * @param {cocos2d::Action*}
 */
stopAction : function () {},

/**
 * @method setBright
 * @param {bool}
 */
setBright : function () {},

/**
 * @method getActionManager
 * @return A value converted from C/C++ "cocos2d::ActionManager*"
 */
getActionManager : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIWidget*"
 */
create : function () {},

/**
 * @method UIWidget
 * @constructor
 */
UIWidget : function () {},

};

/**
 * @class UILayout
 */
ccs.UILayout = {

/**
 * @method setBackGroundColorVector
 * @param {const cocos2d::Point&}
 */
setBackGroundColorVector : function () {},

/**
 * @method isClippingEnabled
 * @return A value converted from C/C++ "bool"
 */
isClippingEnabled : function () {},

/**
 * @method getBackGroundImageTextureSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getBackGroundImageTextureSize : function () {},

/**
 * @method getLayoutType
 * @return A value converted from C/C++ "gui::LayoutType"
 */
getLayoutType : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method setBackGroundColorType
 * @param {gui::LayoutBackGroundColorType}
 */
setBackGroundColorType : function () {},

/**
 * @method setBackGroundImage
 * @param {const char*}
 * @param {gui::TextureResType}
 */
setBackGroundImage : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setOpacity
 * @param {int}
 */
setOpacity : function () {},

/**
 * @method hitTest
 * @return A value converted from C/C++ "bool"
 * @param {const cocos2d::Point&}
 */
hitTest : function () {},

/**
 * @method setBackGroundColorOpacity
 * @param {int}
 */
setBackGroundColorOpacity : function () {},

/**
 * @method setBackGroundImageCapInsets
 * @param {const cocos2d::Rect&}
 */
setBackGroundImageCapInsets : function () {},

/**
 * @method addChild
 * @return A value converted from C/C++ "bool"
 * @param {gui::UIWidget*}
 */
addChild : function () {},

/**
 * @method removeBackGroundImage
 */
removeBackGroundImage : function () {},

/**
 * @method setBackGroundImageScale9Enabled
 * @param {bool}
 */
setBackGroundImageScale9Enabled : function () {},

/**
 * @method doLayout
 */
doLayout : function () {},

/**
 * @method setClippingEnabled
 * @param {bool}
 */
setClippingEnabled : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method setLayoutType
 * @param {gui::LayoutType}
 */
setLayoutType : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILayout*"
 */
create : function () {},

/**
 * @method UILayout
 * @constructor
 */
UILayout : function () {},

};

/**
 * @class UIRootWidget
 */
ccs.UIRootWidget = {

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIRootWidget*"
 */
create : function () {},

/**
 * @method UIRootWidget
 * @constructor
 */
UIRootWidget : function () {},

};

/**
 * @class UIButton
 */
ccs.UIButton = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method getTitleText
 * @return A value converted from C/C++ "const std::string&"
 */
getTitleText : function () {},

/**
 * @method setTitleFontSize
 * @param {float}
 */
setTitleFontSize : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setScale9Enabled
 * @param {bool}
 */
setScale9Enabled : function () {},

/**
 * @method setTitleColor
 * @param {const cocos2d::Color3B&}
 */
setTitleColor : function () {},

/**
 * @method ignoreContentAdaptWithSize
 * @param {bool}
 */
ignoreContentAdaptWithSize : function () {},

/**
 * @method setCapInsetsDisabledRenderer
 * @param {const cocos2d::Rect&}
 */
setCapInsetsDisabledRenderer : function () {},

/**
 * @method isFlipX
 * @return A value converted from C/C++ "bool"
 */
isFlipX : function () {},

/**
 * @method isFlipY
 * @return A value converted from C/C++ "bool"
 */
isFlipY : function () {},

/**
 * @method loadTextureDisabled
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextureDisabled : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method setTitleText
 * @param {const std::string&}
 */
setTitleText : function () {},

/**
 * @method setCapInsetsNormalRenderer
 * @param {const cocos2d::Rect&}
 */
setCapInsetsNormalRenderer : function () {},

/**
 * @method loadTexturePressed
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTexturePressed : function () {},

/**
 * @method setFlipY
 * @param {bool}
 */
setFlipY : function () {},

/**
 * @method setFlipX
 * @param {bool}
 */
setFlipX : function () {},

/**
 * @method setTitleFontName
 * @param {const char*}
 */
setTitleFontName : function () {},

/**
 * @method loadTextures
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextures : function () {},

/**
 * @method getTitleColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getTitleColor : function () {},

/**
 * @method loadTextureNormal
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextureNormal : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method setCapInsetsPressedRenderer
 * @param {const cocos2d::Rect&}
 */
setCapInsetsPressedRenderer : function () {},

/**
 * @method getTitleFontSize
 * @return A value converted from C/C++ "float"
 */
getTitleFontSize : function () {},

/**
 * @method getTitleFontName
 * @return A value converted from C/C++ "const char*"
 */
getTitleFontName : function () {},

/**
 * @method setCapInsets
 * @param {const cocos2d::Rect&}
 */
setCapInsets : function () {},

/**
 * @method setPressedActionEnabled
 * @param {bool}
 */
setPressedActionEnabled : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIButton*"
 */
create : function () {},

/**
 * @method UIButton
 * @constructor
 */
UIButton : function () {},

};

/**
 * @class UICheckBox
 */
ccs.UICheckBox = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method getSelectedState
 * @return A value converted from C/C++ "bool"
 */
getSelectedState : function () {},

/**
 * @method loadTextureBackGroundSelected
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextureBackGroundSelected : function () {},

/**
 * @method loadTextureBackGroundDisabled
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextureBackGroundDisabled : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setFlipY
 * @param {bool}
 */
setFlipY : function () {},

/**
 * @method setFlipX
 * @param {bool}
 */
setFlipX : function () {},

/**
 * @method isFlipX
 * @return A value converted from C/C++ "bool"
 */
isFlipX : function () {},

/**
 * @method isFlipY
 * @return A value converted from C/C++ "bool"
 */
isFlipY : function () {},

/**
 * @method loadTextureFrontCross
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextureFrontCross : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method loadTextures
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextures : function () {},

/**
 * @method loadTextureBackGround
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextureBackGround : function () {},

/**
 * @method setSelectedState
 * @param {bool}
 */
setSelectedState : function () {},

/**
 * @method loadTextureFrontCrossDisabled
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTextureFrontCrossDisabled : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UICheckBox*"
 */
create : function () {},

/**
 * @method UICheckBox
 * @constructor
 */
UICheckBox : function () {},

};

/**
 * @class UIImageView
 */
ccs.UIImageView = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method ignoreContentAdaptWithSize
 * @param {bool}
 */
ignoreContentAdaptWithSize : function () {},

/**
 * @method loadTexture
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTexture : function () {},

/**
 * @method setDoubleClickEnabled
 * @param {bool}
 */
setDoubleClickEnabled : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setFlipY
 * @param {bool}
 */
setFlipY : function () {},

/**
 * @method setFlipX
 * @param {bool}
 */
setFlipX : function () {},

/**
 * @method isFlipX
 * @return A value converted from C/C++ "bool"
 */
isFlipX : function () {},

/**
 * @method isFlipY
 * @return A value converted from C/C++ "bool"
 */
isFlipY : function () {},

/**
 * @method setScale9Enabled
 * @param {bool}
 */
setScale9Enabled : function () {},

/**
 * @method setTextureRect
 * @param {const cocos2d::Rect&}
 */
setTextureRect : function () {},

/**
 * @method setCapInsets
 * @param {const cocos2d::Rect&}
 */
setCapInsets : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method checkDoubleClick
 * @param {float}
 */
checkDoubleClick : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIImageView*"
 */
create : function () {},

/**
 * @method UIImageView
 * @constructor
 */
UIImageView : function () {},

};

/**
 * @class UILabel
 */
ccs.UILabel = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method getStringValue
 * @return A value converted from C/C++ "const std::string&"
 */
getStringValue : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setScale
 * @param {float}
 */
setScale : function () {},

/**
 * @method setTextVerticalAlignment
 * @param {cocos2d::TextVAlignment}
 */
setTextVerticalAlignment : function () {},

/**
 * @method setFontName
 * @param {const std::string&}
 */
setFontName : function () {},

/**
 * @method setTouchScaleChangeEnabled
 * @param {bool}
 */
setTouchScaleChangeEnabled : function () {},

/**
 * @method isFlipX
 * @return A value converted from C/C++ "bool"
 */
isFlipX : function () {},

/**
 * @method isFlipY
 * @return A value converted from C/C++ "bool"
 */
isFlipY : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method isTouchScaleChangeEnabled
 * @return A value converted from C/C++ "bool"
 */
isTouchScaleChangeEnabled : function () {},

/**
 * @method setTextAreaSize
 * @param {const cocos2d::Size&}
 */
setTextAreaSize : function () {},

/**
 * @method getStringLength
 * @return A value converted from C/C++ "int"
 */
getStringLength : function () {},

/**
 * @method setScaleY
 * @param {float}
 */
setScaleY : function () {},

/**
 * @method setScaleX
 * @param {float}
 */
setScaleX : function () {},

/**
 * @method setFlipY
 * @param {bool}
 */
setFlipY : function () {},

/**
 * @method setFlipX
 * @param {bool}
 */
setFlipX : function () {},

/**
 * @method setFontSize
 * @param {int}
 */
setFontSize : function () {},

/**
 * @method setText
 * @param {const std::string&}
 */
setText : function () {},

/**
 * @method setTextHorizontalAlignment
 * @param {cocos2d::TextHAlignment}
 */
setTextHorizontalAlignment : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILabel*"
 */
create : function () {},

/**
 * @method UILabel
 * @constructor
 */
UILabel : function () {},

};

/**
 * @class UICCLabelAtlas
 */
ccs.UICCLabelAtlas = {

/**
 * @method updateDisplayedOpacity
 * @param {GLubyte}
 */
updateDisplayedOpacity : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UICCLabelAtlas*"
 */
create : function () {},

/**
 * @method UICCLabelAtlas
 * @constructor
 */
UICCLabelAtlas : function () {},

};

/**
 * @class UILabelAtlas
 */
ccs.UILabelAtlas = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method getStringValue
 * @return A value converted from C/C++ "const std::string&"
 */
getStringValue : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method setProperty
 * @param {const std::string&}
 * @param {const std::string&}
 * @param {int}
 * @param {int}
 * @param {const std::string&}
 */
setProperty : function () {},

/**
 * @method setStringValue
 * @param {const std::string&}
 */
setStringValue : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILabelAtlas*"
 */
create : function () {},

/**
 * @method UILabelAtlas
 * @constructor
 */
UILabelAtlas : function () {},

};

/**
 * @class UILoadingBar
 */
ccs.UILoadingBar = {

/**
 * @method setPercent
 * @param {int}
 */
setPercent : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method ignoreContentAdaptWithSize
 * @param {bool}
 */
ignoreContentAdaptWithSize : function () {},

/**
 * @method loadTexture
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadTexture : function () {},

/**
 * @method setDirection
 * @param {gui::LoadingBarType}
 */
setDirection : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setScale9Enabled
 * @param {bool}
 */
setScale9Enabled : function () {},

/**
 * @method setCapInsets
 * @param {const cocos2d::Rect&}
 */
setCapInsets : function () {},

/**
 * @method getDirection
 * @return A value converted from C/C++ "int"
 */
getDirection : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method getPercent
 * @return A value converted from C/C++ "int"
 */
getPercent : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILoadingBar*"
 */
create : function () {},

/**
 * @method UILoadingBar
 * @constructor
 */
UILoadingBar : function () {},

};

/**
 * @class UIScrollView
 */
ccs.UIScrollView = {

/**
 * @method addChild
 * @return A value converted from C/C++ "bool"
 * @param {gui::UIWidget*}
 */
addChild : function () {},

/**
 * @method scrollToTop
 * @param {float}
 * @param {bool}
 */
scrollToTop : function () {},

/**
 * @method scrollToPercentHorizontal
 * @param {float}
 * @param {float}
 * @param {bool}
 */
scrollToPercentHorizontal : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method removeAllChildren
 */
removeAllChildren : function () {},

/**
 * @method scrollToPercentBothDirection
 * @param {const cocos2d::Point&}
 * @param {float}
 * @param {bool}
 */
scrollToPercentBothDirection : function () {},

/**
 * @method getChildren
 * @return A value converted from C/C++ "cocos2d::Array*"
 */
getChildren : function () {},

/**
 * @method getDirection
 * @return A value converted from C/C++ "gui::SCROLLVIEW_DIR"
 */
getDirection : function () {},

/**
 * @method scrollToBottomLeft
 * @param {float}
 * @param {bool}
 */
scrollToBottomLeft : function () {},

/**
 * @method getInnerContainer
 * @return A value converted from C/C++ "gui::UILayout*"
 */
getInnerContainer : function () {},

/**
 * @method jumpToBottom
 */
jumpToBottom : function () {},

/**
 * @method setDirection
 * @param {gui::SCROLLVIEW_DIR}
 */
setDirection : function () {},

/**
 * @method scrollToTopLeft
 * @param {float}
 * @param {bool}
 */
scrollToTopLeft : function () {},

/**
 * @method jumpToTopRight
 */
jumpToTopRight : function () {},

/**
 * @method jumpToBottomLeft
 */
jumpToBottomLeft : function () {},

/**
 * @method setInnerContainerSize
 * @param {const cocos2d::Size&}
 */
setInnerContainerSize : function () {},

/**
 * @method isInertiaScrollEnabled
 * @return A value converted from C/C++ "bool"
 */
isInertiaScrollEnabled : function () {},

/**
 * @method getInnerContainerSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getInnerContainerSize : function () {},

/**
 * @method isBounceEnabled
 * @return A value converted from C/C++ "bool"
 */
isBounceEnabled : function () {},

/**
 * @method jumpToPercentVertical
 * @param {float}
 */
jumpToPercentVertical : function () {},

/**
 * @method doLayout
 */
doLayout : function () {},

/**
 * @method setInertiaScrollEnabled
 * @param {bool}
 */
setInertiaScrollEnabled : function () {},

/**
 * @method jumpToTopLeft
 */
jumpToTopLeft : function () {},

/**
 * @method jumpToPercentHorizontal
 * @param {float}
 */
jumpToPercentHorizontal : function () {},

/**
 * @method jumpToBottomRight
 */
jumpToBottomRight : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getLayoutType
 * @return A value converted from C/C++ "gui::LayoutType"
 */
getLayoutType : function () {},

/**
 * @method setBounceEnabled
 * @param {bool}
 */
setBounceEnabled : function () {},

/**
 * @method jumpToTop
 */
jumpToTop : function () {},

/**
 * @method scrollToLeft
 * @param {float}
 * @param {bool}
 */
scrollToLeft : function () {},

/**
 * @method jumpToPercentBothDirection
 * @param {const cocos2d::Point&}
 */
jumpToPercentBothDirection : function () {},

/**
 * @method scrollToPercentVertical
 * @param {float}
 * @param {float}
 * @param {bool}
 */
scrollToPercentVertical : function () {},

/**
 * @method scrollToBottom
 * @param {float}
 * @param {bool}
 */
scrollToBottom : function () {},

/**
 * @method scrollToBottomRight
 * @param {float}
 * @param {bool}
 */
scrollToBottomRight : function () {},

/**
 * @method jumpToLeft
 */
jumpToLeft : function () {},

/**
 * @method scrollToRight
 * @param {float}
 * @param {bool}
 */
scrollToRight : function () {},

/**
 * @method removeChild
 * @return A value converted from C/C++ "bool"
 * @param {gui::UIWidget*}
 */
removeChild : function () {},

/**
 * @method setLayoutType
 * @param {gui::LayoutType}
 */
setLayoutType : function () {},

/**
 * @method jumpToRight
 */
jumpToRight : function () {},

/**
 * @method scrollToTopRight
 * @param {float}
 * @param {bool}
 */
scrollToTopRight : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIScrollView*"
 */
create : function () {},

/**
 * @method UIScrollView
 * @constructor
 */
UIScrollView : function () {},

};

/**
 * @class UIListView
 */
ccs.UIListView = {

/**
 * @method getIndex
 * @return A value converted from C/C++ "unsigned int"
 * @param {gui::UIWidget*}
 */
getIndex : function () {},

/**
 * @method setGravity
 * @param {gui::ListViewGravity}
 */
setGravity : function () {},

/**
 * @method pushBackCustomItem
 * @param {gui::UIWidget*}
 */
pushBackCustomItem : function () {},

/**
 * @method setDirection
 * @param {gui::SCROLLVIEW_DIR}
 */
setDirection : function () {},

/**
 * @method getItems
 * @return A value converted from C/C++ "cocos2d::Array*"
 */
getItems : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method removeItem
 * @param {int}
 */
removeItem : function () {},

/**
 * @method getCurSelectedIndex
 * @return A value converted from C/C++ "int"
 */
getCurSelectedIndex : function () {},

/**
 * @method insertDefaultItem
 * @param {int}
 */
insertDefaultItem : function () {},

/**
 * @method setItemsMargin
 * @param {float}
 */
setItemsMargin : function () {},

/**
 * @method refreshView
 */
refreshView : function () {},

/**
 * @method removeLastItem
 */
removeLastItem : function () {},

/**
 * @method getItem
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {unsigned int}
 */
getItem : function () {},

/**
 * @method setItemModel
 * @param {gui::UIWidget*}
 */
setItemModel : function () {},

/**
 * @method pushBackDefaultItem
 */
pushBackDefaultItem : function () {},

/**
 * @method insertCustomItem
 * @param {gui::UIWidget*}
 * @param {int}
 */
insertCustomItem : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIListView*"
 */
create : function () {},

/**
 * @method UIListView
 * @constructor
 */
UIListView : function () {},

};

/**
 * @class UISlider
 */
ccs.UISlider = {

/**
 * @method setPercent
 * @param {int}
 */
setPercent : function () {},

/**
 * @method loadSlidBallTextureNormal
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadSlidBallTextureNormal : function () {},

/**
 * @method loadBarTexture
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadBarTexture : function () {},

/**
 * @method loadProgressBarTexture
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadProgressBarTexture : function () {},

/**
 * @method loadSlidBallTextures
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadSlidBallTextures : function () {},

/**
 * @method setCapInsetProgressBarRebderer
 * @param {const cocos2d::Rect&}
 */
setCapInsetProgressBarRebderer : function () {},

/**
 * @method setCapInsetsBarRenderer
 * @param {const cocos2d::Rect&}
 */
setCapInsetsBarRenderer : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method setScale9Enabled
 * @param {bool}
 */
setScale9Enabled : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method setCapInsets
 * @param {const cocos2d::Rect&}
 */
setCapInsets : function () {},

/**
 * @method ignoreContentAdaptWithSize
 * @param {bool}
 */
ignoreContentAdaptWithSize : function () {},

/**
 * @method loadSlidBallTexturePressed
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadSlidBallTexturePressed : function () {},

/**
 * @method loadSlidBallTextureDisabled
 * @param {const char*}
 * @param {gui::TextureResType}
 */
loadSlidBallTextureDisabled : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method getPercent
 * @return A value converted from C/C++ "int"
 */
getPercent : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UISlider*"
 */
create : function () {},

/**
 * @method UISlider
 * @constructor
 */
UISlider : function () {},

};

/**
 * @class UICCTextField
 */
ccs.UICCTextField = {

/**
 * @method onTextFieldAttachWithIME
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::TextFieldTTF*}
 */
onTextFieldAttachWithIME : function () {},

/**
 * @method setPasswordText
 * @param {const char*}
 */
setPasswordText : function () {},

/**
 * @method setAttachWithIME
 * @param {bool}
 */
setAttachWithIME : function () {},

/**
 * @method getDeleteBackward
 * @return A value converted from C/C++ "bool"
 */
getDeleteBackward : function () {},

/**
 * @method getAttachWithIME
 * @return A value converted from C/C++ "bool"
 */
getAttachWithIME : function () {},

/**
 * @method onTextFieldDeleteBackward
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::TextFieldTTF*}
 * @param {const char*}
 * @param {int}
 */
onTextFieldDeleteBackward : function () {},

/**
 * @method getInsertText
 * @return A value converted from C/C++ "bool"
 */
getInsertText : function () {},

/**
 * @method deleteBackward
 */
deleteBackward : function () {},

/**
 * @method setInsertText
 * @param {bool}
 */
setInsertText : function () {},

/**
 * @method getDetachWithIME
 * @return A value converted from C/C++ "bool"
 */
getDetachWithIME : function () {},

/**
 * @method getCharCount
 * @return A value converted from C/C++ "int"
 */
getCharCount : function () {},

/**
 * @method closeIME
 */
closeIME : function () {},

/**
 * @method setPasswordEnabled
 * @param {bool}
 */
setPasswordEnabled : function () {},

/**
 * @method setMaxLengthEnabled
 * @param {bool}
 */
setMaxLengthEnabled : function () {},

/**
 * @method isPasswordEnabled
 * @return A value converted from C/C++ "bool"
 */
isPasswordEnabled : function () {},

/**
 * @method insertText
 * @param {const char*}
 * @param {int}
 */
insertText : function () {},

/**
 * @method setPasswordStyleText
 * @param {const char*}
 */
setPasswordStyleText : function () {},

/**
 * @method onTextFieldInsertText
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::TextFieldTTF*}
 * @param {const char*}
 * @param {int}
 */
onTextFieldInsertText : function () {},

/**
 * @method onTextFieldDetachWithIME
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::TextFieldTTF*}
 */
onTextFieldDetachWithIME : function () {},

/**
 * @method getMaxLength
 * @return A value converted from C/C++ "int"
 */
getMaxLength : function () {},

/**
 * @method isMaxLengthEnabled
 * @return A value converted from C/C++ "bool"
 */
isMaxLengthEnabled : function () {},

/**
 * @method openIME
 */
openIME : function () {},

/**
 * @method setDetachWithIME
 * @param {bool}
 */
setDetachWithIME : function () {},

/**
 * @method setMaxLength
 * @param {int}
 */
setMaxLength : function () {},

/**
 * @method setDeleteBackward
 * @param {bool}
 */
setDeleteBackward : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UICCTextField*"
 * @param {const char*}
 * @param {const char*}
 * @param {float}
 */
create : function () {},

/**
 * @method UICCTextField
 * @constructor
 */
UICCTextField : function () {},

};

/**
 * @class UITextField
 */
ccs.UITextField = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method setAttachWithIME
 * @param {bool}
 */
setAttachWithIME : function () {},

/**
 * @method getStringValue
 * @return A value converted from C/C++ "const std::string&"
 */
getStringValue : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method getDeleteBackward
 * @return A value converted from C/C++ "bool"
 */
getDeleteBackward : function () {},

/**
 * @method getAttachWithIME
 * @return A value converted from C/C++ "bool"
 */
getAttachWithIME : function () {},

/**
 * @method setFontName
 * @param {const std::string&}
 */
setFontName : function () {},

/**
 * @method getInsertText
 * @return A value converted from C/C++ "bool"
 */
getInsertText : function () {},

/**
 * @method initRenderer
 */
initRenderer : function () {},

/**
 * @method getDetachWithIME
 * @return A value converted from C/C++ "bool"
 */
getDetachWithIME : function () {},

/**
 * @method setOpacity
 * @param {int}
 */
setOpacity : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method didNotSelectSelf
 */
didNotSelectSelf : function () {},

/**
 * @method isPasswordEnabled
 * @return A value converted from C/C++ "bool"
 */
isPasswordEnabled : function () {},

/**
 * @method attachWithIME
 */
attachWithIME : function () {},

/**
 * @method setPasswordEnabled
 * @param {bool}
 */
setPasswordEnabled : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method setMaxLengthEnabled
 * @param {bool}
 */
setMaxLengthEnabled : function () {},

/**
 * @method setPasswordStyleText
 * @param {const char*}
 */
setPasswordStyleText : function () {},

/**
 * @method setFontSize
 * @param {int}
 */
setFontSize : function () {},

/**
 * @method setPlaceHolder
 * @param {const std::string&}
 */
setPlaceHolder : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method getMaxLength
 * @return A value converted from C/C++ "int"
 */
getMaxLength : function () {},

/**
 * @method isMaxLengthEnabled
 * @return A value converted from C/C++ "bool"
 */
isMaxLengthEnabled : function () {},

/**
 * @method setDetachWithIME
 * @param {bool}
 */
setDetachWithIME : function () {},

/**
 * @method setText
 * @param {const std::string&}
 */
setText : function () {},

/**
 * @method setInsertText
 * @param {bool}
 */
setInsertText : function () {},

/**
 * @method setMaxLength
 * @param {int}
 */
setMaxLength : function () {},

/**
 * @method setTouchSize
 * @param {const cocos2d::Size&}
 */
setTouchSize : function () {},

/**
 * @method setDeleteBackward
 * @param {bool}
 */
setDeleteBackward : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UITextField*"
 */
create : function () {},

/**
 * @method UITextField
 * @constructor
 */
UITextField : function () {},

};

/**
 * @class UILabelBMFont
 */
ccs.UILabelBMFont = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method getVirtualRenderer
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getVirtualRenderer : function () {},

/**
 * @method getStringValue
 * @return A value converted from C/C++ "const char*"
 */
getStringValue : function () {},

/**
 * @method setText
 * @param {const char*}
 */
setText : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method setFntFile
 * @param {const char*}
 */
setFntFile : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILabelBMFont*"
 */
create : function () {},

/**
 * @method UILabelBMFont
 * @constructor
 */
UILabelBMFont : function () {},

};

/**
 * @class UIPageView
 */
ccs.UIPageView = {

/**
 * @method getLayoutType
 * @return A value converted from C/C++ "gui::LayoutType"
 */
getLayoutType : function () {},

/**
 * @method getCurPageIndex
 * @return A value converted from C/C++ "int"
 */
getCurPageIndex : function () {},

/**
 * @method addWidgetToPage
 * @param {gui::UIWidget*}
 * @param {int}
 * @param {bool}
 */
addWidgetToPage : function () {},

/**
 * @method getPage
 * @return A value converted from C/C++ "gui::UILayout*"
 * @param {int}
 */
getPage : function () {},

/**
 * @method removePage
 * @param {gui::UILayout*}
 */
removePage : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "const char*"
 */
getDescription : function () {},

/**
 * @method insertPage
 * @param {gui::UILayout*}
 * @param {int}
 */
insertPage : function () {},

/**
 * @method setLayoutType
 * @param {gui::LayoutType}
 */
setLayoutType : function () {},

/**
 * @method scrollToPage
 * @param {int}
 */
scrollToPage : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method doLayout
 */
doLayout : function () {},

/**
 * @method removePageAtIndex
 * @param {int}
 */
removePageAtIndex : function () {},

/**
 * @method getPages
 * @return A value converted from C/C++ "cocos2d::Array*"
 */
getPages : function () {},

/**
 * @method removeAllPages
 */
removeAllPages : function () {},

/**
 * @method addPage
 * @param {gui::UILayout*}
 */
addPage : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UIPageView*"
 */
create : function () {},

/**
 * @method UIPageView
 * @constructor
 */
UIPageView : function () {},

};

/**
 * @class UIHelper
 */
ccs.UIHelper = {

/**
 * @method seekActionWidgetByActionTag
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {gui::UIWidget*}
 * @param {int}
 */
seekActionWidgetByActionTag : function () {},

/**
 * @method seekWidgetByTag
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {gui::UIWidget*}
 * @param {int}
 */
seekWidgetByTag : function () {},

/**
 * @method seekWidgetByRelativeName
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {gui::UIWidget*}
 * @param {const char*}
 */
seekWidgetByRelativeName : function () {},

/**
 * @method seekWidgetByName
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {gui::UIWidget*}
 * @param {const char*}
 */
seekWidgetByName : function () {},

};

/**
 * @class UILayer
 */
ccs.UILayer = {

/**
 * @method getRootWidget
 * @return A value converted from C/C++ "gui::UIRootWidget*"
 */
getRootWidget : function () {},

/**
 * @method getWidgetByTag
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {int}
 */
getWidgetByTag : function () {},

/**
 * @method removeWidget
 * @param {gui::UIWidget*}
 */
removeWidget : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getWidgetByName
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {const char*}
 */
getWidgetByName : function () {},

/**
 * @method addWidget
 * @param {gui::UIWidget*}
 */
addWidget : function () {},

/**
 * @method setVisible
 * @param {bool}
 */
setVisible : function () {},

/**
 * @method clear
 */
clear : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "gui::UILayer*"
 */
create : function () {},

/**
 * @method UILayer
 * @constructor
 */
UILayer : function () {},

};

/**
 * @class ActionManagerEx
 */
ccs.ActionManagerEx = {

/**
 * @method playActionByName
 * @return A value converted from C/C++ "cocostudio::ActionObject*"
 * @param {const char*}
 * @param {const char*}
 */
playActionByName : function () {},

/**
 * @method getActionByName
 * @return A value converted from C/C++ "cocostudio::ActionObject*"
 * @param {const char*}
 * @param {const char*}
 */
getActionByName : function () {},

/**
 * @method initWithDictionary
 * @param {const char*}
 * @param {cocostudio::JsonDictionary*}
 * @param {cocos2d::Object*}
 */
initWithDictionary : function () {},

/**
 * @method releaseActions
 */
releaseActions : function () {},

/**
 * @method purgeActionManager
 */
purgeActionManager : function () {},

/**
 * @method shareManager
 * @return A value converted from C/C++ "cocostudio::ActionManagerEx*"
 */
shareManager : function () {},

/**
 * @method ActionManagerEx
 * @constructor
 */
ActionManagerEx : function () {},

};

/**
 * @class BaseData
 */
ccs.BaseData = {

/**
 * @method getColor
 * @return A value converted from C/C++ "cocos2d::Color4B"
 */
getColor : function () {},

/**
 * @method copy
 * @param {const cocostudio::BaseData*}
 */
copy : function () {},

/**
 * @method subtract
 * @param {cocostudio::BaseData*}
 * @param {cocostudio::BaseData*}
 * @param {bool}
 */
subtract : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color4B&}
 */
setColor : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::BaseData*"
 */
create : function () {},

/**
 * @method BaseData
 * @constructor
 */
BaseData : function () {},

};

/**
 * @class DisplayData
 */
ccs.DisplayData = {

/**
 * @method copy
 * @param {cocostudio::DisplayData*}
 */
copy : function () {},

/**
 * @method changeDisplayToTexture
 * @return A value converted from C/C++ "const char*"
 * @param {const char*}
 */
changeDisplayToTexture : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::DisplayData*"
 */
create : function () {},

/**
 * @method DisplayData
 * @constructor
 */
DisplayData : function () {},

};

/**
 * @class SpriteDisplayData
 */
ccs.SpriteDisplayData = {

/**
 * @method copy
 * @param {cocostudio::DisplayData*}
 */
copy : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::SpriteDisplayData*"
 */
create : function () {},

/**
 * @method SpriteDisplayData
 * @constructor
 */
SpriteDisplayData : function () {},

};

/**
 * @class ArmatureDisplayData
 */
ccs.ArmatureDisplayData = {

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ArmatureDisplayData*"
 */
create : function () {},

/**
 * @method ArmatureDisplayData
 * @constructor
 */
ArmatureDisplayData : function () {},

};

/**
 * @class ParticleDisplayData
 */
ccs.ParticleDisplayData = {

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ParticleDisplayData*"
 */
create : function () {},

/**
 * @method ParticleDisplayData
 * @constructor
 */
ParticleDisplayData : function () {},

};

/**
 * @class BoneData
 */
ccs.BoneData = {

/**
 * @method getDisplayData
 * @return A value converted from C/C++ "cocostudio::DisplayData*"
 * @param {int}
 */
getDisplayData : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method addDisplayData
 * @param {cocostudio::DisplayData*}
 */
addDisplayData : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::BoneData*"
 */
create : function () {},

/**
 * @method BoneData
 * @constructor
 */
BoneData : function () {},

};

/**
 * @class ArmatureData
 */
ccs.ArmatureData = {

/**
 * @method addBoneData
 * @param {cocostudio::BoneData*}
 */
addBoneData : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getBoneData
 * @return A value converted from C/C++ "cocostudio::BoneData*"
 * @param {const char*}
 */
getBoneData : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ArmatureData*"
 */
create : function () {},

/**
 * @method ArmatureData
 * @constructor
 */
ArmatureData : function () {},

};

/**
 * @class FrameData
 */
ccs.FrameData = {

/**
 * @method copy
 * @param {const cocostudio::BaseData*}
 */
copy : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::FrameData*"
 */
create : function () {},

/**
 * @method FrameData
 * @constructor
 */
FrameData : function () {},

};

/**
 * @class MovementBoneData
 */
ccs.MovementBoneData = {

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method getFrameData
 * @return A value converted from C/C++ "cocostudio::FrameData*"
 * @param {int}
 */
getFrameData : function () {},

/**
 * @method addFrameData
 * @param {cocostudio::FrameData*}
 */
addFrameData : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::MovementBoneData*"
 */
create : function () {},

/**
 * @method MovementBoneData
 * @constructor
 */
MovementBoneData : function () {},

};

/**
 * @class MovementData
 */
ccs.MovementData = {

/**
 * @method getMovementBoneData
 * @return A value converted from C/C++ "cocostudio::MovementBoneData*"
 * @param {const char*}
 */
getMovementBoneData : function () {},

/**
 * @method addMovementBoneData
 * @param {cocostudio::MovementBoneData*}
 */
addMovementBoneData : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::MovementData*"
 */
create : function () {},

/**
 * @method MovementData
 * @constructor
 */
MovementData : function () {},

};

/**
 * @class AnimationData
 */
ccs.AnimationData = {

/**
 * @method getMovement
 * @return A value converted from C/C++ "cocostudio::MovementData*"
 * @param {const char*}
 */
getMovement : function () {},

/**
 * @method getMovementCount
 * @return A value converted from C/C++ "ssize_t"
 */
getMovementCount : function () {},

/**
 * @method addMovement
 * @param {cocostudio::MovementData*}
 */
addMovement : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::AnimationData*"
 */
create : function () {},

/**
 * @method AnimationData
 * @constructor
 */
AnimationData : function () {},

};

/**
 * @class ContourData
 */
ccs.ContourData = {

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method addVertex
 * @param {cocos2d::Point&}
 */
addVertex : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ContourData*"
 */
create : function () {},

/**
 * @method ContourData
 * @constructor
 */
ContourData : function () {},

};

/**
 * @class TextureData
 */
ccs.TextureData = {

/**
 * @method getContourData
 * @return A value converted from C/C++ "cocostudio::ContourData*"
 * @param {int}
 */
getContourData : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method addContourData
 * @param {cocostudio::ContourData*}
 */
addContourData : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::TextureData*"
 */
create : function () {},

/**
 * @method TextureData
 * @constructor
 */
TextureData : function () {},

};

/**
 * @class Bone
 */
ccs.Bone = {

/**
 * @method getTweenData
 * @return A value converted from C/C++ "cocostudio::FrameData*"
 */
getTweenData : function () {},

/**
 * @method isTransformDirty
 * @return A value converted from C/C++ "bool"
 */
isTransformDirty : function () {},

/**
 * @method isIgnoreMovementBoneData
 * @return A value converted from C/C++ "bool"
 */
isIgnoreMovementBoneData : function () {},

/**
 * @method updateZOrder
 */
updateZOrder : function () {},

/**
 * @method setTransformDirty
 * @param {bool}
 */
setTransformDirty : function () {},

/**
 * @method getDisplayRenderNode
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getDisplayRenderNode : function () {},

/**
 * @method isBlendDirty
 * @return A value converted from C/C++ "bool"
 */
isBlendDirty : function () {},

/**
 * @method addChildBone
 * @param {cocostudio::Bone*}
 */
addChildBone : function () {},

/**
 * @method getWorldInfo
 * @return A value converted from C/C++ "cocostudio::BaseData*"
 */
getWorldInfo : function () {},

/**
 * @method getTween
 * @return A value converted from C/C++ "cocostudio::Tween*"
 */
getTween : function () {},

/**
 * @method getParentBone
 * @return A value converted from C/C++ "cocostudio::Bone*"
 */
getParentBone : function () {},

/**
 * @method updateColor
 */
updateColor : function () {},

/**
 * @method getName
 * @return A value converted from C/C++ "const std::string"
 */
getName : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method getDisplayRenderNodeType
 * @return A value converted from C/C++ "cocostudio::DisplayType"
 */
getDisplayRenderNodeType : function () {},

/**
 * @method removeDisplay
 * @param {int}
 */
removeDisplay : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {GLubyte}
 */
updateDisplayedOpacity : function () {},

/**
 * @method changeDisplayByName
 * @param {const char*}
 * @param {bool}
 */
changeDisplayByName : function () {},

/**
 * @method setZOrder
 * @param {int}
 */
setZOrder : function () {},

/**
 * @method setName
 * @param {const std::string&}
 */
setName : function () {},

/**
 * @method removeFromParent
 * @param {bool}
 */
removeFromParent : function () {},

/**
 * @method getColliderDetector
 * @return A value converted from C/C++ "cocostudio::ColliderDetector*"
 */
getColliderDetector : function () {},

/**
 * @method setParentBone
 * @param {cocostudio::Bone*}
 */
setParentBone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getChildArmature
 * @return A value converted from C/C++ "cocostudio::Armature*"
 */
getChildArmature : function () {},

/**
 * @method setBoneData
 * @param {cocostudio::BoneData*}
 */
setBoneData : function () {},

/**
 * @method setArmature
 * @param {cocostudio::Armature*}
 */
setArmature : function () {},

/**
 * @method setBlendDirty
 * @param {bool}
 */
setBlendDirty : function () {},

/**
 * @method getNodeToWorldTransform
 * @return A value converted from C/C++ "kmMat4"
 */
getNodeToWorldTransform : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method removeChildBone
 * @param {cocostudio::Bone*}
 * @param {bool}
 */
removeChildBone : function () {},

/**
 * @method setChildArmature
 * @param {cocostudio::Armature*}
 */
setChildArmature : function () {},

/**
 * @method getNodeToArmatureTransform
 * @return A value converted from C/C++ "kmMat4"
 */
getNodeToArmatureTransform : function () {},

/**
 * @method getDisplayManager
 * @return A value converted from C/C++ "cocostudio::DisplayManager*"
 */
getDisplayManager : function () {},

/**
 * @method getArmature
 * @return A value converted from C/C++ "cocostudio::Armature*"
 */
getArmature : function () {},

/**
 * @method changeDisplayByIndex
 * @param {int}
 * @param {bool}
 */
changeDisplayByIndex : function () {},

/**
 * @method updateDisplayedColor
 * @param {const cocos2d::Color3B&}
 */
updateDisplayedColor : function () {},

/**
 * @method getBoneData
 * @return A value converted from C/C++ "cocostudio::BoneData*"
 */
getBoneData : function () {},

/**
 * @method Bone
 * @constructor
 */
Bone : function () {},

};

/**
 * @class BatchNode
 */
ccs.BatchNode = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method setPopGroupCommand
 * @param {bool}
 */
setPopGroupCommand : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::BatchNode*"
 */
create : function () {},

/**
 * @method BatchNode
 * @constructor
 */
BatchNode : function () {},

};

/**
 * @class ArmatureAnimation
 */
ccs.ArmatureAnimation = {

/**
 * @method getSpeedScale
 * @return A value converted from C/C++ "float"
 */
getSpeedScale : function () {},

/**
 * @method pause
 */
pause : function () {},

/**
 * @method gotoAndPause
 * @param {int}
 */
gotoAndPause : function () {},

/**
 * @method resume
 */
resume : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method setAnimationData
 * @param {cocostudio::AnimationData*}
 */
setAnimationData : function () {},

/**
 * @method setMovementEventCallFunc
 * @param {std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const char *)>}
 */
setMovementEventCallFunc : function () {},

/**
 * @method setSpeedScale
 * @param {float}
 */
setSpeedScale : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAnimationData
 * @return A value converted from C/C++ "cocostudio::AnimationData*"
 */
getAnimationData : function () {},

/**
 * @method gotoAndPlay
 * @param {int}
 */
gotoAndPlay : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 * @param {cocostudio::Armature*}
 */
init : function () {},

/**
 * @method getMovementCount
 * @return A value converted from C/C++ "long"
 */
getMovementCount : function () {},

/**
 * @method setFrameEventCallFunc
 * @param {std::function<void (cocostudio::Bone *, const char *, int, int)>}
 */
setFrameEventCallFunc : function () {},

/**
 * @method getCurrentMovementID
 * @return A value converted from C/C++ "std::string"
 */
getCurrentMovementID : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ArmatureAnimation*"
 * @param {cocostudio::Armature*}
 */
create : function () {},

/**
 * @method ArmatureAnimation
 * @constructor
 */
ArmatureAnimation : function () {},

};

/**
 * @class ArmatureDataManager
 */
ccs.ArmatureDataManager = {

/**
 * @method getAnimationDatas
 * @return A value converted from C/C++ "const cocos2d::Map<std::basic_string<char>, cocostudio::AnimationData *>&"
 */
getAnimationDatas : function () {},

/**
 * @method removeAnimationData
 * @param {const char*}
 */
removeAnimationData : function () {},

/**
 * @method addArmatureData
 * @param {const char*}
 * @param {cocostudio::ArmatureData*}
 * @param {const char*}
 */
addArmatureData : function () {},

/**
 * @method removeArmatureFileInfo
 * @param {const char*}
 */
removeArmatureFileInfo : function () {},

/**
 * @method getTextureDatas
 * @return A value converted from C/C++ "const cocos2d::Map<std::basic_string<char>, cocostudio::TextureData *>&"
 */
getTextureDatas : function () {},

/**
 * @method getTextureData
 * @return A value converted from C/C++ "cocostudio::TextureData*"
 * @param {const char*}
 */
getTextureData : function () {},

/**
 * @method getArmatureData
 * @return A value converted from C/C++ "cocostudio::ArmatureData*"
 * @param {const char*}
 */
getArmatureData : function () {},

/**
 * @method getAnimationData
 * @return A value converted from C/C++ "cocostudio::AnimationData*"
 * @param {const char*}
 */
getAnimationData : function () {},

/**
 * @method addAnimationData
 * @param {const char*}
 * @param {cocostudio::AnimationData*}
 * @param {const char*}
 */
addAnimationData : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method removeArmatureData
 * @param {const char*}
 */
removeArmatureData : function () {},

/**
 * @method getArmatureDatas
 * @return A value converted from C/C++ "const cocos2d::Map<std::basic_string<char>, cocostudio::ArmatureData *>&"
 */
getArmatureDatas : function () {},

/**
 * @method removeTextureData
 * @param {const char*}
 */
removeTextureData : function () {},

/**
 * @method addTextureData
 * @param {const char*}
 * @param {cocostudio::TextureData*}
 * @param {const char*}
 */
addTextureData : function () {},

/**
 * @method isAutoLoadSpriteFile
 * @return A value converted from C/C++ "bool"
 */
isAutoLoadSpriteFile : function () {},

/**
 * @method addSpriteFrameFromFile
 * @param {const char*}
 * @param {const char*}
 * @param {const char*}
 */
addSpriteFrameFromFile : function () {},

/**
 * @method destoryInstance
 */
destoryInstance : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocostudio::ArmatureDataManager*"
 */
getInstance : function () {},

};

/**
 * @class Armature
 */
ccs.Armature = {

/**
 * @method getBone
 * @return A value converted from C/C++ "cocostudio::Bone*"
 * @param {const char*}
 */
getBone : function () {},

/**
 * @method changeBoneParent
 * @param {cocostudio::Bone*}
 * @param {const char*}
 */
changeBoneParent : function () {},

/**
 * @method setAnimation
 * @param {cocostudio::ArmatureAnimation*}
 */
setAnimation : function () {},

/**
 * @method getBoneAtPoint
 * @return A value converted from C/C++ "cocostudio::Bone*"
 * @param {float}
 * @param {float}
 */
getBoneAtPoint : function () {},

/**
 * @method getArmatureTransformDirty
 * @return A value converted from C/C++ "bool"
 */
getArmatureTransformDirty : function () {},

/**
 * @method setVersion
 * @param {float}
 */
setVersion : function () {},

/**
 * @method updateOffsetPoint
 */
updateOffsetPoint : function () {},

/**
 * @method getParentBone
 * @return A value converted from C/C++ "cocostudio::Bone*"
 */
getParentBone : function () {},

/**
 * @method setName
 * @param {const std::string&}
 */
setName : function () {},

/**
 * @method removeBone
 * @param {cocostudio::Bone*}
 * @param {bool}
 */
removeBone : function () {},

/**
 * @method getBatchNode
 * @return A value converted from C/C++ "cocostudio::BatchNode*"
 */
getBatchNode : function () {},

/**
 * @method getName
 * @return A value converted from C/C++ "const std::string&"
 */
getName : function () {},

/**
 * @method getNodeToParentTransform
 * @return A value converted from C/C++ "const kmMat4&"
 */
getNodeToParentTransform : function () {},

/**
 * @method setParentBone
 * @param {cocostudio::Bone*}
 */
setParentBone : function () {},

/**
 * @method getBoundingBox
 * @return A value converted from C/C++ "cocos2d::Rect"
 */
getBoundingBox : function () {},

/**
 * @method drawContour
 */
drawContour : function () {},

/**
 * @method setBatchNode
 * @param {cocostudio::BatchNode*}
 */
setBatchNode : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method setArmatureData
 * @param {cocostudio::ArmatureData*}
 */
setArmatureData : function () {},

/**
 * @method addBone
 * @param {cocostudio::Bone*}
 * @param {const char*}
 */
addBone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getArmatureData
 * @return A value converted from C/C++ "cocostudio::ArmatureData*"
 */
getArmatureData : function () {},

/**
 * @method getVersion
 * @return A value converted from C/C++ "float"
 */
getVersion : function () {},

/**
 * @method getAnimation
 * @return A value converted from C/C++ "cocostudio::ArmatureAnimation*"
 */
getAnimation : function () {},

/**
 * @method getBoneDic
 * @return A value converted from C/C++ "const cocos2d::Map<std::basic_string<char>, cocostudio::Bone *>&"
 */
getBoneDic : function () {},

/**
 * @method Armature
 * @constructor
 */
Armature : function () {},

};

/**
 * @class Skin
 */
ccs.Skin = {

/**
 * @method getBone
 * @return A value converted from C/C++ "cocostudio::Bone*"
 */
getBone : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method getNodeToWorldTransformAR
 * @return A value converted from C/C++ "kmMat4"
 */
getNodeToWorldTransformAR : function () {},

/**
 * @method getNodeToWorldTransform
 * @return A value converted from C/C++ "kmMat4"
 */
getNodeToWorldTransform : function () {},

/**
 * @method updateTransform
 */
updateTransform : function () {},

/**
 * @method getDisplayName
 * @return A value converted from C/C++ "const std::string&"
 */
getDisplayName : function () {},

/**
 * @method updateArmatureTransform
 */
updateArmatureTransform : function () {},

/**
 * @method initWithSpriteFrameName
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 */
initWithSpriteFrameName : function () {},

/**
 * @method initWithFile
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 */
initWithFile : function () {},

/**
 * @method setBone
 * @param {cocostudio::Bone*}
 */
setBone : function () {},

/**
 * @method createWithSpriteFrameName
 * @return A value converted from C/C++ "cocostudio::Skin*"
 * @param {const char*}
 */
createWithSpriteFrameName : function () {},

/**
 * @method Skin
 * @constructor
 */
Skin : function () {},

};

/**
 * @class ComAttribute
 */
ccs.ComAttribute = {

/**
 * @method getFloat
 * @return A value converted from C/C++ "float"
 * @param {const char*}
 */
getFloat : function () {},

/**
 * @method getDict
 * @return A value converted from C/C++ "cocostudio::JsonDictionary*"
 */
getDict : function () {},

/**
 * @method setFloat
 * @param {const char*}
 * @param {float}
 */
setFloat : function () {},

/**
 * @method setCString
 * @param {const char*}
 * @param {const char*}
 */
setCString : function () {},

/**
 * @method getCString
 * @return A value converted from C/C++ "const char*"
 * @param {const char*}
 */
getCString : function () {},

/**
 * @method getBool
 * @return A value converted from C/C++ "bool"
 * @param {const char*}
 */
getBool : function () {},

/**
 * @method setInt
 * @param {const char*}
 * @param {int}
 */
setInt : function () {},

/**
 * @method getInt
 * @return A value converted from C/C++ "int"
 * @param {const char*}
 */
getInt : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method setBool
 * @param {const char*}
 * @param {bool}
 */
setBool : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ComAttribute*"
 */
create : function () {},

};

/**
 * @class ComAudio
 */
ccs.ComAudio = {

/**
 * @method stopAllEffects
 */
stopAllEffects : function () {},

/**
 * @method getEffectsVolume
 * @return A value converted from C/C++ "float"
 */
getEffectsVolume : function () {},

/**
 * @method stopEffect
 * @param {unsigned int}
 */
stopEffect : function () {},

/**
 * @method getBackgroundMusicVolume
 * @return A value converted from C/C++ "float"
 */
getBackgroundMusicVolume : function () {},

/**
 * @method willPlayBackgroundMusic
 * @return A value converted from C/C++ "bool"
 */
willPlayBackgroundMusic : function () {},

/**
 * @method setBackgroundMusicVolume
 * @param {float}
 */
setBackgroundMusicVolume : function () {},

/**
 * @method end
 */
end : function () {},

/**
 * @method isEnabled
 * @return A value converted from C/C++ "bool"
 */
isEnabled : function () {},

/**
 * @method pauseBackgroundMusic
 */
pauseBackgroundMusic : function () {},

/**
 * @method isBackgroundMusicPlaying
 * @return A value converted from C/C++ "bool"
 */
isBackgroundMusicPlaying : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method isLoop
 * @return A value converted from C/C++ "bool"
 */
isLoop : function () {},

/**
 * @method pauseAllEffects
 */
pauseAllEffects : function () {},

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method preloadBackgroundMusic
 * @param {const char*}
 */
preloadBackgroundMusic : function () {},

/**
 * @method resumeAllEffects
 */
resumeAllEffects : function () {},

/**
 * @method setLoop
 * @param {bool}
 */
setLoop : function () {},

/**
 * @method unloadEffect
 * @param {const char*}
 */
unloadEffect : function () {},

/**
 * @method rewindBackgroundMusic
 */
rewindBackgroundMusic : function () {},

/**
 * @method preloadEffect
 * @param {const char*}
 */
preloadEffect : function () {},

/**
 * @method pauseEffect
 * @param {unsigned int}
 */
pauseEffect : function () {},

/**
 * @method resumeBackgroundMusic
 */
resumeBackgroundMusic : function () {},

/**
 * @method setFile
 * @param {const char*}
 */
setFile : function () {},

/**
 * @method setEffectsVolume
 * @param {float}
 */
setEffectsVolume : function () {},

/**
 * @method getFile
 * @return A value converted from C/C++ "const char*"
 */
getFile : function () {},

/**
 * @method resumeEffect
 * @param {unsigned int}
 */
resumeEffect : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ComAudio*"
 */
create : function () {},

};

/**
 * @class ComController
 */
ccs.ComController = {

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method isEnabled
 * @return A value converted from C/C++ "bool"
 */
isEnabled : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ComController*"
 */
create : function () {},

/**
 * @method ComController
 * @constructor
 */
ComController : function () {},

};

/**
 * @class ComRender
 */
ccs.ComRender = {

/**
 * @method getNode
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getNode : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocostudio::ComRender*"
 * @param {cocos2d::Node*}
 * @param {const char*}
 */
create : function () {},

};

/**
 * @class GUIReader
 */
ccs.GUIReader = {

/**
 * @method widgetFromJsonFile
 * @return A value converted from C/C++ "gui::UIWidget*"
 * @param {const char*}
 */
widgetFromJsonFile : function () {},

/**
 * @method getVersionInteger
 * @return A value converted from C/C++ "int"
 * @param {const char*}
 */
getVersionInteger : function () {},

/**
 * @method getFileDesignSize
 * @return A value converted from C/C++ "cocos2d::Size"
 * @param {const char*}
 */
getFileDesignSize : function () {},

/**
 * @method storeFileDesignSize
 * @param {const char*}
 * @param {const cocos2d::Size&}
 */
storeFileDesignSize : function () {},

/**
 * @method purgeGUIReader
 */
purgeGUIReader : function () {},

/**
 * @method shareReader
 * @return A value converted from C/C++ "cocostudio::GUIReader*"
 */
shareReader : function () {},

/**
 * @method GUIReader
 * @constructor
 */
GUIReader : function () {},

};

/**
 * @class SceneReader
 */
ccs.SceneReader = {

/**
 * @method purgeSceneReader
 */
purgeSceneReader : function () {},

/**
 * @method createNodeWithSceneFile
 * @return A value converted from C/C++ "cocos2d::Node*"
 * @param {const char*}
 */
createNodeWithSceneFile : function () {},

/**
 * @method sceneReaderVersion
 * @return A value converted from C/C++ "const char*"
 */
sceneReaderVersion : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocostudio::SceneReader*"
 */
getInstance : function () {},

/**
 * @method SceneReader
 * @constructor
 */
SceneReader : function () {},

};
