#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket>
#include <QQuickView>
#include <QQmlContext>
#include "CursorPos.h"

int main(int argc, char *argv[]) {
    qDebug() << QSslSocket::sslLibraryBuildVersionString();

    QGuiApplication app(argc, argv);

//    QQuickView *view = new QQuickView();
//    view->setResizeMode(QQuickView::SizeRootObjectToView);
//    view->setSource(QUrl("qrc:/main.qml"));
//    view->show();


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.addImportPath("qrc:/");


    CursorPos cursorPos;
    engine.rootContext()->setContextProperty("cursorPos", &cursorPos);
    engine.load(url);
    return app.exec();
}
