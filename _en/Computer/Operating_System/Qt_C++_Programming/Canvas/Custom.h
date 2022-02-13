/* Custom.h
Author: BSS9395
Update: 2022-02-10T00:27:00+08@China-Guangdong-Zhanjiang+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Custom_h
#define Custom_h

#define Header_h
#include "Common.h"
#include "System.h"

class Style {
public:
    class Color {
    public:
        static inline const uptr _Light_Blue_50 = 0xE1F5FE;    // rgba(225, 245, 254, 0.5);
        static inline const uptr _Light_Blue_100 = 0xB3E5FC;   // rgba(179, 229, 252, 0.5);
        static inline const uptr _Light_Blue_200 = 0x81D4FA;   // rgba(129, 212, 250, 0.5);
        static inline const uptr _Light_Blue_300 = 0x4FC3F7;   // rgba(79, 195, 247, 0.5);
        static inline const uptr _Light_Blue_400 = 0x29B6F6;   // rgba(41, 182, 246, 0.5);
        static inline const uptr _Light_Blue_500 = 0x03A9F4;   // rgba(3, 169, 244, 0.5);
        static inline const uptr _Light_Blue_600 = 0x039BE5;   // rgba(3, 155, 229, 0.5);
        static inline const uptr _Light_Blue_700 = 0x0288D1;   // rgba(2, 136, 209, 0.5);
        static inline const uptr _Light_Blue_800 = 0x0277BD;   // rgba(2, 119, 189, 0.5);
        static inline const uptr _Light_Blue_900 = 0x01579B;   // rgba(1, 87, 155, 0.5);
        static inline const uptr _Light_Blue_A100 = 0x80D8FF;  // rgba(128, 216, 255, 0.5);
        static inline const uptr _Light_Blue_A200 = 0x40C4FF;  // rgba(64, 196, 255, 0.5);
        static inline const uptr _Light_Blue_A400 = 0x00B0FF;  // rgba(0, 176, 255, 0.5);
        static inline const uptr _Light_Blue_A700 = 0x0091EA;  // rgba(0, 145, 234, 0.5);

    public:
        static inline const uptr _Blue_50 = 0xE3F2FD;    // rgba(227, 242, 253, 0.5);
        static inline const uptr _Blue_100 = 0xBBDEFB;   // rgba(187, 222, 251, 0.5);
        static inline const uptr _Blue_200 = 0x90CAF9;   // rgba(144, 202, 149, 0.5);
        static inline const uptr _Blue_300 = 0x64B5F6;   // rgba(100, 181, 246, 0.5);
        static inline const uptr _Blue_400 = 0x42A5F5;   // rgba(66, 165, 245, 0.5);
        static inline const uptr _Blue_500 = 0x2196F3;   // rgba(33, 150, 243, 0.5);
        static inline const uptr _Blue_600 = 0x1E88E5;   // rgba(30, 136, 229, 0.5);
        static inline const uptr _Blue_700 = 0x1976D2;   // rgba(25, 118, 210, 0.5);
        static inline const uptr _Blue_800 = 0x1565C0;   // rgba(21, 101, 192, 0.5);
        static inline const uptr _Blue_900 = 0x0D47A1;   // rgba(13, 71, 161, 0.5);
        static inline const uptr _Blue_A100 = 0x82B1FF;  // rgba(130, 177, 255, 0.5);
        static inline const uptr _Blue_A200 = 0x448AFF;  // rgba(68, 138, 255, 0.5);
        static inline const uptr _Blue_A400 = 0x2979FF;  // rgba(41, 121, 255, 0.5);
        static inline const uptr _Blue_A700 = 0x2962FF;  // rgba(41, 98, 255, 0.5);
    };

////////////////////////////////////////////////////////////////////////////////

public:
    static inline const QString _Close_Unsaved = R"(
QWidget {
    border: 0px solid;
    image: url(":/images/icons/custom_circle.png");
}
QWidget:hover {
    border: 0px solid;
    image: url(":/images/icons/custom_close.png");
}
    )";

    static inline const QString _Close_Saved = R"(
QWidget {
    border: 0px solid;
    image: url(":/images/icons/custom_close.png");
}
    )";

    ////////////////////////////////////////////////////////////////////////////////

    static inline const QString _Light_Background = R"(
QTextEdit {
    background-color: rgba(255, 255, 255, 1.0);
}
QTabBar::Tab:selected {
    background-color: rgba(255, 255, 255, 1.0);
}
    )";

    static inline const QString _Gray_Background = R"(
QTextEdit {
    background-color: rgba(127, 127, 127, 1.0);
}
QTabBar::Tab:selected {
    background-color: rgba(127, 127, 127, 1.0);
}
    )";

    static inline const QString _Dark_Background = R"(
QTextEdit {
    background-color: rgba(0, 0, 0, 1.0);
}
QTabBar::Tab:selected {
    background-color: rgba(0, 0, 0, 1.0);
}
    )";

    ////////////////////////////////////////////////////////////////////////////////

    static inline const QString _Username_Edited = R"(
QWidget {
    image: url(":/images/icons/custom_avatar.png");
    border: 1px solid transparent;
    padding: 1px;
}
QWidget:hover {
    background-color: rgba(3, 169, 244, 0.2);
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding: 1px;
}
QWidget:pressed {
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding-left: 2px;
    padding-top: 2px;
    padding-right: 0px;
    padding-bottom: 0px;
}
    )";

    static inline const QString _Username_Editing = R"(
QWidget {
    image: url(":/images/icons/custom_account.png");
    border: 1px solid transparent;
    padding: 1px;
}
QWidget:hover {
    background-color: rgba(3, 169, 244, 0.2);
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding: 1px;
}
QWidget:pressed {
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding-left: 2px;
    padding-top: 2px;
    padding-right: 0px;
    padding-bottom: 0px;
}
    )";

    static inline const QString _Username_Edit = R"(
QWidget {
    image: url(":/images/icons/custom_guest.png");
    border: 1px solid transparent;
    padding: 1px;
}
QWidget:hover {
    background-color: rgba(3, 169, 244, 0.2);
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding: 1px;
}
QWidget:pressed {
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding-left: 2px;
    padding-top: 2px;
    padding-right: 0px;
    padding-bottom: 0px;
}
    )";

    static inline const QString _Password_Edited = R"(
QWidget {
    image: url(":/images/icons/custom_lock.png");
    border: 1px solid transparent;
    padding: 1px;
}
QWidget:hover {
    background-color: rgba(3, 169, 244, 0.2);
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding: 1px;
}
QWidget:pressed {
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding-left: 2px;
    padding-top: 2px;
    padding-right: 0px;
    padding-bottom: 0px;
}
    )";

    static inline const QString _Password_Editing = R"(
QWidget {
    image: url(":/images/icons/custom_unlock.png");
    border: 1px solid transparent;
    padding: 1px;
}
QWidget:hover {
    background-color: rgba(3, 169, 244, 0.2);
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding: 1px;
}
QWidget:pressed {
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding-left: 2px;
    padding-top: 2px;
    padding-right: 0px;
    padding-bottom: 0px;
}
    )";

    static inline const QString _Password_Edit = R"(
QWidget {
    image: url(":/images/icons/custom_imlock.png");
    border: 1px solid transparent;
    padding: 1px;
}
QWidget:hover {
    background-color: rgba(3, 169, 244, 0.2);
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding: 1px;
}
QWidget:pressed {
    border: 1px solid rgba(3, 169, 244, 0.2);
    padding-left: 2px;
    padding-top: 2px;
    padding-right: 0px;
    padding-bottom: 0px;
}
    )";
};

////////////////////////////////////////////////////////////////////////////////

class SpinBox : public QSpinBox {
    Q_OBJECT

public:
    iptr _value = 0;

public:
    explicit SpinBox(QWidget *parent = nullptr)
        : QSpinBox(parent) {
        // System::Logging(__FUNCTION__);
    }

    virtual ~SpinBox() override {
        // System::Logging(__FUNCTION__);
    }

public:
    virtual bool event(QEvent *event) override {
        // System::Logging(__FUNCTION__);

        if(event->type() == QEvent::FocusIn) {
            System::Logging("if(event->type() == QEvent::FocusIn) {");
            _value = this->value();
            // return true;
        } else if((event->type() == QEvent::KeyRelease && ((QKeyEvent *)event)->key() == Qt::Key_Return)
                   || event->type() == QEvent::FocusOut) {
            // System::Logging("} else if((event->type() == QEvent::KeyRelease && ((QKeyEvent *)event)->key() == Qt::Key_Return) || event->type() == QEvent::FocusOut) {");
            if(_value != this->value()) {
                _value = this->value();
                emit Value_Changed(_value);
            }
            // return true;
        }
        return QWidget::event(event);
    }

signals:
    void Value_Changed(iptr value);
};

////////////////////////////////////////////////////////////////////////////////

class ComboBox : public QComboBox {
    Q_OBJECT

public:
    ComboBox(QWidget *parent = nullptr)
        : QComboBox(parent) {
        // System::Logging(__FUNCTION__);
    }

    virtual ~ComboBox() override {
        // System::Logging(__FUNCTION__);
    }

public:
    virtual bool event(QEvent *event) override {
        // System::Logging(__FUNCTION__);

        if(event->type() == QEvent::FocusIn) {
            emit Focus_In_Changed();
        } else if(event->type() == QEvent::FocusOut) {
            emit Focus_Out_Changed();
        }
        return QWidget::event(event);
    }

signals:
    void Focus_In_Changed();
    void Focus_Out_Changed();
};

#endif // Custom_h
