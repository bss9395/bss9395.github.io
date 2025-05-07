/*
Author: BSS9395
Update: 2025-04-30T11:55:18+08@China-Guangdong-Zhanjiang+08
*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
