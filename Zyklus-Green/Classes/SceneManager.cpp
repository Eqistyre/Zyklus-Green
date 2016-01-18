//
//  SceneManager.cpp
//  
//
//  Created by 张仲昊 on 16/1/17.
//
//

#include "SceneManager.h"
#include "MainMenu.h"
#include "Black.h"
#include "GameRunnning.h"

SceneManager* SceneManager::mSceneManager = NULL;

SceneManager* SceneManager::sharedSceneManager()
{
    if(mSceneManager == NULL)
    {
        mSceneManager = new SceneManager();
    }
    return mSceneManager;
}

void SceneManager::changeScene( EnumSceneType enScenType )
{
    changeScene(enScenType, false);
}

void SceneManager::changeScene( EnumSceneType enScenType, bool isTrans )
{
    changeScene(enScenType, isTrans, 1.0f);
}

void SceneManager::changeScene( EnumSceneType enScenType, bool isTrans, float time )
{
    Scene* pScene = getSceneByType(enScenType);
    
    if(pScene == NULL)
    {
        return;
    }
    //TextureCache::sharedTextureCache()->removeUnusedTextures();
    Director* pDirector = Director::getInstance();
    Scene* curScene = pDirector->getRunningScene();
    if(curScene == NULL)
    {
        pDirector->runWithScene(pScene);
    }
    else
    {
        if(isTrans)
        {
            pDirector->replaceScene(TransitionFade::create(time, pScene));
        }
        else
        {
            pDirector->replaceScene(pScene);
        }
    }
}

void SceneManager::MTransitionFadeUp(float time, EnumSceneType enScenType)
{
    Scene* pScene = getSceneByType(enScenType);
    auto ot = TransitionFadeUp::create(time, pScene);
    Director::getInstance()->replaceScene(ot);
}

void SceneManager::pushScene( EnumSceneType enSceneType )
{
    Scene* pScene = getSceneByType(enSceneType);
    
    if(pScene == NULL)
    {
        return;
    }
    Director::getInstance()->pushScene(pScene);
}

void SceneManager::popScene()
{
    Director::getInstance()->popScene();
}

Scene* SceneManager::getSceneByType( EnumSceneType enSceneType )
{
    Scene* pScene = Scene::create();
    Layer *pLayer = NULL;
    switch (enSceneType)
    {
        case en_MainMenu:
            pLayer = MainMenu::create();
            break;
        case en_Black:
            pLayer = Black::create();
            break;
        case en_GameRunning:
            pLayer = GameRunning::create();
            break;
        default:
            break;
    }
    pScene->addChild(pLayer);
    return pScene;
}
