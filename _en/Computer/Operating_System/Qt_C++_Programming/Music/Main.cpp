/* Main.cpp
Author: BSS9395
Update: 2022-07-11T02:22:00+08@China-Shanghai+08
Design: Music
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Music music = Music();
    music.show();

    return application.exec();
}
