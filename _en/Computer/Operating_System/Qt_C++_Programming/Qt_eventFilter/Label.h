#pragma once
#include <QDebug>
#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

class Label: public QLabel {
    Q_OBJECT

public:
    explicit Label(QWidget *parent)
        : QLabel(parent) {
        QString style = R"!(
        [objectName = "this"] {
            background-color: red;
        }
        )!";
        this->setObjectName("this");
        this->setStyleSheet(style);
    }

public:
    void mousePressEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        event->accept();
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        event->accept();
    }

    bool event(QEvent *event) override {
        if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
            qDebug() << __FUNCTION__ << event << event->isAccepted();
        }
        return QLabel::event(event);
    }
};

class Main: public QMainWindow {
    Q_OBJECT

public:
    Label *_label = nullptr;

public:
    explicit Main() {
        _label = new Label(this);
        _label->installEventFilter(this);
    }

public:
    void closeEvent(QCloseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        event->ignore();  // 阻止窗口被关闭
    }

    bool eventFilter(QObject *watched, QEvent *event) override {
        if(watched == _label) {
            if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
                qDebug() << __FUNCTION__ << event << event->isAccepted();
                // event->ignore();
                return false;
            }
        }
        return false;
    }
};
