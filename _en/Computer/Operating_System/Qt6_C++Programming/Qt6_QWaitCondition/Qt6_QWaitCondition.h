/* Qt6_QWaitCondition.h
Author: BSS9395
Update: 2023-08-31T09:49:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QWAITCONDITION_H
#define QT6_QWAITCONDITION_H

#include <QMainWindow>
#include "ui_Qt6_QWaitCondition.h"
#include <QReadLocker>
#include <QWaitCondition>
#include <QThread>
#include <QRandomGenerator64>

struct Locker {
    inline static QReadWriteLock _lock      = QReadWriteLock();
    inline static QWaitCondition _condition = QWaitCondition();
    inline static unsigned int   _seed      = 0;
    inline static unsigned int   _dice      = 0;
};

class Thread_Yield : public QThread {
    Q_OBJECT
public:
    void run() override {
        while(true) {
            Locker::_lock.lockForWrite();
            Locker::_seed += 1;
            Locker::_dice = QRandomGenerator::global()->bounded(1, 7);
            Locker::_lock.unlock();
            Locker::_condition.wakeAll();
            msleep(500);
        }
    }
};

class Thread_Dice : public QThread {
    Q_OBJECT
public:
    void run() override {
        while(true) {
            Locker::_lock.lockForRead();
            Locker::_condition.wait(&Locker::_lock);
            emit _New_Dice(Locker::_seed, Locker::_dice);
            Locker::_lock.unlock();
        }
    }

signals:
    void _New_Dice(unsigned int seed, unsigned int dice);
};

class Thread_Image : public QThread {
    Q_OBJECT
public:
    void run() override {
        while(true) {
            Locker::_lock.lockForRead();
            Locker::_condition.wait(&Locker::_lock);
            QString filename = QString::asprintf(":/images/dice%d.jpg", Locker::_dice);
            emit _New_Image(filename);
            Locker::_lock.unlock();
        }
    }

signals:
    void _New_Image(QString filename);
};

class Qt6_QWaitCondition : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QWaitCondition *_ui = nullptr;
    Thread_Yield _thread_yield = Thread_Yield();
    Thread_Dice  _thread_dice  = Thread_Dice();
    Thread_Image _thread_image = Thread_Image();

public:
    Qt6_QWaitCondition(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QWaitCondition) {
        _ui->setupUi(this);

        _ui->A_Start->setEnabled(true);
        _ui->A_Stop->setEnabled(false);
        QObject::connect(&_thread_yield, &Thread_Yield::started, this, [this]() -> void {
            _ui->PTE_Message->appendPlainText("started");
            _ui->A_Start->setEnabled(false);
            _ui->A_Stop->setEnabled(true);
        });
        QObject::connect(&_thread_yield, &Thread_Yield::finished, this, [this]() -> void {
            _ui->PTE_Message->appendPlainText("finished");
            _ui->A_Start->setEnabled(true);
            _ui->A_Stop->setEnabled(false);
        });

        QObject::connect(_ui->A_Start, &QAction::triggered, this, [this]() -> void {
            _thread_dice.start();
            _thread_image.start();
            _thread_yield.start();
        });

        QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {
            _thread_dice.terminate();
            _thread_image.terminate();
            _thread_yield.terminate();
        });

        QObject::connect(&_thread_dice, &Thread_Dice::_New_Dice, this, [this](unsigned int seed, unsigned int dice) -> void {
            QString text = QString::asprintf("第%d次掷骰子，点数为%d。", seed, dice);
            _ui->PTE_Message->appendPlainText(text);
        });

        QObject::connect(&_thread_image, &Thread_Image::_New_Image, this, [this](QString filename) -> void {
            QPixmap pixmap = QPixmap(filename);
            _ui->L_Dice->setPixmap(pixmap);
        });
    }

    ~Qt6_QWaitCondition() {
        delete _ui;
    }


};

#endif // QT6_QWAITCONDITION_H
