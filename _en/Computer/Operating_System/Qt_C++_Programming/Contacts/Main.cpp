/* Main.cpp
Author: BSS9395
Update: 2022-03-01T02:06:00+08@China-Guangdong-Shenzhen+08
Design: Contacts
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Contacts contacts;
    contacts.show();

    return application.exec();
}
