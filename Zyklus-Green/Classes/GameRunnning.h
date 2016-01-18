//
//  GameRunnning.h
//  Zyklus-Green
//
//  Created by 张仲昊 on 16/1/18.
//
//

#ifndef GameRunnning_h
#define GameRunnning_h

#include "cocos2d.h"

class GameRunning : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameRunning);
};

#endif /* GameRunnning_h */
