//
//  AppManager.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__AppManager__
#define __EmptyGame__AppManager__

#include "cocos2d.h"
#include "../Constants/Constants.h"
#include "../Constants/CommonProtocols.h"

using namespace cocos2d;

class AppManager
{
public:
    static AppManager* getInstance();
    ~AppManager();
    
    void initGame() {_delegate->initGame();};
    void resetGame() {_delegate->resetGame();};
    void finishGame() {_delegate->finishGame();};
    void setDelegate(GameSceneDelegate *delegate) {_delegate = delegate;};
    void exitToMainMenu();
protected:
    AppManager();
    static AppManager *_instance;
    GameSceneDelegate *_delegate;
};
#endif /* defined(__EmptyGame__AppManager__) */
