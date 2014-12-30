//
//  MailSender.m
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#import "MailSender.h"
#import "../Constants/Constants.h"

@implementation MailSender

-(void) sendMailUsingExternalApp
{
[self sendEmailTo:@""
           withCC:@""
          withBCC:@""
      withSubject:@"Test mail :D"
         withBody:@"<p>This is a test message!!!</p><p><a href='http://cocos2d-x.org'><img src='http://www.cocos2d-x.org/attachments/709/cocos2dx_portrait.png'/></a></p>"];
}


- (void)sendEmailTo:(NSString*)to withCC:(NSString*)cc withBCC:(NSString*)bcc withSubject:(NSString*)subject withBody:(NSString*)body {
	NSString * url = [NSString stringWithFormat:@"mailto:?to=%@&cc=%@&bcc=%@&subject=%@&body=%@",
					  [to stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [cc stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [bcc stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [subject stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding],
					  [body stringByAddingPercentEscapesUsingEncoding:NSASCIIStringEncoding]];
    
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
}

- (void)sendMailUsingInAppMailer:(const char *)to withSubject:(const char *)subject withMessage:(const char *)message withImage:(const char *)imageFilePath
{
    if ([MFMailComposeViewController canSendMail])
    {
        MFMailComposeViewController *mailer = [[MFMailComposeViewController alloc] init];
                
        mailer.mailComposeDelegate = self;
        
        [mailer setSubject:[[NSString alloc] initWithUTF8String:subject]];
        
        NSString *emailBody = [[NSString alloc] initWithUTF8String:message];
        [mailer setMessageBody:emailBody isHTML:YES];
        // if recipient specified, use it
        if (strcmp("", to))
        {
            [mailer setToRecipients:[NSArray arrayWithObject:[[NSString alloc] initWithUTF8String:to]]];
        }
        
        if (!strcmp("", imageFilePath))
        {
            if ([[NSFileManager defaultManager] fileExistsAtPath:[NSString stringWithUTF8String:imageFilePath]]) {
                //get the screenshot as raw data
                NSData *data = [NSData dataWithContentsOfFile:[NSString stringWithUTF8String:imageFilePath]];
                
                //create an image from the raw data
                UIImage *img = [UIImage imageWithData:data];
                NSData *imageData = [NSData dataWithData:UIImagePNGRepresentation(img)];
                [mailer addAttachmentData:imageData mimeType:@"image/png" fileName:@"screenshot.png"];
            }
        }
        
        // only for iPad
        // mailer.modalPresentationStyle = UIModalPresentationPageSheet;
        
        UIWindow *window = [[UIApplication sharedApplication] keyWindow];
        currentModalViewController = [UIViewController alloc];
        [window addSubview:currentModalViewController.view];
        [currentModalViewController presentViewController:mailer animated:true completion:^{}];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Failure"
                                                        message:@"Your device doesn't support the composer sheet"
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles: nil];
        [alert show];
        [alert release];
    }
    
}

- (void)mailComposeController:(MFMailComposeViewController*)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError*)error
{
	switch (result)
	{
		case MFMailComposeResultCancelled:
            NSLog(@"Message CANCELLED!");
			break;
		case MFMailComposeResultSaved:
            NSLog(@"Message succesfully SAVED!");
			break;
		case MFMailComposeResultSent:
            NSLog(@"Message succesfully SENT!");
			break;
		case MFMailComposeResultFailed:
            NSLog(@"FAILED to send the message!");
			break;
		default:
            NSLog(@"Unkown ERROR!");
			break;
	}
    
	[currentModalViewController dismissViewControllerAnimated:true completion:^{
        [currentModalViewController.view removeFromSuperview];
        [currentModalViewController release];
    }];
}

@end
