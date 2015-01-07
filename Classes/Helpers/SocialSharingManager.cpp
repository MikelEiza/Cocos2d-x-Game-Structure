//
//  SocialSharingManager.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "SocialSharingManager.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "../InterfaceJNI.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "../ObjCCalls/SocialSharingCalls.h"
#endif

using namespace cocos2d;

bool SocialSharingManager::checkInternetConnection()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return SocialSharingCalls::checkInternetConnection();
#endif
    return false;
}

void SocialSharingManager::postOnEmail(const char *to, const char *subject, const char *message, const char *imageFilePath)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    InterfaceJNI::sendMail(to, subject, message);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::sendEmail(to, subject, message, imageFilePath);
#endif
}

void SocialSharingManager::openWeb(const char *direction)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    InterfaceJNI::openWeb(direction);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openWeb(direction);
#endif
}

void SocialSharingManager::openMarketApp(const char* idiOS, const char* idAndroid)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	InterfaceJNI::openMarketApp(idAndroid);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openMarketApp(idiOS);
#endif
}

void SocialSharingManager::openMarketApps(const char* idiOS, const char* idAndroid)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	InterfaceJNI::openMarketApps(idAndroid);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openMarketApps(idiOS);
#endif
}

void SocialSharingManager::openTwitterProfile(const char* id, const char*username)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    InterfaceJNI::openTwitterProfile(username);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialSharingCalls::openTwitterProfile(id,username);
#endif
}

void SocialSharingManager::postOnTwitter(const char *message, const char *path)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    InterfaceJNI::sendTweet(message);
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
