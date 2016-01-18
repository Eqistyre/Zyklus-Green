//
//  SceneTransition.h
//  Zyklus-Green
//
//  Created by 张仲昊 on 16/1/18.
//
//

#ifndef SceneTransition_h
#define SceneTransition_h

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class SceneTransitionManager : public Ref {
public:
    enum TransitionType
    {
        en_TransitionBg
    };
    
    static SceneTransitionManager* sharedSceneTransitionManager;
    
    void MSceneTransition(Node rnode);

private:
    
    static SceneTransitionManager* mSceneTransitionManager;
    
};










#endif /* SceneTransition_h */
