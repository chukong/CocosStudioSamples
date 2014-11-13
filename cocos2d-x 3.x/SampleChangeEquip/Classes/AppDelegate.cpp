#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"


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

	CCSize screenSize = glview->getFrameSize();

	CCSize designSize = CCSizeMake(480, 320);

	CCFileUtils* pFileUtils = CCFileUtils::sharedFileUtils();

	if (screenSize.height > 320)
	{
		CCSize resourceSize = CCSizeMake(960, 640);
		std::vector<std::string> searchPaths;
		searchPaths.push_back("hd");
		pFileUtils->setSearchPaths(searchPaths);
		director->setContentScaleFactor(resourceSize.height/designSize.height);
	}

	glview->setDesignResolutionSize(designSize.width, designSize.height, kResolutionShowAll);

	// turn on display FPS
	director->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

	// create a scene. it's an autorelease object
	CCScene *pScene = HelloWorld::createScene();

	// run
	director->runWithScene(pScene);

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
