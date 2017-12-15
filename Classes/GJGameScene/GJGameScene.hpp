//
//  GameScene.hpp
//  GitTest
//
//  Created by Winsols on 15/12/17.
//

#ifndef GJGameScene_hpp
#define GJGameScene_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();

    void MotionCallback(cocos2d::Ref* pSender);
    void MenuCallback(cocos2d::Ref* pSender);
    void PlayCallback(cocos2d::Ref* pSender);
    void PageViewCallback(cocos2d::Ref* pSender);
    
    
//    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
//    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
//    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
//    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};
#endif /* GJGameScene_hpp */


