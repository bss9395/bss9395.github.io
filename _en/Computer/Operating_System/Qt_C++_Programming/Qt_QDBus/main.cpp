
#include <QApplication>
#include <QThread>
#include "SoftwareCenter.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Widget widget;
    widget.show();

    QString debpath = "/home/chenwc6/下载/todesk-v4.3.1.0-amd64.deb";
    SoftwareCenter softwareCenter;
    // softwareCenter.systemBusCall(debpath);
    softwareCenter.systemBusAsyncCall(debpath);

//    while(true) {
//        QThread::sleep(1);
//        qDebug() << "QThread::sleep(1);";
//    }

    return a.exec();
}
