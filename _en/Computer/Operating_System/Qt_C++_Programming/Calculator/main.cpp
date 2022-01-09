/* Main.cpp
Author: BSS9395
Update: 2022-01-07T22:33:00+08@China-Guangdong-Shenzhen+08
Design: Calculator
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    Logging(__FUNCTION__);

    QApplication application(argc, argv);
    Calculator calculator;
    calculator.show();

    return application.exec();
}
