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

    qmlRegisterType<LangsListModel>("Languages", 1, 0, "LangsListModel");
    qmlRegisterUncreatableType<LanguagesList>("Languages", 1, 0, "LangsList",
                                                                                   QStringLiteral("Should not be created in QML"));
    //std::map<int, std::pair<std::string, std::string>>langsList;
    MainPresenter *mainPresenter = new MainPresenter();
    LanguagesList langsList = mainPresenter->loadLanguagesList();

    //QQuickView *mainViewImpl = new QQuickView(QUrl::fromLocalFile("../QuickTranslate/src/app/main.qml"));
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("languagesList"), QVariant::fromValue(&langsList));
    engine.load(QUrl::fromLocalFile("../QuickTranslate/src/app/main.qml"));
    //QQuickView *mainViewImpl = new QQuickView(QUrl::fromLocalFile("../QuickTranslate/src/app/main.qml"));
    //QQuickView *mainViewImpl = static_cast<QQuickView*>(engine.rootObjects().at(0));
    QObject *mainViewImpl = engine.rootObjects().at(0);


    //MainView *mainView = new MainView(mainViewImpl);

    //mainViewImpl->show();

    return app.exec();
}
