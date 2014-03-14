#include "lua_cocos2dx_studio_auto.hpp"
#include "CocosGUI.h"
#include "CocoStudio.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_studio_UILayoutParameter_getLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayoutParameter_getLayoutType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getLayoutType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLayoutType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayoutParameter_getLayoutType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayoutParameter_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILayoutParameter* ret = gui::UILayoutParameter::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILayoutParameter*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILayoutParameter");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILayoutParameter");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayoutParameter_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayoutParameter_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILayoutParameter();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILayoutParameter");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILayoutParameter");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILayoutParameter",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayoutParameter_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILayoutParameter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILayoutParameter)");
    return 0;
}

int lua_register_cocos2dx_studio_UILayoutParameter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILayoutParameter");
    tolua_cclass(tolua_S,"UILayoutParameter","UILayoutParameter","",NULL);

    tolua_beginmodule(tolua_S,"UILayoutParameter");
        tolua_function(tolua_S,"getLayoutType",lua_cocos2dx_studio_UILayoutParameter_getLayoutType);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILayoutParameter_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILayoutParameter_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILayoutParameter).hash_code();
    g_luaType[typeId] = "UILayoutParameter";
    return 1;
}

int lua_cocos2dx_studio_UILinearLayoutParameter_setGravity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILinearLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILinearLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILinearLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILinearLayoutParameter_setGravity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UILinearGravity arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setGravity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setGravity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILinearLayoutParameter_setGravity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILinearLayoutParameter_getGravity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILinearLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILinearLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILinearLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILinearLayoutParameter_getGravity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getGravity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getGravity",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILinearLayoutParameter_getGravity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILinearLayoutParameter_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILinearLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILinearLayoutParameter* ret = gui::UILinearLayoutParameter::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILinearLayoutParameter*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILinearLayoutParameter");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILinearLayoutParameter");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILinearLayoutParameter_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILinearLayoutParameter_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILinearLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILinearLayoutParameter();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILinearLayoutParameter");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILinearLayoutParameter");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILinearLayoutParameter",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILinearLayoutParameter_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILinearLayoutParameter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILinearLayoutParameter)");
    return 0;
}

int lua_register_cocos2dx_studio_UILinearLayoutParameter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILinearLayoutParameter");
    tolua_cclass(tolua_S,"UILinearLayoutParameter","UILinearLayoutParameter","UILayoutParameter",NULL);

    tolua_beginmodule(tolua_S,"UILinearLayoutParameter");
        tolua_function(tolua_S,"setGravity",lua_cocos2dx_studio_UILinearLayoutParameter_setGravity);
        tolua_function(tolua_S,"getGravity",lua_cocos2dx_studio_UILinearLayoutParameter_getGravity);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILinearLayoutParameter_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILinearLayoutParameter_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILinearLayoutParameter).hash_code();
    g_luaType[typeId] = "UILinearLayoutParameter";
    return 1;
}

int lua_cocos2dx_studio_UIRelativeLayoutParameter_setAlign(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRelativeLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIRelativeLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIRelativeLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_setAlign'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIRelativeAlign arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setAlign(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAlign",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_setAlign'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeToWidgetName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRelativeLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIRelativeLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIRelativeLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeToWidgetName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setRelativeToWidgetName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRelativeToWidgetName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeToWidgetName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRelativeLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIRelativeLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIRelativeLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getRelativeName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRelativeName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeToWidgetName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRelativeLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIRelativeLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIRelativeLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeToWidgetName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getRelativeToWidgetName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRelativeToWidgetName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeToWidgetName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRelativeLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIRelativeLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIRelativeLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setRelativeName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRelativeName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRelativeLayoutParameter_getAlign(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRelativeLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIRelativeLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIRelativeLayoutParameter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_getAlign'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAlign",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_getAlign'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRelativeLayoutParameter_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIRelativeLayoutParameter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIRelativeLayoutParameter* ret = gui::UIRelativeLayoutParameter::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIRelativeLayoutParameter*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIRelativeLayoutParameter");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIRelativeLayoutParameter");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRelativeLayoutParameter_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRelativeLayoutParameter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIRelativeLayoutParameter();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIRelativeLayoutParameter");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIRelativeLayoutParameter");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIRelativeLayoutParameter",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRelativeLayoutParameter_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIRelativeLayoutParameter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIRelativeLayoutParameter)");
    return 0;
}

int lua_register_cocos2dx_studio_UIRelativeLayoutParameter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIRelativeLayoutParameter");
    tolua_cclass(tolua_S,"UIRelativeLayoutParameter","UIRelativeLayoutParameter","UILayoutParameter",NULL);

    tolua_beginmodule(tolua_S,"UIRelativeLayoutParameter");
        tolua_function(tolua_S,"setAlign",lua_cocos2dx_studio_UIRelativeLayoutParameter_setAlign);
        tolua_function(tolua_S,"setRelativeToWidgetName",lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeToWidgetName);
        tolua_function(tolua_S,"getRelativeName",lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeName);
        tolua_function(tolua_S,"getRelativeToWidgetName",lua_cocos2dx_studio_UIRelativeLayoutParameter_getRelativeToWidgetName);
        tolua_function(tolua_S,"setRelativeName",lua_cocos2dx_studio_UIRelativeLayoutParameter_setRelativeName);
        tolua_function(tolua_S,"getAlign",lua_cocos2dx_studio_UIRelativeLayoutParameter_getAlign);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIRelativeLayoutParameter_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIRelativeLayoutParameter_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIRelativeLayoutParameter).hash_code();
    g_luaType[typeId] = "UIRelativeLayoutParameter";
    return 1;
}

int lua_cocos2dx_studio_UIWidget_addChild(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_addChild'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->addChild(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addChild",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_addChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setActionTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setActionTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setActionTag(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setActionTag",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setActionTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setCascadeOpacityEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setCascadeOpacityEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCascadeOpacityEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCascadeOpacityEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setCascadeOpacityEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getChildren(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getChildren'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Array* ret = cobj->getChildren();
        array_to_luaval(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getChildren",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getChildren'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getPositionType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getPositionType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getPositionType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPositionType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getPositionType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getChildByName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getChildByName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->getChildByName(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getChildByName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getChildByName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipX();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipX",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipY();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipY",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_didNotSelectSelf(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_didNotSelectSelf'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->didNotSelectSelf();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "didNotSelectSelf",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_didNotSelectSelf'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setFocused(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setFocused'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFocused(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFocused",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setFocused'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setZOrder(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setZOrder'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setZOrder(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setZOrder",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setZOrder'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setScaleY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setScaleY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScaleY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScaleY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setScaleY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setScaleX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setScaleX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScaleX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScaleX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setScaleX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getLayoutParameter(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getLayoutParameter'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::LayoutParameterType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        gui::UILayoutParameter* ret = cobj->getLayoutParameter(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILayoutParameter*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILayoutParameter");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILayoutParameter");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLayoutParameter",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getLayoutParameter'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Color3B& ret = cobj->getColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getColor",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isBright(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isBright'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isBright();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isBright",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isBright'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getTag();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTag",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_addRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_addRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        int arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->addRenderer(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addRenderer",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_addRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getSizeType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getSizeType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getSizeType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSizeType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getSizeType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getPositionPercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getPositionPercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getPositionPercent();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPositionPercent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getPositionPercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_removeChild(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_removeChild'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->removeChild(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeChild",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_removeChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_convertToWorldSpace(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_convertToWorldSpace'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cocos2d::Point ret = cobj->convertToWorldSpace(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "convertToWorldSpace",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_convertToWorldSpace'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_removeAllChildren(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_removeAllChildren'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllChildren();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllChildren",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_removeAllChildren'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getRotationX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getRotationX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getRotationX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRotationX",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getRotationX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getRotationY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getRotationY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getRotationY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRotationY",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getRotationY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getSizePercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getSizePercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getSizePercent();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSizePercent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getSizePercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setPositionType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setPositionType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::PositionType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setPositionType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPositionType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setPositionType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isCascadeOpacityEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isCascadeOpacityEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isCascadeOpacityEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isCascadeOpacityEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isCascadeOpacityEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setParent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setParent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setParent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isTouchEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isTouchEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setTouchEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setTouchEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTouchEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setTouchEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setLayoutParameter(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setLayoutParameter'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UILayoutParameter* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UILayoutParameter",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UILayoutParameter*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setLayoutParameter(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLayoutParameter",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setLayoutParameter'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_clippingParentAreaContainPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_clippingParentAreaContainPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        bool ret = cobj->clippingParentAreaContainPoint(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clippingParentAreaContainPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_clippingParentAreaContainPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setPosition'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setPosition(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPosition",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setPosition'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_removeRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_removeRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        bool arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->removeRenderer(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeRenderer",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_removeRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_stopActionByTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_stopActionByTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->stopActionByTag(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopActionByTag",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_stopActionByTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_reorderChild(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_reorderChild'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->reorderChild(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "reorderChild",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_reorderChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getScale(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getScale'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScale",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getScale'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getAnchorPoint();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnchorPoint",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isFocused(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isFocused'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFocused();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFocused",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isFocused'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isVisible(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isVisible'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isVisible();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isVisible",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isVisible'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getLeftInParent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getLeftInParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getLeftInParent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLeftInParent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getLeftInParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setPositionPercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setPositionPercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setPositionPercent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPositionPercent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setPositionPercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getRotation(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getRotation'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getRotation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRotation",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getRotation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getBottomInParent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getBottomInParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getBottomInParent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBottomInParent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getBottomInParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_ignoreContentAdaptWithSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_ignoreContentAdaptWithSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->ignoreContentAdaptWithSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ignoreContentAdaptWithSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_ignoreContentAdaptWithSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getZOrder(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getZOrder'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getZOrder();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getZOrder",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getZOrder'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_runAction(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_runAction'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Action* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Action",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Action*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cocos2d::Action* ret = cobj->runAction(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Action*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Action");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Action");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "runAction",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_runAction'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_stopAllActions(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_stopAllActions'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stopAllActions();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopAllActions",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_stopAllActions'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getActionTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getActionTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getActionTag();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getActionTag",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getActionTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getActionByTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getActionByTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cocos2d::Action* ret = cobj->getActionByTag(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Action*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Action");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Action");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getActionByTag",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getActionByTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setRotationX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setRotationX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRotationX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRotationX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setRotationX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setRotationY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setRotationY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRotationY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRotationY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setRotationY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setBrightStyle(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setBrightStyle'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::BrightStyle arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setBrightStyle(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBrightStyle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setBrightStyle'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setUpdateEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setUpdateEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setUpdateEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setUpdateEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setUpdateEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setRotation(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setRotation'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setRotation(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setRotation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setRotation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setActionManager(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setActionManager'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ActionManager* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"ActionManager",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::ActionManager*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setActionManager(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setActionManager",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setActionManager'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getPosition(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getPosition'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getPosition();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPosition",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getPosition'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getParent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->getParent();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getParent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_hitTest(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_hitTest'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        bool ret = cobj->hitTest(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hitTest",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_hitTest'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setVisible'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setVisible(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVisible",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setVisible'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setSizePercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setSizePercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setSizePercent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSizePercent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setSizePercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setScale(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setScale'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScale",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setScale'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getTouchEndPos(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getTouchEndPos'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getTouchEndPos();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTouchEndPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getTouchEndPos'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getChildByTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getChildByTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->getChildByTag(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getChildByTag",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getChildByTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isIgnoreContentAdaptWithSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isIgnoreContentAdaptWithSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isIgnoreContentAdaptWithSize();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isIgnoreContentAdaptWithSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isIgnoreContentAdaptWithSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isUpdateEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isUpdateEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isUpdateEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isUpdateEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isUpdateEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_updateSizeAndPosition(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_updateSizeAndPosition'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->updateSizeAndPosition();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateSizeAndPosition",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_updateSizeAndPosition'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getWidgetType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getWidgetType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getWidgetType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getWidgetType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getWidgetType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getScaleY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getScaleY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getScaleY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScaleY",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getScaleY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getScaleX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getScaleX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getScaleX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getScaleX",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getScaleX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setCascadeColorEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setCascadeColorEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setCascadeColorEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCascadeColorEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setCascadeColorEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getOpacity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getOpacity();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getOpacity",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getTouchMovePos(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getTouchMovePos'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getTouchMovePos();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTouchMovePos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getTouchMovePos'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_removeFromParent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_removeFromParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeFromParent();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeFromParent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_removeFromParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getWorldPosition(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getWorldPosition'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Point ret = cobj->getWorldPosition();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getWorldPosition",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getWorldPosition'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_clone(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_clone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->clone();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clone",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_clone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_isCascadeColorEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_isCascadeColorEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isCascadeColorEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isCascadeColorEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_isCascadeColorEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_checkChildInfo(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_checkChildInfo'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        gui::UIWidget* arg1;
        cocos2d::Point arg2;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        do {
				if (!luaval_is_usertype(tolua_S,3,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (gui::UIWidget*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_point(tolua_S, 4, &arg2);
        if(!ok)
            return 0;
        cobj->checkChildInfo(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "checkChildInfo",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_checkChildInfo'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getTopInParent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getTopInParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getTopInParent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTopInParent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getTopInParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getRightInParent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getRightInParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getRightInParent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRightInParent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getRightInParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setTag(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTag",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getTouchStartPos(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getTouchStartPos'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Point& ret = cobj->getTouchStartPos();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTouchStartPos",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getTouchStartPos'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setSizeType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setSizeType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::SizeType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setSizeType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSizeType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setSizeType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_stopAction(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_stopAction'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Action* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Action",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Action*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->stopAction(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopAction",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_stopAction'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_setBright(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_setBright'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBright(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBright",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_setBright'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_getActionManager(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIWidget_getActionManager'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::ActionManager* ret = cobj->getActionManager();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::ActionManager*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ActionManager");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ActionManager");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getActionManager",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_getActionManager'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIWidget* ret = gui::UIWidget::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIWidget_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIWidget();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIWidget");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIWidget");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIWidget",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIWidget_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIWidget_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIWidget)");
    return 0;
}

int lua_register_cocos2dx_studio_UIWidget(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIWidget");
    tolua_cclass(tolua_S,"UIWidget","UIWidget","",NULL);

    tolua_beginmodule(tolua_S,"UIWidget");
        tolua_function(tolua_S,"addChild",lua_cocos2dx_studio_UIWidget_addChild);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UIWidget_getVirtualRenderer);
        tolua_function(tolua_S,"setActionTag",lua_cocos2dx_studio_UIWidget_setActionTag);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UIWidget_getDescription);
        tolua_function(tolua_S,"setCascadeOpacityEnabled",lua_cocos2dx_studio_UIWidget_setCascadeOpacityEnabled);
        tolua_function(tolua_S,"getChildren",lua_cocos2dx_studio_UIWidget_getChildren);
        tolua_function(tolua_S,"getPositionType",lua_cocos2dx_studio_UIWidget_getPositionType);
        tolua_function(tolua_S,"getChildByName",lua_cocos2dx_studio_UIWidget_getChildByName);
        tolua_function(tolua_S,"isEnabled",lua_cocos2dx_studio_UIWidget_isEnabled);
        tolua_function(tolua_S,"isFlipX",lua_cocos2dx_studio_UIWidget_isFlipX);
        tolua_function(tolua_S,"isFlipY",lua_cocos2dx_studio_UIWidget_isFlipY);
        tolua_function(tolua_S,"didNotSelectSelf",lua_cocos2dx_studio_UIWidget_didNotSelectSelf);
        tolua_function(tolua_S,"setFocused",lua_cocos2dx_studio_UIWidget_setFocused);
        tolua_function(tolua_S,"setZOrder",lua_cocos2dx_studio_UIWidget_setZOrder);
        tolua_function(tolua_S,"setScaleY",lua_cocos2dx_studio_UIWidget_setScaleY);
        tolua_function(tolua_S,"setScaleX",lua_cocos2dx_studio_UIWidget_setScaleX);
        tolua_function(tolua_S,"getLayoutParameter",lua_cocos2dx_studio_UIWidget_getLayoutParameter);
        tolua_function(tolua_S,"getColor",lua_cocos2dx_studio_UIWidget_getColor);
        tolua_function(tolua_S,"isBright",lua_cocos2dx_studio_UIWidget_isBright);
        tolua_function(tolua_S,"getTag",lua_cocos2dx_studio_UIWidget_getTag);
        tolua_function(tolua_S,"addRenderer",lua_cocos2dx_studio_UIWidget_addRenderer);
        tolua_function(tolua_S,"getSize",lua_cocos2dx_studio_UIWidget_getSize);
        tolua_function(tolua_S,"getSizeType",lua_cocos2dx_studio_UIWidget_getSizeType);
        tolua_function(tolua_S,"getPositionPercent",lua_cocos2dx_studio_UIWidget_getPositionPercent);
        tolua_function(tolua_S,"removeChild",lua_cocos2dx_studio_UIWidget_removeChild);
        tolua_function(tolua_S,"convertToWorldSpace",lua_cocos2dx_studio_UIWidget_convertToWorldSpace);
        tolua_function(tolua_S,"setSize",lua_cocos2dx_studio_UIWidget_setSize);
        tolua_function(tolua_S,"removeAllChildren",lua_cocos2dx_studio_UIWidget_removeAllChildren);
        tolua_function(tolua_S,"getRotationX",lua_cocos2dx_studio_UIWidget_getRotationX);
        tolua_function(tolua_S,"getRotationY",lua_cocos2dx_studio_UIWidget_getRotationY);
        tolua_function(tolua_S,"getSizePercent",lua_cocos2dx_studio_UIWidget_getSizePercent);
        tolua_function(tolua_S,"setPositionType",lua_cocos2dx_studio_UIWidget_setPositionType);
        tolua_function(tolua_S,"isCascadeOpacityEnabled",lua_cocos2dx_studio_UIWidget_isCascadeOpacityEnabled);
        tolua_function(tolua_S,"setParent",lua_cocos2dx_studio_UIWidget_setParent);
        tolua_function(tolua_S,"getName",lua_cocos2dx_studio_UIWidget_getName);
        tolua_function(tolua_S,"isTouchEnabled",lua_cocos2dx_studio_UIWidget_isTouchEnabled);
        tolua_function(tolua_S,"setTouchEnabled",lua_cocos2dx_studio_UIWidget_setTouchEnabled);
        tolua_function(tolua_S,"setLayoutParameter",lua_cocos2dx_studio_UIWidget_setLayoutParameter);
        tolua_function(tolua_S,"clippingParentAreaContainPoint",lua_cocos2dx_studio_UIWidget_clippingParentAreaContainPoint);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_studio_UIWidget_setPosition);
        tolua_function(tolua_S,"removeRenderer",lua_cocos2dx_studio_UIWidget_removeRenderer);
        tolua_function(tolua_S,"stopActionByTag",lua_cocos2dx_studio_UIWidget_stopActionByTag);
        tolua_function(tolua_S,"reorderChild",lua_cocos2dx_studio_UIWidget_reorderChild);
        tolua_function(tolua_S,"getScale",lua_cocos2dx_studio_UIWidget_getScale);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_studio_UIWidget_setColor);
        tolua_function(tolua_S,"getAnchorPoint",lua_cocos2dx_studio_UIWidget_getAnchorPoint);
        tolua_function(tolua_S,"isFocused",lua_cocos2dx_studio_UIWidget_isFocused);
        tolua_function(tolua_S,"isVisible",lua_cocos2dx_studio_UIWidget_isVisible);
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UIWidget_setAnchorPoint);
        tolua_function(tolua_S,"getLeftInParent",lua_cocos2dx_studio_UIWidget_getLeftInParent);
        tolua_function(tolua_S,"setPositionPercent",lua_cocos2dx_studio_UIWidget_setPositionPercent);
        tolua_function(tolua_S,"getRotation",lua_cocos2dx_studio_UIWidget_getRotation);
        tolua_function(tolua_S,"getBottomInParent",lua_cocos2dx_studio_UIWidget_getBottomInParent);
        tolua_function(tolua_S,"ignoreContentAdaptWithSize",lua_cocos2dx_studio_UIWidget_ignoreContentAdaptWithSize);
        tolua_function(tolua_S,"getZOrder",lua_cocos2dx_studio_UIWidget_getZOrder);
        tolua_function(tolua_S,"runAction",lua_cocos2dx_studio_UIWidget_runAction);
        tolua_function(tolua_S,"stopAllActions",lua_cocos2dx_studio_UIWidget_stopAllActions);
        tolua_function(tolua_S,"getActionTag",lua_cocos2dx_studio_UIWidget_getActionTag);
        tolua_function(tolua_S,"getActionByTag",lua_cocos2dx_studio_UIWidget_getActionByTag);
        tolua_function(tolua_S,"setRotationX",lua_cocos2dx_studio_UIWidget_setRotationX);
        tolua_function(tolua_S,"setRotationY",lua_cocos2dx_studio_UIWidget_setRotationY);
        tolua_function(tolua_S,"setBrightStyle",lua_cocos2dx_studio_UIWidget_setBrightStyle);
        tolua_function(tolua_S,"setName",lua_cocos2dx_studio_UIWidget_setName);
        tolua_function(tolua_S,"setFlipY",lua_cocos2dx_studio_UIWidget_setFlipY);
        tolua_function(tolua_S,"setFlipX",lua_cocos2dx_studio_UIWidget_setFlipX);
        tolua_function(tolua_S,"setUpdateEnabled",lua_cocos2dx_studio_UIWidget_setUpdateEnabled);
        tolua_function(tolua_S,"setRotation",lua_cocos2dx_studio_UIWidget_setRotation);
        tolua_function(tolua_S,"setActionManager",lua_cocos2dx_studio_UIWidget_setActionManager);
        tolua_function(tolua_S,"getPosition",lua_cocos2dx_studio_UIWidget_getPosition);
        tolua_function(tolua_S,"getParent",lua_cocos2dx_studio_UIWidget_getParent);
        tolua_function(tolua_S,"hitTest",lua_cocos2dx_studio_UIWidget_hitTest);
        tolua_function(tolua_S,"setVisible",lua_cocos2dx_studio_UIWidget_setVisible);
        tolua_function(tolua_S,"setSizePercent",lua_cocos2dx_studio_UIWidget_setSizePercent);
        tolua_function(tolua_S,"setEnabled",lua_cocos2dx_studio_UIWidget_setEnabled);
        tolua_function(tolua_S,"setScale",lua_cocos2dx_studio_UIWidget_setScale);
        tolua_function(tolua_S,"getTouchEndPos",lua_cocos2dx_studio_UIWidget_getTouchEndPos);
        tolua_function(tolua_S,"getChildByTag",lua_cocos2dx_studio_UIWidget_getChildByTag);
        tolua_function(tolua_S,"isIgnoreContentAdaptWithSize",lua_cocos2dx_studio_UIWidget_isIgnoreContentAdaptWithSize);
        tolua_function(tolua_S,"isUpdateEnabled",lua_cocos2dx_studio_UIWidget_isUpdateEnabled);
        tolua_function(tolua_S,"updateSizeAndPosition",lua_cocos2dx_studio_UIWidget_updateSizeAndPosition);
        tolua_function(tolua_S,"getRenderer",lua_cocos2dx_studio_UIWidget_getRenderer);
        tolua_function(tolua_S,"getWidgetType",lua_cocos2dx_studio_UIWidget_getWidgetType);
        tolua_function(tolua_S,"getScaleY",lua_cocos2dx_studio_UIWidget_getScaleY);
        tolua_function(tolua_S,"getScaleX",lua_cocos2dx_studio_UIWidget_getScaleX);
        tolua_function(tolua_S,"setCascadeColorEnabled",lua_cocos2dx_studio_UIWidget_setCascadeColorEnabled);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_studio_UIWidget_setOpacity);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UIWidget_getContentSize);
        tolua_function(tolua_S,"getOpacity",lua_cocos2dx_studio_UIWidget_getOpacity);
        tolua_function(tolua_S,"getTouchMovePos",lua_cocos2dx_studio_UIWidget_getTouchMovePos);
        tolua_function(tolua_S,"removeFromParent",lua_cocos2dx_studio_UIWidget_removeFromParent);
        tolua_function(tolua_S,"getWorldPosition",lua_cocos2dx_studio_UIWidget_getWorldPosition);
        tolua_function(tolua_S,"clone",lua_cocos2dx_studio_UIWidget_clone);
        tolua_function(tolua_S,"isCascadeColorEnabled",lua_cocos2dx_studio_UIWidget_isCascadeColorEnabled);
        tolua_function(tolua_S,"checkChildInfo",lua_cocos2dx_studio_UIWidget_checkChildInfo);
        tolua_function(tolua_S,"getTopInParent",lua_cocos2dx_studio_UIWidget_getTopInParent);
        tolua_function(tolua_S,"getRightInParent",lua_cocos2dx_studio_UIWidget_getRightInParent);
        tolua_function(tolua_S,"setTag",lua_cocos2dx_studio_UIWidget_setTag);
        tolua_function(tolua_S,"getTouchStartPos",lua_cocos2dx_studio_UIWidget_getTouchStartPos);
        tolua_function(tolua_S,"setSizeType",lua_cocos2dx_studio_UIWidget_setSizeType);
        tolua_function(tolua_S,"stopAction",lua_cocos2dx_studio_UIWidget_stopAction);
        tolua_function(tolua_S,"setBright",lua_cocos2dx_studio_UIWidget_setBright);
        tolua_function(tolua_S,"getActionManager",lua_cocos2dx_studio_UIWidget_getActionManager);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIWidget_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIWidget_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIWidget).hash_code();
    g_luaType[typeId] = "UIWidget";
    return 1;
}

int lua_cocos2dx_studio_UILayout_setBackGroundColorVector(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setBackGroundColorVector'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setBackGroundColorVector(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackGroundColorVector",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setBackGroundColorVector'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_isClippingEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_isClippingEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isClippingEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isClippingEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_isClippingEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_getBackGroundImageTextureSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_getBackGroundImageTextureSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getBackGroundImageTextureSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBackGroundImageTextureSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_getBackGroundImageTextureSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_getLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_getLayoutType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getLayoutType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLayoutType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_getLayoutType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setBackGroundColorType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setBackGroundColorType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::LayoutBackGroundColorType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setBackGroundColorType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackGroundColorType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setBackGroundColorType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setBackGroundImage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setBackGroundImage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setBackGroundImage(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->setBackGroundImage(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackGroundImage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setBackGroundImage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setBackGroundColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setBackGroundColor'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Color3B arg0;
            ok &= luaval_to_color3b(tolua_S, 2, &arg0);

            if (!ok) { break; }
            cocos2d::Color3B arg1;
            ok &= luaval_to_color3b(tolua_S, 3, &arg1);

            if (!ok) { break; }
            cobj->setBackGroundColor(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Color3B arg0;
            ok &= luaval_to_color3b(tolua_S, 2, &arg0);

            if (!ok) { break; }
            cobj->setBackGroundColor(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackGroundColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setBackGroundColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_hitTest(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_hitTest'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        bool ret = cobj->hitTest(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "hitTest",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_hitTest'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setBackGroundColorOpacity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setBackGroundColorOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setBackGroundColorOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackGroundColorOpacity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setBackGroundColorOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setBackGroundImageCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setBackGroundImageCapInsets'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setBackGroundImageCapInsets(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackGroundImageCapInsets",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setBackGroundImageCapInsets'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_addChild(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_addChild'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->addChild(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addChild",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_addChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_removeBackGroundImage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_removeBackGroundImage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeBackGroundImage();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBackGroundImage",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_removeBackGroundImage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setBackGroundImageScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setBackGroundImageScale9Enabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBackGroundImageScale9Enabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackGroundImageScale9Enabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setBackGroundImageScale9Enabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_doLayout(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_doLayout'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->doLayout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "doLayout",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_doLayout'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setClippingEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setClippingEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setClippingEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setClippingEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setClippingEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_setLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayout_setLayoutType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::LayoutType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setLayoutType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLayoutType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_setLayoutType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILayout",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILayout* ret = gui::UILayout::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILayout*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILayout");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILayout");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayout_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILayout();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILayout");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILayout");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILayout",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayout_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILayout_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILayout)");
    return 0;
}

int lua_register_cocos2dx_studio_UILayout(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILayout");
    tolua_cclass(tolua_S,"UILayout","UILayout","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UILayout");
        tolua_function(tolua_S,"setBackGroundColorVector",lua_cocos2dx_studio_UILayout_setBackGroundColorVector);
        tolua_function(tolua_S,"isClippingEnabled",lua_cocos2dx_studio_UILayout_isClippingEnabled);
        tolua_function(tolua_S,"getBackGroundImageTextureSize",lua_cocos2dx_studio_UILayout_getBackGroundImageTextureSize);
        tolua_function(tolua_S,"getLayoutType",lua_cocos2dx_studio_UILayout_getLayoutType);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_studio_UILayout_setColor);
        tolua_function(tolua_S,"setBackGroundColorType",lua_cocos2dx_studio_UILayout_setBackGroundColorType);
        tolua_function(tolua_S,"setBackGroundImage",lua_cocos2dx_studio_UILayout_setBackGroundImage);
        tolua_function(tolua_S,"setBackGroundColor",lua_cocos2dx_studio_UILayout_setBackGroundColor);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UILayout_getDescription);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_studio_UILayout_setOpacity);
        tolua_function(tolua_S,"hitTest",lua_cocos2dx_studio_UILayout_hitTest);
        tolua_function(tolua_S,"setBackGroundColorOpacity",lua_cocos2dx_studio_UILayout_setBackGroundColorOpacity);
        tolua_function(tolua_S,"setBackGroundImageCapInsets",lua_cocos2dx_studio_UILayout_setBackGroundImageCapInsets);
        tolua_function(tolua_S,"addChild",lua_cocos2dx_studio_UILayout_addChild);
        tolua_function(tolua_S,"removeBackGroundImage",lua_cocos2dx_studio_UILayout_removeBackGroundImage);
        tolua_function(tolua_S,"setBackGroundImageScale9Enabled",lua_cocos2dx_studio_UILayout_setBackGroundImageScale9Enabled);
        tolua_function(tolua_S,"doLayout",lua_cocos2dx_studio_UILayout_doLayout);
        tolua_function(tolua_S,"setClippingEnabled",lua_cocos2dx_studio_UILayout_setClippingEnabled);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UILayout_getContentSize);
        tolua_function(tolua_S,"setLayoutType",lua_cocos2dx_studio_UILayout_setLayoutType);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILayout_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILayout_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILayout).hash_code();
    g_luaType[typeId] = "UILayout";
    return 1;
}

int lua_cocos2dx_studio_UIRootWidget_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRootWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIRootWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIRootWidget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIRootWidget_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRootWidget_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRootWidget_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIRootWidget",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIRootWidget* ret = gui::UIRootWidget::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIRootWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIRootWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIRootWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRootWidget_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIRootWidget_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIRootWidget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIRootWidget();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIRootWidget");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIRootWidget");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIRootWidget",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIRootWidget_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIRootWidget_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIRootWidget)");
    return 0;
}

int lua_register_cocos2dx_studio_UIRootWidget(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIRootWidget");
    tolua_cclass(tolua_S,"UIRootWidget","UIRootWidget","UILayout",NULL);

    tolua_beginmodule(tolua_S,"UIRootWidget");
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UIRootWidget_getDescription);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIRootWidget_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIRootWidget_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIRootWidget).hash_code();
    g_luaType[typeId] = "UIRootWidget";
    return 1;
}

int lua_cocos2dx_studio_UIButton_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_getTitleText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_getTitleText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getTitleText();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTitleText",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_getTitleText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setTitleFontSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTitleFontSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTitleFontSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setTitleFontSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setScale9Enabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScale9Enabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScale9Enabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setScale9Enabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setTitleColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setTitleColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTitleColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setTitleColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_ignoreContentAdaptWithSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_ignoreContentAdaptWithSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->ignoreContentAdaptWithSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ignoreContentAdaptWithSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_ignoreContentAdaptWithSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setCapInsetsDisabledRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setCapInsetsDisabledRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsetsDisabledRenderer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsetsDisabledRenderer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setCapInsetsDisabledRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_isFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_isFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipX();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipX",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_isFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_isFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_isFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipY();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipY",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_isFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_loadTextureDisabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_loadTextureDisabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextureDisabled(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTextureDisabled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureDisabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_loadTextureDisabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setTitleText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setTitleText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTitleText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTitleText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setTitleText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setCapInsetsNormalRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setCapInsetsNormalRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsetsNormalRenderer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsetsNormalRenderer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setCapInsetsNormalRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_loadTexturePressed(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_loadTexturePressed'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTexturePressed(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTexturePressed(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTexturePressed",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_loadTexturePressed'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setTitleFontName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setTitleFontName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setTitleFontName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTitleFontName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setTitleFontName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_loadTextures(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_loadTextures'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextures(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        gui::TextureResType arg3;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        if(!ok)
            return 0;
        cobj->loadTextures(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextures",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_loadTextures'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_getTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_getTitleColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Color3B& ret = cobj->getTitleColor();
        color3b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTitleColor",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_getTitleColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_loadTextureNormal(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_loadTextureNormal'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextureNormal(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTextureNormal(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureNormal",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_loadTextureNormal'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setCapInsetsPressedRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setCapInsetsPressedRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsetsPressedRenderer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsetsPressedRenderer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setCapInsetsPressedRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_getTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_getTitleFontSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getTitleFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTitleFontSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_getTitleFontSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_getTitleFontName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_getTitleFontName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getTitleFontName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTitleFontName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_getTitleFontName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setCapInsets'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsets(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsets",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setCapInsets'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_setPressedActionEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIButton_setPressedActionEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPressedActionEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPressedActionEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_setPressedActionEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIButton* ret = gui::UIButton::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIButton*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIButton");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIButton");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIButton_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIButton();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIButton");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIButton");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIButton",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIButton_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIButton)");
    return 0;
}

int lua_register_cocos2dx_studio_UIButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIButton");
    tolua_cclass(tolua_S,"UIButton","UIButton","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UIButton");
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UIButton_setAnchorPoint);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UIButton_getVirtualRenderer);
        tolua_function(tolua_S,"getTitleText",lua_cocos2dx_studio_UIButton_getTitleText);
        tolua_function(tolua_S,"setTitleFontSize",lua_cocos2dx_studio_UIButton_setTitleFontSize);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UIButton_getDescription);
        tolua_function(tolua_S,"setScale9Enabled",lua_cocos2dx_studio_UIButton_setScale9Enabled);
        tolua_function(tolua_S,"setTitleColor",lua_cocos2dx_studio_UIButton_setTitleColor);
        tolua_function(tolua_S,"ignoreContentAdaptWithSize",lua_cocos2dx_studio_UIButton_ignoreContentAdaptWithSize);
        tolua_function(tolua_S,"setCapInsetsDisabledRenderer",lua_cocos2dx_studio_UIButton_setCapInsetsDisabledRenderer);
        tolua_function(tolua_S,"isFlipX",lua_cocos2dx_studio_UIButton_isFlipX);
        tolua_function(tolua_S,"isFlipY",lua_cocos2dx_studio_UIButton_isFlipY);
        tolua_function(tolua_S,"loadTextureDisabled",lua_cocos2dx_studio_UIButton_loadTextureDisabled);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UIButton_getContentSize);
        tolua_function(tolua_S,"setTitleText",lua_cocos2dx_studio_UIButton_setTitleText);
        tolua_function(tolua_S,"setCapInsetsNormalRenderer",lua_cocos2dx_studio_UIButton_setCapInsetsNormalRenderer);
        tolua_function(tolua_S,"loadTexturePressed",lua_cocos2dx_studio_UIButton_loadTexturePressed);
        tolua_function(tolua_S,"setFlipY",lua_cocos2dx_studio_UIButton_setFlipY);
        tolua_function(tolua_S,"setFlipX",lua_cocos2dx_studio_UIButton_setFlipX);
        tolua_function(tolua_S,"setTitleFontName",lua_cocos2dx_studio_UIButton_setTitleFontName);
        tolua_function(tolua_S,"loadTextures",lua_cocos2dx_studio_UIButton_loadTextures);
        tolua_function(tolua_S,"getTitleColor",lua_cocos2dx_studio_UIButton_getTitleColor);
        tolua_function(tolua_S,"loadTextureNormal",lua_cocos2dx_studio_UIButton_loadTextureNormal);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_studio_UIButton_setColor);
        tolua_function(tolua_S,"setCapInsetsPressedRenderer",lua_cocos2dx_studio_UIButton_setCapInsetsPressedRenderer);
        tolua_function(tolua_S,"getTitleFontSize",lua_cocos2dx_studio_UIButton_getTitleFontSize);
        tolua_function(tolua_S,"getTitleFontName",lua_cocos2dx_studio_UIButton_getTitleFontName);
        tolua_function(tolua_S,"setCapInsets",lua_cocos2dx_studio_UIButton_setCapInsets);
        tolua_function(tolua_S,"setPressedActionEnabled",lua_cocos2dx_studio_UIButton_setPressedActionEnabled);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIButton_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIButton_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIButton).hash_code();
    g_luaType[typeId] = "UIButton";
    return 1;
}

int lua_cocos2dx_studio_UICheckBox_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_getSelectedState(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_getSelectedState'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getSelectedState();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSelectedState",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_getSelectedState'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundSelected(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundSelected'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextureBackGroundSelected(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTextureBackGroundSelected(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureBackGroundSelected",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundSelected'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundDisabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundDisabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextureBackGroundDisabled(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTextureBackGroundDisabled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureBackGroundDisabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundDisabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_setFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_setFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_setFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_setFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_setFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_setFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_isFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_isFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipX();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipX",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_isFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_isFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_isFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipY();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipY",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_isFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_loadTextureFrontCross(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_loadTextureFrontCross'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextureFrontCross(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTextureFrontCross(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureFrontCross",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_loadTextureFrontCross'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_loadTextures(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_loadTextures'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextures(arg0, arg1, arg2, arg3, arg4);
        return 0;
    }
    if (argc == 6) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        const char* arg4;
        gui::TextureResType arg5;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp); arg4 = arg4_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5);
        if(!ok)
            return 0;
        cobj->loadTextures(arg0, arg1, arg2, arg3, arg4, arg5);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextures",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_loadTextures'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_loadTextureBackGround(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_loadTextureBackGround'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextureBackGround(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTextureBackGround(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureBackGround",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_loadTextureBackGround'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_setSelectedState(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_setSelectedState'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setSelectedState(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSelectedState",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_setSelectedState'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_loadTextureFrontCrossDisabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICheckBox*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICheckBox_loadTextureFrontCrossDisabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTextureFrontCrossDisabled(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTextureFrontCrossDisabled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTextureFrontCrossDisabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_loadTextureFrontCrossDisabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UICheckBox",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UICheckBox* ret = gui::UICheckBox::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UICheckBox*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UICheckBox");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UICheckBox");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICheckBox_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICheckBox* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UICheckBox();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UICheckBox");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UICheckBox");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UICheckBox",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICheckBox_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UICheckBox_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UICheckBox)");
    return 0;
}

int lua_register_cocos2dx_studio_UICheckBox(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UICheckBox");
    tolua_cclass(tolua_S,"UICheckBox","UICheckBox","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UICheckBox");
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UICheckBox_setAnchorPoint);
        tolua_function(tolua_S,"getSelectedState",lua_cocos2dx_studio_UICheckBox_getSelectedState);
        tolua_function(tolua_S,"loadTextureBackGroundSelected",lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundSelected);
        tolua_function(tolua_S,"loadTextureBackGroundDisabled",lua_cocos2dx_studio_UICheckBox_loadTextureBackGroundDisabled);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UICheckBox_getDescription);
        tolua_function(tolua_S,"setFlipY",lua_cocos2dx_studio_UICheckBox_setFlipY);
        tolua_function(tolua_S,"setFlipX",lua_cocos2dx_studio_UICheckBox_setFlipX);
        tolua_function(tolua_S,"isFlipX",lua_cocos2dx_studio_UICheckBox_isFlipX);
        tolua_function(tolua_S,"isFlipY",lua_cocos2dx_studio_UICheckBox_isFlipY);
        tolua_function(tolua_S,"loadTextureFrontCross",lua_cocos2dx_studio_UICheckBox_loadTextureFrontCross);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UICheckBox_getVirtualRenderer);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UICheckBox_getContentSize);
        tolua_function(tolua_S,"loadTextures",lua_cocos2dx_studio_UICheckBox_loadTextures);
        tolua_function(tolua_S,"loadTextureBackGround",lua_cocos2dx_studio_UICheckBox_loadTextureBackGround);
        tolua_function(tolua_S,"setSelectedState",lua_cocos2dx_studio_UICheckBox_setSelectedState);
        tolua_function(tolua_S,"loadTextureFrontCrossDisabled",lua_cocos2dx_studio_UICheckBox_loadTextureFrontCrossDisabled);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UICheckBox_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UICheckBox_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UICheckBox).hash_code();
    g_luaType[typeId] = "UICheckBox";
    return 1;
}

int lua_cocos2dx_studio_UIImageView_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_ignoreContentAdaptWithSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_ignoreContentAdaptWithSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->ignoreContentAdaptWithSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ignoreContentAdaptWithSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_ignoreContentAdaptWithSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_loadTexture(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_loadTexture'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTexture(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTexture(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_loadTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_setDoubleClickEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_setDoubleClickEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setDoubleClickEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDoubleClickEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_setDoubleClickEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_setFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_setFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_setFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_setFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_setFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_setFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_isFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_isFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipX();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipX",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_isFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_isFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_isFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipY();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipY",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_isFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_setScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_setScale9Enabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScale9Enabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScale9Enabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_setScale9Enabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_setTextureRect(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_setTextureRect'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setTextureRect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTextureRect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_setTextureRect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_setCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_setCapInsets'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsets(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsets",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_setCapInsets'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_checkDoubleClick(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIImageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIImageView_checkDoubleClick'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->checkDoubleClick(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "checkDoubleClick",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_checkDoubleClick'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIImageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIImageView* ret = gui::UIImageView::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIImageView*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIImageView");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIImageView");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIImageView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIImageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIImageView();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIImageView");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIImageView");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIImageView",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIImageView_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIImageView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIImageView)");
    return 0;
}

int lua_register_cocos2dx_studio_UIImageView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIImageView");
    tolua_cclass(tolua_S,"UIImageView","UIImageView","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UIImageView");
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UIImageView_setAnchorPoint);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UIImageView_getVirtualRenderer);
        tolua_function(tolua_S,"ignoreContentAdaptWithSize",lua_cocos2dx_studio_UIImageView_ignoreContentAdaptWithSize);
        tolua_function(tolua_S,"loadTexture",lua_cocos2dx_studio_UIImageView_loadTexture);
        tolua_function(tolua_S,"setDoubleClickEnabled",lua_cocos2dx_studio_UIImageView_setDoubleClickEnabled);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UIImageView_getDescription);
        tolua_function(tolua_S,"setFlipY",lua_cocos2dx_studio_UIImageView_setFlipY);
        tolua_function(tolua_S,"setFlipX",lua_cocos2dx_studio_UIImageView_setFlipX);
        tolua_function(tolua_S,"isFlipX",lua_cocos2dx_studio_UIImageView_isFlipX);
        tolua_function(tolua_S,"isFlipY",lua_cocos2dx_studio_UIImageView_isFlipY);
        tolua_function(tolua_S,"setScale9Enabled",lua_cocos2dx_studio_UIImageView_setScale9Enabled);
        tolua_function(tolua_S,"setTextureRect",lua_cocos2dx_studio_UIImageView_setTextureRect);
        tolua_function(tolua_S,"setCapInsets",lua_cocos2dx_studio_UIImageView_setCapInsets);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UIImageView_getContentSize);
        tolua_function(tolua_S,"checkDoubleClick",lua_cocos2dx_studio_UIImageView_checkDoubleClick);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIImageView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIImageView_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIImageView).hash_code();
    g_luaType[typeId] = "UIImageView";
    return 1;
}

int lua_cocos2dx_studio_UILabel_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_getStringValue(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_getStringValue'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getStringValue();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStringValue",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_getStringValue'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setScale(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setScale'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScale",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setScale'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setTextVerticalAlignment(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setTextVerticalAlignment'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextVAlignment arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setTextVerticalAlignment(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTextVerticalAlignment",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setTextVerticalAlignment'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setFontName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setFontName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFontName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFontName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setFontName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setTouchScaleChangeEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setTouchScaleChangeEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTouchScaleChangeEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchScaleChangeEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setTouchScaleChangeEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_isFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_isFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipX();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipX",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_isFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_isFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_isFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isFlipY();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isFlipY",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_isFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_isTouchScaleChangeEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_isTouchScaleChangeEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTouchScaleChangeEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTouchScaleChangeEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_isTouchScaleChangeEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setTextAreaSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setTextAreaSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setTextAreaSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTextAreaSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setTextAreaSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_getStringLength(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_getStringLength'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getStringLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStringLength",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_getStringLength'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setScaleY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setScaleY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScaleY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScaleY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setScaleY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setScaleX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setScaleX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScaleX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScaleX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setScaleX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setFlipY(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setFlipY'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipY(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipY",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setFlipY'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setFlipX(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setFlipX'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFlipX(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFlipX",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setFlipX'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setFontSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setFontSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setFontSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFontSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setFontSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_setTextHorizontalAlignment(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabel_setTextHorizontalAlignment'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextHAlignment arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setTextHorizontalAlignment(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTextHorizontalAlignment",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_setTextHorizontalAlignment'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILabel* ret = gui::UILabel::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILabel*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILabel");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILabel");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabel_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILabel();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILabel");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILabel");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILabel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabel_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILabel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILabel)");
    return 0;
}

int lua_register_cocos2dx_studio_UILabel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILabel");
    tolua_cclass(tolua_S,"UILabel","UILabel","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UILabel");
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UILabel_setAnchorPoint);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UILabel_getVirtualRenderer);
        tolua_function(tolua_S,"getStringValue",lua_cocos2dx_studio_UILabel_getStringValue);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UILabel_getDescription);
        tolua_function(tolua_S,"setScale",lua_cocos2dx_studio_UILabel_setScale);
        tolua_function(tolua_S,"setTextVerticalAlignment",lua_cocos2dx_studio_UILabel_setTextVerticalAlignment);
        tolua_function(tolua_S,"setFontName",lua_cocos2dx_studio_UILabel_setFontName);
        tolua_function(tolua_S,"setTouchScaleChangeEnabled",lua_cocos2dx_studio_UILabel_setTouchScaleChangeEnabled);
        tolua_function(tolua_S,"isFlipX",lua_cocos2dx_studio_UILabel_isFlipX);
        tolua_function(tolua_S,"isFlipY",lua_cocos2dx_studio_UILabel_isFlipY);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UILabel_getContentSize);
        tolua_function(tolua_S,"isTouchScaleChangeEnabled",lua_cocos2dx_studio_UILabel_isTouchScaleChangeEnabled);
        tolua_function(tolua_S,"setTextAreaSize",lua_cocos2dx_studio_UILabel_setTextAreaSize);
        tolua_function(tolua_S,"getStringLength",lua_cocos2dx_studio_UILabel_getStringLength);
        tolua_function(tolua_S,"setScaleY",lua_cocos2dx_studio_UILabel_setScaleY);
        tolua_function(tolua_S,"setScaleX",lua_cocos2dx_studio_UILabel_setScaleX);
        tolua_function(tolua_S,"setFlipY",lua_cocos2dx_studio_UILabel_setFlipY);
        tolua_function(tolua_S,"setFlipX",lua_cocos2dx_studio_UILabel_setFlipX);
        tolua_function(tolua_S,"setFontSize",lua_cocos2dx_studio_UILabel_setFontSize);
        tolua_function(tolua_S,"setText",lua_cocos2dx_studio_UILabel_setText);
        tolua_function(tolua_S,"setTextHorizontalAlignment",lua_cocos2dx_studio_UILabel_setTextHorizontalAlignment);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILabel_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILabel_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILabel).hash_code();
    g_luaType[typeId] = "UILabel";
    return 1;
}

int lua_cocos2dx_studio_UICCLabelAtlas_setProperty(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCLabelAtlas* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (gui::UICCLabelAtlas*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCLabelAtlas_setProperty'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 5) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cocos2d::Texture2D* arg1;
            do {
				if (!luaval_is_usertype(tolua_S,3,"Texture2D",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocos2d::Texture2D*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            unsigned int arg2;
            ok &= luaval_to_uint32(tolua_S, 4,&arg2);

            if (!ok) { break; }
            unsigned int arg3;
            ok &= luaval_to_uint32(tolua_S, 5,&arg3);

            if (!ok) { break; }
            unsigned int arg4;
            ok &= luaval_to_uint32(tolua_S, 6,&arg4);

            if (!ok) { break; }
            cobj->setProperty(arg0, arg1, arg2, arg3, arg4);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0);

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1);

            if (!ok) { break; }
            unsigned int arg2;
            ok &= luaval_to_uint32(tolua_S, 4,&arg2);

            if (!ok) { break; }
            unsigned int arg3;
            ok &= luaval_to_uint32(tolua_S, 5,&arg3);

            if (!ok) { break; }
            unsigned int arg4;
            ok &= luaval_to_uint32(tolua_S, 6,&arg4);

            if (!ok) { break; }
            cobj->setProperty(arg0, arg1, arg2, arg3, arg4);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProperty",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCLabelAtlas_setProperty'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCLabelAtlas_updateDisplayedOpacity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCLabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCLabelAtlas_updateDisplayedOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;
        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->updateDisplayedOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateDisplayedOpacity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCLabelAtlas_updateDisplayedOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCLabelAtlas_draw(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCLabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCLabelAtlas_draw'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->draw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCLabelAtlas_draw'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCLabelAtlas_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UICCLabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UICCLabelAtlas* ret = gui::UICCLabelAtlas::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UICCLabelAtlas*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UICCLabelAtlas");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UICCLabelAtlas");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCLabelAtlas_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCLabelAtlas_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCLabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UICCLabelAtlas();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UICCLabelAtlas");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UICCLabelAtlas");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UICCLabelAtlas",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCLabelAtlas_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UICCLabelAtlas_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UICCLabelAtlas)");
    return 0;
}

int lua_register_cocos2dx_studio_UICCLabelAtlas(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UICCLabelAtlas");
    tolua_cclass(tolua_S,"UICCLabelAtlas","UICCLabelAtlas","LabelAtlas",NULL);

    tolua_beginmodule(tolua_S,"UICCLabelAtlas");
        tolua_function(tolua_S,"setProperty",lua_cocos2dx_studio_UICCLabelAtlas_setProperty);
        tolua_function(tolua_S,"updateDisplayedOpacity",lua_cocos2dx_studio_UICCLabelAtlas_updateDisplayedOpacity);
        tolua_function(tolua_S,"draw",lua_cocos2dx_studio_UICCLabelAtlas_draw);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UICCLabelAtlas_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UICCLabelAtlas_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UICCLabelAtlas).hash_code();
    g_luaType[typeId] = "UICCLabelAtlas";
    return 1;
}

int lua_cocos2dx_studio_UILabelAtlas_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelAtlas_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelAtlas_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_getStringValue(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelAtlas_getStringValue'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getStringValue();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStringValue",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_getStringValue'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelAtlas_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelAtlas_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_setProperty(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelAtlas_setProperty'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        std::string arg0;
        std::string arg1;
        int arg2;
        int arg3;
        std::string arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        ok &= luaval_to_std_string(tolua_S, 3,&arg1);
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        ok &= luaval_to_std_string(tolua_S, 6,&arg4);
        if(!ok)
            return 0;
        cobj->setProperty(arg0, arg1, arg2, arg3, arg4);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setProperty",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_setProperty'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_setStringValue(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelAtlas*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelAtlas_setStringValue'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setStringValue(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setStringValue",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_setStringValue'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILabelAtlas",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILabelAtlas* ret = gui::UILabelAtlas::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILabelAtlas*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILabelAtlas");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILabelAtlas");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelAtlas_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelAtlas* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILabelAtlas();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILabelAtlas");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILabelAtlas");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILabelAtlas",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelAtlas_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILabelAtlas_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILabelAtlas)");
    return 0;
}

int lua_register_cocos2dx_studio_UILabelAtlas(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILabelAtlas");
    tolua_cclass(tolua_S,"UILabelAtlas","UILabelAtlas","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UILabelAtlas");
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UILabelAtlas_setAnchorPoint);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UILabelAtlas_getVirtualRenderer);
        tolua_function(tolua_S,"getStringValue",lua_cocos2dx_studio_UILabelAtlas_getStringValue);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UILabelAtlas_getDescription);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UILabelAtlas_getContentSize);
        tolua_function(tolua_S,"setProperty",lua_cocos2dx_studio_UILabelAtlas_setProperty);
        tolua_function(tolua_S,"setStringValue",lua_cocos2dx_studio_UILabelAtlas_setStringValue);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILabelAtlas_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILabelAtlas_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILabelAtlas).hash_code();
    g_luaType[typeId] = "UILabelAtlas";
    return 1;
}

int lua_cocos2dx_studio_UILoadingBar_setPercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_setPercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setPercent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPercent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_setPercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_ignoreContentAdaptWithSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_ignoreContentAdaptWithSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->ignoreContentAdaptWithSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ignoreContentAdaptWithSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_ignoreContentAdaptWithSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_loadTexture(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_loadTexture'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadTexture(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadTexture(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_loadTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_setDirection'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::LoadingBarType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDirection(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDirection",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_setDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_setScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_setScale9Enabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScale9Enabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScale9Enabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_setScale9Enabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_setCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_setCapInsets'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsets(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsets",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_setCapInsets'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_getDirection(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_getDirection'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getDirection();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDirection",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_getDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_getPercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILoadingBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILoadingBar_getPercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getPercent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPercent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_getPercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILoadingBar",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILoadingBar* ret = gui::UILoadingBar::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILoadingBar*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILoadingBar");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILoadingBar");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILoadingBar_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILoadingBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILoadingBar();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILoadingBar");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILoadingBar");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILoadingBar",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILoadingBar_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILoadingBar_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILoadingBar)");
    return 0;
}

int lua_register_cocos2dx_studio_UILoadingBar(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILoadingBar");
    tolua_cclass(tolua_S,"UILoadingBar","UILoadingBar","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UILoadingBar");
        tolua_function(tolua_S,"setPercent",lua_cocos2dx_studio_UILoadingBar_setPercent);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UILoadingBar_getVirtualRenderer);
        tolua_function(tolua_S,"ignoreContentAdaptWithSize",lua_cocos2dx_studio_UILoadingBar_ignoreContentAdaptWithSize);
        tolua_function(tolua_S,"loadTexture",lua_cocos2dx_studio_UILoadingBar_loadTexture);
        tolua_function(tolua_S,"setDirection",lua_cocos2dx_studio_UILoadingBar_setDirection);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UILoadingBar_getDescription);
        tolua_function(tolua_S,"setScale9Enabled",lua_cocos2dx_studio_UILoadingBar_setScale9Enabled);
        tolua_function(tolua_S,"setCapInsets",lua_cocos2dx_studio_UILoadingBar_setCapInsets);
        tolua_function(tolua_S,"getDirection",lua_cocos2dx_studio_UILoadingBar_getDirection);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UILoadingBar_getContentSize);
        tolua_function(tolua_S,"getPercent",lua_cocos2dx_studio_UILoadingBar_getPercent);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILoadingBar_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILoadingBar_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILoadingBar).hash_code();
    g_luaType[typeId] = "UILoadingBar";
    return 1;
}

int lua_cocos2dx_studio_UIScrollView_addChild(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_addChild'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->addChild(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addChild",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_addChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToTop(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToTop'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToTop(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToTop",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToTop'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToPercentHorizontal(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToPercentHorizontal'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        bool arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->scrollToPercentHorizontal(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToPercentHorizontal",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToPercentHorizontal'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_removeAllChildren(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_removeAllChildren'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllChildren();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllChildren",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_removeAllChildren'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToPercentBothDirection(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToPercentBothDirection'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Point arg0;
        double arg1;
        bool arg2;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->scrollToPercentBothDirection(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToPercentBothDirection",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToPercentBothDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_getChildren(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_getChildren'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Array* ret = cobj->getChildren();
        array_to_luaval(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getChildren",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_getChildren'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_getDirection(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_getDirection'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getDirection();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDirection",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_getDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToBottomLeft(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToBottomLeft'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToBottomLeft(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToBottomLeft",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToBottomLeft'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_getInnerContainer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_getInnerContainer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        gui::UILayout* ret = cobj->getInnerContainer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILayout*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILayout");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILayout");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInnerContainer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_getInnerContainer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToBottom(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToBottom'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToBottom();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToBottom",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToBottom'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_setDirection'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::SCROLLVIEW_DIR arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDirection(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDirection",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_setDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToTopLeft(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToTopLeft'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToTopLeft(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToTopLeft",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToTopLeft'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToTopRight(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToTopRight'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToTopRight();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToTopRight",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToTopRight'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToBottomLeft(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToBottomLeft'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToBottomLeft();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToBottomLeft",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToBottomLeft'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_setInnerContainerSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_setInnerContainerSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setInnerContainerSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInnerContainerSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_setInnerContainerSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_isInertiaScrollEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_isInertiaScrollEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isInertiaScrollEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isInertiaScrollEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_isInertiaScrollEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_getInnerContainerSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_getInnerContainerSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getInnerContainerSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInnerContainerSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_getInnerContainerSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_isBounceEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_isBounceEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isBounceEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isBounceEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_isBounceEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToPercentVertical(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToPercentVertical'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->jumpToPercentVertical(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToPercentVertical",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToPercentVertical'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_doLayout(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_doLayout'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->doLayout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "doLayout",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_doLayout'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_setInertiaScrollEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_setInertiaScrollEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInertiaScrollEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInertiaScrollEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_setInertiaScrollEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToTopLeft(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToTopLeft'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToTopLeft();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToTopLeft",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToTopLeft'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToPercentHorizontal(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToPercentHorizontal'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->jumpToPercentHorizontal(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToPercentHorizontal",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToPercentHorizontal'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToBottomRight(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToBottomRight'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToBottomRight();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToBottomRight",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToBottomRight'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_update(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_update'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_update'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_getLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_getLayoutType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getLayoutType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLayoutType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_getLayoutType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_setBounceEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_setBounceEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBounceEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBounceEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_setBounceEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToTop(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToTop'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToTop();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToTop",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToTop'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToLeft(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToLeft'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToLeft(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToLeft",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToLeft'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToPercentBothDirection(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToPercentBothDirection'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->jumpToPercentBothDirection(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToPercentBothDirection",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToPercentBothDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToPercentVertical(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToPercentVertical'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        bool arg2;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->scrollToPercentVertical(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToPercentVertical",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToPercentVertical'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToBottom(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToBottom'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToBottom(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToBottom",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToBottom'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToBottomRight(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToBottomRight'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToBottomRight(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToBottomRight",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToBottomRight'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToLeft(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToLeft'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToLeft();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToLeft",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToLeft'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToRight(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToRight'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToRight(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToRight",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToRight'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_removeChild(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_removeChild'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->removeChild(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeChild",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_removeChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_setLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_setLayoutType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::LayoutType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setLayoutType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLayoutType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_setLayoutType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_jumpToRight(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_jumpToRight'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->jumpToRight();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "jumpToRight",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_jumpToRight'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_scrollToTopRight(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIScrollView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIScrollView_scrollToTopRight'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        bool arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->scrollToTopRight(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToTopRight",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_scrollToTopRight'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIScrollView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIScrollView* ret = gui::UIScrollView::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIScrollView*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIScrollView");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIScrollView");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIScrollView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIScrollView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIScrollView();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIScrollView");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIScrollView");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIScrollView",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIScrollView_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIScrollView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIScrollView)");
    return 0;
}

int lua_register_cocos2dx_studio_UIScrollView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIScrollView");
    tolua_cclass(tolua_S,"UIScrollView","UIScrollView","UILayout",NULL);

    tolua_beginmodule(tolua_S,"UIScrollView");
        tolua_function(tolua_S,"addChild",lua_cocos2dx_studio_UIScrollView_addChild);
        tolua_function(tolua_S,"scrollToTop",lua_cocos2dx_studio_UIScrollView_scrollToTop);
        tolua_function(tolua_S,"scrollToPercentHorizontal",lua_cocos2dx_studio_UIScrollView_scrollToPercentHorizontal);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UIScrollView_getDescription);
        tolua_function(tolua_S,"removeAllChildren",lua_cocos2dx_studio_UIScrollView_removeAllChildren);
        tolua_function(tolua_S,"scrollToPercentBothDirection",lua_cocos2dx_studio_UIScrollView_scrollToPercentBothDirection);
        tolua_function(tolua_S,"getChildren",lua_cocos2dx_studio_UIScrollView_getChildren);
        tolua_function(tolua_S,"getDirection",lua_cocos2dx_studio_UIScrollView_getDirection);
        tolua_function(tolua_S,"scrollToBottomLeft",lua_cocos2dx_studio_UIScrollView_scrollToBottomLeft);
        tolua_function(tolua_S,"getInnerContainer",lua_cocos2dx_studio_UIScrollView_getInnerContainer);
        tolua_function(tolua_S,"jumpToBottom",lua_cocos2dx_studio_UIScrollView_jumpToBottom);
        tolua_function(tolua_S,"setDirection",lua_cocos2dx_studio_UIScrollView_setDirection);
        tolua_function(tolua_S,"scrollToTopLeft",lua_cocos2dx_studio_UIScrollView_scrollToTopLeft);
        tolua_function(tolua_S,"jumpToTopRight",lua_cocos2dx_studio_UIScrollView_jumpToTopRight);
        tolua_function(tolua_S,"jumpToBottomLeft",lua_cocos2dx_studio_UIScrollView_jumpToBottomLeft);
        tolua_function(tolua_S,"setInnerContainerSize",lua_cocos2dx_studio_UIScrollView_setInnerContainerSize);
        tolua_function(tolua_S,"isInertiaScrollEnabled",lua_cocos2dx_studio_UIScrollView_isInertiaScrollEnabled);
        tolua_function(tolua_S,"getInnerContainerSize",lua_cocos2dx_studio_UIScrollView_getInnerContainerSize);
        tolua_function(tolua_S,"isBounceEnabled",lua_cocos2dx_studio_UIScrollView_isBounceEnabled);
        tolua_function(tolua_S,"jumpToPercentVertical",lua_cocos2dx_studio_UIScrollView_jumpToPercentVertical);
        tolua_function(tolua_S,"doLayout",lua_cocos2dx_studio_UIScrollView_doLayout);
        tolua_function(tolua_S,"setInertiaScrollEnabled",lua_cocos2dx_studio_UIScrollView_setInertiaScrollEnabled);
        tolua_function(tolua_S,"jumpToTopLeft",lua_cocos2dx_studio_UIScrollView_jumpToTopLeft);
        tolua_function(tolua_S,"jumpToPercentHorizontal",lua_cocos2dx_studio_UIScrollView_jumpToPercentHorizontal);
        tolua_function(tolua_S,"jumpToBottomRight",lua_cocos2dx_studio_UIScrollView_jumpToBottomRight);
        tolua_function(tolua_S,"update",lua_cocos2dx_studio_UIScrollView_update);
        tolua_function(tolua_S,"getLayoutType",lua_cocos2dx_studio_UIScrollView_getLayoutType);
        tolua_function(tolua_S,"setBounceEnabled",lua_cocos2dx_studio_UIScrollView_setBounceEnabled);
        tolua_function(tolua_S,"jumpToTop",lua_cocos2dx_studio_UIScrollView_jumpToTop);
        tolua_function(tolua_S,"scrollToLeft",lua_cocos2dx_studio_UIScrollView_scrollToLeft);
        tolua_function(tolua_S,"jumpToPercentBothDirection",lua_cocos2dx_studio_UIScrollView_jumpToPercentBothDirection);
        tolua_function(tolua_S,"scrollToPercentVertical",lua_cocos2dx_studio_UIScrollView_scrollToPercentVertical);
        tolua_function(tolua_S,"scrollToBottom",lua_cocos2dx_studio_UIScrollView_scrollToBottom);
        tolua_function(tolua_S,"scrollToBottomRight",lua_cocos2dx_studio_UIScrollView_scrollToBottomRight);
        tolua_function(tolua_S,"jumpToLeft",lua_cocos2dx_studio_UIScrollView_jumpToLeft);
        tolua_function(tolua_S,"scrollToRight",lua_cocos2dx_studio_UIScrollView_scrollToRight);
        tolua_function(tolua_S,"removeChild",lua_cocos2dx_studio_UIScrollView_removeChild);
        tolua_function(tolua_S,"setLayoutType",lua_cocos2dx_studio_UIScrollView_setLayoutType);
        tolua_function(tolua_S,"jumpToRight",lua_cocos2dx_studio_UIScrollView_jumpToRight);
        tolua_function(tolua_S,"scrollToTopRight",lua_cocos2dx_studio_UIScrollView_scrollToTopRight);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIScrollView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIScrollView_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIScrollView).hash_code();
    g_luaType[typeId] = "UIScrollView";
    return 1;
}

int lua_cocos2dx_studio_UIListView_getIndex(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_getIndex'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        unsigned int ret = cobj->getIndex(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getIndex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_getIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_setGravity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_setGravity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::ListViewGravity arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setGravity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setGravity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_setGravity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_pushBackCustomItem(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_pushBackCustomItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->pushBackCustomItem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pushBackCustomItem",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_pushBackCustomItem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_setDirection(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_setDirection'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::SCROLLVIEW_DIR arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setDirection(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDirection",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_setDirection'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_getItems(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_getItems'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Array* ret = cobj->getItems();
        array_to_luaval(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getItems",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_getItems'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_removeItem(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_removeItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->removeItem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeItem",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_removeItem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_getCurSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_getCurSelectedIndex'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getCurSelectedIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurSelectedIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_getCurSelectedIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_insertDefaultItem(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_insertDefaultItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->insertDefaultItem(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertDefaultItem",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_insertDefaultItem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_setItemsMargin(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_setItemsMargin'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setItemsMargin(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setItemsMargin",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_setItemsMargin'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_refreshView(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_refreshView'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->refreshView();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "refreshView",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_refreshView'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_removeLastItem(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_removeLastItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeLastItem();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeLastItem",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_removeLastItem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_getItem(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_getItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->getItem(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getItem",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_getItem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_setItemModel(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_setItemModel'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setItemModel(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setItemModel",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_setItemModel'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_pushBackDefaultItem(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_pushBackDefaultItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pushBackDefaultItem();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pushBackDefaultItem",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_pushBackDefaultItem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_insertCustomItem(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIListView_insertCustomItem'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        gui::UIWidget* arg0;
        int arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->insertCustomItem(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertCustomItem",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_insertCustomItem'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIListView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIListView* ret = gui::UIListView::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIListView*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIListView");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIListView");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIListView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIListView();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIListView");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIListView");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIListView",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIListView_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIListView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIListView)");
    return 0;
}

int lua_register_cocos2dx_studio_UIListView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIListView");
    tolua_cclass(tolua_S,"UIListView","UIListView","UIScrollView",NULL);

    tolua_beginmodule(tolua_S,"UIListView");
        tolua_function(tolua_S,"getIndex",lua_cocos2dx_studio_UIListView_getIndex);
        tolua_function(tolua_S,"setGravity",lua_cocos2dx_studio_UIListView_setGravity);
        tolua_function(tolua_S,"pushBackCustomItem",lua_cocos2dx_studio_UIListView_pushBackCustomItem);
        tolua_function(tolua_S,"setDirection",lua_cocos2dx_studio_UIListView_setDirection);
        tolua_function(tolua_S,"getItems",lua_cocos2dx_studio_UIListView_getItems);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UIListView_getDescription);
        tolua_function(tolua_S,"removeItem",lua_cocos2dx_studio_UIListView_removeItem);
        tolua_function(tolua_S,"getCurSelectedIndex",lua_cocos2dx_studio_UIListView_getCurSelectedIndex);
        tolua_function(tolua_S,"insertDefaultItem",lua_cocos2dx_studio_UIListView_insertDefaultItem);
        tolua_function(tolua_S,"setItemsMargin",lua_cocos2dx_studio_UIListView_setItemsMargin);
        tolua_function(tolua_S,"refreshView",lua_cocos2dx_studio_UIListView_refreshView);
        tolua_function(tolua_S,"removeLastItem",lua_cocos2dx_studio_UIListView_removeLastItem);
        tolua_function(tolua_S,"getItem",lua_cocos2dx_studio_UIListView_getItem);
        tolua_function(tolua_S,"setItemModel",lua_cocos2dx_studio_UIListView_setItemModel);
        tolua_function(tolua_S,"pushBackDefaultItem",lua_cocos2dx_studio_UIListView_pushBackDefaultItem);
        tolua_function(tolua_S,"insertCustomItem",lua_cocos2dx_studio_UIListView_insertCustomItem);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIListView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIListView_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIListView).hash_code();
    g_luaType[typeId] = "UIListView";
    return 1;
}

int lua_cocos2dx_studio_UISlider_setPercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_setPercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setPercent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPercent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_setPercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_loadSlidBallTextureNormal(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTextureNormal'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadSlidBallTextureNormal(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadSlidBallTextureNormal(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadSlidBallTextureNormal",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTextureNormal'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_loadBarTexture(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_loadBarTexture'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadBarTexture(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadBarTexture(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadBarTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_loadBarTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_loadProgressBarTexture(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_loadProgressBarTexture'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadProgressBarTexture(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadProgressBarTexture(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadProgressBarTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_loadProgressBarTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_loadSlidBallTextures(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTextures'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadSlidBallTextures(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        gui::TextureResType arg3;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3);
        if(!ok)
            return 0;
        cobj->loadSlidBallTextures(arg0, arg1, arg2, arg3);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadSlidBallTextures",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTextures'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_setCapInsetProgressBarRebderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_setCapInsetProgressBarRebderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsetProgressBarRebderer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsetProgressBarRebderer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_setCapInsetProgressBarRebderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_setCapInsetsBarRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_setCapInsetsBarRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsetsBarRenderer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsetsBarRenderer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_setCapInsetsBarRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_setScale9Enabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_setScale9Enabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setScale9Enabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setScale9Enabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_setScale9Enabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_setCapInsets(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_setCapInsets'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setCapInsets(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCapInsets",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_setCapInsets'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_ignoreContentAdaptWithSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_ignoreContentAdaptWithSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->ignoreContentAdaptWithSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ignoreContentAdaptWithSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_ignoreContentAdaptWithSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_loadSlidBallTexturePressed(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTexturePressed'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadSlidBallTexturePressed(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadSlidBallTexturePressed(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadSlidBallTexturePressed",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTexturePressed'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_loadSlidBallTextureDisabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTextureDisabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->loadSlidBallTextureDisabled(arg0);
        return 0;
    }
    if (argc == 2) 
    {
        const char* arg0;
        gui::TextureResType arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->loadSlidBallTextureDisabled(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "loadSlidBallTextureDisabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_loadSlidBallTextureDisabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_getPercent(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UISlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UISlider_getPercent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getPercent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPercent",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_getPercent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UISlider",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UISlider* ret = gui::UISlider::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UISlider*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UISlider");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UISlider");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UISlider_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UISlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UISlider();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UISlider");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UISlider");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UISlider",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UISlider_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UISlider_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UISlider)");
    return 0;
}

int lua_register_cocos2dx_studio_UISlider(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UISlider");
    tolua_cclass(tolua_S,"UISlider","UISlider","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UISlider");
        tolua_function(tolua_S,"setPercent",lua_cocos2dx_studio_UISlider_setPercent);
        tolua_function(tolua_S,"loadSlidBallTextureNormal",lua_cocos2dx_studio_UISlider_loadSlidBallTextureNormal);
        tolua_function(tolua_S,"loadBarTexture",lua_cocos2dx_studio_UISlider_loadBarTexture);
        tolua_function(tolua_S,"loadProgressBarTexture",lua_cocos2dx_studio_UISlider_loadProgressBarTexture);
        tolua_function(tolua_S,"loadSlidBallTextures",lua_cocos2dx_studio_UISlider_loadSlidBallTextures);
        tolua_function(tolua_S,"setCapInsetProgressBarRebderer",lua_cocos2dx_studio_UISlider_setCapInsetProgressBarRebderer);
        tolua_function(tolua_S,"setCapInsetsBarRenderer",lua_cocos2dx_studio_UISlider_setCapInsetsBarRenderer);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UISlider_getDescription);
        tolua_function(tolua_S,"setScale9Enabled",lua_cocos2dx_studio_UISlider_setScale9Enabled);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UISlider_getVirtualRenderer);
        tolua_function(tolua_S,"setCapInsets",lua_cocos2dx_studio_UISlider_setCapInsets);
        tolua_function(tolua_S,"ignoreContentAdaptWithSize",lua_cocos2dx_studio_UISlider_ignoreContentAdaptWithSize);
        tolua_function(tolua_S,"loadSlidBallTexturePressed",lua_cocos2dx_studio_UISlider_loadSlidBallTexturePressed);
        tolua_function(tolua_S,"loadSlidBallTextureDisabled",lua_cocos2dx_studio_UISlider_loadSlidBallTextureDisabled);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UISlider_getContentSize);
        tolua_function(tolua_S,"getPercent",lua_cocos2dx_studio_UISlider_getPercent);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UISlider_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UISlider_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UISlider).hash_code();
    g_luaType[typeId] = "UISlider";
    return 1;
}

int lua_cocos2dx_studio_UICCTextField_onTextFieldAttachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldAttachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextFieldTTF* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"TextFieldTTF",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::TextFieldTTF*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->onTextFieldAttachWithIME(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTextFieldAttachWithIME",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldAttachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setPasswordText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setPasswordText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setPasswordText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPasswordText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setPasswordText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setAttachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setAttachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setAttachWithIME(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAttachWithIME",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setAttachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_getDeleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_getDeleteBackward'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getDeleteBackward();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDeleteBackward",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_getDeleteBackward'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_getAttachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_getAttachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getAttachWithIME();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAttachWithIME",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_getAttachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_onTextFieldDeleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldDeleteBackward'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::TextFieldTTF* arg0;
        const char* arg1;
        int arg2;
        do {
				if (!luaval_is_usertype(tolua_S,2,"TextFieldTTF",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::TextFieldTTF*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        if(!ok)
            return 0;
        bool ret = cobj->onTextFieldDeleteBackward(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTextFieldDeleteBackward",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldDeleteBackward'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_getInsertText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_getInsertText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getInsertText();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInsertText",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_getInsertText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_deleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_deleteBackward'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->deleteBackward();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "deleteBackward",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_deleteBackward'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setInsertText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setInsertText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInsertText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInsertText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setInsertText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_getDetachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_getDetachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getDetachWithIME();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDetachWithIME",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_getDetachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_getCharCount(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_getCharCount'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getCharCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCharCount",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_getCharCount'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_closeIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_closeIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->closeIME();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "closeIME",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_closeIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setPasswordEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setPasswordEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPasswordEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPasswordEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setPasswordEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setMaxLengthEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setMaxLengthEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setMaxLengthEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxLengthEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setMaxLengthEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_isPasswordEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_isPasswordEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isPasswordEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isPasswordEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_isPasswordEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_insertText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_insertText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->insertText(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertText",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_insertText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setPasswordStyleText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setPasswordStyleText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setPasswordStyleText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPasswordStyleText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setPasswordStyleText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_onTextFieldInsertText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldInsertText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::TextFieldTTF* arg0;
        const char* arg1;
        int arg2;
        do {
				if (!luaval_is_usertype(tolua_S,2,"TextFieldTTF",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::TextFieldTTF*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);
        if(!ok)
            return 0;
        bool ret = cobj->onTextFieldInsertText(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTextFieldInsertText",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldInsertText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_onTextFieldDetachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldDetachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextFieldTTF* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"TextFieldTTF",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::TextFieldTTF*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->onTextFieldDetachWithIME(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "onTextFieldDetachWithIME",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_onTextFieldDetachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_getMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_getMaxLength'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getMaxLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxLength",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_getMaxLength'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_isMaxLengthEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_isMaxLengthEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isMaxLengthEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isMaxLengthEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_isMaxLengthEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_openIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_openIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->openIME();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "openIME",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_openIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setDetachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setDetachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setDetachWithIME(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDetachWithIME",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setDetachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setMaxLength'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setMaxLength(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxLength",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setMaxLength'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_setDeleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UICCTextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UICCTextField_setDeleteBackward'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setDeleteBackward(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDeleteBackward",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_setDeleteBackward'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UICCTextField",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const char* arg0;
        const char* arg1;
        double arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        gui::UICCTextField* ret = gui::UICCTextField::create(arg0, arg1, arg2);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UICCTextField*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UICCTextField");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UICCTextField");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UICCTextField_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UICCTextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UICCTextField();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UICCTextField");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UICCTextField");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UICCTextField",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UICCTextField_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UICCTextField_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UICCTextField)");
    return 0;
}

int lua_register_cocos2dx_studio_UICCTextField(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UICCTextField");
    tolua_cclass(tolua_S,"UICCTextField","UICCTextField","TextFieldTTF",NULL);

    tolua_beginmodule(tolua_S,"UICCTextField");
        tolua_function(tolua_S,"onTextFieldAttachWithIME",lua_cocos2dx_studio_UICCTextField_onTextFieldAttachWithIME);
        tolua_function(tolua_S,"setPasswordText",lua_cocos2dx_studio_UICCTextField_setPasswordText);
        tolua_function(tolua_S,"setAttachWithIME",lua_cocos2dx_studio_UICCTextField_setAttachWithIME);
        tolua_function(tolua_S,"getDeleteBackward",lua_cocos2dx_studio_UICCTextField_getDeleteBackward);
        tolua_function(tolua_S,"getAttachWithIME",lua_cocos2dx_studio_UICCTextField_getAttachWithIME);
        tolua_function(tolua_S,"onTextFieldDeleteBackward",lua_cocos2dx_studio_UICCTextField_onTextFieldDeleteBackward);
        tolua_function(tolua_S,"getInsertText",lua_cocos2dx_studio_UICCTextField_getInsertText);
        tolua_function(tolua_S,"deleteBackward",lua_cocos2dx_studio_UICCTextField_deleteBackward);
        tolua_function(tolua_S,"setInsertText",lua_cocos2dx_studio_UICCTextField_setInsertText);
        tolua_function(tolua_S,"getDetachWithIME",lua_cocos2dx_studio_UICCTextField_getDetachWithIME);
        tolua_function(tolua_S,"getCharCount",lua_cocos2dx_studio_UICCTextField_getCharCount);
        tolua_function(tolua_S,"closeIME",lua_cocos2dx_studio_UICCTextField_closeIME);
        tolua_function(tolua_S,"setPasswordEnabled",lua_cocos2dx_studio_UICCTextField_setPasswordEnabled);
        tolua_function(tolua_S,"setMaxLengthEnabled",lua_cocos2dx_studio_UICCTextField_setMaxLengthEnabled);
        tolua_function(tolua_S,"isPasswordEnabled",lua_cocos2dx_studio_UICCTextField_isPasswordEnabled);
        tolua_function(tolua_S,"insertText",lua_cocos2dx_studio_UICCTextField_insertText);
        tolua_function(tolua_S,"setPasswordStyleText",lua_cocos2dx_studio_UICCTextField_setPasswordStyleText);
        tolua_function(tolua_S,"onTextFieldInsertText",lua_cocos2dx_studio_UICCTextField_onTextFieldInsertText);
        tolua_function(tolua_S,"onTextFieldDetachWithIME",lua_cocos2dx_studio_UICCTextField_onTextFieldDetachWithIME);
        tolua_function(tolua_S,"getMaxLength",lua_cocos2dx_studio_UICCTextField_getMaxLength);
        tolua_function(tolua_S,"isMaxLengthEnabled",lua_cocos2dx_studio_UICCTextField_isMaxLengthEnabled);
        tolua_function(tolua_S,"openIME",lua_cocos2dx_studio_UICCTextField_openIME);
        tolua_function(tolua_S,"setDetachWithIME",lua_cocos2dx_studio_UICCTextField_setDetachWithIME);
        tolua_function(tolua_S,"setMaxLength",lua_cocos2dx_studio_UICCTextField_setMaxLength);
        tolua_function(tolua_S,"setDeleteBackward",lua_cocos2dx_studio_UICCTextField_setDeleteBackward);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UICCTextField_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UICCTextField_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UICCTextField).hash_code();
    g_luaType[typeId] = "UICCTextField";
    return 1;
}

int lua_cocos2dx_studio_UITextField_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setAttachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setAttachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setAttachWithIME(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAttachWithIME",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setAttachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getStringValue(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getStringValue'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getStringValue();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStringValue",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getStringValue'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getDeleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getDeleteBackward'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getDeleteBackward();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDeleteBackward",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getDeleteBackward'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getAttachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getAttachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getAttachWithIME();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAttachWithIME",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getAttachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setFontName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setFontName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setFontName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFontName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setFontName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getInsertText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getInsertText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getInsertText();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInsertText",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getInsertText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_initRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_initRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->initRenderer();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_initRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getDetachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getDetachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getDetachWithIME();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDetachWithIME",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getDetachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_init(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_didNotSelectSelf(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_didNotSelectSelf'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->didNotSelectSelf();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "didNotSelectSelf",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_didNotSelectSelf'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_isPasswordEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_isPasswordEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isPasswordEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isPasswordEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_isPasswordEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_attachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_attachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->attachWithIME();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "attachWithIME",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_attachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setPasswordEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setPasswordEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPasswordEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPasswordEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setPasswordEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_update(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_update'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_update'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setMaxLengthEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setMaxLengthEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setMaxLengthEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxLengthEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setMaxLengthEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setPasswordStyleText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setPasswordStyleText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setPasswordStyleText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPasswordStyleText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setPasswordStyleText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setFontSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setFontSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setFontSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFontSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setFontSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setPlaceHolder(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setPlaceHolder'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPlaceHolder(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPlaceHolder",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setPlaceHolder'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setColor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_getMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_getMaxLength'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getMaxLength();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMaxLength",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_getMaxLength'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_isMaxLengthEnabled(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_isMaxLengthEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isMaxLengthEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isMaxLengthEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_isMaxLengthEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setDetachWithIME(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setDetachWithIME'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setDetachWithIME(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDetachWithIME",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setDetachWithIME'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setInsertText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setInsertText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setInsertText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInsertText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setInsertText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setMaxLength(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setMaxLength'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setMaxLength(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMaxLength",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setMaxLength'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setTouchSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setTouchSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;
        ok &= luaval_to_size(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setTouchSize(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTouchSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setTouchSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_setDeleteBackward(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UITextField*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UITextField_setDeleteBackward'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setDeleteBackward(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setDeleteBackward",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_setDeleteBackward'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UITextField",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UITextField* ret = gui::UITextField::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UITextField*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UITextField");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UITextField");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UITextField_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UITextField* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UITextField();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UITextField");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UITextField");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UITextField",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UITextField_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UITextField_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UITextField)");
    return 0;
}

int lua_register_cocos2dx_studio_UITextField(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UITextField");
    tolua_cclass(tolua_S,"UITextField","UITextField","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UITextField");
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UITextField_setAnchorPoint);
        tolua_function(tolua_S,"setAttachWithIME",lua_cocos2dx_studio_UITextField_setAttachWithIME);
        tolua_function(tolua_S,"getStringValue",lua_cocos2dx_studio_UITextField_getStringValue);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UITextField_getDescription);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UITextField_getVirtualRenderer);
        tolua_function(tolua_S,"getDeleteBackward",lua_cocos2dx_studio_UITextField_getDeleteBackward);
        tolua_function(tolua_S,"getAttachWithIME",lua_cocos2dx_studio_UITextField_getAttachWithIME);
        tolua_function(tolua_S,"setFontName",lua_cocos2dx_studio_UITextField_setFontName);
        tolua_function(tolua_S,"getInsertText",lua_cocos2dx_studio_UITextField_getInsertText);
        tolua_function(tolua_S,"initRenderer",lua_cocos2dx_studio_UITextField_initRenderer);
        tolua_function(tolua_S,"getDetachWithIME",lua_cocos2dx_studio_UITextField_getDetachWithIME);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_studio_UITextField_setOpacity);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_UITextField_init);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UITextField_getContentSize);
        tolua_function(tolua_S,"didNotSelectSelf",lua_cocos2dx_studio_UITextField_didNotSelectSelf);
        tolua_function(tolua_S,"isPasswordEnabled",lua_cocos2dx_studio_UITextField_isPasswordEnabled);
        tolua_function(tolua_S,"attachWithIME",lua_cocos2dx_studio_UITextField_attachWithIME);
        tolua_function(tolua_S,"setPasswordEnabled",lua_cocos2dx_studio_UITextField_setPasswordEnabled);
        tolua_function(tolua_S,"update",lua_cocos2dx_studio_UITextField_update);
        tolua_function(tolua_S,"setMaxLengthEnabled",lua_cocos2dx_studio_UITextField_setMaxLengthEnabled);
        tolua_function(tolua_S,"setPasswordStyleText",lua_cocos2dx_studio_UITextField_setPasswordStyleText);
        tolua_function(tolua_S,"setFontSize",lua_cocos2dx_studio_UITextField_setFontSize);
        tolua_function(tolua_S,"setPlaceHolder",lua_cocos2dx_studio_UITextField_setPlaceHolder);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_studio_UITextField_setColor);
        tolua_function(tolua_S,"getMaxLength",lua_cocos2dx_studio_UITextField_getMaxLength);
        tolua_function(tolua_S,"isMaxLengthEnabled",lua_cocos2dx_studio_UITextField_isMaxLengthEnabled);
        tolua_function(tolua_S,"setDetachWithIME",lua_cocos2dx_studio_UITextField_setDetachWithIME);
        tolua_function(tolua_S,"setText",lua_cocos2dx_studio_UITextField_setText);
        tolua_function(tolua_S,"setInsertText",lua_cocos2dx_studio_UITextField_setInsertText);
        tolua_function(tolua_S,"setMaxLength",lua_cocos2dx_studio_UITextField_setMaxLength);
        tolua_function(tolua_S,"setTouchSize",lua_cocos2dx_studio_UITextField_setTouchSize);
        tolua_function(tolua_S,"setDeleteBackward",lua_cocos2dx_studio_UITextField_setDeleteBackward);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UITextField_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UITextField_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UITextField).hash_code();
    g_luaType[typeId] = "UITextField";
    return 1;
}

int lua_cocos2dx_studio_UILabelBMFont_setAnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelBMFont_setAnchorPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setAnchorPoint(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnchorPoint",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_setAnchorPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_getVirtualRenderer(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelBMFont_getVirtualRenderer'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getVirtualRenderer();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVirtualRenderer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_getVirtualRenderer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_getStringValue(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelBMFont_getStringValue'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getStringValue();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getStringValue",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_getStringValue'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_setText(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelBMFont_setText'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setText(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_setText'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelBMFont_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelBMFont_getContentSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContentSize",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_getContentSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_setFntFile(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILabelBMFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILabelBMFont_setFntFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setFntFile(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFntFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_setFntFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILabelBMFont",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILabelBMFont* ret = gui::UILabelBMFont::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILabelBMFont*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILabelBMFont");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILabelBMFont");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILabelBMFont_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILabelBMFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILabelBMFont();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILabelBMFont");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILabelBMFont");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILabelBMFont",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILabelBMFont_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILabelBMFont_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILabelBMFont)");
    return 0;
}

int lua_register_cocos2dx_studio_UILabelBMFont(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILabelBMFont");
    tolua_cclass(tolua_S,"UILabelBMFont","UILabelBMFont","UIWidget",NULL);

    tolua_beginmodule(tolua_S,"UILabelBMFont");
        tolua_function(tolua_S,"setAnchorPoint",lua_cocos2dx_studio_UILabelBMFont_setAnchorPoint);
        tolua_function(tolua_S,"getVirtualRenderer",lua_cocos2dx_studio_UILabelBMFont_getVirtualRenderer);
        tolua_function(tolua_S,"getStringValue",lua_cocos2dx_studio_UILabelBMFont_getStringValue);
        tolua_function(tolua_S,"setText",lua_cocos2dx_studio_UILabelBMFont_setText);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UILabelBMFont_getDescription);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_studio_UILabelBMFont_getContentSize);
        tolua_function(tolua_S,"setFntFile",lua_cocos2dx_studio_UILabelBMFont_setFntFile);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILabelBMFont_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILabelBMFont_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILabelBMFont).hash_code();
    g_luaType[typeId] = "UILabelBMFont";
    return 1;
}

int lua_cocos2dx_studio_UIPageView_getLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_getLayoutType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getLayoutType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getLayoutType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_getLayoutType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_getCurPageIndex(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_getCurPageIndex'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = cobj->getCurPageIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurPageIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_getCurPageIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_addWidgetToPage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_addWidgetToPage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        gui::UIWidget* arg0;
        int arg1;
        bool arg2;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->addWidgetToPage(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addWidgetToPage",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_addWidgetToPage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_getPage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_getPage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        gui::UILayout* ret = cobj->getPage(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILayout*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILayout");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILayout");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_getPage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_removePage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_removePage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UILayout* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UILayout",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UILayout*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->removePage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removePage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_removePage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_getDescription(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_getDescription'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getDescription();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDescription",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_getDescription'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_insertPage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_insertPage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        gui::UILayout* arg0;
        int arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UILayout",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UILayout*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->insertPage(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "insertPage",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_insertPage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_setLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_setLayoutType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::LayoutType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setLayoutType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLayoutType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_setLayoutType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_scrollToPage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_scrollToPage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->scrollToPage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "scrollToPage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_scrollToPage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_update(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_update'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_update'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_doLayout(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_doLayout'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->doLayout();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "doLayout",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_doLayout'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_removePageAtIndex(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_removePageAtIndex'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->removePageAtIndex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removePageAtIndex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_removePageAtIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_getPages(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_getPages'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Array* ret = cobj->getPages();
        array_to_luaval(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getPages",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_getPages'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_removeAllPages(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_removeAllPages'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->removeAllPages();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAllPages",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_removeAllPages'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_addPage(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UIPageView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UIPageView_addPage'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UILayout* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UILayout",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UILayout*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addPage(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addPage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_addPage'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIPageView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UIPageView* ret = gui::UIPageView::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIPageView*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIPageView");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIPageView");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIPageView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UIPageView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UIPageView();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIPageView");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UIPageView");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UIPageView",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIPageView_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UIPageView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIPageView)");
    return 0;
}

int lua_register_cocos2dx_studio_UIPageView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIPageView");
    tolua_cclass(tolua_S,"UIPageView","UIPageView","UILayout",NULL);

    tolua_beginmodule(tolua_S,"UIPageView");
        tolua_function(tolua_S,"getLayoutType",lua_cocos2dx_studio_UIPageView_getLayoutType);
        tolua_function(tolua_S,"getCurPageIndex",lua_cocos2dx_studio_UIPageView_getCurPageIndex);
        tolua_function(tolua_S,"addWidgetToPage",lua_cocos2dx_studio_UIPageView_addWidgetToPage);
        tolua_function(tolua_S,"getPage",lua_cocos2dx_studio_UIPageView_getPage);
        tolua_function(tolua_S,"removePage",lua_cocos2dx_studio_UIPageView_removePage);
        tolua_function(tolua_S,"getDescription",lua_cocos2dx_studio_UIPageView_getDescription);
        tolua_function(tolua_S,"insertPage",lua_cocos2dx_studio_UIPageView_insertPage);
        tolua_function(tolua_S,"setLayoutType",lua_cocos2dx_studio_UIPageView_setLayoutType);
        tolua_function(tolua_S,"scrollToPage",lua_cocos2dx_studio_UIPageView_scrollToPage);
        tolua_function(tolua_S,"update",lua_cocos2dx_studio_UIPageView_update);
        tolua_function(tolua_S,"doLayout",lua_cocos2dx_studio_UIPageView_doLayout);
        tolua_function(tolua_S,"removePageAtIndex",lua_cocos2dx_studio_UIPageView_removePageAtIndex);
        tolua_function(tolua_S,"getPages",lua_cocos2dx_studio_UIPageView_getPages);
        tolua_function(tolua_S,"removeAllPages",lua_cocos2dx_studio_UIPageView_removeAllPages);
        tolua_function(tolua_S,"addPage",lua_cocos2dx_studio_UIPageView_addPage);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UIPageView_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UIPageView_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIPageView).hash_code();
    g_luaType[typeId] = "UIPageView";
    return 1;
}

int lua_cocos2dx_studio_UIHelper_seekActionWidgetByActionTag(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        gui::UIWidget* arg0;
        int arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        gui::UIWidget* ret = gui::UIHelper::seekActionWidgetByActionTag(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "seekActionWidgetByActionTag",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIHelper_seekActionWidgetByActionTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIHelper_seekWidgetByTag(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        gui::UIWidget* arg0;
        int arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        gui::UIWidget* ret = gui::UIHelper::seekWidgetByTag(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "seekWidgetByTag",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIHelper_seekWidgetByTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIHelper_seekWidgetByRelativeName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        gui::UIWidget* arg0;
        const char* arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        gui::UIWidget* ret = gui::UIHelper::seekWidgetByRelativeName(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "seekWidgetByRelativeName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIHelper_seekWidgetByRelativeName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UIHelper_seekWidgetByName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIHelper",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        gui::UIWidget* arg0;
        const char* arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        gui::UIWidget* ret = gui::UIHelper::seekWidgetByName(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "seekWidgetByName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UIHelper_seekWidgetByName'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_studio_UIHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIHelper)");
    return 0;
}

int lua_register_cocos2dx_studio_UIHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIHelper");
    tolua_cclass(tolua_S,"UIHelper","UIHelper","",NULL);

    tolua_beginmodule(tolua_S,"UIHelper");
        tolua_function(tolua_S,"seekActionWidgetByActionTag", lua_cocos2dx_studio_UIHelper_seekActionWidgetByActionTag);
        tolua_function(tolua_S,"seekWidgetByTag", lua_cocos2dx_studio_UIHelper_seekWidgetByTag);
        tolua_function(tolua_S,"seekWidgetByRelativeName", lua_cocos2dx_studio_UIHelper_seekWidgetByRelativeName);
        tolua_function(tolua_S,"seekWidgetByName", lua_cocos2dx_studio_UIHelper_seekWidgetByName);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UIHelper).hash_code();
    g_luaType[typeId] = "UIHelper";
    return 1;
}

int lua_cocos2dx_studio_UILayer_getRootWidget(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_getRootWidget'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        gui::UIRootWidget* ret = cobj->getRootWidget();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIRootWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIRootWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIRootWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getRootWidget",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_getRootWidget'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_getWidgetByTag(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_getWidgetByTag'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->getWidgetByTag(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getWidgetByTag",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_getWidgetByTag'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_removeWidget(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_removeWidget'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->removeWidget(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeWidget",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_removeWidget'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_init(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_getWidgetByName(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_getWidgetByName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->getWidgetByName(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getWidgetByName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_getWidgetByName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_addWidget(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_addWidget'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        gui::UIWidget* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"UIWidget",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (gui::UIWidget*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addWidget(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addWidget",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_addWidget'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_setVisible'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setVisible(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVisible",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_setVisible'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_clear(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (gui::UILayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_UILayer_clear'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->clear();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "clear",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_clear'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UILayer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        gui::UILayer* ret = gui::UILayer::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UILayer*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UILayer");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UILayer");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_UILayer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    gui::UILayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new gui::UILayer();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UILayer");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"UILayer");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "UILayer",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_UILayer_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_UILayer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UILayer)");
    return 0;
}

int lua_register_cocos2dx_studio_UILayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UILayer");
    tolua_cclass(tolua_S,"UILayer","UILayer","Layer",NULL);

    tolua_beginmodule(tolua_S,"UILayer");
        tolua_function(tolua_S,"getRootWidget",lua_cocos2dx_studio_UILayer_getRootWidget);
        tolua_function(tolua_S,"getWidgetByTag",lua_cocos2dx_studio_UILayer_getWidgetByTag);
        tolua_function(tolua_S,"removeWidget",lua_cocos2dx_studio_UILayer_removeWidget);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_UILayer_init);
        tolua_function(tolua_S,"getWidgetByName",lua_cocos2dx_studio_UILayer_getWidgetByName);
        tolua_function(tolua_S,"addWidget",lua_cocos2dx_studio_UILayer_addWidget);
        tolua_function(tolua_S,"setVisible",lua_cocos2dx_studio_UILayer_setVisible);
        tolua_function(tolua_S,"clear",lua_cocos2dx_studio_UILayer_clear);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_UILayer_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_UILayer_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(gui::UILayer).hash_code();
    g_luaType[typeId] = "UILayer";
    return 1;
}

int lua_cocos2dx_studio_ActionManagerEx_playActionByName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ActionManagerEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ActionManagerEx",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ActionManagerEx*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ActionManagerEx_playActionByName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::ActionObject* ret = cobj->playActionByName(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ActionObject*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ActionObject");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ActionObject");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playActionByName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ActionManagerEx_playActionByName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ActionManagerEx_getActionByName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ActionManagerEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ActionManagerEx",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ActionManagerEx*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ActionManagerEx_getActionByName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::ActionObject* ret = cobj->getActionByName(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ActionObject*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ActionObject");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ActionObject");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getActionByName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ActionManagerEx_getActionByName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ActionManagerEx_initWithDictionary(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ActionManagerEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ActionManagerEx",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ActionManagerEx*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ActionManagerEx_initWithDictionary'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        cocostudio::JsonDictionary* arg1;
        cocos2d::Object* arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        do {
				if (!luaval_is_usertype(tolua_S,3,"JsonDictionary",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::JsonDictionary*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        do {
				if (!luaval_is_usertype(tolua_S,4,"Object",0)){
					ok = false;
					break;
				}
				if (ok){
					arg2 = (cocos2d::Object*)tolua_tousertype(tolua_S,4,0);
					if (nullptr == arg2){
						LUA_PRECONDITION( arg2, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->initWithDictionary(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithDictionary",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ActionManagerEx_initWithDictionary'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ActionManagerEx_releaseActions(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ActionManagerEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ActionManagerEx",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ActionManagerEx*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ActionManagerEx_releaseActions'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->releaseActions();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "releaseActions",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ActionManagerEx_releaseActions'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ActionManagerEx_purgeActionManager(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ActionManagerEx",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ActionManagerEx::purgeActionManager();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "purgeActionManager",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ActionManagerEx_purgeActionManager'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ActionManagerEx_shareManager(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ActionManagerEx",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ActionManagerEx* ret = cocostudio::ActionManagerEx::shareManager();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ActionManagerEx*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ActionManagerEx");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ActionManagerEx");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "shareManager",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ActionManagerEx_shareManager'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ActionManagerEx_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ActionManagerEx* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::ActionManagerEx();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ActionManagerEx");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"ActionManagerEx");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ActionManagerEx",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ActionManagerEx_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_ActionManagerEx_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ActionManagerEx)");
    return 0;
}

int lua_register_cocos2dx_studio_ActionManagerEx(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ActionManagerEx");
    tolua_cclass(tolua_S,"ActionManagerEx","ActionManagerEx","",NULL);

    tolua_beginmodule(tolua_S,"ActionManagerEx");
        tolua_function(tolua_S,"playActionByName",lua_cocos2dx_studio_ActionManagerEx_playActionByName);
        tolua_function(tolua_S,"getActionByName",lua_cocos2dx_studio_ActionManagerEx_getActionByName);
        tolua_function(tolua_S,"initWithDictionary",lua_cocos2dx_studio_ActionManagerEx_initWithDictionary);
        tolua_function(tolua_S,"releaseActions",lua_cocos2dx_studio_ActionManagerEx_releaseActions);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_ActionManagerEx_constructor);
        tolua_function(tolua_S,"destroyInstance", lua_cocos2dx_studio_ActionManagerEx_purgeActionManager);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_studio_ActionManagerEx_shareManager);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ActionManagerEx).hash_code();
    g_luaType[typeId] = "ActionManagerEx";
    return 1;
}

int lua_cocos2dx_studio_BaseData_getColor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BaseData_getColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Color4B ret = cobj->getColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getColor",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BaseData_getColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BaseData_copy(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BaseData_copy'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocostudio::BaseData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"BaseData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const cocostudio::BaseData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->copy(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copy",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BaseData_copy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BaseData_subtract(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BaseData_subtract'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocostudio::BaseData* arg0;
        cocostudio::BaseData* arg1;
        bool arg2;
        do {
				if (!luaval_is_usertype(tolua_S,2,"BaseData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::BaseData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        do {
				if (!luaval_is_usertype(tolua_S,3,"BaseData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::BaseData*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_boolean(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        cobj->subtract(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "subtract",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BaseData_subtract'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BaseData_setColor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BaseData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BaseData_setColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;
        ok &=luaval_to_color4b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BaseData_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BaseData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"BaseData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::BaseData* ret = cocostudio::BaseData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::BaseData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"BaseData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"BaseData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BaseData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BaseData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BaseData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::BaseData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"BaseData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"BaseData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "BaseData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BaseData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_BaseData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BaseData)");
    return 0;
}

int lua_register_cocos2dx_studio_BaseData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BaseData");
    tolua_cclass(tolua_S,"BaseData","BaseData","",NULL);

    tolua_beginmodule(tolua_S,"BaseData");
        tolua_function(tolua_S,"getColor",lua_cocos2dx_studio_BaseData_getColor);
        tolua_function(tolua_S,"copy",lua_cocos2dx_studio_BaseData_copy);
        tolua_function(tolua_S,"subtract",lua_cocos2dx_studio_BaseData_subtract);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_studio_BaseData_setColor);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_BaseData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_BaseData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::BaseData).hash_code();
    g_luaType[typeId] = "BaseData";
    return 1;
}

int lua_cocos2dx_studio_DisplayData_copy(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::DisplayData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DisplayData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::DisplayData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_DisplayData_copy'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::DisplayData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"DisplayData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::DisplayData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->copy(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copy",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_DisplayData_copy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_DisplayData_changeDisplayToTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DisplayData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        const char* ret = cocostudio::DisplayData::changeDisplayToTexture(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "changeDisplayToTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_DisplayData_changeDisplayToTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_DisplayData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DisplayData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::DisplayData* ret = cocostudio::DisplayData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::DisplayData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"DisplayData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"DisplayData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_DisplayData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_DisplayData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::DisplayData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::DisplayData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"DisplayData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"DisplayData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "DisplayData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_DisplayData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_DisplayData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DisplayData)");
    return 0;
}

int lua_register_cocos2dx_studio_DisplayData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DisplayData");
    tolua_cclass(tolua_S,"DisplayData","DisplayData","",NULL);

    tolua_beginmodule(tolua_S,"DisplayData");
        tolua_function(tolua_S,"copy",lua_cocos2dx_studio_DisplayData_copy);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_DisplayData_constructor);
        tolua_function(tolua_S,"changeDisplayToTexture", lua_cocos2dx_studio_DisplayData_changeDisplayToTexture);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_DisplayData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::DisplayData).hash_code();
    g_luaType[typeId] = "DisplayData";
    return 1;
}

int lua_cocos2dx_studio_SpriteDisplayData_copy(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::SpriteDisplayData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteDisplayData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::SpriteDisplayData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_SpriteDisplayData_copy'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::DisplayData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"DisplayData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::DisplayData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->copy(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copy",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SpriteDisplayData_copy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_SpriteDisplayData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteDisplayData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::SpriteDisplayData* ret = cocostudio::SpriteDisplayData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::SpriteDisplayData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"SpriteDisplayData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"SpriteDisplayData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SpriteDisplayData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_SpriteDisplayData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::SpriteDisplayData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::SpriteDisplayData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SpriteDisplayData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"SpriteDisplayData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "SpriteDisplayData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SpriteDisplayData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_SpriteDisplayData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteDisplayData)");
    return 0;
}

int lua_register_cocos2dx_studio_SpriteDisplayData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteDisplayData");
    tolua_cclass(tolua_S,"SpriteDisplayData","SpriteDisplayData","DisplayData",NULL);

    tolua_beginmodule(tolua_S,"SpriteDisplayData");
        tolua_function(tolua_S,"copy",lua_cocos2dx_studio_SpriteDisplayData_copy);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_SpriteDisplayData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_SpriteDisplayData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::SpriteDisplayData).hash_code();
    g_luaType[typeId] = "SpriteDisplayData";
    return 1;
}

int lua_cocos2dx_studio_ArmatureDisplayData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ArmatureDisplayData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ArmatureDisplayData* ret = cocostudio::ArmatureDisplayData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ArmatureDisplayData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ArmatureDisplayData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ArmatureDisplayData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDisplayData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDisplayData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDisplayData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::ArmatureDisplayData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ArmatureDisplayData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"ArmatureDisplayData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ArmatureDisplayData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDisplayData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_ArmatureDisplayData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ArmatureDisplayData)");
    return 0;
}

int lua_register_cocos2dx_studio_ArmatureDisplayData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ArmatureDisplayData");
    tolua_cclass(tolua_S,"ArmatureDisplayData","ArmatureDisplayData","DisplayData",NULL);

    tolua_beginmodule(tolua_S,"ArmatureDisplayData");
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ArmatureDisplayData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ArmatureDisplayData).hash_code();
    g_luaType[typeId] = "ArmatureDisplayData";
    return 1;
}

int lua_cocos2dx_studio_ParticleDisplayData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ParticleDisplayData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ParticleDisplayData* ret = cocostudio::ParticleDisplayData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ParticleDisplayData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ParticleDisplayData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ParticleDisplayData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ParticleDisplayData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ParticleDisplayData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ParticleDisplayData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::ParticleDisplayData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ParticleDisplayData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"ParticleDisplayData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ParticleDisplayData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ParticleDisplayData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_ParticleDisplayData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ParticleDisplayData)");
    return 0;
}

int lua_register_cocos2dx_studio_ParticleDisplayData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ParticleDisplayData");
    tolua_cclass(tolua_S,"ParticleDisplayData","ParticleDisplayData","DisplayData",NULL);

    tolua_beginmodule(tolua_S,"ParticleDisplayData");
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ParticleDisplayData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ParticleDisplayData).hash_code();
    g_luaType[typeId] = "ParticleDisplayData";
    return 1;
}

int lua_cocos2dx_studio_BoneData_getDisplayData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BoneData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BoneData_getDisplayData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cocostudio::DisplayData* ret = cobj->getDisplayData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::DisplayData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"DisplayData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"DisplayData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BoneData_getDisplayData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BoneData_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BoneData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BoneData_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BoneData_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BoneData_addDisplayData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BoneData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BoneData_addDisplayData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::DisplayData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"DisplayData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::DisplayData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addDisplayData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addDisplayData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BoneData_addDisplayData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BoneData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"BoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::BoneData* ret = cocostudio::BoneData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::BoneData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"BoneData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"BoneData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BoneData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BoneData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::BoneData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"BoneData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"BoneData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "BoneData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BoneData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_BoneData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BoneData)");
    return 0;
}

int lua_register_cocos2dx_studio_BoneData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BoneData");
    tolua_cclass(tolua_S,"BoneData","BoneData","BaseData",NULL);

    tolua_beginmodule(tolua_S,"BoneData");
        tolua_function(tolua_S,"getDisplayData",lua_cocos2dx_studio_BoneData_getDisplayData);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_BoneData_init);
        tolua_function(tolua_S,"addDisplayData",lua_cocos2dx_studio_BoneData_addDisplayData);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_BoneData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_BoneData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::BoneData).hash_code();
    g_luaType[typeId] = "BoneData";
    return 1;
}

int lua_cocos2dx_studio_ArmatureData_addBoneData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureData_addBoneData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::BoneData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"BoneData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::BoneData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addBoneData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addBoneData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureData_addBoneData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureData_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureData_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureData_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureData_getBoneData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureData_getBoneData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::BoneData* ret = cobj->getBoneData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::BoneData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"BoneData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"BoneData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBoneData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureData_getBoneData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ArmatureData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ArmatureData* ret = cocostudio::ArmatureData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ArmatureData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ArmatureData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ArmatureData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::ArmatureData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ArmatureData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"ArmatureData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ArmatureData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_ArmatureData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ArmatureData)");
    return 0;
}

int lua_register_cocos2dx_studio_ArmatureData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ArmatureData");
    tolua_cclass(tolua_S,"ArmatureData","ArmatureData","",NULL);

    tolua_beginmodule(tolua_S,"ArmatureData");
        tolua_function(tolua_S,"addBoneData",lua_cocos2dx_studio_ArmatureData_addBoneData);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_ArmatureData_init);
        tolua_function(tolua_S,"getBoneData",lua_cocos2dx_studio_ArmatureData_getBoneData);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_ArmatureData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ArmatureData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ArmatureData).hash_code();
    g_luaType[typeId] = "ArmatureData";
    return 1;
}

int lua_cocos2dx_studio_FrameData_copy(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::FrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"FrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::FrameData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_FrameData_copy'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocostudio::BaseData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"BaseData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const cocostudio::BaseData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->copy(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "copy",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_FrameData_copy'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_FrameData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"FrameData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::FrameData* ret = cocostudio::FrameData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::FrameData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"FrameData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"FrameData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_FrameData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_FrameData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::FrameData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::FrameData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"FrameData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"FrameData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "FrameData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_FrameData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_FrameData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (FrameData)");
    return 0;
}

int lua_register_cocos2dx_studio_FrameData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"FrameData");
    tolua_cclass(tolua_S,"FrameData","FrameData","BaseData",NULL);

    tolua_beginmodule(tolua_S,"FrameData");
        tolua_function(tolua_S,"copy",lua_cocos2dx_studio_FrameData_copy);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_FrameData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_FrameData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::FrameData).hash_code();
    g_luaType[typeId] = "FrameData";
    return 1;
}

int lua_cocos2dx_studio_MovementBoneData_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::MovementBoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MovementBoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::MovementBoneData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_MovementBoneData_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementBoneData_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_MovementBoneData_getFrameData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::MovementBoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MovementBoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::MovementBoneData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_MovementBoneData_getFrameData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cocostudio::FrameData* ret = cobj->getFrameData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::FrameData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"FrameData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"FrameData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFrameData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementBoneData_getFrameData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_MovementBoneData_addFrameData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::MovementBoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MovementBoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::MovementBoneData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_MovementBoneData_addFrameData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::FrameData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"FrameData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::FrameData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addFrameData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addFrameData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementBoneData_addFrameData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_MovementBoneData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MovementBoneData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::MovementBoneData* ret = cocostudio::MovementBoneData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::MovementBoneData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"MovementBoneData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"MovementBoneData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementBoneData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_MovementBoneData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::MovementBoneData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::MovementBoneData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MovementBoneData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"MovementBoneData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "MovementBoneData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementBoneData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_MovementBoneData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MovementBoneData)");
    return 0;
}

int lua_register_cocos2dx_studio_MovementBoneData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MovementBoneData");
    tolua_cclass(tolua_S,"MovementBoneData","MovementBoneData","",NULL);

    tolua_beginmodule(tolua_S,"MovementBoneData");
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_MovementBoneData_init);
        tolua_function(tolua_S,"getFrameData",lua_cocos2dx_studio_MovementBoneData_getFrameData);
        tolua_function(tolua_S,"addFrameData",lua_cocos2dx_studio_MovementBoneData_addFrameData);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_MovementBoneData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_MovementBoneData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::MovementBoneData).hash_code();
    g_luaType[typeId] = "MovementBoneData";
    return 1;
}

int lua_cocos2dx_studio_MovementData_getMovementBoneData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::MovementData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MovementData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::MovementData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_MovementData_getMovementBoneData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::MovementBoneData* ret = cobj->getMovementBoneData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::MovementBoneData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"MovementBoneData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"MovementBoneData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMovementBoneData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementData_getMovementBoneData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_MovementData_addMovementBoneData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::MovementData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MovementData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::MovementData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_MovementData_addMovementBoneData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::MovementBoneData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"MovementBoneData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::MovementBoneData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addMovementBoneData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addMovementBoneData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementData_addMovementBoneData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_MovementData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MovementData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::MovementData* ret = cocostudio::MovementData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::MovementData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"MovementData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"MovementData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_MovementData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::MovementData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::MovementData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MovementData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"MovementData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "MovementData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_MovementData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_MovementData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MovementData)");
    return 0;
}

int lua_register_cocos2dx_studio_MovementData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MovementData");
    tolua_cclass(tolua_S,"MovementData","MovementData","",NULL);

    tolua_beginmodule(tolua_S,"MovementData");
        tolua_function(tolua_S,"getMovementBoneData",lua_cocos2dx_studio_MovementData_getMovementBoneData);
        tolua_function(tolua_S,"addMovementBoneData",lua_cocos2dx_studio_MovementData_addMovementBoneData);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_MovementData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_MovementData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::MovementData).hash_code();
    g_luaType[typeId] = "MovementData";
    return 1;
}

int lua_cocos2dx_studio_AnimationData_getMovement(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_AnimationData_getMovement'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::MovementData* ret = cobj->getMovement(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::MovementData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"MovementData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"MovementData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMovement",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_AnimationData_getMovement'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_AnimationData_getMovementCount(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_AnimationData_getMovementCount'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        ssize_t ret = cobj->getMovementCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMovementCount",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_AnimationData_getMovementCount'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_AnimationData_addMovement(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_AnimationData_addMovement'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::MovementData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"MovementData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::MovementData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addMovement(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addMovement",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_AnimationData_addMovement'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_AnimationData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::AnimationData* ret = cocostudio::AnimationData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::AnimationData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"AnimationData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"AnimationData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_AnimationData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_AnimationData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::AnimationData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"AnimationData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"AnimationData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "AnimationData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_AnimationData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_AnimationData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimationData)");
    return 0;
}

int lua_register_cocos2dx_studio_AnimationData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"AnimationData");
    tolua_cclass(tolua_S,"AnimationData","AnimationData","",NULL);

    tolua_beginmodule(tolua_S,"AnimationData");
        tolua_function(tolua_S,"getMovement",lua_cocos2dx_studio_AnimationData_getMovement);
        tolua_function(tolua_S,"getMovementCount",lua_cocos2dx_studio_AnimationData_getMovementCount);
        tolua_function(tolua_S,"addMovement",lua_cocos2dx_studio_AnimationData_addMovement);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_AnimationData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_AnimationData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::AnimationData).hash_code();
    g_luaType[typeId] = "AnimationData";
    return 1;
}

int lua_cocos2dx_studio_ContourData_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ContourData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ContourData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ContourData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ContourData_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ContourData_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ContourData_addVertex(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ContourData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ContourData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ContourData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ContourData_addVertex'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;
        ok &= luaval_to_point(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->addVertex(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addVertex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ContourData_addVertex'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ContourData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ContourData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ContourData* ret = cocostudio::ContourData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ContourData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ContourData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ContourData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ContourData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ContourData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ContourData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::ContourData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ContourData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"ContourData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ContourData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ContourData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_ContourData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ContourData)");
    return 0;
}

int lua_register_cocos2dx_studio_ContourData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ContourData");
    tolua_cclass(tolua_S,"ContourData","ContourData","",NULL);

    tolua_beginmodule(tolua_S,"ContourData");
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_ContourData_init);
        tolua_function(tolua_S,"addVertex",lua_cocos2dx_studio_ContourData_addVertex);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_ContourData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ContourData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ContourData).hash_code();
    g_luaType[typeId] = "ContourData";
    return 1;
}

int lua_cocos2dx_studio_TextureData_getContourData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::TextureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TextureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::TextureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_TextureData_getContourData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cocostudio::ContourData* ret = cobj->getContourData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ContourData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ContourData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ContourData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getContourData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_TextureData_getContourData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_TextureData_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::TextureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TextureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::TextureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_TextureData_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_TextureData_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_TextureData_addContourData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::TextureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TextureData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::TextureData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_TextureData_addContourData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::ContourData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"ContourData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::ContourData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addContourData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addContourData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_TextureData_addContourData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_TextureData_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TextureData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::TextureData* ret = cocostudio::TextureData::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::TextureData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"TextureData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"TextureData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_TextureData_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_TextureData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::TextureData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::TextureData();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"TextureData");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"TextureData");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "TextureData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_TextureData_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_TextureData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TextureData)");
    return 0;
}

int lua_register_cocos2dx_studio_TextureData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TextureData");
    tolua_cclass(tolua_S,"TextureData","TextureData","",NULL);

    tolua_beginmodule(tolua_S,"TextureData");
        tolua_function(tolua_S,"getContourData",lua_cocos2dx_studio_TextureData_getContourData);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_TextureData_init);
        tolua_function(tolua_S,"addContourData",lua_cocos2dx_studio_TextureData_addContourData);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_TextureData_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_TextureData_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::TextureData).hash_code();
    g_luaType[typeId] = "TextureData";
    return 1;
}

int lua_cocos2dx_studio_Bone_getTweenData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getTweenData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::FrameData* ret = cobj->getTweenData();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::FrameData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"FrameData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"FrameData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTweenData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getTweenData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_isTransformDirty(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_isTransformDirty'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isTransformDirty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isTransformDirty",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_isTransformDirty'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_isIgnoreMovementBoneData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_isIgnoreMovementBoneData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isIgnoreMovementBoneData();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isIgnoreMovementBoneData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_isIgnoreMovementBoneData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_updateZOrder(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_updateZOrder'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->updateZOrder();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateZOrder",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_updateZOrder'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setTransformDirty(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setTransformDirty'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setTransformDirty(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setTransformDirty",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setTransformDirty'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getDisplayRenderNode(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getDisplayRenderNode'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getDisplayRenderNode();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayRenderNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getDisplayRenderNode'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_isBlendDirty(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_isBlendDirty'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isBlendDirty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isBlendDirty",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_isBlendDirty'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_addChildBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_addChildBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::Bone* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addChildBone(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addChildBone",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_addChildBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getWorldInfo(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getWorldInfo'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::BaseData* ret = cobj->getWorldInfo();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::BaseData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"BaseData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"BaseData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getWorldInfo",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getWorldInfo'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getTween(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getTween'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::Tween* ret = cobj->getTween();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Tween*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Tween");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Tween");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTween",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getTween'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getParentBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getParentBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::Bone* ret = cobj->getParentBone();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Bone*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Bone");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Bone");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getParentBone",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getParentBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_updateColor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_updateColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->updateColor();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateColor",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_updateColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string ret = cobj->getName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;
        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setOpacity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getDisplayRenderNodeType(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getDisplayRenderNodeType'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        int ret = (int)cobj->getDisplayRenderNodeType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayRenderNodeType",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getDisplayRenderNodeType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_removeDisplay(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_removeDisplay'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->removeDisplay(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeDisplay",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_removeDisplay'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_updateDisplayedOpacity(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_updateDisplayedOpacity'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;
        ok &= luaval_to_uint16(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->updateDisplayedOpacity(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateDisplayedOpacity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_updateDisplayedOpacity'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_init'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->init();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_changeDisplayByName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_changeDisplayByName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->changeDisplayByName(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "changeDisplayByName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_changeDisplayByName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setZOrder(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setZOrder'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->setZOrder(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setZOrder",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setZOrder'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_removeFromParent(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_removeFromParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->removeFromParent(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeFromParent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_removeFromParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getColliderDetector(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getColliderDetector'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::ColliderDetector* ret = cobj->getColliderDetector();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ColliderDetector*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ColliderDetector");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ColliderDetector");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getColliderDetector",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getColliderDetector'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setParentBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setParentBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::Bone* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setParentBone(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setParentBone",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setParentBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_update(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_update'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_update'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getChildArmature(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getChildArmature'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::Armature* ret = cobj->getChildArmature();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Armature*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Armature");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Armature");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getChildArmature",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getChildArmature'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setBoneData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setBoneData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::BoneData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"BoneData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::BoneData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setBoneData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBoneData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setBoneData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setArmature(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setArmature'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::Armature* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Armature",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Armature*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setArmature(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setArmature",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setArmature'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setBlendDirty(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setBlendDirty'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBlendDirty(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBlendDirty",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setBlendDirty'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_addDisplay(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_addDisplay'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            cobj->addDisplay(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocostudio::DisplayData* arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"DisplayData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::DisplayData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            cobj->addDisplay(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addDisplay",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_addDisplay'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getNodeToWorldTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getNodeToWorldTransform'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        kmMat4 ret = cobj->getNodeToWorldTransform();
        #pragma warning NO CONVERSION FROM NATIVE FOR kmMat4;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeToWorldTransform",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getNodeToWorldTransform'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setColor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->setColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_removeChildBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_removeChildBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocostudio::Bone* arg0;
        bool arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->removeChildBone(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeChildBone",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_removeChildBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_setChildArmature(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_setChildArmature'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::Armature* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Armature",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Armature*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setChildArmature(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setChildArmature",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_setChildArmature'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getNodeToArmatureTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getNodeToArmatureTransform'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        kmMat4 ret = cobj->getNodeToArmatureTransform();
        #pragma warning NO CONVERSION FROM NATIVE FOR kmMat4;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeToArmatureTransform",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getNodeToArmatureTransform'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getDisplayManager(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getDisplayManager'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::DisplayManager* ret = cobj->getDisplayManager();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::DisplayManager*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"DisplayManager");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"DisplayManager");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayManager",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getDisplayManager'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getArmature(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getArmature'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::Armature* ret = cobj->getArmature();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Armature*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Armature");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Armature");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getArmature",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getArmature'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_changeDisplayByIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_changeDisplayByIndex'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        bool arg1;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->changeDisplayByIndex(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "changeDisplayByIndex",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_changeDisplayByIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_updateDisplayedColor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_updateDisplayedColor'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;
        ok &= luaval_to_color3b(tolua_S, 2, &arg0);
        if(!ok)
            return 0;
        cobj->updateDisplayedColor(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateDisplayedColor",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_updateDisplayedColor'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_getBoneData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Bone_getBoneData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::BoneData* ret = cobj->getBoneData();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::BoneData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"BoneData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"BoneData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBoneData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_getBoneData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocostudio::Bone* ret = cocostudio::Bone::create(arg0);
            do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Bone*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Bone");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Bone");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocostudio::Bone* ret = cocostudio::Bone::create();
            do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Bone*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Bone");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Bone");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Bone_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::Bone();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"Bone");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"Bone");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Bone",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Bone_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_Bone_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Bone)");
    return 0;
}

int lua_register_cocos2dx_studio_Bone(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Bone");
    tolua_cclass(tolua_S,"Bone","Bone","NodeRGBA",NULL);

    tolua_beginmodule(tolua_S,"Bone");
        tolua_function(tolua_S,"getTweenData",lua_cocos2dx_studio_Bone_getTweenData);
        tolua_function(tolua_S,"isTransformDirty",lua_cocos2dx_studio_Bone_isTransformDirty);
        tolua_function(tolua_S,"isIgnoreMovementBoneData",lua_cocos2dx_studio_Bone_isIgnoreMovementBoneData);
        tolua_function(tolua_S,"updateZOrder",lua_cocos2dx_studio_Bone_updateZOrder);
        tolua_function(tolua_S,"setTransformDirty",lua_cocos2dx_studio_Bone_setTransformDirty);
        tolua_function(tolua_S,"getDisplayRenderNode",lua_cocos2dx_studio_Bone_getDisplayRenderNode);
        tolua_function(tolua_S,"isBlendDirty",lua_cocos2dx_studio_Bone_isBlendDirty);
        tolua_function(tolua_S,"addChildBone",lua_cocos2dx_studio_Bone_addChildBone);
        tolua_function(tolua_S,"getWorldInfo",lua_cocos2dx_studio_Bone_getWorldInfo);
        tolua_function(tolua_S,"getTween",lua_cocos2dx_studio_Bone_getTween);
        tolua_function(tolua_S,"getParentBone",lua_cocos2dx_studio_Bone_getParentBone);
        tolua_function(tolua_S,"updateColor",lua_cocos2dx_studio_Bone_updateColor);
        tolua_function(tolua_S,"getName",lua_cocos2dx_studio_Bone_getName);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_studio_Bone_setOpacity);
        tolua_function(tolua_S,"getDisplayRenderNodeType",lua_cocos2dx_studio_Bone_getDisplayRenderNodeType);
        tolua_function(tolua_S,"removeDisplay",lua_cocos2dx_studio_Bone_removeDisplay);
        tolua_function(tolua_S,"updateDisplayedOpacity",lua_cocos2dx_studio_Bone_updateDisplayedOpacity);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_Bone_init);
        tolua_function(tolua_S,"changeDisplayByName",lua_cocos2dx_studio_Bone_changeDisplayByName);
        tolua_function(tolua_S,"setZOrder",lua_cocos2dx_studio_Bone_setZOrder);
        tolua_function(tolua_S,"setName",lua_cocos2dx_studio_Bone_setName);
        tolua_function(tolua_S,"removeFromParent",lua_cocos2dx_studio_Bone_removeFromParent);
        tolua_function(tolua_S,"getColliderDetector",lua_cocos2dx_studio_Bone_getColliderDetector);
        tolua_function(tolua_S,"setParentBone",lua_cocos2dx_studio_Bone_setParentBone);
        tolua_function(tolua_S,"update",lua_cocos2dx_studio_Bone_update);
        tolua_function(tolua_S,"getChildArmature",lua_cocos2dx_studio_Bone_getChildArmature);
        tolua_function(tolua_S,"setBoneData",lua_cocos2dx_studio_Bone_setBoneData);
        tolua_function(tolua_S,"setArmature",lua_cocos2dx_studio_Bone_setArmature);
        tolua_function(tolua_S,"setBlendDirty",lua_cocos2dx_studio_Bone_setBlendDirty);
        tolua_function(tolua_S,"addDisplay",lua_cocos2dx_studio_Bone_addDisplay);
        tolua_function(tolua_S,"getNodeToWorldTransform",lua_cocos2dx_studio_Bone_getNodeToWorldTransform);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_studio_Bone_setColor);
        tolua_function(tolua_S,"removeChildBone",lua_cocos2dx_studio_Bone_removeChildBone);
        tolua_function(tolua_S,"setChildArmature",lua_cocos2dx_studio_Bone_setChildArmature);
        tolua_function(tolua_S,"getNodeToArmatureTransform",lua_cocos2dx_studio_Bone_getNodeToArmatureTransform);
        tolua_function(tolua_S,"getDisplayManager",lua_cocos2dx_studio_Bone_getDisplayManager);
        tolua_function(tolua_S,"getArmature",lua_cocos2dx_studio_Bone_getArmature);
        tolua_function(tolua_S,"changeDisplayByIndex",lua_cocos2dx_studio_Bone_changeDisplayByIndex);
        tolua_function(tolua_S,"updateDisplayedColor",lua_cocos2dx_studio_Bone_updateDisplayedColor);
        tolua_function(tolua_S,"getBoneData",lua_cocos2dx_studio_Bone_getBoneData);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_Bone_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_Bone_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::Bone).hash_code();
    g_luaType[typeId] = "Bone";
    return 1;
}

int lua_cocos2dx_studio_BatchNode_addChild(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BatchNode* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BatchNode",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::BatchNode*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BatchNode_addChild'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            cobj->addChild(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Node* arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            cobj->addChild(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::Node* arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

            if (!ok) { break; }
            cobj->addChild(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addChild",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BatchNode_addChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BatchNode_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BatchNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BatchNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BatchNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BatchNode_draw'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->draw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BatchNode_draw'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BatchNode_setPopGroupCommand(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BatchNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BatchNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BatchNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BatchNode_setPopGroupCommand'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setPopGroupCommand(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setPopGroupCommand",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BatchNode_setPopGroupCommand'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BatchNode_removeChild(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BatchNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BatchNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BatchNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BatchNode_removeChild'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        bool arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->removeChild(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeChild",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BatchNode_removeChild'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BatchNode_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BatchNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BatchNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::BatchNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_BatchNode_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BatchNode_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BatchNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"BatchNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::BatchNode* ret = cocostudio::BatchNode::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::BatchNode*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"BatchNode");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"BatchNode");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BatchNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_BatchNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::BatchNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::BatchNode();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"BatchNode");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"BatchNode");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "BatchNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_BatchNode_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_BatchNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BatchNode)");
    return 0;
}

int lua_register_cocos2dx_studio_BatchNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BatchNode");
    tolua_cclass(tolua_S,"BatchNode","BatchNode","Node",NULL);

    tolua_beginmodule(tolua_S,"BatchNode");
        tolua_function(tolua_S,"addChild",lua_cocos2dx_studio_BatchNode_addChild);
        tolua_function(tolua_S,"draw",lua_cocos2dx_studio_BatchNode_draw);
        tolua_function(tolua_S,"setPopGroupCommand",lua_cocos2dx_studio_BatchNode_setPopGroupCommand);
        tolua_function(tolua_S,"removeChild",lua_cocos2dx_studio_BatchNode_removeChild);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_BatchNode_init);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_BatchNode_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_BatchNode_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::BatchNode).hash_code();
    g_luaType[typeId] = "BatchNode";
    return 1;
}

int lua_cocos2dx_studio_ArmatureAnimation_getSpeedScale(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_getSpeedScale'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getSpeedScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getSpeedScale",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_getSpeedScale'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_play(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_play'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"vector<std::basic_string<char>, std::allocator<std::basic_string<char> > >",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > >&)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            cobj->play(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"vector<std::basic_string<char>, std::allocator<std::basic_string<char> > >",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > >&)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            cobj->play(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"vector<std::basic_string<char>, std::allocator<std::basic_string<char> > >",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > >&)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cobj->play(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->play(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            cobj->play(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

            if (!ok) { break; }
            cobj->play(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "play",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_play'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_pause(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_pause'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pause();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pause",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_pause'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_gotoAndPause(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_gotoAndPause'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->gotoAndPause(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoAndPause",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_gotoAndPause'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_resume(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_resume'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resume();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resume",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_resume'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_stop(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_stop'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stop();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stop",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_stop'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_setAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_setAnimationData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::AnimationData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"AnimationData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::AnimationData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setAnimationData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnimationData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_setAnimationData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_setMovementEventCallFunc(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_setMovementEventCallFunc'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (cocostudio::Armature *, cocostudio::MovementEventType, const char *)> arg0;
        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->setMovementEventCallFunc(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setMovementEventCallFunc",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_setMovementEventCallFunc'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_setSpeedScale(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_setSpeedScale'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setSpeedScale(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setSpeedScale",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_setSpeedScale'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_update(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_update'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_update'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_getAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_getAnimationData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::AnimationData* ret = cobj->getAnimationData();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::AnimationData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"AnimationData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"AnimationData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimationData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_getAnimationData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_playByIndex(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_playByIndex'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            std::vector<int, std::allocator<int> > arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"vector<int, std::allocator<int> >",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const std::vector<int, std::allocator<int> >&)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            cobj->playByIndex(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::vector<int, std::allocator<int> > arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"vector<int, std::allocator<int> >",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const std::vector<int, std::allocator<int> >&)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            cobj->playByIndex(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            std::vector<int, std::allocator<int> > arg0;
            do {
				if (!luaval_is_usertype(tolua_S,2,"vector<int, std::allocator<int> >",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (const std::vector<int, std::allocator<int> >&)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2);

            if (!ok) { break; }
            cobj->playByIndex(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

            if (!ok) { break; }
            cobj->playByIndex(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            cobj->playByIndex(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2);

            if (!ok) { break; }
            cobj->playByIndex(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playByIndex",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_playByIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_gotoAndPlay(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_gotoAndPlay'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        cobj->gotoAndPlay(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "gotoAndPlay",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_gotoAndPlay'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::Armature* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Armature",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Armature*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        bool ret = cobj->init(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_getMovementCount(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_getMovementCount'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        long ret = cobj->getMovementCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getMovementCount",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_getMovementCount'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_setFrameEventCallFunc(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_setFrameEventCallFunc'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (cocostudio::Bone *, const char *, int, int)> arg0;
        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
            return 0;
        cobj->setFrameEventCallFunc(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFrameEventCallFunc",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_setFrameEventCallFunc'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        std::string ret = cobj->getCurrentMovementID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCurrentMovementID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ArmatureAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocostudio::Armature* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Armature",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Armature*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cocostudio::ArmatureAnimation* ret = cocostudio::ArmatureAnimation::create(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ArmatureAnimation*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ArmatureAnimation");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ArmatureAnimation");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureAnimation_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::ArmatureAnimation();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ArmatureAnimation");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"ArmatureAnimation");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ArmatureAnimation",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureAnimation_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_ArmatureAnimation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ArmatureAnimation)");
    return 0;
}

int lua_register_cocos2dx_studio_ArmatureAnimation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ArmatureAnimation");
    tolua_cclass(tolua_S,"ArmatureAnimation","ArmatureAnimation","",NULL);

    tolua_beginmodule(tolua_S,"ArmatureAnimation");
        tolua_function(tolua_S,"getSpeedScale",lua_cocos2dx_studio_ArmatureAnimation_getSpeedScale);
        tolua_function(tolua_S,"play",lua_cocos2dx_studio_ArmatureAnimation_play);
        tolua_function(tolua_S,"pause",lua_cocos2dx_studio_ArmatureAnimation_pause);
        tolua_function(tolua_S,"gotoAndPause",lua_cocos2dx_studio_ArmatureAnimation_gotoAndPause);
        tolua_function(tolua_S,"resume",lua_cocos2dx_studio_ArmatureAnimation_resume);
        tolua_function(tolua_S,"stop",lua_cocos2dx_studio_ArmatureAnimation_stop);
        tolua_function(tolua_S,"setAnimationData",lua_cocos2dx_studio_ArmatureAnimation_setAnimationData);
        tolua_function(tolua_S,"setMovementEventCallFunc",lua_cocos2dx_studio_ArmatureAnimation_setMovementEventCallFunc);
        tolua_function(tolua_S,"setSpeedScale",lua_cocos2dx_studio_ArmatureAnimation_setSpeedScale);
        tolua_function(tolua_S,"update",lua_cocos2dx_studio_ArmatureAnimation_update);
        tolua_function(tolua_S,"getAnimationData",lua_cocos2dx_studio_ArmatureAnimation_getAnimationData);
        tolua_function(tolua_S,"playByIndex",lua_cocos2dx_studio_ArmatureAnimation_playByIndex);
        tolua_function(tolua_S,"gotoAndPlay",lua_cocos2dx_studio_ArmatureAnimation_gotoAndPlay);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_ArmatureAnimation_init);
        tolua_function(tolua_S,"getMovementCount",lua_cocos2dx_studio_ArmatureAnimation_getMovementCount);
        tolua_function(tolua_S,"setFrameEventCallFunc",lua_cocos2dx_studio_ArmatureAnimation_setFrameEventCallFunc);
        tolua_function(tolua_S,"getCurrentMovementID",lua_cocos2dx_studio_ArmatureAnimation_getCurrentMovementID);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_ArmatureAnimation_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ArmatureAnimation_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ArmatureAnimation).hash_code();
    g_luaType[typeId] = "ArmatureAnimation";
    return 1;
}

int lua_cocos2dx_studio_ArmatureDataManager_getAnimationDatas(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_getAnimationDatas'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Map<std::basic_string<char>, cocostudio::AnimationData *>& ret = cobj->getAnimationDatas();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Map<std::basic_string<char>, cocostudio::AnimationData *>&)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Map<std::basic_string<char>, cocostudio::AnimationData >");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Map<std::basic_string<char>, cocostudio::AnimationData >");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimationDatas",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_getAnimationDatas'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_removeAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_removeAnimationData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->removeAnimationData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeAnimationData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_removeAnimationData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_addArmatureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_addArmatureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocostudio::ArmatureData* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        do {
				if (!luaval_is_usertype(tolua_S,3,"ArmatureData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::ArmatureData*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addArmatureData(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        const char* arg0;
        cocostudio::ArmatureData* arg1;
        const char* arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        do {
				if (!luaval_is_usertype(tolua_S,3,"ArmatureData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::ArmatureData*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cobj->addArmatureData(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addArmatureData",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_addArmatureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();

            if (!ok) { break; }
            cobj->addArmatureFileInfo(arg0, arg1, arg2);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->addArmatureFileInfo(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addArmatureFileInfo",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->removeArmatureFileInfo(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeArmatureFileInfo",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_getTextureDatas(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_getTextureDatas'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Map<std::basic_string<char>, cocostudio::TextureData *>& ret = cobj->getTextureDatas();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Map<std::basic_string<char>, cocostudio::TextureData *>&)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Map<std::basic_string<char>, cocostudio::TextureData >");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Map<std::basic_string<char>, cocostudio::TextureData >");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTextureDatas",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_getTextureDatas'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_getTextureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_getTextureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::TextureData* ret = cobj->getTextureData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::TextureData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"TextureData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"TextureData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getTextureData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_getTextureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_getArmatureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_getArmatureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::ArmatureData* ret = cobj->getArmatureData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ArmatureData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ArmatureData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ArmatureData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getArmatureData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_getArmatureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_getAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_getAnimationData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::AnimationData* ret = cobj->getAnimationData(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::AnimationData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"AnimationData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"AnimationData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimationData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_getAnimationData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_addAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_addAnimationData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocostudio::AnimationData* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        do {
				if (!luaval_is_usertype(tolua_S,3,"AnimationData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::AnimationData*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addAnimationData(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        const char* arg0;
        cocostudio::AnimationData* arg1;
        const char* arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        do {
				if (!luaval_is_usertype(tolua_S,3,"AnimationData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::AnimationData*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cobj->addAnimationData(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addAnimationData",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_addAnimationData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_removeArmatureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_removeArmatureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->removeArmatureData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeArmatureData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_removeArmatureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_getArmatureDatas(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_getArmatureDatas'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Map<std::basic_string<char>, cocostudio::ArmatureData *>& ret = cobj->getArmatureDatas();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Map<std::basic_string<char>, cocostudio::ArmatureData *>&)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Map<std::basic_string<char>, cocostudio::ArmatureData >");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Map<std::basic_string<char>, cocostudio::ArmatureData >");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getArmatureDatas",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_getArmatureDatas'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_removeTextureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_removeTextureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->removeTextureData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeTextureData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_removeTextureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_addTextureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_addTextureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocostudio::TextureData* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        do {
				if (!luaval_is_usertype(tolua_S,3,"TextureData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::TextureData*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->addTextureData(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        const char* arg0;
        cocostudio::TextureData* arg1;
        const char* arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        do {
				if (!luaval_is_usertype(tolua_S,3,"TextureData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::TextureData*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cobj->addTextureData(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addTextureData",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_addTextureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isAutoLoadSpriteFile();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isAutoLoadSpriteFile",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ArmatureDataManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ArmatureDataManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cobj->addSpriteFrameFromFile(arg0, arg1);
        return 0;
    }
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp); arg2 = arg2_tmp.c_str();
        if(!ok)
            return 0;
        cobj->addSpriteFrameFromFile(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addSpriteFrameFromFile",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_destoryInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ArmatureDataManager::destoryInstance();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "destoryInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_destoryInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ArmatureDataManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ArmatureDataManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ArmatureDataManager* ret = cocostudio::ArmatureDataManager::getInstance();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ArmatureDataManager*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ArmatureDataManager");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ArmatureDataManager");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ArmatureDataManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_studio_ArmatureDataManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ArmatureDataManager)");
    return 0;
}

int lua_register_cocos2dx_studio_ArmatureDataManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ArmatureDataManager");
    tolua_cclass(tolua_S,"ArmatureDataManager","ArmatureDataManager","",NULL);

    tolua_beginmodule(tolua_S,"ArmatureDataManager");
        tolua_function(tolua_S,"getAnimationDatas",lua_cocos2dx_studio_ArmatureDataManager_getAnimationDatas);
        tolua_function(tolua_S,"removeAnimationData",lua_cocos2dx_studio_ArmatureDataManager_removeAnimationData);
        tolua_function(tolua_S,"addArmatureData",lua_cocos2dx_studio_ArmatureDataManager_addArmatureData);
        tolua_function(tolua_S,"addArmatureFileInfo",lua_cocos2dx_studio_ArmatureDataManager_addArmatureFileInfo);
        tolua_function(tolua_S,"removeArmatureFileInfo",lua_cocos2dx_studio_ArmatureDataManager_removeArmatureFileInfo);
        tolua_function(tolua_S,"getTextureDatas",lua_cocos2dx_studio_ArmatureDataManager_getTextureDatas);
        tolua_function(tolua_S,"getTextureData",lua_cocos2dx_studio_ArmatureDataManager_getTextureData);
        tolua_function(tolua_S,"getArmatureData",lua_cocos2dx_studio_ArmatureDataManager_getArmatureData);
        tolua_function(tolua_S,"getAnimationData",lua_cocos2dx_studio_ArmatureDataManager_getAnimationData);
        tolua_function(tolua_S,"addAnimationData",lua_cocos2dx_studio_ArmatureDataManager_addAnimationData);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_ArmatureDataManager_init);
        tolua_function(tolua_S,"removeArmatureData",lua_cocos2dx_studio_ArmatureDataManager_removeArmatureData);
        tolua_function(tolua_S,"getArmatureDatas",lua_cocos2dx_studio_ArmatureDataManager_getArmatureDatas);
        tolua_function(tolua_S,"removeTextureData",lua_cocos2dx_studio_ArmatureDataManager_removeTextureData);
        tolua_function(tolua_S,"addTextureData",lua_cocos2dx_studio_ArmatureDataManager_addTextureData);
        tolua_function(tolua_S,"isAutoLoadSpriteFile",lua_cocos2dx_studio_ArmatureDataManager_isAutoLoadSpriteFile);
        tolua_function(tolua_S,"addSpriteFrameFromFile",lua_cocos2dx_studio_ArmatureDataManager_addSpriteFrameFromFile);
        tolua_function(tolua_S,"destoryInstance", lua_cocos2dx_studio_ArmatureDataManager_destoryInstance);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_studio_ArmatureDataManager_getInstance);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ArmatureDataManager).hash_code();
    g_luaType[typeId] = "ArmatureDataManager";
    return 1;
}

int lua_cocos2dx_studio_Armature_getBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::Bone* ret = cobj->getBone(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Bone*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Bone");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Bone");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBone",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_changeBoneParent(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_changeBoneParent'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocostudio::Bone* arg0;
        const char* arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cobj->changeBoneParent(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "changeBoneParent",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_changeBoneParent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_setAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_setAnimation'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::ArmatureAnimation* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"ArmatureAnimation",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::ArmatureAnimation*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setAnimation(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setAnimation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_setAnimation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getBoneAtPoint(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getBoneAtPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cocostudio::Bone* ret = cobj->getBoneAtPoint(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Bone*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Bone");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Bone");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBoneAtPoint",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getBoneAtPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getArmatureTransformDirty(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getArmatureTransformDirty'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->getArmatureTransformDirty();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getArmatureTransformDirty",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getArmatureTransformDirty'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_setVersion(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_setVersion'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setVersion(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setVersion",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_setVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_updateOffsetPoint(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_updateOffsetPoint'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->updateOffsetPoint();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateOffsetPoint",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_updateOffsetPoint'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getParentBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getParentBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::Bone* ret = cobj->getParentBone();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Bone*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Bone");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Bone");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getParentBone",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getParentBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_setName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_setName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_setName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_removeBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_removeBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocostudio::Bone* arg0;
        bool arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->removeBone(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "removeBone",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_removeBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getBatchNode(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getBatchNode'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::BatchNode* ret = cobj->getBatchNode();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::BatchNode*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"BatchNode");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"BatchNode");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBatchNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getBatchNode'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_init'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->init(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            bool ret = cobj->init();
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocostudio::Bone* arg1;
            do {
				if (!luaval_is_usertype(tolua_S,3,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::Bone*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);

            if (!ok) { break; }
            bool ret = cobj->init(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getNodeToParentTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getNodeToParentTransform'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const kmMat4& ret = cobj->getNodeToParentTransform();
        #pragma warning NO CONVERSION FROM NATIVE FOR kmMat4;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeToParentTransform",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getNodeToParentTransform'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_setParentBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_setParentBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::Bone* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setParentBone(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setParentBone",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_setParentBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getBoundingBox(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getBoundingBox'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Rect ret = cobj->getBoundingBox();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBoundingBox",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getBoundingBox'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_drawContour(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_drawContour'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->drawContour();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "drawContour",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_drawContour'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_setBatchNode(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_setBatchNode'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::BatchNode* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"BatchNode",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::BatchNode*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setBatchNode(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBatchNode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_setBatchNode'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_draw'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->draw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_draw'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_setArmatureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_setArmatureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::ArmatureData* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"ArmatureData",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::ArmatureData*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setArmatureData(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setArmatureData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_setArmatureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_addBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_addBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocostudio::Bone* arg0;
        const char* arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cobj->addBone(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "addBone",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_addBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_update(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_update'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_update'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getArmatureData(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getArmatureData'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::ArmatureData* ret = cobj->getArmatureData();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ArmatureData*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ArmatureData");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ArmatureData");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getArmatureData",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getArmatureData'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getVersion(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getVersion'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getVersion();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVersion",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getAnimation(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getAnimation'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::ArmatureAnimation* ret = cobj->getAnimation();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ArmatureAnimation*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ArmatureAnimation");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ArmatureAnimation");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getAnimation",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getAnimation'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_getBoneDic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Armature_getBoneDic'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const cocos2d::Map<std::basic_string<char>, cocostudio::Bone *>& ret = cobj->getBoneDic();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Map<std::basic_string<char>, cocostudio::Bone *>&)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Map<std::basic_string<char>, cocostudio::Bone >");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Map<std::basic_string<char>, cocostudio::Bone >");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBoneDic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_getBoneDic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocostudio::Armature* ret = cocostudio::Armature::create(arg0);
            do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Armature*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Armature");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Armature");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocostudio::Armature* ret = cocostudio::Armature::create();
            do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Armature*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Armature");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Armature");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocostudio::Bone* arg1;
            do {
				if (!luaval_is_usertype(tolua_S,3,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg1 = (cocostudio::Bone*)tolua_tousertype(tolua_S,3,0);
					if (nullptr == arg1){
						LUA_PRECONDITION( arg1, "Invalid Native Object");
			}}} while (0);
            if (!ok) { break; }
            cocostudio::Armature* ret = cocostudio::Armature::create(arg0, arg1);
            do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Armature*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Armature");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Armature");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Armature_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::Armature();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"Armature");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"Armature");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Armature",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Armature_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_Armature_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Armature)");
    return 0;
}

int lua_register_cocos2dx_studio_Armature(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Armature");
    tolua_cclass(tolua_S,"Armature","Armature","NodeRGBA",NULL);

    tolua_beginmodule(tolua_S,"Armature");
        tolua_function(tolua_S,"getBone",lua_cocos2dx_studio_Armature_getBone);
        tolua_function(tolua_S,"changeBoneParent",lua_cocos2dx_studio_Armature_changeBoneParent);
        tolua_function(tolua_S,"setAnimation",lua_cocos2dx_studio_Armature_setAnimation);
        tolua_function(tolua_S,"getBoneAtPoint",lua_cocos2dx_studio_Armature_getBoneAtPoint);
        tolua_function(tolua_S,"getArmatureTransformDirty",lua_cocos2dx_studio_Armature_getArmatureTransformDirty);
        tolua_function(tolua_S,"setVersion",lua_cocos2dx_studio_Armature_setVersion);
        tolua_function(tolua_S,"updateOffsetPoint",lua_cocos2dx_studio_Armature_updateOffsetPoint);
        tolua_function(tolua_S,"getParentBone",lua_cocos2dx_studio_Armature_getParentBone);
        tolua_function(tolua_S,"setName",lua_cocos2dx_studio_Armature_setName);
        tolua_function(tolua_S,"removeBone",lua_cocos2dx_studio_Armature_removeBone);
        tolua_function(tolua_S,"getBatchNode",lua_cocos2dx_studio_Armature_getBatchNode);
        tolua_function(tolua_S,"getName",lua_cocos2dx_studio_Armature_getName);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_Armature_init);
        tolua_function(tolua_S,"getNodeToParentTransform",lua_cocos2dx_studio_Armature_getNodeToParentTransform);
        tolua_function(tolua_S,"setParentBone",lua_cocos2dx_studio_Armature_setParentBone);
        tolua_function(tolua_S,"getBoundingBox",lua_cocos2dx_studio_Armature_getBoundingBox);
        tolua_function(tolua_S,"drawContour",lua_cocos2dx_studio_Armature_drawContour);
        tolua_function(tolua_S,"setBatchNode",lua_cocos2dx_studio_Armature_setBatchNode);
        tolua_function(tolua_S,"draw",lua_cocos2dx_studio_Armature_draw);
        tolua_function(tolua_S,"setArmatureData",lua_cocos2dx_studio_Armature_setArmatureData);
        tolua_function(tolua_S,"addBone",lua_cocos2dx_studio_Armature_addBone);
        tolua_function(tolua_S,"update",lua_cocos2dx_studio_Armature_update);
        tolua_function(tolua_S,"getArmatureData",lua_cocos2dx_studio_Armature_getArmatureData);
        tolua_function(tolua_S,"getVersion",lua_cocos2dx_studio_Armature_getVersion);
        tolua_function(tolua_S,"getAnimation",lua_cocos2dx_studio_Armature_getAnimation);
        tolua_function(tolua_S,"getBoneDic",lua_cocos2dx_studio_Armature_getBoneDic);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_Armature_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_Armature_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::Armature).hash_code();
    g_luaType[typeId] = "Armature";
    return 1;
}

int lua_cocos2dx_studio_Skin_getBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_getBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::Bone* ret = cobj->getBone();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Bone*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Bone");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Bone");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBone",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_getBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_draw(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_draw'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->draw();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "draw",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_draw'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_getNodeToWorldTransformAR(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_getNodeToWorldTransformAR'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        kmMat4 ret = cobj->getNodeToWorldTransformAR();
        #pragma warning NO CONVERSION FROM NATIVE FOR kmMat4;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeToWorldTransformAR",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_getNodeToWorldTransformAR'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_getNodeToWorldTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_getNodeToWorldTransform'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        kmMat4 ret = cobj->getNodeToWorldTransform();
        #pragma warning NO CONVERSION FROM NATIVE FOR kmMat4;
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNodeToWorldTransform",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_getNodeToWorldTransform'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_updateTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_updateTransform'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->updateTransform();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateTransform",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_updateTransform'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_getDisplayName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_getDisplayName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const std::string& ret = cobj->getDisplayName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDisplayName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_getDisplayName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_updateArmatureTransform(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_updateArmatureTransform'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->updateArmatureTransform();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "updateArmatureTransform",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_updateArmatureTransform'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_initWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_initWithSpriteFrameName'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->initWithSpriteFrameName(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithSpriteFrameName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_initWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_initWithFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->initWithFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "initWithFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_initWithFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_setBone(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::Skin*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_Skin_setBone'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocostudio::Bone* arg0;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Bone",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocostudio::Bone*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        if(!ok)
            return 0;
        cobj->setBone(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBone",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_setBone'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocostudio::Skin* ret = cocostudio::Skin::create(arg0);
            do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Skin*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Skin");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Skin");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            cocostudio::Skin* ret = cocostudio::Skin::create();
            do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Skin*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Skin");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Skin");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
            return 1;
        }
    } while (0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Skin",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::Skin* ret = cocostudio::Skin::createWithSpriteFrameName(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::Skin*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Skin");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Skin");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "createWithSpriteFrameName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_createWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_Skin_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::Skin* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::Skin();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"Skin");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"Skin");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "Skin",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_Skin_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_Skin_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Skin)");
    return 0;
}

int lua_register_cocos2dx_studio_Skin(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Skin");
    tolua_cclass(tolua_S,"Skin","Skin","Sprite",NULL);

    tolua_beginmodule(tolua_S,"Skin");
        tolua_function(tolua_S,"getBone",lua_cocos2dx_studio_Skin_getBone);
        tolua_function(tolua_S,"draw",lua_cocos2dx_studio_Skin_draw);
        tolua_function(tolua_S,"getNodeToWorldTransformAR",lua_cocos2dx_studio_Skin_getNodeToWorldTransformAR);
        tolua_function(tolua_S,"getNodeToWorldTransform",lua_cocos2dx_studio_Skin_getNodeToWorldTransform);
        tolua_function(tolua_S,"updateTransform",lua_cocos2dx_studio_Skin_updateTransform);
        tolua_function(tolua_S,"getDisplayName",lua_cocos2dx_studio_Skin_getDisplayName);
        tolua_function(tolua_S,"updateArmatureTransform",lua_cocos2dx_studio_Skin_updateArmatureTransform);
        tolua_function(tolua_S,"initWithSpriteFrameName",lua_cocos2dx_studio_Skin_initWithSpriteFrameName);
        tolua_function(tolua_S,"initWithFile",lua_cocos2dx_studio_Skin_initWithFile);
        tolua_function(tolua_S,"setBone",lua_cocos2dx_studio_Skin_setBone);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_Skin_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_Skin_create);
        tolua_function(tolua_S,"createWithSpriteFrameName", lua_cocos2dx_studio_Skin_createWithSpriteFrameName);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::Skin).hash_code();
    g_luaType[typeId] = "Skin";
    return 1;
}

int lua_cocos2dx_studio_ComAttribute_getFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_getFloat'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        float ret = cobj->getFloat(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFloat",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_getFloat'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_getDict(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_getDict'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocostudio::JsonDictionary* ret = cobj->getDict();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::JsonDictionary*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"JsonDictionary");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"JsonDictionary");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getDict",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_getDict'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_setFloat(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_setFloat'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        double arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setFloat(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFloat",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_setFloat'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_setCString(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_setCString'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setCString(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setCString",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_setCString'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_getCString(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_getCString'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        const char* ret = cobj->getCString(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getCString",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_getCString'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_getBool(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_getBool'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        bool ret = cobj->getBool(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBool",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_getBool'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_setInt(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_setInt'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        cobj->setInt(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setInt",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_setInt'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_getInt(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_getInt'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cobj->getInt(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getInt",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_getInt'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_setBool(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAttribute* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAttribute*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAttribute_setBool'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_boolean(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        cobj->setBool(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBool",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_setBool'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAttribute_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ComAttribute",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ComAttribute* ret = cocostudio::ComAttribute::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ComAttribute*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ComAttribute");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ComAttribute");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAttribute_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_studio_ComAttribute_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ComAttribute)");
    return 0;
}

int lua_register_cocos2dx_studio_ComAttribute(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ComAttribute");
    tolua_cclass(tolua_S,"ComAttribute","ComAttribute","Component",NULL);

    tolua_beginmodule(tolua_S,"ComAttribute");
        tolua_function(tolua_S,"getFloat",lua_cocos2dx_studio_ComAttribute_getFloat);
        tolua_function(tolua_S,"getDict",lua_cocos2dx_studio_ComAttribute_getDict);
        tolua_function(tolua_S,"setFloat",lua_cocos2dx_studio_ComAttribute_setFloat);
        tolua_function(tolua_S,"setCString",lua_cocos2dx_studio_ComAttribute_setCString);
        tolua_function(tolua_S,"getCString",lua_cocos2dx_studio_ComAttribute_getCString);
        tolua_function(tolua_S,"getBool",lua_cocos2dx_studio_ComAttribute_getBool);
        tolua_function(tolua_S,"setInt",lua_cocos2dx_studio_ComAttribute_setInt);
        tolua_function(tolua_S,"getInt",lua_cocos2dx_studio_ComAttribute_getInt);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_ComAttribute_init);
        tolua_function(tolua_S,"setBool",lua_cocos2dx_studio_ComAttribute_setBool);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ComAttribute_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ComAttribute).hash_code();
    g_luaType[typeId] = "ComAttribute";
    return 1;
}

int lua_cocos2dx_studio_ComAudio_stopAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_stopAllEffects'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->stopAllEffects();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopAllEffects",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_stopAllEffects'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_getEffectsVolume(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_getEffectsVolume'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getEffectsVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getEffectsVolume",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_getEffectsVolume'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_stopEffect(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_stopEffect'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->stopEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopEffect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_stopEffect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_getBackgroundMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_getBackgroundMusicVolume'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        float ret = cobj->getBackgroundMusicVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getBackgroundMusicVolume",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_getBackgroundMusicVolume'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_willPlayBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_willPlayBackgroundMusic'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->willPlayBackgroundMusic();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "willPlayBackgroundMusic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_willPlayBackgroundMusic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_setBackgroundMusicVolume(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_setBackgroundMusicVolume'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setBackgroundMusicVolume(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setBackgroundMusicVolume",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_setBackgroundMusicVolume'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_end(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_end'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->end();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "end",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_end'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_isEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_isEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_isEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_stopBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_stopBackgroundMusic'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 0) {
            cobj->stopBackgroundMusic();
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0);

            if (!ok) { break; }
            cobj->stopBackgroundMusic(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "stopBackgroundMusic",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_stopBackgroundMusic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_pauseBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_pauseBackgroundMusic'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pauseBackgroundMusic();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pauseBackgroundMusic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_pauseBackgroundMusic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isBackgroundMusicPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isBackgroundMusicPlaying",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_isLoop(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_isLoop'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isLoop();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isLoop",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_isLoop'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_pauseAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_pauseAllEffects'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->pauseAllEffects();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pauseAllEffects",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_pauseAllEffects'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_setEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_setEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_setEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_preloadBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_preloadBackgroundMusic'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->preloadBackgroundMusic(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "preloadBackgroundMusic",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_preloadBackgroundMusic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_playBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_playBackgroundMusic'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cobj->playBackgroundMusic(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1);

            if (!ok) { break; }
            cobj->playBackgroundMusic(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playBackgroundMusic",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_playBackgroundMusic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_playEffect(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = NULL;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_playEffect'", NULL);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            unsigned int ret = cobj->playEffect(arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1);

            if (!ok) { break; }
            unsigned int ret = cobj->playEffect(arg0, arg1);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "playEffect",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_playEffect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_resumeAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_resumeAllEffects'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resumeAllEffects();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resumeAllEffects",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_resumeAllEffects'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_setLoop(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_setLoop'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setLoop(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setLoop",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_setLoop'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_unloadEffect(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_unloadEffect'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->unloadEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "unloadEffect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_unloadEffect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_rewindBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_rewindBackgroundMusic'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->rewindBackgroundMusic();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "rewindBackgroundMusic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_rewindBackgroundMusic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_preloadEffect(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_preloadEffect'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->preloadEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "preloadEffect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_preloadEffect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_pauseEffect(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_pauseEffect'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->pauseEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "pauseEffect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_pauseEffect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_resumeBackgroundMusic(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_resumeBackgroundMusic'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->resumeBackgroundMusic();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resumeBackgroundMusic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_resumeBackgroundMusic'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_setFile(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_setFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cobj->setFile(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_setFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_setEffectsVolume(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_setEffectsVolume'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEffectsVolume(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEffectsVolume",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_setEffectsVolume'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_getFile(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_getFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        const char* ret = cobj->getFile();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFile",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_getFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_resumeEffect(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComAudio_resumeEffect'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->resumeEffect(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "resumeEffect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_resumeEffect'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComAudio_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ComAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ComAudio* ret = cocostudio::ComAudio::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ComAudio*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ComAudio");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ComAudio");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComAudio_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_studio_ComAudio_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ComAudio)");
    return 0;
}

int lua_register_cocos2dx_studio_ComAudio(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ComAudio");
    tolua_cclass(tolua_S,"ComAudio","ComAudio","Component",NULL);

    tolua_beginmodule(tolua_S,"ComAudio");
        tolua_function(tolua_S,"stopAllEffects",lua_cocos2dx_studio_ComAudio_stopAllEffects);
        tolua_function(tolua_S,"getEffectsVolume",lua_cocos2dx_studio_ComAudio_getEffectsVolume);
        tolua_function(tolua_S,"stopEffect",lua_cocos2dx_studio_ComAudio_stopEffect);
        tolua_function(tolua_S,"getBackgroundMusicVolume",lua_cocos2dx_studio_ComAudio_getBackgroundMusicVolume);
        tolua_function(tolua_S,"willPlayBackgroundMusic",lua_cocos2dx_studio_ComAudio_willPlayBackgroundMusic);
        tolua_function(tolua_S,"setBackgroundMusicVolume",lua_cocos2dx_studio_ComAudio_setBackgroundMusicVolume);
        tolua_function(tolua_S,"end",lua_cocos2dx_studio_ComAudio_end);
        tolua_function(tolua_S,"isEnabled",lua_cocos2dx_studio_ComAudio_isEnabled);
        tolua_function(tolua_S,"stopBackgroundMusic",lua_cocos2dx_studio_ComAudio_stopBackgroundMusic);
        tolua_function(tolua_S,"pauseBackgroundMusic",lua_cocos2dx_studio_ComAudio_pauseBackgroundMusic);
        tolua_function(tolua_S,"isBackgroundMusicPlaying",lua_cocos2dx_studio_ComAudio_isBackgroundMusicPlaying);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_ComAudio_init);
        tolua_function(tolua_S,"isLoop",lua_cocos2dx_studio_ComAudio_isLoop);
        tolua_function(tolua_S,"pauseAllEffects",lua_cocos2dx_studio_ComAudio_pauseAllEffects);
        tolua_function(tolua_S,"setEnabled",lua_cocos2dx_studio_ComAudio_setEnabled);
        tolua_function(tolua_S,"preloadBackgroundMusic",lua_cocos2dx_studio_ComAudio_preloadBackgroundMusic);
        tolua_function(tolua_S,"playBackgroundMusic",lua_cocos2dx_studio_ComAudio_playBackgroundMusic);
        tolua_function(tolua_S,"playEffect",lua_cocos2dx_studio_ComAudio_playEffect);
        tolua_function(tolua_S,"resumeAllEffects",lua_cocos2dx_studio_ComAudio_resumeAllEffects);
        tolua_function(tolua_S,"setLoop",lua_cocos2dx_studio_ComAudio_setLoop);
        tolua_function(tolua_S,"unloadEffect",lua_cocos2dx_studio_ComAudio_unloadEffect);
        tolua_function(tolua_S,"rewindBackgroundMusic",lua_cocos2dx_studio_ComAudio_rewindBackgroundMusic);
        tolua_function(tolua_S,"preloadEffect",lua_cocos2dx_studio_ComAudio_preloadEffect);
        tolua_function(tolua_S,"pauseEffect",lua_cocos2dx_studio_ComAudio_pauseEffect);
        tolua_function(tolua_S,"resumeBackgroundMusic",lua_cocos2dx_studio_ComAudio_resumeBackgroundMusic);
        tolua_function(tolua_S,"setFile",lua_cocos2dx_studio_ComAudio_setFile);
        tolua_function(tolua_S,"setEffectsVolume",lua_cocos2dx_studio_ComAudio_setEffectsVolume);
        tolua_function(tolua_S,"getFile",lua_cocos2dx_studio_ComAudio_getFile);
        tolua_function(tolua_S,"resumeEffect",lua_cocos2dx_studio_ComAudio_resumeEffect);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ComAudio_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ComAudio).hash_code();
    g_luaType[typeId] = "ComAudio";
    return 1;
}

int lua_cocos2dx_studio_ComController_setEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComController_setEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->setEnabled(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "setEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComController_setEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComController_isEnabled(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComController_isEnabled'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->isEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "isEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComController_isEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComController_update(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComController_update'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        if(!ok)
            return 0;
        cobj->update(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "update",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComController_update'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComController_init(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComController_init'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComController_init'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComController_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ComController",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::ComController* ret = cocostudio::ComController::create();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ComController*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ComController");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ComController");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComController_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComController_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::ComController();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"ComController");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"ComController");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "ComController",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComController_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_ComController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ComController)");
    return 0;
}

int lua_register_cocos2dx_studio_ComController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ComController");
    tolua_cclass(tolua_S,"ComController","ComController","Component",NULL);

    tolua_beginmodule(tolua_S,"ComController");
        tolua_function(tolua_S,"setEnabled",lua_cocos2dx_studio_ComController_setEnabled);
        tolua_function(tolua_S,"isEnabled",lua_cocos2dx_studio_ComController_isEnabled);
        tolua_function(tolua_S,"update",lua_cocos2dx_studio_ComController_update);
        tolua_function(tolua_S,"init",lua_cocos2dx_studio_ComController_init);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_ComController_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ComController_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ComController).hash_code();
    g_luaType[typeId] = "ComController";
    return 1;
}

int lua_cocos2dx_studio_ComRender_getNode(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::ComRender* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ComRender",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::ComRender*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_ComRender_getNode'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->getNode();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComRender_getNode'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_ComRender_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ComRender",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Node* arg0;
        const char* arg1;
        do {
				if (!luaval_is_usertype(tolua_S,2,"Node",0)){
					ok = false;
					break;
				}
				if (ok){
					arg0 = (cocos2d::Node*)tolua_tousertype(tolua_S,2,0);
					if (nullptr == arg0){
						LUA_PRECONDITION( arg0, "Invalid Native Object");
			}}} while (0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        cocostudio::ComRender* ret = cocostudio::ComRender::create(arg0, arg1);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::ComRender*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"ComRender");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"ComRender");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_ComRender_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_studio_ComRender_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ComRender)");
    return 0;
}

int lua_register_cocos2dx_studio_ComRender(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ComRender");
    tolua_cclass(tolua_S,"ComRender","ComRender","Component",NULL);

    tolua_beginmodule(tolua_S,"ComRender");
        tolua_function(tolua_S,"getNode",lua_cocos2dx_studio_ComRender_getNode);
        tolua_function(tolua_S,"create", lua_cocos2dx_studio_ComRender_create);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::ComRender).hash_code();
    g_luaType[typeId] = "ComRender";
    return 1;
}

int lua_cocos2dx_studio_GUIReader_widgetFromJsonFile(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::GUIReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GUIReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::GUIReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_GUIReader_widgetFromJsonFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        gui::UIWidget* ret = cobj->widgetFromJsonFile(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((gui::UIWidget*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"UIWidget");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"UIWidget");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "widgetFromJsonFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_GUIReader_widgetFromJsonFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_GUIReader_getVersionInteger(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::GUIReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GUIReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::GUIReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_GUIReader_getVersionInteger'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        int ret = cobj->getVersionInteger(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getVersionInteger",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_GUIReader_getVersionInteger'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_GUIReader_getFileDesignSize(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::GUIReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GUIReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::GUIReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_GUIReader_getFileDesignSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::Size ret = cobj->getFileDesignSize(arg0);
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "getFileDesignSize",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_GUIReader_getFileDesignSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_GUIReader_storeFileDesignSize(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::GUIReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GUIReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::GUIReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_GUIReader_storeFileDesignSize'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Size arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_size(tolua_S, 3, &arg1);
        if(!ok)
            return 0;
        cobj->storeFileDesignSize(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "storeFileDesignSize",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_GUIReader_storeFileDesignSize'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_GUIReader_purgeGUIReader(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GUIReader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::GUIReader::purgeGUIReader();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "purgeGUIReader",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_GUIReader_purgeGUIReader'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_GUIReader_shareReader(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GUIReader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::GUIReader* ret = cocostudio::GUIReader::shareReader();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::GUIReader*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"GUIReader");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"GUIReader");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "shareReader",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_GUIReader_shareReader'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_GUIReader_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::GUIReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::GUIReader();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"GUIReader");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"GUIReader");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "GUIReader",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_GUIReader_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_GUIReader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GUIReader)");
    return 0;
}

int lua_register_cocos2dx_studio_GUIReader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GUIReader");
    tolua_cclass(tolua_S,"GUIReader","GUIReader","",NULL);

    tolua_beginmodule(tolua_S,"GUIReader");
        tolua_function(tolua_S,"widgetFromJsonFile",lua_cocos2dx_studio_GUIReader_widgetFromJsonFile);
        tolua_function(tolua_S,"getVersionInteger",lua_cocos2dx_studio_GUIReader_getVersionInteger);
        tolua_function(tolua_S,"getFileDesignSize",lua_cocos2dx_studio_GUIReader_getFileDesignSize);
        tolua_function(tolua_S,"storeFileDesignSize",lua_cocos2dx_studio_GUIReader_storeFileDesignSize);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_GUIReader_constructor);
        tolua_function(tolua_S,"destroyInstance", lua_cocos2dx_studio_GUIReader_purgeGUIReader);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_studio_GUIReader_shareReader);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::GUIReader).hash_code();
    g_luaType[typeId] = "GUIReader";
    return 1;
}

int lua_cocos2dx_studio_SceneReader_purgeSceneReader(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::SceneReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SceneReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::SceneReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_SceneReader_purgeSceneReader'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj->purgeSceneReader();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "purgeSceneReader",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SceneReader_purgeSceneReader'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_SceneReader_createNodeWithSceneFile(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::SceneReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SceneReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocostudio::SceneReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_studio_SceneReader_createNodeWithSceneFile'", NULL);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        cocos2d::Node* ret = cobj->createNodeWithSceneFile(arg0);
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocos2d::Node*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"Node");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"Node");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "createNodeWithSceneFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SceneReader_createNodeWithSceneFile'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_SceneReader_sceneReaderVersion(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SceneReader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        const char* ret = cocostudio::SceneReader::sceneReaderVersion();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "sceneReaderVersion",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SceneReader_sceneReaderVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_SceneReader_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SceneReader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocostudio::SceneReader* ret = cocostudio::SceneReader::getInstance();
        do {
			if (NULL != ret){
				cocos2d::Object *dynObject = dynamic_cast<cocos2d::Object *>((cocostudio::SceneReader*)ret);
				if (NULL != dynObject) {
					int ID = ret ? (int)(dynObject->_ID) : -1;
					int* luaID = ret ? &(dynObject->_luaID) : NULL;
					toluafix_pushusertype_ccobject(tolua_S,ID, luaID, (void*)ret,"SceneReader");
				} else {
					 tolua_pushusertype(tolua_S,(void*)ret,"SceneReader");
			}} else {
				lua_pushnil(tolua_S);
			}
		} while (0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SceneReader_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_studio_SceneReader_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocostudio::SceneReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
            return 0;
        cobj = new cocostudio::SceneReader();
        cocos2d::Object* dynObject = dynamic_cast<cocos2d::Object *>(cobj);
        if (nullptr != dynObject) 
        {
            dynObject->autorelease();
            int ID =  (int)dynObject->_ID ;
            int* luaID =  &dynObject->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SceneReader");
        }
        else
        {
            tolua_pushusertype(tolua_S,(void*)cobj,"SceneReader");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        }
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "SceneReader",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_studio_SceneReader_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_studio_SceneReader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SceneReader)");
    return 0;
}

int lua_register_cocos2dx_studio_SceneReader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SceneReader");
    tolua_cclass(tolua_S,"SceneReader","SceneReader","",NULL);

    tolua_beginmodule(tolua_S,"SceneReader");
        tolua_function(tolua_S,"destroyInstance",lua_cocos2dx_studio_SceneReader_purgeSceneReader);
        tolua_function(tolua_S,"createNodeWithSceneFile",lua_cocos2dx_studio_SceneReader_createNodeWithSceneFile);
        tolua_function(tolua_S,"new",lua_cocos2dx_studio_SceneReader_constructor);
        tolua_function(tolua_S,"sceneReaderVersion", lua_cocos2dx_studio_SceneReader_sceneReaderVersion);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_studio_SceneReader_getInstance);
    tolua_endmodule(tolua_S);
    long typeId = typeid(cocostudio::SceneReader).hash_code();
    g_luaType[typeId] = "SceneReader";
    return 1;
}
TOLUA_API int register_all_cocos2dx_studio(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ccs",0);
	tolua_beginmodule(tolua_S,"ccs");

	lua_register_cocos2dx_studio_UILayoutParameter(tolua_S);
	lua_register_cocos2dx_studio_UIWidget(tolua_S);
	lua_register_cocos2dx_studio_UIButton(tolua_S);
	lua_register_cocos2dx_studio_UILabelAtlas(tolua_S);
	lua_register_cocos2dx_studio_UILayout(tolua_S);
	lua_register_cocos2dx_studio_UIScrollView(tolua_S);
	lua_register_cocos2dx_studio_UIListView(tolua_S);
	lua_register_cocos2dx_studio_ContourData(tolua_S);
	lua_register_cocos2dx_studio_UILayer(tolua_S);
	lua_register_cocos2dx_studio_UILinearLayoutParameter(tolua_S);
	lua_register_cocos2dx_studio_ArmatureAnimation(tolua_S);
	lua_register_cocos2dx_studio_DisplayData(tolua_S);
	lua_register_cocos2dx_studio_ArmatureDisplayData(tolua_S);
	lua_register_cocos2dx_studio_ArmatureDataManager(tolua_S);
	lua_register_cocos2dx_studio_BatchNode(tolua_S);
	lua_register_cocos2dx_studio_ActionManagerEx(tolua_S);
	lua_register_cocos2dx_studio_UIHelper(tolua_S);
	lua_register_cocos2dx_studio_ComController(tolua_S);
	lua_register_cocos2dx_studio_BaseData(tolua_S);
	lua_register_cocos2dx_studio_BoneData(tolua_S);
	lua_register_cocos2dx_studio_Bone(tolua_S);
	lua_register_cocos2dx_studio_ParticleDisplayData(tolua_S);
	lua_register_cocos2dx_studio_UILabelBMFont(tolua_S);
	lua_register_cocos2dx_studio_ComRender(tolua_S);
	lua_register_cocos2dx_studio_ArmatureData(tolua_S);
	lua_register_cocos2dx_studio_MovementData(tolua_S);
	lua_register_cocos2dx_studio_UILoadingBar(tolua_S);
	lua_register_cocos2dx_studio_Skin(tolua_S);
	lua_register_cocos2dx_studio_UIImageView(tolua_S);
	lua_register_cocos2dx_studio_UICheckBox(tolua_S);
	lua_register_cocos2dx_studio_ComAttribute(tolua_S);
	lua_register_cocos2dx_studio_GUIReader(tolua_S);
	lua_register_cocos2dx_studio_UIRelativeLayoutParameter(tolua_S);
	lua_register_cocos2dx_studio_Armature(tolua_S);
	lua_register_cocos2dx_studio_SpriteDisplayData(tolua_S);
	lua_register_cocos2dx_studio_UILabel(tolua_S);
	lua_register_cocos2dx_studio_MovementBoneData(tolua_S);
	lua_register_cocos2dx_studio_FrameData(tolua_S);
	lua_register_cocos2dx_studio_TextureData(tolua_S);
	lua_register_cocos2dx_studio_SceneReader(tolua_S);
	lua_register_cocos2dx_studio_UICCLabelAtlas(tolua_S);
	lua_register_cocos2dx_studio_UIRootWidget(tolua_S);
	lua_register_cocos2dx_studio_ComAudio(tolua_S);
	lua_register_cocos2dx_studio_UIPageView(tolua_S);
	lua_register_cocos2dx_studio_AnimationData(tolua_S);
	lua_register_cocos2dx_studio_UITextField(tolua_S);
	lua_register_cocos2dx_studio_UISlider(tolua_S);
	lua_register_cocos2dx_studio_UICCTextField(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

