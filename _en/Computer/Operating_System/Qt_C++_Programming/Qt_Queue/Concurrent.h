#pragma once

#include <QObject>
#include <QThread>
#include <QTimer>

class Concurrent : public QObject {
	Q_OBJECT

public:
    template <typename Functor>
    static QThread *_Asyn(Functor functor) {
		QThread *thread = new QThread();
		QObject *concurrent = new QObject();
        QObject::connect(thread, &QThread::finished, thread, [concurrent]() mutable -> void {  // connect to thread, instead of concurrent
            qDebug().noquote() << "QObject::connect(thread, &QThread::finished, thread, [concurrent]() mutable -> void {";
            concurrent->deleteLater(), concurrent = nullptr;                                   // use concurrent->deleteLater(), instead of delete concurrent
		});

		thread->start();
		concurrent->moveToThread(thread);
        QMetaObject::invokeMethod(concurrent, functor);
		return thread;
	}
};
