//
//  GJSettingScene.cpp
//  GitTest
//
//  Created by admin on 28/11/17.
//
//

#include "GJSettingScene.hpp"
USING_NS_CC;

Scene* SettingScene::createScene()
{
    return SettingScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SettingSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SettingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    CCLOG("Entered ");
    //Srinivas
    
    
    //Srinivas asjdhb
    
    //Cahanges added.
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(SettingScene::menuCloseCallback, this));
    
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        //closeItem->setPosition(Vec2(visibleSize.width + origin.x -closeItem->getContentSize().width*.6, visibleSize.height + origin.y-closeItem->getContentSize().height*.6));
        closeItem->setPosition(Vec2(visibleSize.width + origin.x -closeItem->getContentSize().width*.6, origin.y+closeItem->getContentSize().height*.6));
    }
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
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
    
    // add "SettingScene" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width*.25 + origin.x, visibleSize.height/2 + origin.y));
        
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
        
        sprite->runAction(MoveTo::create(10, Vec2(visibleSize.width*.75+ origin.x, visibleSize.height/2 + origin.y)));
        
        //auto MoveTo::create(duration, Vec3(position.x, position.y, 0));

        
        //MoveTo* MoveTo::create(float duration, const Vec2& position)
        //{
        //    return MoveTo::create(duration, Vec3(position.x, position.y, 0));
        //}
        
        
    }
    return true;
}


void SettingScene::menuCloseCallback(Ref* pSender)
{
    
    
}
