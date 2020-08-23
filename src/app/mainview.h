#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "mainpresenter.h"
#include <QtQuick>
#include <QObject>

class MainView : public QObject, IMainView
{
    Q_OBJECT
public:
    MainView() = default;
    MainView(QObject* _viewImpl);
    std::string getSourceText();
    std::string getSourceLanguage();
    std::string getDestLanguage();
    void showTranslatedText(std::string text);
    void showSupportedLangsList(std::map<std::string, std::string>);

public slots:
    void translateButtonClicked();
    void clipboardDataChanged();

private:
    MainPresenter* mainPresenter;
    QObject* viewImpl;
    QObject* mainLayout;
    void connectToSignals();
};

#endif // MAINVIEW_H
