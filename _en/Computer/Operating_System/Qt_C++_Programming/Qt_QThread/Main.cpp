/* Qt_QThread
Author: bss9395
Update: 2024-08-19T11:29:00+08@China-Beijing+08
*/

#include <QCoreApplication>
#include <QObject>
#include <QMetaObject>
#include <QTimer>
#include "Worker.h"

void _SingleShot() {
    QThread *thread = new QThread();
    thread->start();

    Worker *worker = new Worker();
    worker->moveToThread(thread);

    worker->_Slot_DoWork("Hello, World!");                                              // 在本线程调用_Slot_DoWork()

    QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
    QObject::connect(worker, &Worker::_Signal_DoWork, worker, &Worker::_Slot_DoWork);
    emit worker->_Signal_DoWork("_Signal_DoWork");                                      // 若thread线程在运行中，则切换到worker所在的thread线程，然后调用_Slot_DoWork()

    QMetaObject::invokeMethod(worker, "_Slot_DoWork", Q_ARG(QString, "invokeMethod"));  // 若thread线程在运行中，则切换到worker所在的thread线程，然后调用_Slot_DoWork()

    QTimer::singleShot(0, Qt::PreciseTimer, worker, [thread, worker]() {
        // QTimer存在延迟
        worker->_Slot_DoWork("singleShot");                                             // 若thread线程在运行中，则切换到worker所在的thread线程，然后调用_Slot_DoWork()
        thread->exit();
    });

    thread->wait();  // 阻塞程序
    delete thread;
}

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
    qDebug().noquote() << QString("enter %1, %2").arg(__FUNCTION__).arg((quint64)QThread::currentThreadId());

    _SingleShot();

    qDebug().noquote() << QString("leave %1, %2").arg(__FUNCTION__).arg((quint64)QThread::currentThreadId());
	return a.exec();
}
