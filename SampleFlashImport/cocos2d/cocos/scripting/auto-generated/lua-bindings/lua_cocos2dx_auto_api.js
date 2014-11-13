/**
 * @module cocos2dx
 */
var cc = cc || {};

/**
 * @class Object
 */
cc.Object = {

/**
 * @method isSingleReference
 * @return A value converted from C/C++ "bool"
 */
isSingleReference : function () {},

/**
 * @method release
 */
release : function () {},

/**
 * @method retain
 */
retain : function () {},

/**
 * @method retainCount
 * @return A value converted from C/C++ "unsigned int"
 */
retainCount : function () {},

/**
 * @method Object
 * @constructor
 */
Object : function () {},

};

/**
 * @class Action
 */
cc.Action = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method setOriginalTarget
 * @param {cocos2d::Node*}
 */
setOriginalTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Action*"
 */
clone : function () {},

/**
 * @method getOriginalTarget
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getOriginalTarget : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getTarget
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getTarget : function () {},

/**
 * @method step
 * @param {float}
 */
step : function () {},

/**
 * @method setTag
 * @param {int}
 */
setTag : function () {},

/**
 * @method getTag
 * @return A value converted from C/C++ "int"
 */
getTag : function () {},

/**
 * @method setTarget
 * @param {cocos2d::Node*}
 */
setTarget : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Action*"
 */
reverse : function () {},

};

/**
 * @class FiniteTimeAction
 */
cc.FiniteTimeAction = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FiniteTimeAction*"
 */
clone : function () {},

/**
 * @method setDuration
 * @param {float}
 */
setDuration : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::FiniteTimeAction*"
 */
reverse : function () {},

/**
 * @method getDuration
 * @return A value converted from C/C++ "float"
 */
getDuration : function () {},

};

/**
 * @class Speed
 */
cc.Speed = {

/**
 * @method setInnerAction
 * @param {cocos2d::ActionInterval*}
 */
setInnerAction : function () {},

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method getSpeed
 * @return A value converted from C/C++ "float"
 */
getSpeed : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Speed*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method setSpeed
 * @param {float}
 */
setSpeed : function () {},

/**
 * @method step
 * @param {float}
 */
step : function () {},

/**
 * @method getInnerAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
getInnerAction : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Speed*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Speed*"
 * @param {cocos2d::ActionInterval*}
 * @param {float}
 */
create : function () {},

};

/**
 * @class Follow
 */
cc.Follow = {

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Follow*"
 */
reverse : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Follow*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method setBoudarySet
 * @param {bool}
 */
setBoudarySet : function () {},

/**
 * @method step
 * @param {float}
 */
step : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method isBoundarySet
 * @return A value converted from C/C++ "bool"
 */
isBoundarySet : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Follow*"
 * @param {cocos2d::Node*}
 * @param {const cocos2d::Rect&}
 */
create : function () {},

};

/**
 * @class GLProgram
 */
cc.GLProgram = {

/**
 * @method getFragmentShaderLog
 * @return A value converted from C/C++ "std::string"
 */
getFragmentShaderLog : function () {},

/**
 * @method addAttribute
 * @param {const char*}
 * @param {GLuint}
 */
addAttribute : function () {},

/**
 * @method setUniformLocationWithMatrix4fv
 * @param {GLint}
 * @param {const GLfloat*}
 * @param {unsigned int}
 */
setUniformLocationWithMatrix4fv : function () {},

/**
 * @method getUniformLocationForName
 * @return A value converted from C/C++ "GLint"
 * @param {const char*}
 */
getUniformLocationForName : function () {},

/**
 * @method use
 */
use : function () {},

/**
 * @method getVertexShaderLog
 * @return A value converted from C/C++ "std::string"
 */
getVertexShaderLog : function () {},

/**
 * @method initWithVertexShaderByteArray
 * @return A value converted from C/C++ "bool"
 * @param {const GLchar*}
 * @param {const GLchar*}
 */
initWithVertexShaderByteArray : function () {},

/**
 * @method initWithVertexShaderFilename
 * @return A value converted from C/C++ "bool"
 * @param {const char*}
 * @param {const char*}
 */
initWithVertexShaderFilename : function () {},

/**
 * @method setUniformLocationWith3i
 * @param {GLint}
 * @param {GLint}
 * @param {GLint}
 * @param {GLint}
 */
setUniformLocationWith3i : function () {},

/**
 * @method setUniformLocationWith3iv
 * @param {GLint}
 * @param {GLint*}
 * @param {unsigned int}
 */
setUniformLocationWith3iv : function () {},

/**
 * @method updateUniforms
 */
updateUniforms : function () {},

/**
 * @method setUniformLocationWith4iv
 * @param {GLint}
 * @param {GLint*}
 * @param {unsigned int}
 */
setUniformLocationWith4iv : function () {},

/**
 * @method setUniformLocationWithMatrix2fv
 * @param {GLint}
 * @param {const GLfloat*}
 * @param {unsigned int}
 */
setUniformLocationWithMatrix2fv : function () {},

/**
 * @method link
 * @return A value converted from C/C++ "bool"
 */
link : function () {},

/**
 * @method setUniformLocationWith2iv
 * @param {GLint}
 * @param {GLint*}
 * @param {unsigned int}
 */
setUniformLocationWith2iv : function () {},

/**
 * @method setUniformLocationWithMatrix3fv
 * @param {GLint}
 * @param {const GLfloat*}
 * @param {unsigned int}
 */
setUniformLocationWithMatrix3fv : function () {},

/**
 * @method reset
 */
reset : function () {},

/**
 * @method setUniformLocationWith4i
 * @param {GLint}
 * @param {GLint}
 * @param {GLint}
 * @param {GLint}
 * @param {GLint}
 */
setUniformLocationWith4i : function () {},

/**
 * @method setUniformLocationWith1i
 * @param {GLint}
 * @param {GLint}
 */
setUniformLocationWith1i : function () {},

/**
 * @method setUniformLocationWith2i
 * @param {GLint}
 * @param {GLint}
 * @param {GLint}
 */
setUniformLocationWith2i : function () {},

/**
 * @method GLProgram
 * @constructor
 */
GLProgram : function () {},

};

/**
 * @class Touch
 */
cc.Touch = {

/**
 * @method getPreviousLocationInView
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getPreviousLocationInView : function () {},

/**
 * @method getLocation
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getLocation : function () {},

/**
 * @method getDelta
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getDelta : function () {},

/**
 * @method getStartLocationInView
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getStartLocationInView : function () {},

/**
 * @method getStartLocation
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getStartLocation : function () {},

/**
 * @method getID
 * @return A value converted from C/C++ "int"
 */
getID : function () {},

/**
 * @method setTouchInfo
 * @param {int}
 * @param {float}
 * @param {float}
 */
setTouchInfo : function () {},

/**
 * @method getLocationInView
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getLocationInView : function () {},

/**
 * @method getPreviousLocation
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getPreviousLocation : function () {},

/**
 * @method Touch
 * @constructor
 */
Touch : function () {},

};

/**
 * @class Texture2D
 */
cc.Texture2D = {

/**
 * @method getShaderProgram
 * @return A value converted from C/C++ "cocos2d::GLProgram*"
 */
getShaderProgram : function () {},

/**
 * @method getMaxT
 * @return A value converted from C/C++ "GLfloat"
 */
getMaxT : function () {},

/**
 * @method getStringForFormat
 * @return A value converted from C/C++ "const char*"
 */
getStringForFormat : function () {},

/**
 * @method setShaderProgram
 * @param {cocos2d::GLProgram*}
 */
setShaderProgram : function () {},

/**
 * @method getMaxS
 * @return A value converted from C/C++ "GLfloat"
 */
getMaxS : function () {},

/**
 * @method hasPremultipliedAlpha
 * @return A value converted from C/C++ "bool"
 */
hasPremultipliedAlpha : function () {},

/**
 * @method initWithMipmaps
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::MipmapInfo*}
 * @param {int}
 * @param {cocos2d::Texture2D::PixelFormat}
 * @param {int}
 * @param {int}
 */
initWithMipmaps : function () {},

/**
 * @method getPixelsHigh
 * @return A value converted from C/C++ "int"
 */
getPixelsHigh : function () {},

/**
 * @method getName
 * @return A value converted from C/C++ "GLuint"
 */
getName : function () {},

/**
 * @method setMaxT
 * @param {GLfloat}
 */
setMaxT : function () {},

/**
 * @method drawInRect
 * @param {const cocos2d::Rect&}
 */
drawInRect : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "cocos2d::Size"
 */
getContentSize : function () {},

/**
 * @method setAliasTexParameters
 */
setAliasTexParameters : function () {},

/**
 * @method setAntiAliasTexParameters
 */
setAntiAliasTexParameters : function () {},

/**
 * @method generateMipmap
 */
generateMipmap : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method getPixelFormat
 * @return A value converted from C/C++ "cocos2d::Texture2D::PixelFormat"
 */
getPixelFormat : function () {},

/**
 * @method getContentSizeInPixels
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSizeInPixels : function () {},

/**
 * @method getPixelsWide
 * @return A value converted from C/C++ "int"
 */
getPixelsWide : function () {},

/**
 * @method drawAtPoint
 * @param {const cocos2d::Point&}
 */
drawAtPoint : function () {},

/**
 * @method hasMipmaps
 * @return A value converted from C/C++ "bool"
 */
hasMipmaps : function () {},

/**
 * @method setMaxS
 * @param {GLfloat}
 */
setMaxS : function () {},

/**
 * @method setDefaultAlphaPixelFormat
 * @param {cocos2d::Texture2D::PixelFormat}
 */
setDefaultAlphaPixelFormat : function () {},

/**
 * @method getDefaultAlphaPixelFormat
 * @return A value converted from C/C++ "cocos2d::Texture2D::PixelFormat"
 */
getDefaultAlphaPixelFormat : function () {},

/**
 * @method PVRImagesHavePremultipliedAlpha
 * @param {bool}
 */
PVRImagesHavePremultipliedAlpha : function () {},

/**
 * @method Texture2D
 * @constructor
 */
Texture2D : function () {},

};

/**
 * @class Node
 */
cc.Node = {

/**
 * @method removeComponent
 * @return A value converted from C/C++ "bool"
 * @param {const char*}
 */
removeComponent : function () {},

/**
 * @method setPhysicsBody
 * @param {cocos2d::PhysicsBody*}
 */
setPhysicsBody : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method pause
 */
pause : function () {},

/**
 * @method convertToWorldSpaceAR
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
convertToWorldSpaceAR : function () {},

/**
 * @method isIgnoreAnchorPointForPosition
 * @return A value converted from C/C++ "bool"
 */
isIgnoreAnchorPointForPosition : function () {},

/**
 * @method setRotation
 * @param {float}
 */
setRotation : function () {},

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
 * @method removeAllComponents
 */
removeAllComponents : function () {},

/**
 * @method getTag
 * @return A value converted from C/C++ "int"
 */
getTag : function () {},

/**
 * @method getNodeToWorldAffineTransform
 * @return A value converted from C/C++ "cocos2d::AffineTransform"
 */
getNodeToWorldAffineTransform : function () {},

/**
 * @method getNodeToWorldTransform
 * @return A value converted from C/C++ "kmMat4"
 */
getNodeToWorldTransform : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method convertToWorldSpace
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
convertToWorldSpace : function () {},

/**
 * @method getEventDispatcher
 * @return A value converted from C/C++ "cocos2d::EventDispatcher*"
 */
getEventDispatcher : function () {},

/**
 * @method setSkewX
 * @param {float}
 */
setSkewX : function () {},

/**
 * @method setSkewY
 * @param {float}
 */
setSkewY : function () {},

/**
 * @method convertTouchToNodeSpace
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {cocos2d::Touch*}
 */
convertTouchToNodeSpace : function () {},

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
 * @method getNodeToParentAffineTransform
 * @return A value converted from C/C++ "cocos2d::AffineTransform"
 */
getNodeToParentAffineTransform : function () {},

/**
 * @method setParent
 * @param {cocos2d::Node*}
 */
setParent : function () {},

/**
 * @method getNodeToParentTransform
 * @return A value converted from C/C++ "const kmMat4&"
 */
getNodeToParentTransform : function () {},

/**
 * @method convertToNodeSpace
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
convertToNodeSpace : function () {},

/**
 * @method resume
 */
resume : function () {},

/**
 * @method getPhysicsBody
 * @return A value converted from C/C++ "cocos2d::PhysicsBody*"
 */
getPhysicsBody : function () {},

/**
 * @method stopActionByTag
 * @param {int}
 */
stopActionByTag : function () {},

/**
 * @method reorderChild
 * @param {cocos2d::Node*}
 * @param {int}
 */
reorderChild : function () {},

/**
 * @method ignoreAnchorPointForPosition
 * @param {bool}
 */
ignoreAnchorPointForPosition : function () {},

/**
 * @method setPositionY
 * @param {float}
 */
setPositionY : function () {},

/**
 * @method setPositionX
 * @param {float}
 */
setPositionX : function () {},

/**
 * @method getAnchorPoint
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getAnchorPoint : function () {},

/**
 * @method getNumberOfRunningActions
 * @return A value converted from C/C++ "ssize_t"
 */
getNumberOfRunningActions : function () {},

/**
 * @method updateTransform
 */
updateTransform : function () {},

/**
 * @method isVisible
 * @return A value converted from C/C++ "bool"
 */
isVisible : function () {},

/**
 * @method getChildrenCount
 * @return A value converted from C/C++ "ssize_t"
 */
getChildrenCount : function () {},

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method convertToNodeSpaceAR
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
convertToNodeSpaceAR : function () {},

/**
 * @method addComponent
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::Component*}
 */
addComponent : function () {},

/**
 * @method visit
 */
visit : function () {},

/**
 * @method setShaderProgram
 * @param {cocos2d::GLProgram*}
 */
setShaderProgram : function () {},

/**
 * @method getRotation
 * @return A value converted from C/C++ "float"
 */
getRotation : function () {},

/**
 * @method getZOrder
 * @return A value converted from C/C++ "int"
 */
getZOrder : function () {},

/**
 * @method getAnchorPointInPoints
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getAnchorPointInPoints : function () {},

/**
 * @method runAction
 * @return A value converted from C/C++ "cocos2d::Action*"
 * @param {cocos2d::Action*}
 */
runAction : function () {},

/**
 * @method transform
 */
transform : function () {},

/**
 * @method setVertexZ
 * @param {float}
 */
setVertexZ : function () {},

/**
 * @method setScheduler
 * @param {cocos2d::Scheduler*}
 */
setScheduler : function () {},

/**
 * @method stopAllActions
 */
stopAllActions : function () {},

/**
 * @method getSkewX
 * @return A value converted from C/C++ "float"
 */
getSkewX : function () {},

/**
 * @method getSkewY
 * @return A value converted from C/C++ "float"
 */
getSkewY : function () {},

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
 * @method getParentToNodeAffineTransform
 * @return A value converted from C/C++ "cocos2d::AffineTransform"
 */
getParentToNodeAffineTransform : function () {},

/**
 * @method getOrderOfArrival
 * @return A value converted from C/C++ "int"
 */
getOrderOfArrival : function () {},

/**
 * @method setContentSize
 * @param {const cocos2d::Size&}
 */
setContentSize : function () {},

/**
 * @method setActionManager
 * @param {cocos2d::ActionManager*}
 */
setActionManager : function () {},

/**
 * @method isRunning
 * @return A value converted from C/C++ "bool"
 */
isRunning : function () {},

/**
 * @method getPositionY
 * @return A value converted from C/C++ "float"
 */
getPositionY : function () {},

/**
 * @method getPositionX
 * @return A value converted from C/C++ "float"
 */
getPositionX : function () {},

/**
 * @method removeChildByTag
 * @param {int}
 * @param {bool}
 */
removeChildByTag : function () {},

/**
 * @method setVisible
 * @param {bool}
 */
setVisible : function () {},

/**
 * @method getParentToNodeTransform
 * @return A value converted from C/C++ "const kmMat4&"
 */
getParentToNodeTransform : function () {},

/**
 * @method getVertexZ
 * @return A value converted from C/C++ "float"
 */
getVertexZ : function () {},

/**
 * @method _setZOrder
 * @param {int}
 */
_setZOrder : function () {},

/**
 * @method getChildByTag
 * @return A value converted from C/C++ "cocos2d::Node*"
 * @param {int}
 */
getChildByTag : function () {},

/**
 * @method setOrderOfArrival
 * @param {int}
 */
setOrderOfArrival : function () {},

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
 * @method getWorldToNodeAffineTransform
 * @return A value converted from C/C++ "cocos2d::AffineTransform"
 */
getWorldToNodeAffineTransform : function () {},

/**
 * @method cleanup
 */
cleanup : function () {},

/**
 * @method getComponent
 * @return A value converted from C/C++ "cocos2d::Component*"
 * @param {const char*}
 */
getComponent : function () {},

/**
 * @method getContentSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getContentSize : function () {},

/**
 * @method setGrid
 * @param {cocos2d::GridBase*}
 */
setGrid : function () {},

/**
 * @method getBoundingBox
 * @return A value converted from C/C++ "cocos2d::Rect"
 */
getBoundingBox : function () {},

/**
 * @method updatePhysicsTransform
 * @return A value converted from C/C++ "bool"
 */
updatePhysicsTransform : function () {},

/**
 * @method setEventDispatcher
 * @param {cocos2d::EventDispatcher*}
 */
setEventDispatcher : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method transformAncestors
 */
transformAncestors : function () {},

/**
 * @method setUserObject
 * @param {cocos2d::Object*}
 */
setUserObject : function () {},

/**
 * @method convertTouchToNodeSpaceAR
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {cocos2d::Touch*}
 */
convertTouchToNodeSpaceAR : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method sortAllChildren
 */
sortAllChildren : function () {},

/**
 * @method getWorldToNodeTransform
 * @return A value converted from C/C++ "kmMat4"
 */
getWorldToNodeTransform : function () {},

/**
 * @method getScale
 * @return A value converted from C/C++ "float"
 */
getScale : function () {},

/**
 * @method getCamera
 * @return A value converted from C/C++ "cocos2d::Camera*"
 */
getCamera : function () {},

/**
 * @method setTag
 * @param {int}
 */
setTag : function () {},

/**
 * @method stopAction
 * @param {cocos2d::Action*}
 */
stopAction : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
create : function () {},

};

/**
 * @class NodeRGBA
 */
cc.NodeRGBA = {

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getColor : function () {},

/**
 * @method getDisplayedOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getDisplayedOpacity : function () {},

/**
 * @method setCascadeColorEnabled
 * @param {bool}
 */
setCascadeColorEnabled : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {GLubyte}
 */
updateDisplayedOpacity : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method updateDisplayedColor
 * @param {const cocos2d::Color3B&}
 */
updateDisplayedColor : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getOpacity : function () {},

/**
 * @method getDisplayedColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getDisplayedColor : function () {},

};

/**
 * @class SpriteFrame
 */
cc.SpriteFrame = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::SpriteFrame*"
 */
clone : function () {},

/**
 * @method setRotated
 * @param {bool}
 */
setRotated : function () {},

/**
 * @method setTexture
 * @param {cocos2d::Texture2D*}
 */
setTexture : function () {},

/**
 * @method setRectInPixels
 * @param {const cocos2d::Rect&}
 */
setRectInPixels : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 */
getTexture : function () {},

/**
 * @method getRect
 * @return A value converted from C/C++ "const cocos2d::Rect&"
 */
getRect : function () {},

/**
 * @method setOffsetInPixels
 * @param {const cocos2d::Point&}
 */
setOffsetInPixels : function () {},

/**
 * @method getRectInPixels
 * @return A value converted from C/C++ "const cocos2d::Rect&"
 */
getRectInPixels : function () {},

/**
 * @method setOriginalSize
 * @param {const cocos2d::Size&}
 */
setOriginalSize : function () {},

/**
 * @method getOriginalSizeInPixels
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getOriginalSizeInPixels : function () {},

/**
 * @method setOriginalSizeInPixels
 * @param {const cocos2d::Size&}
 */
setOriginalSizeInPixels : function () {},

/**
 * @method setOffset
 * @param {const cocos2d::Point&}
 */
setOffset : function () {},

/**
 * @method getOffset
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getOffset : function () {},

/**
 * @method isRotated
 * @return A value converted from C/C++ "bool"
 */
isRotated : function () {},

/**
 * @method setRect
 * @param {const cocos2d::Rect&}
 */
setRect : function () {},

/**
 * @method getOffsetInPixels
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getOffsetInPixels : function () {},

/**
 * @method getOriginalSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getOriginalSize : function () {},

};

/**
 * @class AnimationFrame
 */
cc.AnimationFrame = {

/**
 * @method setSpriteFrame
 * @param {cocos2d::SpriteFrame*}
 */
setSpriteFrame : function () {},

/**
 * @method setDelayUnits
 * @param {float}
 */
setDelayUnits : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::AnimationFrame*"
 */
clone : function () {},

/**
 * @method getSpriteFrame
 * @return A value converted from C/C++ "cocos2d::SpriteFrame*"
 */
getSpriteFrame : function () {},

/**
 * @method getDelayUnits
 * @return A value converted from C/C++ "float"
 */
getDelayUnits : function () {},

/**
 * @method setUserInfo
 * @param {const cocos2d::ValueMap&}
 */
setUserInfo : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::AnimationFrame*"
 * @param {cocos2d::SpriteFrame*}
 * @param {float}
 * @param {const cocos2d::ValueMap&}
 */
create : function () {},

};

/**
 * @class Animation
 */
cc.Animation = {

/**
 * @method getLoops
 * @return A value converted from C/C++ "unsigned int"
 */
getLoops : function () {},

/**
 * @method addSpriteFrame
 * @param {cocos2d::SpriteFrame*}
 */
addSpriteFrame : function () {},

/**
 * @method setRestoreOriginalFrame
 * @param {bool}
 */
setRestoreOriginalFrame : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Animation*"
 */
clone : function () {},

/**
 * @method getDuration
 * @return A value converted from C/C++ "float"
 */
getDuration : function () {},

/**
 * @method setFrames
 * @param {const cocos2d::Vector<cocos2d::AnimationFrame *>&}
 */
setFrames : function () {},

/**
 * @method getFrames
 * @return A value converted from C/C++ "const cocos2d::Vector<cocos2d::AnimationFrame *>&"
 */
getFrames : function () {},

/**
 * @method setLoops
 * @param {unsigned int}
 */
setLoops : function () {},

/**
 * @method setDelayPerUnit
 * @param {float}
 */
setDelayPerUnit : function () {},

/**
 * @method addSpriteFrameWithFile
 * @param {const std::string&}
 */
addSpriteFrameWithFile : function () {},

/**
 * @method getTotalDelayUnits
 * @return A value converted from C/C++ "float"
 */
getTotalDelayUnits : function () {},

/**
 * @method getDelayPerUnit
 * @return A value converted from C/C++ "float"
 */
getDelayPerUnit : function () {},

/**
 * @method getRestoreOriginalFrame
 * @return A value converted from C/C++ "bool"
 */
getRestoreOriginalFrame : function () {},

/**
 * @method addSpriteFrameWithTexture
 * @param {cocos2d::Texture2D*}
 * @param {const cocos2d::Rect&}
 */
addSpriteFrameWithTexture : function () {},

/**
 * @method createWithSpriteFrames
 * @return A value converted from C/C++ "cocos2d::Animation*"
 * @param {const cocos2d::Vector<cocos2d::SpriteFrame *>&}
 * @param {float}
 */
createWithSpriteFrames : function () {},

};

/**
 * @class ActionInterval
 */
cc.ActionInterval = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
clone : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method step
 * @param {float}
 */
step : function () {},

/**
 * @method getElapsed
 * @return A value converted from C/C++ "float"
 */
getElapsed : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
reverse : function () {},

};

/**
 * @class Sequence
 */
cc.Sequence = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Sequence*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Sequence*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class Repeat
 */
cc.Repeat = {

/**
 * @method setInnerAction
 * @param {cocos2d::FiniteTimeAction*}
 */
setInnerAction : function () {},

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Repeat*"
 */
reverse : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Repeat*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getInnerAction
 * @return A value converted from C/C++ "cocos2d::FiniteTimeAction*"
 */
getInnerAction : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Repeat*"
 * @param {cocos2d::FiniteTimeAction*}
 * @param {unsigned int}
 */
create : function () {},

};

/**
 * @class RepeatForever
 */
cc.RepeatForever = {

/**
 * @method setInnerAction
 * @param {cocos2d::ActionInterval*}
 */
setInnerAction : function () {},

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::RepeatForever*"
 */
reverse : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::RepeatForever*"
 */
clone : function () {},

/**
 * @method step
 * @param {float}
 */
step : function () {},

/**
 * @method getInnerAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
getInnerAction : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::RepeatForever*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class Spawn
 */
cc.Spawn = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Spawn*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Spawn*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class RotateTo
 */
cc.RotateTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::RotateTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::RotateTo*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class RotateBy
 */
cc.RotateBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::RotateBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::RotateBy*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class MoveBy
 */
cc.MoveBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::MoveBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::MoveBy*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::MoveBy*"
 * @param {float}
 * @param {const cocos2d::Point&}
 */
create : function () {},

};

/**
 * @class MoveTo
 */
cc.MoveTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::MoveTo*"
 */
clone : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::MoveTo*"
 * @param {float}
 * @param {const cocos2d::Point&}
 */
create : function () {},

};

/**
 * @class SkewTo
 */
cc.SkewTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::SkewTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::SkewTo*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::SkewTo*"
 * @param {float}
 * @param {float}
 * @param {float}
 */
create : function () {},

};

/**
 * @class SkewBy
 */
cc.SkewBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::SkewBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::SkewBy*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::SkewBy*"
 * @param {float}
 * @param {float}
 * @param {float}
 */
create : function () {},

};

/**
 * @class JumpBy
 */
cc.JumpBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::JumpBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::JumpBy*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::JumpBy*"
 * @param {float}
 * @param {const cocos2d::Point&}
 * @param {float}
 * @param {int}
 */
create : function () {},

};

/**
 * @class JumpTo
 */
cc.JumpTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::JumpTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::JumpTo*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::JumpTo*"
 * @param {float}
 * @param {const cocos2d::Point&}
 * @param {float}
 * @param {int}
 */
create : function () {},

};

/**
 * @class BezierBy
 */
cc.BezierBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::BezierBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::BezierBy*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class BezierTo
 */
cc.BezierTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::BezierTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::BezierTo*"
 */
reverse : function () {},

};

/**
 * @class ScaleTo
 */
cc.ScaleTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ScaleTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ScaleTo*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class ScaleBy
 */
cc.ScaleBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ScaleBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ScaleBy*"
 */
reverse : function () {},

};

/**
 * @class Blink
 */
cc.Blink = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Blink*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Blink*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Blink*"
 * @param {float}
 * @param {int}
 */
create : function () {},

};

/**
 * @class FadeIn
 */
cc.FadeIn = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FadeIn*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FadeIn*"
 * @param {float}
 */
create : function () {},

};

/**
 * @class FadeOut
 */
cc.FadeOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FadeOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FadeOut*"
 * @param {float}
 */
create : function () {},

};

/**
 * @class FadeTo
 */
cc.FadeTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FadeTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::FadeTo*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FadeTo*"
 * @param {float}
 * @param {GLubyte}
 */
create : function () {},

};

/**
 * @class TintTo
 */
cc.TintTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::TintTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::TintTo*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TintTo*"
 * @param {float}
 * @param {GLubyte}
 * @param {GLubyte}
 * @param {GLubyte}
 */
create : function () {},

};

/**
 * @class TintBy
 */
cc.TintBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::TintBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::TintBy*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TintBy*"
 * @param {float}
 * @param {GLshort}
 * @param {GLshort}
 * @param {GLshort}
 */
create : function () {},

};

/**
 * @class DelayTime
 */
cc.DelayTime = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::DelayTime*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::DelayTime*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::DelayTime*"
 * @param {float}
 */
create : function () {},

};

/**
 * @class Animate
 */
cc.Animate = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Animate*"
 */
reverse : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Animate*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method setAnimation
 * @param {cocos2d::Animation*}
 */
setAnimation : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Animate*"
 * @param {cocos2d::Animation*}
 */
create : function () {},

};

/**
 * @class TargetedAction
 */
cc.TargetedAction = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::TargetedAction*"
 */
reverse : function () {},

/**
 * @method setForcedTarget
 * @param {cocos2d::Node*}
 */
setForcedTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::TargetedAction*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TargetedAction*"
 * @param {cocos2d::Node*}
 * @param {cocos2d::FiniteTimeAction*}
 */
create : function () {},

};

/**
 * @class ActionCamera
 */
cc.ActionCamera = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ActionCamera*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionCamera*"
 */
reverse : function () {},

/**
 * @method ActionCamera
 * @constructor
 */
ActionCamera : function () {},

};

/**
 * @class OrbitCamera
 */
cc.OrbitCamera = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 */
initWithDuration : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::OrbitCamera*"
 */
clone : function () {},

/**
 * @method sphericalRadius
 * @param {float*}
 * @param {float*}
 * @param {float*}
 */
sphericalRadius : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::OrbitCamera*"
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 */
create : function () {},

/**
 * @method OrbitCamera
 * @constructor
 */
OrbitCamera : function () {},

};

/**
 * @class ActionManager
 */
cc.ActionManager = {

/**
 * @method getActionByTag
 * @return A value converted from C/C++ "cocos2d::Action*"
 * @param {int}
 * @param {const cocos2d::Node*}
 */
getActionByTag : function () {},

/**
 * @method removeActionByTag
 * @param {int}
 * @param {cocos2d::Node*}
 */
removeActionByTag : function () {},

/**
 * @method removeAllActions
 */
removeAllActions : function () {},

/**
 * @method addAction
 * @param {cocos2d::Action*}
 * @param {cocos2d::Node*}
 * @param {bool}
 */
addAction : function () {},

/**
 * @method resumeTarget
 * @param {cocos2d::Node*}
 */
resumeTarget : function () {},

/**
 * @method getNumberOfRunningActionsInTarget
 * @return A value converted from C/C++ "ssize_t"
 * @param {const cocos2d::Node*}
 */
getNumberOfRunningActionsInTarget : function () {},

/**
 * @method removeAllActionsFromTarget
 * @param {cocos2d::Node*}
 */
removeAllActionsFromTarget : function () {},

/**
 * @method resumeTargets
 * @param {const cocos2d::Vector<cocos2d::Node *>&}
 */
resumeTargets : function () {},

/**
 * @method removeAction
 * @param {cocos2d::Action*}
 */
removeAction : function () {},

/**
 * @method pauseTarget
 * @param {cocos2d::Node*}
 */
pauseTarget : function () {},

/**
 * @method pauseAllRunningActions
 * @return A value converted from C/C++ "cocos2d::Vector<cocos2d::Node *>"
 */
pauseAllRunningActions : function () {},

/**
 * @method ActionManager
 * @constructor
 */
ActionManager : function () {},

};

/**
 * @class ActionEase
 */
cc.ActionEase = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
reverse : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
clone : function () {},

/**
 * @method stop
 */
stop : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getInnerAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
getInnerAction : function () {},

};

/**
 * @class EaseRateAction
 */
cc.EaseRateAction = {

/**
 * @method setRate
 * @param {float}
 */
setRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseRateAction*"
 */
clone : function () {},

/**
 * @method getRate
 * @return A value converted from C/C++ "float"
 */
getRate : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseRateAction*"
 */
reverse : function () {},

};

/**
 * @class EaseIn
 */
cc.EaseIn = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseIn*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseIn*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseIn*"
 * @param {cocos2d::ActionInterval*}
 * @param {float}
 */
create : function () {},

};

/**
 * @class EaseOut
 */
cc.EaseOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseOut*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseOut*"
 * @param {cocos2d::ActionInterval*}
 * @param {float}
 */
create : function () {},

};

/**
 * @class EaseInOut
 */
cc.EaseInOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseInOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseInOut*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseInOut*"
 * @param {cocos2d::ActionInterval*}
 * @param {float}
 */
create : function () {},

};

/**
 * @class EaseExponentialIn
 */
cc.EaseExponentialIn = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseExponentialIn*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseExponentialIn*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseExponentialOut
 */
cc.EaseExponentialOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseExponentialOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseExponentialOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseExponentialInOut
 */
cc.EaseExponentialInOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseExponentialInOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseExponentialInOut*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseExponentialInOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseSineIn
 */
cc.EaseSineIn = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseSineIn*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseSineIn*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseSineOut
 */
cc.EaseSineOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseSineOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseSineOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseSineInOut
 */
cc.EaseSineInOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseSineInOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseSineInOut*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseSineInOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseElastic
 */
cc.EaseElastic = {

/**
 * @method setPeriod
 * @param {float}
 */
setPeriod : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseElastic*"
 */
clone : function () {},

/**
 * @method getPeriod
 * @return A value converted from C/C++ "float"
 */
getPeriod : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseElastic*"
 */
reverse : function () {},

};

/**
 * @class EaseElasticIn
 */
cc.EaseElasticIn = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseElasticIn*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseElastic*"
 */
reverse : function () {},

};

/**
 * @class EaseElasticOut
 */
cc.EaseElasticOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseElasticOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseElastic*"
 */
reverse : function () {},

};

/**
 * @class EaseElasticInOut
 */
cc.EaseElasticInOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseElasticInOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseElasticInOut*"
 */
reverse : function () {},

};

/**
 * @class EaseBounce
 */
cc.EaseBounce = {

/**
 * @method bounceTime
 * @return A value converted from C/C++ "float"
 * @param {float}
 */
bounceTime : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseBounce*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseBounce*"
 */
reverse : function () {},

};

/**
 * @class EaseBounceIn
 */
cc.EaseBounceIn = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseBounceIn*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseBounce*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseBounceIn*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseBounceOut
 */
cc.EaseBounceOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseBounceOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseBounce*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseBounceOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseBounceInOut
 */
cc.EaseBounceInOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseBounceInOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseBounceInOut*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseBounceInOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseBackIn
 */
cc.EaseBackIn = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseBackIn*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseBackIn*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseBackOut
 */
cc.EaseBackOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseBackOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionEase*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseBackOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class EaseBackInOut
 */
cc.EaseBackInOut = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::EaseBackInOut*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::EaseBackInOut*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::EaseBackInOut*"
 * @param {cocos2d::ActionInterval*}
 */
create : function () {},

};

/**
 * @class ActionInstant
 */
cc.ActionInstant = {

/**
 * @method step
 * @param {float}
 */
step : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ActionInstant*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionInstant*"
 */
reverse : function () {},

/**
 * @method isDone
 * @return A value converted from C/C++ "bool"
 */
isDone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class Show
 */
cc.Show = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Show*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionInstant*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Show*"
 */
create : function () {},

};

/**
 * @class Hide
 */
cc.Hide = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Hide*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionInstant*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Hide*"
 */
create : function () {},

};

/**
 * @class ToggleVisibility
 */
cc.ToggleVisibility = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ToggleVisibility*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ToggleVisibility*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ToggleVisibility*"
 */
create : function () {},

};

/**
 * @class RemoveSelf
 */
cc.RemoveSelf = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::RemoveSelf*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::RemoveSelf*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::RemoveSelf*"
 */
create : function () {},

};

/**
 * @class FlipX
 */
cc.FlipX = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FlipX*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::FlipX*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FlipX*"
 * @param {bool}
 */
create : function () {},

};

/**
 * @class FlipY
 */
cc.FlipY = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FlipY*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::FlipY*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FlipY*"
 * @param {bool}
 */
create : function () {},

};

/**
 * @class Place
 */
cc.Place = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Place*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::Place*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Place*"
 * @param {const cocos2d::Point&}
 */
create : function () {},

};

/**
 * @class CallFunc
 */
cc.CallFunc = {

/**
 * @method execute
 */
execute : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::CallFunc*"
 */
reverse : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::CallFunc*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getTargetCallback
 * @return A value converted from C/C++ "cocos2d::Object*"
 */
getTargetCallback : function () {},

/**
 * @method setTargetCallback
 * @param {cocos2d::Object*}
 */
setTargetCallback : function () {},

};

/**
 * @class GridAction
 */
cc.GridAction = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::GridAction*"
 */
clone : function () {},

/**
 * @method getGrid
 * @return A value converted from C/C++ "cocos2d::GridBase*"
 */
getGrid : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::GridAction*"
 */
reverse : function () {},

};

/**
 * @class Grid3DAction
 */
cc.Grid3DAction = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Grid3DAction*"
 */
clone : function () {},

/**
 * @method getGrid
 * @return A value converted from C/C++ "cocos2d::GridBase*"
 */
getGrid : function () {},

};

/**
 * @class TiledGrid3DAction
 */
cc.TiledGrid3DAction = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::TiledGrid3DAction*"
 */
clone : function () {},

/**
 * @method getGrid
 * @return A value converted from C/C++ "cocos2d::GridBase*"
 */
getGrid : function () {},

};

/**
 * @class StopGrid
 */
cc.StopGrid = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::StopGrid*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::StopGrid*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::StopGrid*"
 */
create : function () {},

};

/**
 * @class ReuseGrid
 */
cc.ReuseGrid = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ReuseGrid*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ReuseGrid*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ReuseGrid*"
 * @param {int}
 */
create : function () {},

};

/**
 * @class Waves3D
 */
cc.Waves3D = {

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Waves3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method setAmplitude
 * @param {float}
 */
setAmplitude : function () {},

/**
 * @method getAmplitude
 * @return A value converted from C/C++ "float"
 */
getAmplitude : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Waves3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {unsigned int}
 * @param {float}
 */
create : function () {},

};

/**
 * @class FlipX3D
 */
cc.FlipX3D = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FlipX3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FlipX3D*"
 * @param {float}
 */
create : function () {},

};

/**
 * @class FlipY3D
 */
cc.FlipY3D = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FlipY3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FlipY3D*"
 * @param {float}
 */
create : function () {},

/**
 * @method FlipY3D
 * @constructor
 */
FlipY3D : function () {},

};

/**
 * @class Lens3D
 */
cc.Lens3D = {

/**
 * @method setConcave
 * @param {bool}
 */
setConcave : function () {},

/**
 * @method setLensEffect
 * @param {float}
 */
setLensEffect : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getLensEffect
 * @return A value converted from C/C++ "float"
 */
getLensEffect : function () {},

/**
 * @method setPosition
 * @param {const cocos2d::Point&}
 */
setPosition : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Lens3D*"
 */
clone : function () {},

/**
 * @method getPosition
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getPosition : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Lens3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {const cocos2d::Point&}
 * @param {float}
 */
create : function () {},

};

/**
 * @class Ripple3D
 */
cc.Ripple3D = {

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Ripple3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method setAmplitude
 * @param {float}
 */
setAmplitude : function () {},

/**
 * @method getAmplitude
 * @return A value converted from C/C++ "float"
 */
getAmplitude : function () {},

/**
 * @method setPosition
 * @param {const cocos2d::Point&}
 */
setPosition : function () {},

/**
 * @method getPosition
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getPosition : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Ripple3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {const cocos2d::Point&}
 * @param {float}
 * @param {unsigned int}
 * @param {float}
 */
create : function () {},

};

/**
 * @class Shaky3D
 */
cc.Shaky3D = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Shaky3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Shaky3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {int}
 * @param {bool}
 */
create : function () {},

/**
 * @method Shaky3D
 * @constructor
 */
Shaky3D : function () {},

};

/**
 * @class Liquid
 */
cc.Liquid = {

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Liquid*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method setAmplitude
 * @param {float}
 */
setAmplitude : function () {},

/**
 * @method getAmplitude
 * @return A value converted from C/C++ "float"
 */
getAmplitude : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Liquid*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {unsigned int}
 * @param {float}
 */
create : function () {},

/**
 * @method Liquid
 * @constructor
 */
Liquid : function () {},

};

/**
 * @class Waves
 */
cc.Waves = {

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Waves*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method setAmplitude
 * @param {float}
 */
setAmplitude : function () {},

/**
 * @method getAmplitude
 * @return A value converted from C/C++ "float"
 */
getAmplitude : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Waves*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {unsigned int}
 * @param {float}
 * @param {bool}
 * @param {bool}
 */
create : function () {},

/**
 * @method Waves
 * @constructor
 */
Waves : function () {},

};

/**
 * @class Twirl
 */
cc.Twirl = {

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::Twirl*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method setAmplitude
 * @param {float}
 */
setAmplitude : function () {},

/**
 * @method getAmplitude
 * @return A value converted from C/C++ "float"
 */
getAmplitude : function () {},

/**
 * @method setPosition
 * @param {const cocos2d::Point&}
 */
setPosition : function () {},

/**
 * @method getPosition
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getPosition : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Twirl*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {cocos2d::Point}
 * @param {unsigned int}
 * @param {float}
 */
create : function () {},

/**
 * @method Twirl
 * @constructor
 */
Twirl : function () {},

};

/**
 * @class PageTurn3D
 */
cc.PageTurn3D = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::PageTurn3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::PageTurn3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 */
create : function () {},

};

/**
 * @class ProgressTo
 */
cc.ProgressTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ProgressTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ProgressTo*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ProgressTo*"
 * @param {float}
 * @param {float}
 */
create : function () {},

};

/**
 * @class ProgressFromTo
 */
cc.ProgressFromTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ProgressFromTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ProgressFromTo*"
 */
reverse : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ProgressFromTo*"
 * @param {float}
 * @param {float}
 * @param {float}
 */
create : function () {},

};

/**
 * @class ShakyTiles3D
 */
cc.ShakyTiles3D = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ShakyTiles3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ShakyTiles3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {int}
 * @param {bool}
 */
create : function () {},

};

/**
 * @class ShatteredTiles3D
 */
cc.ShatteredTiles3D = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ShatteredTiles3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ShatteredTiles3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {int}
 * @param {bool}
 */
create : function () {},

};

/**
 * @class ShuffleTiles
 */
cc.ShuffleTiles = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method placeTile
 * @param {const cocos2d::Point&}
 * @param {cocos2d::Tile*}
 */
placeTile : function () {},

/**
 * @method getDelta
 * @return A value converted from C/C++ "cocos2d::Size"
 * @param {const cocos2d::Size&}
 */
getDelta : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ShuffleTiles*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method shuffle
 * @param {unsigned int*}
 * @param {unsigned int}
 */
shuffle : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ShuffleTiles*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {unsigned int}
 */
create : function () {},

};

/**
 * @class FadeOutTRTiles
 */
cc.FadeOutTRTiles = {

/**
 * @method turnOnTile
 * @param {const cocos2d::Point&}
 */
turnOnTile : function () {},

/**
 * @method turnOffTile
 * @param {const cocos2d::Point&}
 */
turnOffTile : function () {},

/**
 * @method transformTile
 * @param {const cocos2d::Point&}
 * @param {float}
 */
transformTile : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FadeOutTRTiles*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method testFunc
 * @return A value converted from C/C++ "float"
 * @param {const cocos2d::Size&}
 * @param {float}
 */
testFunc : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FadeOutTRTiles*"
 * @param {float}
 * @param {const cocos2d::Size&}
 */
create : function () {},

};

/**
 * @class FadeOutBLTiles
 */
cc.FadeOutBLTiles = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FadeOutBLTiles*"
 */
clone : function () {},

/**
 * @method testFunc
 * @return A value converted from C/C++ "float"
 * @param {const cocos2d::Size&}
 * @param {float}
 */
testFunc : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FadeOutBLTiles*"
 * @param {float}
 * @param {const cocos2d::Size&}
 */
create : function () {},

};

/**
 * @class FadeOutUpTiles
 */
cc.FadeOutUpTiles = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FadeOutUpTiles*"
 */
clone : function () {},

/**
 * @method transformTile
 * @param {const cocos2d::Point&}
 * @param {float}
 */
transformTile : function () {},

/**
 * @method testFunc
 * @return A value converted from C/C++ "float"
 * @param {const cocos2d::Size&}
 * @param {float}
 */
testFunc : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FadeOutUpTiles*"
 * @param {float}
 * @param {const cocos2d::Size&}
 */
create : function () {},

};

/**
 * @class FadeOutDownTiles
 */
cc.FadeOutDownTiles = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::FadeOutDownTiles*"
 */
clone : function () {},

/**
 * @method testFunc
 * @return A value converted from C/C++ "float"
 * @param {const cocos2d::Size&}
 * @param {float}
 */
testFunc : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::FadeOutDownTiles*"
 * @param {float}
 * @param {const cocos2d::Size&}
 */
create : function () {},

};

/**
 * @class TurnOffTiles
 */
cc.TurnOffTiles = {

/**
 * @method turnOnTile
 * @param {const cocos2d::Point&}
 */
turnOnTile : function () {},

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method turnOffTile
 * @param {const cocos2d::Point&}
 */
turnOffTile : function () {},

/**
 * @method shuffle
 * @param {unsigned int*}
 * @param {unsigned int}
 */
shuffle : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::TurnOffTiles*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

};

/**
 * @class WavesTiles3D
 */
cc.WavesTiles3D = {

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::WavesTiles3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method setAmplitude
 * @param {float}
 */
setAmplitude : function () {},

/**
 * @method getAmplitude
 * @return A value converted from C/C++ "float"
 */
getAmplitude : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::WavesTiles3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {unsigned int}
 * @param {float}
 */
create : function () {},

};

/**
 * @class JumpTiles3D
 */
cc.JumpTiles3D = {

/**
 * @method setAmplitudeRate
 * @param {float}
 */
setAmplitudeRate : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::JumpTiles3D*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getAmplitudeRate
 * @return A value converted from C/C++ "float"
 */
getAmplitudeRate : function () {},

/**
 * @method setAmplitude
 * @param {float}
 */
setAmplitude : function () {},

/**
 * @method getAmplitude
 * @return A value converted from C/C++ "float"
 */
getAmplitude : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::JumpTiles3D*"
 * @param {float}
 * @param {const cocos2d::Size&}
 * @param {unsigned int}
 * @param {float}
 */
create : function () {},

};

/**
 * @class SplitRows
 */
cc.SplitRows = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::SplitRows*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::SplitRows*"
 * @param {float}
 * @param {unsigned int}
 */
create : function () {},

};

/**
 * @class SplitCols
 */
cc.SplitCols = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::SplitCols*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::SplitCols*"
 * @param {float}
 * @param {unsigned int}
 */
create : function () {},

};

/**
 * @class ActionTween
 */
cc.ActionTween = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::ActionTween*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {const std::string&}
 * @param {float}
 * @param {float}
 */
initWithDuration : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::ActionTween*"
 */
reverse : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ActionTween*"
 * @param {float}
 * @param {const std::string&}
 * @param {float}
 * @param {float}
 */
create : function () {},

};

/**
 * @class CardinalSplineTo
 */
cc.CardinalSplineTo = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::CardinalSplineTo*"
 */
reverse : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {cocos2d::PointArray*}
 * @param {float}
 */
initWithDuration : function () {},

/**
 * @method getPoints
 * @return A value converted from C/C++ "cocos2d::PointArray*"
 */
getPoints : function () {},

/**
 * @method updatePosition
 * @param {cocos2d::Point&}
 */
updatePosition : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::CardinalSplineTo*"
 */
clone : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method CardinalSplineTo
 * @constructor
 */
CardinalSplineTo : function () {},

};

/**
 * @class CardinalSplineBy
 */
cc.CardinalSplineBy = {

/**
 * @method startWithTarget
 * @param {cocos2d::Node*}
 */
startWithTarget : function () {},

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::CardinalSplineBy*"
 */
clone : function () {},

/**
 * @method updatePosition
 * @param {cocos2d::Point&}
 */
updatePosition : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::CardinalSplineBy*"
 */
reverse : function () {},

/**
 * @method CardinalSplineBy
 * @constructor
 */
CardinalSplineBy : function () {},

};

/**
 * @class CatmullRomTo
 */
cc.CatmullRomTo = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::CatmullRomTo*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::CatmullRomTo*"
 */
reverse : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {cocos2d::PointArray*}
 */
initWithDuration : function () {},

};

/**
 * @class CatmullRomBy
 */
cc.CatmullRomBy = {

/**
 * @method clone
 * @return A value converted from C/C++ "cocos2d::CatmullRomBy*"
 */
clone : function () {},

/**
 * @method reverse
 * @return A value converted from C/C++ "cocos2d::CatmullRomBy*"
 */
reverse : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {cocos2d::PointArray*}
 */
initWithDuration : function () {},

};

/**
 * @class AtlasNode
 */
cc.AtlasNode = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method updateAtlasValues
 */
updateAtlasValues : function () {},

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 */
getTexture : function () {},

/**
 * @method setTextureAtlas
 * @param {cocos2d::TextureAtlas*}
 */
setTextureAtlas : function () {},

/**
 * @method getTextureAtlas
 * @return A value converted from C/C++ "cocos2d::TextureAtlas*"
 */
getTextureAtlas : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method getQuadsToDraw
 * @return A value converted from C/C++ "int"
 */
getQuadsToDraw : function () {},

/**
 * @method setTexture
 * @param {cocos2d::Texture2D*}
 */
setTexture : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getColor : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method setQuadsToDraw
 * @param {int}
 */
setQuadsToDraw : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::AtlasNode*"
 * @param {const std::string&}
 * @param {int}
 * @param {int}
 * @param {int}
 */
create : function () {},

};

/**
 * @class DrawNode
 */
cc.DrawNode = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method onDraw
 */
onDraw : function () {},

/**
 * @method clear
 */
clear : function () {},

/**
 * @method drawDot
 * @param {const cocos2d::Point&}
 * @param {float}
 * @param {const cocos2d::Color4F&}
 */
drawDot : function () {},

/**
 * @method drawSegment
 * @param {const cocos2d::Point&}
 * @param {const cocos2d::Point&}
 * @param {float}
 * @param {const cocos2d::Color4F&}
 */
drawSegment : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::DrawNode*"
 */
create : function () {},

};

/**
 * @class Camera
 */
cc.Camera = {

/**
 * @method locate
 */
locate : function () {},

/**
 * @method restore
 */
restore : function () {},

/**
 * @method getEye
 * @param {float*}
 * @param {float*}
 * @param {float*}
 */
getEye : function () {},

/**
 * @method setEye
 * @param {float}
 * @param {float}
 * @param {float}
 */
setEye : function () {},

/**
 * @method setCenter
 * @param {float}
 * @param {float}
 * @param {float}
 */
setCenter : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method getCenter
 * @param {float*}
 * @param {float*}
 * @param {float*}
 */
getCenter : function () {},

/**
 * @method isDirty
 * @return A value converted from C/C++ "bool"
 */
isDirty : function () {},

/**
 * @method init
 */
init : function () {},

/**
 * @method setDirty
 * @param {bool}
 */
setDirty : function () {},

/**
 * @method setUp
 * @param {float}
 * @param {float}
 * @param {float}
 */
setUp : function () {},

/**
 * @method getUp
 * @param {float*}
 * @param {float*}
 * @param {float*}
 */
getUp : function () {},

/**
 * @method getZEye
 * @return A value converted from C/C++ "float"
 */
getZEye : function () {},

/**
 * @method Camera
 * @constructor
 */
Camera : function () {},

};

/**
 * @class LabelAtlas
 */
cc.LabelAtlas = {

/**
 * @method updateAtlasValues
 */
updateAtlasValues : function () {},

/**
 * @method getString
 * @return A value converted from C/C++ "const std::string&"
 */
getString : function () {},

/**
 * @method setString
 * @param {const std::string&}
 */
setString : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method LabelAtlas
 * @constructor
 */
LabelAtlas : function () {},

};

/**
 * @class Director
 */
cc.Director = {

/**
 * @method pause
 */
pause : function () {},

/**
 * @method setNotificationNode
 * @param {cocos2d::Node*}
 */
setNotificationNode : function () {},

/**
 * @method setContentScaleFactor
 * @param {float}
 */
setContentScaleFactor : function () {},

/**
 * @method getContentScaleFactor
 * @return A value converted from C/C++ "float"
 */
getContentScaleFactor : function () {},

/**
 * @method getWinSizeInPixels
 * @return A value converted from C/C++ "cocos2d::Size"
 */
getWinSizeInPixels : function () {},

/**
 * @method getDeltaTime
 * @return A value converted from C/C++ "float"
 */
getDeltaTime : function () {},

/**
 * @method setGLDefaultValues
 */
setGLDefaultValues : function () {},

/**
 * @method setActionManager
 * @param {cocos2d::ActionManager*}
 */
setActionManager : function () {},

/**
 * @method setAlphaBlending
 * @param {bool}
 */
setAlphaBlending : function () {},

/**
 * @method popToRootScene
 */
popToRootScene : function () {},

/**
 * @method getNotificationNode
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getNotificationNode : function () {},

/**
 * @method getWinSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getWinSize : function () {},

/**
 * @method getTextureCache
 * @return A value converted from C/C++ "cocos2d::TextureCache*"
 */
getTextureCache : function () {},

/**
 * @method isSendCleanupToScene
 * @return A value converted from C/C++ "bool"
 */
isSendCleanupToScene : function () {},

/**
 * @method getVisibleOrigin
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getVisibleOrigin : function () {},

/**
 * @method mainLoop
 */
mainLoop : function () {},

/**
 * @method setDepthTest
 * @param {bool}
 */
setDepthTest : function () {},

/**
 * @method getFrameRate
 * @return A value converted from C/C++ "float"
 */
getFrameRate : function () {},

/**
 * @method getSecondsPerFrame
 * @return A value converted from C/C++ "float"
 */
getSecondsPerFrame : function () {},

/**
 * @method convertToUI
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
convertToUI : function () {},

/**
 * @method setDefaultValues
 */
setDefaultValues : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method setScheduler
 * @param {cocos2d::Scheduler*}
 */
setScheduler : function () {},

/**
 * @method startAnimation
 */
startAnimation : function () {},

/**
 * @method getRunningScene
 * @return A value converted from C/C++ "cocos2d::Scene*"
 */
getRunningScene : function () {},

/**
 * @method setViewport
 */
setViewport : function () {},

/**
 * @method stopAnimation
 */
stopAnimation : function () {},

/**
 * @method popToSceneStackLevel
 * @param {int}
 */
popToSceneStackLevel : function () {},

/**
 * @method resume
 */
resume : function () {},

/**
 * @method isNextDeltaTimeZero
 * @return A value converted from C/C++ "bool"
 */
isNextDeltaTimeZero : function () {},

/**
 * @method end
 */
end : function () {},

/**
 * @method setOpenGLView
 * @param {cocos2d::EGLView*}
 */
setOpenGLView : function () {},

/**
 * @method convertToGL
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
convertToGL : function () {},

/**
 * @method purgeCachedData
 */
purgeCachedData : function () {},

/**
 * @method getTotalFrames
 * @return A value converted from C/C++ "unsigned int"
 */
getTotalFrames : function () {},

/**
 * @method runWithScene
 * @param {cocos2d::Scene*}
 */
runWithScene : function () {},

/**
 * @method drawScene
 */
drawScene : function () {},

/**
 * @method popScene
 */
popScene : function () {},

/**
 * @method isDisplayStats
 * @return A value converted from C/C++ "bool"
 */
isDisplayStats : function () {},

/**
 * @method setProjection
 * @param {cocos2d::Director::Projection}
 */
setProjection : function () {},

/**
 * @method getZEye
 * @return A value converted from C/C++ "float"
 */
getZEye : function () {},

/**
 * @method setNextDeltaTimeZero
 * @param {bool}
 */
setNextDeltaTimeZero : function () {},

/**
 * @method getVisibleSize
 * @return A value converted from C/C++ "cocos2d::Size"
 */
getVisibleSize : function () {},

/**
 * @method getScheduler
 * @return A value converted from C/C++ "cocos2d::Scheduler*"
 */
getScheduler : function () {},

/**
 * @method pushScene
 * @param {cocos2d::Scene*}
 */
pushScene : function () {},

/**
 * @method getAnimationInterval
 * @return A value converted from C/C++ "double"
 */
getAnimationInterval : function () {},

/**
 * @method isPaused
 * @return A value converted from C/C++ "bool"
 */
isPaused : function () {},

/**
 * @method setDisplayStats
 * @param {bool}
 */
setDisplayStats : function () {},

/**
 * @method replaceScene
 * @param {cocos2d::Scene*}
 */
replaceScene : function () {},

/**
 * @method setAnimationInterval
 * @param {double}
 */
setAnimationInterval : function () {},

/**
 * @method getActionManager
 * @return A value converted from C/C++ "cocos2d::ActionManager*"
 */
getActionManager : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::Director*"
 */
getInstance : function () {},

};

/**
 * @class GridBase
 */
cc.GridBase = {

/**
 * @method setGridSize
 * @param {const cocos2d::Size&}
 */
setGridSize : function () {},

/**
 * @method calculateVertexPoints
 */
calculateVertexPoints : function () {},

/**
 * @method afterDraw
 * @param {cocos2d::Node*}
 */
afterDraw : function () {},

/**
 * @method beforeDraw
 */
beforeDraw : function () {},

/**
 * @method isTextureFlipped
 * @return A value converted from C/C++ "bool"
 */
isTextureFlipped : function () {},

/**
 * @method getGridSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getGridSize : function () {},

/**
 * @method getStep
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getStep : function () {},

/**
 * @method set2DProjection
 */
set2DProjection : function () {},

/**
 * @method setStep
 * @param {const cocos2d::Point&}
 */
setStep : function () {},

/**
 * @method setTextureFlipped
 * @param {bool}
 */
setTextureFlipped : function () {},

/**
 * @method blit
 */
blit : function () {},

/**
 * @method setActive
 * @param {bool}
 */
setActive : function () {},

/**
 * @method getReuseGrid
 * @return A value converted from C/C++ "int"
 */
getReuseGrid : function () {},

/**
 * @method setReuseGrid
 * @param {int}
 */
setReuseGrid : function () {},

/**
 * @method isActive
 * @return A value converted from C/C++ "bool"
 */
isActive : function () {},

/**
 * @method reuse
 */
reuse : function () {},

};

/**
 * @class Grid3D
 */
cc.Grid3D = {

/**
 * @method calculateVertexPoints
 */
calculateVertexPoints : function () {},

/**
 * @method reuse
 */
reuse : function () {},

/**
 * @method blit
 */
blit : function () {},

/**
 * @method Grid3D
 * @constructor
 */
Grid3D : function () {},

};

/**
 * @class TiledGrid3D
 */
cc.TiledGrid3D = {

/**
 * @method calculateVertexPoints
 */
calculateVertexPoints : function () {},

/**
 * @method reuse
 */
reuse : function () {},

/**
 * @method blit
 */
blit : function () {},

/**
 * @method TiledGrid3D
 * @constructor
 */
TiledGrid3D : function () {},

};

/**
 * @class Sprite
 */
cc.Sprite = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 */
getTexture : function () {},

/**
 * @method setRotationY
 * @param {float}
 */
setRotationY : function () {},

/**
 * @method setFlippedY
 * @param {bool}
 */
setFlippedY : function () {},

/**
 * @method setFlippedX
 * @param {bool}
 */
setFlippedX : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method setRotationX
 * @param {float}
 */
setRotationX : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method setScaleX
 * @param {float}
 */
setScaleX : function () {},

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method getBatchNode
 * @return A value converted from C/C++ "cocos2d::SpriteBatchNode*"
 */
getBatchNode : function () {},

/**
 * @method getOffsetPosition
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getOffsetPosition : function () {},

/**
 * @method removeAllChildrenWithCleanup
 * @param {bool}
 */
removeAllChildrenWithCleanup : function () {},

/**
 * @method updateQuadVertices
 */
updateQuadVertices : function () {},

/**
 * @method updateTransform
 */
updateTransform : function () {},

/**
 * @method setVertexZ
 * @param {float}
 */
setVertexZ : function () {},

/**
 * @method reorderChild
 * @param {cocos2d::Node*}
 * @param {int}
 */
reorderChild : function () {},

/**
 * @method isFrameDisplayed
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::SpriteFrame*}
 */
isFrameDisplayed : function () {},

/**
 * @method getAtlasIndex
 * @return A value converted from C/C++ "ssize_t"
 */
getAtlasIndex : function () {},

/**
 * @method setRotation
 * @param {float}
 */
setRotation : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {GLubyte}
 */
updateDisplayedOpacity : function () {},

/**
 * @method setBatchNode
 * @param {cocos2d::SpriteBatchNode*}
 */
setBatchNode : function () {},

/**
 * @method setScaleY
 * @param {float}
 */
setScaleY : function () {},

/**
 * @method setDisplayFrameWithAnimationName
 * @param {const std::string&}
 * @param {ssize_t}
 */
setDisplayFrameWithAnimationName : function () {},

/**
 * @method setTextureAtlas
 * @param {cocos2d::TextureAtlas*}
 */
setTextureAtlas : function () {},

/**
 * @method getSpriteFrame
 * @return A value converted from C/C++ "cocos2d::SpriteFrame*"
 */
getSpriteFrame : function () {},

/**
 * @method isDirty
 * @return A value converted from C/C++ "bool"
 */
isDirty : function () {},

/**
 * @method setAtlasIndex
 * @param {ssize_t}
 */
setAtlasIndex : function () {},

/**
 * @method updateDisplayedColor
 * @param {const cocos2d::Color3B&}
 */
updateDisplayedColor : function () {},

/**
 * @method setDirty
 * @param {bool}
 */
setDirty : function () {},

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method isTextureRectRotated
 * @return A value converted from C/C++ "bool"
 */
isTextureRectRotated : function () {},

/**
 * @method sortAllChildren
 */
sortAllChildren : function () {},

/**
 * @method getTextureRect
 * @return A value converted from C/C++ "const cocos2d::Rect&"
 */
getTextureRect : function () {},

/**
 * @method ignoreAnchorPointForPosition
 * @param {bool}
 */
ignoreAnchorPointForPosition : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method getTextureAtlas
 * @return A value converted from C/C++ "cocos2d::TextureAtlas*"
 */
getTextureAtlas : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method isFlippedX
 * @return A value converted from C/C++ "bool"
 */
isFlippedX : function () {},

/**
 * @method isFlippedY
 * @return A value converted from C/C++ "bool"
 */
isFlippedY : function () {},

/**
 * @method setVertexRect
 * @param {const cocos2d::Rect&}
 */
setVertexRect : function () {},

/**
 * @method setSkewX
 * @param {float}
 */
setSkewX : function () {},

/**
 * @method setSkewY
 * @param {float}
 */
setSkewY : function () {},

/**
 * @method setVisible
 * @param {bool}
 */
setVisible : function () {},

/**
 * @method createWithSpriteFrameName
 * @return A value converted from C/C++ "cocos2d::Sprite*"
 * @param {const std::string&}
 */
createWithSpriteFrameName : function () {},

/**
 * @method createWithSpriteFrame
 * @return A value converted from C/C++ "cocos2d::Sprite*"
 * @param {cocos2d::SpriteFrame*}
 */
createWithSpriteFrame : function () {},

};

/**
 * @class NewSprite
 */
cc.NewSprite = {

/**
 * @method updateQuadVertices
 */
updateQuadVertices : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method culling
 * @return A value converted from C/C++ "bool"
 */
culling : function () {},

};

/**
 * @class LabelTTF
 */
cc.LabelTTF = {

/**
 * @method enableShadow
 * @param {const cocos2d::Size&}
 * @param {float}
 * @param {float}
 * @param {bool}
 */
enableShadow : function () {},

/**
 * @method setDimensions
 * @param {const cocos2d::Size&}
 */
setDimensions : function () {},

/**
 * @method getFontSize
 * @return A value converted from C/C++ "float"
 */
getFontSize : function () {},

/**
 * @method getString
 * @return A value converted from C/C++ "const std::string&"
 */
getString : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method setTextDefinition
 * @param {const cocos2d::FontDefinition&}
 */
setTextDefinition : function () {},

/**
 * @method setFontName
 * @param {const std::string&}
 */
setFontName : function () {},

/**
 * @method getHorizontalAlignment
 * @return A value converted from C/C++ "cocos2d::TextHAlignment"
 */
getHorizontalAlignment : function () {},

/**
 * @method initWithStringAndTextDefinition
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 * @param {cocos2d::FontDefinition&}
 */
initWithStringAndTextDefinition : function () {},

/**
 * @method setString
 * @param {const std::string&}
 */
setString : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method setFontFillColor
 * @param {const cocos2d::Color3B&}
 * @param {bool}
 */
setFontFillColor : function () {},

/**
 * @method enableStroke
 * @param {const cocos2d::Color3B&}
 * @param {float}
 * @param {bool}
 */
enableStroke : function () {},

/**
 * @method getDimensions
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getDimensions : function () {},

/**
 * @method setVerticalAlignment
 * @param {cocos2d::TextVAlignment}
 */
setVerticalAlignment : function () {},

/**
 * @method setFontSize
 * @param {float}
 */
setFontSize : function () {},

/**
 * @method getVerticalAlignment
 * @return A value converted from C/C++ "cocos2d::TextVAlignment"
 */
getVerticalAlignment : function () {},

/**
 * @method getTextDefinition
 * @return A value converted from C/C++ "cocos2d::FontDefinition"
 */
getTextDefinition : function () {},

/**
 * @method getFontName
 * @return A value converted from C/C++ "const std::string&"
 */
getFontName : function () {},

/**
 * @method setHorizontalAlignment
 * @param {cocos2d::TextHAlignment}
 */
setHorizontalAlignment : function () {},

/**
 * @method disableShadow
 */
disableShadow : function () {},

/**
 * @method disableStroke
 */
disableStroke : function () {},

/**
 * @method createWithFontDefinition
 * @return A value converted from C/C++ "cocos2d::LabelTTF*"
 * @param {const std::string&}
 * @param {cocos2d::FontDefinition&}
 */
createWithFontDefinition : function () {},

/**
 * @method LabelTTF
 * @constructor
 */
LabelTTF : function () {},

};

/**
 * @class SpriteBatchNode
 */
cc.SpriteBatchNode = {

/**
 * @method appendChild
 * @param {cocos2d::Sprite*}
 */
appendChild : function () {},

/**
 * @method reorderBatch
 * @param {bool}
 */
reorderBatch : function () {},

/**
 * @method visit
 */
visit : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method setTexture
 * @param {cocos2d::Texture2D*}
 */
setTexture : function () {},

/**
 * @method removeChildAtIndex
 * @param {ssize_t}
 * @param {bool}
 */
removeChildAtIndex : function () {},

/**
 * @method removeSpriteFromAtlas
 * @param {cocos2d::Sprite*}
 */
removeSpriteFromAtlas : function () {},

/**
 * @method atlasIndexForChild
 * @return A value converted from C/C++ "ssize_t"
 * @param {cocos2d::Sprite*}
 * @param {int}
 */
atlasIndexForChild : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 */
getTexture : function () {},

/**
 * @method increaseAtlasCapacity
 */
increaseAtlasCapacity : function () {},

/**
 * @method lowestAtlasIndexInChild
 * @return A value converted from C/C++ "ssize_t"
 * @param {cocos2d::Sprite*}
 */
lowestAtlasIndexInChild : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method initWithTexture
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::Texture2D*}
 * @param {ssize_t}
 */
initWithTexture : function () {},

/**
 * @method setTextureAtlas
 * @param {cocos2d::TextureAtlas*}
 */
setTextureAtlas : function () {},

/**
 * @method removeAllChildrenWithCleanup
 * @param {bool}
 */
removeAllChildrenWithCleanup : function () {},

/**
 * @method sortAllChildren
 */
sortAllChildren : function () {},

/**
 * @method reorderChild
 * @param {cocos2d::Node*}
 * @param {int}
 */
reorderChild : function () {},

/**
 * @method rebuildIndexInOrder
 * @return A value converted from C/C++ "ssize_t"
 * @param {cocos2d::Sprite*}
 * @param {ssize_t}
 */
rebuildIndexInOrder : function () {},

/**
 * @method getTextureAtlas
 * @return A value converted from C/C++ "cocos2d::TextureAtlas*"
 */
getTextureAtlas : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method highestAtlasIndexInChild
 * @return A value converted from C/C++ "ssize_t"
 * @param {cocos2d::Sprite*}
 */
highestAtlasIndexInChild : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::SpriteBatchNode*"
 * @param {const char*}
 * @param {ssize_t}
 */
create : function () {},

/**
 * @method createWithTexture
 * @return A value converted from C/C++ "cocos2d::SpriteBatchNode*"
 * @param {cocos2d::Texture2D*}
 * @param {ssize_t}
 */
createWithTexture : function () {},

/**
 * @method SpriteBatchNode
 * @constructor
 */
SpriteBatchNode : function () {},

};

/**
 * @class NewSpriteBatchNode
 */
cc.NewSpriteBatchNode = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::NewSpriteBatchNode*"
 * @param {const char*}
 * @param {long}
 */
create : function () {},

/**
 * @method createWithTexture
 * @return A value converted from C/C++ "cocos2d::NewSpriteBatchNode*"
 * @param {cocos2d::Texture2D*}
 * @param {int}
 */
createWithTexture : function () {},

};

/**
 * @class LabelBMFont
 */
cc.LabelBMFont = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method createFontChars
 */
createFontChars : function () {},

/**
 * @method getString
 * @return A value converted from C/C++ "const std::string&"
 */
getString : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method setScale
 * @param {float}
 */
setScale : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method getFntFile
 * @return A value converted from C/C++ "const std::string&"
 */
getFntFile : function () {},

/**
 * @method updateLabel
 */
updateLabel : function () {},

/**
 * @method setWidth
 * @param {float}
 */
setWidth : function () {},

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method initWithString
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 * @param {const std::string&}
 * @param {float}
 * @param {cocos2d::TextHAlignment}
 * @param {cocos2d::Point}
 */
initWithString : function () {},

/**
 * @method setCascadeColorEnabled
 * @param {bool}
 */
setCascadeColorEnabled : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {GLubyte}
 */
updateDisplayedOpacity : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method setFntFile
 * @param {const std::string&}
 */
setFntFile : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getOpacity : function () {},

/**
 * @method setLineBreakWithoutSpace
 * @param {bool}
 */
setLineBreakWithoutSpace : function () {},

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
 * @method getColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getColor : function () {},

/**
 * @method getDisplayedOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getDisplayedOpacity : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method setCString
 * @param {const char*}
 */
setCString : function () {},

/**
 * @method getDisplayedColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getDisplayedColor : function () {},

/**
 * @method updateDisplayedColor
 * @param {const cocos2d::Color3B&}
 */
updateDisplayedColor : function () {},

/**
 * @method setAlignment
 * @param {cocos2d::TextHAlignment}
 */
setAlignment : function () {},

/**
 * @method purgeCachedData
 */
purgeCachedData : function () {},

/**
 * @method LabelBMFont
 * @constructor
 */
LabelBMFont : function () {},

};

/**
 * @class Label
 */
cc.Label = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method addChild
 * @param {cocos2d::Node*}
 * @param {int}
 * @param {int}
 */
addChild : function () {},

/**
 * @method getString
 * @return A value converted from C/C++ "const std::string&"
 */
getString : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method getXOffsetForChar
 * @return A value converted from C/C++ "int"
 * @param {unsigned short}
 */
getXOffsetForChar : function () {},

/**
 * @method setScale
 * @param {float}
 */
setScale : function () {},

/**
 * @method setLabelEffect
 * @param {cocos2d::LabelEffect}
 * @param {const cocos2d::Color3B&}
 */
setLabelEffect : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method getLetterPosXRight
 * @return A value converted from C/C++ "float"
 * @param {int}
 */
getLetterPosXRight : function () {},

/**
 * @method getCommonLineHeight
 * @return A value converted from C/C++ "int"
 */
getCommonLineHeight : function () {},

/**
 * @method getLabelContentSize
 * @return A value converted from C/C++ "cocos2d::Size"
 */
getLabelContentSize : function () {},

/**
 * @method breakLineWithoutSpace
 * @return A value converted from C/C++ "bool"
 */
breakLineWithoutSpace : function () {},

/**
 * @method setWidth
 * @param {float}
 */
setWidth : function () {},

/**
 * @method getStringLenght
 * @return A value converted from C/C++ "int"
 */
getStringLenght : function () {},

/**
 * @method getMaxLineWidth
 * @return A value converted from C/C++ "float"
 */
getMaxLineWidth : function () {},

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method getRectForChar
 * @return A value converted from C/C++ "cocos2d::Rect"
 * @param {unsigned short}
 */
getRectForChar : function () {},

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
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method getYOffsetForChar
 * @return A value converted from C/C++ "int"
 * @param {unsigned short}
 */
getYOffsetForChar : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {GLubyte}
 */
updateDisplayedOpacity : function () {},

/**
 * @method recordPlaceholderInfo
 * @return A value converted from C/C++ "bool"
 * @param {int}
 */
recordPlaceholderInfo : function () {},

/**
 * @method getLetterPosXLeft
 * @return A value converted from C/C++ "float"
 * @param {int}
 */
getLetterPosXLeft : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getOpacity : function () {},

/**
 * @method getStringNumLines
 * @return A value converted from C/C++ "int"
 */
getStringNumLines : function () {},

/**
 * @method setLineBreakWithoutSpace
 * @param {bool}
 */
setLineBreakWithoutSpace : function () {},

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
 * @method getCharAtStringPosition
 * @return A value converted from C/C++ "unsigned short"
 * @param {int}
 */
getCharAtStringPosition : function () {},

/**
 * @method getAdvanceForChar
 * @return A value converted from C/C++ "int"
 * @param {unsigned short}
 * @param {int}
 */
getAdvanceForChar : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getColor : function () {},

/**
 * @method getDisplayedOpacity
 * @return A value converted from C/C++ "unsigned char"
 */
getDisplayedOpacity : function () {},

/**
 * @method getUTF8String
 * @return A value converted from C/C++ "unsigned short*"
 */
getUTF8String : function () {},

/**
 * @method getKerningForCharsPair
 * @return A value converted from C/C++ "int"
 * @param {unsigned short}
 * @param {unsigned short}
 */
getKerningForCharsPair : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method getLetter
 * @return A value converted from C/C++ "cocos2d::Sprite*"
 * @param {int}
 */
getLetter : function () {},

/**
 * @method setLabelContentSize
 * @param {const cocos2d::Size&}
 */
setLabelContentSize : function () {},

/**
 * @method assignNewUTF8String
 * @param {unsigned short*}
 */
assignNewUTF8String : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method getDisplayedColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getDisplayedColor : function () {},

/**
 * @method setText
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 * @param {float}
 * @param {cocos2d::TextHAlignment}
 * @param {bool}
 */
setText : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method getTextAlignment
 * @return A value converted from C/C++ "cocos2d::TextHAlignment"
 */
getTextAlignment : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method updateDisplayedColor
 * @param {const cocos2d::Color3B&}
 */
updateDisplayedColor : function () {},

/**
 * @method setAlignment
 * @param {cocos2d::TextHAlignment}
 */
setAlignment : function () {},

/**
 * @method recordLetterInfo
 * @return A value converted from C/C++ "bool"
 * @param {const cocos2d::Point&}
 * @param {unsigned short}
 * @param {int}
 */
recordLetterInfo : function () {},

/**
 * @method createWithBMFont
 * @return A value converted from C/C++ "cocos2d::Label*"
 * @param {const std::string&}
 * @param {const std::string&}
 * @param {cocos2d::TextHAlignment}
 * @param {int}
 */
createWithBMFont : function () {},

/**
 * @method createWithTTF
 * @return A value converted from C/C++ "cocos2d::Label*"
 * @param {const std::string&}
 * @param {const std::string&}
 * @param {int}
 * @param {int}
 * @param {cocos2d::TextHAlignment}
 * @param {cocos2d::GlyphCollection}
 * @param {const char*}
 * @param {bool}
 */
createWithTTF : function () {},

};

/**
 * @class Layer
 */
cc.Layer = {

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Layer*"
 */
create : function () {},

};

/**
 * @class LayerRGBA
 */
cc.LayerRGBA = {

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method isCascadeOpacityEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeOpacityEnabled : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getColor : function () {},

/**
 * @method getDisplayedOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getDisplayedOpacity : function () {},

/**
 * @method setCascadeColorEnabled
 * @param {bool}
 */
setCascadeColorEnabled : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method setCascadeOpacityEnabled
 * @param {bool}
 */
setCascadeOpacityEnabled : function () {},

/**
 * @method updateDisplayedOpacity
 * @param {GLubyte}
 */
updateDisplayedOpacity : function () {},

/**
 * @method isCascadeColorEnabled
 * @return A value converted from C/C++ "bool"
 */
isCascadeColorEnabled : function () {},

/**
 * @method updateDisplayedColor
 * @param {const cocos2d::Color3B&}
 */
updateDisplayedColor : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getOpacity : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method getDisplayedColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getDisplayedColor : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::LayerRGBA*"
 */
create : function () {},

};

/**
 * @class LayerColor
 */
cc.LayerColor = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method onDraw
 */
onDraw : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method changeWidthAndHeight
 * @param {GLfloat}
 * @param {GLfloat}
 */
changeWidthAndHeight : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method changeWidth
 * @param {GLfloat}
 */
changeWidth : function () {},

/**
 * @method setContentSize
 * @param {const cocos2d::Size&}
 */
setContentSize : function () {},

/**
 * @method changeHeight
 * @param {GLfloat}
 */
changeHeight : function () {},

};

/**
 * @class LayerGradient
 */
cc.LayerGradient = {

/**
 * @method getStartColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getStartColor : function () {},

/**
 * @method isCompressedInterpolation
 * @return A value converted from C/C++ "bool"
 */
isCompressedInterpolation : function () {},

/**
 * @method getStartOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getStartOpacity : function () {},

/**
 * @method setVector
 * @param {const cocos2d::Point&}
 */
setVector : function () {},

/**
 * @method setStartOpacity
 * @param {GLubyte}
 */
setStartOpacity : function () {},

/**
 * @method setCompressedInterpolation
 * @param {bool}
 */
setCompressedInterpolation : function () {},

/**
 * @method setEndOpacity
 * @param {GLubyte}
 */
setEndOpacity : function () {},

/**
 * @method getVector
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getVector : function () {},

/**
 * @method setEndColor
 * @param {const cocos2d::Color3B&}
 */
setEndColor : function () {},

/**
 * @method getEndColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getEndColor : function () {},

/**
 * @method getEndOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getEndOpacity : function () {},

/**
 * @method setStartColor
 * @param {const cocos2d::Color3B&}
 */
setStartColor : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

};

/**
 * @class LayerMultiplex
 */
cc.LayerMultiplex = {

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method switchToAndReleaseMe
 * @param {int}
 */
switchToAndReleaseMe : function () {},

/**
 * @method addLayer
 * @param {cocos2d::Layer*}
 */
addLayer : function () {},

/**
 * @method switchTo
 * @param {int}
 */
switchTo : function () {},

};

/**
 * @class Scene
 */
cc.Scene = {

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getPhysicsWorld
 * @return A value converted from C/C++ "cocos2d::PhysicsWorld*"
 */
getPhysicsWorld : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::Scene*"
 */
create : function () {},

/**
 * @method createWithPhysics
 * @return A value converted from C/C++ "cocos2d::Scene*"
 */
createWithPhysics : function () {},

};

/**
 * @class TransitionEaseScene
 */
cc.TransitionEaseScene = {

/**
 * @method easeActionWithAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {cocos2d::ActionInterval*}
 */
easeActionWithAction : function () {},

};

/**
 * @class TransitionScene
 */
cc.TransitionScene = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method finish
 */
finish : function () {},

/**
 * @method cleanup
 */
cleanup : function () {},

/**
 * @method hideOutShowIn
 */
hideOutShowIn : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionScene*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionSceneOriented
 */
cc.TransitionSceneOriented = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionSceneOriented*"
 * @param {float}
 * @param {cocos2d::Scene*}
 * @param {cocos2d::TransitionScene::Orientation}
 */
create : function () {},

};

/**
 * @class TransitionRotoZoom
 */
cc.TransitionRotoZoom = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionRotoZoom*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionJumpZoom
 */
cc.TransitionJumpZoom = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionJumpZoom*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionMoveInL
 */
cc.TransitionMoveInL = {

/**
 * @method action
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
action : function () {},

/**
 * @method easeActionWithAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {cocos2d::ActionInterval*}
 */
easeActionWithAction : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionMoveInL*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionMoveInR
 */
cc.TransitionMoveInR = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionMoveInR*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionMoveInT
 */
cc.TransitionMoveInT = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionMoveInT*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionMoveInB
 */
cc.TransitionMoveInB = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionMoveInB*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionSlideInL
 */
cc.TransitionSlideInL = {

/**
 * @method action
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
action : function () {},

/**
 * @method easeActionWithAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {cocos2d::ActionInterval*}
 */
easeActionWithAction : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionSlideInL*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionSlideInR
 */
cc.TransitionSlideInR = {

/**
 * @method action
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
action : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionSlideInR*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionSlideInB
 */
cc.TransitionSlideInB = {

/**
 * @method action
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
action : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionSlideInB*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionSlideInT
 */
cc.TransitionSlideInT = {

/**
 * @method action
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
action : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionSlideInT*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionShrinkGrow
 */
cc.TransitionShrinkGrow = {

/**
 * @method easeActionWithAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {cocos2d::ActionInterval*}
 */
easeActionWithAction : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionShrinkGrow*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionFlipX
 */
cc.TransitionFlipX = {

};

/**
 * @class TransitionFlipY
 */
cc.TransitionFlipY = {

};

/**
 * @class TransitionFlipAngular
 */
cc.TransitionFlipAngular = {

};

/**
 * @class TransitionZoomFlipX
 */
cc.TransitionZoomFlipX = {

};

/**
 * @class TransitionZoomFlipY
 */
cc.TransitionZoomFlipY = {

};

/**
 * @class TransitionZoomFlipAngular
 */
cc.TransitionZoomFlipAngular = {

};

/**
 * @class TransitionFade
 */
cc.TransitionFade = {

};

/**
 * @class TransitionCrossFade
 */
cc.TransitionCrossFade = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionCrossFade*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionTurnOffTiles
 */
cc.TransitionTurnOffTiles = {

/**
 * @method easeActionWithAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {cocos2d::ActionInterval*}
 */
easeActionWithAction : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionTurnOffTiles*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionSplitCols
 */
cc.TransitionSplitCols = {

/**
 * @method action
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
action : function () {},

/**
 * @method easeActionWithAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {cocos2d::ActionInterval*}
 */
easeActionWithAction : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionSplitCols*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionSplitRows
 */
cc.TransitionSplitRows = {

/**
 * @method action
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 */
action : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionSplitRows*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionFadeTR
 */
cc.TransitionFadeTR = {

/**
 * @method easeActionWithAction
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {cocos2d::ActionInterval*}
 */
easeActionWithAction : function () {},

/**
 * @method actionWithSize
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {const cocos2d::Size&}
 */
actionWithSize : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionFadeTR*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionFadeBL
 */
cc.TransitionFadeBL = {

/**
 * @method actionWithSize
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {const cocos2d::Size&}
 */
actionWithSize : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionFadeBL*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionFadeUp
 */
cc.TransitionFadeUp = {

/**
 * @method actionWithSize
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {const cocos2d::Size&}
 */
actionWithSize : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionFadeUp*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionFadeDown
 */
cc.TransitionFadeDown = {

/**
 * @method actionWithSize
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {const cocos2d::Size&}
 */
actionWithSize : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionFadeDown*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionPageTurn
 */
cc.TransitionPageTurn = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method actionWithSize
 * @return A value converted from C/C++ "cocos2d::ActionInterval*"
 * @param {const cocos2d::Size&}
 */
actionWithSize : function () {},

/**
 * @method initWithDuration
 * @return A value converted from C/C++ "bool"
 * @param {float}
 * @param {cocos2d::Scene*}
 * @param {bool}
 */
initWithDuration : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionPageTurn*"
 * @param {float}
 * @param {cocos2d::Scene*}
 * @param {bool}
 */
create : function () {},

/**
 * @method TransitionPageTurn
 * @constructor
 */
TransitionPageTurn : function () {},

};

/**
 * @class TransitionProgress
 */
cc.TransitionProgress = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionProgress*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

/**
 * @method TransitionProgress
 * @constructor
 */
TransitionProgress : function () {},

};

/**
 * @class TransitionProgressRadialCCW
 */
cc.TransitionProgressRadialCCW = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionProgressRadialCCW*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionProgressRadialCW
 */
cc.TransitionProgressRadialCW = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionProgressRadialCW*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionProgressHorizontal
 */
cc.TransitionProgressHorizontal = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionProgressHorizontal*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionProgressVertical
 */
cc.TransitionProgressVertical = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionProgressVertical*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionProgressInOut
 */
cc.TransitionProgressInOut = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionProgressInOut*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class TransitionProgressOutIn
 */
cc.TransitionProgressOutIn = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TransitionProgressOutIn*"
 * @param {float}
 * @param {cocos2d::Scene*}
 */
create : function () {},

};

/**
 * @class MenuItem
 */
cc.MenuItem = {

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method activate
 */
activate : function () {},

/**
 * @method isEnabled
 * @return A value converted from C/C++ "bool"
 */
isEnabled : function () {},

/**
 * @method selected
 */
selected : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method isSelected
 * @return A value converted from C/C++ "bool"
 */
isSelected : function () {},

/**
 * @method unselected
 */
unselected : function () {},

/**
 * @method rect
 * @return A value converted from C/C++ "cocos2d::Rect"
 */
rect : function () {},

};

/**
 * @class MenuItemLabel
 */
cc.MenuItemLabel = {

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method setLabel
 * @param {cocos2d::Node*}
 */
setLabel : function () {},

/**
 * @method activate
 */
activate : function () {},

/**
 * @method getDisabledColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getDisabledColor : function () {},

/**
 * @method setString
 * @param {const std::string&}
 */
setString : function () {},

/**
 * @method selected
 */
selected : function () {},

/**
 * @method setDisabledColor
 * @param {const cocos2d::Color3B&}
 */
setDisabledColor : function () {},

/**
 * @method getLabel
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getLabel : function () {},

/**
 * @method unselected
 */
unselected : function () {},

};

/**
 * @class MenuItemAtlasFont
 */
cc.MenuItemAtlasFont = {

};

/**
 * @class MenuItemFont
 */
cc.MenuItemFont = {

/**
 * @method getFontSizeObj
 * @return A value converted from C/C++ "int"
 */
getFontSizeObj : function () {},

/**
 * @method getFontNameObj
 * @return A value converted from C/C++ "const std::string&"
 */
getFontNameObj : function () {},

/**
 * @method setFontSizeObj
 * @param {int}
 */
setFontSizeObj : function () {},

/**
 * @method setFontNameObj
 * @param {const std::string&}
 */
setFontNameObj : function () {},

/**
 * @method setFontName
 * @param {const std::string&}
 */
setFontName : function () {},

/**
 * @method getFontSize
 * @return A value converted from C/C++ "int"
 */
getFontSize : function () {},

/**
 * @method getFontName
 * @return A value converted from C/C++ "const std::string&"
 */
getFontName : function () {},

/**
 * @method setFontSize
 * @param {int}
 */
setFontSize : function () {},

};

/**
 * @class MenuItemSprite
 */
cc.MenuItemSprite = {

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method selected
 */
selected : function () {},

/**
 * @method setNormalImage
 * @param {cocos2d::Node*}
 */
setNormalImage : function () {},

/**
 * @method setDisabledImage
 * @param {cocos2d::Node*}
 */
setDisabledImage : function () {},

/**
 * @method setSelectedImage
 * @param {cocos2d::Node*}
 */
setSelectedImage : function () {},

/**
 * @method getDisabledImage
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getDisabledImage : function () {},

/**
 * @method getSelectedImage
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getSelectedImage : function () {},

/**
 * @method getNormalImage
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getNormalImage : function () {},

/**
 * @method unselected
 */
unselected : function () {},

};

/**
 * @class MenuItemImage
 */
cc.MenuItemImage = {

/**
 * @method setDisabledSpriteFrame
 * @param {cocos2d::SpriteFrame*}
 */
setDisabledSpriteFrame : function () {},

/**
 * @method setSelectedSpriteFrame
 * @param {cocos2d::SpriteFrame*}
 */
setSelectedSpriteFrame : function () {},

/**
 * @method setNormalSpriteFrame
 * @param {cocos2d::SpriteFrame*}
 */
setNormalSpriteFrame : function () {},

};

/**
 * @class MenuItemToggle
 */
cc.MenuItemToggle = {

/**
 * @method setSubItems
 * @param {const cocos2d::Vector<cocos2d::MenuItem *>&}
 */
setSubItems : function () {},

/**
 * @method activate
 */
activate : function () {},

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method getSelectedIndex
 * @return A value converted from C/C++ "unsigned int"
 */
getSelectedIndex : function () {},

/**
 * @method addSubItem
 * @param {cocos2d::MenuItem*}
 */
addSubItem : function () {},

/**
 * @method selected
 */
selected : function () {},

/**
 * @method unselected
 */
unselected : function () {},

/**
 * @method getSelectedItem
 * @return A value converted from C/C++ "cocos2d::MenuItem*"
 */
getSelectedItem : function () {},

/**
 * @method setSelectedIndex
 * @param {unsigned int}
 */
setSelectedIndex : function () {},

};

/**
 * @class Menu
 */
cc.Menu = {

/**
 * @method setEnabled
 * @param {bool}
 */
setEnabled : function () {},

/**
 * @method alignItemsVertically
 */
alignItemsVertically : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method isEnabled
 * @return A value converted from C/C++ "bool"
 */
isEnabled : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method alignItemsHorizontally
 */
alignItemsHorizontally : function () {},

/**
 * @method alignItemsHorizontallyWithPadding
 * @param {float}
 */
alignItemsHorizontallyWithPadding : function () {},

/**
 * @method alignItemsVerticallyWithPadding
 * @param {float}
 */
alignItemsVerticallyWithPadding : function () {},

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

};

/**
 * @class ClippingNode
 */
cc.ClippingNode = {

/**
 * @method isInverted
 * @return A value converted from C/C++ "bool"
 */
isInverted : function () {},

/**
 * @method visit
 */
visit : function () {},

/**
 * @method setInverted
 * @param {bool}
 */
setInverted : function () {},

/**
 * @method setStencil
 * @param {cocos2d::Node*}
 */
setStencil : function () {},

/**
 * @method getAlphaThreshold
 * @return A value converted from C/C++ "GLfloat"
 */
getAlphaThreshold : function () {},

/**
 * @method getStencil
 * @return A value converted from C/C++ "cocos2d::Node*"
 */
getStencil : function () {},

/**
 * @method setAlphaThreshold
 * @param {GLfloat}
 */
setAlphaThreshold : function () {},

};

/**
 * @class MotionStreak
 */
cc.MotionStreak = {

/**
 * @method reset
 */
reset : function () {},

/**
 * @method setTexture
 * @param {cocos2d::Texture2D*}
 */
setTexture : function () {},

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 */
getTexture : function () {},

/**
 * @method tintWithColor
 * @param {const cocos2d::Color3B&}
 */
tintWithColor : function () {},

/**
 * @method setStartingPositionInitialized
 * @param {bool}
 */
setStartingPositionInitialized : function () {},

/**
 * @method isStartingPositionInitialized
 * @return A value converted from C/C++ "bool"
 */
isStartingPositionInitialized : function () {},

/**
 * @method isFastMode
 * @return A value converted from C/C++ "bool"
 */
isFastMode : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getOpacity : function () {},

/**
 * @method setPosition
 * @param {const cocos2d::Point&}
 */
setPosition : function () {},

/**
 * @method setFastMode
 * @param {bool}
 */
setFastMode : function () {},

};

/**
 * @class ProgressTimer
 */
cc.ProgressTimer = {

/**
 * @method setAnchorPoint
 * @param {const cocos2d::Point&}
 */
setAnchorPoint : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method isReverseDirection
 * @return A value converted from C/C++ "bool"
 */
isReverseDirection : function () {},

/**
 * @method setBarChangeRate
 * @param {const cocos2d::Point&}
 */
setBarChangeRate : function () {},

/**
 * @method getPercentage
 * @return A value converted from C/C++ "float"
 */
getPercentage : function () {},

/**
 * @method setSprite
 * @param {cocos2d::Sprite*}
 */
setSprite : function () {},

/**
 * @method getType
 * @return A value converted from C/C++ "cocos2d::ProgressTimer::Type"
 */
getType : function () {},

/**
 * @method getOpacity
 * @return A value converted from C/C++ "GLubyte"
 */
getOpacity : function () {},

/**
 * @method setOpacity
 * @param {GLubyte}
 */
setOpacity : function () {},

/**
 * @method getSprite
 * @return A value converted from C/C++ "cocos2d::Sprite*"
 */
getSprite : function () {},

/**
 * @method setMidpoint
 * @param {const cocos2d::Point&}
 */
setMidpoint : function () {},

/**
 * @method getColor
 * @return A value converted from C/C++ "const cocos2d::Color3B&"
 */
getColor : function () {},

/**
 * @method getBarChangeRate
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getBarChangeRate : function () {},

/**
 * @method getMidpoint
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getMidpoint : function () {},

/**
 * @method setColor
 * @param {const cocos2d::Color3B&}
 */
setColor : function () {},

/**
 * @method setPercentage
 * @param {float}
 */
setPercentage : function () {},

/**
 * @method setType
 * @param {cocos2d::ProgressTimer::Type}
 */
setType : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ProgressTimer*"
 * @param {cocos2d::Sprite*}
 */
create : function () {},

};

/**
 * @class Image
 */
cc.Image = {

/**
 * @method hasPremultipliedAlpha
 * @return A value converted from C/C++ "bool"
 */
hasPremultipliedAlpha : function () {},

/**
 * @method getDataLen
 * @return A value converted from C/C++ "ssize_t"
 */
getDataLen : function () {},

/**
 * @method isCompressed
 * @return A value converted from C/C++ "bool"
 */
isCompressed : function () {},

/**
 * @method getBitPerPixel
 * @return A value converted from C/C++ "int"
 */
getBitPerPixel : function () {},

/**
 * @method hasAlpha
 * @return A value converted from C/C++ "bool"
 */
hasAlpha : function () {},

/**
 * @method getHeight
 * @return A value converted from C/C++ "int"
 */
getHeight : function () {},

/**
 * @method initWithImageFile
 * @return A value converted from C/C++ "bool"
 * @param {const char*}
 */
initWithImageFile : function () {},

/**
 * @method getWidth
 * @return A value converted from C/C++ "int"
 */
getWidth : function () {},

/**
 * @method isPremultipliedAlpha
 * @return A value converted from C/C++ "bool"
 */
isPremultipliedAlpha : function () {},

/**
 * @method getFileType
 * @return A value converted from C/C++ "cocos2d::Image::Format"
 */
getFileType : function () {},

/**
 * @method saveToFile
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 * @param {bool}
 */
saveToFile : function () {},

/**
 * @method getNumberOfMipmaps
 * @return A value converted from C/C++ "int"
 */
getNumberOfMipmaps : function () {},

/**
 * @method getRenderFormat
 * @return A value converted from C/C++ "cocos2d::Texture2D::PixelFormat"
 */
getRenderFormat : function () {},

/**
 * @method getData
 * @return A value converted from C/C++ "unsigned char*"
 */
getData : function () {},

/**
 * @method getMipmaps
 * @return A value converted from C/C++ "cocos2d::MipmapInfo*"
 */
getMipmaps : function () {},

/**
 * @method Image
 * @constructor
 */
Image : function () {},

};

/**
 * @class RenderTexture
 */
cc.RenderTexture = {

/**
 * @method clearStencil
 * @param {int}
 */
clearStencil : function () {},

/**
 * @method draw
 */
draw : function () {},

/**
 * @method listenToForeground
 * @param {cocos2d::Object*}
 */
listenToForeground : function () {},

/**
 * @method getClearDepth
 * @return A value converted from C/C++ "float"
 */
getClearDepth : function () {},

/**
 * @method getClearStencil
 * @return A value converted from C/C++ "int"
 */
getClearStencil : function () {},

/**
 * @method end
 */
end : function () {},

/**
 * @method setClearStencil
 * @param {int}
 */
setClearStencil : function () {},

/**
 * @method setSprite
 * @param {cocos2d::Sprite*}
 */
setSprite : function () {},

/**
 * @method visit
 */
visit : function () {},

/**
 * @method getSprite
 * @return A value converted from C/C++ "cocos2d::Sprite*"
 */
getSprite : function () {},

/**
 * @method isAutoDraw
 * @return A value converted from C/C++ "bool"
 */
isAutoDraw : function () {},

/**
 * @method setClearFlags
 * @param {unsigned int}
 */
setClearFlags : function () {},

/**
 * @method begin
 */
begin : function () {},

/**
 * @method setAutoDraw
 * @param {bool}
 */
setAutoDraw : function () {},

/**
 * @method setClearColor
 * @param {const cocos2d::Color4F&}
 */
setClearColor : function () {},

/**
 * @method endToLua
 */
endToLua : function () {},

/**
 * @method clearDepth
 * @param {float}
 */
clearDepth : function () {},

/**
 * @method getClearColor
 * @return A value converted from C/C++ "const cocos2d::Color4F&"
 */
getClearColor : function () {},

/**
 * @method listenToBackground
 * @param {cocos2d::Object*}
 */
listenToBackground : function () {},

/**
 * @method clear
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 */
clear : function () {},

/**
 * @method getClearFlags
 * @return A value converted from C/C++ "unsigned int"
 */
getClearFlags : function () {},

/**
 * @method newImage
 * @return A value converted from C/C++ "cocos2d::Image*"
 */
newImage : function () {},

/**
 * @method setClearDepth
 * @param {float}
 */
setClearDepth : function () {},

/**
 * @method RenderTexture
 * @constructor
 */
RenderTexture : function () {},

};

/**
 * @class ParticleBatchNode
 */
cc.ParticleBatchNode = {

/**
 * @method draw
 */
draw : function () {},

/**
 * @method setTexture
 * @param {cocos2d::Texture2D*}
 */
setTexture : function () {},

/**
 * @method initWithFile
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 * @param {int}
 */
initWithFile : function () {},

/**
 * @method disableParticle
 * @param {int}
 */
disableParticle : function () {},

/**
 * @method visit
 */
visit : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 */
getTexture : function () {},

/**
 * @method setTextureAtlas
 * @param {cocos2d::TextureAtlas*}
 */
setTextureAtlas : function () {},

/**
 * @method removeAllChildrenWithCleanup
 * @param {bool}
 */
removeAllChildrenWithCleanup : function () {},

/**
 * @method getTextureAtlas
 * @return A value converted from C/C++ "cocos2d::TextureAtlas*"
 */
getTextureAtlas : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method insertChild
 * @param {cocos2d::ParticleSystem*}
 * @param {int}
 */
insertChild : function () {},

/**
 * @method initWithTexture
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::Texture2D*}
 * @param {int}
 */
initWithTexture : function () {},

/**
 * @method removeChildAtIndex
 * @param {int}
 * @param {bool}
 */
removeChildAtIndex : function () {},

/**
 * @method reorderChild
 * @param {cocos2d::Node*}
 * @param {int}
 */
reorderChild : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleBatchNode*"
 * @param {const std::string&}
 * @param {int}
 */
create : function () {},

/**
 * @method createWithTexture
 * @return A value converted from C/C++ "cocos2d::ParticleBatchNode*"
 * @param {cocos2d::Texture2D*}
 * @param {int}
 */
createWithTexture : function () {},

/**
 * @method ParticleBatchNode
 * @constructor
 */
ParticleBatchNode : function () {},

};

/**
 * @class ParticleSystem
 */
cc.ParticleSystem = {

/**
 * @method getStartSizeVar
 * @return A value converted from C/C++ "float"
 */
getStartSizeVar : function () {},

/**
 * @method getTexture
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 */
getTexture : function () {},

/**
 * @method isFull
 * @return A value converted from C/C++ "bool"
 */
isFull : function () {},

/**
 * @method getBatchNode
 * @return A value converted from C/C++ "cocos2d::ParticleBatchNode*"
 */
getBatchNode : function () {},

/**
 * @method getStartColor
 * @return A value converted from C/C++ "const cocos2d::Color4F&"
 */
getStartColor : function () {},

/**
 * @method getPositionType
 * @return A value converted from C/C++ "cocos2d::ParticleSystem::PositionType"
 */
getPositionType : function () {},

/**
 * @method setPosVar
 * @param {const cocos2d::Point&}
 */
setPosVar : function () {},

/**
 * @method getEndSpin
 * @return A value converted from C/C++ "float"
 */
getEndSpin : function () {},

/**
 * @method setRotatePerSecondVar
 * @param {float}
 */
setRotatePerSecondVar : function () {},

/**
 * @method getStartSpinVar
 * @return A value converted from C/C++ "float"
 */
getStartSpinVar : function () {},

/**
 * @method getRadialAccelVar
 * @return A value converted from C/C++ "float"
 */
getRadialAccelVar : function () {},

/**
 * @method getEndSizeVar
 * @return A value converted from C/C++ "float"
 */
getEndSizeVar : function () {},

/**
 * @method setRotation
 * @param {float}
 */
setRotation : function () {},

/**
 * @method setTangentialAccel
 * @param {float}
 */
setTangentialAccel : function () {},

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
 * @method getRadialAccel
 * @return A value converted from C/C++ "float"
 */
getRadialAccel : function () {},

/**
 * @method setStartRadius
 * @param {float}
 */
setStartRadius : function () {},

/**
 * @method setRotatePerSecond
 * @param {float}
 */
setRotatePerSecond : function () {},

/**
 * @method setEndSize
 * @param {float}
 */
setEndSize : function () {},

/**
 * @method getGravity
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getGravity : function () {},

/**
 * @method getTangentialAccel
 * @return A value converted from C/C++ "float"
 */
getTangentialAccel : function () {},

/**
 * @method setEndRadius
 * @param {float}
 */
setEndRadius : function () {},

/**
 * @method getSpeed
 * @return A value converted from C/C++ "float"
 */
getSpeed : function () {},

/**
 * @method getAngle
 * @return A value converted from C/C++ "float"
 */
getAngle : function () {},

/**
 * @method setEndColor
 * @param {const cocos2d::Color4F&}
 */
setEndColor : function () {},

/**
 * @method setStartSpin
 * @param {float}
 */
setStartSpin : function () {},

/**
 * @method setDuration
 * @param {float}
 */
setDuration : function () {},

/**
 * @method setTexture
 * @param {cocos2d::Texture2D*}
 */
setTexture : function () {},

/**
 * @method getPosVar
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getPosVar : function () {},

/**
 * @method updateWithNoTime
 */
updateWithNoTime : function () {},

/**
 * @method isBlendAdditive
 * @return A value converted from C/C++ "bool"
 */
isBlendAdditive : function () {},

/**
 * @method getSpeedVar
 * @return A value converted from C/C++ "float"
 */
getSpeedVar : function () {},

/**
 * @method setPositionType
 * @param {cocos2d::ParticleSystem::PositionType}
 */
setPositionType : function () {},

/**
 * @method stopSystem
 */
stopSystem : function () {},

/**
 * @method getSourcePosition
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getSourcePosition : function () {},

/**
 * @method setLifeVar
 * @param {float}
 */
setLifeVar : function () {},

/**
 * @method setTotalParticles
 * @param {int}
 */
setTotalParticles : function () {},

/**
 * @method setEndColorVar
 * @param {const cocos2d::Color4F&}
 */
setEndColorVar : function () {},

/**
 * @method updateQuadWithParticle
 * @param {cocos2d::tParticle*}
 * @param {const cocos2d::Point&}
 */
updateQuadWithParticle : function () {},

/**
 * @method getAtlasIndex
 * @return A value converted from C/C++ "int"
 */
getAtlasIndex : function () {},

/**
 * @method getStartSize
 * @return A value converted from C/C++ "float"
 */
getStartSize : function () {},

/**
 * @method setStartSpinVar
 * @param {float}
 */
setStartSpinVar : function () {},

/**
 * @method resetSystem
 */
resetSystem : function () {},

/**
 * @method setAtlasIndex
 * @param {int}
 */
setAtlasIndex : function () {},

/**
 * @method setTangentialAccelVar
 * @param {float}
 */
setTangentialAccelVar : function () {},

/**
 * @method setEndRadiusVar
 * @param {float}
 */
setEndRadiusVar : function () {},

/**
 * @method getEndRadius
 * @return A value converted from C/C++ "float"
 */
getEndRadius : function () {},

/**
 * @method isOpacityModifyRGB
 * @return A value converted from C/C++ "bool"
 */
isOpacityModifyRGB : function () {},

/**
 * @method isActive
 * @return A value converted from C/C++ "bool"
 */
isActive : function () {},

/**
 * @method setRadialAccelVar
 * @param {float}
 */
setRadialAccelVar : function () {},

/**
 * @method setStartSize
 * @param {float}
 */
setStartSize : function () {},

/**
 * @method setSpeed
 * @param {float}
 */
setSpeed : function () {},

/**
 * @method getStartSpin
 * @return A value converted from C/C++ "float"
 */
getStartSpin : function () {},

/**
 * @method getRotatePerSecond
 * @return A value converted from C/C++ "float"
 */
getRotatePerSecond : function () {},

/**
 * @method initParticle
 * @param {cocos2d::tParticle*}
 */
initParticle : function () {},

/**
 * @method setEmitterMode
 * @param {cocos2d::ParticleSystem::Mode}
 */
setEmitterMode : function () {},

/**
 * @method getDuration
 * @return A value converted from C/C++ "float"
 */
getDuration : function () {},

/**
 * @method setSourcePosition
 * @param {const cocos2d::Point&}
 */
setSourcePosition : function () {},

/**
 * @method getEndSpinVar
 * @return A value converted from C/C++ "float"
 */
getEndSpinVar : function () {},

/**
 * @method setBlendAdditive
 * @param {bool}
 */
setBlendAdditive : function () {},

/**
 * @method setLife
 * @param {float}
 */
setLife : function () {},

/**
 * @method setAngleVar
 * @param {float}
 */
setAngleVar : function () {},

/**
 * @method setRotationIsDir
 * @param {bool}
 */
setRotationIsDir : function () {},

/**
 * @method setEndSizeVar
 * @param {float}
 */
setEndSizeVar : function () {},

/**
 * @method setAngle
 * @param {float}
 */
setAngle : function () {},

/**
 * @method setBatchNode
 * @param {cocos2d::ParticleBatchNode*}
 */
setBatchNode : function () {},

/**
 * @method getTangentialAccelVar
 * @return A value converted from C/C++ "float"
 */
getTangentialAccelVar : function () {},

/**
 * @method getEmitterMode
 * @return A value converted from C/C++ "cocos2d::ParticleSystem::Mode"
 */
getEmitterMode : function () {},

/**
 * @method setEndSpinVar
 * @param {float}
 */
setEndSpinVar : function () {},

/**
 * @method getAngleVar
 * @return A value converted from C/C++ "float"
 */
getAngleVar : function () {},

/**
 * @method setStartColor
 * @param {const cocos2d::Color4F&}
 */
setStartColor : function () {},

/**
 * @method getRotatePerSecondVar
 * @return A value converted from C/C++ "float"
 */
getRotatePerSecondVar : function () {},

/**
 * @method getEndSize
 * @return A value converted from C/C++ "float"
 */
getEndSize : function () {},

/**
 * @method getLife
 * @return A value converted from C/C++ "float"
 */
getLife : function () {},

/**
 * @method setSpeedVar
 * @param {float}
 */
setSpeedVar : function () {},

/**
 * @method setAutoRemoveOnFinish
 * @param {bool}
 */
setAutoRemoveOnFinish : function () {},

/**
 * @method setGravity
 * @param {const cocos2d::Point&}
 */
setGravity : function () {},

/**
 * @method postStep
 */
postStep : function () {},

/**
 * @method setEmissionRate
 * @param {float}
 */
setEmissionRate : function () {},

/**
 * @method getEndColorVar
 * @return A value converted from C/C++ "const cocos2d::Color4F&"
 */
getEndColorVar : function () {},

/**
 * @method getRotationIsDir
 * @return A value converted from C/C++ "bool"
 */
getRotationIsDir : function () {},

/**
 * @method setScale
 * @param {float}
 */
setScale : function () {},

/**
 * @method getEmissionRate
 * @return A value converted from C/C++ "float"
 */
getEmissionRate : function () {},

/**
 * @method getEndColor
 * @return A value converted from C/C++ "const cocos2d::Color4F&"
 */
getEndColor : function () {},

/**
 * @method getLifeVar
 * @return A value converted from C/C++ "float"
 */
getLifeVar : function () {},

/**
 * @method setStartSizeVar
 * @param {float}
 */
setStartSizeVar : function () {},

/**
 * @method setOpacityModifyRGB
 * @param {bool}
 */
setOpacityModifyRGB : function () {},

/**
 * @method addParticle
 * @return A value converted from C/C++ "bool"
 */
addParticle : function () {},

/**
 * @method getStartRadius
 * @return A value converted from C/C++ "float"
 */
getStartRadius : function () {},

/**
 * @method getParticleCount
 * @return A value converted from C/C++ "unsigned int"
 */
getParticleCount : function () {},

/**
 * @method getStartRadiusVar
 * @return A value converted from C/C++ "float"
 */
getStartRadiusVar : function () {},

/**
 * @method setStartColorVar
 * @param {const cocos2d::Color4F&}
 */
setStartColorVar : function () {},

/**
 * @method setEndSpin
 * @param {float}
 */
setEndSpin : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method setRadialAccel
 * @param {float}
 */
setRadialAccel : function () {},

/**
 * @method isAutoRemoveOnFinish
 * @return A value converted from C/C++ "bool"
 */
isAutoRemoveOnFinish : function () {},

/**
 * @method getTotalParticles
 * @return A value converted from C/C++ "int"
 */
getTotalParticles : function () {},

/**
 * @method setStartRadiusVar
 * @param {float}
 */
setStartRadiusVar : function () {},

/**
 * @method getEndRadiusVar
 * @return A value converted from C/C++ "float"
 */
getEndRadiusVar : function () {},

/**
 * @method getStartColorVar
 * @return A value converted from C/C++ "const cocos2d::Color4F&"
 */
getStartColorVar : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleSystem*"
 * @param {const std::string&}
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleSystem*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleSystemQuad
 */
cc.ParticleSystem = {

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method setTextureWithRect
 * @param {cocos2d::Texture2D*}
 * @param {const cocos2d::Rect&}
 */
setTextureWithRect : function () {},

/**
 * @method setDisplayFrame
 * @param {cocos2d::SpriteFrame*}
 */
setDisplayFrame : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleSystemQuad*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleFire
 */
cc.ParticleFire = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleFire*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleFire*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleFireworks
 */
cc.ParticleFireworks = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleFireworks*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleFireworks*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleSun
 */
cc.ParticleSun = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleSun*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleSun*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleGalaxy
 */
cc.ParticleGalaxy = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleGalaxy*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleGalaxy*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleFlower
 */
cc.ParticleFlower = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleFlower*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleFlower*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleMeteor
 */
cc.ParticleMeteor = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleMeteor*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleMeteor*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleSpiral
 */
cc.ParticleSpiral = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleSpiral*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleSpiral*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleExplosion
 */
cc.ParticleExplosion = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleExplosion*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleExplosion*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleSmoke
 */
cc.ParticleSmoke = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleSmoke*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleSmoke*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleSnow
 */
cc.ParticleSnow = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleSnow*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleSnow*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class ParticleRain
 */
cc.ParticleRain = {

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParticleRain*"
 */
create : function () {},

/**
 * @method createWithTotalParticles
 * @return A value converted from C/C++ "cocos2d::ParticleRain*"
 * @param {int}
 */
createWithTotalParticles : function () {},

};

/**
 * @class NewRenderTexture
 */
cc.NewRenderTexture = {

/**
 * @method clearDepth
 * @param {float}
 */
clearDepth : function () {},

/**
 * @method end
 */
end : function () {},

/**
 * @method begin
 */
begin : function () {},

/**
 * @method draw
 */
draw : function () {},

};

/**
 * @class NewClippingNode
 */
cc.NewClippingNode = {

/**
 * @method visit
 */
visit : function () {},

};

/**
 * @class FileUtils
 */
cc.FileUtils = {

/**
 * @method isFileExist
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 */
isFileExist : function () {},

/**
 * @method isPopupNotify
 * @return A value converted from C/C++ "bool"
 */
isPopupNotify : function () {},

/**
 * @method fullPathForFilename
 * @return A value converted from C/C++ "std::string"
 * @param {const std::string&}
 */
fullPathForFilename : function () {},

/**
 * @method fullPathFromRelativeFile
 * @return A value converted from C/C++ "std::string"
 * @param {const std::string&}
 * @param {const std::string&}
 */
fullPathFromRelativeFile : function () {},

/**
 * @method setFilenameLookupDictionary
 * @param {const cocos2d::ValueMap&}
 */
setFilenameLookupDictionary : function () {},

/**
 * @method addSearchResolutionsOrder
 * @param {const std::string&}
 */
addSearchResolutionsOrder : function () {},

/**
 * @method writeToFile
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::ValueMap&}
 * @param {const std::string&}
 */
writeToFile : function () {},

/**
 * @method purgeCachedEntries
 */
purgeCachedEntries : function () {},

/**
 * @method isAbsolutePath
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 */
isAbsolutePath : function () {},

/**
 * @method getWritablePath
 * @return A value converted from C/C++ "std::string"
 */
getWritablePath : function () {},

/**
 * @method getValueMapFromFile
 * @return A value converted from C/C++ "cocos2d::ValueMap"
 * @param {const std::string&}
 */
getValueMapFromFile : function () {},

/**
 * @method addSearchPath
 * @param {const std::string&}
 */
addSearchPath : function () {},

/**
 * @method getValueVectorFromFile
 * @return A value converted from C/C++ "cocos2d::ValueVector"
 * @param {const std::string&}
 */
getValueVectorFromFile : function () {},

/**
 * @method setPopupNotify
 * @param {bool}
 */
setPopupNotify : function () {},

/**
 * @method loadFilenameLookupDictionaryFromFile
 * @param {const std::string&}
 */
loadFilenameLookupDictionaryFromFile : function () {},

/**
 * @method destroyInstance
 */
destroyInstance : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::FileUtils*"
 */
getInstance : function () {},

};

/**
 * @class Application
 */
cc.Application = {

/**
 * @method getTargetPlatform
 * @return A value converted from C/C++ "cocos2d::ApplicationProtocol::Platform"
 */
getTargetPlatform : function () {},

/**
 * @method setAnimationInterval
 * @param {double}
 */
setAnimationInterval : function () {},

/**
 * @method getCurrentLanguage
 * @return A value converted from C/C++ "cocos2d::LanguageType"
 */
getCurrentLanguage : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::Application*"
 */
getInstance : function () {},

};

/**
 * @class EGLViewProtocol
 */
cc.EGLViewProtocol = {

/**
 * @method setFrameSize
 * @param {float}
 * @param {float}
 */
setFrameSize : function () {},

/**
 * @method getViewPortRect
 * @return A value converted from C/C++ "const cocos2d::Rect&"
 */
getViewPortRect : function () {},

/**
 * @method handleTouchesMove
 * @param {int}
 * @param {int*}
 * @param {float*}
 * @param {float*}
 */
handleTouchesMove : function () {},

/**
 * @method setIMEKeyboardState
 * @param {bool}
 */
setIMEKeyboardState : function () {},

/**
 * @method setScissorInPoints
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 */
setScissorInPoints : function () {},

/**
 * @method getViewName
 * @return A value converted from C/C++ "const std::string&"
 */
getViewName : function () {},

/**
 * @method isOpenGLReady
 * @return A value converted from C/C++ "bool"
 */
isOpenGLReady : function () {},

/**
 * @method getScissorRect
 * @return A value converted from C/C++ "cocos2d::Rect"
 */
getScissorRect : function () {},

/**
 * @method end
 */
end : function () {},

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
 * @method getVisibleOrigin
 * @return A value converted from C/C++ "cocos2d::Point"
 */
getVisibleOrigin : function () {},

/**
 * @method getFrameSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getFrameSize : function () {},

/**
 * @method getDesignResolutionSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getDesignResolutionSize : function () {},

/**
 * @method pollInputEvents
 */
pollInputEvents : function () {},

/**
 * @method swapBuffers
 */
swapBuffers : function () {},

/**
 * @method setDesignResolutionSize
 * @param {float}
 * @param {float}
 * @param {ResolutionPolicy}
 */
setDesignResolutionSize : function () {},

/**
 * @method handleTouchesBegin
 * @param {int}
 * @param {int*}
 * @param {float*}
 * @param {float*}
 */
handleTouchesBegin : function () {},

/**
 * @method setViewPortInPoints
 * @param {float}
 * @param {float}
 * @param {float}
 * @param {float}
 */
setViewPortInPoints : function () {},

/**
 * @method handleTouchesCancel
 * @param {int}
 * @param {int*}
 * @param {float*}
 * @param {float*}
 */
handleTouchesCancel : function () {},

/**
 * @method setViewName
 * @param {const std::string&}
 */
setViewName : function () {},

/**
 * @method getVisibleSize
 * @return A value converted from C/C++ "cocos2d::Size"
 */
getVisibleSize : function () {},

/**
 * @method isScissorEnabled
 * @return A value converted from C/C++ "bool"
 */
isScissorEnabled : function () {},

/**
 * @method handleTouchesEnd
 * @param {int}
 * @param {int*}
 * @param {float*}
 * @param {float*}
 */
handleTouchesEnd : function () {},

};

/**
 * @class EGLView
 */
cc.EGLView = {

/**
 * @method setIMEKeyboardState
 * @param {bool}
 */
setIMEKeyboardState : function () {},

/**
 * @method isOpenGLReady
 * @return A value converted from C/C++ "bool"
 */
isOpenGLReady : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::EGLView*"
 */
getInstance : function () {},

};

/**
 * @class ShaderCache
 */
cc.ShaderCache = {

/**
 * @method reloadDefaultShaders
 */
reloadDefaultShaders : function () {},

/**
 * @method addProgram
 * @param {cocos2d::GLProgram*}
 * @param {const std::string&}
 */
addProgram : function () {},

/**
 * @method getProgram
 * @return A value converted from C/C++ "cocos2d::GLProgram*"
 * @param {const std::string&}
 */
getProgram : function () {},

/**
 * @method loadDefaultShaders
 */
loadDefaultShaders : function () {},

/**
 * @method destroyInstance
 */
destroyInstance : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::ShaderCache*"
 */
getInstance : function () {},

/**
 * @method ShaderCache
 * @constructor
 */
ShaderCache : function () {},

};

/**
 * @class AnimationCache
 */
cc.AnimationCache = {

/**
 * @method getAnimation
 * @return A value converted from C/C++ "cocos2d::Animation*"
 * @param {const std::string&}
 */
getAnimation : function () {},

/**
 * @method addAnimation
 * @param {cocos2d::Animation*}
 * @param {const std::string&}
 */
addAnimation : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method addAnimationsWithDictionary
 * @param {const cocos2d::ValueMap&}
 */
addAnimationsWithDictionary : function () {},

/**
 * @method removeAnimation
 * @param {const std::string&}
 */
removeAnimation : function () {},

/**
 * @method addAnimationsWithFile
 * @param {const std::string&}
 */
addAnimationsWithFile : function () {},

/**
 * @method destroyInstance
 */
destroyInstance : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::AnimationCache*"
 */
getInstance : function () {},

/**
 * @method AnimationCache
 * @constructor
 */
AnimationCache : function () {},

};

/**
 * @class SpriteFrameCache
 */
cc.SpriteFrameCache = {

/**
 * @method addSpriteFrame
 * @param {cocos2d::SpriteFrame*}
 * @param {const std::string&}
 */
addSpriteFrame : function () {},

/**
 * @method removeUnusedSpriteFrames
 */
removeUnusedSpriteFrames : function () {},

/**
 * @method getSpriteFrameByName
 * @return A value converted from C/C++ "cocos2d::SpriteFrame*"
 * @param {const std::string&}
 */
getSpriteFrameByName : function () {},

/**
 * @method removeSpriteFramesFromFile
 * @param {const std::string&}
 */
removeSpriteFramesFromFile : function () {},

/**
 * @method init
 * @return A value converted from C/C++ "bool"
 */
init : function () {},

/**
 * @method removeSpriteFrames
 */
removeSpriteFrames : function () {},

/**
 * @method removeSpriteFramesFromTexture
 * @param {cocos2d::Texture2D*}
 */
removeSpriteFramesFromTexture : function () {},

/**
 * @method removeSpriteFrameByName
 * @param {const std::string&}
 */
removeSpriteFrameByName : function () {},

/**
 * @method destroyInstance
 */
destroyInstance : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "cocos2d::SpriteFrameCache*"
 */
getInstance : function () {},

};

/**
 * @class UserDefault
 */
cc.UserDefault = {

/**
 * @method setIntegerForKey
 * @param {const char*}
 * @param {int}
 */
setIntegerForKey : function () {},

/**
 * @method setDoubleForKey
 * @param {const char*}
 * @param {double}
 */
setDoubleForKey : function () {},

/**
 * @method setFloatForKey
 * @param {const char*}
 * @param {float}
 */
setFloatForKey : function () {},

/**
 * @method setStringForKey
 * @param {const char*}
 * @param {const std::string&}
 */
setStringForKey : function () {},

/**
 * @method flush
 */
flush : function () {},

/**
 * @method setBoolForKey
 * @param {const char*}
 * @param {bool}
 */
setBoolForKey : function () {},

/**
 * @method destroyInstance
 */
destroyInstance : function () {},

/**
 * @method getXMLFilePath
 * @return A value converted from C/C++ "const std::string&"
 */
getXMLFilePath : function () {},

/**
 * @method isXMLFileExist
 * @return A value converted from C/C++ "bool"
 */
isXMLFileExist : function () {},

};

/**
 * @class TextureCache
 */
cc.TextureCache = {

/**
 * @method dumpCachedTextureInfo
 */
dumpCachedTextureInfo : function () {},

/**
 * @method removeAllTextures
 */
removeAllTextures : function () {},

/**
 * @method removeTextureForKey
 * @param {const std::string&}
 */
removeTextureForKey : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method getTextureForKey
 * @return A value converted from C/C++ "cocos2d::Texture2D*"
 * @param {const std::string&}
 */
getTextureForKey : function () {},

/**
 * @method removeUnusedTextures
 */
removeUnusedTextures : function () {},

/**
 * @method removeTexture
 * @param {cocos2d::Texture2D*}
 */
removeTexture : function () {},

/**
 * @method waitForQuit
 */
waitForQuit : function () {},

/**
 * @method TextureCache
 * @constructor
 */
TextureCache : function () {},

};

/**
 * @class ParallaxNode
 */
cc.ParallaxNode = {

/**
 * @method visit
 */
visit : function () {},

/**
 * @method removeAllChildrenWithCleanup
 * @param {bool}
 */
removeAllChildrenWithCleanup : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method setParallaxArray
 * @param {cocos2d::_ccArray*}
 */
setParallaxArray : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::ParallaxNode*"
 */
create : function () {},

};

/**
 * @class TMXObjectGroup
 */
cc.TMXObjectGroup = {

/**
 * @method setPositionOffset
 * @param {const cocos2d::Point&}
 */
setPositionOffset : function () {},

/**
 * @method getProperty
 * @return A value converted from C/C++ "cocos2d::Value"
 * @param {const std::string&}
 */
getProperty : function () {},

/**
 * @method getPositionOffset
 * @return A value converted from C/C++ "const cocos2d::Point&"
 */
getPositionOffset : function () {},

/**
 * @method getObject
 * @return A value converted from C/C++ "cocos2d::ValueMap"
 * @param {const std::string&}
 */
getObject : function () {},

/**
 * @method setGroupName
 * @param {const std::string&}
 */
setGroupName : function () {},

/**
 * @method getGroupName
 * @return A value converted from C/C++ "const std::string&"
 */
getGroupName : function () {},

/**
 * @method setProperties
 * @param {const cocos2d::ValueMap&}
 */
setProperties : function () {},

/**
 * @method setObjects
 * @param {const cocos2d::ValueVector&}
 */
setObjects : function () {},

/**
 * @method TMXObjectGroup
 * @constructor
 */
TMXObjectGroup : function () {},

};

/**
 * @class TMXLayerInfo
 */
cc.TMXLayerInfo = {

/**
 * @method setProperties
 * @param {cocos2d::ValueMap}
 */
setProperties : function () {},

/**
 * @method getProperties
 * @return A value converted from C/C++ "cocos2d::ValueMap"
 */
getProperties : function () {},

/**
 * @method TMXLayerInfo
 * @constructor
 */
TMXLayerInfo : function () {},

};

/**
 * @class TMXTilesetInfo
 */
cc.TMXTilesetInfo = {

/**
 * @method rectForGID
 * @return A value converted from C/C++ "cocos2d::Rect"
 * @param {unsigned int}
 */
rectForGID : function () {},

/**
 * @method TMXTilesetInfo
 * @constructor
 */
TMXTilesetInfo : function () {},

};

/**
 * @class TMXMapInfo
 */
cc.TMXMapInfo = {

/**
 * @method setObjectGroups
 * @param {const cocos2d::Vector<cocos2d::TMXObjectGroup *>&}
 */
setObjectGroups : function () {},

/**
 * @method setTileSize
 * @param {const cocos2d::Size&}
 */
setTileSize : function () {},

/**
 * @method initWithTMXFile
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 */
initWithTMXFile : function () {},

/**
 * @method getOrientation
 * @return A value converted from C/C++ "int"
 */
getOrientation : function () {},

/**
 * @method isStoringCharacters
 * @return A value converted from C/C++ "bool"
 */
isStoringCharacters : function () {},

/**
 * @method setLayers
 * @param {const cocos2d::Vector<cocos2d::TMXLayerInfo *>&}
 */
setLayers : function () {},

/**
 * @method parseXMLFile
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 */
parseXMLFile : function () {},

/**
 * @method getParentElement
 * @return A value converted from C/C++ "int"
 */
getParentElement : function () {},

/**
 * @method setTMXFileName
 * @param {const std::string&}
 */
setTMXFileName : function () {},

/**
 * @method parseXMLString
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 */
parseXMLString : function () {},

/**
 * @method getParentGID
 * @return A value converted from C/C++ "unsigned int"
 */
getParentGID : function () {},

/**
 * @method setParentElement
 * @param {int}
 */
setParentElement : function () {},

/**
 * @method initWithXML
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 * @param {const std::string&}
 */
initWithXML : function () {},

/**
 * @method setParentGID
 * @param {unsigned int}
 */
setParentGID : function () {},

/**
 * @method getLayerAttribs
 * @return A value converted from C/C++ "int"
 */
getLayerAttribs : function () {},

/**
 * @method getTileSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getTileSize : function () {},

/**
 * @method getTileProperties
 * @return A value converted from C/C++ "cocos2d::IntValueMap&"
 */
getTileProperties : function () {},

/**
 * @method getTMXFileName
 * @return A value converted from C/C++ "const std::string&"
 */
getTMXFileName : function () {},

/**
 * @method setCurrentString
 * @param {const std::string&}
 */
setCurrentString : function () {},

/**
 * @method setProperties
 * @param {cocos2d::ValueMap}
 */
setProperties : function () {},

/**
 * @method setOrientation
 * @param {int}
 */
setOrientation : function () {},

/**
 * @method setTileProperties
 * @param {const cocos2d::IntValueMap&}
 */
setTileProperties : function () {},

/**
 * @method setMapSize
 * @param {const cocos2d::Size&}
 */
setMapSize : function () {},

/**
 * @method setStoringCharacters
 * @param {bool}
 */
setStoringCharacters : function () {},

/**
 * @method getMapSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getMapSize : function () {},

/**
 * @method setTilesets
 * @param {const cocos2d::Vector<cocos2d::TMXTilesetInfo *>&}
 */
setTilesets : function () {},

/**
 * @method getProperties
 * @return A value converted from C/C++ "cocos2d::ValueMap"
 */
getProperties : function () {},

/**
 * @method getCurrentString
 * @return A value converted from C/C++ "const std::string&"
 */
getCurrentString : function () {},

/**
 * @method setLayerAttribs
 * @param {int}
 */
setLayerAttribs : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TMXMapInfo*"
 * @param {const std::string&}
 */
create : function () {},

/**
 * @method createWithXML
 * @return A value converted from C/C++ "cocos2d::TMXMapInfo*"
 * @param {const std::string&}
 * @param {const std::string&}
 */
createWithXML : function () {},

/**
 * @method TMXMapInfo
 * @constructor
 */
TMXMapInfo : function () {},

};

/**
 * @class TMXLayer
 */
cc.TMXLayer = {

/**
 * @method addChild
 * @param {cocos2d::Node*}
 * @param {int}
 * @param {int}
 */
addChild : function () {},

/**
 * @method getTileGIDAt
 * @return A value converted from C/C++ "unsigned int"
 * @param {const cocos2d::Point&}
 * @param {cocos2d::ccTMXTileFlags*}
 */
getTileGIDAt : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method getPositionAt
 * @return A value converted from C/C++ "cocos2d::Point"
 * @param {const cocos2d::Point&}
 */
getPositionAt : function () {},

/**
 * @method setLayerOrientation
 * @param {unsigned int}
 */
setLayerOrientation : function () {},

/**
 * @method releaseMap
 */
releaseMap : function () {},

/**
 * @method setTiles
 * @param {unsigned int*}
 */
setTiles : function () {},

/**
 * @method getLayerSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getLayerSize : function () {},

/**
 * @method setMapTileSize
 * @param {const cocos2d::Size&}
 */
setMapTileSize : function () {},

/**
 * @method getLayerOrientation
 * @return A value converted from C/C++ "unsigned int"
 */
getLayerOrientation : function () {},

/**
 * @method setProperties
 * @param {const cocos2d::ValueMap&}
 */
setProperties : function () {},

/**
 * @method setLayerName
 * @param {const char*}
 */
setLayerName : function () {},

/**
 * @method removeTileAt
 * @param {const cocos2d::Point&}
 */
removeTileAt : function () {},

/**
 * @method initWithTilesetInfo
 * @return A value converted from C/C++ "bool"
 * @param {cocos2d::TMXTilesetInfo*}
 * @param {cocos2d::TMXLayerInfo*}
 * @param {cocos2d::TMXMapInfo*}
 */
initWithTilesetInfo : function () {},

/**
 * @method setupTiles
 */
setupTiles : function () {},

/**
 * @method getMapTileSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getMapTileSize : function () {},

/**
 * @method getProperty
 * @return A value converted from C/C++ "cocos2d::Value"
 * @param {const std::string&}
 */
getProperty : function () {},

/**
 * @method setLayerSize
 * @param {const cocos2d::Size&}
 */
setLayerSize : function () {},

/**
 * @method getLayerName
 * @return A value converted from C/C++ "const char*"
 */
getLayerName : function () {},

/**
 * @method setTileSet
 * @param {cocos2d::TMXTilesetInfo*}
 */
setTileSet : function () {},

/**
 * @method removeChild
 * @param {cocos2d::Node*}
 * @param {bool}
 */
removeChild : function () {},

/**
 * @method getTileSet
 * @return A value converted from C/C++ "cocos2d::TMXTilesetInfo*"
 */
getTileSet : function () {},

/**
 * @method getTileAt
 * @return A value converted from C/C++ "cocos2d::Sprite*"
 * @param {const cocos2d::Point&}
 */
getTileAt : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TMXLayer*"
 * @param {cocos2d::TMXTilesetInfo*}
 * @param {cocos2d::TMXLayerInfo*}
 * @param {cocos2d::TMXMapInfo*}
 */
create : function () {},

/**
 * @method TMXLayer
 * @constructor
 */
TMXLayer : function () {},

};

/**
 * @class TMXTiledMap
 */
cc.TMXTiledMap = {

/**
 * @method setObjectGroups
 * @param {const cocos2d::Vector<cocos2d::TMXObjectGroup *>&}
 */
setObjectGroups : function () {},

/**
 * @method getProperty
 * @return A value converted from C/C++ "cocos2d::Value"
 * @param {const std::string&}
 */
getProperty : function () {},

/**
 * @method setMapSize
 * @param {const cocos2d::Size&}
 */
setMapSize : function () {},

/**
 * @method getObjectGroup
 * @return A value converted from C/C++ "cocos2d::TMXObjectGroup*"
 * @param {const std::string&}
 */
getObjectGroup : function () {},

/**
 * @method getDescription
 * @return A value converted from C/C++ "std::string"
 */
getDescription : function () {},

/**
 * @method getTileSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getTileSize : function () {},

/**
 * @method getMapSize
 * @return A value converted from C/C++ "const cocos2d::Size&"
 */
getMapSize : function () {},

/**
 * @method getProperties
 * @return A value converted from C/C++ "cocos2d::ValueMap&"
 */
getProperties : function () {},

/**
 * @method getPropertiesForGID
 * @return A value converted from C/C++ "cocos2d::Value"
 * @param {int}
 */
getPropertiesForGID : function () {},

/**
 * @method setTileSize
 * @param {const cocos2d::Size&}
 */
setTileSize : function () {},

/**
 * @method setProperties
 * @param {const cocos2d::ValueMap&}
 */
setProperties : function () {},

/**
 * @method getLayer
 * @return A value converted from C/C++ "cocos2d::TMXLayer*"
 * @param {const std::string&}
 */
getLayer : function () {},

/**
 * @method getMapOrientation
 * @return A value converted from C/C++ "int"
 */
getMapOrientation : function () {},

/**
 * @method setMapOrientation
 * @param {int}
 */
setMapOrientation : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TMXTiledMap*"
 * @param {const std::string&}
 */
create : function () {},

/**
 * @method createWithXML
 * @return A value converted from C/C++ "cocos2d::TMXTiledMap*"
 * @param {const std::string&}
 * @param {const std::string&}
 */
createWithXML : function () {},

};

/**
 * @class TileMapAtlas
 */
cc.TileMapAtlas = {

/**
 * @method initWithTileFile
 * @return A value converted from C/C++ "bool"
 * @param {const std::string&}
 * @param {const std::string&}
 * @param {int}
 * @param {int}
 */
initWithTileFile : function () {},

/**
 * @method releaseMap
 */
releaseMap : function () {},

/**
 * @method getTGAInfo
 * @return A value converted from C/C++ "cocos2d::sImageTGA*"
 */
getTGAInfo : function () {},

/**
 * @method getTileAt
 * @return A value converted from C/C++ "cocos2d::Color3B"
 * @param {const cocos2d::Point&}
 */
getTileAt : function () {},

/**
 * @method setTile
 * @param {const cocos2d::Color3B&}
 * @param {const cocos2d::Point&}
 */
setTile : function () {},

/**
 * @method setTGAInfo
 * @param {cocos2d::sImageTGA*}
 */
setTGAInfo : function () {},

/**
 * @method create
 * @return A value converted from C/C++ "cocos2d::TileMapAtlas*"
 * @param {const std::string&}
 * @param {const std::string&}
 * @param {int}
 * @param {int}
 */
create : function () {},

/**
 * @method TileMapAtlas
 * @constructor
 */
TileMapAtlas : function () {},

};

/**
 * @class Timer
 */
cc.Timer = {

/**
 * @method getInterval
 * @return A value converted from C/C++ "float"
 */
getInterval : function () {},

/**
 * @method setInterval
 * @param {float}
 */
setInterval : function () {},

/**
 * @method initWithScriptHandler
 * @return A value converted from C/C++ "bool"
 * @param {int}
 * @param {float}
 */
initWithScriptHandler : function () {},

/**
 * @method update
 * @param {float}
 */
update : function () {},

/**
 * @method getScriptHandler
 * @return A value converted from C/C++ "int"
 */
getScriptHandler : function () {},

/**
 * @method Timer
 * @constructor
 */
Timer : function () {},

};

/**
 * @class Scheduler
 */
cc.Scheduler = {

/**
 * @method setTimeScale
 * @param {float}
 */
setTimeScale : function () {},

/**
 * @method performFunctionInCocosThread
 * @param {const std::function<void ()>&}
 */
performFunctionInCocosThread : function () {},

/**
 * @method getTimeScale
 * @return A value converted from C/C++ "float"
 */
getTimeScale : function () {},

/**
 * @method Scheduler
 * @constructor
 */
Scheduler : function () {},

};

/**
 * @class SimpleAudioEngine
 */
cc.AudioEngine = {

/**
 * @method preloadBackgroundMusic
 * @param {const char*}
 */
preloadBackgroundMusic : function () {},

/**
 * @method stopBackgroundMusic
 */
stopBackgroundMusic : function () {},

/**
 * @method stopAllEffects
 */
stopAllEffects : function () {},

/**
 * @method getBackgroundMusicVolume
 * @return A value converted from C/C++ "float"
 */
getBackgroundMusicVolume : function () {},

/**
 * @method resumeBackgroundMusic
 */
resumeBackgroundMusic : function () {},

/**
 * @method setBackgroundMusicVolume
 * @param {float}
 */
setBackgroundMusicVolume : function () {},

/**
 * @method preloadEffect
 * @param {const char*}
 */
preloadEffect : function () {},

/**
 * @method isBackgroundMusicPlaying
 * @return A value converted from C/C++ "bool"
 */
isBackgroundMusicPlaying : function () {},

/**
 * @method getEffectsVolume
 * @return A value converted from C/C++ "float"
 */
getEffectsVolume : function () {},

/**
 * @method willPlayBackgroundMusic
 * @return A value converted from C/C++ "bool"
 */
willPlayBackgroundMusic : function () {},

/**
 * @method pauseEffect
 * @param {unsigned int}
 */
pauseEffect : function () {},

/**
 * @method playEffect
 * @return A value converted from C/C++ "unsigned int"
 * @param {const char*}
 * @param {bool}
 * @param {float}
 * @param {float}
 * @param {float}
 */
playEffect : function () {},

/**
 * @method rewindBackgroundMusic
 */
rewindBackgroundMusic : function () {},

/**
 * @method playBackgroundMusic
 * @param {const char*}
 * @param {bool}
 */
playBackgroundMusic : function () {},

/**
 * @method resumeAllEffects
 */
resumeAllEffects : function () {},

/**
 * @method setEffectsVolume
 * @param {float}
 */
setEffectsVolume : function () {},

/**
 * @method stopEffect
 * @param {unsigned int}
 */
stopEffect : function () {},

/**
 * @method pauseBackgroundMusic
 */
pauseBackgroundMusic : function () {},

/**
 * @method pauseAllEffects
 */
pauseAllEffects : function () {},

/**
 * @method unloadEffect
 * @param {const char*}
 */
unloadEffect : function () {},

/**
 * @method resumeEffect
 * @param {unsigned int}
 */
resumeEffect : function () {},

/**
 * @method end
 */
end : function () {},

/**
 * @method getInstance
 * @return A value converted from C/C++ "CocosDenshion::SimpleAudioEngine*"
 */
getInstance : function () {},

};
