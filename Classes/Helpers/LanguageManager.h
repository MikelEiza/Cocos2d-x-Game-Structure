//
//  LanguageManager.h
//  EmptyGame
//
//  Created by Mikel Eizagirre on 2014-12-24.
//
//

#ifndef __EmptyGame__LanguageManager__
#define __EmptyGame__LanguageManager__

#include <string>

class LanguageManager
{
public:
    static std::string getLocalizedText(const char *miniDic, const char *key);
    static std::string getCurrentLanguageName();
};
#endif /* defined(__EmptyGame__LanguageManager__) */
