//
//  Black.cpp
//  Zyklus-Green
//
//  Created by 张仲昊 on 16/1/17.
//
//

#include "Black.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* Black::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Black::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Black::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("BlackScene.csb");
    
    addChild(rootNode);
    
    return true;
}

void Black::stopSeconds(float dt) {
    log("Running");
    exit(0);
}
