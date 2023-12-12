#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    engine.load(url);

//    QQuickItem *item = engine.rootObjects().first()->findChild<QQuickItem *>("myRect");
//    if(item != nullptr) {
//        item->setProperty("color", QColor(Qt::yellow));
//    }

    ////////////////////////////////////

    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    QQuickItem *item = view.rootObject()->findChild<QQuickItem *>("object_rectangle");
    if(item != nullptr) {
        item->setProperty("color", QColor(Qt::yellow));
    }

    return app.exec();
}
