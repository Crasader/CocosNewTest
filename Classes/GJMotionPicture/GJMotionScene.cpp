//
//  GJMotionScene.cpp
//  GitTest
//
//  Created by admin on 29/11/17.
//
//

#include "GJMotionScene.hpp"
USING_NS_CC;

Scene* MotionScene::createScene()
{
    return MotionScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SettingSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MotionScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
        auto motionSprite1 = Sprite::create("MP1.png");
    
        if (motionSprite1 == nullptr)
        {
            problemLoading("'MP1.png'");
        }
        else
        {
            motionSprite1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            motionSprite1->setScale(1.1);
            this->addChild(motionSprite1, 0);
        }
    
        auto MPfade = FadeIn::create(1.0f);
        auto firstMPmove = MoveBy::create(5, Vec2(-50,0));
        auto MPfade_reverse = MPfade->reverse();
    
        auto MPdelay = DelayTime::create(3);
    
        motionSprite1->setOpacity(0);
        motionSprite1->runAction( firstMPmove);
        motionSprite1->runAction( Sequence::create( MPfade,MPdelay,MPfade_reverse, nullptr));
    

    //this->scheduleOnce(CC_SCHEDULE_SELECTOR(MotionScene::afterFirstMotion), 10.0f);
    
    
    auto motionSprite2 = Sprite::create("MP2.png");
    
    if (motionSprite2 == nullptr)
    {
        problemLoading("'MP1.png'");
    }
    else
    {
        motionSprite2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        motionSprite2->setScale(1.1);
        this->addChild(motionSprite2, 0);
    }
    
    auto secondMPscale = ScaleTo::create(5, 1.2f);
    auto secondMPmove = MoveBy::create(5, Vec2(0,-30));

    
    auto secondMPdelay = DelayTime::create(5);
    
    motionSprite2->setOpacity(0);
    motionSprite2->runAction( Sequence::create( secondMPdelay,secondMPscale, nullptr));
    motionSprite2->runAction( Sequence::create( secondMPdelay,secondMPmove, nullptr));
    motionSprite2->runAction( Sequence::create( secondMPdelay,MPfade,MPdelay,MPfade_reverse, nullptr));
    
    auto motionSprite3 = Sprite::create("MP3.png");
    
    if (motionSprite3 == nullptr)
    {
        problemLoading("'MP3.png'");
    }
    else
    {
        motionSprite3->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        motionSprite3->setScale(1.1);
        this->addChild(motionSprite3, 0);
    }
    
    auto thirdMPmove = MoveBy::create(5, Vec2(50,0));
    auto thirdMPdelay = DelayTime::create(10);
    
    motionSprite3->setOpacity(0);
    motionSprite3->runAction( Sequence::create( thirdMPdelay,thirdMPmove, nullptr));
    motionSprite3->runAction( Sequence::create( thirdMPdelay,MPfade,MPdelay,MPfade_reverse, nullptr));
   
    CCLOG("Entered ");
    return true;
}
void MotionScene::functionfun1()
{
    
}

void MotionScene::afterFirstMotion(float dt)
{
    
}
