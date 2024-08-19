/* Qt_QEventLoop
Author: bss9395
Update: 2024-08-19T11:09:00+08@China-Beijing+08
*/

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return application.exec();
}
