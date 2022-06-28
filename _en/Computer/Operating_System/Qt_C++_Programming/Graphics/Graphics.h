/* Graphics.h
Author: BSS9395
Update: 2022-06-28T23:53:00+08@China-Shanghai+08
Design: Graphics
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Graphics_h
#define Graphics_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "ui_Graphics.h"
#include "QGraphicsView_Handler.h"

class Graphics : public QMainWindow {
    Q_OBJECT

public:
    Ui::Graphics *_ui = nullptr;
    QLabel _view_pos = QLabel("_view_pos");
    QLabel _scene_pos = QLabel("_scene_pos");
    QLabel _item_pos = QLabel("_item_pos");
    QLabel _info = QLabel("_info");

public:
    explicit Graphics(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Graphics) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _Setup();

        ////////////////////////////////

        QObject::connect(_ui->A_Retangle, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Retangle, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Attach_Rectangle();
        });

        QObject::connect(_ui->A_Circle, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Circle, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Attach_Circle();
        });

        QObject::connect(_ui->A_Triangle, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Triangle, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Attach_Triangle();
        });

        QObject::connect(_ui->A_Line, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Line, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Attach_Line();
        });

        QObject::connect(_ui->A_Text, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Text, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Attach_Text();
        });

        QObject::connect(_ui->A_Trapezoid, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Trapezoid, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Attach_Trapezoid();
        });

        QObject::connect(_ui->A_Ellipse, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Ellipse, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Attach_Ellipse();
        });

        QObject::connect(_ui->A_Zoom_In, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Zoom_In, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Zoom_In();
        });

        QObject::connect(_ui->A_Zoom_Out, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Zoom_Out, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Zoom_Out();
        });

        QObject::connect(_ui->A_Rotate_Posi, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Rotate_Posi, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Rotate_Posi();
        });

        QObject::connect(_ui->A_Rotate_Nega, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Rotate_Nega, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Rotate_Nega();
        });

        QObject::connect(_ui->A_Restore, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Restore, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Restore();
        });

        QObject::connect(_ui->A_Z_Out, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Z_Out, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Z_Out();
        });

        QObject::connect(_ui->A_Z_In, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Z_In, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Z_In();
        });

        QObject::connect(_ui->A_Group, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Group, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Group();
        });

        QObject::connect(_ui->A_Break, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Break, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Break();
        });

        QObject::connect(_ui->A_Delete, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Delete, &QAction::triggered, this, [this]() -> void {");

            _ui->GV_Graphics->_Delete();
        });

        ////////////////////////////////

        QObject::connect(_ui->GV_Graphics, &QGraphicsView_Handler::_Info, this, [this](QPoint view_pos, QPointF scene_pos, QPointF *item_pos, QString *info) -> void {
            // System::Logging("QObject::connect(_ui->GV_Graphics, &QGraphicsView_Handler::_Info, this, [this](QPoint view_pos, QPointF scene_pos, QPointF *item_pos, QString *info) -> void {");

            _view_pos.setText(QString::asprintf("View[%3td, %3td]", (iptr)view_pos.x(), (iptr)view_pos.y()));
            _scene_pos.setText(QString::asprintf("Scene[%+06.1f, %+06.1f]", scene_pos.x(), scene_pos.y()));
            if(item_pos != nullptr) {
                _item_pos.setText(QString::asprintf("Item[%+06.1f, %+06.1f]", item_pos->x(), item_pos->y()));
                delete item_pos;
            } else {
                _item_pos.setText("");
            }
            if(info != nullptr) {
                _info.setText(*info);
                delete info;
            } else {
                _info.setText("");
            }
        });
    }

    virtual ~Graphics() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void _Setup() {
        System::Logging(__FUNCTION__);

        QFont font = QFont("Consolas");
        _view_pos.setFont(font);
        _scene_pos.setFont(font);
        _item_pos.setFont(font);
        _ui->SB_Status->addWidget(&_view_pos);
        _ui->SB_Status->addWidget(&_scene_pos);
        _ui->SB_Status->addWidget(&_item_pos);
        _ui->SB_Status->addWidget(&_info);

        qsrand(QTime::currentTime().second());
    }
};

#endif // Graphics_h
