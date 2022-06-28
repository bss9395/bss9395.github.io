/* Window.h
Author: BSS9395
Update: 2022-06-25T22:47:00+08@China-Shanghai+08
Design: Plotter
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Window_h
#define Window_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "ui_Window.h"


class Window : public QMainWindow {
    Q_OBJECT

public:
    Ui::Window *_ui = nullptr;
    QPen _pen = QPen();
    QBrush _brush = QBrush();
    QLinearGradient _linear = QLinearGradient();
    QRadialGradient _radial = QRadialGradient();
    QConicalGradient _conical = QConicalGradient();

public:
    explicit Window(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Window) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup_Background();
        _Setup_Pen();
        _Setup_Brush();
        _Setup_Gradient();
    }

    virtual ~Window() {
        System::Logging(__FUNCTION__);

        delete _ui;
    }

public:
    void _Setup_Background() {
        System::Logging(__FUNCTION__);

        this->setPalette(QPalette(Qt::white));
        this->setAutoFillBackground(true);
    }

    void _Setup_Pen() {
        System::Logging(__FUNCTION__);

        _pen.setWidth(1);
        _pen.setColor(Qt::black);
        _pen.setStyle(Qt::SolidLine);
        _pen.setCapStyle(Qt::FlatCap);
        _pen.setJoinStyle(Qt::BevelJoin);
    }

    void _Setup_Brush() {
        System::Logging(__FUNCTION__);

        _brush.setColor(Qt::green);
        _brush.setStyle(Qt::SolidPattern);
    }

    void _Setup_Gradient() {
        System::Logging(__FUNCTION__);

        _linear = QLinearGradient(0, 0, 100, 0);
        _linear.setColorAt(0.0, Qt::white);
        _linear.setColorAt(1.0, Qt::green);
        _linear.setSpread(QGradient::PadSpread);

        _radial = QRadialGradient(QPoint(50, 0), 50, QPoint(75, 0));
        _radial.setColorAt(0.0, Qt::white);
        _radial.setColorAt(1.0, Qt::green);
        _radial.setSpread(QGradient::ReflectSpread);

        _conical = QConicalGradient(QPoint(50, 0), 45.0);  // note: counter-clockwise.
        _conical.setColorAt(0.0, Qt::white);
        _conical.setColorAt(1.0, Qt::green);
        _conical.setSpread(QGradient::PadSpread);
    }

    void paintEvent(QPaintEvent *event) override {
        System::Logging(__FUNCTION__);
        (void) event;

        QPainter painter = QPainter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        painter.setPen(_pen);
        // painter.setBrush(_brush);

        iptr width = this->width();
        iptr height = this->height();
        iptr side = qMin(width, height);
        QRect rect = QRect((width - side) / 2, (height - side) / 2, side, side);
        painter.drawRect(rect);
        painter.setViewport(rect);
        painter.setWindow(-100, -100, 200, 200);

        // painter.setBrush(_linear);
        painter.setBrush(_radial);
        // painter.setBrush(_conical);
        painter.setCompositionMode(QPainter::CompositionMode_Multiply);
        for(iptr i = 0; i < 10; i += 1) {
            painter.drawEllipse(QPoint(50, 0), 50, 50);
            painter.rotate(36);  // note: clockwise.
        }
    }
};

#endif // Window_h
