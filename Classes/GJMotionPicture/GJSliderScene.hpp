//
//  GJSliderScene.hpp
//  GitTest
//
//  Created by admin on 30/11/17.
//
//

#ifndef GJSliderScene_hpp
#define GJSliderScene_hpp

#include <stdio.h>
class SliderScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
    //    // a selector callback
    //    void menuCloseCallback(cocos2d::Ref* pSender);
    //   void SettingCallback(cocos2d::Ref* pSender);

    
    // implement the "static create()" method manually
    CREATE_FUNC(SliderScene);
};
#endif /* GJSliderScene_hpp */
