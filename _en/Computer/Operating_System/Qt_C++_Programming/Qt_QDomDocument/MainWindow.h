#pragma once

#include <QDebug>
#include <QMainWindow>
#include <QString>
#include <QTreeWidget>
#include <QMenu>
#include <QFileDialog>
#include <QCoreApplication>
#include <QApplication>
#include <QStatusBar>
#include <QDesktopServices>
#include <QMenu>
#include <QScreen>
#include <QMenuBar>
#include <QClipboard>
#include <QWindow>
#include <QMessageBox>
#include <QHeaderView>
#include <QDomDocument>
#include <QContextMenuEvent>

Q_DECLARE_METATYPE(QDomElement)    // 注册类型信息进Qt事件循环，使用在QVariant::fromValue()

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr)
        : QMainWindow(parent) {
        this->setWindowTitle("DOM Bookmarks");

        ////////////////////////////////////////////////////////////////////////

        QMenu* menu_file = this->menuBar()->addMenu("&File");
        menu_file->addAction("&Open...", this, [this]() {
            _Open("");
        }, QKeySequence::Open);    // 在菜单项目的右侧添加[Ctrl+O]
        menu_file->addAction("&Save As...", this, [this]() {
            _SaveAs();
        }, QKeySequence::SaveAs);
        menu_file->addAction("&Exit", this, [this]() {
            this->close();
        }, QKeySequence::Quit);
        this->menuBar()->addSeparator();
        QMenu* menu_help = this->menuBar()->addMenu("&Help");
        menu_help->addAction("&About", this, [this]() {
            _About();
        });
        menu_help->addAction("About &Qt", QApplication::instance(), &QApplication::aboutQt);

        ////////////////////////////////////////////////////////////////////////

        _icon_folder.addPixmap(QPixmap(":/images/folder_closed.svg"), QIcon::Normal, QIcon::Off);
        _icon_folder.addPixmap(QPixmap(":/images/folder_open.svg"), QIcon::Normal, QIcon::On);
        _icon_bookmark.addPixmap(this->style()->standardPixmap(QStyle::SP_FileIcon), QIcon::Normal, QIcon::On);
        // this->style()->standardPixmap(QStyle::SP_FileIcon).save("sp_fileicon.png", "PNG");

        ////////////////////////////////////////////////////////////////////////

        _treewidget = new QTreeWidget(this);
        this->setCentralWidget(_treewidget);
        _treewidget->header()->setSectionResizeMode(QHeaderView::Stretch);
        _treewidget->setHeaderLabels(QStringList() << "Title" << "Location");        
        QObject::connect(_treewidget, &QTreeWidget::itemChanged, this, &MainWindow::_Update_DomElement);

        ////////////////////////////////////////////////////////////////////////

        _Open(":/resources/jennifer.xbel");
    }

public:
    void resizeEvent(QResizeEvent* event) override {
        (void)event;
        if(_inited == false) {
            _inited = true;
            QScreen* screen  = this->windowHandle()->screen();
            QRect geometry = screen->availableGeometry();
            this->resize(geometry.width() / 2, geometry.height() / 3);
            this->move(geometry.x() + (geometry.width() - this->width()) / 2, geometry.y() + (geometry.height() - this->height()) / 2);
        }
    }

    void contextMenuEvent(QContextMenuEvent* event) override {
        qDebug().nospace() << __FUNCTION__;
        QPoint pos = _treewidget->mapFrom(this, event->pos());
        QTreeWidgetItem* item = _treewidget->itemAt(pos);
        if(item == nullptr) {
            return;
        }
        QString url = item->text(1);
        QMenu menu;
        QAction* action_copy = menu.addAction("Copy Link to Clipboard");
        QAction* action_open = menu.addAction("Open");
        QAction* action_exec = menu.exec(event->globalPos());
        if(action_exec == action_copy) {
            QGuiApplication::clipboard()->setText(url);
        } else if(action_exec == action_open) {
            QDesktopServices::openUrl(QUrl(url));
        }
    }

public:
    void _Parse_Xbel(QDomElement element, QTreeWidgetItem* parent) {
        while(element.isNull() == false) {
            if(element.tagName() == "folder") {
                QTreeWidgetItem* item_folder = (parent == nullptr) ? new QTreeWidgetItem(_treewidget) : new QTreeWidgetItem(parent);
                item_folder->setData(0, Qt::UserRole + 1, QVariant::fromValue(element));
                QDomElement element_folder_title = element.firstChildElement("title");
                item_folder->setFlags(item_folder->flags() | Qt::ItemIsEditable);
                item_folder->setIcon(0, _icon_folder);
                item_folder->setText(0, element_folder_title.text());
                bool folder_folded = QString::compare(element.attribute("folded"), "Yes", Qt::CaseInsensitive);
                item_folder->setExpanded(folder_folded);


                QDomElement element_child = element_folder_title.nextSiblingElement();
                if(element_child.isNull() == false) {
                    _Parse_Xbel(element_child, item_folder);
                }
            } else if(element.tagName() == "bookmark") {
				QTreeWidgetItem* item_bookmark = (parent == nullptr) ? new QTreeWidgetItem(_treewidget) : new QTreeWidgetItem(parent);
				item_bookmark->setData(0, Qt::UserRole + 1, QVariant::fromValue(element));
                QDomElement element_bookmark_title = element.firstChildElement("title");
                item_bookmark->setFlags(item_bookmark->flags() | Qt::ItemIsEditable);
                item_bookmark->setIcon(0, _icon_bookmark);
                item_bookmark->setText(0, element_bookmark_title.text());
                item_bookmark->setText(1, element.attribute("href"));
            } else if(element.tagName() == "separator") {
				QTreeWidgetItem* item_separator = (parent == nullptr) ? new QTreeWidgetItem(_treewidget) : new QTreeWidgetItem(parent);
				item_separator->setData(0, Qt::UserRole + 1, QVariant::fromValue(element));
                item_separator->setFlags(item_separator->flags() & ~(Qt::ItemIsSelectable | Qt::ItemIsEditable));
                item_separator->setText(0, QString(30, '-'));
            }
            element = element.nextSiblingElement();
        }
    }

public:
    void _Open(const QString& filepath_hold = "") {
        QString filepath = (filepath_hold != "") ? filepath_hold : QFileDialog::getOpenFileName(this, "Open Bookmark File", QCoreApplication::applicationDirPath(), "XBEL Files (*.xbel *.xml)");
        if(filepath.isEmpty() == true) {
            return;
        }
        QFile file(filepath);
        if(file.open(QFile::ReadOnly | QFile::Text) == false) {
            qDebug().nospace() << file.errorString();
            return;
        }

        ////////////////////////////////////////////////////////////////////////

        auto _Read = [this](QFile* file) -> bool {
            QString errorString = "";
            int errorLine = 0;
            int errorColumn = 0;
            if(_domDocument.setContent(file, true, &errorString, &errorLine, &errorColumn) == false) {
                qDebug().nospace() << QString("[%1:%2] %3").arg(errorLine).arg(errorColumn).arg(errorString);
                return false;
            }

            QDomProcessingInstruction domInstruction = _domDocument.firstChild().toProcessingInstruction();
            if(domInstruction.isNull() == false) {
                qDebug().nospace().noquote() << QString("[%1] %2").arg(domInstruction.nodeName()).arg(domInstruction.nodeValue());
            }

            QDomElement root = _domDocument.documentElement();
            if(root.tagName() != "xbel") {
                qDebug().nospace() << "The file is not an XBEL file.";
                return false;
            }

            _treewidget->clear();
            _treewidget->blockSignals(true);
            _Parse_Xbel(root.firstChildElement(), nullptr);
            _treewidget->blockSignals(false);
            return true;
        };

        if(_Read(&file) == false) {
            this->statusBar()->showMessage("File Loaded", 2000);
        }
    }

    void _SaveAs() {
        QString filepath = QFileDialog::getSaveFileName(this, "Save Bookmark File", QCoreApplication::applicationDirPath(), "XBEL Files (*.xbel *.xml)");
        if(filepath.isEmpty() == true) {
            return;
        }

        QFile file(filepath);
        if(file.open(QFile::WriteOnly | QFile::Text) == false) {
            qDebug().nospace() << file.errorString();
        }

        ////////////////////////////////////////////////////////////////////////

        auto _Write = [this](QFile* file) -> bool {
            const int indent = 4;
            QTextStream stream(file);
            _domDocument.save(stream, indent);
            return true;
        };

        if(_Write(&file) == false) {
            this->statusBar()->showMessage("File saved failed", 2000);
        }
    }

    void _About() {
        QString title = "About DOM Bookmarks";
        QString info = "The <b>DOM Bookmarks</b> example demonstrates how to use Qt's DOM classes to read and write XML documents.";
        QMessageBox::about(this, title, info);
    }

    void _Update_DomElement(const QTreeWidgetItem *item, int column) {
        qDebug().nospace() << __FUNCTION__ << ", column = " << column;
        QDomElement element = item->data(0, Qt::UserRole + 1).value<QDomElement>();
        if(element.isNull() == true) {
            return;
        }
        if(element.tagName() == "folder") {
            if(column == 0) {
                QDomElement element_title = element.firstChildElement("title");
                QDomText text_title = element_title.firstChild().toText();
                text_title.setNodeValue(item->text(column));
            }
        } else if(element.tagName() == "bookmark") {
            if(column == 0) {
                QDomElement element_title = element.firstChildElement("title");
                QDomText text_title = element_title.firstChild().toText();
                text_title.setNodeValue(item->text(column));
            } else if(column == 1) {
                element.setAttribute("href", item->text(column));
            }
        }

    }

private:
    bool _inited = false;
    QIcon _icon_folder;
    QIcon _icon_bookmark;
    QTreeWidget* _treewidget = nullptr;
    QDomDocument _domDocument;
};
