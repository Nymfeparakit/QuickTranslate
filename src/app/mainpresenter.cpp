#include "mainpresenter.h"
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
    std::string translatedText = translator.translate(text, destLang);
    mainView->showTranslatedText(translatedText);
}

void MainPresenter::onClipboardDataChanged(std::string newClipboardData)
{
    mainView->showWelcomeWindow();
}

void MainPresenter::onWelcomeWindowBtnClicked()
{
   mainView->showOnlyTranslatedTextWindow();
   std::string currentClipboardText(mainView->getClipboardText());
   std::string translatedText = translator.translate(currentClipboardText, "ru");
   mainView->showTranslatedText(translatedText);
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


