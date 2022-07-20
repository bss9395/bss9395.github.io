/* QVideoWidget_Frame.cpp
Author: BSS9395
Update: 2022-07-20T02:00:00+08@China-Shanghai+08
Design: Player
Encode: UTF-8
System: Qt 5.14.2
*/

#include "QVideoWidget_Handler.h"
#include "QVideoWidget_Frame.h"

////////////////////////////////////////////////////////////////////////////////

QVideoWidget_Handler::QVideoWidget_Handler(QWidget *parent)
    : QVideoWidget(parent) {
    System::Logging(__FUNCTION__);

    this->setAttribute(Qt::WA_Hover, true);
}

QVideoWidget_Handler::~QVideoWidget_Handler() {
    System::Logging(__FUNCTION__);
}

void QVideoWidget_Handler::_Setup(QVideoWidget_Frame *frame) {
    System::Logging(__FUNCTION__);
    _frame = frame;
}

////////////////////////////////////////

bool QVideoWidget_Handler::event(QEvent *event) {
    // System::Logging(__FUNCTION__);
    // iptr index = _event_type._Index(event->type());
    // System::Logging("event == [%s: %s]", _event_type[index]._field, _event_type[index]._alias);

    if(event->type() == QEvent::HoverMove) {
        _frame->_Hover_Move();
    }
    return QVideoWidget::event(event);
}

void QVideoWidget_Handler::resizeEvent(QResizeEvent *event) {
    System::Logging(__FUNCTION__);

    _frame->_Resize();
    return QVideoWidget::resizeEvent(event);
}

void QVideoWidget_Handler::mousePressEvent(QMouseEvent *event) {
    // System::Logging(__FUNCTION__);

    _frame->_Mouse_Press(event);
    return QVideoWidget::mousePressEvent(event);
}

void QVideoWidget_Handler::keyPressEvent(QKeyEvent *event) {
    System::Logging(__FUNCTION__);

    _frame->_Key_Press(event);
    return QVideoWidget::keyPressEvent(event);
}

void QVideoWidget_Handler::showEvent(QShowEvent *event) {
    System::Logging(__FUNCTION__);

    _frame->_Show_Hide(true);
    QVideoWidget::showEvent(event);
}

void QVideoWidget_Handler::hideEvent(QHideEvent *event) {
    System::Logging(__FUNCTION__);

    _frame->_Show_Hide(false);
    QVideoWidget::hideEvent(event);
}

////////////////////////////////////////////////////////////////////////////////

QVideoWidget_Frame::QVideoWidget_Frame(QWidget *parent)
    : QWidget(parent), _ui(new Ui::QVideoWidget_Frame) {
    System::Logging(__FUNCTION__);
    _ui->setupUi(this);
    _Setup();

    QObject::connect(&_timer, &QTimer::timeout, this, [this]() -> void {
        // System::Logging("QObject::connect(&_timer, &QTimer::timeout, this, [this]() -> void {");

        QPoint cursor = QCursor::pos();
        if(_state == _Posi || (_area._x_min <= cursor.x() && cursor.x() <= _area._x_max && _area._y_min <= cursor.y() && cursor.y() <= _area._y_max)) {
            _state = _Nega;
            _timer.start(_interval);
        } else if(_state == _Nega) {
            _ui->F_Tool->hide();
            _state = _None;
            _timer.stop();
        }
    });

    QObject::connect(&_delayer, &QTimer::timeout, this, [this]() -> void {
        System::Logging("QObject::connect(&_delayer, &QTimer::timeout, this, [this]() -> void {");
        _ui->F_Panel->show();
        _delayer.stop();
    });

    ////////////////////////////////

    QObject::connect(_ui->TB_Play, &QToolButton::clicked, this, [this]() -> void {
        // System::Logging("QObject::connect(_ui->TB_Play, &QToolButton::clicked, this, [this]() -> void {");

        _player->play();
        _ui->TB_Play->hide();
        _ui->TB_Pause->show();
    });
    QObject::connect(_ui->TB_Pause, &QToolButton::clicked, this, [this]() -> void {
        // System::Logging("QObject::connect(_ui->TB_Pause, &QToolButton::clicked, this, [this]() -> void {");

        _player->pause();
        _ui->TB_Play->show();
        _ui->TB_Pause->hide();
    });

    QObject::connect(_ui->TB_Volume, &QToolButton::clicked, this, [this]() -> void {
        System::Logging("QObject::connect(_ui->TB_Volume, &QToolButton::clicked, this, [this]() -> void {");

        _ui->S_Volume->blockSignals(true);
        _ui->TB_Volume->hide();
        _ui->TB_Mute->show();
        _volume = _ui->S_Volume->value();
        _ui->S_Volume->setValue(0);
        _player->setMuted(true);
        _ui->S_Volume->blockSignals(false);
    });
    QObject::connect(_ui->TB_Mute, &QToolButton::clicked, this, [this]() -> void {
        System::Logging("QObject::connect(_ui->TB_Mute, &QToolButton::clicked, this, [this]() -> void {");

        _ui->S_Volume->blockSignals(true);
        _ui->TB_Volume->show();
        _ui->TB_Mute->hide();
        _ui->S_Volume->setValue(_volume);
        _player->setMuted(false);
        _ui->S_Volume->blockSignals(false);
    });
    QObject::connect(_ui->S_Volume, &QSlider::valueChanged, this, [this]() -> void {
        System::Logging("QObject::connect(_ui->S_Volume, &QSlider::valueChanged, this, [this]() -> void {");

        _volume = _ui->S_Volume->value();
        _player->setVolume(qRound(100.0 * QAudio::convertVolume(_ui->S_Volume->value() / 100.0, QAudio::LogarithmicVolumeScale, QAudio::LinearVolumeScale)));
        if(_volume <=0 ) {
            _ui->TB_Volume->hide();
            _ui->TB_Mute->show();
        } else {
            _ui->TB_Volume->show();
            _ui->TB_Mute->hide();
        }
    });

    QObject::connect(_ui->TB_Full, &QToolButton::clicked, this, [this]() -> void {
        System::Logging("QObject::connect(_ui->TB_Full, &QToolButton::clicked, this, [this]() -> void {");

        _ui->VWH_Video->setFullScreen(true);
        _ui->TB_Full->hide();
        _ui->TB_Restore->show();

        _ui->F_Panel->hide();
        _ui->F_Panel->show();
        _state = _Posi;
    });
    QObject::connect(_ui->TB_Restore, &QToolButton::clicked, this, [this]() -> void {
        System::Logging("QObject::connect(_ui->TB_Restore, &QToolButton::clicked, this, [this]() -> void {");

        _ui->VWH_Video->setFullScreen(false);
        _ui->TB_Full->show();
        _ui->TB_Restore->hide();
    });

    ////////////////////////////////////

    QObject::connect(_player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) -> void {
        System::Logging("QObject::connect(_player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) -> void {");

        _ui->S_Progress->setRange(0, duration);
        iptr tune = duration % 1000;
        iptr sec = (duration /= 1000) % 60;
        iptr min = (duration /= 60 ) % 60;
        iptr hour = (duration /= 60) % 24;
        _ui->L_Timespan->setText(QString::asprintf("%02td:%02td:%02td.%03td", hour, min, sec, tune));
    });

    QObject::connect(_player, &QMediaPlayer::positionChanged, this, [this](qint64 position) -> void {
        // System::Logging("QObject::connect(_player, &QMediaPlayer::positionChanged, this, [this](qint64 position) -> void {");

        _ui->S_Progress->setValue(position);
        iptr tune = position % 1000;
        iptr sec = (position /= 1000) % 60;
        iptr min = (position /= 60 ) % 60;
        iptr hour = (position /= 60) % 24;
        _ui->L_Timestamp->setText(QString::asprintf("%02td:%02td:%02td.%03td", hour, min, sec, tune));
    });

    ////////////////////////////////////

    // QUrl url = QUrl("qrc:///videos/Two_Black_Holes_Merge_into_One.mp4");
    // _player->playlist()->addMedia(url);
    // _player->playlist()->setCurrentIndex(0);
    // _ui->TB_Play->click();
}

QVideoWidget_Frame::~QVideoWidget_Frame() {
    System::Logging(__FUNCTION__);
    Delete(_ui);
    Delete(_player);
    Delete(_play_list);
}

void QVideoWidget_Frame::_Setup() {
    System::Logging(__FUNCTION__);

    _ui->VWH_Video->_Setup(this);

    _ui->F_Panel->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    _ui->F_Panel->setAttribute(Qt::WA_TranslucentBackground, true);
    _ui->F_Panel->setStyleSheet(R"(
        background-color: rgba(255, 255, 255, 0);
    )");
    _ui->F_Panel->show();
    _ui->F_Tool->hide();

    _ui->S_Progress->setTracking(false);
    _ui->S_Progress->setSingleStep(1);

    _ui->TB_Pause->hide();
    _ui->TB_Mute->hide();
    _ui->S_Volume->setTracking(true);
    _ui->S_Volume->setRange(0, 100);
    _ui->S_Volume->setSingleStep(1);
    _ui->S_Volume->setValue(_volume);
    _ui->TB_Restore->hide();

    ////////////////////////////////

    _player = new QMediaPlayer(this);
    _play_list = new QMediaPlaylist();
    _player->setPlaylist(_play_list);
    _player->setVideoOutput(_ui->VWH_Video);
    _player->setVolume(qRound(100.0 * QAudio::convertVolume(_ui->S_Volume->value() / 100.0, QAudio::LogarithmicVolumeScale, QAudio::LinearVolumeScale)));
}

////////////////////////////////////////

void QVideoWidget_Frame::_Hover_Move() {
    // System::Logging(__FUNCTION__);

    if(_state == _None) {
        _ui->F_Tool->show();
        _state = _Nega;
        _timer.start(_interval);
    } else {
        _state = _Posi;
    }
}

void QVideoWidget_Frame::_Resize() {
    // System::Logging(__FUNCTION__);

    QPoint point = _ui->VWH_Video->mapToGlobal(QPoint(0, 0));
    _ui->F_Panel->setFixedWidth(_ui->VWH_Video->width());
    _ui->F_Panel->move(point.x(), point.y() + _ui->VWH_Video->height() - _ui->F_Panel->height());
    _area = Area(_ui->F_Panel->x(), _ui->F_Panel->y(), _ui->F_Panel->x() + _ui->F_Panel->width(), _ui->F_Panel->y() + _ui->F_Panel->height());
}

void QVideoWidget_Frame::_Mouse_Press(QMouseEvent *event) {
    // System::Logging(__FUNCTION__);

    if(event->button() == Qt::LeftButton) {
        if(_ui->TB_Play->isHidden() == false) {
            _ui->TB_Play->click();
        } else if(_ui->TB_Pause->isHidden() == false) {
            _ui->TB_Pause->click();
        }
    }
}

void QVideoWidget_Frame::_Key_Press(QKeyEvent *event) {
    System::Logging(__FUNCTION__);

    if(event->key() == Qt::Key_Escape && _ui->VWH_Video->isFullScreen() == true) {
        _ui->VWH_Video->setFullScreen(false);
        _ui->TB_Full->show();
        _ui->TB_Restore->hide();
    }
}

void QVideoWidget_Frame::_Show_Hide(bool show_hide) {
    System::Logging(__FUNCTION__);

    if(show_hide == true) {
        _delayer.start(_delay);
    } else if(show_hide == false) {
        _ui->F_Panel->hide();
    }
}

////////////////////////////////////////

void QVideoWidget_Frame::moveEvent(QMoveEvent *event) {
    System::Logging(__FUNCTION__);

    _Resize();
    return QWidget::moveEvent(event);
}

////////////////////////////////////////////////////////////////////////////////
