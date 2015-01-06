//
//  About.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "About.h"
#include "../Singletons/SceneManager.h"
#include "../Singletons/SoundManager.h"
#include "../Helpers/SocialSharingManager.h"
#include "../Helpers/LanguageManager.h"

enum class ButtonType
{
    WEB,
	MAIL,
    MARKET_APP,
    MARKET_APPS,
    PROFILE_TWITTER,
    PROFILE_FACEBOOK,
    SHARE_TWITTER,
    SHARE_FACEBOOK,
    BACK
};

Scene* About::createScene()
{
    auto *scene = Scene::create();
    
    auto *layer = About::create();
    layer->setTag(2334);
    
    scene->addChild(layer);
    
    return scene;
}

bool About::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto background = LayerColor::create(Color4B(92,206,238,255), visibleSize.width, visibleSize.height);
    background->setPosition(Point(0, 0));
    this->addChild(background, 0);
    
    Vector<cocos2d::MenuItem *> items;
    
    auto openURL = Label::createWithSystemFont(LanguageManager::getLocalizedText("About", "open_url"), "", 30);
    auto buttonOpenURL = MenuItemLabel::create(openURL, CC_CALLBACK_1(About::buttonPressed, this));
    buttonOpenURL->setPosition(Point(origin.x + visibleSize.width/3, origin.y + visibleSize.height*0.7));
    buttonOpenURL->setTag(static_cast<int>(ButtonType::WEB));
    items.pushBack(buttonOpenURL);
    
    auto sendEmail = Label::createWithSystemFont(LanguageManager::getLocalizedText("About", "send_email"), "", 30);
    auto buttonSendEmail = MenuItemLabel::create(sendEmail, CC_CALLBACK_1(About::buttonPressed, this));
    buttonSendEmail->setPosition(Point(origin.x + visibleSize.width/3, origin.y + visibleSize.height*0.5));
    buttonSendEmail->setTag(static_cast<int>(ButtonType::MAIL));
    items.pushBack(buttonSendEmail);
    
    auto openMarketApp = Label::createWithSystemFont(LanguageManager::getLocalizedText("About", "market_this_app"), "", 30);
    auto buttonOpenMarketApp = MenuItemLabel::create(openMarketApp, CC_CALLBACK_1(About::buttonPressed, this));
    buttonOpenMarketApp->setPosition(Point(origin.x + visibleSize.width/3, origin.y + visibleSize.height*0.3));
    buttonOpenMarketApp->setTag(static_cast<int>(ButtonType::MARKET_APP));
    items.pushBack(buttonOpenMarketApp);
    
    auto openMarketApps = Label::createWithSystemFont(LanguageManager::getLocalizedText("About", "market_developer_apps"), "", 30);
    auto buttonOpenMarketApps = MenuItemLabel::create(openMarketApps, CC_CALLBACK_1(About::buttonPressed, this));
    buttonOpenMarketApps->setPosition(Point(origin.x + visibleSize.width/3, origin.y + visibleSize.height*0.1));
    buttonOpenMarketApps->setTag(static_cast<int>(ButtonType::MARKET_APPS));
    items.pushBack(buttonOpenMarketApps);
    
    auto openTwitterProfile = Label::createWithSystemFont(LanguageManager::getLocalizedText("About", "open_twitter_profile"), "", 30);
    auto buttonOpenTwitterProfile = MenuItemLabel::create(openTwitterProfile, CC_CALLBACK_1(About::buttonPressed, this));
    buttonOpenTwitterProfile->setPosition(Point(origin.x + visibleSize.width*0.66, origin.y + visibleSize.height*0.7));
    buttonOpenTwitterProfile->setTag(static_cast<int>(ButtonType::PROFILE_TWITTER));
    items.pushBack(buttonOpenTwitterProfile);
    
    auto openFacebookProfile = Label::createWithSystemFont(LanguageManager::getLocalizedText("About", "open_facebook_profile"), "", 30);
    auto buttonOpenFacebookProfile = MenuItemLabel::create(openFacebookProfile, CC_CALLBACK_1(About::buttonPressed, this));
    buttonOpenFacebookProfile->setPosition(Point(origin.x + visibleSize.width*0.66, origin.y + visibleSize.height*0.5));
    buttonOpenFacebookProfile->setTag(static_cast<int>(ButtonType::PROFILE_FACEBOOK));
    items.pushBack(buttonOpenFacebookProfile);
    
    auto postOnTwitter = Label::createWithSystemFont(LanguageManager::getLocalizedText("About", "post_on_twitter"), "", 30);
    auto buttonPostOnTwitter = MenuItemLabel::create(postOnTwitter, CC_CALLBACK_1(About::buttonPressed, this));
    buttonPostOnTwitter->setPosition(Point(origin.x + visibleSize.width*0.66, origin.y + visibleSize.height*0.3));
    buttonPostOnTwitter->setTag(static_cast<int>(ButtonType::SHARE_TWITTER));
    items.pushBack(buttonPostOnTwitter);
    
    // Back button
    auto back = Label::createWithSystemFont(LanguageManager::getLocalizedText("General", "back"), "", 40);
    auto backButton = MenuItemLabel::create(back, CC_CALLBACK_1(About::buttonPressed, this));
    backButton->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    backButton->setTag(static_cast<int>(ButtonType::BACK));
    backButton->setPosition(Point(10, origin.y + visibleSize.height - 10));
    items.pushBack(backButton);
    
    auto menu = Menu::createWithArray(items);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    //Initializing and binding
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyReleased = CC_CALLBACK_2(About::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    return true;
}

void About::buttonPressed(Ref *sender)
{
    SoundManager::getInstance()->sfxPlay("button");
    auto button = static_cast<MenuItemSprite*>(sender);
    switch (static_cast<ButtonType>(button->getTag())) {
        case ButtonType::MAIL:
            SocialSharingManager::postOnEmail("hello@ekimuki.com", "Subject", "Message Body");
            break;
        case ButtonType::WEB:
            SocialSharingManager::openWeb("http://www.ekimuki.com");
            break;
        case ButtonType::MARKET_APP:
            SocialSharingManager::openMarketApp("887433848", "org.mikeleiza.ekimukiVol1"); // Apps ID on the App Store and Google Play
            break;
        case ButtonType::MARKET_APPS:
            SocialSharingManager::openMarketApps("MikelEizagirreUrkaregi", "Mikel+Eizagirre"); // Developer ID on the App Store and Google Play
            break;
        case ButtonType::PROFILE_TWITTER:
            SocialSharingManager::openTwitterProfile("238630057", "MikelEiza"); // Twitter ID and UserName - http://mytwitterid.com/
            break;
        case ButtonType::PROFILE_FACEBOOK:
            SocialSharingManager::openFacebookProfile("100003638565932"); // Facebook ID - http://findmyfacebookid.com/
            break;
        case ButtonType::SHARE_TWITTER:
            SocialSharingManager::postOnTwitter("Message Body");
            break;
        case ButtonType::SHARE_FACEBOOK:
            
            break;
        case ButtonType::BACK:
            SceneManager::getInstance()->returnToLastScene();
            break;
        default:
            break;
    }
}

void About::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    // exit to MainMenu only if back key pressed (KeyCode == 6)
    if (static_cast<int>(keyCode) != 6) return;
    SceneManager::getInstance()->returnToLastScene();
}
