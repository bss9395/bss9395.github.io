#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MutexLock.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MultiThread>("Module", 1, 0, "MultiThread");
    qmlRegisterType<MutexLock>("Module", 1, 0, "MutexLock");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}
