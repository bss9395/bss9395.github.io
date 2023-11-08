#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QSslSocket>

int main(int argc, char *argv[])
{
    qDebug() << QSslSocket::sslLibraryBuildVersionString();

    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView();
    view->setResizeMode(QQuickView::SizeRootObjectToView);
    view->setSource(QUrl("qrc:/main.qml"));
    // QWidget *widget = QWidget::createWindowContainer(view);
    // widget->show();
    view->show();

    return app.exec();
}
