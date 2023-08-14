/* Main.cpp
Author: BSS9395
Update: 2023-08-13T19:44:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt_Property.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_Property w;
    w.show();
    return a.exec();
}
