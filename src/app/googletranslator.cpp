#include "googletranslator.h"
#include <iostream>
#include <QDebug>

std::string GoogleTranslator::translate(std::string sourceText, std::string destLang, std::string sourceLang)
{
    std::string translatedText = t.translate(sourceText, destLang, sourceLang);
    return translatedText;
}

std::map<std::string, std::string> GoogleTranslator::getSupportedLanguagesNamesAndCodes()
{
   return t.getSupportedLanguagesNamesAndCodes();
}
