//
//  SocialSharingCalls.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "SocialSharingCalls.h"
#include "Reachability.h"
#include "MailSender.h"
#include "TweetSender.h"

bool SocialSharingCalls::checkInternetConnection()
{
    Reachability *networkReachability = [Reachability reachabilityForInternetConnection];
    NetworkStatus networkStatus = [networkReachability currentReachabilityStatus];
    return !(networkStatus == NotReachable);
}

void SocialSharingCalls::sendEmail(const char *to, const char *subject, const char *message, const char *imageFilePath)
{
    MailSender *mailSender = [MailSender alloc];
    [mailSender sendMailUsingInAppMailer:to withSubject:subject withMessage:message withImage:imageFilePath];
}

void SocialSharingCalls::openWeb(const char *direction)
{
    NSURL *inputURL = [NSURL URLWithString:[NSString stringWithUTF8String:direction]];
    
    // if chrome installed use it
    if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"googlechrome://"]])
    {
        NSString *scheme = inputURL.scheme;
        // if supports callbacks use them
        if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"googlechrome-x-callback://"]])
        {
            NSString *appName = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"ChromeDisplayName"];
            NSURL *callbackURL = [NSURL URLWithString:@"org.mikeleiza.emptyGame://"];
            
            // Proceed only if scheme is http or https.
            if ([scheme isEqualToString:@"http"] || [scheme isEqualToString:@"https"])
            {
                
                NSString *appNameString = (NSString *)CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,
                                                                                              (CFStringRef)appName,
                                                                                              NULL,
                                                                                              (CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                                                              kCFStringEncodingUTF8);
                
                NSString *callbackURLString = (NSString *)CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,
                                                                                                  (CFStringRef)[callbackURL absoluteString],
                                                                                                  NULL,
                                                                                                  (CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                                                                  kCFStringEncodingUTF8);
                NSString *inputURLString = (NSString *)CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,
                                                                                               (CFStringRef)[inputURL absoluteString],
                                                                                               NULL,
                                                                                               (CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                                                               kCFStringEncodingUTF8);
                
                NSString *chromeURLString = [NSString stringWithFormat:
                                             @"googlechrome-x-callback://x-callback-url/open/?x-source=%@&x-success=%@&url=%@",
                                             appNameString,
                                             callbackURLString,
                                             inputURLString];
                NSURL *chromeURL = [NSURL URLWithString:chromeURLString];
                
                // Open the URL with Google Chrome.
                [[UIApplication sharedApplication] openURL:chromeURL];
            }
        }
        else
        {
            // Replace the URL Scheme with the Chrome equivalent.
            NSString *chromeScheme = nil;
            if ([scheme isEqualToString:@"http"])
            {
                chromeScheme = @"googlechrome";
            }
            else if ([scheme isEqualToString:@"https"])
            {
                chromeScheme = @"googlechromes";
            }
            
            // Proceed only if a valid Google Chrome URI Scheme is available.
            if (chromeScheme)
            {
                NSString *absoluteString = [inputURL absoluteString];
                NSRange rangeForScheme = [absoluteString rangeOfString:@":"];
                NSString *urlNoScheme =
                [absoluteString substringFromIndex:rangeForScheme.location];
                NSString *chromeURLString =
                [chromeScheme stringByAppendingString:urlNoScheme];
                NSURL *chromeURL = [NSURL URLWithString:chromeURLString];
                
                // Open the URL with Chrome.
                [[UIApplication sharedApplication] openURL:chromeURL];
            }
        }
    }
    else
    {
        [[UIApplication sharedApplication] openURL:inputURL];
    }
}

void SocialSharingCalls::openMarketApp(const char *id)
{
    static NSString *const iOSAppStoreURLFormat = @"itms-apps://itunes.apple.com/app/id%@?at=10l6dK";
    static NSString *const iOS7AppStoreURLFormat = @"itms-apps://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%@&at=10l6dK";
    
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:([[UIDevice currentDevice].systemVersion floatValue] >= 7.0f)? iOS7AppStoreURLFormat: iOSAppStoreURLFormat, [NSString stringWithUTF8String:id]]];
    
    [[UIApplication sharedApplication] openURL:url];
}

void SocialSharingCalls::openMarketApps(const char *id)
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"itms-apps://itunes.com/apps/%@", [NSString stringWithUTF8String:id]]]];
}

void SocialSharingCalls::openTwitterProfile(std::string id, std::string username)
{
    NSURL *twitterURL = [NSURL URLWithString:[NSString stringWithFormat:@"twitter://user?id=%s",id.c_str()]];
    
    if ([[UIApplication sharedApplication] canOpenURL:twitterURL])
    {
        [[UIApplication sharedApplication] openURL:twitterURL];
    }
    else
    {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"https://www.twitter.com/%s",username.c_str()]]];
    }
}

void SocialSharingCalls::postOnTwitter(const char *message, const char *imageFilePath)
{
    [TweetSender trySendATweet:message withImage:imageFilePath];
}

void SocialSharingCalls::openFacebookProfile(std::string id)
{
    NSURL *facebookURL = [NSURL URLWithString:[NSString stringWithFormat:@"fb://profile/%s",id.c_str()]];
    
    if ([[UIApplication sharedApplication] canOpenURL:facebookURL])
    {
        [[UIApplication sharedApplication] openURL:facebookURL];
    }
    else
    {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"https://www.facebook.com/%s",id.c_str()]]];
    }
}