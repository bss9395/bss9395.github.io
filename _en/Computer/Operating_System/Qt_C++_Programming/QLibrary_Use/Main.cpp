/* Main.cpp
Author: BSS9395
Update: 2022-07-25T01:45:00+08@China-Shanghai+08
Design: QLibrary_Use
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    QLibrary_Use qlibrary_use;
    qlibrary_use.show();

    return application.exec();
}
