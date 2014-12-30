//
//  SoundManager.h
//  EkiMuki
//
//  Created by Mikel Eizagirre on 2014-01-09.
//
//

#ifndef __EkiMuki__SoundManager__
#define __EkiMuki__SoundManager__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

using namespace cocos2d;
using namespace cocos2d::experimental;

class SoundManager
{
public:
    void musicPlay(std::string file, bool loop = true);
    void musicStop();
    void musicPause();
    
    void sfxPlay(std::string file);
    
    static SoundManager* getInstance();
    ~SoundManager();
    
protected:
    SoundManager();
    static SoundManager * _instance;
    
    int _backgroundMusicId;
public:
    
};
#endif /* defined(__EkiMuki__SoundManager__) */
