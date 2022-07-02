/* Main.cpp
Author: BSS9395
Update: 2022-07-02T21:56:00+08@China-Shanghai+08
Design: Chart
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    Chart chart;
    chart.show();

    return application.exec();
}
