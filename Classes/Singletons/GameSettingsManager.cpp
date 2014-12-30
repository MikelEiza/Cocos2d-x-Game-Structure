//
//  GameSettingsManager.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "GameSettingsManager.h"

// Singleton
GameSettingsManager * GameSettingsManager::_instance = NULL;

/**
 * \brief returns Singleton's pointer
 *
 */
GameSettingsManager* GameSettingsManager::getInstance()
{
    if(!_instance) _instance = new GameSettingsManager();
    return _instance;
}

/**
 * \brief CONSTRUCTOR
 *
 * \param[in]		Nan
 * \param[out]		Nan
 *
 */
GameSettingsManager::GameSettingsManager()
{
    this->loadSettings();
}

/**
 * \brief DESTRUCTOR
 *
 * \param[in]		Nan
 * \param[out]		Nan
 *
 */
GameSettingsManager::~GameSettingsManager()
{

}

/**
 * \brief Load ALL settings variables from UserDefault
 *
 * \param[in]		Nan
 * \param[out]		Nan
 *
 */
void GameSettingsManager::loadSettings()
{
    UserDefault *userDefault = UserDefault::getInstance();
    
    // set device language
    if (userDefault->getIntegerForKey("currentLanguage", -1) == -1)
    {
        userDefault->setIntegerForKey("currentLanguage", static_cast<int>(Application::getInstance()->getCurrentLanguage()));
        userDefault->flush();
    }
    
    _currentLanguage = static_cast<LanguageType>(userDefault->getIntegerForKey("currentLanguage", 0));
    _music = userDefault->getBoolForKey("music");
    _sfx = userDefault->getBoolForKey("sfx");
}

/**
 * \brief Set Application language
 *
 * \param[in]		LanguageType language; LanguageType::ENGLISH, LanguageType::SPANISH
 * \param[out]		Nan
 *
 */
void GameSettingsManager::setLanguage(LanguageType language)
{
    _currentLanguage = language;

    UserDefault *userDefault = UserDefault::getInstance();
    userDefault->setIntegerForKey("currentLanguage", static_cast<int>(language));
    userDefault->flush();
}

void GameSettingsManager::switchMusic()
{
    _music = !_music;
    
    if (_music) {
        SoundManager::getInstance()->musicPlay("background");
    }
    else {
        SoundManager::getInstance()->musicStop();
    }
    
    UserDefault *userDefault = UserDefault::getInstance();
    userDefault->setBoolForKey("music", _music);
    userDefault->flush();
}

void GameSettingsManager::switchSFX()
{
    _sfx = !_sfx;
    
    UserDefault *userDefault = UserDefault::getInstance();
    userDefault->setBoolForKey("sfx", _sfx);
    userDefault->flush();
}