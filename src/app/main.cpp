#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainview.h"
#include "mainpresenter.h"
#include <langslistmodel.h>
#include "languageslist.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    qmlRegisterType<LangsListModel>("Languages", 1, 0, "LangsListModel");

    MainPresenter *mainPresenter = new MainPresenter();
    //MainView *mainViewTmp = new MainView();
    
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    QObject* mainViewImpl = engine.rootObjects().at(0);
    MainView *mainView = new MainView(mainViewImpl);

    QClipboard *clipboard = QGuiApplication::clipboard();
    QObject::connect(clipboard, SIGNAL(selectionChanged()),
                     mainView, SLOT(clipboardDataChanged()));

    return app.exec();
}
