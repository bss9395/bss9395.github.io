/* Main.cpp
Author: BSS9395
Update: 2023-08-30T18:54:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QMutex.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt6_QMutex wiget;
    wiget.show();
    return application.exec();
}
