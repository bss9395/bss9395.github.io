/* Main.cpp
Author: BSS9395
Update: 2022-06-25T22:47:00+08@China-Shanghai+08
Design: Plotter
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

//    Window window;
//    window.show();

    Plotter plotter;
    plotter.show();

    return application.exec();
}
