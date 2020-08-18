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
    //std::string translatedText = t.translate(text, destLang, sourceLang);
    t.translate(text, destLang, sourceLang);
    int a = 0;
    //передаем текст view
}

