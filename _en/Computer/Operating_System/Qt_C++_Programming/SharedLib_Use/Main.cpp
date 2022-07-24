/* Main.cpp
Author: BSS9395
Update: 2022-07-25T00:06:00+08@China-Shanghai+08
Design: SharedLib_Use
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    // Widget_Pen widget_pen;
    // widget_pen.show();

    SharedLib_Use sharedlib_use;
    sharedlib_use.show();

    return application.exec();
    return 0;
}
