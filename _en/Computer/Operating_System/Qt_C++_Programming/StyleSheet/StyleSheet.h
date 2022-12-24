/* StyleSheet.h
Author: BSS9395
Update: 2022-12-23T17:51:00+08@China-Shanghai+08
Design: StyleSheet
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef StyleSheet_h
#define StyleSheet_h

#define   Header_h
#include "Common.h"
#include "ui_StyleSheet.h"
#include "System.h"

class StyleSheet : public QMainWindow {
    Q_OBJECT

public:
    Ui::StyleSheet *_ui = nullptr;
    int _count = 0;

public:
    Q_PROPERTY(QString border_color READ _Get_Border_Color WRITE _Set_Border_Color)
    QString _border_color = QString();

    QString _Get_Border_Color() {
        System::Logging(__FUNCTION__);

        return _border_color;
    }

    void _Set_Border_Color(const QString &border_color) {
        System::Logging(__FUNCTION__);

        _border_color = border_color;
    }

public:
    Q_PROPERTY(double _opacity READ _Get_Opacity WRITE _Set_Opacity)
    double _opacity = 1.0;

    double _Get_Opacity() {
        System::Logging(__FUNCTION__);

        return _opacity;
    }

    void _Set_Opacity(double opacity) {
        System::Logging(__FUNCTION__);
        qDebug() << opacity;

        _opacity = opacity;
        _effect.setOpacity(_opacity);
    }

    QGraphicsOpacityEffect _effect = QGraphicsOpacityEffect();
    QPropertyAnimation _animation = QPropertyAnimation(this, "_opacity");

public:
    explicit StyleSheet(QWidget *parent = nullptr)
        : QMainWindow(parent)
        , _ui(new Ui::StyleSheet) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _ui->PB_SetProperty->setGraphicsEffect(&_effect);
        // _ui->PB_Property->setGraphicsEffect(&_effect);  // note: QGraphicsOpacityEffect applys on one widget.
//        _animation.setStartValue(1.0);
//        _animation.setEndValue(0.0);
//        _animation.setDuration(5000);
//        _animation.setLoopCount(-1);
//        _animation.start();
        _animation.setKeyValueAt(0.0, 1.0);
        _animation.setKeyValueAt(0.5, 0.0);
        _animation.setKeyValueAt(1.0, 1.0);
        _animation.setDuration(5000);
        _animation.setLoopCount(-1);
        _animation.start();



        QFile file(":/Style.qss");
        file.open(QIODevice::ReadOnly);
        this->setStyleSheet(file.readAll());

        QObject::connect(_ui->PB_SetProperty, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(ui->PB_SetProperty, &QPushButton::clicked, this, [this]() -> void {");

            if(_count % 3 == 0) {
                this->setProperty("border_color", "red");
            } else if(_count % 3 == 1) {
                this->setProperty("border_color", "green");
            } else if(_count % 3 == 2) {
                this->setProperty("border_color", "blue");
            }
            this->style()->polish(_ui->PB_SetProperty);
            _ui->PB_SetProperty->update();

            _count += 1;
        });

        QObject::connect(_ui->PB_Property, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(ui->PB_Property, &QPushButton::clicked, this, [this]() -> void {");

            if(_count % 3 == 0) {
                _Set_Border_Color("red");
            } else if(_count % 3 == 1) {
                _Set_Border_Color("green");
            } else if(_count % 3 == 2) {
                _Set_Border_Color("blue");
            }
            this->style()->polish(_ui->PB_Property);
            _ui->PB_Property->update();

            _count += 1;
        });
    }

    virtual ~StyleSheet() {
        System::Logging(__FUNCTION__);
        delete _ui;
        _ui = nullptr;
    }
};

#endif // StyleSheet_h
