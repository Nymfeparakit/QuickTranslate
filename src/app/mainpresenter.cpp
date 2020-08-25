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

void MainPresenter::onClipboardDataChanged()
{
   std::string currentClipboardText(mainView->getClipboardText());
   //std::string translatedText = translator.translate(currentClipboardText, "ru");
   //mainView->setTranslatedText(translatedText);
    //mainView->showWelcomeWindow();
}

void MainPresenter::onOpenTranslatedTextWindow()
{
   std::string currentClipboardText(mainView->getClipboardText());
   QThread *thread = new QThread;
   TranslatorWorker *worker = new TranslatorWorker(mainView, thread, currentClipboardText, "ru");
   worker->moveToThread(thread);
   thread->start();
}

void MainPresenter::onOpenMainWindow()
{
   std::string translatedText = mainView->getTranslatedText();
   std::string currentClipboardText(mainView->getClipboardText());
   mainView->setSourceText(currentClipboardText);
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


