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
    mainPresenter = std::unique_ptr<MainPresenter>(new MainPresenter(this));
    connectToSignals();
}

std::string MainView::getSourceText()
{
    QObject *sourceTextRect = viewImpl->findChild<QObject*>("sourceTextRect");
    QObject *sourceTextItem = sourceTextRect->findChild<QObject*>("textArea");
    QString text(sourceTextItem->property("text").toString());
    return text.toStdString();
}

std::string MainView::getSourceLanguage()
{
    QObject *sourceLangBox = viewImpl->findChild<QObject*>("sourceLangBox");
    QString selectedLanguage = sourceLangBox->property("currentText").toString();
    return selectedLanguage.toStdString();
}

std::string MainView::getDestLanguage()
{
    QObject *destLangBox = viewImpl->findChild<QObject*>("destLangBox");
    QString selectedLanguage = destLangBox->property("currentText").toString();
    return selectedLanguage.toStdString();
}

void MainView::showTranslatedText(std::string text)
{
    QObject *translatedTextRect;
    QObject *stackView = viewImpl->findChild<QObject*>("stackView");
    QVariant currentItemName;
    QMetaObject::invokeMethod(viewImpl, "getCurrentItemName",
                              Q_RETURN_ARG(QVariant, currentItemName));
    QString currentItemNameStr = currentItemName.toString();

    //place where the translated text should appear depends on which window is currently open
    if (currentItemNameStr == "translatedTextWindow") {
        QObject *currentWindow = viewImpl->findChild<QObject*>("translatedTextWindow");
        translatedTextRect = currentWindow->findChild<QObject*>("translatedTextRect");
    } else if (currentItemNameStr == "fullLayoutItem") {
        QObject *currentWindow = viewImpl->findChild<QObject*>("fullLayoutItem");
        translatedTextRect = currentWindow->findChild<QObject*>("translatedTextRect");
    }

    QObject *textArea = translatedTextRect->findChild<QObject*>("textArea");
    textArea->setProperty("text", text.c_str()); //set translated text in area
}

std::string MainView::getClipboardText()
{
    return clipboardText.toStdString();
}

void MainView::setSourceText(std::string sourceText)
{
    QObject *sourceTextRect = viewImpl->findChild<QObject*>("sourceTextRect");
    QObject *sourceTextItem = sourceTextRect->findChild<QObject*>("textArea");
    sourceTextItem->setProperty("text", sourceText.c_str());
}

void MainView::setTranslatedText(std::string text)
{
    translatedClipboardText = QString::fromStdString(text);
}

std::string MainView::showBusyIndicator()
{
    QMetaObject::invokeMethod(viewImpl, "showBusyIndicator");
}

std::string MainView::getTranslatedText()
{
   return translatedClipboardText.toStdString();
}

void MainView::translateButtonClicked()
{
    mainPresenter->onTranslate();
}

//currently gets data only for X11 selection
void MainView::clipboardDataChanged()
{
    clipboardText = clipboard->text(QClipboard::Selection);//get current clipboard data
    QMetaObject::invokeMethod(viewImpl, "onClipboardDataChanged");
}

void MainView::welcomeWindowBtnClicked()
{
    mainPresenter->onOpenTranslatedTextWindow();
}

void MainView::expandBtnClicked()
{
    mainPresenter->onOpenMainWindow();
}

void MainView::translationIsReady(QString text)
{
    setTranslatedText(text.toStdString());
    showTranslatedText(text.toStdString());
}

// connect slots to signals of qml elements
void MainView::connectToSignals()
{

    QObject::connect(viewImpl, SIGNAL(translateBtnClicked()),
                     this, SLOT(translateButtonClicked()));
    QObject::connect(clipboard, SIGNAL(selectionChanged()),
                     this, SLOT(clipboardDataChanged()));
    QObject::connect(viewImpl, SIGNAL(welcomeButtonClicked()),
                     this, SLOT(welcomeWindowBtnClicked()));
    QObject::connect(viewImpl, SIGNAL(expandBtnClicked()),
                     this, SLOT(expandBtnClicked()));
    //QObject::connect(viewImpl, SIGNAL(fullWindowClosed()),
                     //this, SLOT(mainWindowClosed()));

}
