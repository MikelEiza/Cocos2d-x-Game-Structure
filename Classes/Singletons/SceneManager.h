//
//  SceneManager.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__SceneManager__
#define __EmptyGame__SceneManager__

#include "cocos2d.h"
#include "../Constants/Constants.h"

class SceneManager
{
public:	// Public singleton
    static SceneManager* getInstance();
    ~SceneManager();
    void runSceneWithType(const SceneType sceneType);
    void returnToLastScene();
private:
    SceneType _sceneTypeToReturn;
    SceneType _currentSceneType;
    static SceneManager * _instance;
    SceneManager();
};
#endif /* defined(__EmptyGame__SceneManager__) */
