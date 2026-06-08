#pragma once
#include <QDebug>
#include <QLabel>
#include <QSlider>
#include <QWidget>
#include <QColor>

class ERGB: public QWidget {
    Q_OBJECT

public:
    QLabel*  _l_far    = new QLabel(this);
    QLabel*  _l_far_A  = new QLabel(this);
    QLabel*  _l_far_R  = new QLabel(this);
    QLabel*  _l_far_G  = new QLabel(this);
    QLabel*  _l_far_B  = new QLabel(this);
    QLabel*  _l_near   = new QLabel(this);
    QLabel*  _l_near_E = new QLabel(this);
    QLabel*  _l_near_R = new QLabel(this);
    QLabel*  _l_near_G = new QLabel(this);
    QLabel*  _l_near_B = new QLabel(this);
    QLabel*  _l_ARGB   = new QLabel(this);
    QLabel*  _l_ERGB   = new QLabel(this);
    QSlider* _s_far_A  = new QSlider(Qt::Horizontal, this);
    QSlider* _s_far_R  = new QSlider(Qt::Horizontal, this);
    QSlider* _s_far_G  = new QSlider(Qt::Horizontal, this);
    QSlider* _s_far_B  = new QSlider(Qt::Horizontal, this);
    QSlider* _s_near_E = new QSlider(Qt::Horizontal, this);
    QSlider* _s_near_R = new QSlider(Qt::Horizontal, this);
    QSlider* _s_near_G = new QSlider(Qt::Horizontal, this);
    QSlider* _s_near_B = new QSlider(Qt::Horizontal, this);
    QWidget* _w_far    = new QWidget(this);
    QWidget* _w_near   = new QWidget(this);
    QWidget* _w_ARGB   = new QWidget(this);
    QWidget* _w_ERGB   = new QWidget(this);
    QColor _far_color  = QColor("#00000000");
    QColor _near_color = QColor("#00000000");

public:
    explicit ERGB(QWidget* parent = nullptr)
        : QWidget(parent) {
        qDebug().noquote() << __FUNCTION__;

        QString style_this = R"!(
background-color: #FF000000; font-family: Consolas; font-size: 12px; color: #FFFFFFFF;
        )!";

        QString style_slider_E = R"!(
QSlider::groove   { height: 8px; background-color: #00000000;              }
QSlider::sub-page { height: 6px; background-color: #FF808080;              }
QSlider::handle   { width : 8px; height: 8px; background-color: #FF673AB7; }
QSlider::add-page { height: 6px; background-color: #FFFFFFFF;              }
    )!";

        QString style_slider_R = R"!(
QSlider::groove   { height: 8px; background-color: #00000000;              }
QSlider::sub-page { height: 6px; background-color: #FFFF0000;              }
QSlider::handle   { width : 8px; height: 8px; background-color: #FF673AB7; }
QSlider::add-page { height: 6px; background-color: #FFFFFFFF;              }
    )!";

        QString style_slider_G = R"!(
QSlider::groove   { height: 8px; background-color: #00000000;              }
QSlider::sub-page { height: 6px; background-color: #FF00FF00;              }
QSlider::handle   { width : 8px; height: 8px; background-color: #FF673AB7; }
QSlider::add-page { height: 6px; background-color: #FFFFFFFF;              }
    )!";

        QString style_slider_B = R"!(
QSlider::groove   { height: 8px; background-color: #00000000;              }
QSlider::sub-page { height: 6px; background-color: #FF0000FF;              }
QSlider::handle   { width : 8px; height: 8px; background-color: #FF673AB7; }
QSlider::add-page { height: 6px; background-color: #FFFFFFFF;              }
    )!";

        this->setWindowTitle("ERGB色彩");
        this->setStyleSheet(style_this);
        _s_far_A->setStyleSheet(style_slider_E);
        _s_far_R->setStyleSheet(style_slider_R);
        _s_far_G->setStyleSheet(style_slider_G);
        _s_far_B->setStyleSheet(style_slider_B);
        _s_near_E->setStyleSheet(style_slider_E);
        _s_near_R->setStyleSheet(style_slider_R);
        _s_near_G->setStyleSheet(style_slider_G);
        _s_near_B->setStyleSheet(style_slider_B);

        ////////////////////////////////////////////////////////////////////////

        this->resize(850, 300);
        _l_far->setFixedSize(250, 20);
        _l_far_A->setFixedSize(50, 20);
        _l_far_R->setFixedSize(50, 20);
        _l_far_G->setFixedSize(50, 20);
        _l_far_B->setFixedSize(50, 20);
        _l_near->setFixedSize(250, 20);
        _l_near_E->setFixedSize(50, 20);
        _l_near_R->setFixedSize(50, 20);
        _l_near_G->setFixedSize(50, 20);
        _l_near_B->setFixedSize(50, 20);
        _l_ARGB->setFixedSize(400, 45);
        _l_ERGB->setFixedSize(350, 45);
        _s_far_A->setFixedSize(255, 20);
        _s_far_R->setFixedSize(255, 20);
        _s_far_G->setFixedSize(255, 20);
        _s_far_B->setFixedSize(255, 20);
        _s_near_E->setFixedSize(255, 20);
        _s_near_R->setFixedSize(255, 20);
        _s_near_G->setFixedSize(255, 20);
        _s_near_B->setFixedSize(255, 20);
        _w_far->setFixedSize(80, 80);
        _w_near->setFixedSize(80, 80);
        _w_ARGB->setFixedSize(80, 80);
        _w_ERGB->setFixedSize(80, 80);

        _l_far->move(QPoint(0, 0));
        _l_far_A->move(_l_far->geometry().bottomLeft());
        _l_far_R->move(_l_far_A->geometry().bottomLeft());
        _l_far_G->move(_l_far_R->geometry().bottomLeft());
        _l_far_B->move(_l_far_G->geometry().bottomLeft());
        _l_near->move(_l_far_B->geometry().bottomLeft() + QPoint(0, 10));
        _l_near_E->move(_l_near->geometry().bottomLeft());
        _l_near_R->move(_l_near_E->geometry().bottomLeft());
        _l_near_G->move(_l_near_R->geometry().bottomLeft());
        _l_near_B->move(_l_near_G->geometry().bottomLeft());
        _s_far_A->move(_l_far_A->geometry().topRight());
        _s_far_R->move(_l_far_R->geometry().topRight());
        _s_far_G->move(_l_far_G->geometry().topRight());
        _s_far_B->move(_l_far_B->geometry().topRight());
        _s_near_E->move(_l_near_E->geometry().topRight());
        _s_near_R->move(_l_near_R->geometry().topRight());
        _s_near_G->move(_l_near_G->geometry().topRight());
        _s_near_B->move(_l_near_B->geometry().topRight());
        _w_far->move(_s_far_A->geometry().topRight() + QPoint(10, 0));
        _w_near->move(_s_near_E->geometry().topRight() + QPoint(10, 0));
        _w_ARGB->move((_w_far->geometry().topRight() + _w_near->geometry().topRight()) / 2 + QPoint(10, 0));
        _w_ERGB->move(_w_ARGB->geometry().topRight() + QPoint(10, 0));
        _l_ARGB->move(_w_ARGB->geometry().topLeft() - QPoint(0, 4 + _l_ARGB->height()));
        _l_ERGB->move(_w_ERGB->geometry().bottomLeft() + QPoint(0, 4));

        ////////////////////////////////////////////////////////////////////////

        _l_ARGB->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        _l_ARGB->setText(R"!(ARGB色彩融合公式：
A_merged =          A_near +         A_far * (1.0 - A_near);
C_merged = C_near * A_near + C_far * A_far * (1.0 - A_near);
    )!");

        _l_ERGB->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        _l_ERGB->setText(R"!(ERGB色彩融合公式：
E_merged = 1.0    * E_near + E_far * (1.0 - E_near);
C_merged = C_near * E_near + C_far * (1.0 - E_near);
    )!");

        _s_far_A->setRange(0, 255);
        QObject::connect(_s_far_A, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_far_A->setValue(value);
            _l_far_A->setText(QString("A: %1").arg(value, 3, 10, QChar('0')));
            _Far_Change();
        });
        emit _s_far_A->valueChanged(127);

        _s_far_R->setRange(0, 255);
        QObject::connect(_s_far_R, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_far_R->setValue(value);
            _l_far_R->setText(QString("R: %1").arg(value, 3, 10, QChar('0')));
            _Far_Change();
        });
        emit _s_far_R->valueChanged(127);

        _s_far_G->setRange(0, 255);
        QObject::connect(_s_far_G, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_far_G->setValue(value);
            _l_far_G->setText(QString("G: %1").arg(value, 3, 10, QChar('0')));
            _Far_Change();
        });
        emit _s_far_G->valueChanged(127);

        _s_far_B->setRange(0, 255);
        QObject::connect(_s_far_B, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_far_B->setValue(value);
            _l_far_B->setText(QString("B: %1").arg(value, 3, 10, QChar('0')));
            _Far_Change();
        });
        emit _s_far_B->valueChanged(127);

        _s_near_E->setRange(0, 255);
        QObject::connect(_s_near_E, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_near_E->setValue(value);
            _l_near_E->setText(QString("E: %1").arg(value, 3, 10, QChar('0')));
            _Near_Change();
        });
        emit _s_near_E->valueChanged(127);

        _s_near_R->setRange(0, 255);
        QObject::connect(_s_near_R, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_near_R->setValue(value);
            _l_near_R->setText(QString("R: %1").arg(value, 3, 10, QChar('0')));
            _Near_Change();
        });
        emit _s_near_R->valueChanged(127);

        _s_near_G->setRange(0, 255);
        QObject::connect(_s_near_G, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_near_G->setValue(value);
            _l_near_G->setText(QString("G: %1").arg(value, 3, 10, QChar('0')));
            _Near_Change();
        });
        emit _s_near_G->valueChanged(127);

        _s_near_B->setRange(0, 255);
        QObject::connect(_s_near_B, &QSlider::valueChanged, this, [this](int value) -> void {
            _s_near_B->setValue(value);
            _l_near_B->setText(QString("B: %1").arg(value, 3, 10, QChar('0')));
            _Near_Change();
        });
        emit _s_near_B->valueChanged(127);
    }

    virtual ~ERGB() {
        qDebug().noquote() << __FUNCTION__;
    }

public:
    void _Far_Change() {
        double snapE = 1.0 * _s_far_A->value() / (_s_far_A->maximum() - _s_far_A->minimum());
        double snapR = 1.0 * _s_far_R->value() / (_s_far_R->maximum() - _s_far_R->minimum());
        double snapG = 1.0 * _s_far_G->value() / (_s_far_G->maximum() - _s_far_G->minimum());
        double snapB = 1.0 * _s_far_B->value() / (_s_far_B->maximum() - _s_far_B->minimum());
        _far_color = _Color_Linearize(QColor("#00000000"), QColor("#FFFFFFFF"), snapE, snapR, snapG, snapB);
        _w_far->setStyleSheet(QString("border-width: 1px; border-style: solid; border-color: white; background-color: %1").arg(_far_color.name(QColor::HexRgb)));
        _l_far->setText(QString("Far : [%1, %2, %3, %4]").arg(_far_color.alphaF(), 6, 'f', 4, QChar(' ')).arg(_far_color.redF(), 6, 'f', 4, QChar(' ')).arg(_far_color.greenF(), 6, 'f', 4, QChar(' ')).arg(_far_color.blueF(), 6, 'f', 4, QChar(' ')));
        _Color_Merge();
    }

    void _Near_Change() {
        double snapE = 1.0 * _s_near_E->value() / (_s_near_E->maximum() - _s_near_E->minimum());
        double snapR = 1.0 * _s_near_R->value() / (_s_near_R->maximum() - _s_near_R->minimum());
        double snapG = 1.0 * _s_near_G->value() / (_s_near_G->maximum() - _s_near_G->minimum());
        double snapB = 1.0 * _s_near_B->value() / (_s_near_B->maximum() - _s_near_B->minimum());
        _near_color = _Color_Linearize(QColor("#00000000"), QColor("#FFFFFFFF"), snapE, snapR, snapG, snapB);
        _w_near->setStyleSheet(QString("border-width: 1px; border-style: solid; border-color: white; background-color: %1").arg(_near_color.name(QColor::HexRgb)));
        _l_near->setText(QString("Near: [%1, %2, %3, %4]").arg(_near_color.alphaF(), 6, 'f', 4, QChar(' ')).arg(_near_color.redF(), 6, 'f', 4, QChar(' ')).arg(_near_color.greenF(), 6, 'f', 4, QChar(' ')).arg(_near_color.blueF(), 6, 'f', 4, QChar(' ')));
        _Color_Merge();
    }

    void _Color_Merge() {
        QColor argb_merged = _ARGB_Merge(_near_color, _far_color);
        _w_ARGB->setStyleSheet(QString("border-width: 1px; border-style: solid; border-color: white; background-color: %1").arg(argb_merged.name(QColor::HexRgb)));
        QColor ergb_merged = _ERGB_Merge(_near_color, _far_color);
        _w_ERGB->setStyleSheet(QString("border-width: 1px; border-style: solid; border-color: white; background-color: %1").arg(ergb_merged.name(QColor::HexRgb)));
    }

    QColor _Color_Linearize(QColor lower, QColor upper, double snapE, double snapR, double snapG, double snapB) {
        double energy = lower.alphaF() + snapE * (upper.alphaF() - lower.alphaF());
        double red    = lower.redF()   + snapR * (upper.redF() - lower.redF());
        double green  = lower.greenF() + snapG * (upper.greenF() - lower.greenF());
        double blue   = lower.blueF()  + snapB * (upper.blueF() - lower.blueF());
        return QColor::fromRgbF(red, green, blue, energy);
    }

    QColor _ARGB_Merge(QColor near, QColor far) {
        // ARGB色彩融合公式：
        // A_merged =          A_near +         A_far * (1.0 - A_near);
        // C_merged = C_near * A_near + C_far * A_far * (1.0 - A_near);
        double alpha =                 near.alphaF() +                far.alphaF() * (1.0 - near.alphaF());
        double red   = near.redF()   * near.alphaF() + far.redF()   * far.alphaF() * (1.0 - near.alphaF());
        double green = near.greenF() * near.alphaF() + far.greenF() * far.alphaF() * (1.0 - near.alphaF());
        double blue  = near.blueF()  * near.alphaF() + far.blueF()  * far.alphaF() * (1.0 - near.alphaF());
        return QColor::fromRgbF(red, green, blue, alpha);
    }

    QColor _ERGB_Merge(QColor near, QColor far) {
        // ERGB色彩融合公式：
        // E_merged = 1.0    * E_near + E_far * (1.0 - E_near);
        // C_merged = C_near * E_near + C_far * (1.0 - E_near);
        double energy = 1.0           * near.alphaF() + far.alphaF() * (1.0 - near.alphaF());
        double red    = near.redF()   * near.alphaF() + far.redF()   * (1.0 - near.alphaF());
        double green  = near.greenF() * near.alphaF() + far.greenF() * (1.0 - near.alphaF());
        double blue   = near.blueF()  * near.alphaF() + far.blueF()  * (1.0 - near.alphaF());
        return QColor::fromRgbF(red, green, blue, energy);
    }
};
