//
//  SoundManager.cpp
//  EkiMuki
//
//  Created by Mikel Eizagirre on 2014-01-09.
//
//

#include "SoundManager.h"
#include "GameSettingsManager.h"

// Singleton
SoundManager * SoundManager::_instance = NULL;

/**
 * Declare sound extension for each platform
 * Android = ogg
 * iOS = caf
 * WIN32 = mp3
 */
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
static std::string audioExtension = ".wav";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
static std::string audioExtension = ".caf";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
static std::string audioExtension = ".ogg";
#endif

SoundManager* SoundManager::getInstance()
{
    if(!_instance) _instance = new SoundManager();
    return _instance;
}

SoundManager::SoundManager():
_backgroundMusicId(-1)
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::musicPlay(std::string file, bool loop)
{
    if (!GameSettingsManager::getInstance()->getIsMusicOn()) {
        return;
    }
    std::string path;
    path = "audio/" + file + audioExtension;
    if (_backgroundMusicId > -1) {
        this->musicStop();
    }
    _backgroundMusicId = AudioEngine::play2d(path, loop);
}

void SoundManager::musicStop()
{
    AudioEngine::stop(_backgroundMusicId);
    _backgroundMusicId = -1;
}

void SoundManager::musicPause()
{
    AudioEngine::pause(_backgroundMusicId);
}

void SoundManager::sfxPlay(std::string file)
{
    if (!GameSettingsManager::getInstance()->getIsSFXOn()) {
        return;
    }
    std::string path;
    path = "audio/" + file + audioExtension;
    AudioEngine::play2d(path);
}