/* Main.cpp
Author: BSS9395
Update: 2022-06-28T23:53:00+08@China-Shanghai+08
Design: Graphics
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Graphics graphics;
    graphics.show();

    return application.exec();
}
