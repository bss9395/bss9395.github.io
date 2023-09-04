/* Main.cpp
Author: BSS9395
Update: 2023-09-01T17:13:00+08@China-Guangdong-Zhanjiang+08
*/


#include "Qt6_UDP_Multicast.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_UDP_Multicast peer0;
    peer0.show();

    Qt6_UDP_Multicast peer1;
    peer1.show();

    return application.exec();
}
