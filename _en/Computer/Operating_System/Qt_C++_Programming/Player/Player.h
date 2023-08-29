/* Player.h
Author: BSS9395
Update: 2022-07-20T02:00:00+08@China-Shanghai+08
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
#include "QVideoWidget_Frame.h"
#include "QVideoWidget_Handler.h"


class Player : public QMainWindow {
    Q_OBJECT

public:
    Ui::Player *_ui = nullptr;

public:
    explicit Player(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Player) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        QObject::connect(_ui->A_Add, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Add, &QAction::triggered, this, [this]() -> void {");

            QString caption = "添加视频文件";
            QString filter = "MP4视频(*.mp4);;WMV视频(*.wmv);;所有文件(*.*)";
            QStringList filepaths = QFileDialog::getOpenFileNames(this, caption, QDir::homePath(), filter);
            if(filepaths.size() < 1) {
                return;
            }
            for(auto beg = filepaths.begin(), end = filepaths.end(); beg != end; beg += 1) {
                QUrl url = QUrl(*beg);
                bool hitted = false;
                for(iptr idx = 0, count = _ui->VWF_Video->_play_list->mediaCount(); idx < count; idx += 1) {
                    //if(url == _ui->VWF_Video->_play_list->media(idx).request().url()) {
                    if(url == _ui->VWF_Video->_play_list->media(idx).canonicalUrl()) {
                        hitted = true;
                        break;
                    }
                }
                if(hitted == false) {
                    _ui->VWF_Video->_play_list->addMedia(url);
                    _ui->LW_List->addItem(url.fileName());
                }
            }
        });

        QObject::connect(_ui->A_Remove, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Remove, &QAction::triggered, this, [this]() -> void {");

            iptr idx = _ui->LW_List->currentRow();
            if(idx < 0) {
                return;
            }
            delete _ui->LW_List->takeItem(idx);
            if(_ui->VWF_Video->_play_list->currentIndex() == idx) {
                _ui->VWF_Video->_play_list->removeMedia(idx);
                iptr numb = _ui->LW_List->count();
                if(1 <= numb) {
                    idx = (idx - 1 + numb) % numb;
                    _ui->LW_List->setCurrentRow(idx);
                    _ui->VWF_Video->_play_list->setCurrentIndex(idx);
                }
            } else {
                _ui->VWF_Video->_play_list->removeMedia(idx);
            }
        });

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->LW_List->clear();
            _ui->VWF_Video->_play_list->clear();
        });

        QObject::connect(_ui->LW_List, &QListWidget::clicked, this, [this](QModelIndex index) -> void {
            System::Logging("QObject::connect(_ui->LW_List, &QListWidget::clicked, this, [this](QModelIndex index) -> void {");
            if(index.isValid() == false) {
                return;
            }
            _ui->VWF_Video->_play_list->setCurrentIndex(index.row());
        });

        QObject::connect(_ui->LW_List, &QListWidget::doubleClicked, this, [this](QModelIndex index) -> void {
            System::Logging("QObject::connect(_ui->LW_List, &QListWidget::doubleClicked, this, [this](QModelIndex index) -> void {");

            if(index.isValid() == false) {
                return ;
            }
            _ui->VWF_Video->_play_list->setCurrentIndex(index.row());
            _ui->VWF_Video->_ui->TB_Play->click();
        });

        ////////////////////////////////

        QUrl url = QUrl("qrc:///videos/Two_Black_Holes_Merge_into_One.mp4");
        _ui->LW_List->addItem(url.fileName());
        _ui->VWF_Video->_play_list->addMedia(url);
        _ui->VWF_Video->_play_list->setCurrentIndex(0);
        // _ui->VWF_Video->_ui->TB_Play->click();


        // _QGraphicsVideoItem();
    }

    virtual ~Player() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void _QGraphicsVideoItem() {
        System::Logging(__FUNCTION__);

        QGraphicsView *graphics = new QGraphicsView(this);
        _ui->F_Video->layout()->addWidget(graphics);
        graphics->setMaximumHeight(300);

        QMediaPlayer *player = new QMediaPlayer(this);
        player->setPlaylist(new QMediaPlaylist());
        QGraphicsScene *scene = new QGraphicsScene(this);
        graphics->setScene(scene);
        QGraphicsVideoItem *video = new QGraphicsVideoItem();
        scene->addItem(video);
        player->setVideoOutput(video);
        video->setFlags(QGraphicsVideoItem::ItemIsMovable | QGraphicsVideoItem::ItemIsSelectable | QGraphicsVideoItem::ItemIsFocusable);

        QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(0, 0, 100, 50);
        scene->addItem(ellipse);
        ellipse->setBrush(QBrush(Qt::green));
        ellipse->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
        QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 200, 100);
        scene->addItem(rect);
        rect->setPos(0, 0);
        rect->setBrush(QBrush(Qt::yellow));
        rect->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

        ////////////////////////////////

        QUrl url = QUrl("qrc:///videos/Two_Black_Holes_Merge_into_One.mp4");
        player->playlist()->addMedia(url);
        player->playlist()->setCurrentIndex(0);
        player->play();
    }

public:
    void moveEvent(QMoveEvent *event) override {
        System::Logging(__FUNCTION__);

        static int counter = 0;
        counter += 1;
        if(2 <= counter) {
            counter = 0;
            _ui->VWF_Video->moveEvent(event);  // note: bug
        }
        return QMainWindow::moveEvent(event);
    }
};

#endif // Player_h
