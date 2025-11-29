/// Record: Main.cpp
/// Author: bss9395
/// Update: 2025-11-30T00:41:00+08@China-BeiJing+08
/// Keepin: bss9395@yeah.net

#include <QApplication>
#include <QThread>
#include <QDebug>
#include "Qt_emit.h"

void _Test_Affinity() {
    QObject* parent = new QObject();
    QObject* child  = new QObject();
    QThread* thread = new QThread();
    thread->start();
    child->moveToThread(thread);

    qDebug().nospace().noquote() << "[before setParent()] parent = " << parent << ", child->parent() = " << child->parent();
    child->setParent(parent);  // 错误：尝试跨线程设置父子关系
    qDebug().nospace().noquote() << "[after  setParent()] parent = " << parent << ", child->parent() = " << child->parent();

    // child->deleteLater();
    // workerThread->quit();   // 实践：使用QThread::terminate()
    thread->terminate();
    thread->deleteLater();
}

void _Test_emit() {
    Receiver *consumer = new Receiver();
    consumer->_Receive();

    // 定时器1毫秒
    QTimer::singleShot(1, [consumer]() -> void {
       consumer->deleteLater();
    });
}

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    // _Test_Affinity();
    _Test_emit();

    return application.exec();
}
