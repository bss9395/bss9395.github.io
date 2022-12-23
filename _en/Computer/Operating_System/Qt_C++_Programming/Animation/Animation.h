/* Animation.h
Author: BSS9395
Update: 2022-12-06T22:22:00+08@China-Shanghai+08
Design: Animation
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Animation_h
#define Animation_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "ui_Animation.h"

class Animation : public QWidget {
    Q_OBJECT
    Q_PROPERTY(double _rotation READ _Get_Rotation WRITE _Set_Rotation)

public:
    Ui::Animation *_ui = nullptr;
    QTimer *_timer = new QTimer(this);

    double _rotation = 0;
    QPropertyAnimation _animation = QPropertyAnimation(this, "_rotation");
    QPixmap _pixmap = QPixmap();

public:
    double _Get_Rotation() {
        System::Logging(__FUNCTION__);

        return _rotation;
    }

    void _Set_Rotation(double rotation) {
        System::Logging(__FUNCTION__);

        _rotation = rotation;
        _Paint();
    }

    void _Paint() {
        System::Logging(__FUNCTION__);

        QPixmap _canvas = QPixmap(_pixmap.size());
        _canvas.fill(Qt::transparent);
        QPainter painter = QPainter(&_canvas);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::TextAntialiasing, true);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

        painter.save();
        painter.translate(_pixmap.rect().center());
        painter.rotate(_rotation);
        painter.translate(-_pixmap.rect().center());
        painter.drawPixmap(0, 0, _pixmap);
        painter.restore();

        _ui->label->setPixmap(_canvas);
    }

public:
    explicit Animation(QWidget *parent = nullptr)
        : QWidget(parent), _ui(new Ui::Animation) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

    }

public:
    virtual void showEvent(QShowEvent *event) override {
        System::Logging(__FUNCTION__);

        _pixmap = QPixmap(":/images/butterfly.png");

        _animation.setStartValue(0.0);
        _animation.setEndValue(360.0);
        _animation.setDuration(5000);
        _animation.setLoopCount(-1);
        _animation.start();

        ////////////////////////////////


//        QObject::connect(_timer, &QTimer::timeout, this, [this]() -> void {
//            System::Logging("QObject::connect(timer, &QTimer::timeout, this, [this]() -> void {");
//
//            _rotation += 1.0;
//            _rotation -= (int)(_rotation / 360.0) * 360.0;
//            System::Logging("rotation=%lf", _rotation);
//
//            _Paint();
//        });
//        _timer->start(50);

        QWidget::showEvent(event);
    }
};

#endif // Animation_h
