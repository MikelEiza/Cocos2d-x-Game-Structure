//
//  HUDManager.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "HUDManager.h"
#include "AppManager.h"

// Singleton
HUDManager * HUDManager::_instance = NULL;

HUDManager* HUDManager::getInstance()
{
    if(!_instance) _instance = new HUDManager();
    return _instance;
}

HUDManager::HUDManager()
{

}

HUDManager::~HUDManager()
{
    
}

/*void HUDManager::setDelegate(PuzzleGameHUDDelegate *delegate)
{
    _delegate = delegate;
}*/
