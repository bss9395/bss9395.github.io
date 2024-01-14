#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // QQmlApplicationEngine engine;
    // engine.load(QUrl("qrc:/main.qml"));


    QQmlApplicationEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/main.qml"));  // 注意根组件是非Window组件
    QQuickItem *item = qobject_cast<QQuickItem*>(component.create());
    qreal width = item->width();
    qDebug().noquote() << "width = " << width;

    return app.exec();
}
