/* Main.cpp
Author: BSS9395
Update: 2022-12-06T22:22:00+08@China-Shanghai+08
Design: Transform
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);

    Transform transform;
    transform.show();

    return application.exec();
}
