/* Qt6_QMediaPlayer.h
Author: BSS9395
Update: 2023-08-30T09:39:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QMEDIAPLAYER_H
#define QT6_QMEDIAPLAYER_H

#include <QMainWindow>
#include "ui_Qt6_QMediaPlayer.h"
#include <QtMultimedia>
#include <QtMultimediaWidgets>

class Qt6_QMediaPlayer : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QMediaPlayer *_ui = nullptr;
    QMediaPlayer *_player = nullptr;
    bool _manual = false;
    QTimer _loop_caption = QTimer();

public:
    Qt6_QMediaPlayer(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QMediaPlayer) {
        qDebug() << __FUNCTION__;
        _ui->setupUi(this);

        _ui->S_Progress->setTracking(false);
        _ui->LW_List->installEventFilter(this);
        _ui->LW_List->setDragEnabled(true);
        _ui->LW_List->setDragDropMode(QAbstractItemView::InternalMove);
        _player = new QMediaPlayer(this);
        _player->setAudioOutput(new QAudioOutput());

        QObject::connect(_ui->A_Add, &QAction::triggered, this, [this]() -> void {
            qDebug() << "QObject::connect(_ui->A_Add, &QAction::triggered, this, [this]() -> void {";
            QString caption = "选择音频文件";
            QString dir = QDir::currentPath();
            QString filter = "音频文件(*.mp3 *.wav *.wma);;所有文件(*.*)";
            QStringList filenames = QFileDialog::getOpenFileNames(this, caption, dir, filter);
            if(filenames.size() < 1) {
                return ;
            }

            for(int i = 0; i < filenames.size(); i += 1) {
                QString filename = filenames.at(i);
                QFileInfo fileinfo = QFileInfo(filename);
                QListWidgetItem *item = new QListWidgetItem(fileinfo.fileName());
                item->setIcon(QIcon(":/images/icons/baseline_music_note.png"));
                item->setData(Qt::UserRole, QUrl(filename));
                _ui->LW_List->addItem(item);
            }
        });

        QObject::connect(_ui->A_Remove, &QAction::triggered, this, [this]() -> void {
            if(0 <= _ui->LW_List->currentRow()) {
                if(_player->source() == _ui->LW_List->currentItem()->data(Qt::UserRole).value<QUrl>()) {
                    _manual = true;
                    _player->stop();
                    _manual = false;
                }

                QListWidgetItem *item = _ui->LW_List->takeItem(_ui->LW_List->currentRow());
                delete item;
            }
        });

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            qDebug() << "QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {";
            _manual = true;
            _ui->LW_List->clear();
            _player->stop();
            _manual = false;
        });


        QObject::connect(_ui->LW_List, &QListWidget::doubleClicked, this, [this](const QModelIndex &index) -> void {
            if(_ui->LW_List->currentRow() < 0) {
                return ;
            }
            _manual = true;
            _ui->LW_List->setCurrentRow(index.row());
            QUrl url = _ui->LW_List->item(index.row())->data(Qt::UserRole).value<QUrl>();
            _player->setSource(url);
            _player->play();
            _manual = false;
        });

        QObject::connect(_ui->TB_Play, &QToolButton::clicked, this, [this]() -> void {
            _manual = true;
            _player->play();
            _manual = false;
        });
        QObject::connect(_ui->TB_Pause, &QToolButton::clicked, this, [this]() -> void{
            _manual = true;
            _player->pause();
            _manual = false;
        });
        _ui->TB_Play->show();
        _ui->TB_Pause->hide();


        QObject::connect(_ui->TB_Previous, &QToolButton::clicked, this, [this]() -> void {
            _manual = true;
            if(1 <= _ui->LW_List->count()) {
                int row = (_ui->LW_List->currentRow() - 1 + _ui->LW_List->count()) % _ui->LW_List->count();
                _ui->LW_List->setCurrentRow(row);
                QUrl url = _ui->LW_List->currentItem()->data(Qt::UserRole).value<QUrl>();
                _player->setSource(url);
                _player->play();
            }
            _manual = false;
        });

        QObject::connect(_ui->TB_Next, &QToolButton::clicked, this, [this]() -> void {
            _manual = true;
            if(1 <= _ui->LW_List->count()) {
                int row = (_ui->LW_List->currentRow() + 1) % _ui->LW_List->count();
                _ui->LW_List->setCurrentRow(row);
                QUrl url = _ui->LW_List->currentItem()->data(Qt::UserRole).value<QUrl>();
                _player->setSource(url);
                _player->play();
            }
            _manual = false;
        });

        QObject::connect(_ui->DSB_Rate, &QDoubleSpinBox::valueChanged, this, [this](double value) -> void {
            _player->setPlaybackRate(value);
        });

        QObject::connect(_ui->TB_Loop, &QToolButton::clicked, this, [this]() -> void {
            _ui->TB_Loop->hide();
            _ui->TB_Loop_One->show();
        });
        QObject::connect(_ui->TB_Loop_One, &QToolButton::clicked, this, [this]() -> void{
            _ui->TB_Loop->show();
            _ui->TB_Loop_One->hide();
        });
        _ui->TB_Loop->show();
        _ui->TB_Loop_One->hide();


        QObject::connect(_ui->TB_Volumn, &QToolButton::clicked, this, [this]() -> void {
            _ui->TB_Volumn->hide();
            _ui->TB_Mute->show();
            _player->audioOutput()->setMuted(true);
        });
        QObject::connect(_ui->TB_Mute, &QToolButton::clicked, this, [this]() -> void{
            _ui->TB_Volumn->show();
            _ui->TB_Mute->hide();
            _player->audioOutput()->setMuted(false);
        });
        QObject::connect(_ui->S_Volume, &QSlider::valueChanged, this, [this](int value) -> void {
            _player->audioOutput()->setVolume(value / 100.0);
            if(value <= 0) {
                _ui->TB_Volumn->hide();
                _ui->TB_Mute->show();
            } else {
                _ui->TB_Volumn->show();
                _ui->TB_Mute->hide();
            }
        });
        _ui->TB_Mute->hide();
        _ui->S_Volume->setRange(0, 100);
        _ui->S_Volume->setValue(50);


        QObject::connect(_ui->S_Progress, &QSlider::valueChanged, this, [this](int value) -> void {
            // qDebug() << "QObject::connect(_ui->S_Progress, &QSlider::valueChanged, this, [this](int value) -> void {";

            _player->setPosition(value);
        });

        QObject::connect(_player, &QMediaPlayer::sourceChanged, this, [this](const QUrl &media) -> void{
            _ui->L_Entry->setText(media.fileName() + "        ");
        });

        QObject::connect(_player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState newState) -> void{
            qDebug() << "QObject::connect(_player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState newState) -> void{";

            _ui->TB_Play->setVisible(newState != QMediaPlayer::PlayingState);
            _ui->TB_Pause->setVisible(newState == QMediaPlayer::PlayingState);

            if(_manual == false && newState == QMediaPlayer::StoppedState && 1 <= _ui->LW_List->count()) {
                _ui->S_Progress->blockSignals(true);
                if(_ui->TB_Loop->isVisible()) {
                    int row = (_ui->LW_List->currentRow() + 1) % _ui->LW_List->count();
                    _ui->LW_List->setCurrentRow(row);
                    QUrl url = _ui->LW_List->currentItem()->data(Qt::UserRole).value<QUrl>();
                    _player->setSource(url);
                    _player->play();
                } else if(_ui->TB_Loop_One->isVisible()) {
                    _player->play();
                }
                _ui->S_Progress->blockSignals(false);
            }
        });

        QObject::connect(_player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) -> void {
            _ui->S_Progress->setRange(0, duration);

            // int tune = duration % 1000;
            int sec = (duration /= 1000) % 60;
            int min = (duration /= 60 ) % 60;
            int hour = (duration /= 60) % 24;
            _ui->L_Duration->setText(QString::asprintf("%02d:%02d:%02d", hour, min, sec));
        });

        QObject::connect(_player, &QMediaPlayer::positionChanged, this, [this](qint64 position) -> void {
            if (_ui->S_Progress->isSliderDown()) {
                return;
            }
            _ui->S_Progress->setSliderPosition(position);

            // int tune = position % 1000;
            int sec = (position /= 1000) % 60;
            int min = (position /= 60 ) % 60;
            int hour = (position /= 60) % 24;
            _ui->L_Progress->setText(QString::asprintf("%02d:%02d:%02d", hour, min, sec));
        });

        QObject::connect(&_loop_caption, &QTimer::timeout, this, [this]() -> void {
            QString entry = _ui->L_Entry->text();;
            entry = entry.mid(1) + entry[0];
            _ui->L_Entry->setText(entry);
        });
        _ui->L_Entry->setText(QString("音乐曲目") + "        ");
        _loop_caption.start(1000);
    }

    ~Qt6_QMediaPlayer() {
        qDebug() << __FUNCTION__;
        delete _ui;
        delete _player;
    }

public:
    bool eventFilter(QObject *watched, QEvent *event) {
        if(event->type() == QEvent::KeyPress && static_cast<QKeyEvent *>(event)->key() == Qt::Key_Delete) {
            if(watched == _ui->LW_List && 0 <= _ui->LW_List->currentRow()) {
                QListWidgetItem *item = _ui->LW_List->takeItem(_ui->LW_List->currentRow());
                delete item;
            }
            return true;
        }
        return QMainWindow::eventFilter(watched, event);
    }
};

#endif // QT6_QMEDIAPLAYER_H
