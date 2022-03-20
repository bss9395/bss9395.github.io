/* Main.cpp
Author: BSS9395
Update: 2022-03-20T21:35:00+08@China-Shanghai+08
Design: Whisper
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);

    Whisper_Server whisper_server = Whisper_Server();
    whisper_server.show();

    Whisper_Client whisper_client = Whisper_Client();
    whisper_client.show();

    return application.exec();
}
