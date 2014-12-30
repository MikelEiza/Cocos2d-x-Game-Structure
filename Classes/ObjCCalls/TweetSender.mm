//
//  TweetSender.m
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#import "TweetSender.h"
#import "platform/ios/CCEAGLView-ios.h"
#include "CCDirector.h"

@implementation TweetSender

+(void) trySendATweet:(const char *)message withImage:(const char *)imagePath
{
    SLComposeViewController  *mySocialComposer;
    UIViewController *myViewController;
    if([SLComposeViewController isAvailableForServiceType:SLServiceTypeTwitter])
    {
        myViewController = [UIViewController alloc];
        auto view = cocos2d::Director::getInstance()->getOpenGLView();
        CCEAGLView *eaglview = (CCEAGLView *) view->getEAGLView();
        [eaglview addSubview:(myViewController.view)];
        
        mySocialComposer = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeTwitter];
        
        NSString *customMessage = [NSString stringWithFormat:@"%@", [[NSString alloc] initWithUTF8String:message]];
        
        [mySocialComposer setInitialText:customMessage];
        
        if (!strcmp(imagePath, "")) {
            UIImage *image = [UIImage imageWithContentsOfFile:[[NSString alloc] initWithUTF8String:imagePath]];
            
            [mySocialComposer addImage:image];
        }
        
        [myViewController presentViewController:mySocialComposer animated:YES completion:nil];
        
        mySocialComposer.completionHandler = ^(SLComposeViewControllerResult result)
        {
             switch (result)
             {
                 case SLComposeViewControllerResultCancelled:
                     NSLog(@"Tweet cancelled :(");
                     break;
                 case SLComposeViewControllerResultDone:
                     NSLog(@"Succesfully posted on Twitter :D");
                     break;
                 default:
                     break;
             }
          
            // Dismiss the controller
            [myViewController dismissViewControllerAnimated:true completion:^{}];
        };
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Twitter not available"
                                                        message:@"You must have a Twitter account configured to send a tweet."
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        [alert show];
        [alert release];
    }
}

@end
