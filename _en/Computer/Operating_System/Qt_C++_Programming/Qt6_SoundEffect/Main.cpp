/* Main.cpp
Author: BS9395
Update: 2023-8-30T11:33:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_SoundEffect.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt6_SoundEffect widget;
    widget.show();
    return application.exec();
}
