#include "mainview.h"
#include <QDebug>
#include <typeinfo>
#include <langslistmodel.h>

MainView::MainView(QObject* _viewImpl)
     :viewImpl(_viewImpl)
{
    mainPresenter = new MainPresenter(this);
    mainLayout = (static_cast<QQuickView*>(viewImpl))->rootObject();
    mainLayout = viewImpl->children().at(1);
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
    QString selectedLanguage = sourceLangBox->property("currentText").toString();
    return selectedLanguage.toStdString();
}

std::string MainView::getDestLanguage()
{
    QObject *destLangBox = mainLayout->findChild<QObject*>("destLangBox");
    QString selectedLanguage = destLangBox->property("currentText").toString();
    return selectedLanguage.toStdString();
}

void MainView::showTranslatedText(std::string text)
{
    QObject *translatedTextRect = mainLayout->findChild<QObject*>("translatedTextRect");
    QObject *textArea = translatedTextRect->findChild<QObject*>("textArea");
    textArea->setProperty("text", text.c_str());

    //QObject *translatedTextItem = mainLayout->findChild<QObject*>("translatedText");
    //translatedTextItem->setProperty("text", text.c_str());
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
    mainPresenter->onTranslate();
}

void MainView::connectToSignals()
{
    QObject *translateBtn = mainLayout->findChild<QObject*>("translateBtn");
    QObject::connect(translateBtn, SIGNAL(clickedSignal()),
                     this, SLOT(translateButtonClicked()));
}
