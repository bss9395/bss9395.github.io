/* Main.cpp
Author: BSS9395
Update: 2023-09-01T10:14:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_TCP_Server.h"
#include "Qt6_TCP_Client.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_TCP_Client client;
    client.show();

    Qt6_TCP_Server server;
    server.show();

    return application.exec();
}
