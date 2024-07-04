#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    // QQuickView *view = new QQuickView();
    // view->setResizeMode(QQuickView::SizeRootObjectToView);
    // view->setSource(QUrl("qrc:/main.qml"));
    // view->show();

    return app.exec();
}
