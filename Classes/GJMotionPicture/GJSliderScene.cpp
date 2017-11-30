//
//  GJSliderScene.cpp
//  GitTest
//
//  Created by admin on 30/11/17.
//
//

#include "GJSliderScene.hpp"

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

USING_NS_CC;

Scene* SliderScene::createScene()
{
    return SliderScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SettingSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SliderScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
//
//    for (int i = 0; i < 50; i++)
//    {
//        cocos2d::__String * nomDuFichier = String::createWithFormat("%d.png", i);
//        auto menu1 = MenuItemFont::create(nomDuFichier->string, CCCALLBACK_1(HelloWorld::Touch1, this));
//        menu->addChild(menu1);
//    }
//    menu->alignItemsVertically();
//    
//    scrollView = cocos2d::extension::ScrollView::create();
//    scrollView->retain();
//    scrollView->setContainer(menu);
//    scrollView->setDirection(extension::ScrollView::Direction::VERTICAL);
//    scrollView->setViewSize(Size(visibleSize.width, visibleSize.height));
//    scrollView->setTouchEnabled(true);
//    scrollView->setContentSize(Size(menu->getContentSize().width, menu->getContentSize().height));
//    scrollView->unscheduleAllSelectors();
//    scrollView->updateInset();
//    this->addChild(scrollView, 2);

    return true;
}
