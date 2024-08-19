/* Qt_QQ
Author: bss9395
Update: 2023-08-16T19:02:00+08@China-Guangdong-Zhanjiang+08
*/

#include "MainBoard.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    MainBoard mainBoard;
    mainBoard.show();

    return application.exec();
}
