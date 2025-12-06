/* Qt_QThread
Author: bss9395
Update: 2024-08-19T11:29:00+08@China-Beijing+08
*/

#include <QCoreApplication>
#include <QObject>
#include <QMetaObject>
#include <QTimer>
#include "Worker.h"

void _Test_SingleShot() {
    Thread* thread = new Thread();
    thread->start();
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    worker->_Slot_DoWork(false, "Hello, World!");                                                           // 在本线程调用_Slot_DoWork()

    QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
    QObject::connect(worker, &Worker::_Signal_DoWork, worker, &Worker::_Slot_DoWork);
    emit worker->_Signal_DoWork(false, "_Signal_DoWork");                                                   // 若worker所在的thread线程在运行中，则在thread线程中调用_Slot_DoWork()

    QMetaObject::invokeMethod(worker, "_Slot_DoWork", Q_ARG(bool, false), Q_ARG(QString, "invokeMethod"));  // 若worker所在的thread线程在运行中，则在thread线程中调用_Slot_DoWork()

    QTimer::singleShot(0, Qt::PreciseTimer, worker, [thread, worker]() {                                    // 若worker所在的thread线程在运行中，则在thread线程中调用_Slot_DoWork()
        // QTimer存在延迟
        worker->_Slot_DoWork(false, "singleShot");
        thread->exit();
    });

    thread->wait();  // 阻塞程序
    delete thread;   // 对于QThread的派生类，使用delete thread;
}

void _Test_Exception() {
    class Finally {
    public:
        explicit Finally(const std::function<void()>& cleanup)
            : _cleanup(cleanup) {}

        ~Finally() {
            _Execute();
        }

    public:
        void _Execute() {
            if (_flag == false) {
                _flag = true;
                _cleanup();
            }
        }

    private:
        bool _flag = false;
        std::function<void()> _cleanup;
    };


    Thread* thread = new Thread();
    thread->start();
    Worker* worker = new Worker();
    worker->moveToThread(thread);

    Finally finally([thread, worker]() {
        delete worker;        // 当thread->terminate()时，worker->deleteLater()不起作用
        thread->terminate();  // 使用thread->wait()会阻塞当前线程
        delete thread;        // 对于QThread的派生类，使用delete thread;
    });
    try {
        QMetaObject::invokeMethod(worker, "_Slot_DoWork", Q_ARG(bool, true), Q_ARG(QString, "invokeMethod"));  // 若worker所在的thread线程在运行中，则在thread线程中调用_Slot_DoWork()
    }
    catch(const QString& except) {
        qDebug().nospace() << "exception caught: " << except;
    }
    catch(...) {
        // 若当前线程为抛出异常的线程，则可以捕获到异常
        // 若当前线程非抛出异常的线程，则不可捕获到异常，也没有任何错误消息，程序也没有出现崩溃
        qDebug().nospace() << "unkown exception.";
        throw;
    }
    finally._Execute();
}

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);
    qDebug().noquote() << QString("enter %1, %2").arg(__FUNCTION__).arg((quint64)QThread::currentThreadId());

    // _Test_SingleShot();
    _Test_Exception();

    qDebug().noquote() << QString("leave %1, %2").arg(__FUNCTION__).arg((quint64)QThread::currentThreadId());
    return application.exec();
}
