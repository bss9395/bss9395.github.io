#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.addImportPath("qrc:/");
    engine.load(url);

//    QQuickView *view = new QQuickView();
//    view->setResizeMode(QQuickView::SizeRootObjectToView);
//    view->setSource(QUrl("qrc:/main.qml"));
//    view->show();

    return app.exec();
}
