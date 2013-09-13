EXECUTABLE = SampleHelloUI

INCLUDES = -I.. -I../Classes

SOURCES = main.cpp \
        ../Classes/AppDelegate.cpp \
        ../Classes/HelloWorldScene.cpp	\
	../Classes/UIScene.cpp \
	../Classes/UISceneManager.cpp \
	../Classes/UIButtonTest/UIButtonTest.cpp \
	../Classes/UICheckBoxTest/UICheckBoxTest.cpp \
	../Classes/UIDragPanelTest/UIDragPanelTest.cpp \
	../Classes/UIImageViewTest/UIImageViewTest.cpp \
	../Classes/UILabelAtlasTest/UILabelAtlasTest.cpp \
	../Classes/UILabelBMFontTest/UILabelBMFontTest.cpp \
	../Classes/UILabelTest/UILabelTest.cpp \
	../Classes/UIListViewTest/UIListViewTest.cpp \
	../Classes/UILoadingBarTest/UILoadingBarTest.cpp \
	../Classes/UINodeContainerTest/UINodeContainerTest.cpp \
	../Classes/UIPageViewTest/UIPageViewTest.cpp \
	../Classes/UIPanelTest/UIPanelTest.cpp \
	../Classes/UIScrollViewTest/UIScrollViewTest.cpp \
	../Classes/UISliderTest/UISliderTest.cpp \
	../Classes/UITextAreaTest/UITextAreaTest.cpp \
	../Classes/UITextButtonTest/UITextButtonTest.cpp \
	../Classes/UITextFieldTest/UITextFieldTest.cpp \
COCOS_ROOT = ../../cocos2d-x
include $(COCOS_ROOT)/cocos2dx/proj.linux/cocos2dx.mk

SHAREDLIBS += -lcocos2d
COCOS_LIBS = $(LIB_DIR)/libcocos2d.so

$(TARGET): $(OBJECTS) $(STATICLIBS) $(COCOS_LIBS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: %.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@
