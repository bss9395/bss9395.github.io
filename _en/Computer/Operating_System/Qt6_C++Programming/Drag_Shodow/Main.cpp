/* Main.cpp
Author: BSS9395
Update: 2023-09-04T10:56:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Drag_Shadow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Drag_Shadow w;
    w.show();
    return a.exec();
}
