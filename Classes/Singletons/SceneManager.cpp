//
//  SceneManager.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "SceneManager.h"
#include "AppManager.h"
#include "../Scenes/MainMenu.h"
#include "../Scenes/Settings.h"
#include "../Scenes/About.h"

using namespace cocos2d;

// Singleton
SceneManager * SceneManager::_instance = NULL;

/**
 * \brief Give me a pointer to Singleton!
 */
SceneManager* SceneManager::getInstance()
{
    if(!_instance) _instance = new SceneManager();
    return _instance;
}

SceneManager::SceneManager():
_sceneTypeToReturn(SceneType::MAINMENU),
_currentSceneType(SceneType::MAINMENU)
{
    
}

SceneManager::~SceneManager()
{
    
}

void SceneManager::runSceneWithType(const SceneType sceneType)
{
    SceneType oldScene = _currentSceneType;
	_currentSceneType = sceneType;
	Scene *sceneToRun = nullptr;
    switch (sceneType) {
        case SceneType::MAINMENU:
            sceneToRun = MainMenu::createScene();
            break;
        case SceneType::SETTINGS:
            sceneToRun = Settings::createScene();
            break;
        case SceneType::ABOUT:
            sceneToRun = About::createScene();
            break;
        default:
            log("WARNING! Default value when trying to run scene with id %d", static_cast<int>(sceneType));
            return;
            break;
	}
    sceneToRun->setTag(static_cast<int>(sceneType));

	if (sceneToRun == nullptr) {
		_currentSceneType = oldScene;
		return;
	}
    
    _sceneTypeToReturn = oldScene;
    
    if (CCDirector::getInstance()->getRunningScene() == nullptr) {
    	CCDirector::getInstance()->runWithScene(sceneToRun);
    }
	else {
		CCDirector::getInstance()->replaceScene(sceneToRun);
	}
}

void SceneManager::returnToLastScene()
{
    this->runSceneWithType(_sceneTypeToReturn);
}