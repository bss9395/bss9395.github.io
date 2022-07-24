/* StaticLib_Use.h
Author: BSS9395
Update: 2022-07-24T21:41:00+08@China-Shanghai+08
Design: StaticLib_Use
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef   StaticLib_Use_h
#define   StaticLib_Use_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "Widget_Pen.h"
#include "ui_StaticLib_Use.h"

class StaticLib_Use : public QMainWindow {
    Q_OBJECT

public:
    Ui::StaticLib_Use *_ui = nullptr;
    Widget_Pen _widget_pen = Widget_Pen();

public:
    explicit StaticLib_Use(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::StaticLib_Use) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        QObject::connect(_ui->A_Setup_Pen, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Setup_Pen, &QAction::triggered, this, [this]() -> void {");

            _widget_pen.exec();
        });
    }

    virtual ~StaticLib_Use() {
        System::Logging(__FUNCTION__);
        Delete(_ui);
    }

public:
    virtual void paintEvent(QPaintEvent *event) override {
        System::Logging("virtual void paintEvent(QPaintEvent *event) override {");

        (void) event;
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::TextAntialiasing);
        iptr width = 800;
        iptr height = 500;
        Area window = Area(0, 0, width, height);
        painter.setViewport(Area::_Viewport(0, _ui->TB_Main->height(), this->width(), this->height(), 1.0 * height / width));  // note: physical coordiante.
        painter.setWindow((QRect)window);                                                                                      // note: logical coordinate.

        painter.setPen(_widget_pen._pen._value);
        painter.drawRect(window._YZ_Rect(0, 50, 800, 500, _widget_pen._pen._value.width()));
    }
};

#endif // StaticLib_Use_h
