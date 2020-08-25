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
    connectToSignals();
    currentWindowName = NoWindow;
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

    if (currentItemNameStr == "translatedTextWindow") {
        QObject *currentWindow = viewImpl->findChild<QObject*>("translatedTextWindow");
        translatedTextRect = currentWindow->findChild<QObject*>("translatedTextRect");
    } else if (currentItemNameStr == "fullLayoutItem") {
        QObject *currentWindow = viewImpl->findChild<QObject*>("fullLayoutItem");
        translatedTextRect = currentWindow->findChild<QObject*>("translatedTextRect");
    }

    QObject *textArea = translatedTextRect->findChild<QObject*>("textArea");
    textArea->setProperty("text", text.c_str());
}

void MainView::showWelcomeWindow()
{
   QObject *welcomeWindow = viewImpl->findChild<QObject*>("welcomeButtonItem");
   QObject *stackView = viewImpl->findChild<QObject*>("stackView");
   QQuickItem currentItem;
   QPoint cursorPoint(QCursor::pos());
}

void MainView::showMainWindow()
{
    (static_cast<QQuickView*>(viewImpl))->show();
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

void MainView::mainWindowClosed()
{
    currentWindowName = NoWindow;
}

void MainView::translationIsReady(QString text)
{
    setTranslatedText(text.toStdString());
    showTranslatedText(text.toStdString());
}

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
