/* Notebook
Author: BSS9395
Update: 2022-01-05T01:10:00+08@China-Guangdong-Shenzhen+08
Design: Notebook Text Editor
Encode: UTF-8
*/

#include "Common.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MW_Notebook w;
    w.show();
    return a.exec();
}
