//
//  CommonProtocols.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__CommonProtocols
#define __EmptyGame__CommonProtocols

class GameHUDDelegate
{
public:
    virtual void showMenu() = 0;
    virtual void hideMenu() = 0;
};

class GameSceneDelegate
{
public:
    virtual void initGame() = 0;
    virtual void resetGame() = 0;
    virtual void finishGame() = 0;
};
#endif
