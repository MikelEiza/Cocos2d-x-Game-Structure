//
//  SocialSharingManager.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__SocialSharingManager__
#define __EmptyGame__SocialSharingManager__

#include "cocos2d.h"
#include "../Constants/Constants.h"

class SocialSharingManager
{
public:
    static bool checkInternetConnection();
    // Email
    static void postOnEmail(const char *to, const char *subject, const char *message, const char *imageFilePath = "");
    // Web
    static void openWeb(const char* direction);
    // Market
    static void openMarketApp(const char* idiOS, const char* idAndroid);
    static void openMarketApps(const char* idiOS, const char* idAndroid);
    // Twitter
    static void openTwitterProfile(const char* id, const char* username);
    static void postOnTwitter(const char *message, const char *path = "");
    // Facebook
    static void openFacebookProfile(std::string id);
};
#endif /* defined(__EmptyGame__SocialSharingManager__) */
