/* Main.cpp
Author: BSS9395
Update: 2023-08-30T15:43:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QProgressBar.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt_QProgressBar widget;
    widget.show();
    return application.exec();
}
