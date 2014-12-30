//
//  SocialSharingCalls.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__SocialSharingCalls__
#define __EmptyGame__SocialSharingCalls__

#include <iostream>

class SocialSharingCalls
{
public:
    static bool checkInternetConnection();

    static void sendEmail(const char *to, const char *subject, const char *message, const char *imageFilePath);
    static void openWeb(const char* direction);
    static void openMarketApp(const char *id);
    static void openMarketApps(const char *id);
    static void openTwitterProfile(std::string id, std::string username);
    static void postOnTwitter(const char *message, const char *imageFilePath);
    static void openFacebookProfile(std::string id);
};
#endif /* defined(__EmptyGame__SocialSharingCalls__) */
