//
//  GameSettingsManager.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__GameSettingsManager__
#define __EmptyGame__GameSettingsManager__

#include "cocos2d.h"
#include "SoundManager.h"
#include "../Constants/Constants.h"

using namespace cocos2d;

class GameSettingsManager
{
public:
    static GameSettingsManager* getInstance();
    ~GameSettingsManager();
    
    void loadSettings();
    void setLanguage(LanguageType language);
    void switchMusic();
    void switchSFX();
    
    CC_SYNTHESIZE_READONLY(LanguageType, _currentLanguage, CurrentLanguage);
    CC_SYNTHESIZE_READONLY(bool, _music, IsMusicOn);
    CC_SYNTHESIZE_READONLY(bool, _sfx, IsSFXOn);
protected:
    GameSettingsManager();
    static GameSettingsManager * _instance;
};
#endif /* defined(__EmptyGame__GameSettingsManager__) */
