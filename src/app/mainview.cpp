#include "mainview.h"
#include <QDebug>
#include <typeinfo>
#include <langslistmodel.h>
#include <iostream>
#include <QCursor>

MainView::MainView(QObject* _viewImpl, QClipboard *_clipboard)
     :viewImpl(_viewImpl),
       clipboard(_clipboard)
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
    QObject *translatedTextRect;

    if (currentWindowName == OnlyTranslatedTextWindow)
    {
        QObject *currentWindow = viewImpl->findChild<QObject*>("onlyTranslatedTextWindow");
        translatedTextRect = currentWindow->findChild<QObject*>("translatedTextRect");
    }
    else if (currentWindowName == MainWindow)
    {
        translatedTextRect = mainLayout->findChild<QObject*>("translatedTextRect");
    }
    QObject *textArea = translatedTextRect->findChild<QObject*>("textArea");
    textArea->setProperty("text", text.c_str());
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

void MainView::showWelcomeWindow()
{
   QObject *welcomeWindow = viewImpl->findChild<QObject*>("welcomeWindow");
   QPoint cursorPoint(QCursor::pos());
   welcomeWindow->setProperty("x", cursorPoint.x());
   welcomeWindow->setProperty("y", cursorPoint.y());
   (static_cast<QQuickView*>(welcomeWindow))->show();
   currentWindowName = WelcomeWindow;
}

void MainView::showMainWindow()
{
    (static_cast<QQuickView*>(viewImpl))->show();
    currentWindowName = MainWindow;
}

void MainView::showOnlyTranslatedTextWindow()
{
   QObject *translatedTextWindow = viewImpl->findChild<QObject*>("onlyTranslatedTextWindow");
   QPoint cursorPoint(QCursor::pos());
   //translatedTextWindow->setProperty("x", cursorPoint.x());
   //translatedTextWindow->setProperty("y", cursorPoint.y());
   //(static_cast<QQuickView*>(translatedTextWindow))->show();
   currentWindowName = OnlyTranslatedTextWindow;
}

std::string MainView::getClipboardText()
{
    return clipboardText.toStdString();
}

void MainView::setSourceText(std::string sourceText)
{
    QObject *sourceTextRect = mainLayout->findChild<QObject*>("sourceTextRect");
    QObject *sourceTextItem = sourceTextRect->findChild<QObject*>("textArea");
    sourceTextItem->setProperty("text", sourceText.c_str());
}

void MainView::translateButtonClicked()
{
    mainPresenter->onTranslate();
}

void MainView::clipboardDataChanged()
{
   clipboardText = clipboard->text(QClipboard::Selection);//get current clipboard data
   mainPresenter->onClipboardDataChanged(clipboardText.toStdString());
}

void MainView::welcomeWindowBtnClicked()
{
    mainPresenter->onWelcomeWindowBtnClicked();
}

void MainView::connectToSignals()
{
    QObject *translateBtn = mainLayout->findChild<QObject*>("translateBtn");
    QObject::connect(translateBtn, SIGNAL(clickedSignal()),
                     this, SLOT(translateButtonClicked()));
    QObject::connect(clipboard, SIGNAL(selectionChanged()),
                     this, SLOT(clipboardDataChanged()));
    QObject *welcomeWindow = viewImpl->findChild<QObject*>("welcomeWindow");
    QObject::connect(welcomeWindow, SIGNAL(onWelcomeWindowBtnClicked()),
                     this, SLOT(welcomeWindowBtnClicked()));
}
