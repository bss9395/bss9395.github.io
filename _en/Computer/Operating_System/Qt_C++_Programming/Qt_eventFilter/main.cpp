/* Main.cpp
Author: bss9395
Update: 2025/10/19T20:19:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#include <QApplication>
#include "Qt_eventFilter.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Main window;
    window.show();

    return application.exec();
}
