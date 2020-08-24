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

class MainView : public QObject, IMainView
{
    Q_OBJECT
public:
    MainView() = default;
    MainView(QObject *_viewImpl, QClipboard *_clipboard);
    std::string getSourceText() override;
    std::string getSourceLanguage() override;
    std::string getDestLanguage() override;
    void showTranslatedText(std::string text) override;
    void showSupportedLangsList(std::map<std::string, std::string>);
    void showWelcomeWindow() override;
    void showMainWindow() override;
    void showOnlyTranslatedTextWindow() override;
    std::string getClipboardText() override;
    void setSourceText(std::string sourceText) override;

public slots:
    void translateButtonClicked();
    void clipboardDataChanged();
    void welcomeWindowBtnClicked();
    void expandBtnClicked();

private:
    MainPresenter* mainPresenter;
    QObject* viewImpl;
    QClipboard* clipboard;
    QObject* mainLayout;
    QString clipboardText;
    WindowName currentWindowName;
    void connectToSignals();
};

#endif // MAINVIEW_H
