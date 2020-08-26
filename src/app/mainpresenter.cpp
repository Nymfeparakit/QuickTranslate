#include "mainpresenter.h"
#include <QDebug>
#include <iostream>

MainPresenter::MainPresenter(IMainView* _mainView)
    :mainView(_mainView)
{
}

void MainPresenter::onTranslate()
{
    std::string text = mainView->getSourceText(); // text that should be translated
    std::string destLang = mainView->getDestLanguage(); // get dest language
    std::string translatedText = translator.translate(text, destLang); // get translation
    mainView->showTranslatedText(translatedText);
}

void MainPresenter::onOpenTranslatedTextWindow()
{
   std::string currentClipboardText(mainView->getClipboardText()); //get current clipboard text
   QThread *thread = new QThread;
   TranslatorWorker *worker = new TranslatorWorker(mainView, thread, currentClipboardText, "ru");
   worker->moveToThread(thread);
   thread->start(); // make a translation in separate thread
}

//method is called when main window opens
void MainPresenter::onOpenMainWindow()
{
    //text was already translated, so just get it from view
   std::string translatedText = mainView->getTranslatedText();
   std::string currentClipboardText(mainView->getClipboardText());
   mainView->setSourceText(currentClipboardText);
   mainView->showTranslatedText(translatedText);
}

// get a list of languages supported by the current translator
LanguagesList *MainPresenter::loadLanguagesList()
{
   GoogleTranslator t;
   //get from current translator languages list
   std::map<std::string, std::string> langsNamesAndCodes = t.getSupportedLanguagesNamesAndCodes();
   // map -> LanguagesList
   LanguagesList* langsList = new LanguagesList();
   for (auto& x : langsNamesAndCodes) {
       LanguageItem item(x.second, x.first);
       langsList->append(item);
   }
   return langsList;
}


