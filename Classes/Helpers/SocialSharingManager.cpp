//
//  SocialSharingManager.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "SocialSharingManager.h"
#include "../ObjCCalls/SocialSharingCalls.h"

using namespace cocos2d;

bool SocialSharingManager::checkInternetConnection()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return SocialSharingCalls::checkInternetConnection();
#endif
}

void SocialSharingManager::postOnEmail(const char *to, const char *subject, const char *message, const char *imageFilePath)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::sendEmail(to, subject, message, imageFilePath);
#endif
}

void SocialSharingManager::openWeb(const char *direction)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openWeb(direction);
#endif
}

void SocialSharingManager::openMarketApp(const char* idiOS, const char* idAndroid)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openMarketApp(idiOS);
#endif
}

void SocialSharingManager::openMarketApps(const char* idiOS, const char* idAndroid)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openMarketApps(idiOS);
#endif
}

void SocialSharingManager::openTwitterProfile(const char* id, const char*username)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openTwitterProfile(id,username);
#endif
}

void SocialSharingManager::postOnTwitter(const char *message, const char *path)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::postOnTwitter(message,path);
#endif
}

void SocialSharingManager::openFacebookProfile(std::string id)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openFacebookProfile(id);
#endif
}