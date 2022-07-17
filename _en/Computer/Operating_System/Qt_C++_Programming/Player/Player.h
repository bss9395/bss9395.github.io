/* Player.h
Author: BSS9395
Update: 2022-07-14T01:54:00+08@China-Shanghai+08
Design: Player
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Player_h
#define Player_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Player.h"

class Player : public QMainWindow {
    Q_OBJECT

public:
    Ui::Player *_ui = nullptr;
    QMediaPlayer *_player = nullptr;
    iptr _volume = 50;

public:
    explicit Player(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Player) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _Setup();

        QObject::connect(_ui->A_Add, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Add, &QAction::triggered, this, [this]() -> void {");

            QString caption = "打开文件";
            QString filter = "mp4文件(*.mp4);;wmv文件(*.wmv);;所有文件(*.*)";
            QStringList filenames = QFileDialog::getOpenFileNames(this, caption, QDir::homePath(), filter);
            if(filenames.size() < 1) {
                return;
            }
            for(iptr row = 0, rows = filenames.count(); row < rows; row += 1) {
                QUrl url = QUrl(filenames[row]);
                bool hitted = false;
                for(iptr col = 0, cols = _player->playlist()->mediaCount(); col < cols; col += 1) {
                    if(url == _player->playlist()->media(col).request().url()) {
                        hitted = true;
                        break;
                    }
                }
                if(hitted == false) {
                    _player->playlist()->addMedia(url);
                    _ui->LW_List->addItem(url.fileName());
                }
            }
        });

        QObject::connect(_ui->A_Remove, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Remove, &QAction::triggered, this, [this]() -> void {");

            iptr index = _ui->LW_List->currentRow();
            delete _ui->LW_List->takeItem(index);
            if(_player->playlist()->currentIndex() == index) {
                _player->playlist()->removeMedia(index);
                iptr numb = _ui->LW_List->count();
                if(1 <= numb) {
                    index = (index - 1 + numb) % numb;
                    _ui->LW_List->setCurrentRow(index);
                    _player->playlist()->setCurrentIndex(index);
                }
            } else {
                _player->playlist()->removeMedia(index);
            }

            if(_player->playlist()->mediaCount() < 1) {
                _ui->A_Remove->setEnabled(false);
                _ui->A_Clear->setEnabled(false);
                _ui->GB_Panel->setEnabled(false);
            }
        });

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->LW_List->clear();
            _player->playlist()->clear();

            _ui->A_Remove->setEnabled(false);
            _ui->A_Clear->setEnabled(false);
            _ui->GB_Panel->setEnabled(false);
        });

        QObject::connect(_ui->LW_List, &QListWidget::doubleClicked, this, [this](QModelIndex index) -> void {
            System::Logging("QObject::connect(_ui->LW_List, &QListWidget::doubleClicked, this, [this](QModelIndex index) -> void {");

            if(index.isValid() == false) {
                return;
            }
            _player->playlist()->setCurrentIndex(index.row());
            _player->play();

            _ui->GB_Panel->setEnabled(true);
        });

        QObject::connect(_ui->TB_Play_Pause, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Play_Pause, &QToolButton::clicked, this, [this]() -> void {");

            if(_player->state() == QMediaPlayer::PlayingState) {
                _player->pause();
            } else {
                _player->play();
            }
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

        QObject::connect(_ui->TB_Zoom, &QToolButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->TB_Zoom, &QToolButton::clicked, this, [this]() -> void {");

            _ui->VW_Video->setFullScreen(true);
        });

        ////////////////////////////////

        QObject::connect(_ui->VW_Video, &QVideoWidget_Handler::_Mouse_Press, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->VW_Video, &QVideoWidget_Handler::_Mouse_Press, this, [this]() -> void {");

            _ui->TB_Play_Pause->click();
        });

        QObject::connect(_player, &QMediaPlayer::stateChanged, this, [this](QMediaPlayer::State state) -> void {
            System::Logging("QObject::connect(_player, &QMediaPlayer::stateChanged, this, [this](QMediaPlayer::State state) -> void {");

            if(state == QMediaPlayer::PlayingState) {
                _ui->TB_Play_Pause->setIcon(QIcon(":/images/icons/pause_circle.png"));
            } else {
                _ui->TB_Play_Pause->setIcon(QIcon(":/images/icons/play_circle.png"));
            }
        });

        QObject::connect(_player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) -> void {
            System::Logging("QObject::connect(_player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) -> void {");

            _ui->S_Progress->setRange(0, duration);
            duration /= 1000;
            iptr sec = duration % 60;
            iptr min = duration / 60 % 60;
            iptr hour = duration / 3600 % 24;
            _ui->L_Timelength->setText(QString::asprintf("%02td:%02td:%02td", hour, min, sec));
        });

        QObject::connect(_player, &QMediaPlayer::positionChanged, this, [this](qint64 position) -> void {
            System::Logging("QObject::connect(_player, &QMediaPlayer::positionChanged, this, [this](qint64 position) -> void {");

            _ui->S_Progress->setValue(position);
            position /= 1000;
            iptr sec = position % 60;
            iptr min = position / 60 % 60;
            iptr hour = position / 3600 % 24;
            _ui->L_Timestamp->setText(QString::asprintf("%02td:%02td:%02td", hour, min, sec));
        });
    }

    virtual ~Player() {
        System::Logging(__FUNCTION__);
        delete _ui;
        delete _player;
    }

    void _Setup() {
        System::Logging(__FUNCTION__);

        _ui->DW_List->setTitleBarWidget(new QWidget());

        _ui->S_Volume->setTracking(false);
        _ui->S_Volume->setRange(0, 100);
        _ui->S_Volume->setSingleStep(1);
        _ui->S_Volume->setValue(_volume);

        ////////////////////////////////

        _player = new QMediaPlayer(this);
        _player->setPlaylist(new QMediaPlaylist());
        _player->setVideoOutput(_ui->VW_Video);
        _player->setVolume(qRound(100 * QAudio::convertVolume(_ui->S_Volume->value() / qreal(100.0), QAudio::LogarithmicVolumeScale, QAudio::LinearVolumeScale)));

        ////////////////////////////////

//        _player = new QMediaPlayer(this);
//        _player->setPlaylist(new QMediaPlaylist());
//        QGraphicsScene *scene = new QGraphicsScene(this);
//        _ui->GV_Video->setScene(scene);
//        QGraphicsVideoItem *video = new QGraphicsVideoItem();
//        scene->addItem(video);
//        _player->setVideoOutput(video);
//        video->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsSelectable | QGraphicsVideoItem::ItemIsFocusable);
//        QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(0, 0, 100, 50);
//        scene->addItem(ellipse);
//        ellipse->setBrush(QBrush(Qt::green));
//        ellipse->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
//        QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 200, 100);
//        scene->addItem(rect);
//        rect->setPos(0, 0);
//        rect->setBrush(QBrush(Qt::yellow));
//        rect->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

        ////////////////////////////////

        QUrl url = QUrl("qrc:///videos/Two_Black_Holes_Merge_into_One.mp4");
        _ui->LW_List->addItem(url.fileName());
        _player->playlist()->addMedia(url);
        _ui->GB_Panel->setEnabled(false);
    }

public:
    virtual void showEvent(QShowEvent *event) override {
        System::Logging(__FUNCTION__);
        (void) event;

//        QWidget *parent = _ui->GB_Panel->parentWidget();
//        QPoint pos = parent->mapToGlobal(_ui->GB_Panel->pos());
//        _ui->GB_Panel->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
//        _ui->GB_Panel->show();
//        _ui->GB_Panel->move(pos);
    }

public:

};

#endif // Player_h
