#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Config.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    Config config;
    engine.rootContext()->setContextProperty("configcpp", &config);

    return app.exec();
}
