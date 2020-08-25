#include "translatorworker.h"

TranslatorWorker::TranslatorWorker(IMainView *mainView, QThread *thread, std::string _sourceText, std::string _destLang)
    :sourceText(_sourceText),
      destLang(_destLang)
{
    connect(thread, SIGNAL(started()), this, SLOT(process()));
    MainView *viewImpl = static_cast<MainView*>(mainView);
    connect(this, SIGNAL(translationIsReady(QString)), viewImpl, SLOT(translationIsReady(QString)));
    connect(this, SIGNAL(finished()), thread, SLOT(quit()));
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
}

TranslatorWorker::~TranslatorWorker()
{
    if (translator != NULL) {
        delete translator;
    }
}

void TranslatorWorker::process()
{
    translator = new GoogleTranslator();
    std::string translatedText = translator->translate(sourceText, destLang);
    emit translationIsReady(QString::fromStdString(translatedText));
    emit finished();
}
