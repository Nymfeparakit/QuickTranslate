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

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    QObject* mainViewImpl = engine.rootObjects().at(0);
    QClipboard *clipboard = QGuiApplication::clipboard();
    MainView *mainView = new MainView(mainViewImpl, clipboard);

    return app.exec();
}
