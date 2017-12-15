//
//  GameScene.cpp
//  GitTest
//
//  Created by Winsols on 15/12/17.
//

#include "GJGameScene.hpp"
#include "GJMotionScene.hpp"
#include "GJPlayScene.hpp"
#include "GJMenuScene.hpp"
#include "GJSettingScene.hpp"



#include <stdio.h>
#include "cocos2d.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"


using namespace cocos2d;
using namespace ui;

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SettingSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto Motion_btn = MenuItemImage::create(
                                         "MotionBtn.png",
                                         "MotionBtn.png",
                                         CC_CALLBACK_1(GameScene::MotionCallback, this));
    Motion_btn->setPosition(Vec2(visibleSize.width*.25,visibleSize.height*.80));
    
    auto Pop_btn = MenuItemImage::create(
                                            "PopBtn.png",
                                            "PopBtn.png",
                                            CC_CALLBACK_1(GameScene::PlayCallback, this));
    Pop_btn->setPosition(Vec2(visibleSize.width*.75,visibleSize.height*.80));
    
    
    auto Setting_btn = MenuItemImage::create(
                                             "SettingBtn.png",
                                             "SettingBtn.png",
                                             CC_CALLBACK_1(GameScene::MenuCallback, this));
    Setting_btn->setPosition(Vec2(visibleSize.width*.25,visibleSize.height*.30));
    
    
    auto PageView_btn = MenuItemImage::create(
                                            "PageViewBtn.png",
                                            "PageViewBtn.png",
                                            CC_CALLBACK_1(GameScene::PageViewCallback, this));
    PageView_btn->setPosition(Vec2(visibleSize.width*.75,visibleSize.height*.30));
    
    
    
    
    auto Setting_menu = Menu::create(Motion_btn,Pop_btn,PageView_btn,Setting_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    this->addChild(Setting_menu, 1);
 
    return true;
}
void GameScene::MotionCallback(Ref* pSender)
{
    auto scene = MotionScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
}
void GameScene::PlayCallback(Ref* pSender)
{
    auto scene = PlayScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
}
void GameScene::MenuCallback(Ref* pSender)
{
    auto scene = MenuScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
}

void GameScene::PageViewCallback(Ref* pSender)
{
    auto scene = SettingScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
}
