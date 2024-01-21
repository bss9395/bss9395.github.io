/* Qt6_QSemaphore.h
Author: BSS9395
Update: 2023-08-30T14:21:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QSEMAPHORE_H
#define QT6_QSEMAPHORE_H

#include <QMainWindow>
#include "ui_Qt6_QSemaphore.h"
#include <QSemaphore>
#include <QThread>
#include <QVector>

struct Locker {
    inline static int _buffer0[10] = {0};
    inline static int _buffer1[10] = {0};
    inline static int _counter_index  = 0;
    inline static int _index_producer = 0;
    inline static int _index_consumer = 0;
    inline static QSemaphore _semaphore_producer = QSemaphore(2);
    inline static QSemaphore _semaphore_consumer  = QSemaphore(0);
};

class Thread_Producer : public QThread {
    Q_OBJECT
public:
    void run() override {
        int _counter_data  = 0;
        while(true) {
            Locker::_semaphore_producer.acquire(1);
            if(Locker::_index_producer == 0) {
                for(int i = 0; i < 10; i += 1) {
                    Locker::_buffer0[i] = _counter_data;
                    _counter_data += 1;
                    msleep(10);
                }
            } else if(Locker::_index_producer == 1) {
                for(int i = 0; i < 10; i += 1) {
                    Locker::_buffer1[i] = _counter_data;
                    _counter_data += 1;
                    msleep(10);
                }
            }
            Locker::_counter_index += 1;
            Locker::_index_consumer = Locker::_index_producer;
            Locker::_index_producer = (Locker::_index_producer + 1) % 2;
            Locker::_semaphore_consumer.release(1);
        }
    }
};

class Thread_Consumer : public QThread {
    Q_OBJECT
public:
    void run() override {
        QVector<int> data;
        while(true) {
            Locker::_semaphore_consumer.acquire(1);
            data.clear();
            if(Locker::_index_consumer == 0) {
                for(int i=0; i < 10; i++) {         //模拟数据处理
                    data += Locker::_buffer0[i];
                }
            } else if(Locker::_index_consumer == 1) {
                for(int i = 0; i < 10; i += 1) {
                    data += Locker::_buffer1[i];
                }
            }
            Locker::_semaphore_producer.release();    //emptyBufs释放一个资源，可用空缓冲区个数加
            emit _New_Value(Locker::_counter_index, data);  //发射信号
        }
    }

signals:
    void _New_Value(unsigned int index, QVector<int> data);
};

class Qt6_QSemaphore : public QMainWindow {
    Q_OBJECT
private:
    Ui::Qt6_QSemaphore *_ui = nullptr;
    Thread_Producer _thread_producer = Thread_Producer();
    Thread_Consumer _thread_consumer = Thread_Consumer();

public:
    Qt6_QSemaphore(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QSemaphore) {
        _ui->setupUi(this);

        _ui->A_Start->setEnabled(true);
        _ui->A_Stop->setEnabled(false);
        QObject::connect(&_thread_producer, &Thread_Producer::started, this, [this]() -> void {
            _ui->PTW_Message->appendPlainText("started");
            _ui->A_Start->setEnabled(false);
            _ui->A_Stop->setEnabled(true);
        });
        QObject::connect(&_thread_producer, &Thread_Producer::finished, this, [this]() -> void {
            _ui->PTW_Message->appendPlainText("finished");
            _ui->A_Start->setEnabled(true);
            _ui->A_Stop->setEnabled(false);
        });

        QObject::connect(&_thread_consumer, &Thread_Consumer::_New_Value, this, [this](unsigned int index, QVector<int> data) -> void {
            QString text = QString::asprintf("第%d个缓冲区: ", index);
            for(int i = 0; i < data.size(); i += 1) {
                text += QString::asprintf(", %d", data[i]);
            }
            _ui->PTW_Message->appendPlainText(text);
        });

        QObject::connect(_ui->A_Start, &QAction::triggered, this, [this]() -> void {
            _thread_consumer.start();
            _thread_producer.start();
        });

        QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {
            _thread_consumer.terminate();
            _thread_producer.terminate();
        });
    }

    ~Qt6_QSemaphore()
    {
        delete _ui;
    }


};
#endif // QT6_QSEMAPHORE_H
