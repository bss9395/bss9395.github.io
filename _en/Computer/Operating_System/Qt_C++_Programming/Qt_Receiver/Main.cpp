/* Main.cpp
Author: bss9395
Update: 2024-09-28T00:34:00+08@China-Beijing+08
*/

#include "Receiver.h"
#include <QApplication>
#include <QDebug>

static void _Test_Receiver_delete() {
    Sender *sender = new Sender();
    Receiver *receiver = new Receiver();

    QObject::connect(sender, &Sender::_Signal, receiver, [receiver](const QString& text) -> void {
        qDebug().noquote() << "text = " << text;
        delete receiver;
    });

    emit sender->_Signal("abc");
    // 析构receiver，自动断开信号连接
    emit sender->_Signal("def");
    qDebug().noquote() << "leave";
}

static void _Test_Receiver_Local() {
    Sender *sender = new Sender();
    Receiver *local = nullptr;
    {
        Receiver receiver;
        local = &receiver;
        QObject::connect(sender, &Sender::_Signal, local, [local](const QString& text) -> void {
            qDebug().noquote() << "text = " << text;
        });

        emit sender->_Signal("abc");
        // 析构receiver，自动断开信号连接
    }
    emit sender->_Signal("def");
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // _Test_Receiver_delete();
    _Test_Receiver_Local();

    return a.exec();
}
