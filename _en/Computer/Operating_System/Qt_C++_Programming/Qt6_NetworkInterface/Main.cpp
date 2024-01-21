/* Main.cpp
Author: BSS9395
Update: 2023-08-31T16:26:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QNetworkInterface.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt6_QNetworkInterface widget;
    widget.show();
    return application.exec();
}
