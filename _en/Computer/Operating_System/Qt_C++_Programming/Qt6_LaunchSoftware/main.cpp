#include <QApplication>

#include "SoftwareCenter.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    SoftwareCenter softwareCenter;
    softwareCenter.launchSoftware("1234", "/home/chenwc6/下载/wps-office_11.8.2.1130.AK.preload.sw.withsn_amd64.deb", "");

    return a.exec();
}
