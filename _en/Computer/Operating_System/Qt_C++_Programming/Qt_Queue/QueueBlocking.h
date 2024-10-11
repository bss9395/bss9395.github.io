#pragma once

#include <QDebug>
#include <QMutex>
#include <QQueue>
#include <QString>
#include <QWaitCondition>
#include "Concurrent.h"

template<typename Type_>
class QueueBlocking {
public:
	QQueue<Type_>  _queue;
	QMutex         _mutex;
	QWaitCondition _condition;

public:
	void _Push(const Type_& element) {
		qDebug().noquote() << __FUNCTION__;
		QMutexLocker locker(&_mutex);
		_queue.push_back(element);
		_condition.wakeAll();
	}

	Type_ _Pull() {
		qDebug().noquote() << __FUNCTION__;
		QMutexLocker locker(&_mutex);
		while (_queue.isEmpty() == true) {
			qDebug().noquote() << "while(_queue.isEmpty() == true) {";
			_condition.wait(&_mutex);  // 阻塞程序
		}
		return _queue.takeFirst();
	}

	bool _Empty() {
		qDebug().noquote() << __FUNCTION__;
		QMutexLocker locker(&_mutex);
		return _queue.isEmpty();
	}
};

static void _Test_QueueBlocking() {
	QueueBlocking<QString> *queue = new QueueBlocking<QString>();
	QThread *producer = Concurrent::_Asyn([queue]() mutable -> void {
        qDebug().noquote() << "QThread *producer = Concurrent::_Asyn([queue]() mutable -> void {";
		int i = 0;
		while (true) {
			queue->_Push(QString("%1").arg(i));
			i += 1;
			QThread::msleep(1000);
		}
	});
	QThread *consumer = Concurrent::_Asyn([queue]() mutable -> void {
        qDebug().noquote() << "QThread *consumer = Concurrent::_Asyn([queue]() mutable -> void {";
		while (true) {
			QString element = queue->_Pull();  // 阻塞程序
			qDebug().noquote() << QString("element = %1").arg(element);
		}
	});

	QThread::sleep(5);
    producer->terminate();          // use producer->terminate(), instead of producer->quit()
    producer->deleteLater(), producer = nullptr;
    consumer->terminate();          // use consumer->terminate(), instead of consumer->quit()
    consumer->deleteLater(), consumer = nullptr;
    delete queue, queue = nullptr;  // QWaitCondition: Destroyed while threads are still waiting
}
