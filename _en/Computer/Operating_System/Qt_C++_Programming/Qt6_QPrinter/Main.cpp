/* Main.cpp
Author: BSS9395
Update: 2023-09-07T10:48:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QPrinter.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_Qimage widget;
    widget.show();

    return application.exec();
}
