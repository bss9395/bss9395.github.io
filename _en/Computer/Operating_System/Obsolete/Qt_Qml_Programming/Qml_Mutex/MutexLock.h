#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H

#include <QDebug>
#include <QObject>
#include <QMutex>
#include <QThread>

class MultiThread: public QThread {
    Q_OBJECT

public:
    explicit MultiThread(QObject *parent = nullptr)
        : QThread(parent) {
        // qDebug().noquote() << __FUNCTION__;
        this->start();
    }

public:
    void run() override {
        while(true) {
            QThread::msleep(5 * 1000);
            qDebug().noquote() << "MultiThread" << QThread::currentThread();
            emit signal_thread();
        }
    }

public:
    Q_INVOKABLE void _Sleep(const int &seconds) {
        QThread::currentThread()->msleep(seconds * 1000);
        qDebug().noquote() << __FUNCTION__ << QThread::currentThread() << QString("msleep(%1 * 1000)").arg(seconds);
    }

signals:
    void signal_thread();
};


class MutexLock: public QObject {
    Q_OBJECT

    class MultiSignal: public QThread {
    public:
        MutexLock *_mutexLock = nullptr;

    public:
        explicit MultiSignal(MutexLock *mutexLock = nullptr)
            : QThread(mutexLock) {
            // qDebug().noquote() << __FUNCTION__;
            _mutexLock = mutexLock;
        }

    public:
        void run() override {
            while(true) {
                QThread::msleep(5 * 1000);
                qDebug().noquote() << "MultiSignal: " << QThread::currentThread();
                emit _mutexLock->signal_thread();  // 信号发射发生在接收者线程
            }
        }
    };

public:
    QMutex  _mutex;
    MultiSignal *_multisignal = new MultiSignal(this);

public:
    explicit MutexLock() {
        // qDebug().noquote() << __FUNCTION__;
    }

public:
    Q_INVOKABLE void _Sleep(const int &seconds) {
        QThread::currentThread()->msleep(seconds * 1000);
        qDebug().noquote() << __FUNCTION__ << QThread::currentThread() << QString("msleep(%1 * 1000)").arg(seconds);
    }

    Q_INVOKABLE void _LockAndSleep(const int &seconds) {
        _mutex.lock();
        QThread::currentThread()->msleep(seconds * 1000);
        qDebug().noquote() << __FUNCTION__ << QThread::currentThread() << QString("msleep(%1 * 1000)").arg(seconds);
    }

    Q_INVOKABLE void _UnLock() {
        qDebug().noquote() << __FUNCTION__ << QThread::currentThread();
        _mutex.unlock();
    }

signals:
    void signal_thread();
};

#endif // MUTEXLOCK_H
