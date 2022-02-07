/* Notebook.h
Author: BSS9395
Update: 2022-02-08T00:24:00+08@China-Guangdong-Zhanjiang+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Notebook_h
#define Notebook_h

#define Header_h
#include "Common.h"
#include "ui_Editor.h"
#include "ui_Notebook.h"
#include "System.h"
#include "Toolkit.h"
#include "Ending.h"

class Editor : public QWidget {
    Q_OBJECT

public:
    static inline QMdiArea *_mdiarea = nullptr;
    static inline QTabBar *_tabbar = nullptr;

public:
    Ui::Editor *_ui = nullptr;
    QFileInfo _fileinfo = QFileInfo();
    bool _saved = false;

public:
    static iptr Index_SubWindow(QMdiSubWindow *window, QMdiArea::WindowOrder order = QMdiArea::CreationOrder) {
        QList<QMdiSubWindow *> windows = window->mdiArea()->subWindowList(order);
        iptr index = -1;
        for(auto beg = windows.begin(), end = windows.end(); beg < end; beg += 1) {
            index += 1;
            if((*beg) == window) {
                // System::Logging("index = %td", index);
                return index;
            }
        }
        return index;
    }

public:
    explicit Editor(QMdiArea *parent, const QIcon &icon = QIcon(), const QString &filename = QString("Untitled"), bool saved = false)
        : QWidget(parent), _ui(new Ui::Editor) {
        System::Logging(__FUNCTION__);

        _ui->setupUi(this);
        if(_mdiarea != parent) {
            _mdiarea = parent;
            _tabbar = _mdiarea->findChild<QTabBar *>();
            _tabbar->setExpanding(false);
        }

        _fileinfo = QFileInfo(filename);
        _saved = saved;
        this->setAttribute(Qt::WA_DeleteOnClose);

        QMdiSubWindow *window = _mdiarea->addSubWindow(this);
        window->setWindowIcon(icon);
        window->setWindowTitle(_fileinfo.fileName());
        QToolButton *close = new QToolButton(_tabbar);
        close->setStyleSheet((_saved == true) ? Style::_close_saved : Style::_close_unsaved);
        QObject::connect(close, &QToolButton::clicked, window, &QMdiSubWindow::close);
        _tabbar->setTabButton(Index_SubWindow(window), QTabBar::RightSide, close);

        ////////////////////////////////

        if(_saved == true) {
            QFile file(_fileinfo.filePath());
            if (file.open(QFile::ReadWrite)) {
                QTextStream stream(&file);
                stream.setCodec("UTF-8");
                _ui->TE_Editor->append(stream.readAll());
            }
        }

        this->show();
    }

    virtual ~Editor() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

};

class Notebook : public QMainWindow {
    Q_OBJECT

public:
    Ui::Notebook *_ui = nullptr;


    QStringList _supported = {
        "*.txt", "*.text",
        "*.md", "*.markdown",
        "*.*"
    };

public:
    explicit Notebook(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Notebook) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _ui->SB_Status->addWidget(_ui->GB_Status);

        this->setWindowIcon(QIcon(":/images/view_in_ar.png"));
        this->setWindowTitle(QString("记事本"));

        ////////////////////////////////////

        QObject::connect(_ui->A_New, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_New, &QAction::triggered, [this]() -> void {");

            new Editor(_ui->MA_Editor, QIcon(), QString("Untitled.text"), false);
        });

        QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {");

            QString caption = "打开";
            QString filter = "文本文件(*.txt *.text);; Markdown(*.md *.markdown);; 所有文件(*.*)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            if(0 < filename.size()) {
                 new Editor(_ui->MA_Editor, QIcon(), filename, true);
            }
        });

        ////////////////////////////////////

        QObject::connect(_ui->PB_Ending, &QPushButton::clicked, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Ending, &QPushButton::clicked, [this]() -> void {");

            Ending *ending = new Ending(_ui->PB_Ending, _ui->PB_Ending->text());
            QObject::connect(ending, &Ending::Update_Ending, [this](QString form) -> void {
                _ui->PB_Ending->setText(form);
            });
        });
    }

    virtual ~Notebook() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }
};

#endif // Notebook_h
