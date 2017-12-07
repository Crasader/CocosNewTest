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
    
    auto sprite = Sprite::create("BG.jpg");
    if (sprite == nullptr)
    {
        problemLoading("'BG.jpg'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
        this->addChild(sprite, 0);
    }
    
    auto SettingPanel = Sprite::create("Setting/SettingPanel.png");
    SettingPanel->setPosition(Vec2(visibleSize.width/2, visibleSize.height*.53));
    this->addChild(SettingPanel, 0);
    
    
 
    auto Sound_btn = MenuItemImage::create(
                                          "Setting/SoundOn.png",
                                          "Setting/SoundOff.png",
                                          CC_CALLBACK_1(MenuScene::SoundCallback, this));

    if (Sound_btn == nullptr ||
        Sound_btn->getContentSize().width <= 0 ||
        Sound_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/SoundOn.png' and 'Setting/SoundOff.png'");
    }
    else
    {
        Sound_btn->setPosition(Vec2(visibleSize.width*.30, visibleSize.height*.63));
    }
    
    auto Music_btn = MenuItemImage::create(
                                           "Setting/MusicOn.png",
                                           "Setting/MusicOff.png",
                                           CC_CALLBACK_1(MenuScene::MusicCallback, this));
    
    
    if (Music_btn == nullptr ||
        Music_btn->getContentSize().width <= 0 ||
        Music_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/MusicOn.png' and 'Setting/MusicOff.png'");
    }
    else
    {
        Music_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-(Music_btn->getContentSize().height*1.20)));
    }
    
    auto Chart_btn = MenuItemImage::create(
                                           "Setting/Chart.png",
                                           "Setting/Chart.png",
                                           CC_CALLBACK_1(MenuScene::ChartCallback, this));
    
    
    if (Chart_btn == nullptr ||
        Chart_btn->getContentSize().width <= 0 ||
        Chart_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/Chart.png' and 'Setting/Chart.png'");
    }
    else
    {
        Chart_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*2)));
    }

    auto Rate_btn = MenuItemImage::create(
                                           "Setting/Rate.png",
                                           "Setting/Rate.png",
                                           CC_CALLBACK_1(MenuScene::RateCallback, this));
    
    
    if (Rate_btn == nullptr ||
        Rate_btn->getContentSize().width <= 0 ||
        Rate_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/Rate.png' and 'Setting/Rate.png'");
    }
    else
    {
        Rate_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-((Rate_btn->getContentSize().height*1.20)*3)));
    }
    
    auto About_btn = MenuItemImage::create(
                                          "Setting/About.png",
                                          "Setting/About.png",
                                          CC_CALLBACK_1(MenuScene::AboutCallback, this));
    
    
    if (About_btn == nullptr ||
        About_btn->getContentSize().width <= 0 ||
        About_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/About.png' and 'Setting/About.png'");
    }
    else
    {
        About_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-((About_btn->getContentSize().height*1.20)*4)));
    }
    
    auto Close_btn = MenuItemImage::create(
                                           "ExitBtn.png",
                                           "ExitBtn.png",
                                           CC_CALLBACK_1(MenuScene::CloseCallback, this));
    
    Close_btn->setScale(3.0f);
    
    if (Close_btn == nullptr ||
        Close_btn->getContentSize().width <= 0 ||
        Close_btn->getContentSize().height <= 0)
    {
        problemLoading("'ExitBtn.png' and 'ExitBtn.png'");
    }
    else
    {
        Close_btn->setPosition(Vec2(SettingPanel->getContentSize().width,SettingPanel->getContentSize().height));
    }


    auto Setting_menu = Menu::create(Sound_btn,Music_btn,Chart_btn,Rate_btn,About_btn,Close_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    SettingPanel->addChild(Setting_menu, 1);
    

    
    auto Settings_label = Label::createWithTTF("SETTINGS", "fonts/Marker Felt.ttf", 60);
    Settings_label->setPosition(Vec2(visibleSize.width*.25,visibleSize.height*.78));
    Settings_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    SettingPanel->addChild(Settings_label, 1);
    
    auto Sound_label = Label::createWithTTF("SOUND", "fonts/Marker Felt.ttf", 40);
    Sound_label->setPosition(Vec2(visibleSize.width*.18, visibleSize.height*.63));
    Sound_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    //Sound_label->setHorizontalAlignment(TextHAlignment::LEFT);
    SettingPanel->addChild(Sound_label, 1);
    
    auto Music_label = Label::createWithTTF("MUSIC", "fonts/Marker Felt.ttf", 40);
    Music_label->setPosition(Vec2(visibleSize.width*.18, (visibleSize.height*.63)-(Music_btn->getContentSize().height*1.20)));
    Music_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    SettingPanel->addChild(Music_label, 1);
    
    auto Chart_label = Label::createWithTTF("CHART", "fonts/Marker Felt.ttf", 40);
    Chart_label->setPosition(Vec2(visibleSize.width*.18, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*2)));
    Chart_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    SettingPanel->addChild(Chart_label, 1);
    
    auto Rate_label = Label::createWithTTF("RATE US", "fonts/Marker Felt.ttf", 40);
    Rate_label->setPosition(Vec2(visibleSize.width*.18, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*3)));
    Rate_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    SettingPanel->addChild(Rate_label, 1);
    
    auto About_label = Label::createWithTTF("ABOUT", "fonts/Marker Felt.ttf", 40);
    About_label->setPosition(Vec2(visibleSize.width*.18, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*4)));
    About_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    SettingPanel->addChild(About_label, 1);

 
    
    return true;
}
void MenuScene::SoundCallback(Ref* pSender)
{
    CCLOG("Sound");
}
void MenuScene::MusicCallback(Ref* pSender)
{
    CCLOG("Music");
}
void MenuScene::ChartCallback(Ref* pSender)
{
    CCLOG("Chart");
}
void MenuScene::RateCallback(Ref* pSender)
{
    CCLOG("Rate");
}
void MenuScene::AboutCallback(Ref* pSender)
{
    CCLOG("About");
}
void MenuScene::CloseCallback(Ref* pSender)
{
    CCLOG("Back");
    auto scene = SettingScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);

}

