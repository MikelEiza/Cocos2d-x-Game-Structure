//
//  MainMenu.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "MainMenu.h"
#include "../Singletons/AppManager.h"
#include "../Singletons/SceneManager.h"
#include "../Singletons/SoundManager.h"
#include "../Helpers/LanguageManager.h"

Scene* MainMenu::createScene()
{
    auto *scene = Scene::create();
    
    auto *layer = MainMenu::create();
    layer->setTag(2334);
    
    scene->addChild(layer);
    
    return scene;
}

bool MainMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }    

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto background = LayerColor::create(Color4B(121,189,154,255), visibleSize.width, visibleSize.height);
    background->setPosition(Point(0, 0));
    this->addChild(background, 0);

    auto settings = Label::createWithSystemFont(LanguageManager::getLocalizedText("MainMenu", "settings"), "", 40);
    auto buttonSettings = MenuItemLabel::create(settings, CC_CALLBACK_1(MainMenu::changeScene, this));
    buttonSettings->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    buttonSettings->setPosition(Point(10, origin.y + visibleSize.height - 10));
    buttonSettings->setTag(static_cast<int>(SceneType::SETTINGS));
    
    auto about = Label::createWithSystemFont(LanguageManager::getLocalizedText("MainMenu", "about"), "", 40);
    auto buttonAbout = MenuItemLabel::create(about, CC_CALLBACK_1(MainMenu::changeScene, this));
    buttonAbout->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    buttonAbout->setPosition(Point(origin.x + visibleSize.width - 10, origin.y + visibleSize.height - 10));
    buttonAbout->setTag(static_cast<int>(SceneType::ABOUT));
    
    auto play = Label::createWithSystemFont(LanguageManager::getLocalizedText("MainMenu", "play"), "", 80);
    auto buttonPlay = MenuItemLabel::create(play, CC_CALLBACK_1(MainMenu::changeScene, this));
    buttonPlay->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    buttonPlay->setTag(static_cast<int>(SceneType::GAMEPLAY));

    auto menu = Menu::create(buttonSettings, buttonAbout, buttonPlay, nullptr);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    //Initializing and binding
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyReleased = CC_CALLBACK_2(MainMenu::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

    auto creditsLabel = Label::createWithSystemFont("Music: Mellowtron by Kevin MacLeod (incompetech.com)\nLicensed under Creative Commons: By Attribution 3.0\nhttp://creativecommons.org/licenses/by/3.0/", "", 20);
    creditsLabel->setPosition(Point(origin.x + visibleSize.width - 10,10));
    creditsLabel->setAnchorPoint(Point::ANCHOR_BOTTOM_RIGHT);
    this->addChild(creditsLabel);
    return true;
}

void MainMenu::changeScene(cocos2d::Ref* sender)
{
    SoundManager::getInstance()->sfxPlay("button");

    MenuItem *item = static_cast<MenuItem*>(sender);
    SceneManager::getInstance()->runSceneWithType(static_cast<SceneType>(item->getTag()));
}

void MainMenu::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    if (static_cast<int>(keyCode) != 6) return;
    log("[MainMenu] BACK key pressed!");
}
