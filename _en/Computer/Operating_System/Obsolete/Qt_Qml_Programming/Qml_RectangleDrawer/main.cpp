#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Config.h"

int main(int argc, char *argv[])
{
    Config app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);
    engine.rootContext()->setContextProperty("app", &app);
    engine.rootContext()->setContextProperty("config", &app);

    return app.exec();
}
