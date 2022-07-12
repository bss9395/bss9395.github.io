/* Main.cpp
Author: BSS9395
Update: 2022-07-11T23:36:00+08@China-Shanghai+08
Design: Recorder
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Recorder recorder;
    recorder.show();

    return application.exec();
}
