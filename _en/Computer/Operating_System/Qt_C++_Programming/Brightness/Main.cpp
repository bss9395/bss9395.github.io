/* Main.cpp
Author: BSS9395
Update: 2023-02-07T23:48:00+08@China-Shanghai+08
Design: Brightness
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);
    Brightness brightness;
    brightness.show();

    return application.exec();
}
