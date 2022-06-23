/* Main.cpp
Author: BSS9395
Update: 2022-06-23T21:53:00+08@China-Shanghai+08
Design: FileSystem
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);

    FileSystem file_system;
    file_system.show();

    return application.exec();
}
