//
//  GJSettingScene.hpp
//  GitTest
//
//  Created by admin on 28/11/17.
//
//

#ifndef GJSettingScene_hpp
#define GJSettingScene_hpp

#include <stdio.h>

class SettingScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SettingScene);
};
#endif /* GJSettingScene_hpp */
