/* Qt_QThread
Author: bss9395
Update: 2024-08-19T11:29:00+08@China-Beijing+08
*/

#include <QCoreApplication>
#include <QObject>
#include <QMetaObject>
#include "Worker.h"

QThread *_InvokeMethod() {
	QThread *thread = new QThread();
	thread->start();

	Worker *worker = new Worker();
	worker->moveToThread(thread);
	QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
    QObject::connect(worker, &Worker::_Signal_DoWork, worker, &Worker::_Slot_DoWork);        // 连接信号与槽
    emit worker->_Signal_DoWork("Hello, world!");

	Routine *routine = new Routine();
	routine->moveToThread(thread);
	QObject::connect(thread, &QThread::finished, routine, &Routine::deleteLater);
    QMetaObject::invokeMethod(routine, "_Slot_DoRoutine", Q_ARG(QString, "Hello, world!"));  // 连接信号与槽

    worker->_Slot_DoWork("Hello, world!");  // 在当前线程中调用函数
	return thread;
}

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);
    qDebug().noquote() << QString("enter %1, %2").arg(__FUNCTION__).arg((quint64)QThread::currentThreadId());


	QThread *thread = _InvokeMethod();
	thread->exit();
	thread->wait();  // 阻塞程序
	delete thread;

    qDebug().noquote() << QString("leave %1, %2").arg(__FUNCTION__).arg((quint64)QThread::currentThreadId());
	return a.exec();
}
