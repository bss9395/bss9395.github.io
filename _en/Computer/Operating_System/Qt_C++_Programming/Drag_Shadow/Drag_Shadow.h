/* Drag_Shadow.h
Author: BSS9395
Update: 2023-09-04T10:56:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef DRAG_SHADOW_H
#define DRAG_SHADOW_H

#include <QMainWindow>
#include "ui_Drag_Shadow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

class Shadow : public QWidget {
    Q_OBJECT

public:
    Shadow(QWidget *parent = nullptr)
        : QWidget(parent) {
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
        this->setAttribute(Qt::WA_TranslucentBackground);

    }

public:
    void _Set_Geometry(int x, int y, int width, int height) {
        this->setGeometry(x, y, width, height);
    }

public:
    void paintEvent(QPaintEvent *event) override {
        int lines = 4;
        QPainter painter(this);
        painter.setBrush(Qt::NoBrush);
        QPen pen;
        pen.setStyle(Qt::SolidLine);
        pen.setColor(Qt::black);
        pen.setWidth(1);
        painter.setPen(pen);

        QColor color;
        for(int line = 0; line < lines; line += 1) {
            for(int col = line; col < this->width() - line; col += 1) {
                color = Qt::black;
                pen.setColor(color);
                painter.setPen(pen);
                painter.drawPoint(col, line);  // note: top

                color = Qt::black;
                pen.setColor(color);
                painter.setPen(pen);
                painter.drawPoint(col, this->height() - 1 - line);
            }

            for(int row = line; row < this->height() - line; row += 1) {
                color = Qt::black;
                pen.setColor(color);
                painter.setPen(pen);
                painter.drawPoint(line, row);

                color = Qt::black;
                pen.setColor(color);
                painter.setPen(pen);
                painter.drawPoint(this->width() - 1 - line, row);
            }
        }
    }
};

class Drag_Shadow : public QMainWindow {
    Q_OBJECT

private:
    Ui::Drag_Shadow *_ui = nullptr;
    Shadow _shadow;
    QPoint _point;

public:
    Drag_Shadow(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Drag_Shadow)
        , _shadow(this) {
        _ui->setupUi(this);
        _shadow.hide();

        // this->setMouseTracking(true);
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    }

    ~Drag_Shadow() {
        delete _ui;
    }

public:
    void mousePressEvent(QMouseEvent *event) override {
        qDebug() << "void mousePressEvent(QMouseEvent *event) override {";

        if(event->button() == Qt::LeftButton) {
            _point = event->pos();
            qDebug() << "_point = " << _point;
            _shadow._Set_Geometry(this->x(), this->y(), this->width(), this->height());
            _shadow.show();
        }
        return QMainWindow::mousePressEvent(event);
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        qDebug() << "void mouseMoveEvent(QMouseEvent *event) override {";

        this->move(event->globalPos() - _point);  // note: move to a global position.
        _shadow._Set_Geometry(this->x(), this->y(), this->width(), this->height());

        return QMainWindow::mouseMoveEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        qDebug() << "void mouseReleaseEvent(QMouseEvent *event) override {";

        if(event->button() == Qt::LeftButton) {
            _shadow.hide();
        }
        return QMainWindow::mouseReleaseEvent(event);
    }

};
#endif // DRAG_SHADOW_H
