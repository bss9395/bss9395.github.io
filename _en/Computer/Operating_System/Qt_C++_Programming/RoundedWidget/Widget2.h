#pragma once

#include <QWidget>
#include <QPainter>

class Widget: public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr) {
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
        this->setAttribute(Qt::WA_TranslucentBackground);
        this->setFixedWidth(400);
        this->setFixedHeight(400);
    }

    void paintEvent(QPaintEvent* event) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QBrush(QColor(255, 0, 0, 127)));
        painter.setPen(Qt::transparent);
        QRect rect = this->rect();
        rect.setWidth(rect.width() - 1);
        rect.setHeight(rect.height() - 1);
        painter.drawRoundedRect(rect, 20, 20);
        QWidget::paintEvent(event);
    }
};
