/* Main.cpp
Author: BSS9395
Update: 2022-07-20T02:00:00+08@China-Shanghai+08
Design: Player
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication a(argc, argv);

//    QVideoWidget_Frame video;
//    video.show();

    Player player;
    player.show();

    return a.exec();
}
