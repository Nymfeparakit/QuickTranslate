#include "mainpresenter.h"

MainPresenter::MainPresenter(IMainView* _mainView)
    :mainView(_mainView)
{

}

void MainPresenter::onTranslate()
{
    //TODO replace QString with c++ string
    QString text = mainView->getSourceText();//достаем текст источника от view
    //достаем source, dest языки
    QString sourceLang = mainView->getSourceLanguage();
    QString destLang = mainView->getDestLanguage();
    //получаем перевод
    //передаем текст view
}

