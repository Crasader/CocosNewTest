//
//  GJSettingScene.cpp
//  GitTest
//
//  Created by admin on 28/11/17.
//
//

#include "GJSettingScene.hpp"
#include "GJMenuScene.hpp"
#include "GJPlayScene.hpp"
#include "GJGameScene.hpp"
#include "SimpleAudioEngine.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace std;

Scene* SettingScene::createScene()
{
    return SettingScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SettingSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SettingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    this->menuSettingLayer =Layer::create();
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    CCLOG("Entered");


    ui::ImageView *bgview1 = ui::ImageView::create("BG.jpg");
    ui::ImageView *bgview2 = ui::ImageView::create("BG2.jpg");
    ui::ImageView *bgview3 = ui::ImageView::create("BG.jpg");
    bgview1->setAnchorPoint( Vec2( 0, 0 ) );
    bgview2->setAnchorPoint( Vec2( 0, 0 ) );
    bgview3->setAnchorPoint( Vec2( 0, 0 ) );

    bgpageView = ui::PageView::create();
    bgpageView->setTouchEnabled( true );
    bgpageView->setContentSize( Size( visibleSize.width,1536) );
    bgpageView->setPosition(Vec2(0, 0));
    //pageView->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height/2+origin.y));

    ui::Layout *layout1 = ui::Layout::create();
    //layout1->setContentSize( Size( visibleSize.width,visibleSize.height) );
    layout1->addChild(bgview1);

    ui::Layout *layout2 = ui::Layout::create();
    //layout2->setContentSize( Size( visibleSize.width,visibleSize.height) );
    layout2->addChild(bgview2);

    ui::Layout *layout3 = ui::Layout::create();
    //layout3->setContentSize( Size( visibleSize.width,visibleSize.height) );
    layout3->addChild(bgview3);

    bgpageView->addPage(layout1);
    bgpageView->insertPage(layout2,1);
    bgpageView->insertPage(layout3,2);

    this->addChild(bgpageView,5);

    auto Setting_btn3 = MenuItemImage::create(
                                              "Setting.png",
                                              "Setting.png",
                                              CC_CALLBACK_1(SettingScene::SettingCallback, this));
    Setting_btn3->setPosition(Vec2(origin.x + Setting_btn3->getContentSize().width*.6, visibleSize.height + origin.y-Setting_btn3->getContentSize().height*.6));

    auto Play_btn1 = MenuItemImage::create(
                                          "PlayBtn.png",
                                          "PlayBtn.png",
                                          CC_CALLBACK_1(SettingScene::PlayClickCallback, this));
    Play_btn1->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y+
                                                        visibleSize.height/2));


    auto Setting_menu3 = Menu::create(Setting_btn3,Play_btn1, NULL);
    Setting_menu3->setPosition(Vec2::ZERO);

    layout2->addChild(Setting_menu3,10);

 
//    PageView *pageView = PageView::create( );
//    pageView->setTouchEnabled( true );
//    pageView->setContentSize( Size( 240.0, 900.0 ) );
//    pageView->setAnchorPoint( Vec2( 0.5, 0.5 ) );
//
//    Layout *layout = Layout::create( );
//    layout->setContentSize( Size( 240.0, 900.0 ) );
//    // add a node to the layout (multiple nodes can be added to the layout)
//    layout->addChild( elementToAddToLayout );
//
//    // add a layout as a page
//    pageView->addPage( layout );
//    // add a layout as a page at a certain index
//    pageView->insertPage( layout, 1 );
//
//    // remove a particular page
//    pageView->removePageAtIndex( 0 );
//    // remove all the pages
//    pageView->removeAllPages( );
//
//    // scroll to a particular page
//    pageView->scrollToPage( 2 );
//
    
    
    
    //Sound Added
    //CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/BGM_MainMenu.mp3",true);
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto Coin = MenuItemImage::create(
                                           "Coin.png",
                                           "Coin.png",
                                           CC_CALLBACK_1(SettingScene::menuCloseCallback, this));
    
    if (Coin == nullptr ||
        Coin->getContentSize().width <= 0 ||
        Coin->getContentSize().height <= 0)
    {
        problemLoading("'Coin.png' and 'Coin.png'");
    }
    else
    {
         Coin->setPosition(Vec2(visibleSize.width + origin.x -Coin->getContentSize().width*.6, visibleSize.height + origin.y-Coin->getContentSize().height*.6));
    }
    
    // add "SettingScene" splash screen"
    
    bg = Sprite::create("BG.jpg");
    if (bg == nullptr)
    {
        problemLoading("'BG.jpg'");
    }
    else
    {
        bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
        this->addChild(bg, 0);
    }
    
    // add a "setting" icon to exit the progress. it's an autorelease object
    auto Setting_btn = MenuItemImage::create(
                                             "Setting.png",
                                             "Setting.png",
                                             CC_CALLBACK_1(SettingScene::SettingCallback, this));
    
    if (Setting_btn == nullptr ||
        Setting_btn->getContentSize().width <= 0 ||
        Setting_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting.png' and 'Setting.png'");
    }
    else
    {
        Setting_btn->setPosition(Vec2(origin.x + Setting_btn->getContentSize().width*.6, visibleSize.height + origin.y-Setting_btn->getContentSize().height*.6));
    }
    
    auto Play_btn = MenuItemImage::create(
                                             "Store.png",
                                             "Store.png",
                                             CC_CALLBACK_1(SettingScene::PlayCallback, this));
    
    if (Play_btn == nullptr ||
        Play_btn->getContentSize().width <= 0 ||
        Play_btn->getContentSize().height <= 0)
    {
        problemLoading("'Store.png' and 'Store.png'");
    }
    else
    {
         Play_btn->setPosition(Vec2(origin.x + Play_btn->getContentSize().width*.6, visibleSize.height + origin.y-Play_btn->getContentSize().height*1.8));
        //Play_btn->setPosition(Vec2(origin.x + visibleSize.width/2,
          //                         visibleSize.height*.25));
    }
    
    // create menu, it's an autorelease object
    
    auto Setting_menu = Menu::create(Setting_btn,Coin,Play_btn, NULL);
    Setting_menu->setPosition(Vec2::ZERO);
    this->addChild(Setting_menu, 1);
    

    ValueMap data;
    std::string path = FileUtils::getInstance()->fullPathForFilename("Plist/FirstPointArray.plist");
    data = FileUtils::getInstance()->getValueMapFromFile(path);
    
    ValueVector arrLevels = data.at("PointsArray").asValueVector();
    
    for (int i = 0; i<arrLevels.size(); i++)
    {
        
        std::string sdata = (arrLevels[i]).asString();
        
        Vec2 pos=PointFromString(sdata.c_str());
        
        CCLOG(" Value %s",sdata.c_str());
        CCLOG("Points x %f , y %f",pos.x,pos.y);
    }
    
  //  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Animation/bullet.plist","Animation/bulletani.png");
   // AnimationCache::getInstance()->addAnimationsWithFile("Animation/animation.plist");
  //  auto bullet1 = Sprite::createWithSpriteFrameName("0.png");
  //  bullet1->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    //this->addChild(bullet1,100);
    //bullet1->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("animation_1"))));
    
//    //Frame Animation
//    Sprite *birdAnimSpr = Sprite::createWithSpriteFrameName("0.png");
//    //call idle animation
//    birdAnimSpr->setPosition(Vec2(this->getContentSize().width/2,this->getContentSize().height/2));
//    this->addChild(birdAnimSpr);
//    birdAnimSpr->setName("birdAnim");
//    
//    Vector<SpriteFrame*> animFrames(120);
//    
//    char str[120] = {0};
//    for(int i = 1; i < 8; i++)
//    {
//        sprintf(str, "%s%d.png","Pigeon-animation_",i);
//        
//        auto frame = AnimationCache->getSpriteFrameByName(str);
//        animFrames.pushBack(frame);
//    }
//    Animation *_birdAnim = Animation::createWithSpriteFrames(animFrames, 0.09f);
//    RepeatForever *moveAction=RepeatForever::create(Animate::create(_birdAnim));
//    moveAction->setTag(6);
//    
//    birdAnimSpr->runAction(moveAction);
    
//    ////////////////
//    
//    Vector< SpriteFrame*> _walkFrames;
//    Animation* _walkAnimation;
//    Animate* _walkAction;
//    
//    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
//    cache->addSpriteFramesWithFile("frames.plist"); // relative
//    
//    
//    for (int i = 0; i <= 1; i++)
//    {
//        std::string num = StringUtils::format("%d", i);
//        _walkFrames.pushBack(cache->getSpriteFrameByName(num + ".png"));
//    }
//    
//    // create the animation out of the frames and an action for the new animation
//    
//    _walkAnimation = Animation::createWithSpriteFrames(_walkFrames, 0.02f);
//    _walkAnimation->retain();
//    
//    // use/run the animation
//    
//    auto walk = Animate::create(_walkAnimation);
//    _legsSprite->runAction(RepeatForever::create(walk));

    
    black_bg = Sprite::create("menu1.png");
    //black_bg->setOpacity(200);
    //black_bg->setPosition(Vec2(origin.x + black_bg->getContentSize().width/2, visibleSize.height/2));
    black_bg->setPosition(Vec2(origin.x - black_bg->getContentSize().width/2, visibleSize.height/2));
    this->addChild(black_bg, 16);
    
    white_bg = Sprite::create("menu2.png");
    //white_bg->setOpacity(200);
    white_bg->setPosition(Vec2(origin.x + ((black_bg->getContentSize().width/2)*16), visibleSize.height/2));
    this->addChild(white_bg, 15);
    
    this->menuSettingLayer =Layer::create();
    //bg->setOpacity(50);
    

    auto Resume_btn = MenuItemImage::create(
                                            "Resume.png",
                                            "Resume.png",
                                            CC_CALLBACK_1(SettingScene::ResumeCallback, this));
    Resume_btn->setPosition(Vec2(origin.x + black_bg->getContentSize().width/2, black_bg->getContentSize().height*.20));
    
    auto Restart_btn = MenuItemImage::create(
                                             "Restart.png",
                                             "Restart.png",
                                             CC_CALLBACK_1(SettingScene::RestartCallback, this));
    Restart_btn->setPosition(Vec2(origin.x + black_bg->getContentSize().width/2, black_bg->getContentSize().height*.30));
    
    auto Home_btn = MenuItemImage::create(
                                          "Home.png",
                                          "Home.png",
                                          CC_CALLBACK_1(SettingScene::HomeCallback, this));
    Home_btn->setPosition(Vec2(origin.x + black_bg->getContentSize().width/2, black_bg->getContentSize().height*.40));
    
    auto labelCoin = Label::createWithTTF("Coin", "fonts/Marker Felt.ttf", 30);
    labelCoin->setPosition(Vec2(origin.x + black_bg->getContentSize().width/2, black_bg->getContentSize().height*.90));
    black_bg->addChild(labelCoin, 1);
    
    auto labelDistance = Label::createWithTTF("0", "fonts/Marker Felt.ttf", 30);
    labelDistance->setPosition(Vec2(origin.x + black_bg->getContentSize().width/2, black_bg->getContentSize().height*.80));
    black_bg->addChild(labelDistance, 1);
    
    auto Black_menu = Menu::create(Resume_btn,Restart_btn,Home_btn, NULL);
    Black_menu->setPosition(Vec2::ZERO);
    black_bg->addChild(Black_menu, 1);
 
    auto sett_menu = Sprite::create("settinglabel.png");
    
    ui::ImageView *imgview1 = ui::ImageView::create("menu2.jpg");
    ui::ImageView *imgview2 = ui::ImageView::create("menu2.jpg");
    ui::ImageView *imgview3 = ui::ImageView::create("menu2.jpg");
    ui::ImageView *imgview4 = ui::ImageView::create("menu2.jpg");
    imgview1->setAnchorPoint( Vec2( 0, 0 ) );
    imgview2->setAnchorPoint( Vec2( 0, 0 ) );
    imgview3->setAnchorPoint( Vec2( 0, 0 ) );
    imgview4->setAnchorPoint( Vec2( 0, 0 ) );
    
    imgview1->setOpacity(200);
    imgview2->setOpacity(200);
    imgview3->setOpacity(200);
    imgview4->setOpacity(200);
    
    pageView = ui::PageView::create();
    pageView->setTouchEnabled( true );
    pageView->setContentSize( Size( white_bg->getContentSize().width,(white_bg->getContentSize().height)*.85) );
    //pageView->setPosition(Vec2(visibleSize.width/2+origin.x, visibleSize.height/2+origin.y));

    ui::Layout *menuItem1 = ui::Layout::create();
    //layout1->setContentSize( Size( visibleSize.width,visibleSize.height) );
    menuItem1->addChild(imgview1);

    ui::Layout *menuItem2 = ui::Layout::create();
    //layout2->setContentSize( Size( visibleSize.width,visibleSize.height) );
    menuItem2->addChild(imgview2);

    ui::Layout *menuItem3 = ui::Layout::create();
    //layout3->setContentSize( Size( visibleSize.width,visibleSize.height) );
    menuItem3->addChild(imgview3);

    ui::Layout *menuItem4 = ui::Layout::create();
    //layout3->setContentSize( Size( visibleSize.width,visibleSize.height) );
    menuItem4->addChild(imgview4);
    

    pageView->addPage(menuItem1);
    pageView->insertPage(menuItem2,1);
    pageView->insertPage(menuItem3,2);
    pageView->insertPage(menuItem4,3);

    white_bg->addChild(pageView,5);

    auto menuName = Label::createWithTTF("Goals", "fonts/Marker Felt.ttf", 60);
    menuName->setPosition( Vec2( ((menuItem1->getContentSize( ).width/2)), menuItem1->getContentSize( ).height*.80) );
    menuName->setTextColor(Color4B::WHITE);
    menuName->enableOutline(Color4B::RED,3);
    //menuItem1->addChild(menuName, 1);

    auto labelitem1 = Label::createWithTTF("Land a backflip", "fonts/Marker Felt.ttf", 30);
    auto labelitem2 = Label::createWithTTF("Grind a bunting line", "fonts/Marker Felt.ttf", 30);
    auto labelitem3 = Label::createWithTTF("Jump across a chasm", "fonts/Marker Felt.ttf", 30);
    labelitem1->setPosition( Vec2( (menuItem1->getContentSize( ).width/2), menuItem1->getContentSize( ).height*.70) );
    labelitem2->setPosition( Vec2( (menuItem1->getContentSize( ).width/2), menuItem1->getContentSize( ).height*.60) );
    labelitem3->setPosition( Vec2( ((menuItem1->getContentSize( ).width/2)), menuItem1->getContentSize( ).height*.50) );

    labelitem1->setTextColor(Color4B::BLACK);
    labelitem2->setTextColor(Color4B::BLACK);
    labelitem3->setTextColor(Color4B::BLACK);
    menuItem1->addChild(labelitem1, 1);
    menuItem1->addChild(labelitem2, 1);
    menuItem1->addChild(labelitem3, 1);
//
//    white_bg->addChild( settingpageView,5 );
    
    auto SettingPanel = Sprite::create("Setting/SettingPanel.png");
    menuSettingLayer->addChild(SettingPanel, 10);
    menuSettingLayer->setPosition( Vec2( ((menuItem2->getContentSize( ).width/2)), menuItem2->getContentSize( ).height / 2) );
    menuItem2->addChild(menuSettingLayer,11);



    auto Sound_btn = MenuItemImage::create(
                                           "Setting/SoundOn.png",
                                           "Setting/SoundOff.png",
                                           CC_CALLBACK_1(SettingScene::SoundCallback, this));

    if (Sound_btn == nullptr ||
        Sound_btn->getContentSize().width <= 0 ||
        Sound_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/SoundOn.png' and 'Setting/SoundOff.png'");
    }
    else
    {
        Sound_btn->setPosition(Vec2(visibleSize.width*.30, visibleSize.height*.63));
    }

    auto Music_btn = MenuItemImage::create(
                                           "Setting/MusicOn.png",
                                           "Setting/MusicOff.png",
                                           CC_CALLBACK_1(SettingScene::MusicCallback, this));


    if (Music_btn == nullptr ||
        Music_btn->getContentSize().width <= 0 ||
        Music_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/MusicOn.png' and 'Setting/MusicOff.png'");
    }
    else
    {
        Music_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-(Music_btn->getContentSize().height*1.20)));
    }

    auto Chart_btn = MenuItemImage::create(
                                           "Setting/Chart.png",
                                           "Setting/Chart.png",
                                           CC_CALLBACK_1(SettingScene::ChartCallback, this));


    if (Chart_btn == nullptr ||
        Chart_btn->getContentSize().width <= 0 ||
        Chart_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/Chart.png' and 'Setting/Chart.png'");
    }
    else
    {
        Chart_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*2)));
    }

    auto Rate_btn = MenuItemImage::create(
                                          "Setting/Rate.png",
                                          "Setting/Rate.png",
                                          CC_CALLBACK_1(SettingScene::RateCallback, this));


    if (Rate_btn == nullptr ||
        Rate_btn->getContentSize().width <= 0 ||
        Rate_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/Rate.png' and 'Setting/Rate.png'");
    }
    else
    {
        Rate_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-((Rate_btn->getContentSize().height*1.20)*3)));
    }

    auto About_btn = MenuItemImage::create(
                                           "Setting/About.png",
                                           "Setting/About.png",
                                           CC_CALLBACK_1(SettingScene::AboutCallback, this));


    if (About_btn == nullptr ||
        About_btn->getContentSize().width <= 0 ||
        About_btn->getContentSize().height <= 0)
    {
        problemLoading("'Setting/About.png' and 'Setting/About.png'");
    }
    else
    {
        About_btn->setPosition(Vec2(visibleSize.width*.30, (visibleSize.height*.63)-((About_btn->getContentSize().height*1.20)*4)));
    }




    auto Setting_menu1 = Menu::create(Sound_btn,Music_btn,Chart_btn,Rate_btn,About_btn, NULL);
    Setting_menu1->setPosition(Vec2::ZERO);
    SettingPanel->addChild(Setting_menu1, 1);

    auto Settings_label = Label::createWithTTF("SETTINGS", "fonts/Marker Felt.ttf", 60);
    Settings_label->setPosition(Vec2(visibleSize.width*.25,visibleSize.height*.78));
    Settings_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    Settings_label->setTextColor(Color4B::WHITE);
    Settings_label->enableOutline(Color4B::RED,3);
    //SettingPanel->addChild(Settings_label, 1);

    auto Sound_label = Label::createWithTTF("SOUND", "fonts/Marker Felt.ttf", 40);
    Sound_label->setPosition(Vec2(visibleSize.width*.12, visibleSize.height*.63));
    Sound_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    Sound_label->setAnchorPoint(Vec2(0, 0.5f));
    SettingPanel->addChild(Sound_label, 1);

    auto Music_label = Label::createWithTTF("MUSIC", "fonts/Marker Felt.ttf", 40);
    Music_label->setPosition(Vec2(visibleSize.width*.12, (visibleSize.height*.63)-(Music_btn->getContentSize().height*1.20)));
    Music_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    Music_label->setAnchorPoint(Vec2(0, 0.5f));
    SettingPanel->addChild(Music_label, 1);

    auto Chart_label = Label::createWithTTF("CHART", "fonts/Marker Felt.ttf", 40);
    Chart_label->setPosition(Vec2(visibleSize.width*.12, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*2)));
    Chart_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    Chart_label->setAnchorPoint(Vec2(0, 0.5f));
    SettingPanel->addChild(Chart_label, 1);

    auto Rate_label = Label::createWithTTF("RATE US", "fonts/Marker Felt.ttf", 40);
    Rate_label->setPosition(Vec2(visibleSize.width*.12, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*3)));
    Rate_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    Rate_label->setAnchorPoint(Vec2(0, 0.5f));
    SettingPanel->addChild(Rate_label, 1);

    auto About_label = Label::createWithTTF("ABOUT", "fonts/Marker Felt.ttf", 40);
    About_label->setPosition(Vec2(visibleSize.width*.12, (visibleSize.height*.63)-((Chart_btn->getContentSize().height*1.20)*4)));
    About_label->setHorizontalAlignment(TextHAlignment::RIGHT);
    About_label->setAnchorPoint(Vec2(0, 0.5f));
    SettingPanel->addChild(About_label, 1);
    



    ui::ScrollView *scrollView1 = ui::ScrollView::create( );

    scrollView1->setDirection( ui::ScrollView::Direction::VERTICAL );
    scrollView1->setContentSize( Size( white_bg->getContentSize().width/2, white_bg->getContentSize().height/2 ) );
    scrollView1->setInnerContainerSize( Size( white_bg->getContentSize().width/2, sett_menu->getContentSize().height*8) );

    scrollView1->setBackGroundColor(Color3B(221,243,255));
    scrollView1->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);

    //scrollView1->setBackGroundImage( "menu1.png" );
    scrollView1->setBounceEnabled( true );
    scrollView1->setAnchorPoint( Vec2( 0.5, 0.5 ) );
    scrollView1->setPosition( Vec2( white_bg->getContentSize().width/2 + origin.x, white_bg->getContentSize().height/2 + origin.y) );

    //auto arrayName[2]= {1, 2};

    for ( int i = 1; i <= 8; i++ )
    {
        ui::Button *button;
        if(i%2==0)
        {
            button = ui::Button::create( "settinglabel.png", "settinglabel3.png" );
        }
        else
        {
            button = ui::Button::create( "settinglabel1.png", "settinglabel2.png" );
        }
        //button->setPosition(Vec2(scrollView1->getContentSize().width / 2, origin.y+Back_btn->getContentSize().height*.6));
        button->setPosition(Vec2(scrollView1->getContentSize().width / 2,(((sett_menu->getContentSize().height*8)-(sett_menu->getContentSize().height/2)*(i+(i-1))))));
        scrollView1->addChild( button );

        std::vector<std::string> labelArr = {"","Best Combo", "Best score", "Best distance", "Meters travelled", "Times jumped","Rocks smashed","Rock bounced","Rock hit","Highest Jump"};
        auto label = Label::createWithTTF(labelArr.at(i), "fonts/Marker Felt.ttf", 30);
        label->setPosition(Vec2(scrollView1->getContentSize().width*.10,(((sett_menu->getContentSize().height*8)-(sett_menu->getContentSize().height/2)*(i+(i-1))))));
        //label -> setAnchorPoint( Point::ANCHOR_BOTTOM_LEFT );
        label->setAnchorPoint(Vec2(0, 0.5f));
        label->setHorizontalAlignment(TextHAlignment::LEFT);
        label->setVerticalAlignment(TextVAlignment::BOTTOM);
        scrollView1->addChild( label );

        std::vector<std::string> labelValArr = {"","0", "0", "0m", "0m", "0","0","0","0","0m"};

        auto labelVal = Label::createWithTTF(labelValArr.at(i), "fonts/Marker Felt.ttf", 30);
        labelVal->setPosition(Vec2(scrollView1->getContentSize().width*.90,(((sett_menu->getContentSize().height*8)-(sett_menu->getContentSize().height/2)*(i+(i-1))))));
        //label -> setAnchorPoint( Point::ANCHOR_BOTTOM_LEFT );
        labelVal->setAnchorPoint(Vec2(0, 0.5f));
        labelVal->setHorizontalAlignment(TextHAlignment::LEFT);
        labelVal->setVerticalAlignment(TextVAlignment::BOTTOM);
        scrollView1->addChild( labelVal );
    }
    
    auto menuName3 = Label::createWithTTF("Stats", "fonts/Marker Felt.ttf", 60);
    menuName3->setPosition( Vec2( ((menuItem3->getContentSize( ).width/2)), menuItem3->getContentSize( ).height*.80) );
    menuName3->setTextColor(Color4B::WHITE);
    menuName3->enableOutline(Color4B::RED,3);
    //menuItem3->addChild(menuName3, 0);


    scrollView1->setPosition( Vec2( ((menuItem3->getContentSize( ).width/2)), menuItem3->getContentSize( ).height / 2) );
    menuItem3->addChild( scrollView1 );
    
    auto menuName4 = Label::createWithTTF("Google Play", "fonts/Marker Felt.ttf", 60);
    menuName4->setPosition( Vec2( ((menuItem4->getContentSize( ).width/2)), menuItem4->getContentSize( ).height*.80) );
    menuName4->setTextColor(Color4B::WHITE);
    menuName4->enableOutline(Color4B::RED,3);
    //menuItem4->addChild(menuName4, 0);


    auto labelMessage = Label::createWithTTF("Sign in to Google Play to\n complete with friends!", "fonts/Marker Felt.ttf", 40);
    labelMessage->setPosition( Vec2( ((menuItem4->getContentSize( ).width/2)), menuItem4->getContentSize( ).height*.60) );
    labelMessage->setTextColor(Color4B::BLACK);
    menuItem4->addChild(labelMessage, 0);

    auto Google_btn = MenuItemImage::create(
                                            "Googleplay.png",
                                            "Googleplay.png",
                                            CC_CALLBACK_1(SettingScene::glinkCallback, this));
    Google_btn->setPosition( Vec2( ((menuItem4->getContentSize( ).width/2)), menuItem4->getContentSize( ).height*.30) );


    auto glink_menu = Menu::create(Google_btn, NULL);
    glink_menu->setPosition(Vec2::ZERO);
    menuItem4->addChild(glink_menu, 1);
    
    
    
    auto menuLabel1 = Label::createWithTTF("Goals", "fonts/Marker Felt.ttf", 60);
    menuLabel1->setTextColor(Color4B::WHITE);
    menuLabel1->enableOutline(Color4B::RED,3);
    
    MenuItem1 = MenuItemLabel::create(menuLabel1, CC_CALLBACK_1(SettingScene::GoalspageCallback, this));
    MenuItem1->setPosition( Vec2( ((white_bg->getContentSize( ).width/2)), white_bg->getContentSize( ).height*.90) );
    
    
    auto menuLabel2 = Label::createWithTTF("Setting", "fonts/Marker Felt.ttf", 60);
    menuLabel2->setTextColor(Color4B::WHITE);
    menuLabel2->enableOutline(Color4B::RED,3);
    
    MenuItem2 = MenuItemLabel::create(menuLabel2, CC_CALLBACK_1(SettingScene::SettingpageCallback, this));
    //MenuItem2->setPosition( Vec2( ((white_bg->getContentSize( ).width/2)+white_bg->getContentSize( ).width/4), white_bg->getContentSize( ).height*.90) );
    MenuItem2->setPosition( Vec2( ((white_bg->getContentSize( ).width/2)*2), white_bg->getContentSize( ).height*.90) );
    
    
    
    auto menuLabel3 = Label::createWithTTF("Stats", "fonts/Marker Felt.ttf", 60);
    menuLabel3->setTextColor(Color4B::WHITE);
    menuLabel3->enableOutline(Color4B::RED,3);
    
    MenuItem3 = MenuItemLabel::create(menuLabel3, CC_CALLBACK_1(SettingScene::StatspageCallback, this));
    MenuItem3->setPosition( Vec2( ((white_bg->getContentSize( ).width/2)*3), white_bg->getContentSize( ).height*.90) );
    
    
    auto menuLabel4 = Label::createWithTTF("GooglePlay", "fonts/Marker Felt.ttf", 60);
    menuLabel4->setTextColor(Color4B::WHITE);
    menuLabel4->enableOutline(Color4B::RED,3);

    
    MenuItem4 = MenuItemLabel::create(menuLabel4, CC_CALLBACK_1(SettingScene::GooglepageCallback, this));
    MenuItem4->setPosition( Vec2( ((white_bg->getContentSize( ).width/2)*4), white_bg->getContentSize( ).height*.90) );
    
    
    auto menu = Menu::create(MenuItem1,MenuItem2,MenuItem3,MenuItem4, nullptr);
    menu->setPosition(Vec2::ZERO);
    white_bg->addChild(menu, 1);

    pageView->addEventListener(CC_CALLBACK_2(SettingScene::pageViewEvent,this));
    
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(SettingScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(SettingScene::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(SettingScene::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(SettingScene::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, imgview1);
    
    MenuItem1->setOpacity(255);
    MenuItem2->setOpacity(50);
    MenuItem3->setOpacity(50);
    MenuItem4->setOpacity(50);
    
    return true;
}
bool SettingScene::onTouchBegan(Touch* touch, Event* event)
{
    CCLOG("begin");
    auto pos = convertToWorldSpace(MenuItem1->getPosition());
    auto pos1 = MenuItem1->getPosition();
    CCLOG("Points x %f , y %f",pos.x,pos.y);
    CCLOG("Points x %f , y %f",pos1.x,pos1.y);
    cocos2d::log("touch begin");
    return true;
}
void SettingScene::onTouchEnded(Touch* touch, Event* event)
{
    cocos2d::log("touch ended");
}
void SettingScene::onTouchMoved(Touch* touch, Event* event)
{
    CCLOG("moved");
    cocos2d::log("touch moved");
}
void SettingScene::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");
}
void SettingScene::menuCloseCallback(Ref* pSender)
{
    CCLOG("CLOSE");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/SFX_ButtonClick.wav");
    
}
void SettingScene::SettingCallback(Ref* pSender)
{
    CCLOG("SETTING");
    
    blackMoveEffect = MoveTo::create(1, Vec2(origin.x + black_bg->getContentSize().width/2, visibleSize.height/2));
    
    
    black_bg->runAction( blackMoveEffect);
    
    whiteMoveEffect = MoveTo::create(1, Vec2(origin.x + ((black_bg->getContentSize().width/2)*5), visibleSize.height/2));
    
    
    white_bg->runAction( whiteMoveEffect);

    
}
void SettingScene::PlayCallback(Ref* pSender)
{
//    CCLOG("Play");
//    auto scene = PlayScene::createScene();
//    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
//    Director::getInstance()->replaceScene(transition);

}
void SettingScene::SoundCallback(Ref* pSender)
{
    CCLOG("Sound");
}
void SettingScene::MusicCallback(Ref* pSender)
{
    CCLOG("Music");
}
void SettingScene::ChartCallback(Ref* pSender)
{
    CCLOG("Chart");
}
void SettingScene::RateCallback(Ref* pSender)
{
    CCLOG("Rate");
}
void SettingScene::AboutCallback(Ref* pSender)
{
    CCLOG("About");
}
void SettingScene::CloseCallback(Ref* pSender)
{
    CCLOG("Back");
}
void SettingScene::ResumeCallback(Ref* pSender)
{
    CCLOG("Resume");
    blackMoveReverse = MoveTo::create(1, Vec2(origin.x - black_bg->getContentSize().width/2, visibleSize.height/2));
    
    black_bg->runAction( blackMoveReverse);
    
    whiteMoveReverse = MoveTo::create(1, Vec2(origin.x + ((black_bg->getContentSize().width/2)*16), visibleSize.height/2));
    white_bg->runAction( whiteMoveReverse);
    
    //bg->setOpacity(255);
}
void SettingScene::RestartCallback(Ref* pSender)
{
    CCLOG("Restart");
    auto scene = GameScene::createScene();
    cocos2d::TransitionFade* transition = cocos2d::TransitionFade::create(.5, scene);
    Director::getInstance()->replaceScene(transition);
}
void SettingScene::HomeCallback(Ref* pSender)
{
    CCLOG("Home");
    pageView->setScale(1);
    black_bg->setPosition(Vec2(origin.x - black_bg->getContentSize().width/2, visibleSize.height/2));
    white_bg->setPosition(Vec2(origin.x + ((black_bg->getContentSize().width/2)*16), visibleSize.height/2));
}
void SettingScene::glinkCallback(Ref* pSender)
{
    CCLOG("Google_Link");
    Application::getInstance()->openURL("https://play.google.com/store?");
}
void SettingScene::PlayClickCallback(Ref* pSender)
{
    CCLOG("play_clk");
    bgpageView->setScale(0);
}
void SettingScene::GoalspageCallback(Ref* pSender)
{
    //auto page = pageView->getCurrentPageIndex();
    
    MenuItem1->runAction(FadeTo::create(0.5f,255));
    MenuItem2->runAction(FadeTo::create(0.5f,50));

    //if(page!=0)
    {
        pageView->scrollToPage(0);
        menuMoveEffect0 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*-1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect1 = MoveTo::create(0.5, Vec2(0,white_bg->getContentSize( ).height*.90));
        menuMoveEffect2 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect3 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*2),white_bg->getContentSize( ).height*.90));
        menuMoveEffect4 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*3),white_bg->getContentSize( ).height*.90));
        menuMoveEffect5 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*4),white_bg->getContentSize( ).height*.90));

        MenuItem1->runAction( menuMoveEffect2);
        MenuItem2->runAction( menuMoveEffect3);
        MenuItem3->runAction( menuMoveEffect4);
        MenuItem4->runAction( menuMoveEffect5);
    }
}
void SettingScene::SettingpageCallback(Ref* pSender)
{
        MenuItem1->runAction(FadeTo::create(0.5f,50));
        MenuItem2->runAction(FadeTo::create(0.5f,255));
        MenuItem3->runAction(FadeTo::create(0.5f,50));
    

    //auto page = pageView->getCurrentPageIndex();
    //if(page!=1)
    {
        menuMoveEffect0 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*-1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect1 = MoveTo::create(0.5, Vec2(0,white_bg->getContentSize( ).height*.90));
        menuMoveEffect2 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect3 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*2),white_bg->getContentSize( ).height*.90));
        menuMoveEffect4 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*3),white_bg->getContentSize( ).height*.90));
        menuMoveEffect5 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*4),white_bg->getContentSize( ).height*.90));
        
        
        pageView->scrollToPage(1);
        MenuItem1->runAction( menuMoveEffect1);
        MenuItem2->runAction( menuMoveEffect2);
        MenuItem3->runAction( menuMoveEffect3);
        MenuItem4->runAction( menuMoveEffect4);
    }
}
void SettingScene::StatspageCallback(Ref* pSender)
{
    
        MenuItem2->runAction(FadeTo::create(0.5f,50));
        MenuItem3->runAction(FadeTo::create(0.5f,255));
        MenuItem4->runAction(FadeTo::create(0.5f,50));
    
    //auto page = pageView->getCurrentPageIndex();
    //if(page!=2)
    {
        menuMoveEffect0 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*-1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect1 = MoveTo::create(0.5, Vec2(0,white_bg->getContentSize( ).height*.90));
        menuMoveEffect2 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect3 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*2),white_bg->getContentSize( ).height*.90));
        menuMoveEffect4 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*3),white_bg->getContentSize( ).height*.90));
        menuMoveEffect5 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*4),white_bg->getContentSize( ).height*.90));
        pageView->scrollToPage(2);

        MenuItem1->runAction( menuMoveEffect0);
        MenuItem2->runAction( menuMoveEffect1);
        MenuItem3->runAction( menuMoveEffect2);
        MenuItem4->runAction( menuMoveEffect3);
    }
}
void SettingScene::GooglepageCallback(Ref* pSender)
{
    
        MenuItem3->runAction(FadeTo::create(0.5f,50));
        MenuItem4->runAction(FadeTo::create(0.5f,255));
    
    //auto page = pageView->getCurrentPageIndex();
    //if(page!=3)
    {
        menuMoveEffect0 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*-1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect1 = MoveTo::create(0.5, Vec2(0,white_bg->getContentSize( ).height*.90));
        menuMoveEffect2 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*1),white_bg->getContentSize( ).height*.90));
        menuMoveEffect3 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*2),white_bg->getContentSize( ).height*.90));
        menuMoveEffect4 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*3),white_bg->getContentSize( ).height*.90));
        menuMoveEffect5 = MoveTo::create(0.5, Vec2(((white_bg->getContentSize( ).width/2)*4),white_bg->getContentSize( ).height*.90));
        
        
        pageView->scrollToPage(3);
        MenuItem1->runAction( menuMoveEffect0);
        MenuItem2->runAction( menuMoveEffect0);
        MenuItem3->runAction( menuMoveEffect1);
        MenuItem4->runAction( menuMoveEffect2);
    }
}
void SettingScene::pageViewEvent(Ref *sender, ui::PageView::EventType type)
{
    pageView = dynamic_cast<ui::PageView *>(sender);
    switch(type)
    {
        case ui::PageView::EventType::TURNING:
            log("%zi",pageView->getCurrentPageIndex());
            break;

            default:
            break;
    }
}

