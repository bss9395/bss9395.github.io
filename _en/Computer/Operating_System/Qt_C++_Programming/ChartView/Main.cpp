/* Main.cpp
Author: BSS9395
Update: 2022-07-05T14:13:00+08@China-Shanghai+08
Design: ChartView
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    System::Logging(__FUNCTION__);
    QApplication application(argc, argv);

    ChartView chartview;
    chartview.show();

    return application.exec();
}
