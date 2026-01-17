/// Record: Qt_emit.h
/// Author: bss9395
/// Update: 2025-11-30T00:41:00+08@China-BeiJing+08
/// Keepin: bss9395@yeah.net

#pragma once

#include <QCoreApplication>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

class Sender: public QObject {
    Q_OBJECT

signals:
    void _Signal(const QString &bulk);

public:
    void _Send(){
        auto _Emit = [this](QString bulk) -> void {
            QString print = QString("[_Emit] threadID = %1, &bulk = %2, bulk.size() = %3, bulk[0:10) = %4")
                    .arg((quint64)QThread::currentThreadId())
                    .arg((quint64)&bulk)
                    .arg((quint64)bulk.size())
                    .arg(bulk.mid(0, 10));
            qDebug().nospace().noquote() << print;

            // QThread::msleep(10);
            emit this->_Signal(bulk);
        };

        QString bulk = QString(100, 'A');
        QString print = QString("[_Send] threadID = %1, &bulk = %2, bulk.size() = %3, bulk[0:10) = %4")
                .arg((quint64)QThread::currentThreadId())
                .arg((quint64)&bulk)
                .arg((quint64)bulk.size())
                .arg(bulk.mid(0, 10));
        qDebug().nospace().noquote() << print;

        QtConcurrent::run([_Emit, bulk]() -> void {  // 注意：_Emit为临时对象
            QString copy = bulk;
            _Emit(copy);
        });
    }
};

class Receiver: public QObject {
    Q_OBJECT

public:
    QString _text = "Hello";
    Sender *_sender = new Sender();

public:
    void _Receive() {
        QString extra = "Hello";
        QString *pextra = new QString("Hello");
        QObject::connect(this, &Receiver::destroyed, [pextra]() -> void {
            QString print = QString("[destroyed] threadID = %1")
                    .arg((quint64)QThread::currentThreadId());
            qDebug().nospace().noquote() << print;
            delete pextra;
        });

        QObject::connect(_sender, &Sender::_Signal, this, [this, extra, pextra](const QString& bulk) {
            QString print = QString("[_Signal0] threadID = %1, &bulk = %2, bulk.size() = %3, bulk[0:10) = %4")
                    .arg((quint64)QThread::currentThreadId())
                    .arg((quint64)&bulk)
                    .arg((quint64)bulk.size())
                    .arg(bulk.mid(0, 10));
            qDebug().nospace().noquote() << print;

            _text = "World";
            ((QString)extra) = "World";
            *pextra = "World";
            ((QString &)bulk) = "World";
        }, Qt::QueuedConnection);

        QObject::connect(_sender, &Sender::_Signal, this, [this, extra, pextra](const QString& bulk) {
            QThread::msleep(5000);
            QString print = QString("[_Signal1] threadID = %1, &bulk = %2, bulk.size() = %3, bulk[0:10) = %4")
                    .arg((quint64)QThread::currentThreadId())
                    .arg((quint64)&bulk)
                    .arg((quint64)bulk.size())
                    .arg(bulk.mid(0, 10));
            qDebug().nospace().noquote() << print;

            _text = "Yet";
            ((QString)extra) = "Yet";
            *pextra = "Yet";
            ((QString &)bulk) = "Yet";
            qDebug().nospace().noquote() << "bulk = " << bulk;
        }, Qt::QueuedConnection);


        QString print = QString("[_Receive] threadID = %1")
                .arg((quint64)QThread::currentThreadId());
        qDebug().nospace().noquote() << print;
        _sender->_Send();
        QObject::disconnect()
    }

    virtual ~Receiver() {
        QObject::disconnect(_sender, &Sender::_Signal, this, nullptr);
        _sender->deleteLater();
    }
};
