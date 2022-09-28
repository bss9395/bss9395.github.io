/* Multi_Language.h
Author: BSS9395
Update: 2022-07-27T12:16:00+08@China-Shanghai+08
Design: Multi_Language
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef   Multi_Language_h
#define   Multi_Language_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "Widget_Pen.h"
#include "ui_Multi_Language.h"

class Multi_Language : public QMainWindow {
    Q_OBJECT

public:
    struct : public Enume {
        Enume _Organization = Enume(this, "BSS9395", "BSS9395");
        Enume _Application = Enume(this, "Application", "Application");
        Enume _Language = Enume(this, "Language", "Language");
        Enume _CN = Enume(this, "CN", "E:/Downloads/QtProjects/Projects/Multi_Language/Multi_Language_han.qm");
        Enume _EN = Enume(this, "EN", "E:/Downloads/QtProjects/Projects/Multi_Language/Multi_Language_english.qm");
    } _Settings;

public:
    Ui::Multi_Language *_ui = nullptr;
    Widget_Pen _widget_pen = Widget_Pen();
    QTranslator *_translator = new QTranslator();

public:
    explicit Multi_Language(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Multi_Language) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _Setup();

        QObject::connect(_ui->A_Setup_Pen, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Setup_Pen, &QAction::triggered, this, [this]() -> void {");

            _widget_pen.exec();
        });

        QObject::connect(_ui->A_Chinese, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Chinese, &QAction::triggered, this, [this]() -> void {");

            QCoreApplication::instance()->removeTranslator(_translator);
            Delete(_translator);

            _translator = new QTranslator();
            _translator->load(_Settings._CN._alias);
            QCoreApplication::instance()->installTranslator(_translator);
            _ui->retranslateUi(this);
            _widget_pen._ui->retranslateUi(&_widget_pen);

            QSettings settings = QSettings(_Settings._Organization._field, _Settings._Application._field);
            settings.setValue(_Settings._Language._field, _Settings._CN._field);
        });

        QObject::connect(_ui->A_English, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_English, &QAction::triggered, this, [this]() -> void {");

            QCoreApplication::instance()->removeTranslator(_translator);
            Delete(_translator);

            _translator = new QTranslator();
            _translator->load(_Settings._EN._alias);
            QCoreApplication::instance()->installTranslator(_translator);
            _ui->retranslateUi(this);
            _widget_pen._ui->retranslateUi(this);

            QSettings settings = QSettings(_Settings._Organization._field, _Settings._Application._field);
            settings.setValue(_Settings._Language._field, _Settings._EN._field);
        });
    }

    virtual ~Multi_Language() {
        System::Logging(__FUNCTION__);
        Delete(_ui);
    }

    void _Setup() {
        System::Logging(__FUNCTION__);

        QSettings settings = QSettings(_Settings._Organization._field, _Settings._Application._field);
        QString language = settings.value(_Settings._Language._field, _Settings._CN._field).toString();
        _translator->load(_Settings._Alias(language));
        QCoreApplication::instance()->installTranslator(_translator);
        _ui->retranslateUi(this);
        _widget_pen._ui->retranslateUi(&_widget_pen);
    }

public:
    virtual void paintEvent(QPaintEvent *event) override {
        // System::Logging("virtual void paintEvent(QPaintEvent *event) override {");

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

#endif // Multi_Language_h
