/* Main.cpp
Author: BSS9395
Update: 2023-08-14T08:27:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt_Manual_UI.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Qt_Manual_UI w;
    w.show();
    return a.exec();
}
