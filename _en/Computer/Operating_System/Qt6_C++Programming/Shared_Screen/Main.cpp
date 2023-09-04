/* Shared_Screen.h
Author: BSS9395
Update: 2023-09-04T09:10:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Shared_Screen.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Shared_Screen widget;
    widget.show();

    return application.exec();
}
