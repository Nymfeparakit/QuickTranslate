
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainview.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //if (engine.rootObjects().isEmpty())
    //    return -1;

    QQuickView *mainViewImpl = new QQuickView(QUrl::fromLocalFile("../QuickTranslate/QuickTranslate/main.qml"));

    MainView *mainView = new MainView(mainViewImpl);

    mainViewImpl->show();

    return app.exec();
}
