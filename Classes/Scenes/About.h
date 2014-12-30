//
//  About.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__About__
#define __EmptyGame__About__

#include "cocos2d.h"

using namespace cocos2d;

class About : public Layer
{
protected:
    void buttonPressed(Ref *sender);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(About);
};
#endif /* defined(__EmptyGame__About__) */
