//
//  GJMenuScene.cpp
//  GitTest
//
//  Created by Winsols/Srinivas on 28/11/17.
//
//

#include "GJMenuScene.hpp"
#include "GJSettingScene.hpp"
USING_NS_CC;

using namespace cocos2d::ui;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithTTF("Settings", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));
        
        // add the label as a child to this layer
        this->addChild(label, 1);
    }
    
    
    
    // add a "volume" icon to exit the progress. it's an autorelease object
    auto Volume_btn = MenuItemImage::create(
                                             "CloseNormal.png",
                                             "CloseSelected.png",
                                             CC_CALLBACK_1(MenuScene::VolumeCallback, this));
    
    if (Volume_btn == nullptr ||
        Volume_btn->getContentSize().width <= 0 ||
        Volume_btn->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        Volume_btn->setPosition(Vec2(visibleSize.width*.25, visibleSize.height*.5));
    }
    
    // add a "mute" icon to exit the progress. it's an autorelease object
    auto Mute_btn = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MenuScene::MuteCallback, this));
    
    if (Mute_btn == nullptr ||
        Mute_btn->getContentSize().width <= 0 ||
        Mute_btn->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        Mute_btn->setPosition(Vec2(visibleSize.width*.75, visibleSize.height*.5));
    }
    
    auto Back_btn = MenuItemImage::create(
                                          "CloseNormal.png",
                                          "CloseSelected.png",
                                          CC_CALLBACK_1(MenuScene::BackCallback, this));
    if (Back_btn == nullptr ||
        Back_btn->getContentSize().width <= 0 ||
        Back_btn->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        Back_btn->setPosition(Vec2(origin.x + Back_btn->getContentSize().width*.6, origin.y+Back_btn->getContentSize().height*.6));
    }
    
    // create menu, it's an autorelease object
    
    auto Setting_menu = Menu::create(Volume_btn,Mute_btn,Back_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    this->addChild(Setting_menu, 1);

 
    
    return true;
}
void MenuScene::VolumeCallback(Ref* pSender)
{
    CCLOG("Volume");
}
void MenuScene::MuteCallback(Ref* pSender)
{
    CCLOG("Mute");
    
}
void MenuScene::BackCallback(Ref* pSender)
{
    CCLOG("Back");
    auto scene = SettingScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);

}
