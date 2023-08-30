/* Main.cpp
Author: BSS9395
Update: 2023-08-30T09:39:00+08@China-Guangdong-Zhanjiang+08
*/

#include "Qt6_QMediaPlayer.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    Qt6_QMediaPlayer widget;
    widget.show();
    return application.exec();
}
