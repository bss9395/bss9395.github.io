/* Brightness.h
Author: BSS9395
Update: 2023-02-07T23:48:00+08@China-Shanghai+08
Design: Brightness
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Brightness_h
#define Brightness_h

#define   Header_h
#include "Common.h"
#include "ui_Brightness.h"
#include "System.h"
#include "Gamma_Ramp.h"

class Brightness : public QMainWindow {
    Q_OBJECT

private:
    Ui::Brightness *_ui = nullptr;
    QSettings *_settings = nullptr;

public:
    explicit Brightness(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Brightness) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        QObject::connect(_ui->S_Gamma, &QSlider::valueChanged, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->S_Gamma, &QSlider::valueChanged, this, [this]() -> void {");

            CGammaRamp().SetBrightness(NULL, _ui->S_Gamma->value());
        });
        QObject::connect(_ui->PB_Gamma, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Gamma, &QPushButton::clicked, this, [this]() -> void {");

            _ui->S_Gamma->setValue(_ui->S_Gamma->maximum() / 2);
            CGammaRamp().SetBrightness(NULL, _ui->S_Gamma->value());
        });


        _settings = new QSettings(QString("%1/%2.config").arg(QApplication::applicationDirPath()).arg(QApplication::applicationName()), QSettings::IniFormat);
        int value = _settings->value("brightness/value", QVariant::fromValue(127)).toInt();

        this->setWindowTitle("屏幕亮度调节工具");
        _ui->S_Gamma->setRange(0, 255);
        _ui->S_Gamma->setValue(value);
    }

    virtual ~Brightness() {
        System::Logging(__FUNCTION__);

        delete _ui;
        _ui = nullptr;
    }

public:
    void closeEvent(QCloseEvent *event) override {
        System::Logging(__FUNCTION__);

        QSettings settings(QString("%1/%2.config").arg(QApplication::applicationDirPath()).arg(QApplication::applicationName()), QSettings::IniFormat);
        settings.setValue("brightness/value", QVariant::fromValue(QString::asprintf("%d", _ui->S_Gamma->value())));

        QMainWindow::closeEvent(event);
    }

};
#endif // Brightness_h
