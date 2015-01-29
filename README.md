Cocos2d-x-Game-Structure
========================

This is the game structure that I'm using in my games; [Pinsaic](https://pinsaic.com) and [EkiMuki](http://ekimuki.com).

This is not the final version and it has been only tested on iOS. In future commits I will add Android features.

Also, I will update this readme file to explain the different features.

##Requirements
+ Cocos2d-x 3.3 Dec.12
+ Android NDK r10d

##Scenes

###Main Menu
This is the first scene that appears when you run the app. You can use the top buttons to change the scene and go to *Settings* or *About* scene. In future updates you will be able to jump to the gameplay scene.
###Settings
* **Display Settings Menu:** Thanks to this menu, it's possible to switch on/off the background music and sound effects. And see which is the current language.
* **Display Language Menu:** Displays a list of available languages. If one of them is selected, it will call *GameSettingsManager* to update the current language configuration and refresh the app's texts.

###About
* **Open an URL:** If chrome is available, the URL is opened by it, else Safari will be used. Chrome has a callback to return to the app. 
* **Send an email:** It opens a mail composer view without leaving the app.
* **Show app on the market:** It opens the App Store to show a specific app.
* **Show all apps from the developer on the market:** It opens the App Store to show all the apps developed by an author.
* **Open Twitter profile:** If the official app is available, it opens the Twitter profile in it. Else, is called OpenURL with the correct URL.
* **Open Facebook profile:** If the official app is available, it opens the Facebook profile in it. Else, is called OpenURL with the correct URL.
* **Post on Twitter:** It uses the builtin social sharing mechanism to send a tweet.

##Helpers

###Language Manager
* **Get Localized Text:** It returns the localized string from languages/languages_CURRENT_LANGUAGE.plist.
* **Get Current Language Name:** It returns the name of the current language; English or Español.

###Social Sharing Manager
This is the class used by the About scene.
Depending on the platform, it uses the classes under *ObjCCalls* or it uses *InterfaceJNI* to use native features. 

##Singletons

###App Manager
###Scene Manager
###Game Settings Manager
###HUD Manager
