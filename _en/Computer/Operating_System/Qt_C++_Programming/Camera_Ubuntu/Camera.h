/* Camera.h
Author: BSS9395
Update: 2022-07-17T16:42:00+08@China-Shanghai+08
Design: Camera
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Camera_h
#define Camera_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Camera.h"

class Camera : public QMainWindow {
    Q_OBJECT

public:
    struct : public Enume {
        Enume _UnloadedState = Enume(this, QCamera::UnloadedState, "UnloadedState");
        Enume _LoadedState   = Enume(this, QCamera::LoadedState  , "LoadedState");
        Enume _ActiveState   = Enume(this, QCamera::ActiveState  , "ActiveState");
    } _Camera_State;

    struct : public Enume {
        Enume _UnavailableStatus = Enume(this, QCamera::UnavailableStatus, "UnavailableStatus");
        Enume _UnloadedStatus    = Enume(this, QCamera::UnloadedStatus   , "UnloadedStatus");
        Enume _LoadingStatus     = Enume(this, QCamera::LoadingStatus    , "LoadingStatus");
        Enume _UnloadingStatus   = Enume(this, QCamera::UnloadingStatus  , "UnloadingStatus");
        Enume _LoadedStatus      = Enume(this, QCamera::LoadedStatus     , "LoadedStatus");
        Enume _StandbyStatus     = Enume(this, QCamera::StandbyStatus    , "StandbyStatus");
        Enume _StartingStatus    = Enume(this, QCamera::StartingStatus   , "StartingStatus");
        Enume _StoppingStatus    = Enume(this, QCamera::StoppingStatus   , "StoppingStatus");
        Enume _ActiveStatus      = Enume(this, QCamera::ActiveStatus     , "ActiveStatus");
    } _Camera_Status;

    struct : public Enume {
        Enume _NoError                  = Enume(this, QCamera::NoError                 , "NoError");
        Enume _CameraError              = Enume(this, QCamera::CameraError             , "CameraError");
        Enume _InvalidRequestError      = Enume(this, QCamera::InvalidRequestError     , "InvalidRequestError");
        Enume _ServiceMissingError      = Enume(this, QCamera::ServiceMissingError     , "ServiceMissingError");
        Enume _NotSupportedFeatureError = Enume(this, QCamera::NotSupportedFeatureError, "NotSupportedFeatureError");
    } _Camera_Error;

    struct : public Enume {
        Enume _StoppedState   = Enume(this, QMediaRecorder::StoppedState  , "StoppedState");
        Enume _RecordingState = Enume(this, QMediaRecorder::RecordingState, "RecordingState");
        Enume _PausedState    = Enume(this, QMediaRecorder::PausedState   , "PausedState");
    } _Recorder_State;

    struct : public Enume {
        Enume _NoError         = Enume(this, QMediaRecorder::NoError        , "NoError");
        Enume _ResourceError   = Enume(this, QMediaRecorder::ResourceError  , "ResourceError");
        Enume _FormatError     = Enume(this, QMediaRecorder::FormatError    , "FormatError");
        Enume _OutOfSpaceError = Enume(this, QMediaRecorder::OutOfSpaceError, "OutOfSpaceError");
    } _Recorder_Error;

public:
    Ui::Camera *_ui = nullptr;
    QList<QCameraInfo> _available_cameras;
    iptr _width = 640;
    iptr _height = 480;
    iptr _volume = 50;
    QCamera *_camera = nullptr;
    QVideoProbe *_probe = nullptr;
    QMediaRecorder *_recorder = nullptr;
    bool _snapshot = false;

public:
    Camera(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Camera) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _Setup();

        QObject::connect(_ui->PB_Refresh, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Refresh, &QPushButton::clicked, this, [this]() -> void {");

            _ui->CB_Camera_List->blockSignals(true);
            _ui->CB_Camera_List->clear();
            _available_cameras = QCameraInfo::availableCameras();
            if(_available_cameras.count() < 1) {
                return;
            }
            for(auto beg = _available_cameras.begin(), end = _available_cameras.end(); beg != end; beg += 1) {
                _ui->CB_Camera_List->addItem(beg->description());
            }
            _ui->CB_Camera_List->setCurrentIndex(-1);
            _ui->CB_Camera_List->blockSignals(false);
            _ui->CB_Camera_List->setCurrentText(QCameraInfo::defaultCamera().description());
        });

        QObject::connect(_ui->PB_Filepath, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Filepath, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "选择保存文件";
            QString filter = "所有文件(*.*)";
            QString filepath = QFileDialog::getSaveFileName(this, caption, QDir::homePath(), filter);
            if(filepath.size() < 0) {
                return;
            }
            _ui->LE_Filepath->setText(filepath);
        });

        _ui->TB_Camera_Close->hide();
        QObject::connect(_ui->TB_Camera_Open, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Camera_Open, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return ;
            }
            _camera->start();
            _ui->TB_Camera_Open->hide();
            _ui->TB_Camera_Close->show();
        });
        QObject::connect(_ui->TB_Camera_Close, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Camera_Close, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return;
            }
            _camera->stop();
            _ui->TB_Camera_Open->show();
            _ui->TB_Camera_Close->hide();
        });

        _ui->TB_Recorder_Stop->hide();
        QObject::connect(_ui->TB_Recorder_Start, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Recorder_Start, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return ;
            }
            QString filepath = _ui->LE_Filepath->text();
            if(filepath.size() <= 0) {
                filepath = _ui->LE_Filepath->placeholderText();
            }
            if(QFile::exists(filepath) == true) {
                if(QFile::remove(filepath) == false) {
                    QString title = "错误";
                    QString text = "文件被占用！";
                    QMessageBox::information(this, title, text);
                    return;
                }
            }
            _recorder->setOutputLocation(QUrl(filepath));
            _recorder->record();
            _ui->TB_Recorder_Start->hide();
            _ui->TB_Recorder_Stop->show();
        });
        QObject::connect(_ui->TB_Recorder_Stop, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Recorder_Stop, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return ;
            }
            _recorder->stop();
            _ui->TB_Recorder_Start->show();
            _ui->TB_Recorder_Stop->hide();
        });

        _ui->TB_Recorder_Mute->hide();
        _ui->S_Recorder_Volume->setTracking(false);
        _ui->S_Recorder_Volume->setRange(0, 100);
        _ui->S_Recorder_Volume->setSingleStep(1);
        _ui->S_Recorder_Volume->setValue(_volume);
        QObject::connect(_ui->TB_Recorder_Volume, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Recorder_Volume, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return ;
            }
            _ui->S_Recorder_Volume->blockSignals(true);
            _recorder->setMuted(true);
            _volume = _ui->S_Recorder_Volume->value();
            _ui->S_Recorder_Volume->setValue(0);
            _ui->TB_Recorder_Volume->hide();
            _ui->TB_Recorder_Mute->show();
            _ui->S_Recorder_Volume->blockSignals(false);
        });
        QObject::connect(_ui->TB_Recorder_Mute, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Recorder_Mute, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return ;
            }
            _ui->S_Recorder_Volume->blockSignals(true);
            _recorder->setMuted(false);
            _ui->S_Recorder_Volume->setValue(_volume);
            _recorder->setVolume(qRound(100 * QAudio::convertVolume(_volume / qreal(100.0), QAudio::LogarithmicVolumeScale, QAudio::LinearVolumeScale)));
            _ui->TB_Recorder_Volume->show();
            _ui->TB_Recorder_Mute->hide();
            _ui->S_Recorder_Volume->blockSignals(false);
        });
        QObject::connect(_ui->S_Recorder_Volume, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Recorder_Volume, &QSlider::valueChanged, this, [this](int value) -> void {");

            if(_camera == nullptr) {
                return ;
            }
            if(value <= 0) {
                _ui->TB_Recorder_Volume->click();
            } else {
                _ui->TB_Recorder_Mute->click();
            }
        });

        QObject::connect(_ui->TB_Frame_Capture, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Frame_Capture, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return ;
            }
            _snapshot = true;
        });

        QObject::connect(_ui->TB_Frame_Save, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Frame_Save, &QToolButton::clicked, this, [this]() -> void {");

            if(_camera == nullptr) {
                return ;
            }
            QString caption = "选择保存文件";
            QString filter = "PNG图片(*.png)";
            QString filepath = QFileDialog::getSaveFileName(this, caption, QDir::homePath(), filter);
            if(filepath.size() <= 0) {
                return;
            }
            _ui->L_Frame->pixmap()->save(filepath, "", 100);
        });

        ////////////////////////////////////////////////////////////////////////

        QObject::connect(_ui->CB_Camera_List, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_Camera_List, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");

            if(index < 0) {
                return ;
            }
            _Destruct();
            _camera = new QCamera(_available_cameras[index], this);
            QCameraViewfinderSettings settings = QCameraViewfinderSettings();
            settings.setPixelFormat(QVideoFrame::Format_ARGB32);
            settings.setResolution(_width, _height);
            _camera->setViewfinderSettings(settings);
            _camera->setCaptureMode(QCamera::CaptureVideo);

            QObject::connect(_camera, &QCamera::stateChanged, this, [this](QCamera::State state) -> void {
                System::Logging("QObject::connect(_camera, &QCamera::stateChanged, this, [this](QCamera::State state) -> void {");

                _ui->L_Camera_Status->setText(_Camera_State._Alias(state));
                System::Logging(_ui->L_Camera_Status->text().toStdString().data());
            });

            QObject::connect(_camera, &QCamera::statusChanged, this, [this](QCamera::Status status) -> void {
                System::Logging("QObject::connect(_camera, &QCamera::statusChanged, this, [this](QCamera::Status status) -> void {");

                _ui->L_Camera_Status->setText(_Camera_Status._Alias(status));
                System::Logging(_ui->L_Camera_Status->text().toStdString().data());

                if(status == _Camera_Status._LoadedStatus._enume) {
                    iptr count = 0;
                    auto resolution = _camera->supportedViewfinderResolutions();
                    for(auto beg = resolution.begin(), end = resolution.end(); beg != end; beg += 1, count += 1) {
                        QString text = QString::asprintf("supportedViewfinderPixelFormats[%td] == [%td, %td]", count, (iptr)beg->width(), (iptr)beg->height());
                        System::Logging(text.toStdString().data());
                    }
                    count = 0;
                    auto framerate = _camera->supportedViewfinderFrameRateRanges();
                    for(auto beg = framerate.begin(), end = framerate.end(); beg != end; beg += 1, count += 1) {
                        QString text = QString::asprintf("framerate[%td] == [%td, %td]", count, (iptr)beg->minimumFrameRate, (iptr)beg->maximumFrameRate);
                        System::Logging(text.toStdString().data());
                    }
                }
            });

            QObject::connect(_camera, (void (QCamera::*)(QCamera::Error))&QCamera::error, this, [this](QCamera::Error error) -> void {
                System::Logging("QObject::connect(_camera, (void (QCamera::*)(QCamera::Error))&QCamera::error, this, [this](QCamera::Error error) -> void {");

                _ui->L_Camera_Status->setText(_Camera_Error._Alias(error));
                System::Logging(_ui->L_Camera_Status->text().toStdString().data());
            });

            ////////////////////////////

            _probe = new QVideoProbe(this);
            _probe->setSource(_camera);
            QObject::connect(_probe, &QVideoProbe::videoFrameProbed, this, [this](QVideoFrame frame) -> void {
                System::Logging("QObject::connect(_probe, &QVideoProbe::videoFrameProbed, this, [this](QVideoFrame frame) -> void {");

                frame.map(QAbstractVideoBuffer::ReadOnly);    // note: bug on frame.map(QAbstractVideoBuffer::ReadWrite);
                QImage image = QImage(frame.bits(), frame.width(), frame.height(), QImage::Format_ARGB32);
                QDateTime datetime = QDateTime::currentDateTime();
                QString timestamp = datetime.toString("yyyy-MM-ddThh:mm:ss.zzz");
                QPainter painter = QPainter(&image);
                QPen pen = QPen(Qt::white);
                painter.setPen(pen);
                painter.drawText(QPointF(4, image.height() - 4), timestamp);
                _ui->L_Video->setPixmap(QPixmap::fromImage(image.scaled(_ui->L_Video->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)));
                if(_snapshot == true) {
                    _snapshot = false;
                    QSound::play(":/musics/sounds/shutter.wav");
                    _ui->L_Frame->setPixmap(QPixmap::fromImage(image.scaled(_ui->L_Frame->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)));
                    _ui->L_Frame_Timestamp->setText(timestamp);
                }
                frame.unmap();
            });

            ////////////////////////////

            _recorder = new QMediaRecorder(_camera, this);
            QAudioEncoderSettings audio_settings = QAudioEncoderSettings();
            audio_settings.setCodec("audio/amr");
            audio_settings.setQuality(QMultimedia::HighQuality);
            _recorder->setAudioSettings(audio_settings);
            if(_ui->TB_Recorder_Volume->isHidden() == false) {
                _ui->TB_Recorder_Mute->click();
            } else {
                _ui->TB_Recorder_Volume->click();
            }
            QVideoEncoderSettings video_settings = QVideoEncoderSettings();
            video_settings.setCodec("video/mpeg2");
            video_settings.setResolution(_width, _height);
            video_settings.setQuality(QMultimedia::HighQuality);
            _recorder->setVideoSettings(video_settings);

            QObject::connect(_recorder, &QMediaRecorder::durationChanged, this, [this](qint64 duration) -> void {
                System::Logging("QObject::connect(_recorder, &QMediaRecorder::durationChanged, this, [this](qint64 duration) -> void {");

                System::Logging("duration = %d", duration);
                iptr tune = duration % 1000;
                iptr sec = (duration /= 1000) % 60;
                iptr min = (duration /= 60) % 60;
                iptr hour = (duration /= 60) % 24;
                _ui->L_Recorder_Timespan->setText(QString::asprintf("%02td:%02td:%02td.%03td", (iptr)hour, (iptr)min, (iptr)sec, (iptr)tune));
            });

            QObject::connect(_recorder, (void (QMediaRecorder::*)(QMediaRecorder::Error))&QMediaRecorder::error, this, [this](QMediaRecorder::Error error) -> void {
                System::Logging("QObject::connect(_recorder, (void (QMediaRecorder::*)(QMediaRecorder::Error))&QMediaRecorder::error, this, [this](QMediaRecorder::Error error) -> void {");

                _ui->L_Recorder_Status->setText(_Recorder_Error._Alias(error) + QString(": ") + _recorder->errorString());
                System::Logging("%s", _ui->L_Recorder_Status->text().toStdString().data());
            });

            QObject::connect(_recorder, &QMediaRecorder::stateChanged, this, [this](QMediaRecorder::State state) -> void {
                System::Logging("QObject::connect(_recorder, &QMediaRecorder::stateChanged, this, [this](QMediaRecorder::State state) -> void {");

                _ui->L_Recorder_Status->setText(_Recorder_State._Alias(state));
                System::Logging("%s", _ui->L_Recorder_Status->text().toStdString().data());
            });

            ////////////////////////////

            _ui->CB_Support_Recording->setChecked(_camera->isCaptureModeSupported(QCamera::CaptureVideo));
            _ui->CB_Support_Capturing->setChecked(_camera->isCaptureModeSupported(QCamera::CaptureStillImage));
            _ui->CB_Support_Exposure->setChecked(_camera->exposure()->isAvailable());
            _ui->CB_Support_Zooming->setChecked(_camera->focus()->isAvailable());
            if(_ui->TB_Camera_Open->isHidden() == false) {
                if(_camera == nullptr) {
                    return;
                }
                _camera->start();
                _ui->TB_Camera_Open->hide();
                _ui->TB_Camera_Close->show();
            }
        });
    }

    virtual ~Camera() {
        System::Logging(__FUNCTION__);
        Delete(_ui);
        _Destruct();
    }

    void _Setup() {
        System::Logging(__FUNCTION__);

    }

    void _Destruct() {
        System::Logging(__FUNCTION__);
        Delete(_camera);
        Delete(_probe);
        Delete(_recorder);
    }
};

#endif // Camera_h
