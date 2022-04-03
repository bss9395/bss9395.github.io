/* Main.cpp
Author: BSS9395
Update: 2022-04-03T17:45:00+08@China-Shanghai+08
Design: Chat
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);

    Chat chat;
    chat.show();

    return application.exec();
}
