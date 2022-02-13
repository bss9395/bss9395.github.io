/* Main.cpp
Author: BSS9395
Update: 2022-02-12T02:12:00+08@China-Guangdong-Shenzhen+08
Design: Canvas
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);

    QApplication application(argc, argv);

    iptr ret = 0;
    Login *login = new Login(nullptr, &ret);
    login->exec();
    System::Logging("ret = %d", ret);
    if(ret != QDialog::Accepted) {  // note: login destructs itself before exec() return.
        return 0;
    }

    System::Logging("if(login->exec() != QDialog::Accepted) { ");
    Canvas canvas;
    canvas.show();
    return application.exec();
}
