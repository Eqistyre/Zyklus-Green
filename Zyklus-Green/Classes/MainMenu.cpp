#include "MainMenu.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CCTransition.h"
#include "SceneManager.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainMenuScene.csb");
    auto MainMenuBtnLayer = CSLoader::createNode("MainMenuBtnLayer.csb");
    
    this->addChild(rootNode);
    rootNode->addChild(MainMenuBtnLayer);
    
    cocos2d::ui::Button* ExitBtn = (cocos2d::ui::Button*)MainMenuBtnLayer->getChildByName("ExitBtn");
    
    ExitBtn->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                SceneManager::sharedSceneManager()->changeScene(SceneManager::en_Black);
                exit(0);
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
        }
    });
    
    return true;
}
