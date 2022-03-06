/* Fortune.h
Author: BSS9395
Update: 2022-03-07T00:33:00+08@China-Guangdong-Shenzhen+08
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

class Dice : public QThread {
    Q_OBJECT

public:
    typedef const char *State;
    static inline const State _Unknown = "Unknown";
    static inline const State _Created = "Created";
    static inline const State _Running = "Running";
    static inline const State _Blocked = "Blocked";
    static inline const State _Waiting = "Waiting";
    static inline const State _Stopped = "Stopped";

public:
    State _state = _Unknown;
    iptr _seed = 0;
    iptr _dice = 0;

public:
    Dice() {
        System::Logging(__FUNCTION__);

        _state = _Created;
    }

public:
    void Start() {
        System::Logging(__FUNCTION__);

        _state = _Running;
    }

    void Pause() {
        System::Logging(__FUNCTION__);

        _state = _Blocked;
    }

    void Close() {
        System::Logging(__FUNCTION__);

        _state = _Stopped;
    }

public:
    void run() override {
        System::Logging(__FUNCTION__);

        qsrand(QTime::currentTime().msec());
        while(_state != _Stopped) {
            if(_state == _Running) {
                _dice = (qrand() % 6) + 1;
                Yield(_seed, _dice);
                _seed += 1;
            }
            msleep(500);
        }
        this->terminate();
    }

signals:
    void Yield(iptr seed, iptr dice);
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

        QObject::connect(_ui->A_Clear, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, [this]() -> void {");

            _ui->PTE_Logging->clear();
        });

        QObject::connect(_ui->A_Start, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Start, &QAction::triggered, [this]() -> void {");

            _dice.start();
            _dice.Start();
        });

        QObject::connect(_ui->A_Pause, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Pause, &QAction::triggered, [this]() -> void {");

            _dice.Pause();
        });

        QObject::connect(_ui->A_Stop, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Stop, &QAction::triggered, [this]() -> void {");

            _dice.Close();
            _dice.wait();
        });

        QObject::connect(&_dice, &QThread::started, [this]() -> void {
            System::Logging("QObject::connect(&_dice, &QThread::started, [this]() -> void {");

            _ui->PTE_Logging->appendPlainText("thread started");
        });

        QObject::connect(&_dice, &QThread::finished, [this]() -> void {
            System::Logging("QObject::connect(&_dice, &QThread::finished, [this]() -> void {");

            _ui->PTE_Logging->appendPlainText("thread finished");
        });

        QObject::connect(&_dice, &Dice::Yield, [this](iptr seed, iptr dice) -> void {
            System::Logging("QObject::connect(&_dice, &Dice::Yield, [this](iptr seed, iptr dice) -> void {");

            _ui->PTE_Logging->appendPlainText(QString("第%1次掷骰子点数%td").arg(seed).arg(dice));
            QPixmap pixmap = QPixmap();
            pixmap.load(QString(":/images/dice/dice_%1.png").arg(dice));
            _ui->TB_Dice->setIcon(pixmap);
        });
    }

    virtual ~Fortune() override {
        System::Logging(__FUNCTION__);

        if(_dice.isRunning()) {
            _dice.Close();
            _dice.wait();
        }
        delete _ui;
    }

public:
    bool event(QEvent *event) override {
        // System::Logging(__FUNCTION__);

        if(event->type() == QEvent::Close) {
            System::Logging("if(event->type() == QEvent::Close) {");
            if(_dice.isRunning() == true) {
                System::Logging("if(_dice.isRunning() == true) {");
                _dice.Close();
                _dice.wait();
            }
            event->accept();
        }
        return QWidget::event(event);
    }

};

#endif // Fortune_h
