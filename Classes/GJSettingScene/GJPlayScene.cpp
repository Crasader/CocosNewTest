//
//  GJPlayScene.cpp
//  GitTest
//
//  Created by admin on 29/11/17.
//
//

#include "GJPlayScene.hpp"
#include "GJSettingScene.hpp"
USING_NS_CC;

using namespace cocos2d::ui;

Scene* PlayScene::createScene()
{
    return PlayScene::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool PlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->isPopupPresent = false;
    
    auto Pop_btn = MenuItemImage::create(
                                         "HelloWorld.png",
                                         "HelloWorld.png",
                                         CC_CALLBACK_1(PlayScene::PopCallback, this));
    if (Pop_btn == nullptr ||
        Pop_btn->getContentSize().width <= 0 ||
        Pop_btn->getContentSize().height <= 0)
    {
        problemLoading("'HelloWorld.png' and 'HelloWorld.png'");
    }
    else
    {
        Pop_btn->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    }
    
    auto Back_btn = MenuItemImage::create(
                                          "PlayBtn.png",
                                          "PlayBtn.png",
                                          CC_CALLBACK_1(PlayScene::BackCallback, this));
    Back_btn->setRotation(180);
    if (Back_btn == nullptr ||
        Back_btn->getContentSize().width <= 0 ||
        Back_btn->getContentSize().height <= 0)
    {
        problemLoading("'PlayBtn.png' and 'PlayBtn.png'");
    }
    else
    {
        Back_btn->setPosition(Vec2(origin.x + Back_btn->getContentSize().width*.6, origin.y+Back_btn->getContentSize().height*.6));
    }
    
    // create menu, it's an autorelease object
    
    auto Setting_menu = Menu::create(Pop_btn,Back_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    this->addChild(Setting_menu, 1);

    return true;
}

void PlayScene::PopCallback(Ref* pSender)
{
    if(this->isPopupPresent)
        return;
    
    this->isPopupPresent = true;
    
    CCLOG("Pop");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->subLayer =Layer::create();
    
    this->blackBGSprite = Sprite::create("BG.jpg");
    this->blackBGSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //sprite->setTag(black_tag);
    
    Sprite *imgSpr = Sprite::create("Img1.jpg");
    imgSpr->setPosition(Vec2(1059.7,444.0));
    imgSpr->setOpacity(155);
    this->blackBGSprite->addChild(imgSpr,11);
//    subLayer->addChild(this->blackBGSprite, 10);
//    this->addChild(subLayer,100);
    
    
    auto Close_btn = MenuItemImage::create(
                                          "ExitBtn.png",
                                          "ExitBtn.png",
                                          CC_CALLBACK_1(PlayScene::CloseCallback, this));
    if (Close_btn == nullptr ||
        Close_btn->getContentSize().width <= 0 ||
        Close_btn->getContentSize().height <= 0)
    {
        problemLoading("'ExitBtn.png' and 'ExitBtn.png'");
    }
    else
    {

        //Close_btn->setPosition(Vec2(this->blackBGSprite->getContentSize().width -Close_btn->getContentSize().width*.6 ,this->blackBGSprite->getContentSize().height -Close_btn->getContentSize().height*.6));
        Close_btn->setPosition(Vec2(this->blackBGSprite->getContentSize().width*.95,this->blackBGSprite->getContentSize().height*.90));
    }
    

    auto Setting_menu = Menu::create(Close_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    this->blackBGSprite->addChild(Setting_menu, 1);
    
//    auto label = Label::createWithTTF("GJGameplay", "fonts/Marker Felt.ttf", 24);
//    if (label == nullptr)
//    {
//        problemLoading("'fonts/Marker Felt.ttf'");
//    }
//    else
//    {
//        // position the label on the center of the screen
//        label->setPosition(Vec2(blackBGSprite->getContentSize().width/2,
//                                blackBGSprite->getContentSize().height/2));
//        
//        // add the label as a child to this layer
//        this->blackBGSprite->addChild(label, 1);
//    }
    
    subLayer->addChild(this->blackBGSprite, 10);
    this->addChild(subLayer,100);
    
}

void PlayScene::BackCallback(Ref* pSender)
{
    CCLOG("Back");
    auto scene = SettingScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
    
}
void PlayScene::CloseCallback(Ref* pSender)
{
    CCLOG("close");
    //this->removeChild(sprite, 1);
    //this->blackBGSprite->removeFromParentAndCleanup(true);
    this->removeChild(subLayer, 100);
    this->isPopupPresent = false;

}
