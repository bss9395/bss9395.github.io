/* Qt_QRandomGenerator.cpp
Author: BSS9395
Update: 2023-08-13T20:42:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QRandomGenerator generator(QDateTime::currentSecsSinceEpoch());
    for(int i = 0; i < 10; i += 1) {
        fwprintf(stdout, L"%u, ", generator());
    }
    fwprintf(stdout, L"\n");

    for(int i = 0; i < 10; i += 1) {
        fwprintf(stdout, L"%u, ", generator.generate());
    }
    fwprintf(stdout, L"\n");

    for (int i = 0; i < 10; i+= 1) {
        fwprintf(stdout, L"%lf, ", generator.generateDouble());
    }
    fwprintf(stdout, L"\n");

    fflush(stdout);
    return a.exec();
}
