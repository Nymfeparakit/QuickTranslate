#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainview.h"
#include "mainpresenter.h"
#include <langslistmodel.h>
#include "languageslist.h"
#include "cursorposprovider.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    // app should stil work when window closed
    app.setQuitOnLastWindowClosed(false);

    //register LangsListModel to use it in LanguageBox
    qmlRegisterType<LangsListModel>("Languages", 1, 0, "LangsListModel");
    CursorPosProvider cursorPosProvider;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cursorPosProvider", &cursorPosProvider);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    QObject* mainViewImpl = engine.rootObjects().at(0);
    QClipboard *clipboard = QGuiApplication::clipboard();
    MainView *mainView = new MainView(mainViewImpl, clipboard);

    return app.exec();
}
