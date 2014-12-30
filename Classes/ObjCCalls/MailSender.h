//
//  MailSender.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

@interface MailSender : UIViewController <MFMailComposeViewControllerDelegate>
{
    UIViewController *currentModalViewController;
}
- (void) sendMailUsingInAppMailer:(const char *)to withSubject:(const char *)subject withMessage:(const char *)message withImage:(const char *)imageFilePath;
- (void) sendMailUsingExternalApp;

@end
