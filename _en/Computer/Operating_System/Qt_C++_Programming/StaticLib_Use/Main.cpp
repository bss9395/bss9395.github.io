/* Main.cpp
Author: BSS9395
Update: 2022-07-24T21:41:00+08@China-Shanghai+08
Design: StaticLib_Use
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    // Widget_Pen widget_pen;
    // widget_pen.show();

    StaticLib_Use staticlib_use;
    staticlib_use.show();

    return application.exec();
    return 0;
}
