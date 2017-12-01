//
//  GJSettingScene.cpp
//  GitTest
//
//  Created by admin on 28/11/17.
//
//

#include "GJSettingScene.hpp"
#include "GJMenuScene.hpp"
#include "GJPlayScene.hpp"
#include "SimpleAudioEngine.h"
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
    //Sound Added
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BGM_MainMenu.mp3",true);
    

    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "Coin.png",
                                           "Coin.png",
                                           CC_CALLBACK_1(SettingScene::menuCloseCallback, this));
    
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'Coin.png' and 'Coin.png'");
    }
    else
    {
         closeItem->setPosition(Vec2(visibleSize.width + origin.x -closeItem->getContentSize().width*.6, visibleSize.height + origin.y-closeItem->getContentSize().height*.6));
        //closeItem->setPosition(Vec2(visibleSize.width + origin.x -closeItem->getContentSize().width*.6, origin.y+closeItem->getContentSize().height*.6));
    }

    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Home", "fonts/Marker Felt.ttf", 24);
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
    auto sprite = Sprite::create("BG.jpg");
    if (sprite == nullptr)
    {
        problemLoading("'BG.jpg'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.height/2 + origin.x, visibleSize.height/2 + origin.y));
        
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
        
        // auto sprite_move = MoveTo::create(2, Vec2(visibleSize.width*.75+ origin.x, visibleSize.height/2 + origin.y));
        //auto sprite_rot = RotateBy::create(2, 360);
        //auto rot2 = rot1->reverse();
        
        // auto sprite_seq = Sequence::create(sprite_move, sprite_rot, nullptr);
         //sprite->runAction(sprite_seq);
        //sprite->runAction(MoveTo::create(10, Vec2(visibleSize.width*.75+ origin.x, visibleSize.height/2 + origin.y)));
        
        //sprite->runAction(Sequence::create(sprite_move, sprite_rot, nullptr));
        
    }
    
    // add a "setting" icon to exit the progress. it's an autorelease object
    auto Setting_btn = MenuItemImage::create(
                                             "Setting.png",
                                             "Setting.png",
                                             CC_CALLBACK_1(SettingScene::SettingCallback, this));
    
    if (Setting_btn == nullptr ||
        Setting_btn->getContentSize().width <= 0 ||
        Setting_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting.png' and 'Setting.png'");
    }
    else
    {
        Setting_btn->setPosition(Vec2(origin.x + Setting_btn->getContentSize().width*.6, visibleSize.height + origin.y-Setting_btn->getContentSize().height*.6));
    }
    
    auto Play_btn = MenuItemImage::create(
                                             "Store.png",
                                             "Store.png",
                                             CC_CALLBACK_1(SettingScene::PlayCallback, this));
    
    if (Play_btn == nullptr ||
        Play_btn->getContentSize().width <= 0 ||
        Play_btn->getContentSize().height <= 0)
    {
        problemLoading("'Store.png' and 'Store.png'");
    }
    else
    {
         Play_btn->setPosition(Vec2(origin.x + Play_btn->getContentSize().width*.6, visibleSize.height + origin.y-Play_btn->getContentSize().height*.24));
        //Play_btn->setPosition(Vec2(origin.x + visibleSize.width/2,
          //                         visibleSize.height*.25));
    }
    
    // create menu, it's an autorelease object
    
    auto Setting_menu = Menu::create(Setting_btn,closeItem,Play_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    this->addChild(Setting_menu, 1);
    
    //auto play_label = Label::createWithTTF("Play", "fonts/Marker Felt.ttf", 50);
    // auto play_label = Label::createWithBMFont("fonts/Marker Felt.ttf", "Play");
    // Setting_menu->addChild(play_label, 1);
    
//    auto labelPlay = Label::createWithTTF("Play", "fonts/Marker Felt.ttf", 30);
//    auto Play_Btn = MenuItemLabel::create(labelPlay, CC_CALLBACK_1(SettingScene::PlayCallback, this));
//    Play_Btn->setPosition(Vec2(origin.x + visibleSize.width/2,
//                               visibleSize.height*.25));
//    this->addChild(Play_Btn, 1);
    
    //
    ValueMap data;
    std::string path = FileUtils::getInstance()->fullPathForFilename("Plist/FirstPointArray.plist");
    data = FileUtils::getInstance()->getValueMapFromFile(path);
    
    ValueVector arrLevels = data.at("PointsArray").asValueVector();
    
    for (int i = 0; i<arrLevels.size(); i++)
    {
        
        std::string sdata = (arrLevels[i]).asString();
        
        Vec2 pos=PointFromString(sdata.c_str());
        
        CCLOG(" Value %s",sdata.c_str());
        CCLOG("Points x %f , y %f",pos.x,pos.y);
    }
    
  //  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Animation/bullet.plist","Animation/bulletani.png");
   // AnimationCache::getInstance()->addAnimationsWithFile("Animation/animation.plist");
  //  auto bullet1 = Sprite::createWithSpriteFrameName("0.png");
  //  bullet1->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    //this->addChild(bullet1,100);
    //bullet1->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("animation_1"))));
    
//    //Frame Animation
//    Sprite *birdAnimSpr = Sprite::createWithSpriteFrameName("0.png");
//    //call idle animation
//    birdAnimSpr->setPosition(Vec2(this->getContentSize().width/2,this->getContentSize().height/2));
//    this->addChild(birdAnimSpr);
//    birdAnimSpr->setName("birdAnim");
//    
//    Vector<SpriteFrame*> animFrames(120);
//    
//    char str[120] = {0};
//    for(int i = 1; i < 8; i++)
//    {
//        sprintf(str, "%s%d.png","Pigeon-animation_",i);
//        
//        auto frame = AnimationCache->getSpriteFrameByName(str);
//        animFrames.pushBack(frame);
//    }
//    Animation *_birdAnim = Animation::createWithSpriteFrames(animFrames, 0.09f);
//    RepeatForever *moveAction=RepeatForever::create(Animate::create(_birdAnim));
//    moveAction->setTag(6);
//    
//    birdAnimSpr->runAction(moveAction);
    
//    ////////////////
//    
//    Vector< SpriteFrame*> _walkFrames;
//    Animation* _walkAnimation;
//    Animate* _walkAction;
//    
//    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
//    cache->addSpriteFramesWithFile("frames.plist"); // relative
//    
//    
//    for (int i = 0; i <= 1; i++)
//    {
//        std::string num = StringUtils::format("%d", i);
//        _walkFrames.pushBack(cache->getSpriteFrameByName(num + ".png"));
//    }
//    
//    // create the animation out of the frames and an action for the new animation
//    
//    _walkAnimation = Animation::createWithSpriteFrames(_walkFrames, 0.02f);
//    _walkAnimation->retain();
//    
//    // use/run the animation
//    
//    auto walk = Animate::create(_walkAnimation);
//    _legsSprite->runAction(RepeatForever::create(walk));

    

    
    return true;
}



void SettingScene::menuCloseCallback(Ref* pSender)
{
    CCLOG("CLOSE");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/SFX_ButtonClick.wav");
    
}
void SettingScene::SettingCallback(Ref* pSender)
{
    CCLOG("SETTING");
    auto scene = MenuScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
}
void SettingScene::PlayCallback(Ref* pSender)
{
    CCLOG("Play");
    auto scene = PlayScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);

}
