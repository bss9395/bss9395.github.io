/* Main.cpp
Author: BSS9395
Update: 2022-07-17T16:42:00+08@China-Shanghai+08
Design: Playback
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Playback playback;
    playback.show();

    return application.exec();
}
