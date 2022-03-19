/* Main.cpp
Author: BSS9395
Update: 2022-03-19T16:46:00+08@China-Shanghai+08
Design: Lookup
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);

    Lookup lookup;
    lookup.show();

    return application.exec();
}
