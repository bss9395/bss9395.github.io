/* Main.cpp
Author: BSS9395
Update: 2022-07-14T01:54:00+08@China-Shanghai+08
Design: Player
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication a(argc, argv);

    Player player;
    player.show();

    return a.exec();
}
