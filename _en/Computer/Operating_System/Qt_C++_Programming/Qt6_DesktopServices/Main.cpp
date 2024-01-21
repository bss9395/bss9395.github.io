/* Main.cpp
Author: BSS9395
Update: 2023-09-04T15:45:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QDesktopServices.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Qt6_QNetworkServices w;
    w.show();
    return a.exec();
}
