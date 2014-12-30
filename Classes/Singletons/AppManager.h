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
    
    void initGame();
    void resetGame();
    void finishGame();
    void exitToMainMenu();
    void setDelegate(GameSceneDelegate *delegate);
    
    CC_SYNTHESIZE(float, _scaleFactor, ScaleFactor);
protected:
    AppManager();
    static AppManager *_instance;
    GameSceneDelegate *_delegate;
};
#endif /* defined(__EmptyGame__AppManager__) */
