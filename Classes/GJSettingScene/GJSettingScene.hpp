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


#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"


#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace ui;


using namespace cocos2d;

class SettingScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    //FadeTo* fade = FadeTo::create(1.0f,100);
    
    MoveTo *menuMoveEffect0;
    MoveTo *menuMoveEffect1;
    MoveTo *menuMoveEffect2;
    MoveTo *menuMoveEffect3;
    MoveTo *menuMoveEffect4;
    MoveTo *menuMoveEffect5;
    
    
    MoveTo *blackMoveEffect;
    MoveTo *blackMoveReverse;
    MoveTo *whiteMoveEffect;
    MoveTo *whiteMoveReverse;
    Sprite *black_bg;
    Sprite *white_bg;
    Sprite *bg;
    
    MenuItemLabel *MenuItem1;
    MenuItemLabel *MenuItem2;
    MenuItemLabel *MenuItem3;
    MenuItemLabel *MenuItem4;
    //auto MenuItem1;
    
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
    
    void GoalspageCallback(cocos2d::Ref* pSender);
    void SettingpageCallback(cocos2d::Ref* pSender);
    void StatspageCallback(cocos2d::Ref* pSender);
    void GooglepageCallback(cocos2d::Ref* pSender);
    
    
    ui::PageView *pageView;
    ui::PageView *bgpageView;
    void PlayClickCallback(cocos2d::Ref* pSender);
    
    void pageViewEvent(Ref *sender, ui::PageView::EventType type);
    
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    
  
    
    Layer *menuSettingLayer;

    // implement the "static create()" method manually
    CREATE_FUNC(SettingScene);
};
#endif /* GJSettingScene_hpp */

