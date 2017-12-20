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
    
    //auto visibleSize = Director::getInstance()->getVisibleSize();
   // Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
//    ui::ScrollView *scrollView = ui::ScrollView::create( );
//
//    scrollView->setDirection( ui::ScrollView::Direction::HORIZONTAL );
//    scrollView->setContentSize( Size( 500, 500 ) );
//    scrollView->setInnerContainerSize( Size( 1000, 500 ) );
//    scrollView->setBackGroundImage( "HelloWorld.png" );
//    scrollView->setBounceEnabled( true );
//    scrollView->setAnchorPoint( Vec2( 0.5, 0.5 ) );
//    scrollView->setPosition( Vec2( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y) );
//    for ( int i = 1; i <= 4; i++ )
//    {
//
//        ui::Button *button = ui::Button::create( "Sliderbox.png", "Sliderbox.png" );
//        button->setPosition( Vec2( ((scrollView->getContentSize( ).width/4)*(i+(i-1))), scrollView->getContentSize( ).height / 2) );
//        scrollView->addChild( button );
//    }
//    this->addChild( scrollView );
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
   
    Size size(500, 500);
    PageView* pageView = PageView::create();
    pageView->setDirection(PageView::Direction::HORIZONTAL);
    pageView->setContentSize(size);
    //Size backgroundSize = background->getContentSize();
    pageView->setPosition((visibleSize - pageView->getContentSize()) / 2.0f);
    pageView->removeAllItems();
    pageView->setIndicatorEnabled(true);
    pageView->setGlobalZOrder(200);
    
    pageView->setIndicatorEnabled(true);
    pageView->setIndicatorSpaceBetweenIndexNodes(5);
    pageView->setIndicatorIndexNodesScale(0.5);
    pageView->setIndicatorIndexNodesTexture("ExitBtn.png");
    pageView->setIndicatorIndexNodesColor(Color3B::RED);
    
    pageView->setMagneticType(PageView::MagneticType::CENTER);
    pageView->setGravity(PageView::Gravity::CENTER_HORIZONTAL);
    pageView->setBounceEnabled(true);
    

    int pageCount = 4;
    for (int i = 0; i < pageCount; ++i)
    {
        Layout* layout = Layout::create();
        layout->setContentSize(size);
        
        ImageView* imageView = ImageView::create("MP1.png");
        imageView->setScale9Enabled(true);
        imageView->setContentSize(size);
        imageView->setPosition(Vec2(layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f));
        layout->addChild(imageView);
        
        Text* label = Text::create(StringUtils::format("page %d",(i+1)), "fonts/Marker Felt.ttf", 30);
        label->setColor(Color3B(192, 192, 192));
        label->setPosition(Vec2(layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f));
        layout->addChild(label);
        
        pageView->insertCustomItem(layout, i);
    }
    pageView->setIndicatorIndexNodesOpacity(255);
    
    this->addChild(pageView);
    
    
//    _indicator = PageViewIndicator::create();
//    _indicator->setDirection(getDirection());
//    addProtectedChild(_indicator, 10000);
//    setIndicatorSelectedIndexColor(Color3B(100, 100, 255));
//    refreshIndicatorPosition();

    return true;
}


void SliderScene::pageViewEvent(Ref *pSender, PageViewEventType type)
{
    switch (type)
    {
        case PAGEVIEW_EVENT_TURNING:
        {
            PageView* pageView = dynamic_cast<PageView*>(pSender);
            
            _displayValueLabel->setString(StringUtils::format("page = %ld", static_cast<long>(pageView->getCurrentPageIndex() + 1)));
        }
            break;
            
        default:
            break;
    }
}

