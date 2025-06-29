#pragma once

#include <QDebug>
#include <QDialog>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QResizeEvent>
#include <QScreen>

class Dialog : public QDialog {
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr)
        : QDialog(parent) {
        // this
        this->setObjectName("this");
        this->setWindowFlag(Qt::FramelessWindowHint, true);
        this->setAttribute(Qt::WA_TranslucentBackground);
        this->setStyleSheet(_qss);

        // _this
        _this = new QWidget(this);
        _this->setObjectName("_this");
        QGraphicsDropShadowEffect* _this_shadowEffect = new QGraphicsDropShadowEffect(_this);
        _this_shadowEffect->setColor(Qt::black);
        _this_shadowEffect->setBlurRadius(20);
        _this_shadowEffect->setOffset(0, 0);
        _this->setGraphicsEffect(_this_shadowEffect);    // 需要_this设置background-color或者paintEvent()

        // _frame
        QWidget* _frame = new QFrame(_this);
        _frame->setObjectName("_frame");
        QVBoxLayout* _frame_layout = new QVBoxLayout(_frame);
        QGraphicsDropShadowEffect* _frame_shadowEffect = new QGraphicsDropShadowEffect(_frame);
        _this_shadowEffect->setColor(Qt::black);
        _this_shadowEffect->setBlurRadius(20);
        _this_shadowEffect->setOffset(0, 0);
        _frame->setGraphicsEffect(_frame_shadowEffect);  // 同一个QGraphicsDropShadowEffect不能共用

        // _frame_button
        QPushButton* _frame_button = new QPushButton(_frame);
        _frame_button->setObjectName("_frame_button");
        _frame_layout->addWidget(_frame_button);
        _frame_button->setText("button");

        // _frame_label
        QLabel* _frame_label = new QLabel(_frame);
        _frame_label->setObjectName("_frame_label");
        _frame_layout->addWidget(_frame_label);
        _frame_label->setText("label");
    }

    virtual ~Dialog() {

    }

public:
    void resizeEvent(QResizeEvent *event) override {
        qDebug().nospace() << __FUNCTION__ << ", event = " << event;
        (void)event;
        this->setMinimumWidth(400);
        this->setMinimumHeight(400);

        _this->setFixedWidth(this->width() - _edge_length - _edge_length);
        _this->setFixedHeight(this->height() - _edge_length - _edge_length);
        _this->move((this->width() - _this->width()) / 2, (this->height() - _this->height()) / 2);

        // 居中对齐在父级顶层控件中央
        QWidget *parentWidget = this->parentWidget();
        QRect toplevelGeometry = (parentWidget == nullptr)? this->screen()->geometry() : parentWidget->topLevelWidget()->frameGeometry();
        this->move(toplevelGeometry.x() + (toplevelGeometry.width() - this->width()) / 2, toplevelGeometry.y() + (toplevelGeometry.height() - this->height()) / 2);
    }

    void paintEvent(QPaintEvent *event) {
        (void)event;
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

//        QBrush brush;
//        brush.setStyle(Qt::BrushStyle::SolidPattern);
//        brush.setColor(Qt::green);
//        painter.setBrush(brush);
//        painter.setPen(QPen(Qt::NoPen));
//        painter.drawRoundedRect(this->rect().adjusted(_edge_length, _edge_length, -_edge_length, -_edge_length), 2, 2);  // QGraphicsDropShadowEffect不会超出窗体边框

        QPen pen;
        pen.setWidth(2);
        pen.setStyle(Qt::PenStyle::SolidLine);
        pen.setColor(QColor("#FFC7CDD5"));
        painter.setBrush(QBrush(Qt::NoBrush));
        painter.setPen(pen);
        painter.drawRect(_this->geometry());  // 绘制边框线，无填充
    }

public:
    QString _qss = R"!(
    [objectName = "_this"] {
        background-color: "#FFFFFFFF";
    }

    )!";
    int _edge_length = 5;
    QWidget* _this = nullptr;
};
