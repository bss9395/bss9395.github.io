/* Main.cpp
Author: BSS9395
Update: 2023-08-30T18:07:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QThread.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt6_QThread widget;
    widget.show();
    return application.exec();
}
