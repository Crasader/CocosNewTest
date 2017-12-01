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

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"


using namespace cocos2d;
using namespace ui;

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
    
    ui::ScrollView *scrollView = ui::ScrollView::create( );
    
    scrollView->setDirection( ui::ScrollView::Direction::HORIZONTAL );
    scrollView->setContentSize( Size( 500, 500 ) );
    scrollView->setInnerContainerSize( Size( 1000, 500 ) );
    scrollView->setBackGroundImage( "HelloWorld.png" );
    scrollView->setBounceEnabled( true );
    scrollView->setAnchorPoint( Vec2( 0.5, 0.5 ) );
    scrollView->setPosition( Vec2( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y) );
    for ( int i = 1; i <= 4; i++ )
    {
        
        ui::Button *button = ui::Button::create( "Sliderbox.png", "Sliderbox.png" );
        button->setPosition( Vec2( ((scrollView->getContentSize( ).width/4)*(i+(i-1))), scrollView->getContentSize( ).height / 2) );
        scrollView->addChild( button );
    }
    this->addChild( scrollView );
    
    
    
    

    return true;
}
