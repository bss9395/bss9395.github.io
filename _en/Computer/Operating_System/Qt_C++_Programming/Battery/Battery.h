/* Battery.h
Author: BSS9395
Update: 2022-07-22T01:23:00+08@China-Shanghai+08
Design: Battery
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef   Battery_h
#define   Battery_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Battery.h"

class Battery : public QWidget {
    Q_OBJECT

public:
    class Battery_Handler : public QWidget {
    public:
        Battery *_battery = nullptr;
        QPen _pen = QPen();
        QBrush _brush = QBrush();
        QColor _color_border = QColor(0, 0, 0, 255);
        QColor _color_cap = QColor(0, 0, 0, 255);
        QColor _color_background = QColor(255, 255, 255, 255);
        QColor _color_power = QColor(0, 255, 0, 255);
        QColor _color_warn = QColor(255, 0, 0, 255);
        iptr _warn = 15;
        Property<iptr> _power = Property<iptr>(0, [this]() -> void {
            System::Logging("Property<iptr> _power = Property<iptr>(60, [this]() -> void {");

            this->update();
            _battery->_ui->L_Slider->setText(QString::asprintf("%3td%%", (iptr)(this->_power)));
        });

    public:
        explicit Battery_Handler(Battery *parent)
            : QWidget(parent), _battery(parent) {
            System::Logging(__FUNCTION__);

            _Setup();
        }

        virtual ~Battery_Handler() {
            System::Logging(__FUNCTION__);
        }

        void _Setup() {
            System::Logging(__FUNCTION__);

            _pen.setWidth(2);
            _pen.setColor(Qt::black);
            _pen.setStyle(Qt::SolidLine);
            _pen.setCapStyle(Qt::FlatCap);     // Qt::SquareCap | Qt::FlatCap   | Qt::RoundCap
            _pen.setJoinStyle(Qt::MiterJoin);  // Qt::BevelJoin | Qt::MiterJoin | Qt::RoundJoin

            _brush.setColor(Qt::white);
            _brush.setStyle(Qt::SolidPattern);
        }

    public:
        virtual void paintEvent(QPaintEvent *event) override {
            System::Logging(__FUNCTION__);

            System::Logging("[width, height] == [%d, %d]", this->width(), this->height());

            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setRenderHint(QPainter::TextAntialiasing);
            iptr width = 800;
            iptr height = 500;
            Area window = Area(0, 0, width, height);
            painter.setViewport(Area::_Viewport(this->width(), this->height(), 1.0 * height / width));  // note: physical coordiante.
            painter.setWindow((QRect)window);                                            // note: logical coordinate.

            _pen.setWidth(10);
            _pen.setColor(_color_border);
            _brush.setColor(_color_background);
            painter.setPen(_pen);
            painter.setBrush(_brush);
            painter.drawRect(window._YZ_Rect(5, 5, width * (11.0 / 12.0), height - 5));

            _pen.setWidth(10);
            _pen.setColor(_color_border);
            _brush.setColor(_color_cap);
            painter.setPen(_pen);
            painter.setBrush(_brush);
            painter.drawRect(window._YZ_Rect(width * (11.0 / 12.0), height * (1.0 / 3.0), width - 5, height * (2.0 / 3.0)));

            if(0 < _power) {
                _pen.setWidth(0);
                if(_warn <= _power) {
                    _pen.setColor(_color_power);
                    _brush.setColor(_color_power);
                } else {
                    _pen.setColor(_color_warn);
                    _brush.setColor(_color_warn);
                }
                painter.setPen(_pen);
                painter.setBrush(_brush);
                painter.drawRect(window._YZ_Rect(10, 10, 10 + (width * (11.0 / 12.0) - 15) * (_power / 100.0), height - 10));
            }

            QString text = QString::asprintf("%td%%", (iptr)_power);
            double prop = 2.0 * width / this->width();
            QRect bound = Area::_Proption(QFontMetrics(this->font()).boundingRect(text), prop);
            _pen.setColor(_color_border);
            _brush.setColor(_color_border);
            painter.setPen(_pen);
            painter.setBrush(_brush);
            QFont font = this->font();
            font.setPointSize(font.pointSize() * prop);
            painter.setFont(font);
            painter.drawText(window._YZ_Point((width - (bound.width() + bound.x())) / 2, (height - (bound.height() + bound.y())) / 2), text);

            QWidget::paintEvent(event);
        }
    };

public:
    Ui::Battery *_ui = new Ui::Battery();
    Battery_Handler *_handler = new Battery_Handler(this);  // note: C++17 supports keyword new at the level of member variables.

public:
    explicit Battery(QWidget *parent = nullptr)
        : QWidget(parent) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _ui->F_Handler->layout()->addWidget(_handler);

        QObject::connect(_ui->S_Slider, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Slider, &QSlider::valueChanged, this, [this](int value) -> void {");

            _handler->_power = value;
        });
        _ui->S_Slider->setTracking(true);
        _ui->S_Slider->setRange(0, 100);
        _ui->S_Slider->setSingleStep(1);
        _ui->S_Slider->setValue(80);
    }

    virtual ~Battery() {
        System::Logging(__FUNCTION__);
        Delete(_ui);
    }
};
#endif // Battery_h
