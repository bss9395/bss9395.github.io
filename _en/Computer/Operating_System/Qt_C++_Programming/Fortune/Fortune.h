/* Fortune.h
Author: BSS9395
Update: 2022-03-07T18:14:00+08@China-Guangdong-Shenzhen+08
Design: Fortune
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Fortune_h
#define Fortune_h

#define Header_h
#include "Common.h"
#include "ui_Fortune.h"
#include "System.h"

class Dice : public Thread {
    Q_OBJECT

public:
    uptr _seed = 0;  // note: unsigned integer for cyclic variable.
    iptr _dice = 0;

public:
    void run() override {
        System::Logging(__FUNCTION__);

        qsrand(QTime::currentTime().msec());
        while(_state != Thread::_Stopped) {
            if(_state == Thread::_Running) {
                _dice = (qrand() % 6) + 1;
                Yield(_seed, _dice);
                _seed += 1;
            }
            msleep(500);
        }
        this->quit();          // note: use this->quit() inside the thread body.
        // this->terminate();  // note: use terminate() outside the thread body.
    }

signals:
    void Yield(uptr seed, iptr dice);
};

class Fortune : public QMainWindow {
    Q_OBJECT

public:
    Ui::Fortune *_ui = nullptr;
    Dice _dice = Dice();

public:
    explicit Fortune(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Fortune) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        QObject::connect(&_dice, &QThread::started, this, [this]() -> void {
            System::Logging("QObject::connect(&_dice, &QThread::started, this, [this]() -> void {");

            _ui->PTE_Logging->appendPlainText("thread started");
        });

        QObject::connect(&_dice, &QThread::finished, this, [this]() -> void {
            System::Logging("QObject::connect(&_dice, &QThread::finished, this, [this]() -> void {");

            _ui->PTE_Logging->appendPlainText("thread finished");
        });

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Logging->clear();
        });

        QObject::connect(_ui->A_Running, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Running, &QAction::triggered, this, [this]() -> void {");

            Running();
        });

        QObject::connect(_ui->A_Pending, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Blocked, &QAction::triggered, this, [this]() -> void {");

            Pending();
        });

        QObject::connect(_ui->A_Stopped, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Stopped, &QAction::triggered, this, [this]() -> void {");

            Stopped();
        });

        QObject::connect(&_dice, &Dice::Yield, this, [this](uptr seed, iptr dice) -> void {
            // System::Logging("QObject::connect(&_dice, &Dice::Yield, this, [this](uptr seed, iptr dice) -> void {");

            _ui->PTE_Logging->appendPlainText(QString("第%1次掷骰子点数为%2").arg(seed).arg(dice));

            QPixmap pixmap = QPixmap();
            pixmap.load(QString(":/images/dice/dice_%1.png").arg(dice));
            _ui->TB_Dice->setIcon(pixmap);
        });
    }

    virtual ~Fortune() override {
        System::Logging(__FUNCTION__);

        Stopped();
        delete _ui;
    }

public:
    bool event(QEvent *event) override {
        // System::Logging(__FUNCTION__);

        if(event->type() == QEvent::Close) {
            Stopped();
            event->accept();
            return true;
        }
        return QWidget::event(event);
    }

public:
    void Running() {
        System::Logging(__FUNCTION__);

        if(_dice.isRunning() == false) {
            _dice.start();
        }
        _dice.Transfer(Thread::_Running);
    }

    void Pending() {
        System::Logging(__FUNCTION__);

        _dice.Transfer(Thread::_Pending);
    }

    void Stopped() {
        System::Logging(__FUNCTION__);

        _dice.Transfer(Thread::_Stopped);
        if(_dice.isRunning() == true) {
            _dice.quit();
            _dice.wait();
        }
    }
};

#endif // Fortune_h
