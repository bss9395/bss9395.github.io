/* Main.cpp
Author: BSS9395
Update: 2022-07-12T23:00:00+08@China-Shanghai+08
Design: Oscillometer
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Oscillometer oscillometer;
    oscillometer.show();

    return application.exec();
}
