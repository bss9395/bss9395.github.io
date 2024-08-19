/* Qt_QLocalServer
Author: bss9395
Update: 2024-08-19T19:45:00+08@China-Beijing+08
*/

#include <QApplication>
#include <QTimer>
#include "MainWindow.h"
#include "SingleApplication.h"

int main(int argc, char *argv[]) {
    SingleApplication singleApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    QObject::connect(&singleApplication, &SingleApplication::_Signal_Connected, [&mainWindow]() -> void {
        mainWindow.setWindowState(mainWindow.windowState() & ~Qt::WindowMinimized);  // 取消最小化
        mainWindow.raise();           // Raises this widget to the top of the parent widget's stack.
        mainWindow.activateWindow();  // Sets the top-level widget containing this widget to be the active window.
        // On Windows, if you are calling this when the application is not currently the active one then it will not make it the active window. It will change the color of the taskbar entry to indicate that the window has changed in some way. This is because Microsoft does not allow an application to interrupt what the user is currently doing in another application.
    });

    QObject::connect(&singleApplication, &SingleApplication::_Signal_Echo, [&mainWindow](const QString& echo) -> void {
        mainWindow._SetText(echo);
    });
    return singleApplication.exec();
}
