/**
 * @module cocos2dx_gui
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
