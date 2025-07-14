#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "Config.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Config>("Module_Config", 1, 0, "Type_Config");  // 注册 C++ 类型为 QML 类型

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}
