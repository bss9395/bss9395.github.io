
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "Config.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;  // qml根组件是window组件
    engine.rootContext()->setContextProperty("configcpp", &Config::instance());
    engine.load(QUrl("qrc:/main.qml"));


//    QQuickView *view = new QQuickView();  // qml根组件是非window组件
//    view->rootContext()->setContextProperty("configcpp", &Config::instance());  // setContextProperty()在setSource()之前
//    view->setSource(QUrl("qrc:/main.qml"));
//    view->show();

    return app.exec();
}
