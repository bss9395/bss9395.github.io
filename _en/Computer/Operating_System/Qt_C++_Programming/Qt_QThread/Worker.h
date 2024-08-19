#ifndef WORKER_H
#define WORKER_H

#include <QDebug>
#include <QException>
#include <QObject>
#include <QThread>

class Worker: public QObject {
    Q_OBJECT
public:
    explicit Worker() {
        qDebug().noquote() << __FUNCTION__;
    }

    virtual ~Worker() {
        qDebug().noquote() << __FUNCTION__;
    }

public slots:
    void _Slot_DoWork(const QString& para) {     // 若采用SLOT()则必须定义为槽函数
        qDebug().noquote() << QString("enter %1(%2), %3").arg(__FUNCTION__).arg(para).arg((quint64)QThread::currentThreadId());
        for(qint64 i = 0; i < (qint64)1024 * 1024 * 1024; i += 1) {
            ;
        }
        qDebug().noquote() << QString("leave %1(%2), %3").arg(__FUNCTION__).arg(para).arg((quint64)QThread::currentThreadId());
    }

signals:
    void _Signal_DoWork(QString);
};

class Routine: public QObject {
    Q_OBJECT
public:
    explicit Routine() {
        qDebug().noquote() << __FUNCTION__;
    }

    virtual ~Routine() {
        qDebug().noquote() << __FUNCTION__;
    }

public slots:
    void _Slot_DoRoutine(const QString& para) {  // 若采用SLOT()则必须定义为槽函数
        qDebug().noquote() << QString("enter %1(%2), %3").arg(__FUNCTION__).arg(para).arg((quint64)QThread::currentThreadId());
        for(qint64 i = 0; i < (qint64)1024 * 1024 * 1024; i += 1) {
            ;
        }
        qDebug().noquote() << QString("leave %1(%2), %3").arg(__FUNCTION__).arg(para).arg((quint64)QThread::currentThreadId());

    }
};

#endif // WORKER_H
