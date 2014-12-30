//
//  CheckBox.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-03-20.
//
//

#ifndef __EmptyGame__ButtonSpriteLabelOnOff__
#define __EmptyGame__ButtonSpriteLabelOnOff__

#include "cocos2d.h"
#include "../Constants/Constants.h"

using namespace cocos2d;

class CheckBox : public MenuItemLabel
{
public:
    CheckBox() {}
    virtual ~CheckBox();
    static CheckBox* create(std::string onString, std::string offString, bool isOn, const ccMenuCallback& callback);
    bool initWithString(std::string onString, std::string offString, bool isOn, const ccMenuCallback& callback);

    virtual void activate() override;
protected:
    std::string _onString;
    std::string _offString;
    bool _on;
};
#endif /* defined(__EmptyGame__ButtonSpriteLabelOnOff__) */