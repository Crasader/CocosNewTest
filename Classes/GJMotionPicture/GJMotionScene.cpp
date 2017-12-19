//
//  GJMotionScene.cpp
//  GitTest
//
//  Created by admin on 29/11/17.
//
//

#include "GJMotionScene.hpp"
#include "GJGameScene.hpp"
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
    
   // label = Label::createWithSystemFont("hello","Arial.ttf",40);
    
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
        auto firstMPscale = ScaleTo::create(15, 1.2f);
        auto firstMPmove = MoveBy::create(60, Vec2(50,-50));
        auto firstMPmove1 = MoveBy::create(10, Vec2(-10,10));
        //auto MPfade_reverse = MPfade->reverse();
    
        motionSprite1->setOpacity(0);
        motionSprite1->runAction( firstMPscale);
        motionSprite1->runAction( Sequence::create( MPfade,firstMPmove,firstMPmove1, nullptr));
    
        //this->scheduleOnce(CC_SCHEDULE_SELECTOR(MotionScene::afterFirstMotion), 10.0f);
    
    
    
        charSprite1 = Sprite::create("Character1.png");
        charSprite1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        charSprite1->setScale(0);
        this->addChild(charSprite1, 1);
    
        charSprite2 = Sprite::create("Character2.png");
        charSprite2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        charSprite2->setScale(0);
        this->addChild(charSprite2, 1);
 

    this->MPLayer1 =Layer::create();
    this->addChild(MPLayer1,1);
    MPLayer1->setScale(0);
    auto motionSprite2 = Sprite::create("MP2.png");
    
    if (motionSprite2 == nullptr)
    {
        problemLoading("'MP2.png'");
    }
    else
    {
        motionSprite2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        motionSprite2->setScale(1.1);
        MPLayer1->addChild(motionSprite2, 0);
    }
    
    this->MPLayer2 =Layer::create();
    this->addChild(MPLayer2,2);
    MPLayer2->setScale(0);
    auto motionSprite3 = Sprite::create("MP3.png");
    
    if (motionSprite3 == nullptr)
    {
        problemLoading("'MP3.png'");
    }
    else
    {
        motionSprite3->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        motionSprite3->setScale(1.1);
        MPLayer2->addChild(motionSprite3, 0);
    }

    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(MotionScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(MotionScene::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(MotionScene::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(MotionScene::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    auto Back_btn = MenuItemImage::create(
                                          "PlayBtn.png",
                                          "PlayBtn.png",
                                          CC_CALLBACK_1(MotionScene::BackCallback, this));
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
    auto Setting_menu = Menu::create(Back_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    this->addChild(Setting_menu, 1);

   
    CCLOG("Entered ");
    return true;
}
void MotionScene::functionfun1()
{
    
}

void MotionScene::afterFirstMotion(float dt)
{
    CCLOG("comee");
}

bool MotionScene::onTouchBegan(Touch* touch, Event* event)
{
    cocos2d::log("touch begin");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    //label = LabelTTF::create("", "Arial", 40);
    label = Label::createWithSystemFont("hello","Arial.ttf",40);
    //label=Label::createWithTTF("", "fonts/Marker Felt.ttf", 50);
    Label_val++;
    if(Label_val==1)
    {
        
        label->setString("Label1");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
        
    }
    else if(Label_val==2)
    {
        label->setString("Label2");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
        
        
    }
    else if(Label_val==3)
    {
        label->setString("Label3");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
        
    }
    else if(Label_val==4)
    {
        charSprite1->setScale(1);
        charSprite2->setScale(0);
        label->setString("Label4");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
        
    }
    else if(Label_val==5)
    {
        charSprite1->setScale(0);
        charSprite2->setScale(1);
        label->setString("");
        label->setString("Label5");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==6)
    {
        charSprite1->setScale(1);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label6");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==7)
    {
        charSprite1->setScale(1);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label7");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==8)
    {
        charSprite1->setScale(1);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label8");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==9)
    {
        charSprite1->setScale(0);
        charSprite2->setScale(1);
        label->setString("");
        label->setString("Label9");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==10)
    {
        charSprite1->setScale(1);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label10");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==11)
    {
        charSprite1->setScale(1);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label11");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==12)
    {
        charSprite1->setScale(1);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label12");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==13)
    {
        charSprite1->setScale(0);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label13");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
        MPLayer1->setOpacity(0);
        
        auto MPfade = FadeIn::create(1.0f);
        auto firstMPmove = MoveBy::create(15, Vec2(-40,0));
   
        MPLayer1->runAction( Sequence::create( MPfade,firstMPmove, nullptr));

         MPLayer1->setScale(1);
    }
    else if(Label_val==14)
    {
        label->setString("");
        label->setString("Label14");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==15)
    {
        label->setString("");
        label->setString("Label15");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==16)
    {
        label->setString("");
        label->setString("Label16");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==17)
    {
        label->setString("");
        label->setString("Label17");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==18)
    {
        charSprite1->setScale(0);
        charSprite2->setScale(0);
        label->setString("");
        label->setString("Label13");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
        MPLayer2->setOpacity(0);
        
        auto MPfade = FadeIn::create(1.0f);
        auto firstMPmove = MoveBy::create(30, Vec2(-10,0));
        MPLayer2->runAction( Sequence::create( MPfade,firstMPmove, nullptr));
        
        MPLayer2->setScale(1);
    }
    else if(Label_val==19)
    {
        label->setString("");
        label->setString("Label19");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==20)
    {
        label->setString("");
        label->setString("Label20");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==21)
    {
        label->setString("");
        label->setString("Label21");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    else if(Label_val==22)
    {
        label->setString("");
        label->setString("Label22");
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/4));
    }
    this->addChild(label, 3);
    return true;
}
void MotionScene::BackCallback(Ref* pSender)
{
    CCLOG("Back");
    auto scene = GameScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
}

void MotionScene::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended");
}

void MotionScene::onTouchMoved(Touch* touch, Event* event)
{
    cocos2d::log("touch moved");
}

void MotionScene::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");
}
