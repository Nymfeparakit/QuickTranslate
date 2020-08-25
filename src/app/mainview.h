#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "mainpresenter.h"
#include <QtQuick>
#include <QObject>

enum WindowName {
    NoWindow,
    WelcomeWindow,
    OnlyTranslatedTextWindow,
    MainWindow
};

class MainPresenter;

class MainView : public QObject, public IMainView
{
    Q_OBJECT
public:
    MainView() = default;
    MainView(QObject *_viewImpl, QClipboard *_clipboard);
    std::string getSourceText() override;
    std::string getSourceLanguage() override;
    std::string getDestLanguage() override;
    void showTranslatedText(std::string text) override;
    void showWelcomeWindow() override;
    void showMainWindow() override;
    void showOnlyTranslatedTextWindow() override;
    std::string getClipboardText() override;
    void setSourceText(std::string sourceText) override;
    void setTranslatedText(std::string text) override;
    std::string showBusyIndicator() override;
    std::string getTranslatedText();

public slots:
    void translateButtonClicked();
    void clipboardDataChanged();
    void welcomeWindowBtnClicked();
    void expandBtnClicked();
    void mainWindowClosed();
    void translationIsReady(QString);

private:
    MainPresenter* mainPresenter;
    QObject* viewImpl;
    QClipboard* clipboard;
    QString clipboardText;
    QString translatedClipboardText;
    WindowName currentWindowName;
    QObject* stackView;
    void connectToSignals();
};

#endif // MAINVIEW_H
