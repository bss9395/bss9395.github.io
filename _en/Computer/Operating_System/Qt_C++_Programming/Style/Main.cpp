/* Main.cpp
Author: BSS9395
Update: 2022-07-27T19:38:00+08@China-Shanghai+08
Design: Style
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Style style;
    style.show();

    return application.exec();
}
