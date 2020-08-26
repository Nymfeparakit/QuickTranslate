#ifndef GOOGLETRANSLATOR_H
#define GOOGLETRANSLATOR_H
#include <string>
#include <map>
#include "translator.h"

class GoogleTranslator
{
public:
    std::string translate(std::string sourceText, std::string destLang, std::string sourceLang = "");
    //gets languages which are supported by translator
    std::map<std::string, std::string> getSupportedLanguagesNamesAndCodes();
private:
    Translator t;
};

#endif // GOOGLETRANSLATOR_H
