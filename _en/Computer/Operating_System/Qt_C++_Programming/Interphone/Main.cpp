/* Main.cpp
Author: BSS9395
Update: 2022-03-21T20:58:00+08@China-Shanghai+08
Design: Interphone
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication a(argc, argv);

    Interphone talkie = Interphone(Interphone::_Talkie);
    talkie.show();
    Interphone walkie = Interphone(Interphone::_Walkie);
    walkie.show();

    return a.exec();
}
