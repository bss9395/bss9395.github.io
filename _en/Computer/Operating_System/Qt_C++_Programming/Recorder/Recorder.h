/* Recorder.h
Author: BSS9395
Update: 2022-07-11T23:36:00+08@China-Shanghai+08
Design: Recorder
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Recorder_h
#define Recorder_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Recorder.h"

class Recorder : public QMainWindow {
    Q_OBJECT

    struct : public Enume {
        Enume _VeryLowQuality  = Enume(this, QMultimedia::VeryLowQuality , "VeryLowQuality");
        Enume _LowQuality      = Enume(this, QMultimedia::LowQuality     , "LowQuality");
        Enume _NormalQuality   = Enume(this, QMultimedia::NormalQuality  , "NormalQuality");
        Enume _HighQuality     = Enume(this, QMultimedia::HighQuality    , "HighQuality");
        Enume _VeryHighQuality = Enume(this, QMultimedia::VeryHighQuality, "VeryHighQuality");
    } _EncodingQuality;

    struct : public Enume {
        Enume _UnavailableStatus = Enume(this, QMediaRecorder::UnavailableStatus, "UnavailableStatus");
        Enume _UnloadedStatus    = Enume(this, QMediaRecorder::UnloadedStatus   , "UnloadedStatus");
        Enume _LoadingStatus     = Enume(this, QMediaRecorder::LoadingStatus    , "LoadingStatus");
        Enume _LoadedStatus      = Enume(this, QMediaRecorder::LoadedStatus     , "LoadedStatus");
        Enume _StartingStatus    = Enume(this, QMediaRecorder::StartingStatus   , "StartingStatus");
        Enume _RecordingStatus   = Enume(this, QMediaRecorder::RecordingStatus  , "RecordingStatus");
        Enume _PausedStatus      = Enume(this, QMediaRecorder::PausedStatus     , "PausedStatus");
        Enume _FinalizingStatus  = Enume(this, QMediaRecorder::FinalizingStatus , "FinalizingStatus");
    } _Status;

    struct : public Enume {
        Enume _BigEndian    = Enume(this, QAudioFormat::BigEndian   , "BigEndian");
        Enume _LittleEndian = Enume(this, QAudioFormat::LittleEndian, "LittleEndian");
    } _Endian;

    struct : public Enume {
        Enume _Unknown     = Enume(this, QAudioFormat::Unknown    , "Unknown");
        Enume _SignedInt   = Enume(this, QAudioFormat::SignedInt  , "SignedInt");
        Enume _UnSignedInt = Enume(this, QAudioFormat::UnSignedInt, "UnSignedInt");
        Enume _Float       = Enume(this, QAudioFormat::Float      , "Float");
    } _SampleType;

public:
    Ui::Recorder *_ui = nullptr;
    QAudioRecorder *_recorder = nullptr;
    QAudioProbe *_probe = nullptr;

public:
    explicit Recorder(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Recorder) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup();

        QObject::connect(_ui->A_Record_Pause, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Record_Pause, &QAction::triggered, this, [this]() -> void {");

            if(_recorder->state() == QMediaRecorder::RecordingState) {
                _recorder->pause();
            } else if(_recorder->state() == QMediaRecorder::PausedState) {
                _recorder->record();
            } else if(_recorder->state() == QMediaRecorder::StoppedState) {
                QString filename = _ui->LE_File->text().trimmed();
                if(filename.size() < 1) {
                    filename = _ui->LE_File->placeholderText().trimmed();
                }
                if(QFile::exists(filename) == true && QFile::remove(filename) == false) {
                    QString title = "错误";
                    QString text = "录音输出文件被占用！";
                    QMessageBox::critical(this, title, text);
                    return ;
                }
                _recorder->setOutputLocation(QUrl::fromLocalFile(filename));
                _recorder->setAudioInput(_ui->CB_Audio_Inputs->currentText());
                QAudioEncoderSettings settings = QAudioEncoderSettings();
                settings.setCodec(_ui->CB_Supported_Audio_Codecs->currentText());
                settings.setSampleRate(_ui->CB_Sample_Rate->currentText().toInt());
                settings.setChannelCount(_ui->CB_Channels->currentText().toInt());
                if(_ui->RB_Quality->isChecked() == true) {
                    settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);
                } else if(_ui->RB_Bit_Rate->isChecked() == true) {
                    settings.setEncodingMode(QMultimedia::ConstantBitRateEncoding);
                    settings.setBitRate(_ui->CB_Bit_Rate->currentText().toInt());
                }
                _recorder->setAudioSettings(settings);
                _recorder->record();
            }
        });

        QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {");

            _recorder->stop();
        });

        ////////////////////////////////

        QObject::connect(_recorder, &QAudioRecorder::stateChanged, this, [this](QMediaRecorder::State state) -> void {
            System::Logging("QObject::connect(_recorder, &QAudioRecorder::stateChanged, this, [this](QMediaRecorder::State state) -> void {");

            if(state == QMediaRecorder::RecordingState) {
                _ui->A_Record_Pause->setIcon(QIcon(":/images/icons/pause_circle.png"));
            } else if (state == QMediaRecorder::PausedState) {
                _ui->A_Record_Pause->setIcon(QIcon(":/images/icons/play_circle.png"));
            } else if (state == QMediaRecorder::StoppedState) {
                _ui->A_Record_Pause->setIcon(QIcon(":/images/icons/play_circle.png"));
                _ui->L_Timestamp->setText("00:00:00");
            }
            _ui->GB_File->setEnabled(state == QMediaRecorder::StoppedState);
        });

        QObject::connect(_recorder, &QAudioRecorder::statusChanged, this, [this](QMediaRecorder::Status status) -> void {
            System::Logging("QObject::connect(_recorder, &QAudioRecorder::statusChanged, this, [this](QMediaRecorder::Status status) -> void {");

            System::Logging("status == %s", _Status._Alias(status));
        });

        QObject::connect(_recorder, &QAudioRecorder::durationChanged, this, [this](qint64 duration) -> void {
            System::Logging("QObject::connect(_recorder, &QAudioRecorder::durationChanged, this, [this](qint64 duration) -> void {");

            duration = duration / 1000;
            iptr sec = duration % 60;
            iptr min = duration / 60 % 60;
            iptr hour = duration / 3600 % 24;
            _ui->L_Timestamp->setText(QString::asprintf("%02td:%02td:%02td", hour, min, sec));
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_File, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_File, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "请选择输出文件";
            QString filter = "WAV文件(*.wav);;所有文件(*.*)";
            QString filename = QFileDialog::getSaveFileName(this, caption, QDir::currentPath(), filter);
            if(filename.size() < 1) {
                return ;
            }
            _ui->LE_File->setText(filename);
        });

        QObject::connect(_probe, &QAudioProbe::audioBufferProbed, this, [this](const QAudioBuffer &buffer) -> void {
            // System::Logging("QObject::connect(_probe, &QAudioProbe::audioBufferProbed, this, [this](const QAudioBuffer &buffer) -> void {");

            _ui->SB_Byte_Count->setRange(buffer.byteCount(), buffer.byteCount());
            _ui->SB_Duration->setRange(buffer.duration() / 1000, buffer.duration() / 1000);
            _ui->SB_Frame_Count->setRange(buffer.frameCount(), buffer.frameCount());
            _ui->SB_Sample_Count->setRange(buffer.sampleCount(), buffer.sampleCount());

            ////////////////////////////

            QAudioFormat format = buffer.format();
            _ui->SB_Channel_Count->setRange(format.channelCount(), format.channelCount());
            _ui->SB_Sample_Size->setRange(format.sampleSize(), format.sampleSize());
            _ui->SB_Sample_Rate->setRange(format.sampleRate(), format.sampleRate());
            _ui->SB_Bytes_Per_Frame->setRange(format.bytesPerFrame(), format.bytesPerFrame());
            _ui->LE_Byte_Order->setText(_Endian._Alias(format.byteOrder()));
            _ui->LE_Codec->setText(format.codec());
            _ui->LE_Sample_Type->setText(_SampleType._Alias(format.sampleType()));
        });
    }

    virtual ~Recorder() {
        System::Logging(__FUNCTION__);
        delete _ui;
        delete _recorder;
        delete _probe;
    }

public:
    void _Setup() {
        System::Logging(__FUNCTION__);

        _recorder = new QAudioRecorder(this);
        _probe = new QAudioProbe(this);
        _probe->setSource(_recorder);

        if(_recorder->defaultAudioInput().isEmpty() == true) {
            return;
        }

        _ui->LE_File->setPlaceholderText(QDir::currentPath() + "temp.wav");

        _ui->CB_Audio_Inputs->addItems(_recorder->audioInputs());

        _ui->CB_Supported_Audio_Codecs->addItems(_recorder->supportedAudioCodecs());

        for(iptr i = 0, count = _recorder->supportedAudioSampleRates().count(); i < count; i += 1) {
            _ui->CB_Sample_Rate->addItem(QString::number(_recorder->supportedAudioSampleRates().at(i)));
        }

        _ui->CB_Channels->addItem("1");
        _ui->CB_Channels->addItem("2");
        _ui->CB_Channels->addItem("4");
        _ui->CB_Channels->setCurrentText("2");

        _ui->RB_Quality->setChecked(true);
        _ui->S_Quality->setRange(0, _EncodingQuality._index - 1);
        _ui->S_Quality->setSingleStep(1);
        _ui->S_Quality->setValue(_EncodingQuality._NormalQuality._index);

        _ui->CB_Bit_Rate->addItem("32000");
        _ui->CB_Bit_Rate->addItem("64000");
        _ui->CB_Bit_Rate->addItem("96000");
        _ui->CB_Bit_Rate->addItem("128000");
        _ui->CB_Bit_Rate->setCurrentText("64000");
    }
};

#endif // Recorder_h
