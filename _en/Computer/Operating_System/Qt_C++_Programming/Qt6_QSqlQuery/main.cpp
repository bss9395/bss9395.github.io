/* Qt6_QSqlQuery.h
Author: BSS9395
Update: 2023-09-12T12:20:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QSqlQuery.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt6_QSqlQuery widget;
    widget.show();

    return application.exec();
}
