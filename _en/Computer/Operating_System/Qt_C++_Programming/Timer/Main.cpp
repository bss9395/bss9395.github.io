/* Main.cpp
Author: BSS9395
Update: 2022-01-09T01:21:00+08@China-Guangdong-Shenzhen+08
Design: Timer
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    Logger(__FUNCTION__);

    QApplication application(argc, argv);
    Timer timer;
    timer.show();
    return application.exec();
}
