#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MyImageProvider.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImageProvider("myprovider", new MyImageProvider());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
