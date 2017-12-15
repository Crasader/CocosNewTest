//
//  GJMotionScene.hpp
//  GitTest
//
//  Created by admin on 29/11/17.
//
//

#ifndef GJMotionScene_hpp
#define GJMotionScene_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class MotionScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    int Label_val = 0;
   
    Sprite *charSprite1;
    Sprite *charSprite2;
    Sprite *mpSprite;
    
    Label *label;
    //cocos2d::LabelTTF* label;
    
    Layer *MPLayer1;
    Layer *MPLayer2;

    void functionfun1();
    void afterFirstMotion(float dt);
    
    void BackCallback(cocos2d::Ref* pSender);
    
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

    
    // implement the "static create()" method manually
    CREATE_FUNC(MotionScene);
};
#endif /* GJMotionScene_hpp */


