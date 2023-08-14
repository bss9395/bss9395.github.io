/* Main.cpp
Author: BSS9395
Update: 2023-08-14T08:24:00+08@China-Guangdong-Zhanjiang+08
*/


#include "Qt_Signal_Slot.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Qt_Signal_Slot w;
    w.show();
    return a.exec();
}
