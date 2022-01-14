/* Main.cpp
Author: BSS9395
Update: 2022-01-15T01:30:00+08@China-Guangdong-Shenzhen+08
Design: File Explorer
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    Logging(__FUNCTION__);

    QApplication application(argc, argv);
    File_System file_system;
    file_system.show();
    return application.exec();
}
