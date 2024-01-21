/* Main.cpp
Author: BSS9395
Update: 2023-09-07T16:52:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_dropEvent.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_dropEvent widget;
    widget.show();

    return application.exec();
}
