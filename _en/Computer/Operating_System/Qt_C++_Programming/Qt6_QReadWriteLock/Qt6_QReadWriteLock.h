/* Qt6_QReadWriteLock.h
Author: BSS9395
Update: 2023-08-30T18:54:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QREADWRITELOCK_H
#define QT6_QREADWRITELOCK_H

#include <QMainWindow>
#include "ui_Qt6_QReadWriteLock.h"
#include <QThread>
#include <QRandomGenerator64>
#include <QTimer>
#include <QMutex>
#include <QReadWriteLock>

class Thread_Dice : public QThread {
    Q_OBJECT

public:
    inline static const char *_none = "None";
    inline static const char *_nega = "Nega";
    inline static const char *_posi = "Posi";

    unsigned int _seed = 0;
    unsigned int _dice = 0;
    const char *_state = _nega;
    QReadWriteLock _lock;

public:
    void run() override {
        while(_state != _none) {
            if(_state == _posi) {
                QWriteLocker locker(&_lock);
                _seed += 1;
                for(int i = 0; i < 5; i += 1) {
                    _dice += QRandomGenerator::global()->bounded(1, 7);
                }
                _dice /= 5;

            }
            msleep(500);
        }
    }

public:
    bool _Read_Dice(unsigned int *seed, unsigned int *dice) {
        if(_lock.tryLockForRead(100)) {
            *seed = _seed;
            *dice = _dice;
            _lock.unlock();
            return true;
        }
        return false;
    }
};

class Qt6_QMutex : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QMutex *_ui = nullptr;
    Thread_Dice *_thread_dice = new Thread_Dice();
    QTimer _timer = QTimer();

public:
    Qt6_QMutex(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QMutex) {
        _ui->setupUi(this);

        _ui->A_Started->setEnabled(true);
        _ui->A_Run->setEnabled(false);
        _ui->A_Pause->setEnabled(false);
        _ui->A_Stop->setEnabled(false);
        QObject::connect(_thread_dice, &Thread_Dice::started, this, [this]() -> void {
            _ui->PTE_Message->appendPlainText("Thread started");
            _ui->A_Started->setEnabled(false);
            _ui->A_Run->setEnabled(true);
            _ui->A_Pause->setEnabled(false);
            _ui->A_Stop->setEnabled(true);
        });
        QObject::connect(_thread_dice, &Thread_Dice::finished, this, [this]() -> void {
            _ui->PTE_Message->appendPlainText("Thread finished");
            _ui->A_Started->setEnabled(true);
            _ui->A_Run->setEnabled(false);
            _ui->A_Pause->setEnabled(false);
            _ui->A_Stop->setEnabled(false);
        });

        QObject::connect(&_timer, &QTimer::timeout, this, [this]() -> void {
            unsigned int seed = 0;
            unsigned int dice = 0;
            bool ok = _thread_dice->_Read_Dice(&seed, &dice);
            if(ok == true && _thread_dice->_state == Thread_Dice::_posi) {
                QString text = QString::asprintf("第%d次掷骰子，点数为%d。", seed, dice);
                _ui->PTE_Message->appendPlainText(text);
                QString filename = QString::asprintf(":/images/dice%d.jpg", dice);
                QPixmap image = QPixmap(filename);
                image = image.scaled(128, 128);
                _ui->L_Dice->setPixmap(image);
            }
        });
        _timer.start(200);

        QObject::connect(_ui->A_Started, &QAction::triggered, this, [this]() -> void {
            _thread_dice->_state = Thread_Dice::_nega;
            _thread_dice->start();
        });


        QObject::connect(_ui->A_Run, &QAction::triggered, this, [this]() -> void{
            _thread_dice->_state = Thread_Dice::_posi;
            _ui->A_Started->setEnabled(false);
            _ui->A_Run->setEnabled(false);
            _ui->A_Pause->setEnabled(true);
            _ui->A_Stop->setEnabled(true);
        });

        QObject::connect(_ui->A_Pause, &QAction::triggered, this, [this]() -> void {
            _thread_dice->_state = Thread_Dice::_nega;
            _ui->A_Started->setEnabled(false);
            _ui->A_Run->setEnabled(true);
            _ui->A_Pause->setEnabled(false);
            _ui->A_Stop->setEnabled(true);
        });

        QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {
            _thread_dice->_state = Thread_Dice::_none;
            _ui->A_Started->setEnabled(true);
            _ui->A_Run->setEnabled(false);
            _ui->A_Pause->setEnabled(false);
            _ui->A_Stop->setEnabled(false);
        });
    }

    ~Qt6_QMutex() {
        delete _ui;
        delete _thread_dice;
    }


};
#endif // QT6_QREADWRITELOCK_H
