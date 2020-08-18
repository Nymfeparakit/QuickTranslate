#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainview.h"
#include "mainpresenter.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickView *mainViewImpl = new QQuickView(QUrl::fromLocalFile("../QuickTranslate/src/app/main.qml"));

    MainView *mainView = new MainView(mainViewImpl);

    mainViewImpl->show();

    return app.exec();
}
