/* Widget_Pen.h
Author: BSS9395
Update: 2022-07-24T21:41:00+08@China-Shanghai+08
Design: StaticLib_Pen
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef   Widget_Pen_h
#define   Widget_Pen_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Widget_Pen.h"

class Widget_Pen : public QDialog {
    Q_OBJECT

public:
    struct : public Enume {
        Enume _NoPen          = Enume(this, Qt::NoPen         , "NoPen");
        Enume _SolidLine      = Enume(this, Qt::SolidLine     , "SolidLine");
        Enume _DashLine       = Enume(this, Qt::DashLine      , "DashLine");
        Enume _DotLine        = Enume(this, Qt::DotLine       , "DotLine");
        Enume _DashDotLine    = Enume(this, Qt::DashDotLine   , "DashDotLine");
        Enume _DashDotDotLine = Enume(this, Qt::DashDotDotLine, "DashDotDotLine");
        Enume _CustomDashLine = Enume(this, Qt::CustomDashLine, "CustomDashLine");
        Enume _MPenStyle      = Enume(this, Qt::MPenStyle     , "MPenStyle");
    } _PenStyle;

    struct : public Enume {
        Enume _FlatCap      = Enume(this, Qt::FlatCap     , "FlatCap");
        Enume _SquareCap    = Enume(this, Qt::SquareCap   , "SquareCap");
        Enume _RoundCap     = Enume(this, Qt::RoundCap    , "RoundCap");
        Enume _MPenCapStyle = Enume(this, Qt::MPenCapStyle, "MPenCapStyle");
    } _PenCapStyle;

    struct : public Enume {
        Enume _MiterJoin     = Enume(this, Qt::MiterJoin    , "MiterJoin");
        Enume _BevelJoin     = Enume(this, Qt::BevelJoin    , "BevelJoin");
        Enume _RoundJoin     = Enume(this, Qt::RoundJoin    , "RoundJoin");
        Enume _SvgMiterJoin  = Enume(this, Qt::SvgMiterJoin , "SvgMiterJoin");
        Enume _MPenJoinStyle = Enume(this, Qt::MPenJoinStyle, "MPenJoinStyle");
    } _PenJoinStyle;

public:
    Ui::Widget_Pen *_ui = nullptr;
    Property<QPen> _pen = Property<QPen>(QPen(), [this]() -> void {
        System::Logging("Property<QPen> _pen = Property<QPen>(QPen(), [this]() -> void {");

        _ui->SB_Width->setValue(_pen._value.width());
        _ui->CB_Style->setCurrentIndex(_PenStyle._Index(_pen._value.style()));
        _ui->CB_Cap->setCurrentIndex(_PenCapStyle._Index(_pen._value.capStyle()));
        _ui->CB_Joint->setCurrentIndex(_PenJoinStyle._Index(_pen._value.joinStyle()));
        QPalette palette = _ui->PB_Color->palette();
        palette.setColor(QPalette::Button, _pen._value.color());
        _ui->PB_Color->setPalette(palette);
    }, [this]() -> void {
        System::Logging("}, [this]() -> void {");

        _pen._value.setWidth(_ui->SB_Width->value());
        _pen._value.setStyle((Qt::PenStyle)_PenStyle[_ui->CB_Style->currentIndex()]._enume);
        _pen._value.setCapStyle((Qt::PenCapStyle)_PenCapStyle[_ui->CB_Cap->currentIndex()]._enume);
        _pen._value.setJoinStyle((Qt::PenJoinStyle)_PenJoinStyle[_ui->CB_Joint->currentIndex()]._enume);
        _pen._value.setColor(_ui->PB_Color->palette().color(QPalette::Button));
    });

public:
    explicit Widget_Pen(QWidget *parent = nullptr)
        : QDialog(parent), _ui(new Ui::Widget_Pen) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _Setup();

        QObject::connect(_ui->PB_Accept, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Accept, &QPushButton::clicked, this, [this]() -> void {");

            (QPen)_pen;
            this->hide();
        });
        QObject::connect(_ui->PB_Reject, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Reject, &QPushButton::clicked, this, [this]() -> void {");

            this->hide();
        });
    }

    virtual ~Widget_Pen() {
        System::Logging(__FUNCTION__);
        Delete(_ui);
    }

    void _Setup() {
        System::Logging(__FUNCTION__);
        this->hide();

        _ui->SB_Width->setRange(0, 100);
        _ui->SB_Width->setSingleStep(1);
        _ui->SB_Width->setValue(1);
        _ui->CB_Style->clear();
        _ui->CB_Style->addItems(_PenStyle._Aliases());
        _ui->CB_Cap->clear();
        _ui->CB_Cap->addItems(_PenCapStyle._Aliases());
        _ui->CB_Joint->clear();
        _ui->CB_Joint->addItems(_PenJoinStyle._Aliases());

        _ui->PB_Color->setFlat(true);
        _ui->PB_Color->setAutoFillBackground(true);
        QObject::connect(_ui->PB_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Color, &QPushButton::clicked, this, [this]() -> void {");

            QString title = "选择颜色";
            QPalette palette = _ui->PB_Color->palette();
            QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, title);
            if(color.isValid() == true) {
                palette.setColor(QPalette::Button, color);
                _ui->PB_Color->setPalette(palette);
            }
        });

        QPen pen = QPen();
        pen.setWidth(1);
        pen.setStyle((Qt::PenStyle)_PenStyle._SolidLine._enume);
        pen.setCapStyle((Qt::PenCapStyle)_PenCapStyle._FlatCap._enume);
        pen.setJoinStyle((Qt::PenJoinStyle)_PenJoinStyle._MiterJoin._enume);
        pen.setColor(Qt::black);
        _pen = pen;
    }
};

#endif // Widget_Pen_h
