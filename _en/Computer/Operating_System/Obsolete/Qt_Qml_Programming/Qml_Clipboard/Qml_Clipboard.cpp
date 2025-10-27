/* Qml_Clipboard.cpp
Author: bss9395
Update: 2025/10/28T02:41:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#include <QGuiApplication>
#include <QApplication>
#include <QClipboard>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Clipboard.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Clipboard>("Custom", 1, 0, "Clipboard");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Qml_Clipboard.qml"));
    static Clipboard context_clipboard;
    engine.rootContext()->setContextProperty("context_clipboard", &context_clipboard);
    engine.load(url);

    return app.exec();
}
