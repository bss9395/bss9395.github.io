/* Main.cpp
Author: BSS9395
Update: 2023-09-01T14:45:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_UDP_Peer.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_UDP_Peer peer0;
    peer0._ui->SB_Port_Bound->setValue(9395);
    peer0._ui->SB_Port_Destination->setValue(9396);
    peer0.show();

    Qt6_UDP_Peer peer1;
    peer1._ui->SB_Port_Bound->setValue(9396);
    peer1._ui->SB_Port_Destination->setValue(9395);
    peer1.show();

    return application.exec();
}
