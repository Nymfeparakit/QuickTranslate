#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "mainpresenter.h"
#include <QtQuick>

class MainView : public IMainView
{
    Q_OBJECT
public:
    MainView(QObject* _viewImpl);
    std::string getSourceText();
    std::string getSourceLanguage();
    std::string getDestLanguage();
    void connectToSignals();

public slots:
    void translateButtonClicked();

private:
    MainPresenter* mainPresenter;
    QObject* viewImpl;
    QObject* mainLayout;
};

#endif // MAINVIEW_H
