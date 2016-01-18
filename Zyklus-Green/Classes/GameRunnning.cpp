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
    
    
    //int bg_x = Bg->getPositionX();
    //int bg_y = Bg->getPositionY();
    
    schedule(schedule_selector(GameRunning::update),0.1f);
    
    return true;
}

void GameRunning::update(float delta)
{
    auto rootNode = CSLoader::createNode("GameScene.csb");
    auto Bg = rootNode->getChildByName("Bg");
    
    Bg->setVisible(false);
//    int y = Bg->getPositionY();
//    
//    
//    int speed=2;
//    
//    y -= speed;
    int y = 0;
    Bg->setPositionY(y);
//    CCSize size = m_sprite1->getContentSize();
//    if (X1<-size.width/2)
//    {
//        X2 = size.width/2;
//        X1=size.width/2+size.width;
//    }
//    if (X2<-size.width/2)
//    {
//        X1 = size.width/2;
//        X2=size.width/2+size.width;
//    }
//    m_sprite1->setPositionX(X1);
//    m_sprite2->setPositionX(X2);
}
