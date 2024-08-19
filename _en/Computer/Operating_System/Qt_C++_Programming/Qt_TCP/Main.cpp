/* Qt_TCP
Author: BSS9395
Update: 2023-09-01T10:14:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt_TCP_Server.h"
#include "Qt_TCP_Client.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt_TCP_Client client;
    client.show();

    Qt_TCP_Server server;
    server.show();

    return application.exec();
}
