#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "mainpresenter.h"
#include <QtQuick>

class MainView : public IMainView
{
    Q_OBJECT
public:
    MainView(QObject* _viewImpl);
    QString getSourceText();
    QString getSourceLanguage();
    QString getDestLanguage();

public slots:
    void translateButtonClicked();
    void connectToSignals();

private:
    MainPresenter* mainPresenter;
    QObject* viewImpl;
    QObject* mainLayout;
};

#endif // MAINVIEW_H
