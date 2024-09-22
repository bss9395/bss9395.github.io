#pragma once

#include <QObject>
#include <QThread>
#include <QTimer>

class Concurrent: public QObject {
    Q_OBJECT

public:
    template <typename Functor_>
    static QObject *_Asyn(Functor_ functor) {
        QThread *thread = new QThread();
        QObject *concurrent = new QObject();
        QObject::connect(concurrent, &QObject::destroyed, thread, [thread]() mutable -> void {
            qDebug().noquote() << "QObject::connect(concurrent, &QObject::destroyed, thread, [thread]() mutable -> void {";
            thread->terminate();   // use thread->terminate(), instead of thread->quit()
            thread->deleteLater(), thread = nullptr;
        });

        thread->start();
        concurrent->moveToThread(thread);
        QTimer::singleShot(0, Qt::PreciseTimer, concurrent, functor);
        return concurrent;
    }
};
