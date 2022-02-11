/* Canvas.cpp
Author: BSS9395
Update: 2022-02-12T02:12:00+08@China-Guangdong-Shenzhen+08
Design: Canvas
Encode: UTF-8
System: Qt 5.14.2
*/

#include "Common.h"

Canvas::Canvas(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::Canvas) {
    System::Logging(__FUNCTION__);
    _ui->setupUi(this);
    _ui->SB_Status->addWidget(_ui->GB_Status);
    this->setWindowIcon(QIcon(":/images/view_in_ar.png"));
    this->setWindowTitle(QString("画布"));

    _ui->TW_Picture->clear();
    QObject::connect(_ui->A_Scan, &QAction::triggered, [this]() -> void {
        System::Logging("QObject::connect(_ui->A_Scan, &QAction::triggered, [this]() -> void {");

        QString directory = QFileDialog::getExistingDirectory(this, "挂载目录", QDir::currentPath(), QFileDialog::ShowDirsOnly);
        if (0 < directory.size()) {
            directory += '/';
            QStringList filenames = QDir(directory, "*.png;;*.jpg").entryList(QDir::Files);
            QTreeWidgetItem *folder = Attach_Folder(_ui->TW_Picture, directory);
            Attach_Files(folder, directory, filenames, _hitted = _Enum_Relative);
            _ui->TW_Picture->expandAll();
        }
    });

    QObject::connect(_ui->A_Mount, &QAction::triggered, [this]() -> void {
        System::Logging("QObject::connect(_ui->A_Mount, &QAction::triggered, [this]() -> void {");

        QStringList filenames = QFileDialog::getOpenFileNames(this, "挂载图片", QDir::currentPath(), "图像文件(*.png *.jpg);;所有文件(*.*)");
        if (0 < filenames.size()) {
            QString directory = filenames[0].left(filenames[0].lastIndexOf('/') + 1);
            QTreeWidgetItem *folder = Attach_Folder(_ui->TW_Picture, directory);
            Attach_Files(folder, directory, filenames, _hitted = _Enum_Absolute);
            _ui->TW_Picture->expandAll();
        }
    });

    QObject::connect(_ui->A_Unmount, &QAction::triggered, [this]() -> void {
        QTreeWidgetItem *node = _ui->TW_Picture->currentItem();
        if (node != nullptr) {
            QTreeWidgetItem *parent = node->parent();
            if (parent == nullptr) { // top level item
                _ui->TW_Picture->takeTopLevelItem(_ui->TW_Picture->indexOfTopLevelItem(node));
            } else {
                parent->removeChild(node);
            }
            delete node;
        }
    });

    _ui->L_Picture->setPixmap(_pixmap);
    QObject::connect(_ui->TW_Picture, &QTreeWidget::currentItemChanged, [this](QTreeWidgetItem *current, QTreeWidgetItem *previous) -> void {
        (void)previous;
        if (current != nullptr) {
            QString filename = current->data(_Enum_Path, Qt::UserRole).toString();
            _ui->L_Path->setText(filename);

            iptr type = current->type();
            if (type == _Enum_File) {
                _pixmap.load(filename);
                _scale = 1.0;
                _ui->L_Picture->setPixmap(_pixmap);
            }
        }
    });

    QObject::connect(_ui->A_Actual_Size, &QAction::triggered, [this]() -> void {
        _scale = 1.0;
        _ui->L_Picture->setPixmap(_pixmap);
    });

    QObject::connect(_ui->A_Zoom_In, &QAction::triggered, [this]() -> void {
        _scale *= 1.1;
        iptr width = _scale * _pixmap.width();
        iptr height = _scale * _pixmap.height();
        QPixmap pixmap = _pixmap.scaled(width, height);
        _ui->L_Picture->setPixmap(pixmap);
    });

    QObject::connect(_ui->A_Zoom_Out, &QAction::triggered, [this]() -> void {
        _scale /= 1.1;
        iptr width = _scale * _pixmap.width();
        iptr height = _scale * _pixmap.height();
        QPixmap pixmap = _pixmap.scaled(width, height);
        _ui->L_Picture->setPixmap(pixmap);
    });

    QObject::connect(_ui->A_Fit_Height, &QAction::triggered, [this]() -> void {
        iptr height = _ui->SA_Picture->height();
        _scale = (double)height / (double)_pixmap.height();
        QPixmap pixmap = _pixmap.scaledToHeight(height);
        _ui->L_Picture->setPixmap(pixmap);
    });

    QObject::connect(_ui->A_Fit_Width, &QAction::triggered, [this]() -> void {
        iptr width = _ui->SA_Picture->width();
        _scale = (double)width / (double)_pixmap.width();
        QPixmap pixmap = _pixmap.scaledToWidth(width);
        _ui->L_Picture->setPixmap(pixmap);
    });

    QObject::connect(_ui->A_Update_Theme, &QAction::triggered, [this]() -> void {
        System::Logging("QObject::connect(_ui->A_Update_Theme, &QAction::triggered, [this]() -> void {");

        QString caption = "选择颜色";
        QColor color = _ui->L_Picture->palette().color(QPalette::Window);
        color = QColorDialog::getColor(color, this, caption);
        if(color.isValid()){
            QString css = QString("QLabel {\n    background-color: rgba(%1, %2, %3, %4); \n}")
                              .arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha() / 255);
            _ui->L_Picture->setStyleSheet(css);
        }
    });

}

Canvas::~Canvas() {
    System::Logging(__FUNCTION__);

    delete _ui;
}

// pointer can do anything, but reference can't.
QTreeWidgetItem *Canvas::Traverse(QTreeWidget *widget, QTreeWidgetItem *tree, const QChar *directory, iptr &hitted) {
    System::Logging(__FUNCTION__);

    if (tree != nullptr) {
        QString relative = tree->text(_Enum_Path);
        QChar *folder = relative.data();
        int last = 0;
        int idx = 0;
        for (; folder[idx] != '\0' && directory[idx] != '\0' && folder[idx] == directory[idx]; idx += 1) {
            if (folder[idx] == '/') {
                last = idx + 1;
            }
        }
        if (last == 0) {
            return nullptr;
        } else if (folder[idx] == '\0' && directory[idx] == '\0') {
            hitted += 1;
            return tree;
        } else if (folder[idx] != '\0' && directory[idx] == '\0') {
            QTreeWidgetItem *node = new QTreeWidgetItem(_Enum_Folder);
            node->setText(_Enum_Path, QString(&folder[0], last));
            QTreeWidgetItem *parent = tree->parent();
            if (parent == nullptr) { // top level item
                widget->takeTopLevelItem(widget->indexOfTopLevelItem(tree));
                tree->setText(_Enum_Path, QString(&folder[last]));
                node->addChild(tree);
                widget->addTopLevelItem(node);
            } else {
                parent->removeChild(tree);
                tree->setText(_Enum_Path, QString(&folder[last]));
                node->addChild(tree);
                parent->addChild(node);
            }
            return node;
        } else if (folder[idx] != '\0' && directory[idx] != '\0') {
            QTreeWidgetItem *node = new QTreeWidgetItem(_Enum_Folder);
            node->setIcon(_Enum_Path, _Icon_Folder);
            node->setText(_Enum_Path, QString(&folder[0], last));
            QString data = tree->data(_Enum_Path, Qt::UserRole).toString();
            node->setData(_Enum_Path, Qt::UserRole, data.chopped(relative.size() - last)); // absolute
            node->setText(_Enum_Type, "folder");
            QTreeWidgetItem *sibling = new QTreeWidgetItem(_Enum_Folder);
            sibling->setText(_Enum_Path, QString(&directory[last]));
            QTreeWidgetItem *parent = tree->parent();
            if (parent == nullptr) {
                widget->takeTopLevelItem(widget->indexOfTopLevelItem(tree));
                tree->setText(_Enum_Path, QString(&folder[last]));
                node->addChild(tree);
                node->addChild(sibling);
                widget->addTopLevelItem(node);
            } else {
                parent->removeChild(tree);
                tree->setText(_Enum_Path, QString(&folder[last]));
                node->addChild(tree);
                node->addChild(sibling);
                parent->addChild(node);
            }
            return sibling;
        } else { // if (folder[idx] == '\0' && directory[idx] != '\0')
            // recursively
            for (iptr i = 0, count = tree->childCount(); i < count; i += 1) {
                QTreeWidgetItem *node = Traverse(widget, tree->child(i), &directory[idx], hitted);
                if (node != nullptr) {
                    return node;
                }
            }
            QTreeWidgetItem *node = new QTreeWidgetItem(_Enum_Folder);
            node->setText(_Enum_Folder, QString(&directory[idx]));
            tree->addChild(node);
            return node;
        }
    }
    return nullptr;
}

QTreeWidgetItem *Canvas::Attach_Folder(QTreeWidget *widget, const QString &directory, iptr &hitted) {
    System::Logging(__FUNCTION__);

    hitted = 0;
    QTreeWidgetItem *folder = nullptr;
    for (iptr i = 0, count = widget->topLevelItemCount(); i < count; i += 1) {
        folder = Traverse(widget, widget->topLevelItem(i), directory.data(), hitted);
        if (folder != nullptr) {
            break;
        }
    }
    if (folder == nullptr) {
        folder = new QTreeWidgetItem(_Enum_Folder);
        folder->setText(_Enum_Path, directory);
        widget->addTopLevelItem(folder);
    }
    if (hitted <= 0) {
        folder->setIcon(_Enum_Path, _Icon_Folder);
        folder->setData(_Enum_Path, Qt::UserRole, directory);
        folder->setText(_Enum_Type, "folder");
    }
    return folder;
}

iptr Canvas::Attach_Files(QTreeWidgetItem *folder, const QString &directory, const QStringList &filenames, iptr &hitted) {
    System::Logging(__FUNCTION__);

    // ToDo: check duplicated.
    iptr attached = 0;
    if (hitted == _Enum_Absolute) {
        hitted = 0;
        iptr sepa = directory.size();
        for (iptr i = 0, numb = filenames.size(); i < numb; i += 1) {
            QTreeWidgetItem *file = new QTreeWidgetItem(_Enum_File);
            file->setIcon(_Enum_Path, _Icon_Image);
            file->setText(_Enum_Path, filenames[i].mid(sepa));
            file->setData(_Enum_Path, Qt::UserRole, filenames[i]);
            file->setText(_Enum_Type, filenames[i].mid(filenames[i].lastIndexOf('.') + 1));
            folder->addChild(file);
            attached += 1;
        }
    } else if (hitted == _Enum_Relative) {
        hitted = 0;
        for (iptr i = 0, numb = filenames.size(); i < numb; i += 1) {
            QTreeWidgetItem *file = new QTreeWidgetItem(_Enum_File);
            file->setIcon(_Enum_Path, _Icon_Image);
            file->setText(_Enum_Path, filenames[i]);
            file->setData(_Enum_Path, Qt::UserRole, directory + filenames[i]);
            file->setText(_Enum_Type, filenames[i].mid(filenames[i].lastIndexOf('.') + 1));
            folder->addChild(file);
            attached += 1;
        }
    } else {
        Exception::Excepting(true, System::_Info, "an unknown mode", "choose a mode");
    }
    return attached;
}
