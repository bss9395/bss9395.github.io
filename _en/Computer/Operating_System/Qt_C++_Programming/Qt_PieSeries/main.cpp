#include "mainwindow.h"
#include "MainWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget mainWidget;
    mainWidget.show();

    // MainWindow w;
    // w.show();
    return QApplication::exec();
}
