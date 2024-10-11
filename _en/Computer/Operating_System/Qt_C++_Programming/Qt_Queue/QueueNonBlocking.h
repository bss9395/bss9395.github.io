#pragma once

#include <QDebug>
#include <QMutex>
#include <QQueue>
#include <QString>
#include "Concurrent.h"

template<typename Type_>
class QueueNonBlocking {
public:
	QQueue<Type_> _queue;
	QMutex        _mutex;

public:
	void _Push(const Type_& element) {
		qDebug().noquote() << __FUNCTION__;
		QMutexLocker locker(&_mutex);
		_queue.push_back(element);
	}

	Type_ _Pull() {
		qDebug().noquote() << __FUNCTION__;
		QMutexLocker locker(&_mutex);
		if (_queue.isEmpty() == false) {
			return _queue.takeFirst();
		}
		return Type_();
	}

	bool _Empty() {
		qDebug().noquote() << __FUNCTION__;
		QMutexLocker locker(&_mutex);
		return _queue.isEmpty();
	}
};

static void _Test_QueueNonBlocking() {
	QueueNonBlocking<QString> *queue = new QueueNonBlocking<QString>();
	QThread* producer = Concurrent::_Asyn([queue]() -> void {
        qDebug().noquote() << "QThread* producer = Concurrent::_Asyn([queue]() -> void {";
		int i = 0;
		while (true) {
			queue->_Push(QString("%1").arg(i));
			i += 1;
			QThread::msleep(1000);
		}
	});
	QThread* consumer = Concurrent::_Asyn([queue]() -> void {
        qDebug().noquote() << "QThread* consumer = Concurrent::_Asyn([queue]() -> void {";
		while (true) {
			if (queue->_Empty() == false) {        // 非阻塞程序
				QString element = queue->_Pull();  // 非阻塞程序
				qDebug().noquote() << QString("element = %1").arg(element);
			}
			QThread::msleep(500);
		}
	});

	QThread::sleep(5);
    producer->terminate();          // use producer->terminate(), instead of producer->quit()
    producer->deleteLater(), producer = nullptr;
    consumer->terminate();          // use consumer->terminate(), instead of consumer->quit()
    consumer->deleteLater(), consumer = nullptr;
	delete queue, queue = nullptr;
}
