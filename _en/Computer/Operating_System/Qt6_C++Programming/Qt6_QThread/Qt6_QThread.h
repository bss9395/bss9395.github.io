/* Qt6_QThread.h
Author: BSS9395
Update: 2023-08-30T18:07:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QTHREAD_H
#define QT6_QTHREAD_H

#include <QMainWindow>
#include "ui_Qt6_QThread.h"
#include <QThread>
#include <QRandomGenerator64>

class Thread_Dice : public QThread {
    Q_OBJECT

public:
	inline static const char *_none = "None";
    inline static const char *_nega = "Nega";
    inline static const char *_posi = "Posi";

    unsigned int _seed = 0;
    unsigned int _dice = 0;
    const char *_state = _nega;

public:
    void run() override {

        while(_state != _none) {
            if(_state == _posi) {
                _seed += 1;
                _dice = QRandomGenerator::global()->bounded(1, 7);
                emit _New_Dice(_seed, _dice);
            }
            msleep(500);
        }
    }

signals:
    void _New_Dice(unsigned int seed, unsigned int dice);
};

class Qt6_QThread : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QThread *_ui = nullptr;
    Thread_Dice *_thread_dice = new Thread_Dice();


public:
    Qt6_QThread(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QThread) {
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

        QObject::connect(_thread_dice, &Thread_Dice::_New_Dice, this, [this](unsigned int seed, unsigned int dice) -> void{
            QString text = QString::asprintf("第%d次掷骰子，点数为%d", seed, dice);
            _ui->PTE_Message->appendPlainText(text);

            QString filename = QString::asprintf(":/images/dice%d.jpg", dice);
            QPixmap image = QPixmap(filename);
            image = image.scaled(128, 128);
            _ui->L_Dice->setPixmap(image);
        });

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

    ~Qt6_QThread() {
        delete _ui;
        delete _thread_dice;
    }


};
#endif // QT6_QTHREAD_H
