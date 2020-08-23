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
    std::string text = mainView->getSourceText();
    std::string destLang = mainView->getDestLanguage(); //get dest language
    //get translation
    GoogleTranslator t;
    std::string translatedText = t.translate(text, destLang);
    mainView->showTranslatedText(translatedText);
}

void MainPresenter::onClipboardDataChanged(std::string newClipboardData)
{
    mainView->showWelcomeWindow();
}

void MainPresenter::onOpenMainWindow()
{
   mainView->showMainWindow();
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
}


