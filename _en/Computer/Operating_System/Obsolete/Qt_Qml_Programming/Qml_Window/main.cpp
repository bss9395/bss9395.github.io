#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSslSocket>
#include <QQuickView>

int main(int argc, char *argv[])
{
    qDebug() << QSslSocket::sslLibraryBuildVersionString();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.addImportPath("qrc:/");
    engine.load(url);

    return app.exec();
}
