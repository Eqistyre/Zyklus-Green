//
//  GameRunnning.cpp
//  Zyklus-Green
//
//  Created by 张仲昊 on 16/1/18.
//
//

#include "GameRunnning.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameRunning::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameRunning::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameRunning::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("GameScene.csb");
    addChild(rootNode);

    Bg1 = (cocos2d::ui::ImageView*)rootNode->getChildByName("Bg1");
    Bg2 = (cocos2d::ui::ImageView*)rootNode->getChildByName("Bg2");
//
//    cocos2d::ui::ImageView* Bg = (cocos2d::ui::ImageView*)rootNode->getChildByName("Bg");
//    
//    Bg->setVisible(false);
    //int bg_x = Bg->getPositionX();
    //int bg_y = Bg->getPositionY();
    
    schedule(schedule_selector(GameRunning::update),0.02f);
    
    return true;
}

void GameRunning::update(float delta)
{
    int y1 = Bg1->getPositionY();
    int y2 = Bg2->getPositionY();
    
    int speed = 5;
    log("y1%d",y1);
    y1 -= speed;
    Bg1->setPositionY(y1);
    
    //Unlimited
    log("y2%d",y2);
    if (y1 <= -3000) {
        y2 -= speed;
        Bg2->setPositionY(y2);
        if (y2 <= -3000) {
            y1 = -3000;
            Bg1->setPositionY(y1);
            y2 = 750;
            Bg2->setPositionY(y2);
            
        }
    }
//    //cocos2d::ui::ImageView* Bg = (cocos2d::ui::ImageView*)rootNode->getChildByName("Bg");
//    
//    //Bg->setVisible(false);
//    
//    int y = Bg->getPositionY();
////    y -= 2;
////    Bg->setPositionY(y);
//    
////    auto rootNode = CSLoader::createNode("GameScene.csb");
////    auto Bg = rootNode->getChildByName("Bg");
////    
////    Bg->setVisible(false);
////    int y = Bg->getPositionY();
////    
////    
////    int speed=2;
////    
////    y -= speed;
////    int y = 0;
////    Bg->setPositionY(y);
//
//    log("asd");
//    
////    CCSize size = m_sprite1->getContentSize();
////    if (X1<-size.width/2)
////    {
////        X2 = size.width/2;
////        X1=size.width/2+size.width;
////    }
////    if (X2<-size.width/2)
////    {
////        X1 = size.width/2;
////        X2=size.width/2+size.width;
////    }
////    m_sprite1->setPositionX(X1);
////    m_sprite2->setPositionX(X2);
}
