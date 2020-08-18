#include "mainview.h"
#include <QDebug>
#include <typeinfo>

MainView::MainView(QObject* _viewImpl)
     :viewImpl(_viewImpl)
{
    mainPresenter = new MainPresenter(this);
    mainLayout = (static_cast<QQuickView*>(viewImpl))->rootObject();
    connectToSignals();
    //mainPresenter->onTranslate();
}

std::string MainView::getSourceText()
{
    QObject *sourceTextRect = mainLayout->findChild<QObject*>("sourceTextRect");
    QObject *sourceTextItem = sourceTextRect->findChild<QObject*>("textArea");
    QString text(sourceTextItem->property("text").toString());
    return text.toStdString();
}

std::string MainView::getSourceLanguage()
{
    QObject *sourceLangBox = mainLayout->findChild<QObject*>("sourceLangBox");
    //sourceLangBox->itemData(sourceLangBox->currentIndex());
    return "English";
}

std::string MainView::getDestLanguage()
{
   return "Russian";
}

void MainView::translateButtonClicked()
{
    //qDebug() << "translate button clicked";
    mainPresenter->onTranslate();
}

void MainView::connectToSignals()
{
    QObject *translateBtn = mainLayout->findChild<QObject*>("translateBtn");
    QObject::connect(translateBtn, SIGNAL(clickedSignal()),
                     this, SLOT(translateButtonClicked()));
}
