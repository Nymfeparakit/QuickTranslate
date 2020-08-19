#ifndef GOOGLETRANSLATOR_H
#define GOOGLETRANSLATOR_H
#include <string>
#include <map>

class GoogleTranslator
{
public:
    std::string translate(std::string sourceText, std::string destLang, std::string sourceLang = "");
    std::map<std::string, std::string> getSupportedLanguagesNamesAndCodes();
};

#endif // GOOGLETRANSLATOR_H
