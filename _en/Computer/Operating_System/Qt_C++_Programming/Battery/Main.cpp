/* Main.cpp
Author: BSS9395
Update: 2022-07-22T01:23:00+08@China-Shanghai+08
Design: Battery
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Battery battery;
    battery.show();

    return application.exec();
}
