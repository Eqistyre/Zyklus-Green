//
//  SceneManager.h
//  
//
//  Created by 张仲昊 on 16/1/17.
//
//

#ifndef ____SceneManager__
#define ____SceneManager__

#include "cocos2d.h"

using namespace cocos2d;

class SceneManager : public Ref {
public:
    
    enum EnumSceneType
    {
        en_MainMenu,
        en_Black
    };
    
    static SceneManager* sharedSceneManager();;
    
    void changeScene(EnumSceneType enScenType);
    
    void changeScene(EnumSceneType enScenType, bool isTrans);
    
    void changeScene(EnumSceneType enScenType, bool isTrans, float time);
    
    void Fade(float time, EnumSceneType enScenType);
    
    void pushScene(EnumSceneType enSceneType);
    
    void popScene();
private:
    
    static SceneManager* mSceneManager;
    
    Scene* getSceneByType(EnumSceneType enSceneType);
};

#endif
