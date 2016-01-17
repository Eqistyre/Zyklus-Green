//
//  Black.hpp
//  Zyklus-Green
//
//  Created by 张仲昊 on 16/1/17.
//
//

#ifndef Black_h
#define Black_h

#include "cocos2d.h"

class Black : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void stopSeconds(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(Black);
};

#endif /* Black_h */
