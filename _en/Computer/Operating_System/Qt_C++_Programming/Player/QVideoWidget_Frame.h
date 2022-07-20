/* QVideoWidget_Frame.h
Author: BSS9395
Update: 2022-07-20T02:00:00+08@China-Shanghai+08
Design: Player
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef QVideoWidget_Frame_h
#define QVideoWidget_Frame_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_QVideoWidget_Frame.h"

class QVideoWidget_Frame : public QWidget, public Boolean {
    Q_OBJECT

public:
    Ui::QVideoWidget_Frame *_ui = nullptr;
    QMediaPlayer *_player = nullptr;
    QMediaPlaylist *_play_list = nullptr;
    QTimer _timer = QTimer();
    QTimer _delayer = QTimer();
    iptr _interval = 1500;
    iptr _delay = 250;
    Bool _state = _None;
    Area _area = Area();
    iptr _volume = 50;

public:
    explicit QVideoWidget_Frame(QWidget *parent = nullptr);
    virtual ~QVideoWidget_Frame();
    void _Setup();

public:
    void _Hover_Move();
    void _Resize();
    void _Mouse_Press(QMouseEvent *event);
    void _Key_Press(QKeyEvent *event);
    void _Show_Hide(bool show_hide);

public:
    virtual void moveEvent(QMoveEvent *event) override;
};

#endif // QVideoWidget_Frame_h
