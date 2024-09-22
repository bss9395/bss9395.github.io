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
    QObject* producer = Concurrent::_Asyn([queue]() -> void {
        qDebug().noquote() << "QTimer::singleShot(0, Qt::PreciseTimer, producer, [queue]() -> void {";
        int i = 0;
        while (true) {
            queue->_Push(QString("%1").arg(i));
            i += 1;
            QThread::msleep(1000);
        }
    });
    QObject* consumer = Concurrent::_Asyn([queue]() -> void {
        qDebug().noquote() << "QTimer::singleShot(0, Qt::PreciseTimer, consumer, [queue]() -> void {";
        while (true) {
            if (queue->_Empty() == false) {        // 非阻塞程序
                QString element = queue->_Pull();  // 非阻塞程序
                qDebug().noquote() << QString("element = %1").arg(element);
            }
            QThread::msleep(500);
        }
    });

	QThread::sleep(5);
	delete producer, producer = nullptr;  // use delete producer, instead of producer->deleteLater()
	delete consumer, consumer = nullptr;  // use delete consumer, instead of consumer->deleteLater()
	delete queue, queue = nullptr;
}
