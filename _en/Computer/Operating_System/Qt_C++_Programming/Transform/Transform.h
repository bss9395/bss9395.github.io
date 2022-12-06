/* Transform.h
Author: BSS9395
Update: 2022-12-06T22:22:00+08@China-Shanghai+08
Design: Transform
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Transform_h
#define Transform_h

#define Header_h
#include "Common.h"
#include "ui_Transform.h"
#include "System.h"

class Transform : public QMainWindow {
    Q_OBJECT

public:
    Ui::Transform *_ui = nullptr;

public:
    explicit Transform(QWidget *parent = nullptr)
        : QMainWindow(parent)
        , _ui(new Ui::Transform) {
        System::Logging(__FUNCTION__);

        _ui->setupUi(this);
        _ui->TB_Tool->addWidget(_ui->W_Tool);

        QObject::connect(_ui->W_Canvas, &Canvas::_Bounding, this, [this](QRect bounding) -> void {
            System::Logging("QObject::connect(_ui->W_Canvas, &Canvas::_Bounding, this, [this](QRect bounding) -> void {");

            _Block_Signals(_ui->W_Tool, true);
            _ui->DSB_X_0->setValue(bounding.x());
            _ui->DSB_Y_0->setValue(bounding.y());
            _ui->DSB_Width->setValue(bounding.width());
            _ui->DSB_Height->setValue(bounding.height());
            _Block_Signals(_ui->W_Tool, false);
        });

        QObject::connect(_ui->W_Canvas, &Canvas::_Center, this, [this](QPoint center) -> void {
            System::Logging("QObject::connect(_ui->W_Canvas, &Canvas::_Center, this, [this](QPoint center) -> void {");

            _Block_Signals(_ui->W_Tool, true);
            _ui->DSB_X->setValue(center.x());
            _ui->DSB_Y->setValue(center.y());
            _ui->DSB_Rotation->setValue(0.0);
            _Block_Signals(_ui->W_Tool, false);
        });

        QObject::connect(_ui->DSB_Rotation, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double value) -> void {
            System::Logging("QObject::connect(_ui->DSB_Rotation, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double value) -> void {");

            _ui->W_Canvas->_Rotate(value);
        });
    }

    virtual ~Transform() {
        System::Logging(__FUNCTION__);
        delete _ui;
        _ui = nullptr;
    }

public:
    void _Block_Signals(QObject *object, bool blocked) {
        System::Logging(__FUNCTION__);

        if(object == _ui->W_Tool) {
            _ui->W_Tool->blockSignals(blocked);
            _ui->DSB_X_0->blockSignals(blocked);
            _ui->DSB_Y_0->blockSignals(blocked);
            _ui->DSB_Width->blockSignals(blocked);
            _ui->DSB_Height->blockSignals(blocked);
            _ui->DSB_X->blockSignals(blocked);
            _ui->DSB_Y->blockSignals(blocked);
            _ui->DSB_Rotation->blockSignals(blocked);
        }
    }
};

#endif // Transform_h
