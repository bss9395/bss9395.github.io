#include "mainwindow.h"
#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return application.exec();
}
