/* Sketch.cpp
Author: BSS9395
Update: 2022-01-11T21:16:00+08@China-Guangdong-Shenzhen+08
Design: Sketch
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

Sketch::Sketch(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::Sketch) {
    Logging(__FUNCTION__);

    _ui->setupUi(this);

    _ui->TW_Picture->clear();
    QObject::connect(_ui->A_Scan, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Scan, &QAction::triggered, [this]() -> void {");

        QString directory = QFileDialog::getExistingDirectory(this, "挂载目录", QDir::currentPath());
        directory += '/';


    });

    QObject::connect(_ui->A_Mount, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Mount, &QAction::triggered, [this]() -> void {");

        QStringList filenames = QFileDialog::getOpenFileNames(this, "挂载图片", QDir::currentPath(), "图像文件(*.png *.jpg);;所有文件(*.*)");
        if(0 < filenames.size()) {
            iptr sepa = filenames[0].lastIndexOf('/') + 1;
            QString directory = QString(filenames[0].data(), sepa);
            QTreeWidgetItem *node = nullptr;
            bool hitted = false;
            for(iptr i = 0, count = _ui->TW_Picture->topLevelItemCount(); i < count; i += 1) {
                node = Traverse(_ui->TW_Picture->topLevelItem(i), directory.data(), hitted);
                if(node != nullptr) {
                    break;
                }
            }
            if(node == nullptr) {
                node = new QTreeWidgetItem(_Folder);
                node->setText(_Path, directory);
                _ui->TW_Picture->addTopLevelItem(node);
            }

            ////////////////////////////

            for(iptr i = 0, numb = filenames.size(); i < numb; i +=1) {
                QTreeWidgetItem *file = new QTreeWidgetItem(_File);
                file ->setText(_Path, filenames[i].mid(sepa));
                node->addChild(file);
            }
            _ui->TW_Picture->expandAll();
        }
        return ;
    });
}

Sketch::~Sketch() {
    Logging(__FUNCTION__);

    delete _ui;
}

// pointer can do anything, but reference can't.
QTreeWidgetItem *Sketch::Traverse(QTreeWidgetItem *tree, const QChar *directory, bool &hitted) {
    // Logging("QTreeWidgetItem *Sketch::Traverse(QTreeWidgetItem *tree, const QChar *directory, bool &hitted) {");

    if(tree != nullptr) {
        QString path = tree->text(_Path);
        QChar *folder = path.data();
        int last = 0;
        int idx = 0;
        for(; folder[idx] != '\0' && directory[idx] != '\0' && folder[idx] == directory[idx]; idx += 1) {
            if(folder[idx] == '/') {
                last = idx + 1;
            }
        }
        if(last == 0) {
            return nullptr;
        } else if(folder[idx] == '\0' && directory[idx] == '\0') {
            hitted = true;
            return tree;
        } else if(folder[idx] != '\0' && directory[idx] == '\0') {
            QTreeWidgetItem *node = new QTreeWidgetItem(_Folder);
            node->setText(_Path, QString(&directory[0]));
            QTreeWidgetItem *parent = tree->parent();
            if(parent == nullptr) { // top level item
                _ui->TW_Picture->takeTopLevelItem(_ui->TW_Picture->indexOfTopLevelItem(tree));
                tree->setText(_Path, QString(&folder[last]));
                node->addChild(tree);
                _ui->TW_Picture->addTopLevelItem(node);
            } else {
                parent->removeChild(tree);
                tree->setText(_Path, QString(&folder[last]));
                node->addChild(tree);
                parent->addChild(node);
            }
            return node;
        } else if(folder[idx] != '\0' && directory[idx] != '\0') {
            QTreeWidgetItem *node = new QTreeWidgetItem(_Folder);
            node->setText(_Path, QString(&folder[0], last));
            QTreeWidgetItem *sibling = new QTreeWidgetItem(_Folder);
            sibling->setText(_Path, QString(&directory[last]));
            QTreeWidgetItem *parent = tree->parent();
            if(parent == nullptr) {
                _ui->TW_Picture->takeTopLevelItem(_ui->TW_Picture->indexOfTopLevelItem(tree));
                tree->setText(_Path, QString(&folder[last]));
                node->addChild(tree);
                node->addChild(sibling);
                _ui->TW_Picture->addTopLevelItem(node);
            } else {
                parent->removeChild(tree);
                tree->setText(_Path, QString(&folder[last]));
                node->addChild(tree);
                node->addChild(sibling);
                parent->addChild(node);
            }
            return sibling;
        } else { // folder[idx] == '\0' && directory[idx] != '\0'
            // recursively
            for(iptr i = 0, count = tree->childCount(); i < count; i += 1) {
                QTreeWidgetItem *node = Traverse(tree->child(i), &directory[idx], hitted);
                if(node != nullptr) {
                    return node;
                }
            }
            QTreeWidgetItem *node = new QTreeWidgetItem(_Folder);
            node->setText(_Folder, QString(&directory[idx]));
            tree->addChild(node);
            return node;
        }
    }
    return nullptr;
}
