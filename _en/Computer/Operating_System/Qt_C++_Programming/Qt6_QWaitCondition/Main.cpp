/* Main.cpp
Author: BSS9395
Update: 2023-08-31T09:49:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QWaitCondition.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt6_QWaitCondition widget;
    widget.show();
    return application.exec();
}
