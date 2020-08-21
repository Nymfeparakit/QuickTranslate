#include "mainpresenter.h"
#include "googletranslator.h"
#include <QDebug>
#include <iostream>

MainPresenter::MainPresenter(IMainView* _mainView)
    :mainView(_mainView)
{
}

void MainPresenter::onTranslate()
{
    std::string text = mainView->getSourceText();//достаем текст источника от view
    //достаем source, dest языки
    std::string sourceLang = mainView->getSourceLanguage();
    std::string destLang = mainView->getDestLanguage();
    //получаем перевод
    GoogleTranslator t;
    std::string translatedText = t.translate(text, destLang, sourceLang);
    mainView->showTranslatedText(translatedText); //передаем текст view
}

LanguagesList *MainPresenter::loadLanguagesList()
{
   GoogleTranslator t;
   //get from current translator languages list
   std::map<std::string, std::string> langsNamesAndCodes = t.getSupportedLanguagesNamesAndCodes();
   LanguagesList* langsList = new LanguagesList();
   for (auto& x : langsNamesAndCodes) {
       LanguageItem item(x.second, x.first); // >_<
       langsList->append(item);
   }
   return langsList;
   //mainView->showSupportedLangsList(langsNamesAndCodes);
}

