/* Plotter.h
Author: BSS9395
Update: 2022-06-25T22:47:00+08@China-Shanghai+08
Design: Plotter
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Plotter_h
#define Plotter_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "ui_Plotter.h"


class Plotter : public QMainWindow {
    Q_OBJECT

public:
    Ui::Plotter *_ui = nullptr;
    QPainter _painter = QPainter();
    QPen _dotted = QPen();
    QPen _solid = QPen();
    QPen _pen = QPen();
    QFontMetrics _metrics = QFontMetrics(this->font());
    QMargins _margins = QMargins(80, 40, 40, 40);
    QRect _window = QRect();
    QRect _figure = QRect();

    qreal _x_min = +0.0;
    qreal _x_max = +10.0;
    qreal _y_min = -1.5;
    qreal _y_max = +1.5;
    iptr _cells = 100000;
    iptr _x_ticks = 10;
    iptr _y_ticks = 4;
    QVector<QPointF> _data = QVector<QPointF>();
    QPolygon _points = QVector<QPoint>();

public:
    explicit Plotter(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Plotter) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup_Background();
        _Setup_Pen();
        _Generate_Points();
    }

    virtual ~Plotter() {
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

        _dotted.setWidth(1);
        _dotted.setColor(Qt::gray);
        _dotted.setStyle(Qt::DotLine);
        _dotted.setCapStyle(Qt::FlatCap);
        _dotted.setJoinStyle(Qt::BevelJoin);

        _solid.setWidth(1);
        _solid.setColor(Qt::black);
        _solid.setStyle(Qt::SolidLine);
        _solid.setCapStyle(Qt::FlatCap);
        _solid.setJoinStyle(Qt::BevelJoin);

        _pen.setWidth(2);
        _pen.setColor(Qt::blue);
        _pen.setStyle(Qt::SolidLine);
        _pen.setCapStyle(Qt::FlatCap);
        _pen.setJoinStyle(Qt::BevelJoin);
    }

    void _Generate_Points() {
        System::Logging(__FUNCTION__);

        qreal step = (_x_max - _x_min) / _cells;
        qreal t = _x_min;
        qreal w = 4.0;
        _data.reserve(_cells + 1);
        for(iptr i = 0; i <= _cells; i += 1) {
            _data.append(QPointF(t, qSin(w * t)));
            t += step;
        }
    }

    void _Plot_Grid() {
        System::Logging(__FUNCTION__);

        if(_figure.isValid() == false) {
            return ;
        }
        _painter.setPen(_solid);
        // _painter.drawRect(_figure);
        _painter.drawRect(_figure.adjusted(0, 0, -1, -1));  // note: integer rounds towards 0.

        ////////////////////////////////

        QString label = "";
        QRect rect = QRect();
        label = "y = sin(x)";
        rect = _metrics.boundingRect(label);
        _painter.drawText(QPoint(_figure.left() + (_figure.width() - rect.width()) / 2, (_margins.top() - rect.height()) / 2 + rect.height()), label);

        ////////////////////////////////

        iptr x_pos = 0;
        qreal x_value = 0.0;
        for(double i = 0.0; i <= _x_ticks; i += 1.0) {
            x_pos = _figure.left() + i * (_figure.right() - _figure.left()) / _x_ticks;
            x_value = _x_min + i * (_x_max - _x_min) / _x_ticks;
            _painter.setPen(_dotted);
            _painter.drawLine(QPoint(x_pos, _figure.top()), QPoint(x_pos, _figure.bottom()));
            _painter.setPen(_solid);
            _painter.drawLine(QPoint(x_pos, _figure.bottom()), QPoint(x_pos, _figure.bottom() + 5));

            label = QString::asprintf("%.1f", x_value);
            rect = _metrics.boundingRect(label);
            _painter.drawText(QPoint(x_pos - rect.width() / 2, _figure.bottom() + 5 + rect.height()), label);
        }
        label = "t /s";
        rect = _metrics.boundingRect(label);
        _painter.drawText(QPoint(_figure.left() + (_figure.width() - rect.width()) / 2, _window.bottom() - rect.height() / 2), label);

        ////////////////////////////////

        iptr y_pos = 0;
        qreal y_value = 0.0;
        for(double i = 0.0; i <= _y_ticks; i += 1.0) {
            y_pos = _figure.bottom() - i * (_figure.bottom() - _figure.top()) / _y_ticks;
            y_value = _y_min + i * (_y_max - _y_min) / _y_ticks;
            _painter.setPen(_dotted);
            _painter.drawLine(QPoint(_figure.left(), y_pos), QPoint(_figure.right(), y_pos));
            _painter.setPen(_solid);
            _painter.drawLine(QPoint(_figure.left() - 5, y_pos), QPoint(_figure.left(), y_pos));

            label = QString::asprintf("%.1f", y_value);
            rect = _metrics.boundingRect(label);
            _painter.drawText(QPoint(_figure.left() - 10 - rect.width(), y_pos + rect.height() / 2), label);
        }
        label = "sin(t) /1";
        rect = _metrics.boundingRect(label);
        _painter.save();
        _painter.translate(0, _window.height() / 2);
        _painter.rotate(-90.0);
        _painter.drawText(QPoint(-rect.width() / 2, (_margins.left() - rect.height()) / 2), label);
        _painter.restore();
    }

    void _Plot_Curve() {
        System::Logging(__FUNCTION__);

        qreal x = 0.0;
        qreal y = 0.0;
        iptr x_pos = 0;
        iptr y_pos = 0;
        _points.clear();
        for(iptr i = 0, count = _data.count(); i < count; i += 1) {
            x = _data[i].x();
            y = _data[i].y();
            x_pos = _figure.width() * (x - _x_min) / (_x_max - _x_min);
            x_pos = _margins.left() + x_pos;
            y_pos = _figure.height() * (y - _y_min) / (_y_max - _y_min);
            y_pos = _margins.top() + _figure.bottom() - y_pos;
            _points.append(QPoint(x_pos, y_pos));
        }

        _painter.setPen(_pen);
        _painter.drawPolyline(_points);  // note: drawPolyline(const QPolygon &polyline);
    }

    void paintEvent(QPaintEvent *event) override {
        System::Logging(__FUNCTION__);
        (void) event;

        _painter.begin(this);
        _painter.setRenderHint(QPainter::Antialiasing);
        _painter.setRenderHint(QPainter::TextAntialiasing);

        _window = QRect(0, 0, this->width(), this->height());
        _figure = QRect(_window.left() + _margins.left(),
                        _window.top() + _margins.top(),
                        _window.width() - _margins.left() - _margins.right(),
                        _window.height() - _margins.top() - _margins.bottom());
        _painter.setWindow(_window);

        _Plot_Grid();
        _Plot_Curve();
        _painter.end();
    }
};

#endif // Plotter_h
