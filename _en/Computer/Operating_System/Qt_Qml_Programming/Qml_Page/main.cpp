#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket>
#include <QQuickView>

int main(int argc, char *argv[])
{
    qDebug() << QSslSocket::sslLibraryBuildVersionString();

    QGuiApplication app(argc, argv);

//    QQuickView *view = new QQuickView();
//    view->setResizeMode(QQuickView::SizeRootObjectToView);
//    view->setSource(QUrl("qrc:/main.qml"));
//    // QWidget *widget = QWidget::createWindowContainer(view);
//    // widget->show();
//    view->show();


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.addImportPath("qrc:/");
    engine.load(url);

    return app.exec();
}
