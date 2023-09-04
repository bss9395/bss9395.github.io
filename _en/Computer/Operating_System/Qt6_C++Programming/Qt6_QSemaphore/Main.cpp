/* Main.cpp
Author: BSS9395
Update: 2023-08-30T14:21:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QSemaphore.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt6_QSemaphore widget;
    widget.show();
    return application.exec();
}
