/* Qt6_QPainter.h
Author: BSS9395
Update: 2023-09-05T15:47:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QPAINTER_H
#define QT6_QPAINTER_H

#include <QWidget>
#include "ui_Qt6_QPainter.h"
#include <QPainter>
#include <QPainterPath>

class Qt6_QPainter : public QWidget {
    Q_OBJECT

private:
    Ui::Qt6_QPainter *_ui = nullptr;

public:
    Qt6_QPainter(QWidget *parent = nullptr)
        : QWidget(parent), _ui(new Ui::Qt6_QPainter) {
        _ui->setupUi(this);

        this->setPalette(QPalette(Qt::white));//设置窗口为白色背景
        // setAutoFillBackground(true);
        this->resize(400,300);
    }

    ~Qt6_QPainter() {
        delete _ui;
    }

public:
    void paintEvent(QPaintEvent *event) override {
        // _Draw_Rect();
        // _Draw_Gradient();

        // _Draw_Wire();
        _Draw_Composite();
    }

public:
    void _Draw_Rect() {
        int width = this->width();
        int height = this->height();
        QRect rect = QRect(width / 4, height / 4, width / 2, height / 2);

        QPoint points[9]={
            QPoint(5 * width / 12, height / 4),
            QPoint(7 * width / 12, height / 4),
            QPoint(3 * width / 4, 5 * height / 12),
            QPoint(3 * width / 4, 7 * height / 12),
            QPoint(7 * width / 12, 3 * height / 4),
            QPoint(5 * width / 12, 3 * height / 4),
            QPoint(width / 4, 7 * height / 12),
            QPoint(width / 4, 5 * height / 12),
            QPoint(5 * width / 12, height / 4)
        };

        QPainterPath path;
        path.moveTo(points[0]);
        path.lineTo(points[2]);
        path.lineTo(points[4]);
        path.lineTo(points[1]);
        path.lineTo(points[3]);
        path.closeSubpath();


        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);

        QPen pen;
        pen.setWidth(3);
        pen.setColor(QColor(255, 0, 0));
        pen.setStyle(Qt::SolidLine);       // NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine, CustomDashLine
        pen.setCapStyle(Qt::FlatCap);      // FlatCap, SquareCap, RoundCap, MPenCapStyle
        pen.setJoinStyle(Qt::BevelJoin);   // MiterJoin, BevelJoin, RoundJoin, SvgMiterJoin, MPenJoinStyle
        painter.setPen(pen);


        QPixmap pixmap(":/images/texture.jpg");
        QBrush brush;
        brush.setColor(QColor(255, 255, 0));
        brush.setStyle(Qt::SolidPattern);  // NoBrush, SolidPattern, Dense1Pattern, Dense2Pattern, Dense3Pattern, Dense4Pattern, Dense5Pattern, Dense6Pattern, Dense7Pattern, HorPattern, VerPattern, CrossPattern, BDiagPattern, FDiagPattern, DiagCrossPattern, LinearGradientPattern, RadialGradientPattern, ConicalGradientPattern, TexturePattern
        // brush.setStyle(Qt::TexturePattern); brush.setTexture(pixmap);
        painter.setBrush(brush);

        // painter.drawLine(rect.left(), rect.top(), rect.right(), rect.bottom());
        painter.drawRect(rect);
        // painter.drawRoundedRect(rect, 40, 20);
        // painter.drawEllipse(rect);
        // painter.drawPolyline(points, 9);
        // painter.drawPolygon(points, 9);
        // painter.drawPath(path);
        // painter.drawArc(rect, 30 * 16, 80 * 16);
        // painter.drawChord(rect, 90 * 16, 120 * 16);
        // painter.drawPie(rect, 90 * 16, 120 * 16);
        // painter.drawText(rect, "Hello, Qt!");
        painter.drawImage(rect, QImage(":/images/qt.jpg"));
    }

    void _Draw_Gradient() {
        int width = this->width();
        int height = this->height();
        QRect rect = QRect(width / 4, height / 4, width / 2, height / 2);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);

        painter.setPen(QPen(Qt::NoPen));

        QLinearGradient linear = QLinearGradient(rect.left(), rect.top(), rect.right(), rect.bottom());
        linear.setColorAt(0, Qt::blue);
        linear.setColorAt(0.5, Qt::white);
        linear.setColorAt(1, Qt::blue);
        linear.setSpread(QGradient::PadSpread);  // PadSpread, ReflectSpread, RepeatSpread
        painter.setBrush(linear);
        painter.drawRect(rect);


//        QRadialGradient radial = QRadialGradient(width / 2, height / 2, width / 4, width / 2, height / 2);
//        radial.setColorAt(0, Qt::yellow);
//        radial.setColorAt(0.8, Qt::blue);
//        radial.setSpread(QGradient::PadSpread);  // PadSpread, ReflectSpread, RepeatSpread
//        painter.setBrush(radial);
//        painter.drawRect(rect);


//        QConicalGradient conical = QConicalGradient(width / 2, height / 2, 45);
//        conical.setColorAt(0, Qt::blue);
//        conical.setColorAt(1, Qt::white);
//        conical.setSpread(QGradient::PadSpread);  // PadSpread, ReflectSpread, RepeatSpread
//        painter.setBrush(conical);
//        painter.drawRect(rect);
    }

    void _Draw_Wire() {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);

        int width = this->width();
        int height = this->height();
        int side = qMin(width, height);
        QRect rect = QRect((width - side) / 2, (height - side) / 2, side, side);
        painter.drawRect(rect);     // note: viewport==window
        painter.setViewport(rect);
        painter.setWindow(-100, -100, 200, 200);

        QPen pen;
        pen.setWidth(1);
        pen.setColor(Qt::red);
        pen.setStyle(Qt::SolidLine);
        pen.setCapStyle(Qt::FlatCap);
        pen.setJoinStyle(Qt::BevelJoin);
        painter.setPen(pen);

        for(int i = 0; i < 36; i += 1) {
            painter.drawEllipse(QPoint(50, 0), 50, 50);
            painter.rotate(10);
        }
    }

    void _Draw_Composite() {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);

        int width = this->width();
        int height = this->height();
        int side = qMin(width, height);
        QRect rect = QRect((width - side) / 2, (height - side) / 2, side, side);
        painter.drawRect(rect);
        painter.setViewport(rect);
        painter.setWindow(-100, -100, 200, 200);

        QPen pen;
        pen.setWidth(1);
        pen.setColor(Qt::red);
        pen.setStyle(Qt::SolidLine);
        pen.setCapStyle(Qt::FlatCap);
        pen.setJoinStyle(Qt::BevelJoin);
        painter.setPen(pen);

        QLinearGradient linear = QLinearGradient(0, 0, 100, 0);
        linear.setColorAt(0, Qt::yellow);
        linear.setColorAt(1, Qt::green);
        linear.setSpread(QGradient::PadSpread);
        painter.setBrush(linear);

        painter.setCompositionMode(QPainter::CompositionMode_Difference);
        for(int i = 0; i < 36; i += 1) {
            painter.drawEllipse(QPoint(50, 0), 50, 50);
            painter.rotate(10);
        }
    }
};
#endif // QT6_QPAINTER_H
