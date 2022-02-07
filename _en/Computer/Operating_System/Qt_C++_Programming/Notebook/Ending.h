/* Ending.h
Author: BSS9395
Update: 2022-02-08T00:24:00+08@China-Guangdong-Zhanjiang+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Ending_h
#define Ending_h

#define Header_h
#include "Common.h"
#include "ui_Ending.h"
#include "System.h"

class Ending : public QDialog {
    Q_OBJECT

public:
    Ui::Ending *_ui = nullptr;

public:
    explicit Ending(QWidget *parent = nullptr, const QString &form = QString("LF"))
        : QDialog(parent), _ui(new Ui::Ending) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        this->setAttribute(Qt::WA_DeleteOnClose);

        if(form == "LF") {
            _ui->RB_Unix->setChecked(true);
        } else if(form == "CRLF") {
            _ui->RB_Windows->setChecked(true);
        } else if(form == "CR") {
            _ui->RB_Mac->setChecked(true);
        }

        ////////////////////////////////

        this->setWindowFlag(Qt::FramelessWindowHint, true);
        this->setWindowFlag(Qt::WindowStaysOnTopHint, true);
        this->resize(_ui->GB_Ending->sizeHint().width(), _ui->GB_Ending->sizeHint().height());

        QPoint pos = (parent == nullptr) ? QCursor::pos() : parent->parentWidget()->mapToGlobal(parent->pos());
        QScreen *screen = QGuiApplication::screenAt(pos);
        if(screen->geometry().width() < pos.x() + this->size().width()) {
            pos.setX(screen->geometry().width() - this->size().width());
        }
        pos.setY(pos.y() - this->size().height());
        this->move(pos);

        ////////////////////////////////

        QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this]() -> void {");
            (void) checked;
            emit Update_Ending("LF");
            this->close();
        });

        QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this]() -> void {");
            (void) checked;
            emit Update_Ending("CRLF");
            this->close();
        });

        QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {");
            (void) checked;
            emit Update_Ending("CR");
            this->close();
        });

        this->show();
    }

    virtual ~Ending() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    virtual bool event(QEvent *event) override {
        // Logging(__FUNCTION__);

        if(event->type() == QEvent::FocusIn || event->type() == QEvent::Leave) {
            System::Logging("if(event->type() == QEvent::FocusIn) {");
            this->grabMouse();
            return true;
        } else if(event->type() == QEvent::Enter) {
            System::Logging("} else if(event->type() == QEvent::Enter) {");
            this->releaseMouse();
            return true;
        } else if(event->type() == QEvent::MouseButtonPress) {
            System::Logging("} else if(event->type() == QEvent::MouseButtonPress) {");
            this->releaseMouse();
            this->close(); // note: mouse button press outside this widget.
            return true;
        }
        return QWidget::event(event);
    }

signals:
    void Update_Ending(QString form);
};

#endif // Ending_h
