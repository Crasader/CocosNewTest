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
#include "cocos2d.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
USING_NS_CC;


using namespace ui;
using namespace cocos2d;

class SliderScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    PageViewIndicator* _indicator;
    Label *_displayValueLabel;
//
    void pageViewEvent(Ref *pSender, PageViewEventType type);
    
    CREATE_FUNC(SliderScene);
};
#endif /* GJSliderScene_hpp */

