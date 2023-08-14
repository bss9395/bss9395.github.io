/* Qt_Icons.h
Author: BSS9395
Update: 2023-08-13T10:23:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT_ICONS_H
#define QT_ICONS_H

#include <QMainWindow>
#include "ui_Qt_Icons.h"

class Qt_Icons : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Qt_Icons *_ui = nullptr;

public:
    Qt_Icons(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt_Icons) {
        _ui->setupUi(this);

        QObject::connect(_ui->PB_Ok, &QPushButton::clicked, this, [this]() -> void {
            this->close();
        });
    }

    ~Qt_Icons() {
        delete _ui;
    }
};
#endif // QT_ICONS_H
