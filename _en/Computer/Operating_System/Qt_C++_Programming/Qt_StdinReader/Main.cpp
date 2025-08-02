#include <QApplication>
#include <QDebug>
#include <iostream>
#include <string>
#include "StdinReader.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    StdinReader stdinReader;
    QObject::connect(&stdinReader, &StdinReader::_Signal_ReadLine, [](const QString& data) -> void {
        qDebug().noquote() << data;
    });

    return a.exec();
}
