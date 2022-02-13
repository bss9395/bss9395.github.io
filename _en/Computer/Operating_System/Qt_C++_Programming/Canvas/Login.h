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
#include "Custom.h"

class Login : public QDialog {
    Q_OBJECT

public:
    struct Datum {
        static inline const QString _Username = "_Username";
        static inline const QString _Encrypted = "_Encrypted";
        static inline const QString _Username_Checked = "_Username_Checked";
        static inline const QString _Password_Checked = "_Password_Checked";
        static inline const QString _Automate_Checked = "_Automate_Checked";

        QString _username = QString();
        QString _encrypted = QString();
        bool _username_checked = false;
        bool _password_checked = false;
        bool _automate_checked = false;
    };

public:
    iptr *_result = nullptr;
    Ui::Login *_ui = nullptr;
    QPixmap _background = QPixmap(":/images/wallpapers/windows_10.png");
    bool _moving = false;
    QPoint _relative = QPoint();

public:
    QCryptographicHash _crypto = QCryptographicHash(Setting::_Crypto);
    QSettings _setting = QSettings(Setting::_Organization, Setting::_Software);
    iptr _tried = Setting::_Tried;
    Datum datum = Datum();
    bool _reading = false;

public:
    explicit Login(QWidget *parent, iptr *result)
        : QDialog(parent), _ui(new Ui::Login) {
        _ui->setupUi(this);
        System::Logging(__FUNCTION__);

        _result = result;
        this->setAttribute(Qt::WA_DeleteOnClose);   // note: either use exec() or Qt::WA_DeleteOnClose.
        // this->setWindowFlag(Qt::SplashScreen);      // note: do not appear on taskbar.
        this->setWindowFlag(Qt::FramelessWindowHint);  // note: appear on taskbar.
        this->setWindowTitle(QString("Login"));
        _ui->CB_Username->lineEdit()->setPlaceholderText(QString("账号"));
        _ui->CB_Password->lineEdit()->setPlaceholderText(QString("密码"));
        // _ui->CB_Password->lineEdit()->setEchoMode(QLineEdit::Password);  // note: password editing mode.

        ////////////////////////////////

        QObject::connect(_ui->CB_Username, &ComboBox::Focus_In_Changed, [this]() -> void {
            System::Logging("QObject::connect(_ui->CB_Username, &ComboBox::Focus_In_Changed, [this]() -> void {");

            _ui->TB_Username->setStyleSheet(Style::_Username_Editing);
        });

        QObject::connect(_ui->CB_Username, &QComboBox::editTextChanged, [this]() -> void {
            System::Logging("QObject::connect(_ui->CB_Username, &QComboBox::editTextChanged, [this]() -> void {");

            if(_reading == false) {
                datum._password_checked = false;
            }
        });

        QObject::connect(_ui->CB_Username, &ComboBox::Focus_Out_Changed, [this]() -> void {
            System::Logging("QObject::connect(_ui->CB_Username, &ComboBox::Focus_Out_Changed, [this]() -> void {");

            _ui->TB_Username->setStyleSheet(Style::_Username_Edited);
        });

        QObject::connect(_ui->CB_Password, &ComboBox::Focus_In_Changed, [this]() -> void {
            System::Logging("QObject::connect(_ui->CB_Password, &ComboBox::Focus_In_Changed, [this]() -> void {");

            _ui->TB_Password->setStyleSheet(Style::_Password_Editing);
        });

        QObject::connect(_ui->CB_Password, &QComboBox::editTextChanged, [this]() -> void {
            System::Logging("QObject::connect(_ui->CB_Password, &QComboBox::editTextChanged, [this]() -> void {");

            if(_reading == false) {
                datum._password_checked = false;
            }
        });

        QObject::connect(_ui->CB_Username, &ComboBox::Focus_Out_Changed, [this]() -> void {
            System::Logging("QObject::connect(_ui->CB_Username, &ComboBox::Focus_Out_Changed, [this]() -> void {");

            _ui->TB_Password->setStyleSheet(Style::_Password_Edited);
        });

        QObject::connect(_ui->CB_Username_Checked, &QCheckBox::clicked, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Username_Checked, &QCheckBox::clicked, [this](bool checked) -> void {");

            if(checked == false) {
                _ui->CB_Password_Checked->setChecked(false);
                _ui->CB_Automate_Checked->setChecked(false);
            }
        });

        QObject::connect(_ui->CB_Password_Checked, &QCheckBox::clicked, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Password_Checked, &QCheckBox::clicked, [this](bool checked) -> void {");

            if(checked == true) {
                _ui->CB_Username_Checked->setChecked(true);
            } else if(checked == false) {
                _ui->CB_Automate_Checked->setChecked(false);
            }
        });

        QObject::connect(_ui->CB_Automate_Checked, &QCheckBox::clicked, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Automate_Checked, &QCheckBox::clicked, [this](bool checked) -> void {");

            if(checked == true) {
                _ui->CB_Username_Checked->setChecked(true);
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

            Sign_In();
        });

        QObject::connect(_ui->PB_Retrieve, &QPushButton::clicked, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Retrieve, &QPushButton::clicked, [this]() -> void {");

            (void) this;
            Exception::Excepting(true, System::_Info, QString("unimplemented functionality."), QString(""));
        });

        ////////////////////////////////

        (*_result) = 1;
        this->close();
        return ;
        // this->accept();
//        System::Logging("this->accept();");
//        return ;

//        Read_Info();
//        if(datum._automate_checked == true) {
//            Sign_In();
//        }
    }

    void Sign_In() {
        System::Logging("QObject::connect(_ui->PB_Sign_In, &QPushButton::clicked, [this]() -> void {");

        // Save_Info();
        if(Setting::_Username == datum._username) {
            if(Encrypt(Setting::_Password) == datum._encrypted) {
                (*_result) = QDialog::Accepted;
                this->accept();
                System::Logging("this->accept();");
                return ;        // note: don't forget to return;
            } else {
                _ui->TB_Password->setStyleSheet(Style::_Password_Edit);
            }
        } else {
            _ui->TB_Username->setStyleSheet(Style::_Username_Edit);
        }
        _tried -= 1;
        _ui->CB_Password->lineEdit()->setPlaceholderText(QString("剩余%1次试错机会").arg(_tried));
        if(_tried <= 0) {
            (*_result) = QDialog::Rejected;
            this->reject();
            return ;
        }
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

    iptr Read_Info() {
        System::Logging(__FUNCTION__);
        _reading = true;

        datum._username = _setting.value(Datum::_Username, QString("")).toString();
        datum._encrypted = _setting.value(Datum::_Encrypted, QString("")).toString();
        datum._username_checked = _setting.value(Datum::_Username_Checked, false).toBool();
        datum._password_checked = _setting.value(Datum::_Password_Checked, false).toBool();
        datum._automate_checked = _setting.value(Datum::_Automate_Checked, false).toBool();
        if (datum._username_checked == true) {  // if have data.
            _ui->CB_Username->setCurrentText(datum._username);
            _ui->CB_Password->setCurrentText((datum._password_checked == true) ? QString("0123456789012345") : QString()); // note: don't display encrypted password on the screen.
            _ui->CB_Username_Checked->setChecked(datum._username_checked);
            _ui->CB_Password_Checked->setChecked(datum._password_checked);
            _ui->CB_Automate_Checked->setChecked(datum._automate_checked);
        } else {                                // if no data, reset ui.
            _ui->CB_Username->setCurrentText(QString());
            _ui->CB_Password->setCurrentText(QString());
            _ui->CB_Username_Checked->setChecked(true);   // note: username_checked is checked by default.
            _ui->CB_Password_Checked->setChecked(false);
            _ui->CB_Automate_Checked->setChecked(false);
        }

        _reading = false;
        return 5;
    }

    iptr Save_Info() {
        System::Logging(__FUNCTION__);

        datum._username = _ui->CB_Username->currentText().trimmed();
        if(datum._password_checked == false) {
            datum._encrypted = Encrypt(_ui->CB_Password->currentText().trimmed());
        }
        datum._username_checked = _ui->CB_Username_Checked->isChecked();
        datum._password_checked = _ui->CB_Password_Checked->isChecked();
        datum._automate_checked = _ui->CB_Automate_Checked->isChecked();
        if(datum._username_checked == true) {  // if have data.
            _setting.setValue(Datum::_Username, datum._username);
            _setting.setValue(Datum::_Encrypted, (datum._password_checked == true) ? datum._encrypted : Encrypt(datum._username));  // note: falsify encrypted password.
            _setting.setValue(Datum::_Username_Checked, datum._username_checked);
            _setting.setValue(Datum::_Password_Checked, datum._password_checked);
            _setting.setValue(Datum::_Automate_Checked, datum._automate_checked);
        }
        return 5;
    }

public:
    virtual bool event(QEvent *event) override {
        // System::Logging(__FUNCTION__);

        if(event->type() == QEvent::Paint) {
            // System::Logging("if(event->type() == QEvent::Paint) {");

            QPainter painter = QPainter(this); // note: construct painter every time if widget itself changes.
            painter.drawPixmap(0, 0, this->width() + 1, this->height() + 1, _background);
        } else if(_moving == false && event->type() == QEvent::MouseButtonPress && ((QMouseEvent *)event)->button() == Qt::LeftButton) {
            // System::Logging("} else if(_moving == false && event->type() == QEvent::MouseButtonPress && ((QMouseEvent *)event)->button() == Qt::LeftButton) {");

            _moving = true;
            _relative = QCursor::pos() - this->pos();
        } else if(_moving == true && event->type() == QEvent::MouseMove  && (((QMouseEvent *)event)->buttons() & Qt::LeftButton)) {
            // System::Logging("} else if(_moving == true && event->type() == QEvent::MouseMove && ((QMouseEvent *)event)->button() == Qt::LeftButton) {");

            this->move(QCursor::pos() - _relative); // note: move to a new absolute position in glabal screen.
        } else if(_moving == true && event->type() == QEvent::MouseButtonRelease && ((QMouseEvent *)event)->button() == Qt::LeftButton) {
            // System::Logging("} else if(_moving == true && event->type() == QEvent::MouseButtonRelease && ((QMouseEvent *)event)->button() == Qt::LeftButton) {");

            _moving = false;
        }
        return QWidget::event(event);
    }
};

#endif // Logging_h
