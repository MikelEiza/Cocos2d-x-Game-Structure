//
//  TweetSender.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#import <Social/Social.h>
#import <Accounts/Accounts.h>

@interface TweetSender : NSObject

+ (void) trySendATweet:(const char *)message withImage:(const char *)imagePath;

@end
