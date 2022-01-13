/* Timer.h
Author: BSS9395
Update: 2022-01-09T01:21:00+08@China-Guangdong-Shenzhen+08
Design: Timer
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Timer_h
#define Timer_h

#define   Header_h
#include "Common.h"
#include "ui_Timer.h"

class Timer : public QMainWindow {
    Q_OBJECT

public:
    Ui::Timer *_ui = nullptr;
    QTimer _clock = QTimer();
    QTimer _timer = QTimer();
    QTime _last = QTime::currentTime();
    QTime _elapsed = QTime(0, 0, 0, 0);

public:
    Timer(QWidget *parent = nullptr);
    ~Timer();

public:
    void Update_Timer(bool paused = false);
};
#endif // Timer_h
