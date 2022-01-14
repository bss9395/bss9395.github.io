/* Main.cpp
Author: BSS9395
Update: 2022-01-11T21:16:00+08@China-Guangdong-Shenzhen+08
Design: Sketch
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    Logging(__FUNCTION__);

    QApplication application(argc, argv);
    Sketch sketch;
    sketch.show();
    return application.exec();
}
