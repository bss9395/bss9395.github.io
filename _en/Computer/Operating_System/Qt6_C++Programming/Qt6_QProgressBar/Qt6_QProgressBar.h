/* Qt6_QProgressBar.h
Author: BSS9395
Update: 2023-08-30T15:43:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QPROGRESSBAR_H
#define QT6_QPROGRESSBAR_H

#include <QWidget>
#include "ui_Qt6_QProgressBar.h"

class Qt_QProgressBar : public QWidget {
    Q_OBJECT

private:
    Ui::Qt_QProgressBar *_ui = nullptr;

public:
    explicit Qt_QProgressBar(QWidget *parent = nullptr)
        : QWidget(parent), _ui(new Ui::Qt_QProgressBar) {
        _ui->setupUi(this);

        QObject::connect(_ui->D_Dial, &QDial::valueChanged, this, &Qt_QProgressBar::_Value_Changed);
        QObject::connect(_ui->S_Slider, &QSlider::valueChanged, this, &Qt_QProgressBar::_Value_Changed);
        QObject::connect(_ui->SB_Scroll, &QScrollBar::valueChanged, this, &Qt_QProgressBar::_Value_Changed);

        QObject::connect(_ui->CB_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {
            _ui->PB_Progress->setTextVisible(checked);
        });

        QObject::connect(_ui->CB_Inverted, &QCheckBox::clicked, this, [this](bool checked) -> void{
            _ui->PB_Progress->setInvertedAppearance(checked);
        });

        QObject::connect(_ui->RB_Percent, &QRadioButton::clicked, this, [this](bool checked) -> void{
            _ui->PB_Progress->setFormat("%p%");
        });

        QObject::connect(_ui->RB_Value, &QRadioButton::clicked, this, [this](bool checked) -> void{
            _ui->PB_Progress->setFormat("%v");
        });
    }

    ~Qt_QProgressBar() {
        delete _ui;
    }

public slots:
    void _Value_Changed(int value) {
        _ui->PB_Progress->setValue(value);
    }
};

#endif // QT6_QPROGRESSBAR_H
