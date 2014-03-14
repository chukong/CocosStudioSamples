#include "jsb_cocos2dx_gui_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "CocosGUI.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    JSBool isNewValid = JS_TRUE;
    JSObject* global = ScriptingCore::getInstance()->getGlobalObject();
	isNewValid = JS_GetProperty(cx, global, "initializing", &initializing) && JSVAL_TO_BOOLEAN(initializing);
	if (isNewValid)
	{
		TypeTest<T> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");

		JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
		return JS_TRUE;
	}

    JS_ReportError(cx, "Don't use `new cc.XXX`, please use `cc.XXX.create` instead! ");
    return JS_FALSE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *jsb_UILayoutParameter_class;
JSObject *jsb_UILayoutParameter_prototype;

JSBool js_cocos2dx_gui_UILayoutParameter_getLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayoutParameter* cobj = (gui::UILayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayoutParameter_getLayoutType : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getLayoutType();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayoutParameter_getLayoutType : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayoutParameter_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILayoutParameter* ret = gui::UILayoutParameter::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILayoutParameter>(cx, (gui::UILayoutParameter*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILayoutParameter_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILayoutParameter_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILayoutParameter* cobj = new gui::UILayoutParameter();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILayoutParameter> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILayoutParameter");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayoutParameter_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_cocos2dx_gui_UILayoutParameter_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILayoutParameter)", obj);
}

void js_register_cocos2dx_gui_UILayoutParameter(JSContext *cx, JSObject *global) {
	jsb_UILayoutParameter_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILayoutParameter_class->name = "UILayoutParameter";
	jsb_UILayoutParameter_class->addProperty = JS_PropertyStub;
	jsb_UILayoutParameter_class->delProperty = JS_DeletePropertyStub;
	jsb_UILayoutParameter_class->getProperty = JS_PropertyStub;
	jsb_UILayoutParameter_class->setProperty = JS_StrictPropertyStub;
	jsb_UILayoutParameter_class->enumerate = JS_EnumerateStub;
	jsb_UILayoutParameter_class->resolve = JS_ResolveStub;
	jsb_UILayoutParameter_class->convert = JS_ConvertStub;
	jsb_UILayoutParameter_class->finalize = js_cocos2dx_gui_UILayoutParameter_finalize;
	jsb_UILayoutParameter_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getLayoutType", js_cocos2dx_gui_UILayoutParameter_getLayoutType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILayoutParameter_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILayoutParameter_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_UILayoutParameter_class,
		js_cocos2dx_gui_UILayoutParameter_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILayoutParameter", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILayoutParameter> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILayoutParameter_class;
		p->proto = jsb_UILayoutParameter_prototype;
		p->parentProto = NULL;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UILinearLayoutParameter_class;
JSObject *jsb_UILinearLayoutParameter_prototype;

JSBool js_cocos2dx_gui_UILinearLayoutParameter_setGravity(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILinearLayoutParameter* cobj = (gui::UILinearLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILinearLayoutParameter_setGravity : Invalid Native Object");
	if (argc == 1) {
		gui::UILinearGravity arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILinearLayoutParameter_setGravity : Error processing arguments");
		cobj->setGravity(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILinearLayoutParameter_setGravity : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILinearLayoutParameter_getGravity(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILinearLayoutParameter* cobj = (gui::UILinearLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILinearLayoutParameter_getGravity : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getGravity();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILinearLayoutParameter_getGravity : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILinearLayoutParameter_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILinearLayoutParameter* ret = gui::UILinearLayoutParameter::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILinearLayoutParameter>(cx, (gui::UILinearLayoutParameter*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILinearLayoutParameter_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILinearLayoutParameter_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILinearLayoutParameter* cobj = new gui::UILinearLayoutParameter();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILinearLayoutParameter> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILinearLayoutParameter");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILinearLayoutParameter_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UILayoutParameter_prototype;

void js_cocos2dx_gui_UILinearLayoutParameter_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILinearLayoutParameter)", obj);
}

void js_register_cocos2dx_gui_UILinearLayoutParameter(JSContext *cx, JSObject *global) {
	jsb_UILinearLayoutParameter_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILinearLayoutParameter_class->name = "UILinearLayoutParameter";
	jsb_UILinearLayoutParameter_class->addProperty = JS_PropertyStub;
	jsb_UILinearLayoutParameter_class->delProperty = JS_DeletePropertyStub;
	jsb_UILinearLayoutParameter_class->getProperty = JS_PropertyStub;
	jsb_UILinearLayoutParameter_class->setProperty = JS_StrictPropertyStub;
	jsb_UILinearLayoutParameter_class->enumerate = JS_EnumerateStub;
	jsb_UILinearLayoutParameter_class->resolve = JS_ResolveStub;
	jsb_UILinearLayoutParameter_class->convert = JS_ConvertStub;
	jsb_UILinearLayoutParameter_class->finalize = js_cocos2dx_gui_UILinearLayoutParameter_finalize;
	jsb_UILinearLayoutParameter_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setGravity", js_cocos2dx_gui_UILinearLayoutParameter_setGravity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getGravity", js_cocos2dx_gui_UILinearLayoutParameter_getGravity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILinearLayoutParameter_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILinearLayoutParameter_prototype = JS_InitClass(
		cx, global,
		jsb_UILayoutParameter_prototype,
		jsb_UILinearLayoutParameter_class,
		js_cocos2dx_gui_UILinearLayoutParameter_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILinearLayoutParameter", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILinearLayoutParameter> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILinearLayoutParameter_class;
		p->proto = jsb_UILinearLayoutParameter_prototype;
		p->parentProto = jsb_UILayoutParameter_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIRelativeLayoutParameter_class;
JSObject *jsb_UIRelativeLayoutParameter_prototype;

JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_setAlign(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIRelativeLayoutParameter* cobj = (gui::UIRelativeLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_setAlign : Invalid Native Object");
	if (argc == 1) {
		gui::UIRelativeAlign arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_setAlign : Error processing arguments");
		cobj->setAlign(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_setAlign : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeToWidgetName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIRelativeLayoutParameter* cobj = (gui::UIRelativeLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeToWidgetName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeToWidgetName : Error processing arguments");
		cobj->setRelativeToWidgetName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeToWidgetName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIRelativeLayoutParameter* cobj = (gui::UIRelativeLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeName : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getRelativeName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeName : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeToWidgetName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIRelativeLayoutParameter* cobj = (gui::UIRelativeLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeToWidgetName : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getRelativeToWidgetName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeToWidgetName : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIRelativeLayoutParameter* cobj = (gui::UIRelativeLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeName : Error processing arguments");
		cobj->setRelativeName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_getAlign(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIRelativeLayoutParameter* cobj = (gui::UIRelativeLayoutParameter *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIRelativeLayoutParameter_getAlign : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getAlign();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_getAlign : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIRelativeLayoutParameter* ret = gui::UIRelativeLayoutParameter::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIRelativeLayoutParameter>(cx, (gui::UIRelativeLayoutParameter*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIRelativeLayoutParameter_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIRelativeLayoutParameter* cobj = new gui::UIRelativeLayoutParameter();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UIRelativeLayoutParameter> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UIRelativeLayoutParameter");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIRelativeLayoutParameter_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UILayoutParameter_prototype;

void js_cocos2dx_gui_UIRelativeLayoutParameter_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIRelativeLayoutParameter)", obj);
}

void js_register_cocos2dx_gui_UIRelativeLayoutParameter(JSContext *cx, JSObject *global) {
	jsb_UIRelativeLayoutParameter_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIRelativeLayoutParameter_class->name = "UIRelativeLayoutParameter";
	jsb_UIRelativeLayoutParameter_class->addProperty = JS_PropertyStub;
	jsb_UIRelativeLayoutParameter_class->delProperty = JS_DeletePropertyStub;
	jsb_UIRelativeLayoutParameter_class->getProperty = JS_PropertyStub;
	jsb_UIRelativeLayoutParameter_class->setProperty = JS_StrictPropertyStub;
	jsb_UIRelativeLayoutParameter_class->enumerate = JS_EnumerateStub;
	jsb_UIRelativeLayoutParameter_class->resolve = JS_ResolveStub;
	jsb_UIRelativeLayoutParameter_class->convert = JS_ConvertStub;
	jsb_UIRelativeLayoutParameter_class->finalize = js_cocos2dx_gui_UIRelativeLayoutParameter_finalize;
	jsb_UIRelativeLayoutParameter_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAlign", js_cocos2dx_gui_UIRelativeLayoutParameter_setAlign, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setRelativeToWidgetName", js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeToWidgetName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRelativeName", js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRelativeToWidgetName", js_cocos2dx_gui_UIRelativeLayoutParameter_getRelativeToWidgetName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setRelativeName", js_cocos2dx_gui_UIRelativeLayoutParameter_setRelativeName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getAlign", js_cocos2dx_gui_UIRelativeLayoutParameter_getAlign, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UIRelativeLayoutParameter_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIRelativeLayoutParameter_prototype = JS_InitClass(
		cx, global,
		jsb_UILayoutParameter_prototype,
		jsb_UIRelativeLayoutParameter_class,
		js_cocos2dx_gui_UIRelativeLayoutParameter_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIRelativeLayoutParameter", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIRelativeLayoutParameter> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIRelativeLayoutParameter_class;
		p->proto = jsb_UIRelativeLayoutParameter_prototype;
		p->parentProto = jsb_UILayoutParameter_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIWidget_class;
JSObject *jsb_UIWidget_prototype;

JSBool js_cocos2dx_gui_UIWidget_addChild(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_addChild : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_addChild : Error processing arguments");
		bool ret = cobj->addChild(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_addChild : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setActionTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setActionTag : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setActionTag : Error processing arguments");
		cobj->setActionTag(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setActionTag : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setCascadeOpacityEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setCascadeOpacityEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setCascadeOpacityEnabled : Error processing arguments");
		cobj->setCascadeOpacityEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setCascadeOpacityEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getChildren(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getChildren : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Array* ret = cobj->getChildren();
		jsval jsret;
		jsret = ccarray_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getChildren : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getPositionType(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getPositionType : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getPositionType();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getPositionType : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getChildByName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getChildByName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getChildByName : Error processing arguments");
		gui::UIWidget* ret = cobj->getChildByName(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getChildByName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isFlipX : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipX();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isFlipX : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isFlipY : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipY();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isFlipY : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_didNotSelectSelf(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_didNotSelectSelf : Invalid Native Object");
	if (argc == 0) {
		cobj->didNotSelectSelf();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_didNotSelectSelf : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setFocused(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setFocused : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setFocused : Error processing arguments");
		cobj->setFocused(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setFocused : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setZOrder(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setZOrder : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setZOrder : Error processing arguments");
		cobj->setZOrder(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setZOrder : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setScaleY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setScaleY : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setScaleY : Error processing arguments");
		cobj->setScaleY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setScaleY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setScaleX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setScaleX : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setScaleX : Error processing arguments");
		cobj->setScaleX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setScaleX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getLayoutParameter(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getLayoutParameter : Invalid Native Object");
	if (argc == 1) {
		gui::LayoutParameterType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getLayoutParameter : Error processing arguments");
		gui::UILayoutParameter* ret = cobj->getLayoutParameter(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UILayoutParameter>(cx, (gui::UILayoutParameter*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getLayoutParameter : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getColor : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Color3B& ret = cobj->getColor();
		jsval jsret;
		jsret = cccolor3b_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getColor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isBright(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isBright : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isBright();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isBright : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getTag : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getTag();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getTag : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_addRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_addRenderer : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Node* arg0;
		int arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_addRenderer : Error processing arguments");
		cobj->addRenderer(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_addRenderer : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getSizeType(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getSizeType : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getSizeType();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getSizeType : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getPositionPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getPositionPercent : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Point& ret = cobj->getPositionPercent();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getPositionPercent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_removeChild(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_removeChild : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_removeChild : Error processing arguments");
		bool ret = cobj->removeChild(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_removeChild : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_convertToWorldSpace(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_convertToWorldSpace : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_convertToWorldSpace : Error processing arguments");
		cocos2d::Point ret = cobj->convertToWorldSpace(arg0);
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_convertToWorldSpace : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setSize : Error processing arguments");
		cobj->setSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_removeAllChildren(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_removeAllChildren : Invalid Native Object");
	if (argc == 0) {
		cobj->removeAllChildren();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_removeAllChildren : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getRotationX(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getRotationX : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getRotationX();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getRotationX : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getRotationY(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getRotationY : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getRotationY();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getRotationY : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getSizePercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getSizePercent : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Point& ret = cobj->getSizePercent();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getSizePercent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setPositionType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setPositionType : Invalid Native Object");
	if (argc == 1) {
		gui::PositionType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setPositionType : Error processing arguments");
		cobj->setPositionType(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setPositionType : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isCascadeOpacityEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isCascadeOpacityEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isCascadeOpacityEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isCascadeOpacityEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setParent : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setParent : Error processing arguments");
		cobj->setParent(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setParent : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getName : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getName : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isTouchEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isTouchEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isTouchEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setTouchEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setTouchEnabled : Error processing arguments");
		cobj->setTouchEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setTouchEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setLayoutParameter(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setLayoutParameter : Invalid Native Object");
	if (argc == 1) {
		gui::UILayoutParameter* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UILayoutParameter*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setLayoutParameter : Error processing arguments");
		cobj->setLayoutParameter(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setLayoutParameter : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_clippingParentAreaContainPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_clippingParentAreaContainPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_clippingParentAreaContainPoint : Error processing arguments");
		bool ret = cobj->clippingParentAreaContainPoint(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_clippingParentAreaContainPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setPosition : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setPosition : Error processing arguments");
		cobj->setPosition(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setPosition : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_removeRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_removeRenderer : Invalid Native Object");
	if (argc == 2) {
		cocos2d::Node* arg0;
		JSBool arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Node*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_removeRenderer : Error processing arguments");
		cobj->removeRenderer(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_removeRenderer : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_stopActionByTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_stopActionByTag : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_stopActionByTag : Error processing arguments");
		cobj->stopActionByTag(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_stopActionByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_reorderChild(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_reorderChild : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_reorderChild : Error processing arguments");
		cobj->reorderChild(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_reorderChild : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getScale(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getScale : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getScale();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getScale : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setColor : Error processing arguments");
		cobj->setColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getAnchorPoint : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Point& ret = cobj->getAnchorPoint();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isFocused(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isFocused : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFocused();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isFocused : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isVisible : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isVisible();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isVisible : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getLeftInParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getLeftInParent : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getLeftInParent();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getLeftInParent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setPositionPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setPositionPercent : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setPositionPercent : Error processing arguments");
		cobj->setPositionPercent(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setPositionPercent : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getRotation(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getRotation : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getRotation();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getRotation : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getBottomInParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getBottomInParent : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getBottomInParent();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getBottomInParent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_ignoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_ignoreContentAdaptWithSize : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_ignoreContentAdaptWithSize : Error processing arguments");
		cobj->ignoreContentAdaptWithSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_ignoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getZOrder(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getZOrder : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getZOrder();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getZOrder : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_runAction(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_runAction : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Action* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Action*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_runAction : Error processing arguments");
		cocos2d::Action* ret = cobj->runAction(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Action>(cx, (cocos2d::Action*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_runAction : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_stopAllActions(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_stopAllActions : Invalid Native Object");
	if (argc == 0) {
		cobj->stopAllActions();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_stopAllActions : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getActionTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getActionTag : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getActionTag();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getActionTag : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getActionByTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getActionByTag : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getActionByTag : Error processing arguments");
		cocos2d::Action* ret = cobj->getActionByTag(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Action>(cx, (cocos2d::Action*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getActionByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setRotationX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setRotationX : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setRotationX : Error processing arguments");
		cobj->setRotationX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setRotationX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setRotationY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setRotationY : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setRotationY : Error processing arguments");
		cobj->setRotationY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setRotationY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setBrightStyle(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setBrightStyle : Invalid Native Object");
	if (argc == 1) {
		gui::BrightStyle arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setBrightStyle : Error processing arguments");
		cobj->setBrightStyle(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setBrightStyle : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setName : Error processing arguments");
		cobj->setName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setFlipY : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setFlipY : Error processing arguments");
		cobj->setFlipY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setFlipY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setFlipX : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setFlipX : Error processing arguments");
		cobj->setFlipX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setFlipX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setUpdateEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setUpdateEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setUpdateEnabled : Error processing arguments");
		cobj->setUpdateEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setUpdateEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setRotation(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setRotation : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setRotation : Error processing arguments");
		cobj->setRotation(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setRotation : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setActionManager(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setActionManager : Invalid Native Object");
	if (argc == 1) {
		cocos2d::ActionManager* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::ActionManager*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setActionManager : Error processing arguments");
		cobj->setActionManager(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setActionManager : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getPosition : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Point& ret = cobj->getPosition();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getParent : Invalid Native Object");
	if (argc == 0) {
		gui::UIWidget* ret = cobj->getParent();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getParent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_hitTest(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_hitTest : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_hitTest : Error processing arguments");
		bool ret = cobj->hitTest(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_hitTest : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setVisible : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setVisible : Error processing arguments");
		cobj->setVisible(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setVisible : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setSizePercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setSizePercent : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setSizePercent : Error processing arguments");
		cobj->setSizePercent(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setSizePercent : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setEnabled : Error processing arguments");
		cobj->setEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setScale(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setScale : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setScale : Error processing arguments");
		cobj->setScale(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setScale : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getTouchEndPos(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getTouchEndPos : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Point& ret = cobj->getTouchEndPos();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getTouchEndPos : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getChildByTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getChildByTag : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getChildByTag : Error processing arguments");
		gui::UIWidget* ret = cobj->getChildByTag(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getChildByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isIgnoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isIgnoreContentAdaptWithSize : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isIgnoreContentAdaptWithSize();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isIgnoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isUpdateEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isUpdateEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isUpdateEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isUpdateEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_updateSizeAndPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_updateSizeAndPosition : Invalid Native Object");
	if (argc == 0) {
		cobj->updateSizeAndPosition();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_updateSizeAndPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getWidgetType(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getWidgetType : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getWidgetType();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getWidgetType : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getScaleY(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getScaleY : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getScaleY();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getScaleY : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getScaleX(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getScaleX : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getScaleX();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getScaleX : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setCascadeColorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setCascadeColorEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setCascadeColorEnabled : Error processing arguments");
		cobj->setCascadeColorEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setCascadeColorEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setOpacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setOpacity : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setOpacity : Error processing arguments");
		cobj->setOpacity(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getOpacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getOpacity : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getOpacity();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getOpacity : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getTouchMovePos(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getTouchMovePos : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Point& ret = cobj->getTouchMovePos();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getTouchMovePos : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_removeFromParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_removeFromParent : Invalid Native Object");
	if (argc == 0) {
		cobj->removeFromParent();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_removeFromParent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getWorldPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getWorldPosition : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Point ret = cobj->getWorldPosition();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getWorldPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_clone(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_clone : Invalid Native Object");
	if (argc == 0) {
		gui::UIWidget* ret = cobj->clone();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_clone : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_isCascadeColorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_isCascadeColorEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isCascadeColorEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_isCascadeColorEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_checkChildInfo(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_checkChildInfo : Invalid Native Object");
	if (argc == 3) {
		int arg0;
		gui::UIWidget* arg1;
		cocos2d::Point arg2;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		do {
			if (!argv[1].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg1 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg1, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_ccpoint(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_checkChildInfo : Error processing arguments");
		cobj->checkChildInfo(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_checkChildInfo : wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getTopInParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getTopInParent : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getTopInParent();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getTopInParent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getRightInParent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getRightInParent : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getRightInParent();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getRightInParent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setTag : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setTag : Error processing arguments");
		cobj->setTag(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setTag : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getTouchStartPos(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getTouchStartPos : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Point& ret = cobj->getTouchStartPos();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getTouchStartPos : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setSizeType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setSizeType : Invalid Native Object");
	if (argc == 1) {
		gui::SizeType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setSizeType : Error processing arguments");
		cobj->setSizeType(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setSizeType : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_stopAction(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_stopAction : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Action* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (cocos2d::Action*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_stopAction : Error processing arguments");
		cobj->stopAction(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_stopAction : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_setBright(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setBright : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_setBright : Error processing arguments");
		cobj->setBright(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_setBright : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_getActionManager(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIWidget* cobj = (gui::UIWidget *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIWidget_getActionManager : Invalid Native Object");
	if (argc == 0) {
		cocos2d::ActionManager* ret = cobj->getActionManager();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::ActionManager>(cx, (cocos2d::ActionManager*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_getActionManager : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIWidget_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIWidget* ret = gui::UIWidget::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIWidget_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIWidget* cobj = new gui::UIWidget();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UIWidget> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UIWidget");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIWidget_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_cocos2dx_gui_UIWidget_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIWidget)", obj);
}

void js_register_cocos2dx_gui_UIWidget(JSContext *cx, JSObject *global) {
	jsb_UIWidget_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIWidget_class->name = "UIWidget";
	jsb_UIWidget_class->addProperty = JS_PropertyStub;
	jsb_UIWidget_class->delProperty = JS_DeletePropertyStub;
	jsb_UIWidget_class->getProperty = JS_PropertyStub;
	jsb_UIWidget_class->setProperty = JS_StrictPropertyStub;
	jsb_UIWidget_class->enumerate = JS_EnumerateStub;
	jsb_UIWidget_class->resolve = JS_ResolveStub;
	jsb_UIWidget_class->convert = JS_ConvertStub;
	jsb_UIWidget_class->finalize = js_cocos2dx_gui_UIWidget_finalize;
	jsb_UIWidget_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("addChild", js_cocos2dx_gui_UIWidget_addChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UIWidget_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setActionTag", js_cocos2dx_gui_UIWidget_setActionTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UIWidget_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCascadeOpacityEnabled", js_cocos2dx_gui_UIWidget_setCascadeOpacityEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getChildren", js_cocos2dx_gui_UIWidget_getChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPositionType", js_cocos2dx_gui_UIWidget_getPositionType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getChildByName", js_cocos2dx_gui_UIWidget_getChildByName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isEnabled", js_cocos2dx_gui_UIWidget_isEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipX", js_cocos2dx_gui_UIWidget_isFlipX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipY", js_cocos2dx_gui_UIWidget_isFlipY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("didNotSelectSelf", js_cocos2dx_gui_UIWidget_didNotSelectSelf, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFocused", js_cocos2dx_gui_UIWidget_setFocused, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setZOrder", js_cocos2dx_gui_UIWidget_setZOrder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScaleY", js_cocos2dx_gui_UIWidget_setScaleY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScaleX", js_cocos2dx_gui_UIWidget_setScaleX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getLayoutParameter", js_cocos2dx_gui_UIWidget_getLayoutParameter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getColor", js_cocos2dx_gui_UIWidget_getColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isBright", js_cocos2dx_gui_UIWidget_isBright, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTag", js_cocos2dx_gui_UIWidget_getTag, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("addRenderer", js_cocos2dx_gui_UIWidget_addRenderer, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSize", js_cocos2dx_gui_UIWidget_getSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSizeType", js_cocos2dx_gui_UIWidget_getSizeType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPositionPercent", js_cocos2dx_gui_UIWidget_getPositionPercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeChild", js_cocos2dx_gui_UIWidget_removeChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("convertToWorldSpace", js_cocos2dx_gui_UIWidget_convertToWorldSpace, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSize", js_cocos2dx_gui_UIWidget_setSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeAllChildren", js_cocos2dx_gui_UIWidget_removeAllChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRotationX", js_cocos2dx_gui_UIWidget_getRotationX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRotationY", js_cocos2dx_gui_UIWidget_getRotationY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSizePercent", js_cocos2dx_gui_UIWidget_getSizePercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPositionType", js_cocos2dx_gui_UIWidget_setPositionType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isCascadeOpacityEnabled", js_cocos2dx_gui_UIWidget_isCascadeOpacityEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setParent", js_cocos2dx_gui_UIWidget_setParent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getName", js_cocos2dx_gui_UIWidget_getName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isTouchEnabled", js_cocos2dx_gui_UIWidget_isTouchEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTouchEnabled", js_cocos2dx_gui_UIWidget_setTouchEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setLayoutParameter", js_cocos2dx_gui_UIWidget_setLayoutParameter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("clippingParentAreaContainPoint", js_cocos2dx_gui_UIWidget_clippingParentAreaContainPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPosition", js_cocos2dx_gui_UIWidget_setPosition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeRenderer", js_cocos2dx_gui_UIWidget_removeRenderer, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("stopActionByTag", js_cocos2dx_gui_UIWidget_stopActionByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("reorderChild", js_cocos2dx_gui_UIWidget_reorderChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getScale", js_cocos2dx_gui_UIWidget_getScale, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setColor", js_cocos2dx_gui_UIWidget_setColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getAnchorPoint", js_cocos2dx_gui_UIWidget_getAnchorPoint, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFocused", js_cocos2dx_gui_UIWidget_isFocused, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isVisible", js_cocos2dx_gui_UIWidget_isVisible, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UIWidget_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getLeftInParent", js_cocos2dx_gui_UIWidget_getLeftInParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPositionPercent", js_cocos2dx_gui_UIWidget_setPositionPercent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRotation", js_cocos2dx_gui_UIWidget_getRotation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBottomInParent", js_cocos2dx_gui_UIWidget_getBottomInParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("ignoreContentAdaptWithSize", js_cocos2dx_gui_UIWidget_ignoreContentAdaptWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getZOrder", js_cocos2dx_gui_UIWidget_getZOrder, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("runAction", js_cocos2dx_gui_UIWidget_runAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("stopAllActions", js_cocos2dx_gui_UIWidget_stopAllActions, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getActionTag", js_cocos2dx_gui_UIWidget_getActionTag, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getActionByTag", js_cocos2dx_gui_UIWidget_getActionByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setRotationX", js_cocos2dx_gui_UIWidget_setRotationX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setRotationY", js_cocos2dx_gui_UIWidget_setRotationY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBrightStyle", js_cocos2dx_gui_UIWidget_setBrightStyle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setName", js_cocos2dx_gui_UIWidget_setName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipY", js_cocos2dx_gui_UIWidget_setFlipY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipX", js_cocos2dx_gui_UIWidget_setFlipX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setUpdateEnabled", js_cocos2dx_gui_UIWidget_setUpdateEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setRotation", js_cocos2dx_gui_UIWidget_setRotation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setActionManager", js_cocos2dx_gui_UIWidget_setActionManager, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPosition", js_cocos2dx_gui_UIWidget_getPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getParent", js_cocos2dx_gui_UIWidget_getParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("hitTest", js_cocos2dx_gui_UIWidget_hitTest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setVisible", js_cocos2dx_gui_UIWidget_setVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSizePercent", js_cocos2dx_gui_UIWidget_setSizePercent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setEnabled", js_cocos2dx_gui_UIWidget_setEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScale", js_cocos2dx_gui_UIWidget_setScale, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTouchEndPos", js_cocos2dx_gui_UIWidget_getTouchEndPos, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getChildByTag", js_cocos2dx_gui_UIWidget_getChildByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isIgnoreContentAdaptWithSize", js_cocos2dx_gui_UIWidget_isIgnoreContentAdaptWithSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isUpdateEnabled", js_cocos2dx_gui_UIWidget_isUpdateEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("updateSizeAndPosition", js_cocos2dx_gui_UIWidget_updateSizeAndPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRenderer", js_cocos2dx_gui_UIWidget_getRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getWidgetType", js_cocos2dx_gui_UIWidget_getWidgetType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getScaleY", js_cocos2dx_gui_UIWidget_getScaleY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getScaleX", js_cocos2dx_gui_UIWidget_getScaleX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCascadeColorEnabled", js_cocos2dx_gui_UIWidget_setCascadeColorEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setOpacity", js_cocos2dx_gui_UIWidget_setOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UIWidget_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getOpacity", js_cocos2dx_gui_UIWidget_getOpacity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTouchMovePos", js_cocos2dx_gui_UIWidget_getTouchMovePos, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeFromParent", js_cocos2dx_gui_UIWidget_removeFromParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getWorldPosition", js_cocos2dx_gui_UIWidget_getWorldPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("clone", js_cocos2dx_gui_UIWidget_clone, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isCascadeColorEnabled", js_cocos2dx_gui_UIWidget_isCascadeColorEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("checkChildInfo", js_cocos2dx_gui_UIWidget_checkChildInfo, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTopInParent", js_cocos2dx_gui_UIWidget_getTopInParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getRightInParent", js_cocos2dx_gui_UIWidget_getRightInParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTag", js_cocos2dx_gui_UIWidget_setTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTouchStartPos", js_cocos2dx_gui_UIWidget_getTouchStartPos, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSizeType", js_cocos2dx_gui_UIWidget_setSizeType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("stopAction", js_cocos2dx_gui_UIWidget_stopAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBright", js_cocos2dx_gui_UIWidget_setBright, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getActionManager", js_cocos2dx_gui_UIWidget_getActionManager, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UIWidget_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIWidget_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_UIWidget_class,
		js_cocos2dx_gui_UIWidget_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIWidget", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIWidget> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIWidget_class;
		p->proto = jsb_UIWidget_prototype;
		p->parentProto = NULL;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UILayout_class;
JSObject *jsb_UILayout_prototype;

JSBool js_cocos2dx_gui_UILayout_setBackGroundColorVector(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundColorVector : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundColorVector : Error processing arguments");
		cobj->setBackGroundColorVector(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setBackGroundColorVector : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_isClippingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_isClippingEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isClippingEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_isClippingEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_getBackGroundImageTextureSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_getBackGroundImageTextureSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getBackGroundImageTextureSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_getBackGroundImageTextureSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_getLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_getLayoutType : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getLayoutType();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_getLayoutType : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setColor : Error processing arguments");
		cobj->setColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setBackGroundColorType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundColorType : Invalid Native Object");
	if (argc == 1) {
		gui::LayoutBackGroundColorType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundColorType : Error processing arguments");
		cobj->setBackGroundColorType(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setBackGroundColorType : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setBackGroundImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundImage : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundImage : Error processing arguments");
		cobj->setBackGroundImage(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundImage : Error processing arguments");
		cobj->setBackGroundImage(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setBackGroundImage : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setBackGroundColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;

	JSObject *obj = NULL;
	gui::UILayout* cobj = NULL;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundColor : Invalid Native Object");
	do {
		if (argc == 2) {
			cocos2d::Color3B arg0;
			ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cocos2d::Color3B arg1;
			ok &= jsval_to_cccolor3b(cx, argv[1], &arg1);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->setBackGroundColor(arg0, arg1);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	do {
		if (argc == 1) {
			cocos2d::Color3B arg0;
			ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
			if (!ok) { ok = JS_TRUE; break; }
			cobj->setBackGroundColor(arg0);
			JS_SET_RVAL(cx, vp, JSVAL_VOID);
			return JS_TRUE;
		}
	} while(0);

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setBackGroundColor : wrong number of arguments");
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setOpacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setOpacity : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setOpacity : Error processing arguments");
		cobj->setOpacity(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_hitTest(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_hitTest : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_hitTest : Error processing arguments");
		bool ret = cobj->hitTest(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_hitTest : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setBackGroundColorOpacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundColorOpacity : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundColorOpacity : Error processing arguments");
		cobj->setBackGroundColorOpacity(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setBackGroundColorOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setBackGroundImageCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundImageCapInsets : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundImageCapInsets : Error processing arguments");
		cobj->setBackGroundImageCapInsets(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setBackGroundImageCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_addChild(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_addChild : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_addChild : Error processing arguments");
		bool ret = cobj->addChild(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_addChild : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_removeBackGroundImage(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_removeBackGroundImage : Invalid Native Object");
	if (argc == 0) {
		cobj->removeBackGroundImage();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_removeBackGroundImage : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setBackGroundImageScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundImageScale9Enabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setBackGroundImageScale9Enabled : Error processing arguments");
		cobj->setBackGroundImageScale9Enabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setBackGroundImageScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_doLayout(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_doLayout : Invalid Native Object");
	if (argc == 0) {
		cobj->doLayout();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_doLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setClippingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setClippingEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setClippingEnabled : Error processing arguments");
		cobj->setClippingEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setClippingEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_setLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayout* cobj = (gui::UILayout *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setLayoutType : Invalid Native Object");
	if (argc == 1) {
		gui::LayoutType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayout_setLayoutType : Error processing arguments");
		cobj->setLayoutType(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_setLayoutType : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayout_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILayout* ret = gui::UILayout::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILayout>(cx, (gui::UILayout*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILayout_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILayout* cobj = new gui::UILayout();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILayout> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILayout");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayout_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UILayout_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILayout)", obj);
}

void js_register_cocos2dx_gui_UILayout(JSContext *cx, JSObject *global) {
	jsb_UILayout_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILayout_class->name = "UILayout";
	jsb_UILayout_class->addProperty = JS_PropertyStub;
	jsb_UILayout_class->delProperty = JS_DeletePropertyStub;
	jsb_UILayout_class->getProperty = JS_PropertyStub;
	jsb_UILayout_class->setProperty = JS_StrictPropertyStub;
	jsb_UILayout_class->enumerate = JS_EnumerateStub;
	jsb_UILayout_class->resolve = JS_ResolveStub;
	jsb_UILayout_class->convert = JS_ConvertStub;
	jsb_UILayout_class->finalize = js_cocos2dx_gui_UILayout_finalize;
	jsb_UILayout_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setBackGroundColorVector", js_cocos2dx_gui_UILayout_setBackGroundColorVector, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isClippingEnabled", js_cocos2dx_gui_UILayout_isClippingEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getBackGroundImageTextureSize", js_cocos2dx_gui_UILayout_getBackGroundImageTextureSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getLayoutType", js_cocos2dx_gui_UILayout_getLayoutType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setColor", js_cocos2dx_gui_UILayout_setColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackGroundColorType", js_cocos2dx_gui_UILayout_setBackGroundColorType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackGroundImage", js_cocos2dx_gui_UILayout_setBackGroundImage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackGroundColor", js_cocos2dx_gui_UILayout_setBackGroundColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UILayout_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setOpacity", js_cocos2dx_gui_UILayout_setOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("hitTest", js_cocos2dx_gui_UILayout_hitTest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackGroundColorOpacity", js_cocos2dx_gui_UILayout_setBackGroundColorOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackGroundImageCapInsets", js_cocos2dx_gui_UILayout_setBackGroundImageCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("addChild", js_cocos2dx_gui_UILayout_addChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeBackGroundImage", js_cocos2dx_gui_UILayout_removeBackGroundImage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBackGroundImageScale9Enabled", js_cocos2dx_gui_UILayout_setBackGroundImageScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("doLayout", js_cocos2dx_gui_UILayout_doLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setClippingEnabled", js_cocos2dx_gui_UILayout_setClippingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UILayout_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setLayoutType", js_cocos2dx_gui_UILayout_setLayoutType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILayout_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILayout_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UILayout_class,
		js_cocos2dx_gui_UILayout_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILayout", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILayout> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILayout_class;
		p->proto = jsb_UILayout_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIButton_class;
JSObject *jsb_UIButton_prototype;

JSBool js_cocos2dx_gui_UIButton_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_getTitleText(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_getTitleText : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getTitleText();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_getTitleText : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setTitleFontSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleFontSize : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleFontSize : Error processing arguments");
		cobj->setTitleFontSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setTitleFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setScale9Enabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setScale9Enabled : Error processing arguments");
		cobj->setScale9Enabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setTitleColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleColor : Error processing arguments");
		cobj->setTitleColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setTitleColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_ignoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_ignoreContentAdaptWithSize : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_ignoreContentAdaptWithSize : Error processing arguments");
		cobj->ignoreContentAdaptWithSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_ignoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setCapInsetsDisabledRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsetsDisabledRenderer : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsetsDisabledRenderer : Error processing arguments");
		cobj->setCapInsetsDisabledRenderer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setCapInsetsDisabledRenderer : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_isFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_isFlipX : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipX();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_isFlipX : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_isFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_isFlipY : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipY();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_isFlipY : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_loadTextureDisabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextureDisabled : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextureDisabled : Error processing arguments");
		cobj->loadTextureDisabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextureDisabled : Error processing arguments");
		cobj->loadTextureDisabled(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_loadTextureDisabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setTitleText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleText : Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleText : Error processing arguments");
		cobj->setTitleText(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setTitleText : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setCapInsetsNormalRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsetsNormalRenderer : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsetsNormalRenderer : Error processing arguments");
		cobj->setCapInsetsNormalRenderer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setCapInsetsNormalRenderer : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_loadTexturePressed(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTexturePressed : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTexturePressed : Error processing arguments");
		cobj->loadTexturePressed(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTexturePressed : Error processing arguments");
		cobj->loadTexturePressed(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_loadTexturePressed : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setFlipY : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setFlipY : Error processing arguments");
		cobj->setFlipY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setFlipY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setFlipX : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setFlipX : Error processing arguments");
		cobj->setFlipX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setFlipX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setTitleFontName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleFontName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setTitleFontName : Error processing arguments");
		cobj->setTitleFontName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setTitleFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_loadTextures(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextures : Invalid Native Object");
	if (argc == 3) {
		const char* arg0;
		const char* arg1;
		const char* arg2;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextures : Error processing arguments");
		cobj->loadTextures(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 4) {
		const char* arg0;
		const char* arg1;
		const char* arg2;
		gui::TextureResType arg3;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextures : Error processing arguments");
		cobj->loadTextures(arg0, arg1, arg2, arg3);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_loadTextures : wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_getTitleColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_getTitleColor : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Color3B& ret = cobj->getTitleColor();
		jsval jsret;
		jsret = cccolor3b_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_getTitleColor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_loadTextureNormal(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextureNormal : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextureNormal : Error processing arguments");
		cobj->loadTextureNormal(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_loadTextureNormal : Error processing arguments");
		cobj->loadTextureNormal(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_loadTextureNormal : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setColor : Error processing arguments");
		cobj->setColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setCapInsetsPressedRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsetsPressedRenderer : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsetsPressedRenderer : Error processing arguments");
		cobj->setCapInsetsPressedRenderer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setCapInsetsPressedRenderer : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_getTitleFontSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_getTitleFontSize : Invalid Native Object");
	if (argc == 0) {
		float ret = cobj->getTitleFontSize();
		jsval jsret;
		jsret = DOUBLE_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_getTitleFontSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_getTitleFontName(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_getTitleFontName : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getTitleFontName();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_getTitleFontName : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsets : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setCapInsets : Error processing arguments");
		cobj->setCapInsets(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_setPressedActionEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIButton* cobj = (gui::UIButton *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setPressedActionEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIButton_setPressedActionEnabled : Error processing arguments");
		cobj->setPressedActionEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_setPressedActionEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIButton_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIButton* ret = gui::UIButton::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIButton>(cx, (gui::UIButton*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIButton_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIButton* cobj = new gui::UIButton();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UIButton> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UIButton");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIButton_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UIButton_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIButton)", obj);
}

void js_register_cocos2dx_gui_UIButton(JSContext *cx, JSObject *global) {
	jsb_UIButton_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIButton_class->name = "UIButton";
	jsb_UIButton_class->addProperty = JS_PropertyStub;
	jsb_UIButton_class->delProperty = JS_DeletePropertyStub;
	jsb_UIButton_class->getProperty = JS_PropertyStub;
	jsb_UIButton_class->setProperty = JS_StrictPropertyStub;
	jsb_UIButton_class->enumerate = JS_EnumerateStub;
	jsb_UIButton_class->resolve = JS_ResolveStub;
	jsb_UIButton_class->convert = JS_ConvertStub;
	jsb_UIButton_class->finalize = js_cocos2dx_gui_UIButton_finalize;
	jsb_UIButton_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UIButton_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UIButton_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleText", js_cocos2dx_gui_UIButton_getTitleText, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleFontSize", js_cocos2dx_gui_UIButton_setTitleFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UIButton_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScale9Enabled", js_cocos2dx_gui_UIButton_setScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleColor", js_cocos2dx_gui_UIButton_setTitleColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("ignoreContentAdaptWithSize", js_cocos2dx_gui_UIButton_ignoreContentAdaptWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsetsDisabledRenderer", js_cocos2dx_gui_UIButton_setCapInsetsDisabledRenderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipX", js_cocos2dx_gui_UIButton_isFlipX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipY", js_cocos2dx_gui_UIButton_isFlipY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextureDisabled", js_cocos2dx_gui_UIButton_loadTextureDisabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UIButton_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleText", js_cocos2dx_gui_UIButton_setTitleText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsetsNormalRenderer", js_cocos2dx_gui_UIButton_setCapInsetsNormalRenderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTexturePressed", js_cocos2dx_gui_UIButton_loadTexturePressed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipY", js_cocos2dx_gui_UIButton_setFlipY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipX", js_cocos2dx_gui_UIButton_setFlipX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTitleFontName", js_cocos2dx_gui_UIButton_setTitleFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextures", js_cocos2dx_gui_UIButton_loadTextures, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleColor", js_cocos2dx_gui_UIButton_getTitleColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextureNormal", js_cocos2dx_gui_UIButton_loadTextureNormal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setColor", js_cocos2dx_gui_UIButton_setColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsetsPressedRenderer", js_cocos2dx_gui_UIButton_setCapInsetsPressedRenderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleFontSize", js_cocos2dx_gui_UIButton_getTitleFontSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getTitleFontName", js_cocos2dx_gui_UIButton_getTitleFontName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsets", js_cocos2dx_gui_UIButton_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPressedActionEnabled", js_cocos2dx_gui_UIButton_setPressedActionEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UIButton_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIButton_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UIButton_class,
		js_cocos2dx_gui_UIButton_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIButton", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIButton> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIButton_class;
		p->proto = jsb_UIButton_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UICheckBox_class;
JSObject *jsb_UICheckBox_prototype;

JSBool js_cocos2dx_gui_UICheckBox_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_getSelectedState(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_getSelectedState : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getSelectedState();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_getSelectedState : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_loadTextureBackGroundSelected(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundSelected : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundSelected : Error processing arguments");
		cobj->loadTextureBackGroundSelected(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundSelected : Error processing arguments");
		cobj->loadTextureBackGroundSelected(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundSelected : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_loadTextureBackGroundDisabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundDisabled : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundDisabled : Error processing arguments");
		cobj->loadTextureBackGroundDisabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundDisabled : Error processing arguments");
		cobj->loadTextureBackGroundDisabled(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_loadTextureBackGroundDisabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_setFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setFlipY : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setFlipY : Error processing arguments");
		cobj->setFlipY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_setFlipY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_setFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setFlipX : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setFlipX : Error processing arguments");
		cobj->setFlipX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_setFlipX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_isFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_isFlipX : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipX();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_isFlipX : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_isFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_isFlipY : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipY();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_isFlipY : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_loadTextureFrontCross(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCross : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCross : Error processing arguments");
		cobj->loadTextureFrontCross(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCross : Error processing arguments");
		cobj->loadTextureFrontCross(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCross : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_loadTextures(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextures : Invalid Native Object");
	if (argc == 5) {
		const char* arg0;
		const char* arg1;
		const char* arg2;
		const char* arg3;
		const char* arg4;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
		std::string arg3_tmp; ok &= jsval_to_std_string(cx, argv[3], &arg3_tmp); arg3 = arg3_tmp.c_str();
		std::string arg4_tmp; ok &= jsval_to_std_string(cx, argv[4], &arg4_tmp); arg4 = arg4_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextures : Error processing arguments");
		cobj->loadTextures(arg0, arg1, arg2, arg3, arg4);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 6) {
		const char* arg0;
		const char* arg1;
		const char* arg2;
		const char* arg3;
		const char* arg4;
		gui::TextureResType arg5;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
		std::string arg3_tmp; ok &= jsval_to_std_string(cx, argv[3], &arg3_tmp); arg3 = arg3_tmp.c_str();
		std::string arg4_tmp; ok &= jsval_to_std_string(cx, argv[4], &arg4_tmp); arg4 = arg4_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[5], (int32_t *)&arg5);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextures : Error processing arguments");
		cobj->loadTextures(arg0, arg1, arg2, arg3, arg4, arg5);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_loadTextures : wrong number of arguments: %d, was expecting %d", argc, 5);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_loadTextureBackGround(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGround : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGround : Error processing arguments");
		cobj->loadTextureBackGround(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureBackGround : Error processing arguments");
		cobj->loadTextureBackGround(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_loadTextureBackGround : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_setSelectedState(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setSelectedState : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_setSelectedState : Error processing arguments");
		cobj->setSelectedState(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_setSelectedState : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_loadTextureFrontCrossDisabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UICheckBox* cobj = (gui::UICheckBox *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCrossDisabled : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCrossDisabled : Error processing arguments");
		cobj->loadTextureFrontCrossDisabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCrossDisabled : Error processing arguments");
		cobj->loadTextureFrontCrossDisabled(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_loadTextureFrontCrossDisabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UICheckBox_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UICheckBox* ret = gui::UICheckBox::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UICheckBox>(cx, (gui::UICheckBox*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UICheckBox_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UICheckBox* cobj = new gui::UICheckBox();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UICheckBox> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UICheckBox");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UICheckBox_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UICheckBox_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UICheckBox)", obj);
}

void js_register_cocos2dx_gui_UICheckBox(JSContext *cx, JSObject *global) {
	jsb_UICheckBox_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UICheckBox_class->name = "UICheckBox";
	jsb_UICheckBox_class->addProperty = JS_PropertyStub;
	jsb_UICheckBox_class->delProperty = JS_DeletePropertyStub;
	jsb_UICheckBox_class->getProperty = JS_PropertyStub;
	jsb_UICheckBox_class->setProperty = JS_StrictPropertyStub;
	jsb_UICheckBox_class->enumerate = JS_EnumerateStub;
	jsb_UICheckBox_class->resolve = JS_ResolveStub;
	jsb_UICheckBox_class->convert = JS_ConvertStub;
	jsb_UICheckBox_class->finalize = js_cocos2dx_gui_UICheckBox_finalize;
	jsb_UICheckBox_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UICheckBox_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getSelectedState", js_cocos2dx_gui_UICheckBox_getSelectedState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextureBackGroundSelected", js_cocos2dx_gui_UICheckBox_loadTextureBackGroundSelected, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextureBackGroundDisabled", js_cocos2dx_gui_UICheckBox_loadTextureBackGroundDisabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UICheckBox_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipY", js_cocos2dx_gui_UICheckBox_setFlipY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipX", js_cocos2dx_gui_UICheckBox_setFlipX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipX", js_cocos2dx_gui_UICheckBox_isFlipX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipY", js_cocos2dx_gui_UICheckBox_isFlipY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextureFrontCross", js_cocos2dx_gui_UICheckBox_loadTextureFrontCross, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UICheckBox_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UICheckBox_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextures", js_cocos2dx_gui_UICheckBox_loadTextures, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextureBackGround", js_cocos2dx_gui_UICheckBox_loadTextureBackGround, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setSelectedState", js_cocos2dx_gui_UICheckBox_setSelectedState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTextureFrontCrossDisabled", js_cocos2dx_gui_UICheckBox_loadTextureFrontCrossDisabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UICheckBox_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UICheckBox_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UICheckBox_class,
		js_cocos2dx_gui_UICheckBox_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UICheckBox", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UICheckBox> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UICheckBox_class;
		p->proto = jsb_UICheckBox_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIImageView_class;
JSObject *jsb_UIImageView_prototype;

JSBool js_cocos2dx_gui_UIImageView_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_ignoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_ignoreContentAdaptWithSize : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_ignoreContentAdaptWithSize : Error processing arguments");
		cobj->ignoreContentAdaptWithSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_ignoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_loadTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_loadTexture : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_loadTexture : Error processing arguments");
		cobj->loadTexture(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_loadTexture : Error processing arguments");
		cobj->loadTexture(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_loadTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_setDoubleClickEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setDoubleClickEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setDoubleClickEnabled : Error processing arguments");
		cobj->setDoubleClickEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_setDoubleClickEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_setFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setFlipY : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setFlipY : Error processing arguments");
		cobj->setFlipY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_setFlipY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_setFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setFlipX : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setFlipX : Error processing arguments");
		cobj->setFlipX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_setFlipX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_isFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_isFlipX : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipX();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_isFlipX : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_isFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_isFlipY : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipY();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_isFlipY : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_setScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setScale9Enabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setScale9Enabled : Error processing arguments");
		cobj->setScale9Enabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_setScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_setTextureRect(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setTextureRect : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setTextureRect : Error processing arguments");
		cobj->setTextureRect(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_setTextureRect : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setCapInsets : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_setCapInsets : Error processing arguments");
		cobj->setCapInsets(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_setCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIImageView* cobj = (gui::UIImageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIImageView_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIImageView_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIImageView* ret = gui::UIImageView::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIImageView>(cx, (gui::UIImageView*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIImageView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIImageView* cobj = new gui::UIImageView();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UIImageView> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UIImageView");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIImageView_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UIImageView_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIImageView)", obj);
}

void js_register_cocos2dx_gui_UIImageView(JSContext *cx, JSObject *global) {
	jsb_UIImageView_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIImageView_class->name = "UIImageView";
	jsb_UIImageView_class->addProperty = JS_PropertyStub;
	jsb_UIImageView_class->delProperty = JS_DeletePropertyStub;
	jsb_UIImageView_class->getProperty = JS_PropertyStub;
	jsb_UIImageView_class->setProperty = JS_StrictPropertyStub;
	jsb_UIImageView_class->enumerate = JS_EnumerateStub;
	jsb_UIImageView_class->resolve = JS_ResolveStub;
	jsb_UIImageView_class->convert = JS_ConvertStub;
	jsb_UIImageView_class->finalize = js_cocos2dx_gui_UIImageView_finalize;
	jsb_UIImageView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UIImageView_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UIImageView_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("ignoreContentAdaptWithSize", js_cocos2dx_gui_UIImageView_ignoreContentAdaptWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTexture", js_cocos2dx_gui_UIImageView_loadTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDoubleClickEnabled", js_cocos2dx_gui_UIImageView_setDoubleClickEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UIImageView_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipY", js_cocos2dx_gui_UIImageView_setFlipY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipX", js_cocos2dx_gui_UIImageView_setFlipX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipX", js_cocos2dx_gui_UIImageView_isFlipX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipY", js_cocos2dx_gui_UIImageView_isFlipY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScale9Enabled", js_cocos2dx_gui_UIImageView_setScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTextureRect", js_cocos2dx_gui_UIImageView_setTextureRect, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsets", js_cocos2dx_gui_UIImageView_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UIImageView_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UIImageView_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIImageView_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UIImageView_class,
		js_cocos2dx_gui_UIImageView_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIImageView", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIImageView> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIImageView_class;
		p->proto = jsb_UIImageView_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UILabel_class;
JSObject *jsb_UILabel_prototype;

JSBool js_cocos2dx_gui_UILabel_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_getStringValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_getStringValue : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getStringValue();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_getStringValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setScale(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setScale : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setScale : Error processing arguments");
		cobj->setScale(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setScale : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setTextVerticalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTextVerticalAlignment : Invalid Native Object");
	if (argc == 1) {
		cocos2d::TextVAlignment arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTextVerticalAlignment : Error processing arguments");
		cobj->setTextVerticalAlignment(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setTextVerticalAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setFontName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFontName : Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFontName : Error processing arguments");
		cobj->setFontName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setTouchScaleChangeEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTouchScaleChangeEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTouchScaleChangeEnabled : Error processing arguments");
		cobj->setTouchScaleChangeEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setTouchScaleChangeEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_isFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_isFlipX : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipX();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_isFlipX : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_isFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_isFlipY : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isFlipY();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_isFlipY : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_isTouchScaleChangeEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_isTouchScaleChangeEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isTouchScaleChangeEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_isTouchScaleChangeEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setTextAreaSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTextAreaSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTextAreaSize : Error processing arguments");
		cobj->setTextAreaSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setTextAreaSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_getStringLength(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_getStringLength : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getStringLength();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_getStringLength : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setScaleY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setScaleY : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setScaleY : Error processing arguments");
		cobj->setScaleY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setScaleY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setScaleX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setScaleX : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setScaleX : Error processing arguments");
		cobj->setScaleX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setScaleX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setFlipY(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFlipY : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFlipY : Error processing arguments");
		cobj->setFlipY(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setFlipY : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setFlipX(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFlipX : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFlipX : Error processing arguments");
		cobj->setFlipX(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setFlipX : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setFontSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFontSize : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setFontSize : Error processing arguments");
		cobj->setFontSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setText : Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setText : Error processing arguments");
		cobj->setText(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setText : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_setTextHorizontalAlignment(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabel* cobj = (gui::UILabel *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTextHorizontalAlignment : Invalid Native Object");
	if (argc == 1) {
		cocos2d::TextHAlignment arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabel_setTextHorizontalAlignment : Error processing arguments");
		cobj->setTextHorizontalAlignment(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_setTextHorizontalAlignment : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabel_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILabel* ret = gui::UILabel::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILabel>(cx, (gui::UILabel*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILabel_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILabel* cobj = new gui::UILabel();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILabel> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILabel");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabel_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UILabel_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILabel)", obj);
}

void js_register_cocos2dx_gui_UILabel(JSContext *cx, JSObject *global) {
	jsb_UILabel_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILabel_class->name = "UILabel";
	jsb_UILabel_class->addProperty = JS_PropertyStub;
	jsb_UILabel_class->delProperty = JS_DeletePropertyStub;
	jsb_UILabel_class->getProperty = JS_PropertyStub;
	jsb_UILabel_class->setProperty = JS_StrictPropertyStub;
	jsb_UILabel_class->enumerate = JS_EnumerateStub;
	jsb_UILabel_class->resolve = JS_ResolveStub;
	jsb_UILabel_class->convert = JS_ConvertStub;
	jsb_UILabel_class->finalize = js_cocos2dx_gui_UILabel_finalize;
	jsb_UILabel_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UILabel_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UILabel_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStringValue", js_cocos2dx_gui_UILabel_getStringValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UILabel_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScale", js_cocos2dx_gui_UILabel_setScale, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTextVerticalAlignment", js_cocos2dx_gui_UILabel_setTextVerticalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFontName", js_cocos2dx_gui_UILabel_setFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTouchScaleChangeEnabled", js_cocos2dx_gui_UILabel_setTouchScaleChangeEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipX", js_cocos2dx_gui_UILabel_isFlipX, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isFlipY", js_cocos2dx_gui_UILabel_isFlipY, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UILabel_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isTouchScaleChangeEnabled", js_cocos2dx_gui_UILabel_isTouchScaleChangeEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTextAreaSize", js_cocos2dx_gui_UILabel_setTextAreaSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStringLength", js_cocos2dx_gui_UILabel_getStringLength, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScaleY", js_cocos2dx_gui_UILabel_setScaleY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScaleX", js_cocos2dx_gui_UILabel_setScaleX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipY", js_cocos2dx_gui_UILabel_setFlipY, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFlipX", js_cocos2dx_gui_UILabel_setFlipX, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFontSize", js_cocos2dx_gui_UILabel_setFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setText", js_cocos2dx_gui_UILabel_setText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTextHorizontalAlignment", js_cocos2dx_gui_UILabel_setTextHorizontalAlignment, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILabel_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILabel_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UILabel_class,
		js_cocos2dx_gui_UILabel_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILabel", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILabel> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILabel_class;
		p->proto = jsb_UILabel_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UILabelAtlas_class;
JSObject *jsb_UILabelAtlas_prototype;

JSBool js_cocos2dx_gui_UILabelAtlas_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelAtlas* cobj = (gui::UILabelAtlas *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelAtlas_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelAtlas* cobj = (gui::UILabelAtlas *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelAtlas_getStringValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelAtlas* cobj = (gui::UILabelAtlas *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_getStringValue : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getStringValue();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_getStringValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelAtlas_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelAtlas* cobj = (gui::UILabelAtlas *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelAtlas_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelAtlas* cobj = (gui::UILabelAtlas *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelAtlas_setProperty(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelAtlas* cobj = (gui::UILabelAtlas *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_setProperty : Invalid Native Object");
	if (argc == 5) {
		std::string arg0;
		std::string arg1;
		int arg2;
		int arg3;
		std::string arg4;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		ok &= jsval_to_std_string(cx, argv[1], &arg1);
		ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
		ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
		ok &= jsval_to_std_string(cx, argv[4], &arg4);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_setProperty : Error processing arguments");
		cobj->setProperty(arg0, arg1, arg2, arg3, arg4);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_setProperty : wrong number of arguments: %d, was expecting %d", argc, 5);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelAtlas_setStringValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelAtlas* cobj = (gui::UILabelAtlas *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_setStringValue : Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabelAtlas_setStringValue : Error processing arguments");
		cobj->setStringValue(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_setStringValue : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelAtlas_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILabelAtlas* ret = gui::UILabelAtlas::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILabelAtlas>(cx, (gui::UILabelAtlas*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILabelAtlas_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILabelAtlas* cobj = new gui::UILabelAtlas();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILabelAtlas> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILabelAtlas");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelAtlas_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UILabelAtlas_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILabelAtlas)", obj);
}

void js_register_cocos2dx_gui_UILabelAtlas(JSContext *cx, JSObject *global) {
	jsb_UILabelAtlas_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILabelAtlas_class->name = "UILabelAtlas";
	jsb_UILabelAtlas_class->addProperty = JS_PropertyStub;
	jsb_UILabelAtlas_class->delProperty = JS_DeletePropertyStub;
	jsb_UILabelAtlas_class->getProperty = JS_PropertyStub;
	jsb_UILabelAtlas_class->setProperty = JS_StrictPropertyStub;
	jsb_UILabelAtlas_class->enumerate = JS_EnumerateStub;
	jsb_UILabelAtlas_class->resolve = JS_ResolveStub;
	jsb_UILabelAtlas_class->convert = JS_ConvertStub;
	jsb_UILabelAtlas_class->finalize = js_cocos2dx_gui_UILabelAtlas_finalize;
	jsb_UILabelAtlas_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UILabelAtlas_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UILabelAtlas_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStringValue", js_cocos2dx_gui_UILabelAtlas_getStringValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UILabelAtlas_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UILabelAtlas_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setProperty", js_cocos2dx_gui_UILabelAtlas_setProperty, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setStringValue", js_cocos2dx_gui_UILabelAtlas_setStringValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILabelAtlas_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILabelAtlas_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UILabelAtlas_class,
		js_cocos2dx_gui_UILabelAtlas_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILabelAtlas", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILabelAtlas> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILabelAtlas_class;
		p->proto = jsb_UILabelAtlas_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UILoadingBar_class;
JSObject *jsb_UILoadingBar_prototype;

JSBool js_cocos2dx_gui_UILoadingBar_setPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setPercent : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setPercent : Error processing arguments");
		cobj->setPercent(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_setPercent : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_ignoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_ignoreContentAdaptWithSize : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_ignoreContentAdaptWithSize : Error processing arguments");
		cobj->ignoreContentAdaptWithSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_ignoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_loadTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_loadTexture : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_loadTexture : Error processing arguments");
		cobj->loadTexture(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_loadTexture : Error processing arguments");
		cobj->loadTexture(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_loadTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_setDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setDirection : Invalid Native Object");
	if (argc == 1) {
		gui::LoadingBarType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setDirection : Error processing arguments");
		cobj->setDirection(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_setDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_setScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setScale9Enabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setScale9Enabled : Error processing arguments");
		cobj->setScale9Enabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_setScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setCapInsets : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_setCapInsets : Error processing arguments");
		cobj->setCapInsets(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_setCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_getDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_getDirection : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getDirection();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_getDirection : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_getPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILoadingBar* cobj = (gui::UILoadingBar *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILoadingBar_getPercent : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getPercent();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_getPercent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILoadingBar_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILoadingBar* ret = gui::UILoadingBar::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILoadingBar>(cx, (gui::UILoadingBar*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILoadingBar_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILoadingBar* cobj = new gui::UILoadingBar();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILoadingBar> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILoadingBar");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILoadingBar_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UILoadingBar_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILoadingBar)", obj);
}

void js_register_cocos2dx_gui_UILoadingBar(JSContext *cx, JSObject *global) {
	jsb_UILoadingBar_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILoadingBar_class->name = "UILoadingBar";
	jsb_UILoadingBar_class->addProperty = JS_PropertyStub;
	jsb_UILoadingBar_class->delProperty = JS_DeletePropertyStub;
	jsb_UILoadingBar_class->getProperty = JS_PropertyStub;
	jsb_UILoadingBar_class->setProperty = JS_StrictPropertyStub;
	jsb_UILoadingBar_class->enumerate = JS_EnumerateStub;
	jsb_UILoadingBar_class->resolve = JS_ResolveStub;
	jsb_UILoadingBar_class->convert = JS_ConvertStub;
	jsb_UILoadingBar_class->finalize = js_cocos2dx_gui_UILoadingBar_finalize;
	jsb_UILoadingBar_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setPercent", js_cocos2dx_gui_UILoadingBar_setPercent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UILoadingBar_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("ignoreContentAdaptWithSize", js_cocos2dx_gui_UILoadingBar_ignoreContentAdaptWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadTexture", js_cocos2dx_gui_UILoadingBar_loadTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDirection", js_cocos2dx_gui_UILoadingBar_setDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UILoadingBar_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScale9Enabled", js_cocos2dx_gui_UILoadingBar_setScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsets", js_cocos2dx_gui_UILoadingBar_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDirection", js_cocos2dx_gui_UILoadingBar_getDirection, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UILoadingBar_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPercent", js_cocos2dx_gui_UILoadingBar_getPercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILoadingBar_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILoadingBar_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UILoadingBar_class,
		js_cocos2dx_gui_UILoadingBar_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILoadingBar", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILoadingBar> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILoadingBar_class;
		p->proto = jsb_UILoadingBar_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIScrollView_class;
JSObject *jsb_UIScrollView_prototype;

JSBool js_cocos2dx_gui_UIScrollView_addChild(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_addChild : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_addChild : Error processing arguments");
		bool ret = cobj->addChild(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_addChild : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToTop(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToTop : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToTop : Error processing arguments");
		cobj->scrollToTop(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToTop : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToPercentHorizontal(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToPercentHorizontal : Invalid Native Object");
	if (argc == 3) {
		double arg0;
		double arg1;
		JSBool arg2;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToNumber(cx, argv[1], &arg1);
		ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToPercentHorizontal : Error processing arguments");
		cobj->scrollToPercentHorizontal(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToPercentHorizontal : wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_removeAllChildren(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_removeAllChildren : Invalid Native Object");
	if (argc == 0) {
		cobj->removeAllChildren();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_removeAllChildren : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToPercentBothDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToPercentBothDirection : Invalid Native Object");
	if (argc == 3) {
		cocos2d::Point arg0;
		double arg1;
		JSBool arg2;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		ok &= JS_ValueToNumber(cx, argv[1], &arg1);
		ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToPercentBothDirection : Error processing arguments");
		cobj->scrollToPercentBothDirection(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToPercentBothDirection : wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_getChildren(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_getChildren : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Array* ret = cobj->getChildren();
		jsval jsret;
		jsret = ccarray_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_getChildren : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_getDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_getDirection : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getDirection();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_getDirection : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToBottomLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToBottomLeft : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToBottomLeft : Error processing arguments");
		cobj->scrollToBottomLeft(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToBottomLeft : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_getInnerContainer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_getInnerContainer : Invalid Native Object");
	if (argc == 0) {
		gui::UILayout* ret = cobj->getInnerContainer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UILayout>(cx, (gui::UILayout*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_getInnerContainer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToBottom(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToBottom : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToBottom();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToBottom : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_setDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setDirection : Invalid Native Object");
	if (argc == 1) {
		gui::SCROLLVIEW_DIR arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setDirection : Error processing arguments");
		cobj->setDirection(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_setDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToTopLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToTopLeft : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToTopLeft : Error processing arguments");
		cobj->scrollToTopLeft(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToTopLeft : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToTopRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToTopRight : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToTopRight();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToTopRight : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToBottomLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToBottomLeft : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToBottomLeft();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToBottomLeft : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_setInnerContainerSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setInnerContainerSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setInnerContainerSize : Error processing arguments");
		cobj->setInnerContainerSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_setInnerContainerSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_isInertiaScrollEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_isInertiaScrollEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isInertiaScrollEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_isInertiaScrollEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_getInnerContainerSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_getInnerContainerSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getInnerContainerSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_getInnerContainerSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_isBounceEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_isBounceEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isBounceEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_isBounceEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToPercentVertical(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToPercentVertical : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToPercentVertical : Error processing arguments");
		cobj->jumpToPercentVertical(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToPercentVertical : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_doLayout(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_doLayout : Invalid Native Object");
	if (argc == 0) {
		cobj->doLayout();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_doLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_setInertiaScrollEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setInertiaScrollEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setInertiaScrollEnabled : Error processing arguments");
		cobj->setInertiaScrollEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_setInertiaScrollEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToTopLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToTopLeft : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToTopLeft();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToTopLeft : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToPercentHorizontal(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToPercentHorizontal : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToPercentHorizontal : Error processing arguments");
		cobj->jumpToPercentHorizontal(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToPercentHorizontal : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToBottomRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToBottomRight : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToBottomRight();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToBottomRight : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_update : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_update : Error processing arguments");
		cobj->update(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_update : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_getLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_getLayoutType : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getLayoutType();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_getLayoutType : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_setBounceEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setBounceEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setBounceEnabled : Error processing arguments");
		cobj->setBounceEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_setBounceEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToTop(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToTop : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToTop();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToTop : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToLeft : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToLeft : Error processing arguments");
		cobj->scrollToLeft(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToLeft : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToPercentBothDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToPercentBothDirection : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToPercentBothDirection : Error processing arguments");
		cobj->jumpToPercentBothDirection(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToPercentBothDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToPercentVertical(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToPercentVertical : Invalid Native Object");
	if (argc == 3) {
		double arg0;
		double arg1;
		JSBool arg2;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToNumber(cx, argv[1], &arg1);
		ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToPercentVertical : Error processing arguments");
		cobj->scrollToPercentVertical(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToPercentVertical : wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToBottom(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToBottom : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToBottom : Error processing arguments");
		cobj->scrollToBottom(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToBottom : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToBottomRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToBottomRight : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToBottomRight : Error processing arguments");
		cobj->scrollToBottomRight(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToBottomRight : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToLeft : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToLeft();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToLeft : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToRight : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToRight : Error processing arguments");
		cobj->scrollToRight(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToRight : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_removeChild(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_removeChild : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_removeChild : Error processing arguments");
		bool ret = cobj->removeChild(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_removeChild : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_setLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setLayoutType : Invalid Native Object");
	if (argc == 1) {
		gui::LayoutType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_setLayoutType : Error processing arguments");
		cobj->setLayoutType(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_setLayoutType : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_jumpToRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_jumpToRight : Invalid Native Object");
	if (argc == 0) {
		cobj->jumpToRight();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_jumpToRight : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_scrollToTopRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIScrollView* cobj = (gui::UIScrollView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToTopRight : Invalid Native Object");
	if (argc == 2) {
		double arg0;
		JSBool arg1;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		ok &= JS_ValueToBoolean(cx, argv[1], &arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIScrollView_scrollToTopRight : Error processing arguments");
		cobj->scrollToTopRight(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_scrollToTopRight : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIScrollView_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIScrollView* ret = gui::UIScrollView::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIScrollView>(cx, (gui::UIScrollView*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIScrollView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIScrollView* cobj = new gui::UIScrollView();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UIScrollView> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UIScrollView");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIScrollView_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UILayout_prototype;

void js_cocos2dx_gui_UIScrollView_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIScrollView)", obj);
}

void js_register_cocos2dx_gui_UIScrollView(JSContext *cx, JSObject *global) {
	jsb_UIScrollView_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIScrollView_class->name = "UIScrollView";
	jsb_UIScrollView_class->addProperty = JS_PropertyStub;
	jsb_UIScrollView_class->delProperty = JS_DeletePropertyStub;
	jsb_UIScrollView_class->getProperty = JS_PropertyStub;
	jsb_UIScrollView_class->setProperty = JS_StrictPropertyStub;
	jsb_UIScrollView_class->enumerate = JS_EnumerateStub;
	jsb_UIScrollView_class->resolve = JS_ResolveStub;
	jsb_UIScrollView_class->convert = JS_ConvertStub;
	jsb_UIScrollView_class->finalize = js_cocos2dx_gui_UIScrollView_finalize;
	jsb_UIScrollView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("addChild", js_cocos2dx_gui_UIScrollView_addChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToTop", js_cocos2dx_gui_UIScrollView_scrollToTop, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToPercentHorizontal", js_cocos2dx_gui_UIScrollView_scrollToPercentHorizontal, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UIScrollView_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeAllChildren", js_cocos2dx_gui_UIScrollView_removeAllChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToPercentBothDirection", js_cocos2dx_gui_UIScrollView_scrollToPercentBothDirection, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getChildren", js_cocos2dx_gui_UIScrollView_getChildren, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDirection", js_cocos2dx_gui_UIScrollView_getDirection, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToBottomLeft", js_cocos2dx_gui_UIScrollView_scrollToBottomLeft, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInnerContainer", js_cocos2dx_gui_UIScrollView_getInnerContainer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToBottom", js_cocos2dx_gui_UIScrollView_jumpToBottom, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDirection", js_cocos2dx_gui_UIScrollView_setDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToTopLeft", js_cocos2dx_gui_UIScrollView_scrollToTopLeft, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToTopRight", js_cocos2dx_gui_UIScrollView_jumpToTopRight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToBottomLeft", js_cocos2dx_gui_UIScrollView_jumpToBottomLeft, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInnerContainerSize", js_cocos2dx_gui_UIScrollView_setInnerContainerSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isInertiaScrollEnabled", js_cocos2dx_gui_UIScrollView_isInertiaScrollEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInnerContainerSize", js_cocos2dx_gui_UIScrollView_getInnerContainerSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isBounceEnabled", js_cocos2dx_gui_UIScrollView_isBounceEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToPercentVertical", js_cocos2dx_gui_UIScrollView_jumpToPercentVertical, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("doLayout", js_cocos2dx_gui_UIScrollView_doLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInertiaScrollEnabled", js_cocos2dx_gui_UIScrollView_setInertiaScrollEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToTopLeft", js_cocos2dx_gui_UIScrollView_jumpToTopLeft, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToPercentHorizontal", js_cocos2dx_gui_UIScrollView_jumpToPercentHorizontal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToBottomRight", js_cocos2dx_gui_UIScrollView_jumpToBottomRight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_cocos2dx_gui_UIScrollView_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getLayoutType", js_cocos2dx_gui_UIScrollView_getLayoutType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setBounceEnabled", js_cocos2dx_gui_UIScrollView_setBounceEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToTop", js_cocos2dx_gui_UIScrollView_jumpToTop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToLeft", js_cocos2dx_gui_UIScrollView_scrollToLeft, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToPercentBothDirection", js_cocos2dx_gui_UIScrollView_jumpToPercentBothDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToPercentVertical", js_cocos2dx_gui_UIScrollView_scrollToPercentVertical, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToBottom", js_cocos2dx_gui_UIScrollView_scrollToBottom, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToBottomRight", js_cocos2dx_gui_UIScrollView_scrollToBottomRight, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToLeft", js_cocos2dx_gui_UIScrollView_jumpToLeft, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToRight", js_cocos2dx_gui_UIScrollView_scrollToRight, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeChild", js_cocos2dx_gui_UIScrollView_removeChild, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setLayoutType", js_cocos2dx_gui_UIScrollView_setLayoutType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("jumpToRight", js_cocos2dx_gui_UIScrollView_jumpToRight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToTopRight", js_cocos2dx_gui_UIScrollView_scrollToTopRight, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UIScrollView_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIScrollView_prototype = JS_InitClass(
		cx, global,
		jsb_UILayout_prototype,
		jsb_UIScrollView_class,
		js_cocos2dx_gui_UIScrollView_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIScrollView", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIScrollView> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIScrollView_class;
		p->proto = jsb_UIScrollView_prototype;
		p->parentProto = jsb_UILayout_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIListView_class;
JSObject *jsb_UIListView_prototype;

JSBool js_cocos2dx_gui_UIListView_getIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_getIndex : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_getIndex : Error processing arguments");
		unsigned int ret = cobj->getIndex(arg0);
		jsval jsret;
		jsret = uint32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_getIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_setGravity(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setGravity : Invalid Native Object");
	if (argc == 1) {
		gui::ListViewGravity arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setGravity : Error processing arguments");
		cobj->setGravity(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_setGravity : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_pushBackCustomItem(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_pushBackCustomItem : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_pushBackCustomItem : Error processing arguments");
		cobj->pushBackCustomItem(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_pushBackCustomItem : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_setDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setDirection : Invalid Native Object");
	if (argc == 1) {
		gui::SCROLLVIEW_DIR arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setDirection : Error processing arguments");
		cobj->setDirection(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_setDirection : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_getItems(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_getItems : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Array* ret = cobj->getItems();
		jsval jsret;
		jsret = ccarray_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_getItems : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_removeItem(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_removeItem : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_removeItem : Error processing arguments");
		cobj->removeItem(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_removeItem : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_getCurSelectedIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_getCurSelectedIndex : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getCurSelectedIndex();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_getCurSelectedIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_insertDefaultItem(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_insertDefaultItem : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_insertDefaultItem : Error processing arguments");
		cobj->insertDefaultItem(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_insertDefaultItem : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_setItemsMargin(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setItemsMargin : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setItemsMargin : Error processing arguments");
		cobj->setItemsMargin(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_setItemsMargin : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_refreshView(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_refreshView : Invalid Native Object");
	if (argc == 0) {
		cobj->refreshView();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_refreshView : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_removeLastItem(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_removeLastItem : Invalid Native Object");
	if (argc == 0) {
		cobj->removeLastItem();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_removeLastItem : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_getItem(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_getItem : Invalid Native Object");
	if (argc == 1) {
		unsigned int arg0;
		ok &= jsval_to_uint32(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_getItem : Error processing arguments");
		gui::UIWidget* ret = cobj->getItem(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_getItem : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_setItemModel(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setItemModel : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_setItemModel : Error processing arguments");
		cobj->setItemModel(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_setItemModel : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_pushBackDefaultItem(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_pushBackDefaultItem : Invalid Native Object");
	if (argc == 0) {
		cobj->pushBackDefaultItem();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_pushBackDefaultItem : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_insertCustomItem(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIListView* cobj = (gui::UIListView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_insertCustomItem : Invalid Native Object");
	if (argc == 2) {
		gui::UIWidget* arg0;
		int arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIListView_insertCustomItem : Error processing arguments");
		cobj->insertCustomItem(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_insertCustomItem : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIListView_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIListView* ret = gui::UIListView::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIListView>(cx, (gui::UIListView*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIListView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIListView* cobj = new gui::UIListView();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UIListView> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UIListView");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIListView_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIScrollView_prototype;

void js_cocos2dx_gui_UIListView_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIListView)", obj);
}

void js_register_cocos2dx_gui_UIListView(JSContext *cx, JSObject *global) {
	jsb_UIListView_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIListView_class->name = "UIListView";
	jsb_UIListView_class->addProperty = JS_PropertyStub;
	jsb_UIListView_class->delProperty = JS_DeletePropertyStub;
	jsb_UIListView_class->getProperty = JS_PropertyStub;
	jsb_UIListView_class->setProperty = JS_StrictPropertyStub;
	jsb_UIListView_class->enumerate = JS_EnumerateStub;
	jsb_UIListView_class->resolve = JS_ResolveStub;
	jsb_UIListView_class->convert = JS_ConvertStub;
	jsb_UIListView_class->finalize = js_cocos2dx_gui_UIListView_finalize;
	jsb_UIListView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getIndex", js_cocos2dx_gui_UIListView_getIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setGravity", js_cocos2dx_gui_UIListView_setGravity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("pushBackCustomItem", js_cocos2dx_gui_UIListView_pushBackCustomItem, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDirection", js_cocos2dx_gui_UIListView_setDirection, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getItems", js_cocos2dx_gui_UIListView_getItems, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UIListView_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeItem", js_cocos2dx_gui_UIListView_removeItem, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCurSelectedIndex", js_cocos2dx_gui_UIListView_getCurSelectedIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("insertDefaultItem", js_cocos2dx_gui_UIListView_insertDefaultItem, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setItemsMargin", js_cocos2dx_gui_UIListView_setItemsMargin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("refreshView", js_cocos2dx_gui_UIListView_refreshView, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeLastItem", js_cocos2dx_gui_UIListView_removeLastItem, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getItem", js_cocos2dx_gui_UIListView_getItem, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setItemModel", js_cocos2dx_gui_UIListView_setItemModel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("pushBackDefaultItem", js_cocos2dx_gui_UIListView_pushBackDefaultItem, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("insertCustomItem", js_cocos2dx_gui_UIListView_insertCustomItem, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UIListView_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIListView_prototype = JS_InitClass(
		cx, global,
		jsb_UIScrollView_prototype,
		jsb_UIListView_class,
		js_cocos2dx_gui_UIListView_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIListView", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIListView> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIListView_class;
		p->proto = jsb_UIListView_prototype;
		p->parentProto = jsb_UIScrollView_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UISlider_class;
JSObject *jsb_UISlider_prototype;

JSBool js_cocos2dx_gui_UISlider_setPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setPercent : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setPercent : Error processing arguments");
		cobj->setPercent(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_setPercent : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_loadSlidBallTextureNormal(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextureNormal : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextureNormal : Error processing arguments");
		cobj->loadSlidBallTextureNormal(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextureNormal : Error processing arguments");
		cobj->loadSlidBallTextureNormal(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_loadSlidBallTextureNormal : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_loadBarTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadBarTexture : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadBarTexture : Error processing arguments");
		cobj->loadBarTexture(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadBarTexture : Error processing arguments");
		cobj->loadBarTexture(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_loadBarTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_loadProgressBarTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadProgressBarTexture : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadProgressBarTexture : Error processing arguments");
		cobj->loadProgressBarTexture(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadProgressBarTexture : Error processing arguments");
		cobj->loadProgressBarTexture(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_loadProgressBarTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_loadSlidBallTextures(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextures : Invalid Native Object");
	if (argc == 3) {
		const char* arg0;
		const char* arg1;
		const char* arg2;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextures : Error processing arguments");
		cobj->loadSlidBallTextures(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 4) {
		const char* arg0;
		const char* arg1;
		const char* arg2;
		gui::TextureResType arg3;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		std::string arg2_tmp; ok &= jsval_to_std_string(cx, argv[2], &arg2_tmp); arg2 = arg2_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextures : Error processing arguments");
		cobj->loadSlidBallTextures(arg0, arg1, arg2, arg3);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_loadSlidBallTextures : wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_setCapInsetProgressBarRebderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setCapInsetProgressBarRebderer : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setCapInsetProgressBarRebderer : Error processing arguments");
		cobj->setCapInsetProgressBarRebderer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_setCapInsetProgressBarRebderer : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_setCapInsetsBarRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setCapInsetsBarRenderer : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setCapInsetsBarRenderer : Error processing arguments");
		cobj->setCapInsetsBarRenderer(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_setCapInsetsBarRenderer : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_setScale9Enabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setScale9Enabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setScale9Enabled : Error processing arguments");
		cobj->setScale9Enabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_setScale9Enabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setCapInsets : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= jsval_to_ccrect(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_setCapInsets : Error processing arguments");
		cobj->setCapInsets(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_setCapInsets : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_ignoreContentAdaptWithSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_ignoreContentAdaptWithSize : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_ignoreContentAdaptWithSize : Error processing arguments");
		cobj->ignoreContentAdaptWithSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_ignoreContentAdaptWithSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_loadSlidBallTexturePressed(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTexturePressed : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTexturePressed : Error processing arguments");
		cobj->loadSlidBallTexturePressed(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTexturePressed : Error processing arguments");
		cobj->loadSlidBallTexturePressed(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_loadSlidBallTexturePressed : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_loadSlidBallTextureDisabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextureDisabled : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextureDisabled : Error processing arguments");
		cobj->loadSlidBallTextureDisabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		gui::TextureResType arg1;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_loadSlidBallTextureDisabled : Error processing arguments");
		cobj->loadSlidBallTextureDisabled(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_loadSlidBallTextureDisabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_getPercent(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UISlider* cobj = (gui::UISlider *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UISlider_getPercent : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getPercent();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_getPercent : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UISlider_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UISlider* ret = gui::UISlider::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UISlider>(cx, (gui::UISlider*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UISlider_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UISlider* cobj = new gui::UISlider();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UISlider> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UISlider");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UISlider_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UISlider_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UISlider)", obj);
}

void js_register_cocos2dx_gui_UISlider(JSContext *cx, JSObject *global) {
	jsb_UISlider_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UISlider_class->name = "UISlider";
	jsb_UISlider_class->addProperty = JS_PropertyStub;
	jsb_UISlider_class->delProperty = JS_DeletePropertyStub;
	jsb_UISlider_class->getProperty = JS_PropertyStub;
	jsb_UISlider_class->setProperty = JS_StrictPropertyStub;
	jsb_UISlider_class->enumerate = JS_EnumerateStub;
	jsb_UISlider_class->resolve = JS_ResolveStub;
	jsb_UISlider_class->convert = JS_ConvertStub;
	jsb_UISlider_class->finalize = js_cocos2dx_gui_UISlider_finalize;
	jsb_UISlider_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setPercent", js_cocos2dx_gui_UISlider_setPercent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadSlidBallTextureNormal", js_cocos2dx_gui_UISlider_loadSlidBallTextureNormal, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadBarTexture", js_cocos2dx_gui_UISlider_loadBarTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadProgressBarTexture", js_cocos2dx_gui_UISlider_loadProgressBarTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadSlidBallTextures", js_cocos2dx_gui_UISlider_loadSlidBallTextures, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsetProgressBarRebderer", js_cocos2dx_gui_UISlider_setCapInsetProgressBarRebderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsetsBarRenderer", js_cocos2dx_gui_UISlider_setCapInsetsBarRenderer, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UISlider_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setScale9Enabled", js_cocos2dx_gui_UISlider_setScale9Enabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UISlider_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setCapInsets", js_cocos2dx_gui_UISlider_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("ignoreContentAdaptWithSize", js_cocos2dx_gui_UISlider_ignoreContentAdaptWithSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadSlidBallTexturePressed", js_cocos2dx_gui_UISlider_loadSlidBallTexturePressed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("loadSlidBallTextureDisabled", js_cocos2dx_gui_UISlider_loadSlidBallTextureDisabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UISlider_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPercent", js_cocos2dx_gui_UISlider_getPercent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UISlider_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UISlider_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UISlider_class,
		js_cocos2dx_gui_UISlider_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UISlider", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UISlider> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UISlider_class;
		p->proto = jsb_UISlider_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UITextField_class;
JSObject *jsb_UITextField_prototype;

JSBool js_cocos2dx_gui_UITextField_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setAttachWithIME(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setAttachWithIME : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setAttachWithIME : Error processing arguments");
		cobj->setAttachWithIME(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setAttachWithIME : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getStringValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getStringValue : Invalid Native Object");
	if (argc == 0) {
		const std::string& ret = cobj->getStringValue();
		jsval jsret;
		jsret = std_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getStringValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getDeleteBackward(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getDeleteBackward : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getDeleteBackward();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getDeleteBackward : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getAttachWithIME(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getAttachWithIME : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getAttachWithIME();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getAttachWithIME : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setFontName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setFontName : Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setFontName : Error processing arguments");
		cobj->setFontName(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setFontName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getInsertText(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getInsertText : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getInsertText();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getInsertText : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_initRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_initRenderer : Invalid Native Object");
	if (argc == 0) {
		cobj->initRenderer();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_initRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getDetachWithIME(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getDetachWithIME : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->getDetachWithIME();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getDetachWithIME : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setOpacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setOpacity : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setOpacity : Error processing arguments");
		cobj->setOpacity(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setOpacity : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_init : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_init : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_didNotSelectSelf(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_didNotSelectSelf : Invalid Native Object");
	if (argc == 0) {
		cobj->didNotSelectSelf();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_didNotSelectSelf : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_isPasswordEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_isPasswordEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isPasswordEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_isPasswordEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_attachWithIME(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_attachWithIME : Invalid Native Object");
	if (argc == 0) {
		cobj->attachWithIME();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_attachWithIME : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setPasswordEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setPasswordEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setPasswordEnabled : Error processing arguments");
		cobj->setPasswordEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setPasswordEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_update : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_update : Error processing arguments");
		cobj->update(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_update : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setMaxLengthEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setMaxLengthEnabled : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setMaxLengthEnabled : Error processing arguments");
		cobj->setMaxLengthEnabled(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setMaxLengthEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setPasswordStyleText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setPasswordStyleText : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setPasswordStyleText : Error processing arguments");
		cobj->setPasswordStyleText(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setPasswordStyleText : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setFontSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setFontSize : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setFontSize : Error processing arguments");
		cobj->setFontSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setFontSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setPlaceHolder(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setPlaceHolder : Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setPlaceHolder : Error processing arguments");
		cobj->setPlaceHolder(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setPlaceHolder : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setColor : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= jsval_to_cccolor3b(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setColor : Error processing arguments");
		cobj->setColor(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setColor : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_getMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_getMaxLength : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getMaxLength();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_getMaxLength : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_isMaxLengthEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_isMaxLengthEnabled : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->isMaxLengthEnabled();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_isMaxLengthEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setDetachWithIME(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setDetachWithIME : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setDetachWithIME : Error processing arguments");
		cobj->setDetachWithIME(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setDetachWithIME : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setText : Invalid Native Object");
	if (argc == 1) {
		std::string arg0;
		ok &= jsval_to_std_string(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setText : Error processing arguments");
		cobj->setText(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setText : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setInsertText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setInsertText : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setInsertText : Error processing arguments");
		cobj->setInsertText(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setInsertText : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setMaxLength : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setMaxLength : Error processing arguments");
		cobj->setMaxLength(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setMaxLength : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setTouchSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setTouchSize : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Size arg0;
		ok &= jsval_to_ccsize(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setTouchSize : Error processing arguments");
		cobj->setTouchSize(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setTouchSize : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_setDeleteBackward(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UITextField* cobj = (gui::UITextField *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setDeleteBackward : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UITextField_setDeleteBackward : Error processing arguments");
		cobj->setDeleteBackward(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_setDeleteBackward : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UITextField_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UITextField* ret = gui::UITextField::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UITextField>(cx, (gui::UITextField*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UITextField_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UITextField* cobj = new gui::UITextField();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UITextField> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UITextField");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UITextField_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UITextField_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UITextField)", obj);
}

void js_register_cocos2dx_gui_UITextField(JSContext *cx, JSObject *global) {
	jsb_UITextField_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UITextField_class->name = "UITextField";
	jsb_UITextField_class->addProperty = JS_PropertyStub;
	jsb_UITextField_class->delProperty = JS_DeletePropertyStub;
	jsb_UITextField_class->getProperty = JS_PropertyStub;
	jsb_UITextField_class->setProperty = JS_StrictPropertyStub;
	jsb_UITextField_class->enumerate = JS_EnumerateStub;
	jsb_UITextField_class->resolve = JS_ResolveStub;
	jsb_UITextField_class->convert = JS_ConvertStub;
	jsb_UITextField_class->finalize = js_cocos2dx_gui_UITextField_finalize;
	jsb_UITextField_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UITextField_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setAttachWithIME", js_cocos2dx_gui_UITextField_setAttachWithIME, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStringValue", js_cocos2dx_gui_UITextField_getStringValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UITextField_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UITextField_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDeleteBackward", js_cocos2dx_gui_UITextField_getDeleteBackward, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getAttachWithIME", js_cocos2dx_gui_UITextField_getAttachWithIME, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFontName", js_cocos2dx_gui_UITextField_setFontName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getInsertText", js_cocos2dx_gui_UITextField_getInsertText, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("initRenderer", js_cocos2dx_gui_UITextField_initRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDetachWithIME", js_cocos2dx_gui_UITextField_getDetachWithIME, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setOpacity", js_cocos2dx_gui_UITextField_setOpacity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_cocos2dx_gui_UITextField_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UITextField_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("didNotSelectSelf", js_cocos2dx_gui_UITextField_didNotSelectSelf, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isPasswordEnabled", js_cocos2dx_gui_UITextField_isPasswordEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("attachWithIME", js_cocos2dx_gui_UITextField_attachWithIME, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPasswordEnabled", js_cocos2dx_gui_UITextField_setPasswordEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_cocos2dx_gui_UITextField_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMaxLengthEnabled", js_cocos2dx_gui_UITextField_setMaxLengthEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPasswordStyleText", js_cocos2dx_gui_UITextField_setPasswordStyleText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFontSize", js_cocos2dx_gui_UITextField_setFontSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setPlaceHolder", js_cocos2dx_gui_UITextField_setPlaceHolder, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setColor", js_cocos2dx_gui_UITextField_setColor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getMaxLength", js_cocos2dx_gui_UITextField_getMaxLength, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("isMaxLengthEnabled", js_cocos2dx_gui_UITextField_isMaxLengthEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDetachWithIME", js_cocos2dx_gui_UITextField_setDetachWithIME, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setText", js_cocos2dx_gui_UITextField_setText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setInsertText", js_cocos2dx_gui_UITextField_setInsertText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setMaxLength", js_cocos2dx_gui_UITextField_setMaxLength, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setTouchSize", js_cocos2dx_gui_UITextField_setTouchSize, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setDeleteBackward", js_cocos2dx_gui_UITextField_setDeleteBackward, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UITextField_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UITextField_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UITextField_class,
		js_cocos2dx_gui_UITextField_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UITextField", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UITextField> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UITextField_class;
		p->proto = jsb_UITextField_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UILabelBMFont_class;
JSObject *jsb_UILabelBMFont_prototype;

JSBool js_cocos2dx_gui_UILabelBMFont_setAnchorPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelBMFont* cobj = (gui::UILabelBMFont *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_setAnchorPoint : Invalid Native Object");
	if (argc == 1) {
		cocos2d::Point arg0;
		ok &= jsval_to_ccpoint(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_setAnchorPoint : Error processing arguments");
		cobj->setAnchorPoint(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_setAnchorPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelBMFont_getVirtualRenderer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelBMFont* cobj = (gui::UILabelBMFont *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_getVirtualRenderer : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Node* ret = cobj->getVirtualRenderer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::Node>(cx, (cocos2d::Node*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_getVirtualRenderer : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelBMFont_getStringValue(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelBMFont* cobj = (gui::UILabelBMFont *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_getStringValue : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getStringValue();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_getStringValue : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelBMFont_setText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelBMFont* cobj = (gui::UILabelBMFont *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_setText : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_setText : Error processing arguments");
		cobj->setText(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_setText : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelBMFont_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelBMFont* cobj = (gui::UILabelBMFont *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelBMFont_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelBMFont* cobj = (gui::UILabelBMFont *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_getContentSize : Invalid Native Object");
	if (argc == 0) {
		const cocos2d::Size& ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_getContentSize : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelBMFont_setFntFile(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILabelBMFont* cobj = (gui::UILabelBMFont *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_setFntFile : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILabelBMFont_setFntFile : Error processing arguments");
		cobj->setFntFile(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_setFntFile : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILabelBMFont_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILabelBMFont* ret = gui::UILabelBMFont::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILabelBMFont>(cx, (gui::UILabelBMFont*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILabelBMFont_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILabelBMFont* cobj = new gui::UILabelBMFont();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILabelBMFont> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILabelBMFont");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILabelBMFont_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UIWidget_prototype;

void js_cocos2dx_gui_UILabelBMFont_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILabelBMFont)", obj);
}

void js_register_cocos2dx_gui_UILabelBMFont(JSContext *cx, JSObject *global) {
	jsb_UILabelBMFont_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILabelBMFont_class->name = "UILabelBMFont";
	jsb_UILabelBMFont_class->addProperty = JS_PropertyStub;
	jsb_UILabelBMFont_class->delProperty = JS_DeletePropertyStub;
	jsb_UILabelBMFont_class->getProperty = JS_PropertyStub;
	jsb_UILabelBMFont_class->setProperty = JS_StrictPropertyStub;
	jsb_UILabelBMFont_class->enumerate = JS_EnumerateStub;
	jsb_UILabelBMFont_class->resolve = JS_ResolveStub;
	jsb_UILabelBMFont_class->convert = JS_ConvertStub;
	jsb_UILabelBMFont_class->finalize = js_cocos2dx_gui_UILabelBMFont_finalize;
	jsb_UILabelBMFont_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("setAnchorPoint", js_cocos2dx_gui_UILabelBMFont_setAnchorPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getVirtualRenderer", js_cocos2dx_gui_UILabelBMFont_getVirtualRenderer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getStringValue", js_cocos2dx_gui_UILabelBMFont_getStringValue, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setText", js_cocos2dx_gui_UILabelBMFont_setText, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UILabelBMFont_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getContentSize", js_cocos2dx_gui_UILabelBMFont_getContentSize, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setFntFile", js_cocos2dx_gui_UILabelBMFont_setFntFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILabelBMFont_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILabelBMFont_prototype = JS_InitClass(
		cx, global,
		jsb_UIWidget_prototype,
		jsb_UILabelBMFont_class,
		js_cocos2dx_gui_UILabelBMFont_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILabelBMFont", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILabelBMFont> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILabelBMFont_class;
		p->proto = jsb_UILabelBMFont_prototype;
		p->parentProto = jsb_UIWidget_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIPageView_class;
JSObject *jsb_UIPageView_prototype;

JSBool js_cocos2dx_gui_UIPageView_getLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_getLayoutType : Invalid Native Object");
	if (argc == 0) {
		int ret = (int)cobj->getLayoutType();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_getLayoutType : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_getCurPageIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_getCurPageIndex : Invalid Native Object");
	if (argc == 0) {
		int ret = cobj->getCurPageIndex();
		jsval jsret;
		jsret = int32_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_getCurPageIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_addWidgetToPage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_addWidgetToPage : Invalid Native Object");
	if (argc == 3) {
		gui::UIWidget* arg0;
		int arg1;
		JSBool arg2;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		ok &= JS_ValueToBoolean(cx, argv[2], &arg2);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_addWidgetToPage : Error processing arguments");
		cobj->addWidgetToPage(arg0, arg1, arg2);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_addWidgetToPage : wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_getPage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_getPage : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_getPage : Error processing arguments");
		gui::UILayout* ret = cobj->getPage(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UILayout>(cx, (gui::UILayout*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_getPage : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_removePage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_removePage : Invalid Native Object");
	if (argc == 1) {
		gui::UILayout* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UILayout*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_removePage : Error processing arguments");
		cobj->removePage(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_removePage : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_getDescription(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_getDescription : Invalid Native Object");
	if (argc == 0) {
		const char* ret = cobj->getDescription();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_getDescription : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_insertPage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_insertPage : Invalid Native Object");
	if (argc == 2) {
		gui::UILayout* arg0;
		int arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UILayout*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_insertPage : Error processing arguments");
		cobj->insertPage(arg0, arg1);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_insertPage : wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_setLayoutType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_setLayoutType : Invalid Native Object");
	if (argc == 1) {
		gui::LayoutType arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_setLayoutType : Error processing arguments");
		cobj->setLayoutType(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_setLayoutType : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_scrollToPage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_scrollToPage : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_scrollToPage : Error processing arguments");
		cobj->scrollToPage(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_scrollToPage : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_update(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_update : Invalid Native Object");
	if (argc == 1) {
		double arg0;
		ok &= JS_ValueToNumber(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_update : Error processing arguments");
		cobj->update(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_update : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_doLayout(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_doLayout : Invalid Native Object");
	if (argc == 0) {
		cobj->doLayout();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_doLayout : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_removePageAtIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_removePageAtIndex : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_removePageAtIndex : Error processing arguments");
		cobj->removePageAtIndex(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_removePageAtIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_getPages(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_getPages : Invalid Native Object");
	if (argc == 0) {
		cocos2d::Array* ret = cobj->getPages();
		jsval jsret;
		jsret = ccarray_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_getPages : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_removeAllPages(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_removeAllPages : Invalid Native Object");
	if (argc == 0) {
		cobj->removeAllPages();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_removeAllPages : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_addPage(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UIPageView* cobj = (gui::UIPageView *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_addPage : Invalid Native Object");
	if (argc == 1) {
		gui::UILayout* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UILayout*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIPageView_addPage : Error processing arguments");
		cobj->addPage(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_addPage : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UIPageView_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIPageView* ret = gui::UIPageView::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIPageView>(cx, (gui::UIPageView*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIPageView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UIPageView* cobj = new gui::UIPageView();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UIPageView> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UIPageView");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UIPageView_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_UILayout_prototype;

void js_cocos2dx_gui_UIPageView_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIPageView)", obj);
}

void js_register_cocos2dx_gui_UIPageView(JSContext *cx, JSObject *global) {
	jsb_UIPageView_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIPageView_class->name = "UIPageView";
	jsb_UIPageView_class->addProperty = JS_PropertyStub;
	jsb_UIPageView_class->delProperty = JS_DeletePropertyStub;
	jsb_UIPageView_class->getProperty = JS_PropertyStub;
	jsb_UIPageView_class->setProperty = JS_StrictPropertyStub;
	jsb_UIPageView_class->enumerate = JS_EnumerateStub;
	jsb_UIPageView_class->resolve = JS_ResolveStub;
	jsb_UIPageView_class->convert = JS_ConvertStub;
	jsb_UIPageView_class->finalize = js_cocos2dx_gui_UIPageView_finalize;
	jsb_UIPageView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getLayoutType", js_cocos2dx_gui_UIPageView_getLayoutType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getCurPageIndex", js_cocos2dx_gui_UIPageView_getCurPageIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("addWidgetToPage", js_cocos2dx_gui_UIPageView_addWidgetToPage, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPage", js_cocos2dx_gui_UIPageView_getPage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removePage", js_cocos2dx_gui_UIPageView_removePage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getDescription", js_cocos2dx_gui_UIPageView_getDescription, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("insertPage", js_cocos2dx_gui_UIPageView_insertPage, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setLayoutType", js_cocos2dx_gui_UIPageView_setLayoutType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("scrollToPage", js_cocos2dx_gui_UIPageView_scrollToPage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("update", js_cocos2dx_gui_UIPageView_update, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("doLayout", js_cocos2dx_gui_UIPageView_doLayout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removePageAtIndex", js_cocos2dx_gui_UIPageView_removePageAtIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getPages", js_cocos2dx_gui_UIPageView_getPages, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeAllPages", js_cocos2dx_gui_UIPageView_removeAllPages, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("addPage", js_cocos2dx_gui_UIPageView_addPage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UIPageView_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIPageView_prototype = JS_InitClass(
		cx, global,
		jsb_UILayout_prototype,
		jsb_UIPageView_class,
		js_cocos2dx_gui_UIPageView_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIPageView", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIPageView> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIPageView_class;
		p->proto = jsb_UIPageView_prototype;
		p->parentProto = jsb_UILayout_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UIHelper_class;
JSObject *jsb_UIHelper_prototype;

JSBool js_cocos2dx_gui_UIHelper_seekActionWidgetByActionTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 2) {
		gui::UIWidget* arg0;
		int arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIHelper_seekActionWidgetByActionTag : Error processing arguments");
		gui::UIWidget* ret = gui::UIHelper::seekActionWidgetByActionTag(arg0, arg1);
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIHelper_seekActionWidgetByActionTag : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIHelper_seekWidgetByTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 2) {
		gui::UIWidget* arg0;
		int arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIHelper_seekWidgetByTag : Error processing arguments");
		gui::UIWidget* ret = gui::UIHelper::seekWidgetByTag(arg0, arg1);
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIHelper_seekWidgetByTag : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIHelper_seekWidgetByRelativeName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 2) {
		gui::UIWidget* arg0;
		const char* arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIHelper_seekWidgetByRelativeName : Error processing arguments");
		gui::UIWidget* ret = gui::UIHelper::seekWidgetByRelativeName(arg0, arg1);
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIHelper_seekWidgetByRelativeName : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UIHelper_seekWidgetByName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	if (argc == 2) {
		gui::UIWidget* arg0;
		const char* arg1;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UIHelper_seekWidgetByName : Error processing arguments");
		gui::UIWidget* ret = gui::UIHelper::seekWidgetByName(arg0, arg1);
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UIHelper_seekWidgetByName : wrong number of arguments");
	return JS_FALSE;
}



void js_cocos2dx_gui_UIHelper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UIHelper)", obj);
}

void js_register_cocos2dx_gui_UIHelper(JSContext *cx, JSObject *global) {
	jsb_UIHelper_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UIHelper_class->name = "UIHelper";
	jsb_UIHelper_class->addProperty = JS_PropertyStub;
	jsb_UIHelper_class->delProperty = JS_DeletePropertyStub;
	jsb_UIHelper_class->getProperty = JS_PropertyStub;
	jsb_UIHelper_class->setProperty = JS_StrictPropertyStub;
	jsb_UIHelper_class->enumerate = JS_EnumerateStub;
	jsb_UIHelper_class->resolve = JS_ResolveStub;
	jsb_UIHelper_class->convert = JS_ConvertStub;
	jsb_UIHelper_class->finalize = js_cocos2dx_gui_UIHelper_finalize;
	jsb_UIHelper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	JSPropertySpec *properties = NULL;

	JSFunctionSpec *funcs = NULL;

	static JSFunctionSpec st_funcs[] = {
		JS_FN("seekActionWidgetByActionTag", js_cocos2dx_gui_UIHelper_seekActionWidgetByActionTag, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("seekWidgetByTag", js_cocos2dx_gui_UIHelper_seekWidgetByTag, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("seekWidgetByRelativeName", js_cocos2dx_gui_UIHelper_seekWidgetByRelativeName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("seekWidgetByName", js_cocos2dx_gui_UIHelper_seekWidgetByName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UIHelper_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		jsb_UIHelper_class,
		empty_constructor, 0,
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UIHelper", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UIHelper> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UIHelper_class;
		p->proto = jsb_UIHelper_prototype;
		p->parentProto = NULL;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}


JSClass  *jsb_UILayer_class;
JSObject *jsb_UILayer_prototype;

JSBool js_cocos2dx_gui_UILayer_getRootWidget(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_getRootWidget : Invalid Native Object");
	if (argc == 0) {
		gui::UIRootWidget* ret = cobj->getRootWidget();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIRootWidget>(cx, (gui::UIRootWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_getRootWidget : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_getWidgetByTag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_getWidgetByTag : Invalid Native Object");
	if (argc == 1) {
		int arg0;
		ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_getWidgetByTag : Error processing arguments");
		gui::UIWidget* ret = cobj->getWidgetByTag(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_getWidgetByTag : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_removeWidget(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_removeWidget : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_removeWidget : Error processing arguments");
		cobj->removeWidget(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_removeWidget : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_init : Invalid Native Object");
	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_init : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_getWidgetByName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_getWidgetByName : Invalid Native Object");
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_getWidgetByName : Error processing arguments");
		gui::UIWidget* ret = cobj->getWidgetByName(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<gui::UIWidget>(cx, (gui::UIWidget*)ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_getWidgetByName : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_addWidget(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_addWidget : Invalid Native Object");
	if (argc == 1) {
		gui::UIWidget* arg0;
		do {
			if (!argv[0].isObject()) { ok = JS_FALSE; break; }
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			proxy = jsb_get_js_proxy(tmpObj);
			arg0 = (gui::UIWidget*)(proxy ? proxy->ptr : NULL);
			JSB_PRECONDITION2( arg0, cx, JS_FALSE, "Invalid Native Object");
		} while (0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_addWidget : Error processing arguments");
		cobj->addWidget(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_addWidget : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_setVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSBool ok = JS_TRUE;
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_setVisible : Invalid Native Object");
	if (argc == 1) {
		JSBool arg0;
		ok &= JS_ValueToBoolean(cx, argv[0], &arg0);
		JSB_PRECONDITION2(ok, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_setVisible : Error processing arguments");
		cobj->setVisible(arg0);
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_setVisible : wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_clear(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy = jsb_get_js_proxy(obj);
	gui::UILayer* cobj = (gui::UILayer *)(proxy ? proxy->ptr : NULL);
	JSB_PRECONDITION2( cobj, cx, JS_FALSE, "js_cocos2dx_gui_UILayer_clear : Invalid Native Object");
	if (argc == 0) {
		cobj->clear();
		JS_SET_RVAL(cx, vp, JSVAL_VOID);
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_clear : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_gui_UILayer_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILayer* ret = gui::UILayer::create();
		jsval jsret;
		do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<gui::UILayer>(cx, (gui::UILayer*)ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_create : wrong number of arguments");
	return JS_FALSE;
}

JSBool js_cocos2dx_gui_UILayer_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
	if (argc == 0) {
		gui::UILayer* cobj = new gui::UILayer();
		cocos2d::Object *_ccobj = dynamic_cast<cocos2d::Object *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
		TypeTest<gui::UILayer> t;
		js_type_class_t *typeClass = nullptr;
		long typeId = t.s_id();
		auto typeMapIter = _js_global_type_map.find(typeId);
		CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
		typeClass = typeMapIter->second;
		CCASSERT(typeClass, "The value is null.");
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t* p = jsb_new_proxy(cobj, obj);
		JS_AddNamedObjectRoot(cx, &p->obj, "gui::UILayer");
		return JS_TRUE;
	}

	JS_ReportError(cx, "js_cocos2dx_gui_UILayer_constructor : wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}


extern JSObject *jsb_Layer_prototype;

void js_cocos2dx_gui_UILayer_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (UILayer)", obj);
}

void js_register_cocos2dx_gui_UILayer(JSContext *cx, JSObject *global) {
	jsb_UILayer_class = (JSClass *)calloc(1, sizeof(JSClass));
	jsb_UILayer_class->name = "UILayer";
	jsb_UILayer_class->addProperty = JS_PropertyStub;
	jsb_UILayer_class->delProperty = JS_DeletePropertyStub;
	jsb_UILayer_class->getProperty = JS_PropertyStub;
	jsb_UILayer_class->setProperty = JS_StrictPropertyStub;
	jsb_UILayer_class->enumerate = JS_EnumerateStub;
	jsb_UILayer_class->resolve = JS_ResolveStub;
	jsb_UILayer_class->convert = JS_ConvertStub;
	jsb_UILayer_class->finalize = js_cocos2dx_gui_UILayer_finalize;
	jsb_UILayer_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("getRootWidget", js_cocos2dx_gui_UILayer_getRootWidget, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getWidgetByTag", js_cocos2dx_gui_UILayer_getWidgetByTag, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("removeWidget", js_cocos2dx_gui_UILayer_removeWidget, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("init", js_cocos2dx_gui_UILayer_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("getWidgetByName", js_cocos2dx_gui_UILayer_getWidgetByName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("addWidget", js_cocos2dx_gui_UILayer_addWidget, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("setVisible", js_cocos2dx_gui_UILayer_setVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FN("clear", js_cocos2dx_gui_UILayer_clear, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_gui_UILayer_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
		JS_FS_END
	};

	jsb_UILayer_prototype = JS_InitClass(
		cx, global,
		jsb_Layer_prototype,
		jsb_UILayer_class,
		js_cocos2dx_gui_UILayer_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);
	// make the class enumerable in the registered namespace
	JSBool found;
	JS_SetPropertyAttributes(cx, global, "UILayer", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<gui::UILayer> t;
	js_type_class_t *p;
	long typeId = t.s_id();
	if (_js_global_type_map.find(typeId) == _js_global_type_map.end())
	{
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->jsclass = jsb_UILayer_class;
		p->proto = jsb_UILayer_prototype;
		p->parentProto = jsb_Layer_prototype;
		_js_global_type_map.insert(std::make_pair(typeId, p));
	}
}

void register_all_cocos2dx_gui(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	JS::RootedValue nsval(cx);
	JSObject *ns;
	JS_GetProperty(cx, obj, "ccs", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "ccs", nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_cocos2dx_gui_UILayoutParameter(cx, obj);
	js_register_cocos2dx_gui_UIWidget(cx, obj);
	js_register_cocos2dx_gui_UILabelAtlas(cx, obj);
	js_register_cocos2dx_gui_UILayout(cx, obj);
	js_register_cocos2dx_gui_UIScrollView(cx, obj);
	js_register_cocos2dx_gui_UIListView(cx, obj);
	js_register_cocos2dx_gui_UILayer(cx, obj);
	js_register_cocos2dx_gui_UILinearLayoutParameter(cx, obj);
	js_register_cocos2dx_gui_UIHelper(cx, obj);
	js_register_cocos2dx_gui_UILabelBMFont(cx, obj);
	js_register_cocos2dx_gui_UILoadingBar(cx, obj);
	js_register_cocos2dx_gui_UIImageView(cx, obj);
	js_register_cocos2dx_gui_UICheckBox(cx, obj);
	js_register_cocos2dx_gui_UIButton(cx, obj);
	js_register_cocos2dx_gui_UIRelativeLayoutParameter(cx, obj);
	js_register_cocos2dx_gui_UILabel(cx, obj);
	js_register_cocos2dx_gui_UIPageView(cx, obj);
	js_register_cocos2dx_gui_UITextField(cx, obj);
	js_register_cocos2dx_gui_UISlider(cx, obj);
}

