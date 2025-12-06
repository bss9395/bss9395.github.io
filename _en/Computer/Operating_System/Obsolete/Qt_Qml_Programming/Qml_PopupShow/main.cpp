/// Record: main.cpp
/// Author: bss9395
/// Update: 2025-12-06T22:22:00+08$08@China-BeiJing
/// Keepin: bss9395@yeah.net

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}
