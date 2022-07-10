/* Music.h
Author: BSS9395
Update: 2022-07-11T02:22:00+08@China-Shanghai+08
Design: Music
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Music_h
#define Music_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Music.h"

class Music : public QMainWindow {
    Q_OBJECT

public:
    struct : public Enume {
        Enume _CurrentItemOnce   = Enume(this, QMediaPlaylist::CurrentItemOnce  , ":/images/icons/looks_one.png");
        Enume _CurrentItemInLoop = Enume(this, QMediaPlaylist::CurrentItemInLoop, ":/images/icons/repeat_one.png");
        Enume _Sequential        = Enume(this, QMediaPlaylist::Sequential       , ":/images/icons/directions_alt.png");
        Enume _Loop              = Enume(this, QMediaPlaylist::Loop             , ":/images/icons/repeat.png");
        Enume _Random            = Enume(this, QMediaPlaylist::Random           , ":/images/icons/shuffle.png");
    } _PlaybackMode;

public:
    Ui::Music *_ui = nullptr;
    iptr _volume = 0;
    QMediaPlayer *_player = nullptr;

public:
    explicit Music(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Music) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup();

        ////////////////////////////////

        QObject::connect(_ui->TB_Add, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Add, &QToolButton::clicked, this, [this]() -> void {");

            QString caption = "选择音频文件";
            QString filter = "音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)";
            QStringList filenames = QFileDialog::getOpenFileNames(this, caption, QDir::homePath(), filter);
            if(filenames.count() < 1) {
                return;
            }
            for(iptr row = 0, rows = filenames.count(); row < rows; row += 1) {
                QUrl url = QUrl::fromLocalFile(filenames[row]);
                bool hitted = false;
                for(iptr col = 0, cols = _player->playlist()->mediaCount(); col < cols; col += 1) {
                    if(_player->playlist()->media(col).request().url() == url) {
                        hitted = true;
                        break;
                    }
                }
                if(hitted == true) {
                    continue;
                }
                _player->playlist()->addMedia(url);
                _ui->LW_Music->addItem(url.fileName());
            }
        });

        QObject::connect(_ui->TB_Remove, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Remove, &QToolButton::clicked, this, [this]() -> void {");

            iptr index = _ui->LW_Music->currentRow();
            delete _ui->LW_Music->takeItem(index);
            if(_player->playlist()->currentIndex() == index) {
                _player->playlist()->removeMedia(index);
                iptr numb = _ui->LW_Music->count();
                if(1 <= numb) {
                    index = (index - 1 + numb) % numb;
                    _ui->LW_Music->setCurrentRow(index);
                    _player->playlist()->setCurrentIndex(index);
                }
            } else {
                _player->playlist()->removeMedia(index);
            }
        });

        QObject::connect(_ui->TB_Clear, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Clear, &QToolButton::clicked, this, [this]() -> void {");

            _ui->LW_Music->clear();
            _player->playlist()->clear();
        });

        ////////////////////////////////

        QObject::connect(_player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) -> void {
            System::Logging("QObject::connect(_player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) -> void {");

            _ui->S_Progress->setRange(0, duration);
            _ui->S_Progress->setSingleStep(1);
            duration = duration / 1000;
            int sec = duration % 60;
            int min = duration / 60 % 60;
            _ui->L_Time_Total->setText(QString::asprintf("%02d:%02d", min, sec));
        });

        QObject::connect(_player, &QMediaPlayer::positionChanged, this, [this](qint64 position) -> void {
            System::Logging("QObject::connect(_player, &QMediaPlayer::positionChanged, this, [this](qint64 position) -> void {");

            if(_ui->S_Progress->isSliderDown() == true) {
                return;
            }
            _ui->S_Progress->setSliderPosition(position);
            position = position / 1000;
            int sec = position % 60;
            int min = position / 60 % 60;
            _ui->L_Time_Current->setText(QString::asprintf("%02d:%02d", min, sec));
        });

        QObject::connect(_ui->S_Progress, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Progress, &QSlider::valueChanged, this, [this](int value) -> void {");

            _player->setPosition(value);
        });

        QObject::connect(_player, &QMediaPlayer::stateChanged, this, [this](QMediaPlayer::State state) -> void {
            System::Logging("");

            if(state == QMediaPlayer::PlayingState) {
                _ui->TB_Play_Pause->setIcon(QIcon(":/images/icons/pause_circle.png"));
            } else {
                _ui->TB_Play_Pause->setIcon(QIcon(":/images/icons/play_circle.png"));
            }
        });

        QObject::connect(_player->playlist(), &QMediaPlaylist::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("");

            _ui->LW_Music->setCurrentRow(index);
            _ui->L_Name->setText(_player->playlist()->media(index).request().url().fileName());
        });

        ////////////////////////////////

        QObject::connect(_ui->LW_Music, &QListWidget::doubleClicked, this, [this](const QModelIndex &index) -> void {
            System::Logging("QObject::connect(_ui->LW_Music, &QListWidget::doubleClicked, this, [this](const QModelIndex &index) -> void {");

            if(index.isValid() == true) {
                _player->playlist()->setCurrentIndex(index.row());
                _player->play();
            }
        });

        QObject::connect(_ui->TB_Mode, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Mode, &QToolButton::clicked, this, [this]() -> void {");

            iptr index = _PlaybackMode._Index(_player->playlist()->playbackMode());
            index = (index + 1) % _PlaybackMode._index;
            _player->playlist()->setPlaybackMode((QMediaPlaylist::PlaybackMode)_PlaybackMode[index]._enume);
        });

        QObject::connect(_player->playlist(), &QMediaPlaylist::playbackModeChanged, this, [this](QMediaPlaylist::PlaybackMode mode) -> void {
            System::Logging("QObject::connect(_player->playlist(), &QMediaPlaylist::playbackModeChanged, this, [this](QMediaPlaylist::PlaybackMode mode) -> void {");

            _ui->TB_Mode->setIcon(QIcon(_PlaybackMode._Alias(mode)));
        });

        QObject::connect(_ui->TB_Play_Pause, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Play_Pause, &QToolButton::clicked, this, [this]() -> void {");

            if(_player->playlist()->currentIndex() < 0) {
                return ;
            }
            if(_player->state() == QMediaPlayer::PlayingState) {
                _player->pause();
            } else {
                _player->play();
            }
        });

        QObject::connect(_ui->TB_Previous, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Previous, &QToolButton::clicked, this, [this]() -> void {");

            if(_player->playlist()->mediaCount() < 1) {
                return;
            }

            iptr index = _player->playlist()->currentIndex();
            index = (index - 1 + _player->playlist()->mediaCount()) % _player->playlist()->mediaCount();
            _player->playlist()->setCurrentIndex(index);
            _player->play();
        });

        QObject::connect(_ui->TB_Next, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Next, &QToolButton::clicked, this, [this]() -> void {");

            if(_player->playlist()->mediaCount() < 1) {
                return;
            }

            iptr index = _player->playlist()->currentIndex();
            index = (index + 1) % _player->playlist()->mediaCount();
            _player->playlist()->setCurrentIndex(index);
            _player->play();
        });

        QObject::connect(_ui->TB_Volume, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Volume, &QToolButton::clicked, this, [this]() -> void {");

            if(_ui->S_Volume->value() <= 0) {
                _ui->S_Volume->setValue(_volume);
            } else {
                _volume = _ui->S_Volume->value();
                _ui->S_Volume->setValue(0);
            }
        });

        QObject::connect(_ui->S_Volume, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Volumn, &QSlider::valueChanged, this, [this](int value) -> void {");

            if(value <= 0) {
                _player->setMuted(true);
                _ui->TB_Volume->setIcon(QIcon(":/images/icons/volume_off.png"));
            } else {
                _player->setMuted(false);
                _ui->TB_Volume->setIcon(QIcon(":/images/icons/volume_up.png"));
                _player->setVolume(qRound(100 * QAudio::convertVolume(value / qreal(100.0), QAudio::LogarithmicVolumeScale, QAudio::LinearVolumeScale)));
            }
        });
    }

    virtual ~Music() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void _Setup() {
        _ui->S_Progress->setTracking(false);

        _ui->S_Volume->setTracking(false);
        _ui->S_Volume->setRange(0, 100);
        _ui->S_Volume->setSingleStep(1);
        _ui->S_Volume->setValue(50);

        _player = new QMediaPlayer(this);
        _player->setPlaylist(new QMediaPlaylist(this));
        _player->playlist()->setPlaybackMode((QMediaPlaylist::PlaybackMode)_PlaybackMode._Loop._enume);
        _player->setVolume(qRound(100 * QAudio::convertVolume(_ui->S_Volume->value() / qreal(100.0), QAudio::LogarithmicVolumeScale, QAudio::LinearVolumeScale)));
    }
};

#endif // Music_h
