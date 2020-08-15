#include "mainview.h"
#include <QDebug>
#include <typeinfo>

MainView::MainView(QObject* _viewImpl)
    :mainPresenter(new MainPresenter(this)),
     viewImpl(_viewImpl)
{
    mainLayout = (static_cast<QQuickView*>(viewImpl))->rootObject();
    connectToSignals();
}

QString MainView::getSourceText()
{
    QObject *sourceTextRect = mainLayout->findChild<QObject*>("sourceTextRect");
    QObject *sourceTextItem = sourceTextRect->findChild<QObject*>("textArea");
    QString text(sourceTextItem->property("text").toString());
    return text;
}

QString MainView::getSourceLanguage()
{
    //QObject *sourceLangBox = mainLayout->findChild<QObject*>("sourceLangBox");
    return "English";
}

QString MainView::getDestLanguage()
{
   return "Russian";
}

void MainView::translateButtonClicked()
{
    qDebug() << "translate button clicked";
    mainPresenter->onTranslate();
}

void MainView::connectToSignals()
{
    //QObject* window = (static_cast<QQuickView*>(viewImpl))->rootObject();
    //QObject *mainLayout = window->findChild<QObject*>("mainLayout");
    QObject *translateBtn = mainLayout->findChild<QObject*>("translateBtn");
    QObject::connect(translateBtn, SIGNAL(clickedSignal()),
                     this, SLOT(translateButtonClicked()));
}
