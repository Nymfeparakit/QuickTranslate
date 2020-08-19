#include "mainview.h"
#include <QDebug>
#include <typeinfo>
#include <langslistmodel.h>

MainView::MainView(QObject* _viewImpl)
     :viewImpl(_viewImpl)
{
    //mainPresenter = new MainPresenter(this);
    mainLayout = (static_cast<QQuickView*>(viewImpl))->rootObject();
    connectToSignals();
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
    QObject *destLangBox = mainLayout->findChild<QObject*>("destLangBox");
    //destLangBox->itemData(sourceLangBox->currentIndex());
    return "Russian";
}

void MainView::showTranslatedText(std::string text)
{
    QObject *sourceTextRect = mainLayout->findChild<QObject*>("translatedTextRect");
    QObject *sourceTextItem = sourceTextRect->findChild<QObject*>("textArea");
    sourceTextItem->setProperty("text", text.c_str());
}

void MainView::showSupportedLangsList(std::map<std::string, std::string> langsMap)
{
    /*
    QObject *sourceLangBox = mainLayout->findChild<QObject*>("sourceLangBox");
    std::map<int, std::pair<std::string, std::string>> langsMapWithIndexes;
    int counter = 0;
    for (auto& item : langsMap) {
        langsMapWithIndexes.insert(std::pair<int, std::pair<std::string, std::string>>(counter, item));
    }
    LangsListModel langsModel(langsMapWithIndexes);
    */
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
