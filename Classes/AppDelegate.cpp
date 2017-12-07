#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GJSliderScene.hpp"
#include "GJSettingScene.hpp"
#include "GJMotionScene.hpp"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

//own
static cocos2d::Size workingArea;
static float scaleFactor;
typedef struct tagResource
{
    cocos2d::Size size;
    char directory[100];
}Resource;

using namespace std;
USING_NS_CC;

static cocos2d::Size designResolutionSize;
//own

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("GitTest", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("GitTest");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    //own resolution
    designResolutionSize = cocos2d::Size(1212, 768);
    Resource mediumResource =  { cocos2d::Size(1212, 768),  "Normal" };
    Resource largeResource  =  { cocos2d::Size(2424, 1536), "HD" };
    
    Size frameSize = glview->getFrameSize();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
#else
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
#endif
    
    vector<string> searchPath;
    
    float genericDeviceWidth = (frameSize.width > frameSize.height) ? frameSize.width : frameSize.height;
    float genericDeviceHeight = (frameSize.width > frameSize.height) ? frameSize.height : frameSize.width;
    
    if (genericDeviceWidth > designResolutionSize.width || genericDeviceHeight > designResolutionSize.height)
    {
        scaleFactor = largeResource.size.height/designResolutionSize.height;
        searchPath.push_back(largeResource.directory);
        //searchPath.push_back(mediumResource.directory);
        director->setContentScaleFactor(scaleFactor);
        
    }
    else
    {
        workingArea = Size(1024.0f, ceilf((1024.0f / 960.0f) * 640.0f));
        
        float scaleFactor_deviceToResources = genericDeviceWidth / mediumResource.size.width;
        
        if(scaleFactor_deviceToResources * mediumResource.size.height < genericDeviceHeight)
        {
            scaleFactor_deviceToResources = genericDeviceHeight / mediumResource.size.height;
        }
        
        float scaleFactor_workingAreaToDevice = (scaleFactor_deviceToResources * workingArea.height) / genericDeviceHeight;
        
        if((scaleFactor_workingAreaToDevice * genericDeviceWidth) < (scaleFactor_deviceToResources * workingArea.width))
        {
            scaleFactor_workingAreaToDevice = (scaleFactor_deviceToResources * workingArea.width) / genericDeviceWidth;
        }
        
        scaleFactor = scaleFactor_workingAreaToDevice;
        searchPath.push_back(mediumResource.directory);
        director->setContentScaleFactor(scaleFactor);
        
        CCLOG("scaleFactor=%f",scaleFactor);
    }
    
    FileUtils::getInstance()->setSearchPaths(searchPath);
    
    //own resolution
    
    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = MotionScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
