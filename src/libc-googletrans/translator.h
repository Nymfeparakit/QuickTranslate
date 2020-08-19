#pragma once

#include <string>
#include <map>

class Translator 
{
    public:
    std::string translate(std::string sourceText, std::string destLang, std::string sourceLang);
    std::map<std::string, std::string> getSupportedLanguagesNamesAndCodes();

};
