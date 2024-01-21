#ifndef QT6_SETDRAGENABLED_H
#define QT6_SETDRAGENABLED_H

#include <QMainWindow>
#include <ui_Qt6_setDragEnabled.h>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *_ui = nullptr;
    QAbstractItemView *_view = nullptr;

public:
    MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
        _ui->setupUi(this);

        _ui->LW_List->setAcceptDrops(true);
        _ui->LW_List->setDragDropMode(QAbstractItemView::DragDrop);  // NoDragDrop, DragOnly, DropOnly, DragDrop, InternalMove
        _ui->LW_List->setDragEnabled(true);
        _ui->LW_List->setDefaultDropAction(Qt::CopyAction);          // CopyAction, MoveAction, LinkAction, ActionMask, TargetMoveAction, IgnoreAction

        _ui->TW_Tree->setAcceptDrops(true);
        _ui->TW_Tree->setDragDropMode(QAbstractItemView::DragDrop);   // NoDragDrop, DragOnly, DropOnly, DragDrop, InternalMove
        _ui->TW_Tree->setDragEnabled(true);
        _ui->TW_Tree->setDefaultDropAction(Qt::CopyAction);           // CopyAction, MoveAction, LinkAction, ActionMask, TargetMoveAction, IgnoreAction

        _ui->TW_Table->setAcceptDrops(true);
        _ui->TW_Table->setDragDropMode(QAbstractItemView::DragDrop);  // NoDragDrop, DragOnly, DropOnly, DragDrop, InternalMove
        _ui->TW_Table->setDragEnabled(true);
        _ui->TW_Table->setDefaultDropAction(Qt::CopyAction);          // CopyAction, MoveAction, LinkAction, ActionMask, TargetMoveAction, IgnoreAction


        _ui->LW_List->installEventFilter(this);
        _ui->TW_Tree->installEventFilter(this);
        _ui->TW_Table->installEventFilter(this);


        QObject::connect(_ui->RB_QListWidget, &QRadioButton::clicked, this, [this]() -> void {
            _view = _ui->LW_List;
            _Show_Mode();
        });
        QObject::connect(_ui->RB_QTreeWidget, &QRadioButton::clicked, this, [this]() -> void {
            _view = _ui->TW_Tree;
            _Show_Mode();
        });
        QObject::connect(_ui->RB_QTableWidget, &QRadioButton::clicked, this, [this]() -> void {
            _view = _ui->TW_Table;
            _Show_Mode();
        });
        _view = _ui->LW_List;
        _ui->RB_QListWidget->click();

        QObject::connect(_ui->CB_AcceptDrops, &QCheckBox::clicked, this, [this](bool checked) -> void {
            _view->setAcceptDrops(checked);
        });
        QObject::connect(_ui->CB_DragEnabled, &QCheckBox::clicked, this, [this](bool checked) -> void {
            _view->setDragEnabled(checked);
        });

        QObject::connect(_ui->CB_DragDropMode, &QComboBox::currentIndexChanged, this, [this](int index) -> void {
            switch(index) {
            case 0:
                _view->setDragDropMode(QAbstractItemView::NoDragDrop);
                break;
            case 1:
                _view->setDragDropMode(QAbstractItemView::DragOnly);
                break;
            case 2:
                _view->setDragDropMode(QAbstractItemView::DropOnly);
                break;
            case 3:
                _view->setDragDropMode(QAbstractItemView::DragDrop);
                break;
            case 4:
                _view->setDragDropMode(QAbstractItemView::InternalMove);
                break;
            }
        });

        QObject::connect(_ui->CB_DefaultDropAction, &QComboBox::currentIndexChanged, this, [this](int index) -> void {
            switch (index) {
            case 0:
                _view->setDefaultDropAction(Qt::CopyAction);
                break;
            case 1:
                _view->setDefaultDropAction(Qt::MoveAction);
                break;
            case 2:
                _view->setDefaultDropAction(Qt::LinkAction);
                break;
            case 3:
                _view->setDefaultDropAction(Qt::ActionMask);
                break;
            case 4:
                _view->setDefaultDropAction(Qt::TargetMoveAction);
                break;
            case 5:
                _view->setDefaultDropAction(Qt::IgnoreAction);
                break;
            }
        });
    }

    void _Show_Mode() {
        int drag_drop_mode = 0;
        switch(_view->dragDropMode()) {
        case QAbstractItemView::NoDragDrop:
            drag_drop_mode = 0;
            break;
        case QAbstractItemView::DragOnly:
            drag_drop_mode = 1;
            break;
        case QAbstractItemView::DropOnly:
            drag_drop_mode = 2;
            break;
        case QAbstractItemView::DragDrop:
            drag_drop_mode = 3;
            break;
        case QAbstractItemView::InternalMove:
            drag_drop_mode = 4;
            break;
        };

        int default_drop_action = 0;
        switch(_view->defaultDropAction()) {
        case Qt::CopyAction:
            default_drop_action = 0;
            break;
        case Qt::MoveAction:
            default_drop_action = 1;
            break;
        case Qt::LinkAction:
            default_drop_action = 2;
            break;
        case Qt::ActionMask:
            default_drop_action = 3;
            break;
        case Qt::TargetMoveAction:
            default_drop_action = 4;
            break;
        case Qt::IgnoreAction:
            default_drop_action = 5;
            break;
        }

        _ui->CB_AcceptDrops->setChecked(_view->acceptDrops());
        _ui->CB_DragEnabled->setChecked(_view->dragEnabled());
        _ui->CB_DragDropMode->setCurrentIndex(drag_drop_mode);
        _ui->CB_DefaultDropAction->setCurrentIndex(default_drop_action);
    }

    ~MainWindow() {
        delete _ui;
    }

public:
    bool eventFilter(QObject *watched, QEvent *event) override {
        if(event->type() == QEvent::KeyPress) {
            QKeyEvent *key_event = static_cast<QKeyEvent *>(event);
            if(key_event->key() == Qt::Key_Delete) {
                if(watched == _ui->LW_List) {
                    QListWidgetItem *item = _ui->LW_List->takeItem(_ui->LW_List->currentRow());
                    delete item;
                } else if(watched == _ui->TW_Tree) {
                    QTreeWidgetItem *item = _ui->TW_Tree->currentItem();
                    if(item->parent() != nullptr) {
                        QTreeWidgetItem *parent = item->parent();
                        parent->removeChild(item);
                    } else {
                        int index = _ui->TW_Tree->indexOfTopLevelItem(item);
                        _ui->TW_Tree->takeTopLevelItem(index);
                    }
                    delete item;
                } else if(watched == _ui->TW_Table) {
                    QTableWidgetItem *item = _ui->TW_Table->takeItem(_ui->TW_Table->currentRow(), _ui->TW_Table->currentColumn());
                    delete item;
                }
            }
        }
        return QMainWindow::eventFilter(watched, event);
    }

};
#endif // QT6_SETDRAGENABLED_H
