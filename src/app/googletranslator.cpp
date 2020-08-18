#include "googletranslator.h"
#include "translator.h"
#include <iostream>
#include <QDebug>

std::string GoogleTranslator::translate(std::string sourceText, std::string destLang, std::string sourceLang)
{
    qDebug() << "calling translate";
    Translator t;
    t.translate(sourceText, destLang, sourceLang);
    return "";
}
