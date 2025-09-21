#pragma once

#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

template<typename Type_, unsigned int>
struct Enum {
    Type_ _enum;
    Enum(const Type_& that) {
        _enum = that;
    }
    operator Type_() {
        return _enum;
    }
};

class Localization: public QObject {
    Q_OBJECT
public:
    typedef Enum<QString, 0> Locale;
    const Locale _locale_zh_CN = Localization::Locale("zh-CN");
    const Locale _locale_en_US = Localization::Locale("en-US");
public:
    const QJsonObject _localization;

private:
    explicit Localization() {
        _Load_Localization(_locale_zh_CN);
    }
    explicit Localization(const Localization&) = delete;
    Localization& operator=(const Localization&) = delete;

public:
    static Localization* _Instance() {
        static Localization config;
        return &config;
    }

    void _Load_Localization(Locale locale) {
        for(QFile file(QString(":/locales/%1.json").arg(locale)); file.open(QFile::ReadOnly | QFile::Text) == true; ) {
            QByteArray json = file.readAll();
            file.close();
            (*(QJsonObject*)(&_localization)) = QJsonDocument::fromJson(json).object();
            break;
        }
    }
    void _Update_Localization(Locale locale) {
        _Load_Localization(locale);

        QWidgetList widgets = QApplication::allWidgets();
        for(int i = 0; i < widgets.size(); i += 1) {
            QWidget* widget = widgets[i];
            // qDebug() << "widget = " << widget;
            int methodIndex = widget->metaObject()->indexOfMethod("_Localize()");
            if(0 <= methodIndex) {
                QMetaObject::invokeMethod(widget, "_Localize");
            }
        }
    }
};

class WindowPopup: public QWidget {
    Q_OBJECT

public:
    explicit WindowPopup(QWidget* parent = nullptr)
        : QWidget(parent) {
        this->setWindowFlag(Qt::Dialog, true);
        this->setWindowModality(Qt::ApplicationModal);
        QWidget::setAttribute(Qt::WA_StyledBackground, true);    // 启用O_OBJECT宏，需要设置Qt::WA_StyledBackground，否则背景样式不生效
        this->resize(200, 150);
        QString style = R"!(
        [objectName = "this"] {
            background-color: "#FF0000FF";
        }
        )!";
        this->setObjectName("this");
        this->setStyleSheet(style);

        this->setWindowTitle("");
        _label = new QLabel(this);
        _label->setText("");
        _label->move(0, this->height() - _label->height());

		_Localize();
    }

public:
    QLabel* _label = nullptr;

public:
    Q_INVOKABLE void _Localize() {
        qDebug().noquote() << __FUNCTION__;
        QJsonObject localization = Localization::_Instance()->_localization;
        QJsonObject windowpopup = localization["_windowpopup"].toObject();
        if(windowpopup.isEmpty() == false) {
            if(windowpopup["_title"].isNull() == false) {
                this->setWindowTitle(windowpopup["_title"].toString());
            }
            if(_label != nullptr && windowpopup["_label"].isNull() == false) {
                _label->setText(windowpopup["_label"].toString());
            }
        }
    }
};

class WindowMinor: public QWidget {
    Q_OBJECT

public:
    explicit WindowMinor(QWidget* parent = nullptr)
        : QWidget(parent) {
        QWidget::setAttribute(Qt::WA_StyledBackground, true);    // 启用O_OBJECT宏，需要设置Qt::WA_StyledBackground，否则背景样式不生效
        this->resize(400, 300);
        QString style = R"!(
        [objectName = "this"] {
            background-color: "#FF00FF00";
        }
        )!";
        this->setObjectName("this");
        this->setStyleSheet(style);

        this->setWindowTitle("");
        _label = new QLabel(this);
        _label->setText("");
        _label->move(0, this->height() - _label->height());

        _windowPopup = new WindowPopup(this);
        _windowPopup->show();

        _Localize();
    }

public:
    QLabel* _label = nullptr;
    WindowPopup* _windowPopup = nullptr;

public:
    Q_INVOKABLE void _Localize() {
        qDebug().noquote() << __FUNCTION__;
        QJsonObject localization = Localization::_Instance()->_localization;
        QJsonObject windowminor = localization["_windowminor"].toObject();
        if(windowminor.isEmpty() == false) {
            if(windowminor["_title"].isNull() == false) {
                this->setWindowTitle(windowminor["_title"].toString());
            }
            if(_label != nullptr && windowminor["_label"].isNull() == false) {
                _label->setText(windowminor["_label"].toString());
            }
        }
    }
};

class WindowMain: public QMainWindow {
    Q_OBJECT

public:
    explicit WindowMain(QWidget* parent = nullptr)
        : QMainWindow(parent) {
        QWidget::setAttribute(Qt::WA_StyledBackground, true);    // 启用O_OBJECT宏，需要设置Qt::WA_StyledBackground，否则背景样式不生效
        this->resize(800, 600);
        QString style = R"!(
        [objectName = "this"] {
            background-color: "#FFFF0000";
        }
        )!";
        this->setObjectName("this");
        this->setStyleSheet(style);
        this->setWindowTitle("");

        _label = new QLabel(this);
        _label->setText("");
        _label->move(0, this->height() - _label->height());

        _windowMinor = new WindowMinor(this);
        _windowMinor->move(0, 0);

        _Localize();
    }

public:
    QLabel* _label = nullptr;
    WindowMinor* _windowMinor = nullptr;

public:
    Q_INVOKABLE void _Localize() {
        qDebug().noquote() << __FUNCTION__;
        QJsonObject localization = Localization::_Instance()->_localization;
        QJsonObject windowmain = localization["_windowmain"].toObject();
        if(windowmain.isEmpty() == false) {
            if(windowmain["_title"].isNull() == false) {
                this->setWindowTitle(windowmain["_title"].toString());
            }
            if(_label != nullptr && windowmain["_label"].isNull() == false) {
                _label->setText(windowmain["_label"].toString());
            }
        }
    }
};
