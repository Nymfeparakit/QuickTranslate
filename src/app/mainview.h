#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "mainpresenter.h"
#include <QtQuick>
#include <QObject>
#include <memory>

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
    std::string getClipboardText() override;
    void setSourceText(std::string sourceText) override;
    void setTranslatedText(std::string text) override;
    std::string showBusyIndicator() override;
    std::string getTranslatedText();

public slots:
    void translateButtonClicked();
    void clipboardDataChanged();
    void welcomeWindowBtnClicked();
    void expandBtnClicked(); // button to expand to main window is clicked
    void translationIsReady(QString);

private:
    std::unique_ptr<MainPresenter> mainPresenter;
    QObject* viewImpl; // implementation of view in qml
    QClipboard* clipboard;
    QString clipboardText;
    QString translatedClipboardText;
    QObject* stackView; // stackview that always contains one current visible item
    void connectToSignals();
};

#endif // MAINVIEW_H
