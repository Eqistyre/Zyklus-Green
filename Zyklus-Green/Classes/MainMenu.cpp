#include "MainMenu.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CCTransition.h"
#include "SceneManager.h"
#include "Black.h"
#include "SoundManager.h"

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
    
    //player background music
    SoundManager::shareSoundManager()->playBackgroundMusic("V.A. - 120円の春オルゴール.mp3", true);
    
    auto MainSceneSettingLayer = CSLoader::createNode("MainSceneSettingLayer.csb");
    this->addChild(MainSceneSettingLayer);
    MainSceneSettingLayer->setVisible(false);
    
    
    cocos2d::ui::Button* StartBtn = (cocos2d::ui::Button*)MainMenuBtnLayer->getChildByName("StartBtn");
    StartBtn->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                SoundManager::shareSoundManager()->playEffect("木牌.wav");
                SceneManager::sharedSceneManager()->MTransitionFadeUp(0.9, SceneManager::en_GameRunning);
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
        }
    });
    
    cocos2d::ui::Button* SettingBtn = (cocos2d::ui::Button*)MainMenuBtnLayer->getChildByName("SettingBtn");
    SettingBtn->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                SoundManager::shareSoundManager()->playEffect("木牌.wav");
                MainSceneSettingLayer->setVisible(true);
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
        }
    });
    
    cocos2d::ui::Button* ExitBtn = (cocos2d::ui::Button*)MainMenuBtnLayer->getChildByName("ExitBtn");
    
    ExitBtn->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                SoundManager::shareSoundManager()->playEffect("木牌.wav");
                scheduleOnce(schedule_selector(Black::stopSeconds), 0.9f);
                SceneManager::sharedSceneManager()->MTransitionFadeUp(0.9, SceneManager::en_Black);
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
        }
    });
    
    
    //add MainMenuSettingLayer.
    cocos2d::ui::Button* XBtn = (cocos2d::ui::Button*)MainSceneSettingLayer->getChildByName("XBtn");
    
    XBtn->addTouchEventListener([=](Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
        switch (type) {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                MainSceneSettingLayer->setVisible(false);
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
        }
    });
    
    return true;
}
