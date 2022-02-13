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
};

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

#endif // Custom_h
