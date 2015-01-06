//
//  Settings.cpp
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#include "Settings.h"
#include "../Singletons/SceneManager.h"
#include "../Singletons/GameSettingsManager.h"
#include "../Helpers/LanguageManager.h"
#include "../CustomGUI/CheckBox.h"

enum class ButtonType
{
    MUSIC,
    SFX,
    LANGUAGE,
    BACK_SETTINGS,
    BACK_LANGUAGE
};

Scene* Settings::createScene()
{
    auto *scene = Scene::create();
    
    auto *layer = Settings::create();
    layer->setTag(2334);
    
    scene->addChild(layer);
    
    return scene;
}

bool Settings::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    displaySettingsMenu();
    
    return true;
}

void Settings::displaySettingsMenu()
{
    _showingLanguageSettings = false;

    this->removeAllChildren();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto background = LayerColor::create(Color4B(255,196,140,255), visibleSize.width, visibleSize.height);
    background->setPosition(Point(0, 0));
    this->addChild(background, 0);
    
    Vector<cocos2d::MenuItem *> items;
    
    auto labelMusic = Label::createWithSystemFont(LanguageManager::getLocalizedText("Settings", "music"), "", 40);
    labelMusic->setPosition(Point(origin.x + visibleSize.width/5, origin.y + visibleSize.height*0.6));
    labelMusic->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    this->addChild(labelMusic);
    
    auto labelSound = Label::createWithSystemFont(LanguageManager::getLocalizedText("Settings", "sound_effects"), "", 40);
    labelSound->setPosition(Point(origin.x + visibleSize.width/5, origin.y + visibleSize.height*0.45));
    labelSound->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    this->addChild(labelSound);
    
    auto labelLanguage = Label::createWithSystemFont(LanguageManager::getLocalizedText("Settings", "language"), "", 40);
    labelLanguage->setPosition(Point(origin.x + visibleSize.width/5, origin.y + visibleSize.height*0.3));
    labelLanguage->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
    this->addChild(labelLanguage);
    
    auto checkBoxMusic = CheckBox::create("On", "Off", GameSettingsManager::getInstance()->getIsMusicOn(), CC_CALLBACK_1(Settings::buttonPressed, this));
    checkBoxMusic->setPosition(Point(origin.x + visibleSize.width*.8, origin.y + visibleSize.height*0.6));
    checkBoxMusic->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    checkBoxMusic->setTag(static_cast<int>(ButtonType::MUSIC));
    items.pushBack(checkBoxMusic);

    auto checkSFX = CheckBox::create("On", "Off", GameSettingsManager::getInstance()->getIsSFXOn(), CC_CALLBACK_1(Settings::buttonPressed, this));
    checkSFX->setPosition(Point(origin.x + visibleSize.width*.8, origin.y + visibleSize.height*0.45));
    checkSFX->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    checkSFX->setTag(static_cast<int>(ButtonType::SFX));
    items.pushBack(checkSFX);
    
    auto buttonLanguageLabel = Label::createWithSystemFont(LanguageManager::getCurrentLanguageName() + " >", "", 40);
    auto buttonLanguage = MenuItemLabel::create(buttonLanguageLabel, CC_CALLBACK_1(Settings::buttonPressed, this));
    buttonLanguage->setPosition(Point(origin.x + visibleSize.width*.8, origin.y + visibleSize.height*0.3));
    buttonLanguage->setTag(static_cast<int>(ButtonType::LANGUAGE));
    buttonLanguage->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
    items.pushBack(buttonLanguage);
    
    // Back button
    auto back = Label::createWithSystemFont(LanguageManager::getLocalizedText("General", "back"), "", 40);
    auto backButton = MenuItemLabel::create(back, CC_CALLBACK_1(Settings::buttonPressed, this));
    backButton->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    backButton->setTag(static_cast<int>(ButtonType::BACK_SETTINGS));
    backButton->setPosition(Point(10, origin.y + visibleSize.height - 10));
    items.pushBack(backButton);
    
    auto menu = Menu::createWithArray(items);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    //Initializing and binding
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyReleased = CC_CALLBACK_2(Settings::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void Settings::displayLanguageMenu()
{
    _showingLanguageSettings = true;
    
    this->removeAllChildren();
    _languageButtons.clear();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto background = LayerColor::create(Color4B(82,70,86,255), visibleSize.width, visibleSize.height);
    background->setPosition(Point(0, 0));
    this->addChild(background, 0);
    
    Vector<cocos2d::MenuItem *> items;
    
    // Language selection buttons
    auto english = Label::createWithSystemFont("English", "", 40);
    auto buttonEnglish = MenuItemLabel::create(english, CC_CALLBACK_1(Settings::languageChanged, this));
    buttonEnglish->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.6));
    buttonEnglish->setTag(static_cast<int>(LanguageType::ENGLISH));
    if (GameSettingsManager::getInstance()->getCurrentLanguage() == LanguageType::ENGLISH) {
        buttonEnglish->setColor(Color3B::GREEN);
    }
    else {
        buttonEnglish->setColor(Color3B::GRAY);
    }
    items.pushBack(buttonEnglish);
    _languageButtons.push_back(buttonEnglish);

    auto espanol = Label::createWithSystemFont("Español", "", 40);
    auto buttonEspanol = MenuItemLabel::create(espanol, CC_CALLBACK_1(Settings::languageChanged, this));
    buttonEspanol->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height*0.4));
    buttonEspanol->setTag(static_cast<int>(LanguageType::SPANISH));
    if (GameSettingsManager::getInstance()->getCurrentLanguage() == LanguageType::SPANISH) {
        buttonEspanol->setColor(Color3B::GREEN);
    }
    else {
        buttonEspanol->setColor(Color3B::GRAY);
    }
    items.pushBack(buttonEspanol);
    _languageButtons.push_back(buttonEspanol);
    
    // Back button
    auto back = Label::createWithSystemFont(LanguageManager::getLocalizedText("General", "back"), "", 40);
    auto backButton = MenuItemLabel::create(back, CC_CALLBACK_1(Settings::buttonPressed, this));
    backButton->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    backButton->setTag(static_cast<int>(ButtonType::BACK_LANGUAGE));
    backButton->setPosition(Point(10, origin.y + visibleSize.height - 10));
    items.pushBack(backButton);
    
    auto menu = Menu::createWithArray(items);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    //Initializing and binding
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyReleased = CC_CALLBACK_2(Settings::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void Settings::languageChanged(Ref *sender)
{
    SoundManager::getInstance()->sfxPlay("button");

    auto button = static_cast<MenuItemSprite*>(sender);
    auto newLanguage = static_cast<LanguageType>(button->getTag());
    
    GameSettingsManager::getInstance()->setLanguage(newLanguage);
    
    _backButton->setString(LanguageManager::getLocalizedText("General", "back"));
    
    for (MenuItemLabel *it : _languageButtons) {
        if (static_cast<LanguageType>(it->getTag()) == newLanguage) {
            it->setColor(Color3B::GREEN);
        }
        else {
            it->setColor(Color3B::GRAY);
        }
    }
}

void Settings::buttonPressed(Ref *sender)
{
    SoundManager::getInstance()->sfxPlay("button");
    auto button = static_cast<MenuItemSprite*>(sender);
    switch (static_cast<ButtonType>(button->getTag())) {
        case ButtonType::MUSIC:
            GameSettingsManager::getInstance()->switchMusic();
            break;
        case ButtonType::SFX:
            GameSettingsManager::getInstance()->switchSFX();
            break;
        case ButtonType::LANGUAGE:
            this->displayLanguageMenu();
            break;
        case ButtonType::BACK_SETTINGS:
            SceneManager::getInstance()->returnToLastScene();
            break;
        case ButtonType::BACK_LANGUAGE:
            this->displaySettingsMenu();
            break;
        default:
            break;
    }
}

void Settings::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    // exit to MainMenu or display Settings Initial Menu, only if back key pressed (KeyCode == 6)
    if (static_cast<int>(keyCode) != 6) return;

    if (_showingLanguageSettings) {
        this->displaySettingsMenu();
    }
    else {
        SceneManager::getInstance()->returnToLastScene();
    }
}
