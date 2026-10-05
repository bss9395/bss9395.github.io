#pragma once

#include <QWidget>
#include <QWindow>
#include <QStyleOption>
#include <QPainter>
#include <QBitmap>

class Widget: public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr) {
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
        this->setFixedWidth(400);
        this->setFixedHeight(400);
    }

    void paintEvent(QPaintEvent* event) {
        // QStyleOption option;
        // option.initFrom(this);
        // QPainter paint(this);
        // this->style()->drawPrimitive(QStyle::PE_Widget, &option, &paint, this);

        QBitmap bitmap(this->size());
        bitmap.fill();
        QPainter painter(&bitmap);
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::black);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawRoundedRect(bitmap.rect(), 20, 20);
        this->setMask(bitmap);

        this->setStyleSheet("background-color: green;");
        QWidget::paintEvent(event);
    }
};
