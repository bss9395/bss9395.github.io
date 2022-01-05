/* Notebook
Author: BSS9395
Update: 2022-01-05T23:10:00+08@China-Guangdong-Shenzhen+08
Design: Notebook Text Editor
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MW_Notebook mw_notebook;
    mw_notebook.show();
    return application.exec();
}
