#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQuickItem>
#include <QDebug>
#include <QQuickView>
#include <QDate>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    QVariantList list;
    list << 10 << QColor(Qt::green) << "bottles";
    QVariantMap map;
    map.insert("language", "QML");
    map.insert("released", QDate(2010, 9, 21));
    QMetaObject::invokeMethod(engine.rootObjects()[0], "readValues",
                              Q_ARG(QVariant, QVariant::fromValue(list)),
                              Q_ARG(QVariant, QVariant::fromValue(map)));


//    QQuickView view;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    view.setSource(url);
//    view.show();

//    QVariantList list;
//    list << 10 << QColor(Qt::green) << "bottles";
//    QVariantMap map;
//    map.insert("language", "QML");
//    map.insert("released", QDate(2010, 9, 21));
//    QMetaObject::invokeMethod(view.rootObject(), "readValues",
//                              Q_ARG(QVariant, QVariant::fromValue(list)),
//                              Q_ARG(QVariant, QVariant::fromValue(map)));

    return app.exec();
}
