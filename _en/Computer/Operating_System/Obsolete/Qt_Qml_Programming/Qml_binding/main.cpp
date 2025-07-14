#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView();
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl("qrc:/main.qml"));
    view->show();

    return app.exec();
}
