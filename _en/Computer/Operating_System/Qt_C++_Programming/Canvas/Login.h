/* Login.h
Author: BSS9395
Update: 2022-02-12T02:12:00+08@China-Guangdong-Shenzhen+08
Design: Canvas
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Logging_h
#define Logging_h

#define Header_h
#include "Common.h"
#include "ui_Login.h"
#include "System.h"
#include "Setting.h"

class Login : public QDialog {
    Q_OBJECT

public:
    Ui::Login *_ui = nullptr;
    QPixmap _background = QPixmap(":/images/wallpapers/windows_10.png");
    bool _moving = false;
    iptr _start_drag_distance = QApplication::startDragDistance(); // note: unnecessary.
    QPoint _relative = QPoint();

public:
    QCryptographicHash _crypto = QCryptographicHash(Setting::_Crypto);
    QSettings _setting = QSettings(Setting::_Organization, Setting::_Software);
    QString _username = QString();
    QString _password = QString();
    bool _username_checked = false;
    bool _password_checked = false;
    bool _sign_in_checked = false;

public:
    explicit Login(QWidget *parent = nullptr)
        : QDialog(parent), _ui(new Ui::Login) {
        _ui->setupUi(this);
        System::Logging(__FUNCTION__);
        this->setAttribute(Qt::WA_DeleteOnClose);
        // this->setWindowFlag(Qt::SplashScreen);      // note: do not appear on taskbar.
        this->setWindowFlag(Qt::FramelessWindowHint);  // note: appear on taskbar.

        ////////////////////////////////

        _username = _setting.value("_Username", Setting::_Username).toString();
        _password = _setting.value("_Password", Encrypt(Setting::_Password)).toString();
        _username_checked = _setting.value("_Username_Checked", false).toBool();
        _password_checked = _setting.value("_Password_Checked", false).toBool();
        _sign_in_checked = _setting.value("_Sign_In_Checked", false).toBool();
        if (_username_checked == true) {
            _ui->CB_Username->setCurrentText(_username);
            _ui->CB_Username_Checked->setChecked(true);
        }
        if(_password_checked == true) {
            _ui->CB_Password->setCurrentText(_password);
            _ui->CB_Password_Checked->setChecked(true);
        }
        if(_sign_in_checked == true) {
            _ui->CB_Sign_In_Checked->setChecked(true);
        }

        ////////////////////////////////

        QObject::connect(_ui->CB_Username_Checked, &QCheckBox::stateChanged, [this](int state) -> void {
            System::Logging("QObject::connect(_ui->CB_Username_Checked, &QCheckBox::stateChanged, [this](int state) -> void {");

            if(state == Qt::Unchecked) {
                _ui->CB_Password_Checked->setChecked(false);
            }
        });

        QObject::connect(_ui->CB_Password_Checked, &QCheckBox::stateChanged, [this](int state) -> void {
            System::Logging("QObject::connect(_ui->CB_Password_Checked, &QCheckBox::stateChanged, [this](int state) -> void {");

            if(state == Qt::Checked) {
                _ui->CB_Username_Checked->setChecked(true);
            } else if(state == Qt::Unchecked) {
                _ui->CB_Sign_In_Checked->setChecked(false);
            }
        });

        QObject::connect(_ui->CB_Sign_In_Checked, &QCheckBox::stateChanged, [this](int state) -> void {
            System::Logging("QObject::connect(_ui->CB_Sign_In_Checked, &QCheckBox::stateChanged, [this](int state) -> void {");

            if(state == Qt::Checked) {
                _ui->CB_Password_Checked->setChecked(true);
            }
        });

        QObject::connect(_ui->PB_Sign_Up, &QPushButton::clicked, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Sign_Up, &QPushButton::clicked, [this]() -> void {");

            (void) this;
            Exception::Excepting(true, System::_Info, QString("unimplemented functionality."), QString(""));
        });

        QObject::connect(_ui->PB_Sign_In, &QPushButton::clicked, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Sign_In, &QPushButton::clicked, [this]() -> void {");

            QString username = _ui->CB_Username->currentText().trimmed();
            QString password = _ui->CB_Password->currentText().trimmed();
            if(_username == username) {
                QString encrypted = Encrypt(password);
                if(_password == encrypted) {
                    this->accept();
                    return ;        // note: don't forget to return;
                }
            }
            this->reject();
        });

        QObject::connect(_ui->PB_Retrieve, &QPushButton::clicked, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Retrieve, &QPushButton::clicked, [this]() -> void {");

            (void) this;
            Exception::Excepting(true, System::_Info, QString("unimplemented functionality."), QString(""));
        });
    }

    virtual ~Login() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }



public:
    QString Encrypt(const QString &literal) {
        System::Logging(__FUNCTION__);

        _crypto.reset();
        _crypto.addData(QByteArray().append(literal));
        return QString(_crypto.result().toHex());     // note: toHex() to avoid copying null terminated byte from QByteArray into QString.
    }

public:
    virtual bool event(QEvent *event) override {
        // System::Logging(__FUNCTION__);

        if(event->type() == QEvent::Paint) {
            // System::Logging("if(event->type() == QEvent::Paint) {");

            // QPoint point = this->pos();     // note: Login is a top level Widget.
            QPainter painter = QPainter(this); // note: construct painter every time if widget itself changes.
            painter.drawPixmap(0, 0, this->width() + 1, this->height() + 1, _background);
        } else if(_moving == false && event->type() == QEvent::MouseButtonPress && ((QMouseEvent *)event)->button() == Qt::LeftButton) {
            System::Logging("} else if(_moving == false && event->type() == QEvent::MouseButtonPress && ((QMouseEvent *)event)->button() == Qt::LeftButton) {");

            _moving = true;
            _relative = QCursor::pos() - this->pos();
        } else if(_moving == true && event->type() == QEvent::MouseMove  && (((QMouseEvent *)event)->buttons() & Qt::LeftButton)) {
            System::Logging("} else if(_moving == true && event->type() == QEvent::MouseMove && ((QMouseEvent *)event)->button() == Qt::LeftButton) {");

            this->move(QCursor::pos() - _relative); // note: move to a new absolute position in glabal screen.
        } else if(_moving == true && event->type() == QEvent::MouseButtonRelease && ((QMouseEvent *)event)->button() == Qt::LeftButton) {
            System::Logging("} else if(_moving == true && event->type() == QEvent::MouseButtonRelease && ((QMouseEvent *)event)->button() == Qt::LeftButton) {");

            _moving = false;
        }
        return QWidget::event(event);
    }
};

#endif // Logging_h
