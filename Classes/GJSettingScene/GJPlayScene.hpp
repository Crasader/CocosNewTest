//
//  GJPlayScene.hpp
//  GitTest
//
//  Created by admin on 29/11/17.
//
//

#ifndef GJPlayScene_hpp
#define GJPlayScene_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class PlayScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    Sprite *blackBGSprite;
    Layer *subLayer;
    bool isPopupPresent = false;
    
    
    void PopCallback(cocos2d::Ref* pSender);
    void BackCallback(cocos2d::Ref* pSender);
    void CloseCallback(cocos2d::Ref* pSender);
    


    
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
};
#endif /* GJPlayScene_hpp */
