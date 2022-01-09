/* Timer.cpp
Author: BSS9395
Update: 2022-01-09T01:21:00+08@China-Guangdong-Shenzhen+08
Design: Timer
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

Timer::Timer(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::Timer) {
    Logging(__FUNCTION__);

    _ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/view_in_ar.png"));
    this->setWindowTitle(QString("Timer"));

    ////////////////////////////////////

    _clock.setInterval(5);
    _ui->LCDN_Clock->setDigitCount(12);
    _ui->LCDN_Clock->display(QString("00:00:00:000"));
    _clock.start();
    QObject::connect(&_clock, &QTimer::timeout, [this]() -> void {
        // Logging("QObject::connect(&_clock, &QTimer::timeout, [this]() -> void {");

        QTime time = QTime::currentTime();
        QString stamp = time.toString("hh:mm:ss.zzz");
        if (time.minute() % 30 == 29) {
            stamp[2] = ' ';
        }
        if (time.second() % 30 == 29) {
            stamp[5] = ' ';
        }
        if (time.msec() >= 500) {
            stamp[8] = ' ';
        }
        _ui->LCDN_Clock->display(stamp);
    });

    _timer.setInterval(5);
    _ui->LCDN_Timer->setDigitCount(12);
    _ui->LCDN_Timer->display(QString("00:00:00.000"));
    QObject::connect(_ui->PB_Update_Interval, &QPushButton::clicked, [this]() -> void {
        Logging("QObject::connect(_ui->PB_Update_Interval, &QPushButton::clicked, [this]() -> void {");

        _timer.setInterval(_ui->SB_Interval->value());
    });

    QObject::connect(_ui->PB_Continue_Pause, &QPushButton::clicked, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->PB_Continue_Pause, &QPushButton::clicked, [this](bool checked) -> void {");

        if (checked == true) {
            _ui->PB_Continue_Pause->setText(QString("暂停"));
            _ui->PB_Clear->setEnabled(false);
            _last = QTime::currentTime();
            _timer.start();
        } else {
            _ui->PB_Continue_Pause->setText(QString("继续"));
            _ui->PB_Clear->setEnabled(true);
            _timer.stop();
            Update_Timer(true);
        }
    });

    QObject::connect(_ui->PB_Clear, &QPushButton::clicked, [this]() -> void {
        Logging("QObject::connect(_ui->PB_Clear, &QPushButton::clicked, [this]() -> void {");

        _ui->LCDN_Timer->display(QString("00:00:00.000"));
        _elapsed = QTime(0, 0, 0, 0);
        _last = QTime::currentTime();
    });

    QObject::connect(&_timer, &QTimer::timeout, [this]() -> void {
        // Logging("QObject::connect(&_timer, &QTimer::timeout, [this]() -> void {");

        Update_Timer(false);
    });
}

Timer::~Timer() {
    Logging(__FUNCTION__);

    delete _ui;
}

void Timer::Update_Timer(bool paused) {
    // Logging(__FUNCTION__);

    iptr hour = _elapsed.hour();
    iptr minute = _elapsed.minute();
    iptr second = _elapsed.second();
    iptr milli = _elapsed.msec();
    iptr carry = 0;

    QTime time = QTime::currentTime();
    milli += 1000 + carry + time.msec() - _last.msec();
    carry = milli / 1000 - 1;
    milli %= 1000;

    second += 60 + carry + time.second() - _last.second();
    carry = second / 60 - 1;
    second %= 60;

    minute += 60 + carry + time.minute() - _last.minute();
    carry = minute / 60 - 1;
    minute %= 60;

    hour += 24 + carry + time.hour() - _last.hour();
    carry = hour / 24 - 1;
    hour %= 24;
    (void)carry;

    QString stamp = QString::asprintf("%02td:%02td:%02td.%03td", hour, minute, second, milli);
    if (paused == false) {
        if (minute % 30 == 29) {
            stamp[2] = ' ';
        }
        if (second % 30 == 29) {
            stamp[5] = ' ';
        }
        if (milli >= 500) {
            stamp[8] = ' ';
        }
    } else if (paused == true) {
        _elapsed = QTime(hour, minute, second, milli); // save timer state
    }
    _ui->LCDN_Timer->display(stamp);
}
