/* Main.cpp
Author: BSS9395
Update: 2023-09-11T16:12:00+08@China-Guangdong-Zhangjiang+08
*/

#include "Qt6_QSqlQueryModel.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_QSqlQueryModel widget;
    widget.show();

    return application.exec();
}
