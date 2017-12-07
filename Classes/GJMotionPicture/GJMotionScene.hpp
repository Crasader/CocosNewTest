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
class MotionScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
//    // a selector callback
//    void menuCloseCallback(cocos2d::Ref* pSender);
//    void SettingCallback(cocos2d::Ref* pSender);
    void functionfun1();
    void afterFirstMotion(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MotionScene);
};
#endif /* GJMotionScene_hpp */
