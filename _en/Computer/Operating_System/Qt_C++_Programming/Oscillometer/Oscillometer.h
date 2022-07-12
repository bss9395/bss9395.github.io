/* Oscillometer.h
Author: BSS9395
Update: 2022-07-12T23:00:00+08@China-Shanghai+08
Design: Oscillometer
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Oscillometer_h
#define Oscillometer_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Oscillometer.h"
#include "Displayer.h"

class Oscillometer : public QMainWindow {
    Q_OBJECT

public:
    struct : public Enume {
        Enume _Unknown     = Enume(this, QAudioFormat::Unknown    , "Unknown");
        Enume _SignedInt   = Enume(this, QAudioFormat::SignedInt  , "SignedInt");
        Enume _UnSignedInt = Enume(this, QAudioFormat::UnSignedInt, "UnSignedInt");
        Enume _Float       = Enume(this, QAudioFormat::Float      , "Float");
    } _SampleType;

    struct : public Enume {
        Enume _BigEndian    = Enume(this, QAudioFormat::BigEndian   , "BigEndian");
        Enume _LittleEndian = Enume(this, QAudioFormat::LittleEndian, "LittleEndian");
    } _Endian;

public:
    Ui::Oscillometer *_ui = nullptr;
    QAudioInput *_input = nullptr;
    Displayer *_displayer = nullptr;
    QList<QAudioDeviceInfo> _devices;

public:
    explicit Oscillometer(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Oscillometer) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup();

        QObject::connect(_ui->CB_Available_Devices, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_Available_Devices, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");

            QAudioDeviceInfo device = _devices.at(index);
            _ui->CB_Supported_Codecs->clear();
            _ui->CB_Supported_Codecs->addItems(device.supportedCodecs());

            _ui->CB_Supported_Sample_Rates->clear();
            QList<int> rates = device.supportedSampleRates();
            for(auto beg = rates.begin(), end = rates.end(); beg != end; beg += 1) {
                _ui->CB_Supported_Sample_Rates->addItem(QString::number(*beg));
            }

            _ui->CB_Supported_Channel_Counts->clear();
            QList<int> channels = device.supportedChannelCounts();
            for(auto beg = channels.begin(), end = channels.end(); beg != end; beg += 1) {
                _ui->CB_Supported_Channel_Counts->addItem(QString::number(*beg));
            }

            _ui->CB_Supported_Sample_Types->clear();
            QList<QAudioFormat::SampleType> types = device.supportedSampleTypes();
            for(auto beg = types.begin(), end = types.end(); beg != end; beg += 1) {
                _ui->CB_Supported_Sample_Types->addItem(_SampleType._Alias(*beg));
            }

            _ui->CB_Supported_Sample_Sizes->clear();
            QList<int> sizes = device.supportedSampleSizes();
            for(auto beg = sizes.begin(), end = sizes.end(); beg != end; beg += 1) {
                _ui->CB_Supported_Sample_Sizes->addItem(QString::number(*beg));
            }

            _ui->CB_Supported_Byte_Orders->clear();
            QList<QAudioFormat::Endian> orders = device.supportedByteOrders();
            for(auto beg = orders.begin(), end = orders.end(); beg != end; beg += 1) {
                _ui->CB_Supported_Byte_Orders->addItem(_Endian._Alias(*beg));
            }
        });
        _ui->CB_Available_Devices->setCurrentIndex(0);

        ////////////////////////////////

        QObject::connect(_ui->A_Start, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Start, &QAction::triggered, this, [this]() -> void {");

            QAudioFormat format = QAudioFormat();
            format.setCodec(_ui->CB_Supported_Codecs->currentText());
            format.setSampleRate(_ui->CB_Supported_Sample_Rates->currentText().toInt());
            format.setChannelCount(_ui->CB_Supported_Channel_Counts->currentText().toInt());
            format.setSampleType((QAudioFormat::SampleType)_SampleType._Enume(_ui->CB_Supported_Sample_Types->currentText()));
            format.setSampleSize(_ui->CB_Supported_Sample_Sizes->currentText().toInt());
            format.setByteOrder((QAudioFormat::Endian)_Endian._Enume(_ui->CB_Supported_Byte_Orders->currentText()));
            if(false == (1 <= _devices.count() && _devices.at(_ui->CB_Available_Devices->currentIndex()).isFormatSupported(format))) {
                QString title = "测试失败";
                QString text = "输入设备不支持此设置！";
                QMessageBox::critical(this, title, text);
                return;
            }

            ////////////////////////////

            _input = new QAudioInput(_devices.at(_ui->CB_Available_Devices->currentIndex()), format, this);
            _displayer = new Displayer(_ui, _input, this);
            _input->start(_displayer);

            _ui->A_Start->setEnabled(false);
            _ui->A_Stop->setEnabled(true);
        });

        QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {");

            delete _input;     _input = nullptr;
            delete _displayer; _displayer = nullptr;
            _ui->A_Start->setEnabled(true);
            _ui->A_Stop->setEnabled(false);
        });
    }

    virtual ~Oscillometer() {
        System::Logging(__FUNCTION__);
        delete _input;
        delete _displayer;
        delete _ui;
    }

public:
    void _Setup() {
        System::Logging(__FUNCTION__);

        _devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
        if(_devices.count() < 1) {
            _ui->A_Start->setEnabled(false);
            _ui->A_Stop->setEnabled(false);
            return;
        }
        for(auto beg = _devices.begin(), end = _devices.end(); beg != end; beg += 1) {
            _ui->CB_Available_Devices->addItem((*beg).deviceName());
        }
        _ui->CB_Available_Devices->setCurrentIndex(-1);
    }
};

#endif // Oscillometer_h
