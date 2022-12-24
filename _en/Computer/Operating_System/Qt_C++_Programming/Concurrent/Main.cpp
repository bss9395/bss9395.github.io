/* Main.cpp
Author: BSS9395
Update: 2022-12-23T22:19:00+08@China-Shanghai+08
Design: Concurrent
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);
    Concurrent concurrent = Concurrent();
    concurrent.show();
    return application.exec();
}
