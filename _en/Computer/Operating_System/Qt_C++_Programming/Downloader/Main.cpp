/* Main.cpp
Author: BSS9395
Update: 2022-03-27T01:40:00+08@China-Shanghai+08
Design: Downloader
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);

    Downloader downloader = Downloader();
    downloader.show();

    return application.exec();
}
