/* Main.cpp
Author: BSS9395
Update: 2023-09-05T15:47:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QPainter.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_QPainter widget;
    widget.show();

    return application.exec();
}
