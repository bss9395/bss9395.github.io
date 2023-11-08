#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView();
    view->setSource(QUrl("qrc:/Qml_Resources/main.qml"));
    view->show();

    return app.exec();
}
