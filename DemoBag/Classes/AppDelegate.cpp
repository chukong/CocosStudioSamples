#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "CocosGUIExamplesEquipScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    auto screenSize = glview->getFrameSize();
    
    auto designSize = Size(480, 320);
    
    auto fileUtils = FileUtils::getInstance();
    std::vector<std::string> searchPaths;
    
    if (screenSize.height > 320)
    {
        auto resourceSize = Size(960, 640);
        searchPaths.push_back("hd");
        director->setContentScaleFactor(resourceSize.height/designSize.height);
    }
    
    fileUtils->setSearchPaths(searchPaths);
    
    //    glview->setDesignResolutionSize(screenSize.width, screenSize.height, ResolutionPolicy::NO_BORDER);
    glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::NO_BORDER);
    
    
    // create a scene. it's an autorelease object
    auto scene = new CocosGUIExamplesEquipScene();
    scene->autorelease();
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
