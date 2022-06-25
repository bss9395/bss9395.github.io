/* Painter.h
Author: BSS9395
Update: 2022-06-25T22:47:00+08@China-Shanghai+08
Design: Painter
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Painter_h
#define Painter_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "ui_Painter.h"

class Painter : public QMainWindow {
    Q_OBJECT

public:
    Ui::Painter *_ui = nullptr;
    iptr _width = 0;
    iptr _height = 0;
    QRect _rect = QRect();
    iptr _from = 0;
    iptr _span = 0;
    QPen _pen = QPen();
    QBrush _brush = QBrush();
    QPainter _painter = QPainter();

public:
    explicit Painter(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Painter) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup_Background();
        _Setup_Pen();
        _Setup_Brush();
    }

    virtual ~Painter() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void _Setup_Background() {
        System::Logging(__FUNCTION__);
        _width = this->width();
        _height = this->height();
        _rect = QRect(_width / 4, _height / 4, _width / 2, _height / 2);

        this->setPalette(QPalette(Qt::white));
        this->setAutoFillBackground(true);
    }

    void _Setup_Pen() {
        System::Logging(__FUNCTION__);
        _pen.setWidth(3);
        _pen.setColor(Qt::black);
        _pen.setStyle(Qt::SolidLine);
        _pen.setCapStyle(Qt::FlatCap);
        _pen.setJoinStyle(Qt::BevelJoin);
    }

    void _Setup_Brush() {
        System::Logging(__FUNCTION__);
        _brush.setColor(Qt::yellow);
        _brush.setStyle(Qt::SolidPattern);
    }

    void _Use_Painter() {
        System::Logging(__FUNCTION__);
        _painter.setRenderHint(QPainter::Antialiasing);
        _painter.setRenderHint(QPainter::TextAntialiasing);
        _painter.setPen(_pen);
        _painter.setBrush(_brush);
    }

public:
    void _Draw_Path() {
        System::Logging(__FUNCTION__);
        _painter.begin(this);
        _Use_Painter();

//        /* drawArc() */
//        _from = 45 * 16;                        // The startAngle and spanAngle must be specified in 1/16th of a degree,
//        _span = 90 * 16;
//        _painter.drawArc(_rect, _from, _span);

//        /* drawChord() */
//        _from = 45 * 16;
//        _span = 90 * 16;
//        _painter.drawChord(_rect, _from, _span);

//        /* drawConvexPolygon() */
//        QPoint points[] = {
//            QPoint(_width / 4 * 1, _height / 4 * 2),
//            QPoint(_width / 4 * 2, _height / 4 * 3),
//            QPoint(_width / 4 * 3, _height / 4 * 2),
//            QPoint(_width / 4 * 2, _height / 4 * 1)
//        };
//        _painter.drawConvexPolygon(points, sizeof(points) / sizeof(points[0]));

//        /* drawEllipse() */
//        _painter.drawEllipse(_rect);

//        /* drawImage() */
//        QImage image = QImage(":/images/qt.jpg");
//        _painter.drawImage(_rect, image);

//        /* drawLine() */
//        QLine line = QLine(_width / 4, _height / 4, _width / 2, _height / 2);
//        _painter.drawLine(line);

//        /* drawLines() */
//        QVector<QLine> lines = {
//            QLine(_rect.topLeft(), _rect.bottomRight()),
//            QLine(_rect.bottomRight(), _rect.bottomLeft()),
//            QLine(_rect.bottomLeft(), _rect.topRight())
//        };
//        _painter.drawLines(lines);

//        /* drawPath() */
//        QPainterPath path;
//        path.addRect(_rect);
//        path.addEllipse(_rect);
//        _painter.drawPath(path);

//        /* drawPie() */
//        _from = 40 * 16;
//        _span = 120 * 16;
//        _painter.drawPie(_rect, _from, _span);

//        /* drawPixmap */
//        QPixmap pixmap = QPixmap(":/images/qt.jpg");
//        _painter.drawPixmap(_rect, pixmap);

//        /* drawPoint() */
//        QPoint point = QPoint(_width / 2, _height / 2);
//        _painter.drawPoint(point);

//        /* drawPoints() */
//        QPoint points[] = {
//            QPoint(_width / 4 * 2, _height / 4 * 2),
//            QPoint(_width / 4 * 3, _height / 4 * 2),
//            QPoint(_width / 4 * 1, _height / 4 * 1)
//        };
//        _painter.drawPoints(points, sizeof(points) / sizeof(points[0]));

//        /* drawPolygon() */
//        QPoint points[] = {
//            QPoint(5 * _width / 12, _height / 4),
//            QPoint(3 * _width / 4, 5 * _height / 12),
//            QPoint(5 * _width / 12, 3 * _height / 4),
//            QPoint(2 * _width / 4, 5 * _height / 12)
//        };
//        _painter.drawPolygon(points, sizeof(points) / sizeof(points[0]));

//        /* drawPolyline() */
//        QPoint points[] = {
//            QPoint(5 * _width / 12, _height / 4),
//            QPoint(3 * _width / 4, 5 * _height / 12),
//            QPoint(5 * _width / 12, 3 * _height / 4),
//            QPoint(2 * _width / 4, 5 * _height / 12)
//        };
//        _painter.drawPolyline(points, sizeof(points) / sizeof(points[0]));

//        /* drawRect() */
//        _painter.drawRect(_rect);

//        /* drawRoundedRect() */
//        iptr x_radius = _width / 20;
//        iptr y_radius = _height / 20;
//        _painter.drawRoundedRect(_rect, x_radius, y_radius);

//        /* drawText() */
//        QFont font = QFont();
//        font.setPointSize(30);
//        font.setBold(true);
//        _painter.setFont(font);
//        _painter.drawText(_rect, "Hello, Qt!");

//        /* eraseRect() */
//        QRect rect = QRect(_width / 4, _height / 4, _width / 8, _height / 8);
//        _painter.eraseRect(rect);

//        /* fillPath() */
//        QPainterPath fill_path = QPainterPath();
//        fill_path.addRect(_rect);
//        fill_path.addEllipse(_rect);
//        _painter.fillPath(fill_path, Qt::yellow);

//        /* fillRect() */
//        _painter.fillRect(_rect, Qt::green);

        _painter.end();
    }

    void _Draw_Texture() {
        System::Logging(__FUNCTION__);
        _painter.begin(this);
        _Use_Painter();
        _brush.setTexture(QPixmap(":/images/texture_plank.jpg"));
        _painter.drawRect(_rect);
        _painter.end();
    }

    void _Draw_Gradient() {
        System::Logging(__FUNCTION__);
        _painter.begin(this);
        _Use_Painter();

//        QLinearGradient linear = QLinearGradient(_rect.left(), _rect.top(), _rect.right(), _rect.bottom());
//        linear.setColorAt(0.0, Qt::blue);
//        linear.setColorAt(0.618, Qt::green);
//        linear.setColorAt(1.0, Qt::red);
//        linear.setSpread(QGradient::ReflectSpread);
//        _painter.setBrush(linear);

        QRadialGradient radial = QRadialGradient(_width / 2, _height / 2, qMax(_width / 8, _height / 8), _width / 2, _height / 2);
        radial.setColorAt(0.0, Qt::white);
        radial.setColorAt(1.0, Qt::green);
        radial.setSpread(QGradient::ReflectSpread);
        _painter.setBrush(radial);

//        QConicalGradient conical = QConicalGradient(_width / 2, _height / 2, 45);
//        conical.setColorAt(0.0, Qt::green);
//        conical.setColorAt(1.0, Qt::blue);
//        conical.setSpread(QGradient::ReflectSpread);
//        _painter.setBrush(conical);

        _painter.drawRect(this->rect());
        _painter.end();
    }

    void _Draw_Pentastar() {
        System::Logging(__FUNCTION__);
        QPainter painter = QPainter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);

        QFont font = QFont();
        font.setPointSize(12);
        font.setBold(true);
        painter.setFont(font);

        QPen pen = QPen();
        pen.setWidth(2);
        pen.setColor(Qt::blue);
        pen.setStyle(Qt::SolidLine);
        pen.setCapStyle(Qt::FlatCap);
        pen.setJoinStyle(Qt::BevelJoin);
        painter.setPen(pen);

        QBrush brush = QBrush();
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);

        qreal radius = 100.0;
        qreal degree = (M_PI / 180.0) * (360.0 / 5.0);
        QPoint points[5] = {
            QPoint(radius * qCos(0 * degree), radius * qSin(0 * degree)),
            QPoint(radius * qCos(1 * degree), radius * qSin(1 * degree)),
            QPoint(radius * qCos(2 * degree), radius * qSin(2 * degree)),
            QPoint(radius * qCos(3 * degree), radius * qSin(3 * degree)),
            QPoint(radius * qCos(4 * degree), radius * qSin(4 * degree))
        };

        QPainterPath path = QPainterPath();
        path.moveTo(points[0]);
        path.lineTo(points[2]);
        path.lineTo(points[4]);
        path.lineTo(points[1]);
        path.lineTo(points[3]);
        path.closeSubpath();
        path.addText(points[0], font, "0");
        path.addText(points[1], font, "1");
        path.addText(points[2], font, "2");
        path.addText(points[3], font, "3");
        path.addText(points[4], font, "4");

        painter.save();
        painter.translate(100, 120);
        painter.drawPath(path);
        painter.drawText(0, 0, "S1");
        painter.restore();

        painter.save();
        painter.translate(300, 120);
        painter.scale(0.8, 0.8);
        painter.rotate(90);
        painter.drawPath(path);
        painter.drawText(0, 0, "S2");
        painter.restore();

        painter.resetTransform();
        painter.translate(500, 120);
        painter.rotate(270);
        painter.drawPath(path);
        painter.drawText(0, 0, "S3");
    }

public:
    void paintEvent(QPaintEvent *event) override {
        (void) event;

        // _Draw_Path();
        // _Draw_Texture();
        _Draw_Gradient();
        // _Draw_Pentastar();
    }
};

#endif // Painter_h
