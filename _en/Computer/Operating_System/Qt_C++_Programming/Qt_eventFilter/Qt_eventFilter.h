/* Qt_eventFilter.h
Author: bss9395
Update: 2025/10/19T20:19:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#pragma once
#include <QDebug>
#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

/* Qt事件流程
步骤零：事件拦截。bool eventFilter(QObject *watched, QEvent *event) ? [return false]步骤一                 | [return true]步骤三
步骤一：事件分发。bool event(QEvent *event)                         ? [return QLabel::event(event)]步骤二  | []步骤四
步骤二：事件处理。void mousePressEvent(QMouseEvent *event)          ? [event->ignore()]步骤三              | [event->accept()]步骤四
步骤三：事件传播。Event Propagates to Parent Widget.
步骤四：事件终止。Event Ends.
*/


class Background: public QLabel {
    Q_OBJECT

public:
    explicit Background(QWidget *parent)
        : QLabel(parent) {
        QString style = R"!(
        [objectName = "this"] {
            background-color: "red";
        }
        )!";
        this->setObjectName("this");
        this->setStyleSheet(style);
    }

    // 事件分发
    bool event(QEvent *event) override {
        if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
            qDebug() << __FUNCTION__ << event << event->isAccepted();
        }
        return QLabel::event(event);
        // return false;
    }

    void mousePressEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        // event->accept();
        event->ignore();
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        // event->accept();
        event->ignore();
    }
};


class Label0: public QLabel {
    Q_OBJECT

public:
    explicit Label0(QWidget *parent)
        : QLabel(parent) {
        QString style = R"!(
        [objectName = "this"] {
            background-color: "green";
        }
        )!";
        this->setObjectName("this");
        this->setStyleSheet(style);
    }

    // 事件分发
    bool event(QEvent *event) override {
        if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
            qDebug() << __FUNCTION__ << event << event->isAccepted();
        }
        return QLabel::event(event);
    }

    void mousePressEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        // event->accept();
        event->ignore();
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        // event->accept();
        event->ignore();
    }
};

class Label1: public QLabel {
    Q_OBJECT

public:
    explicit Label1(QWidget *parent)
        : QLabel(parent) {
        QString style = R"!(
        [objectName = "this"] {
            background-color: "blue";
        }
        )!";
        this->setObjectName("this");
        this->setStyleSheet(style);
    }

    // 事件分发
    bool event(QEvent *event) override {
        if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
            qDebug() << __FUNCTION__ << event << event->isAccepted();
        }
        return QLabel::event(event);
    }

    void mousePressEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        // event->accept();
        event->ignore();
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        // event->accept();
        event->ignore();
    }
};

class Main: public QMainWindow {
    Q_OBJECT

public:
    Background *_background = nullptr;
    Label0 *_label0 = nullptr;
    Label1 *_label1 = nullptr;

    explicit Main() {
        _background = new Background(this);
        _background->installEventFilter(this);
        _label0 = new Label0(_background);
        _label0->installEventFilter(this);
        _label1 = new Label1(_background);
        _label1->installEventFilter(this);

        this->resize(300, 300);
        _background->resize(200, 200);
        _label0->resize(100, 100);
        _label1->resize(100, 100);
        _label1->move(50, 50);
    }

    void closeEvent(QCloseEvent *event) override {
        qDebug() << __FUNCTION__ << event << event->isAccepted();
        // event->ignore();  // 阻止窗体被关闭
        event->accept();
    }

    // 事件拦截
    bool eventFilter(QObject *watched, QEvent *event) override {
        if(watched == _label0) {
            if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
                qDebug() << __FUNCTION__ << event << event->isAccepted();
                // event->ignore();
                // event->accept();
                return true;
            }
        } else if(watched == _label1) {
            if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
                qDebug() << __FUNCTION__ << event << event->isAccepted();
                // event->ignore();
                // event->accept();
                return true;
            }
        } else if(watched == _background) {
            if(event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave) {
                qDebug() << __FUNCTION__ << event << event->isAccepted();
                // event->ignore();
                // event->accept();
                return true;
            }
        }
        return false;
    }
};
