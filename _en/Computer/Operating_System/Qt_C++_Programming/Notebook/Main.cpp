/* Main.cpp
Author: BSS9395
Update: 2022-01-06T20:21:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.15.2
Notice: Bug on Visual Studio 2017
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Notebook notebook;
    notebook.show();

    return application.exec();
}
