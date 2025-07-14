#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Config.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Grouped>("Custom", 1, 0, "Grouped");
    qmlRegisterType<Config>("Custom", 1, 0, "Config");
    qmlRegisterType<Attached>("Custom", 1, 0, "Attached");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}
