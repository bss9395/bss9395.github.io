/* Main.cpp
Author: BSS9395
Update: 2022-02-18T23:40:00+08@China-Guangdong-Zhanjiang+08
Design: Contacts
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Contacts contacts;
    contacts.show();

    return application.exec();
}
