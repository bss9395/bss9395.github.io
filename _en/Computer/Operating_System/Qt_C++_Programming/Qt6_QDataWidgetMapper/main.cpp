/* Main.cpp
Author: BSS9395
Update: 2023-09-11T14:30:00+08@China-Guangdong-Zhanjiang+08
*/


#include "Qt6_QDataWidgetMapper.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_QSqlDatabase widget;
    widget.show();

    return application.exec();
}
