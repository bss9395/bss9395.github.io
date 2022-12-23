/* Main.cpp
Author: BSS9395
Update: 2022-12-23T17:51:00+08@China-Shanghai+08
Design: StyleSheet
Encode: UTF-8
System: Qt 5.15.2
*/


#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);
    StyleSheet stylesheet = StyleSheet();
    stylesheet.show();
    return application.exec();
}
