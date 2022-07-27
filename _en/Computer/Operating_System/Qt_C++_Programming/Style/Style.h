/* Style.h
Author: BSS9395
Update: 2022-07-27T19:38:00+08@China-Shanghai+08
Design: Style
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Style_h
#define Style_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Style.h"

class Style : public QMainWindow {
    Q_OBJECT

public:
    Ui::Style *_ui = nullptr;

public:
    explicit Style(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Style) {
        _ui->setupUi(this);

        _ui->CB_ComboBox->addItems(QStyleFactory::keys());

        QObject::connect(_ui->CB_ComboBox, &QComboBox::currentTextChanged, this, [this](QString text) -> void {
            System::Logging("QObject::connect(_ui->CB_ComboBox, &QComboBox::currentTextChanged, this, [this](QString text) -> void {");

            QStyle *style = QStyleFactory::create(text);
            ((QApplication *)QCoreApplication::instance())->setStyle(style);
            _ui->SB_Status->showMessage(style->metaObject()->className());
        });
    }

    virtual ~Style() {
        Delete(_ui);
    }
};

#endif // Style_h
