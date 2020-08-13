#ifndef GOOGLETRANSLATOR_H
#define GOOGLETRANSLATOR_H
#include <string>

class GoogleTranslator
{
public:
    GoogleTranslator();
    std::string translate(std::string sourceText, std::string destLang, std::string sourceLang = "");
};

#endif // GOOGLETRANSLATOR_H
