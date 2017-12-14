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
#include "cocos2d.h"
using namespace cocos2d;

class SettingScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
    MoveTo *blackMoveEffect;
    MoveTo *blackMoveReverse;
    MoveTo *whiteMoveEffect;
    MoveTo *whiteMoveReverse;
    Sprite *black_bg;
    Sprite *white_bg;
    Sprite *bg;
    
    Size visibleSize;
    Point origin;
    
    int add_val = 0;
    
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void SettingCallback(cocos2d::Ref* pSender);
    void PlayCallback(cocos2d::Ref* pSender);
    int getting_data_from_plist(int l,std::string s);
    
    void SoundCallback(cocos2d::Ref* pSender);
    void MusicCallback(cocos2d::Ref* pSender);
    void ChartCallback(cocos2d::Ref* pSender);
    void RateCallback(cocos2d::Ref* pSender);
    void AboutCallback(cocos2d::Ref* pSender);
    void CloseCallback(cocos2d::Ref* pSender);
    void glinkCallback(cocos2d::Ref* pSender);
    
    void ResumeCallback(cocos2d::Ref* pSender);
    void RestartCallback(cocos2d::Ref* pSender);
    void HomeCallback(cocos2d::Ref* pSender);
    
    
    
    Layer *menuSettingLayer;

    // implement the "static create()" method manually
    CREATE_FUNC(SettingScene);
};
#endif /* GJSettingScene_hpp */

