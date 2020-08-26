#ifndef TRANSLATORWORKER_H
#define TRANSLATORWORKER_H
#include <QObject>
#include "googletranslator.h"
#include <string>
#include "mainview.h"
#include "imainview.h"
#include <QThread>

class MainView;

// class that supposed to be moved to separate thread to do translation work
class TranslatorWorker : public QObject {
  Q_OBJECT

private:
    GoogleTranslator *translator;
    std::string sourceText;
    std::string destLang;

public:
    TranslatorWorker(IMainView *mainView, QThread *thread, std::string _sourceText, std::string _destLang);
    ~TranslatorWorker();

public slots:
    void process();

signals:
    void finished();
    void translationIsReady(QString translatedText);
};

#endif
