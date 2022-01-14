/* Explorer.cpp
Author: BSS9395
Update: 2022-01-15T01:30:00+08@China-Guangdong-Shenzhen+08
Design: File Explorer
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

File_System::File_System(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::File_System) {
    Logging(__FUNCTION__);

    _ui->setupUi(this);
    QModelIndex index = _model.setRootPath(QDir::currentPath());
    _ui->TV_File_System->setModel(&_model);
    _ui->LV_Folder->setModel(&_model);
    _ui->TV_Folder->setModel(&_model);
    _ui->TV_File_System->setRootIndex(index);
    _ui->LV_Folder->setRootIndex(index);
    _ui->TV_Folder->setRootIndex(index);
    _history.push_back(index); // note: initialized,
    _index = _history.begin(); // note: initialized, ensure 1<= _history.size().
    Enable_Direction();

    QObject::connect(_ui->TV_File_System, &QTreeView::doubleClicked, [this](QModelIndex index) -> void {
        Logging("QObject::connect(_ui->TV_File_System, &QTreeView::doubleClicked, [this](QModelIndex index) -> void {");

        _ui->TV_File_System->setRootIndex(index);
        auto snap = _index;
        if (++snap, snap != _history.end()) {
            _history.erase(snap, _history.end());
        }
        _history.push_back(index);
        ++_index;
        Enable_Direction();
    });

    QObject::connect(_ui->A_Upward, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Upward, &QAction::triggered, [this]() -> void {");

        QModelIndex parent = _ui->TV_File_System->rootIndex().parent();
        _ui->TV_File_System->setRootIndex(parent);
        auto snap = _index;
        if (++snap, snap != _history.end()) {
            _history.erase(snap, _history.end());
        }
        _history.push_back(parent);
        ++_index;
        Enable_Direction();
    });

    QObject::connect(_ui->A_Backward, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Backward, &QAction::triggered, [this]() -> void {");

        if (_index != _history.begin()) {
            --_index;
            _ui->TV_File_System->setRootIndex(*_index);
        }
        Enable_Direction();
    });

    QObject::connect(_ui->A_Forward, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Forward, &QAction::triggered, [this]() -> void {");

        auto snap = _index; // note: snapshot state, iterator doesn't have operations like +1 or +=1.
        if (++snap, snap != _history.end()) {
            ++_index;
            _ui->TV_File_System->setRootIndex(*_index);
        }
        Enable_Direction();
    });

    QObject::connect(_ui->TV_File_System, &QTreeView::clicked, [this](QModelIndex index) -> void {
        Logging("QObject::connect(_ui->TV_File_System, &QTreeView::clicked, [this](QModelIndex index) -> void {");

        _ui->LV_Folder->setRootIndex(index);
        _ui->TV_Folder->setRootIndex(index);

        iptr size = _model.size(index) / 1024.0;
        _ui->L_Filename->setText(_model.fileName(index));
        _ui->L_Size->setText(size < 1024.0 ? QString("%1 KB").arg(size) : QString("%1 MB").arg(size / 1024.0, 4, 'f', 2));
        _ui->L_Type->setText(_model.type(index));
        _ui->CB_Directory->setChecked(_model.isDir(index));
        _ui->L_Path->setText(_model.filePath(index));

        Enable_Direction();
    });

    QObject::connect(&timer, &QTimer::timeout, [this]() -> void {
        Logging("QObject::connect(&timer, &QTimer::timeout, [this]() -> void {");

        timer.stop();
        _ui->TV_Folder->resizeColumnsToContents();
        _ui->TV_Folder->resizeRowsToContents();
        // _ui->TV_File_System->expandAll();
        for (iptr col = 0, count = _ui->TV_File_System->header()->count(); col < count; col += 1) {
            _ui->TV_File_System->resizeColumnToContents(col);
        }
    });
}

File_System::~File_System() {
    Logging(__FUNCTION__);

    delete _ui;
}

void File_System::Enable_Direction(iptr milli) {
    Logging(__FUNCTION__);

    static auto null_index = QModelIndex();
    _ui->A_Upward->setEnabled(_ui->TV_File_System->rootIndex() != null_index);
    _ui->A_Backward->setEnabled(_index != _history.begin());
    auto snap = _index; ++snap;
    _ui->A_Forward->setEnabled(snap != _history.end());
    timer.start(milli);
}
