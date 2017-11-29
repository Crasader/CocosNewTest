//
//  GJMenuScene.hpp
//  GitTest
//
//  Created by Winsols/Srinivas on 28/11/17.
//
//

#ifndef GJMenuScene_hpp
#define GJMenuScene_hpp

#include <stdio.h>
class MenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void VolumeCallback(cocos2d::Ref* pSender);
    void MuteCallback(cocos2d::Ref* pSender);
    void BackCallback(cocos2d::Ref* pSender);

    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};
#endif /* GJMenuScene_hpp */
