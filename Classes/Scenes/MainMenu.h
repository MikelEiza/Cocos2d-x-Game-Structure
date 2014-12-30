//
//  MainMenu.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__MainMenu__
#define __EmptyGame__MainMenu__

#include "cocos2d.h"

using namespace cocos2d;

class MainMenu : public Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(MainMenu);
protected:
    void changeScene(Ref* sender);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};
#endif /* defined(__EmptyGame__MainMenu__) */
