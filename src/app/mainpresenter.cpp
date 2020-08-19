#include "mainpresenter.h"
#include "googletranslator.h"
#include <QDebug>
#include <iostream>

/*MainPresenter::MainPresenter(IMainView* _mainView)
    :mainView(_mainView)
{
    loadLanguagesList();
}*/

MainPresenter::MainPresenter()
{

}

void MainPresenter::onTranslate()
{
    //TODO replace QString with c++ string
    std::string text = mainView->getSourceText();//достаем текст источника от view
    //qDebug() << "Source text: " << QString::fromStdString(text);
    //std::cout << "Source text: " << text;
    //достаем source, dest языки
    std::string sourceLang = mainView->getSourceLanguage();
    //qDebug() << "Source lang: " << QString::fromStdString(sourceLang);
    std::string destLang = mainView->getDestLanguage();
    //qDebug() << "Dest lang: " << QString::fromStdString(destLang);
    //получаем перевод
    qDebug() << "ready to translate text 2";
    GoogleTranslator t;
    std::string translatedText = t.translate(text, destLang, sourceLang);
    std::cout << "presenter got translated text: " << translatedText << std::endl;
    mainView->showTranslatedText(translatedText); //передаем текст view
}

LanguagesList& MainPresenter::loadLanguagesList()
{
   GoogleTranslator t;
   //get from current translator languages list
   std::map<std::string, std::string> langsNamesAndCodes = t.getSupportedLanguagesNamesAndCodes();
   LanguagesList langsList;
   for (auto& x : langsNamesAndCodes) {
       LanguageItem item(x.first, x.second);
       langsList.append(item);
   }
   return langsList;
   //mainView->showSupportedLangsList(langsNamesAndCodes);
}

