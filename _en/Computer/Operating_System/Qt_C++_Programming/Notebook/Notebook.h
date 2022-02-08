/* Notebook.h
Author: BSS9395
Update: 2022-02-09T00:44:00+08@China-Guangdong-Zhanjiang+08
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

class Notebook : public QMainWindow {
    Q_OBJECT

public:
    static inline QStringList _supported = {
        "*.txt", "*.text",
        "*.md",  "*.markdown",
        "*.html",
        "*.*"
    };

public:
    Ui::Notebook *_ui = nullptr;

public:
    explicit Notebook(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Notebook) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _ui->TB_Minor->addWidget(_ui->GB_Font);
        _ui->SB_Status->addWidget(_ui->GB_Status);

        this->setWindowIcon(QIcon(":/images/view_in_ar.png"));
        this->setWindowTitle(QString("记事本"));

        ////////////////////////////////////

        QObject::connect(_ui->A_New, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_New, &QAction::triggered, [this]() -> void {");

            new Editor(this, _ui->MA_Editor, _None);
        });

        QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {");

            new Editor(this, _ui->MA_Editor, _Posi);
        });

        QObject::connect(_ui->A_Save, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Save, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Save();
        });

        QObject::connect(_ui->A_Save_As, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Save_As, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Save_As();
        });

        QObject::connect(_ui->A_Undo, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Undo, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Undo();
        });

        QObject::connect(_ui->A_Redo, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Redo, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Redo();
        });

        QObject::connect(_ui->A_Clear, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Clear();
        });

        QObject::connect(_ui->A_Cut, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Cut, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Cut();
        });

        QObject::connect(_ui->A_Copy, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Copy, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Copy();
        });

        QObject::connect(_ui->A_Paste, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Paste, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Paste();
        });

        QObject::connect(_ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Bold, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Bold(checked);
        });

        QObject::connect(_ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr) ((Editor *)window->widget())->Italic(checked);
        });

        QObject::connect(_ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if (window != nullptr) ((Editor *)window->widget())->Underline(checked);
        });

        QObject::connect(_ui->A_Strikeout, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Strikeout, &QAction::triggered, [this](bool checked) -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if (window != nullptr) ((Editor *)window->widget())->Strikeout(checked);
        });

        QObject::connect(_ui->FCB_Font, &QFontComboBox::currentFontChanged, [this](QFont font) -> void {
            System::Logging("QObject::connect(_ui->FCB_Font, &QFontComboBox::currentFontChanged, [this](QFont font) -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if (window != nullptr) ((Editor *)window->widget())->Font(font);
        });

        _ui->CB_Font_Size->setValidator(new QDoubleValidator());
        QObject::connect(_ui->CB_Font_Size, &QComboBox::editTextChanged, [this](QString size) -> void {
            System::Logging("QObject::connect(_ui->CB_Font_Size, &QComboBox::currentTextChanged, [this](QString size) -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if (window != nullptr) ((Editor *)window->widget())->Font_Size(size.toDouble());
        });

        ////////////////////////////////

        QObject::connect(_ui->A_Close, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Close, &QAction::triggered, [this]() -> void {");

            QMdiSubWindow *window = _ui->MA_Editor->activeSubWindow();
            if(window != nullptr){
                window->close();
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

public:
    void Format_Changed(const QTextCharFormat &format) {
        System::Logging(__FUNCTION__);

        _ui->A_Bold->setChecked(format.fontWeight() >= QFont::DemiBold);
        _ui->A_Italic->setChecked(format.fontItalic());
        _ui->A_Underline->setChecked(format.fontUnderline());
        _ui->A_Strikeout->setChecked(format.fontStrikeOut());
    }

    ////////////////////////////////////////////////////////////////////////////

public:
    class Editor : public QWidget {
    public:
        static inline Notebook *_notebook = nullptr;
        static inline QMdiArea *_mdiarea = nullptr;
        static inline QTabBar *_tabbar = nullptr;

    public:
        Ui::Editor *_ui = nullptr;
        QFileInfo _fileinfo = QFileInfo();
        QToolButton *_button = nullptr;

        Property<Bool> _saved = Property<Bool>(_None, [this]() {
            // System::Logging("Property<Bool> _saved = Property<Bool>(_None, [this]() {");
            _button->setStyleSheet(_saved == _Posi ? Style::_close_saved : Style::_close_unsaved);
        });

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
        explicit Editor(Notebook *notebook, QMdiArea *mdiarea, Bool saved)
            : QWidget(mdiarea), _ui(new Ui::Editor) {
            System::Logging(__FUNCTION__);

            _ui->setupUi(this);
            if(_mdiarea != mdiarea) {
                _notebook = notebook;
                _mdiarea = mdiarea;
                _tabbar = _mdiarea->findChild<QTabBar *>();
                _tabbar->setExpanding(false);
            }
            _button = new QToolButton(_tabbar);
            this->setAttribute(Qt::WA_DeleteOnClose);

            ////////////////////////////////

            _saved = saved;
            if(Open(), _saved == _Nega) {
                this->close();
                return ;
            }

            ////////////////////////////////

            QMdiSubWindow *window = _mdiarea->addSubWindow(this);
            window->setWindowIcon(QIcon());
            window->setWindowTitle(_fileinfo.fileName());
            QObject::connect(_button, &QToolButton::clicked, window, &QMdiSubWindow::close);
            _tabbar->setTabButton(Index_SubWindow(window), QTabBar::RightSide, _button);
            this->show();

            ////////////////////////////////

            QObject::connect(_ui->TE_Editor, &QTextEdit::customContextMenuRequested, [this](QPoint point) -> void {
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::customContextMenuRequested, [this](QPoint point) -> void {");

                (void) point;
                QMenu *menu = _ui->TE_Editor->createStandardContextMenu();
                menu->exec(QCursor::pos());
                delete menu;
            });

            QObject::connect(_ui->TE_Editor, &QTextEdit::currentCharFormatChanged, [this](QTextCharFormat format) -> void {
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::currentCharFormatChanged, [this](QTextCharFormat format) -> void {");

                (void) this;
                _notebook->Format_Changed(format);
            });
        }

        virtual ~Editor() override {
            System::Logging(__FUNCTION__);
            delete _ui;
        }

    public:
        void Open() {
            System::Logging(__FUNCTION__);

            if(_saved == _None) {
                _fileinfo = QFileInfo("Untitled.text");
                return ;
            }

            QString caption = "打开";
            QString filter = "文本文件(*.txt;*.text);; Markdown(*.md;*.markdown);; Html(*.html);; 所有文件(*.*)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            if(!(0 < filename.size())) {
                _saved = _Nega;
                return ;
            }

            _fileinfo = QFileInfo(filename);
            QFile file(_fileinfo.filePath());
            if (!file.open(QFile::ReadWrite) && System::Checking(true, System::_Error, "!file.open(QFile::ReadWrite)", NULL)) {
                _saved = _Nega;
                return ;
            }
            QTextStream stream(&file);
            stream.setCodec("UTF-8");

            _ui->TE_Editor->setPlainText(stream.readAll());
            _saved = _Posi;
        }

        void Save() {
            System::Logging(__FUNCTION__);

            if(_saved != _Posi) {
                if(_saved == _None) {
                    QString caption = "保存";
                    QString filter = "文本文件(*.txt;*.text);; Markdown(*.md;*.markdown);; Html(*.html);; 所有文件(*.*)";
                    QString filename = QFileDialog::getSaveFileName(this, caption, QDir::currentPath(), filter);
                    if(!(0 < filename.size())) {
                        return ;
                    }
                    _fileinfo = QFileInfo(filename);
                }

                QFile file(_fileinfo.filePath());
                if(!file.open(QFile::ReadWrite) && System::Checking(true, System::_Error, "!file.open(QFile::ReadWrite)", NULL)) {
                    return ;
                }
                QTextStream stream(&file);
                stream.setCodec("UTF-8");

                stream << _ui->TE_Editor->toPlainText();
                _saved = _Posi;
            }
        }

        void Save_As() {
            System::Logging(__FUNCTION__);

            QString caption = "另存";
            QString filter = "文本文件(*.txt;*.text);; Markdown(*.md;*.markdown);; Html(*.html);; 所有文件(*.*)";
            QString filename = QFileDialog::getSaveFileName(this, caption, QDir::currentPath(), filter);
            if(!(0 < filename.size())) {
                return ;
            }

            QFile file(filename);
            if(!file.open(QFile::ReadWrite) && System::Checking(true, System::_Error, "!file.open(QFile::ReadWrite)", NULL)) {
                return ;
            }
            QTextStream stream(&file);
            stream.setCodec("UTF-8");

            stream << _ui->TE_Editor->toPlainText();
        }

        void Undo() {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->undo();
        }

        void Redo() {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->redo();
        }

        void Clear() {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->clear();
        }

        void Cut() {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->cut();
        }

        void Copy() {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->copy();
        }

        void Paste() {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->paste();
        }

        void Bold(bool checked) {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->setFontWeight((checked == true) ? QFont::Bold : QFont::Normal);
        }

        void Italic(bool checked) {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->setFontItalic(checked);
        }

        void Underline(bool checked) {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->setFontUnderline(checked);
        }

        void Strikeout(bool checked) {
            System::Logging(__FUNCTION__);

            QTextCharFormat format = _ui->TE_Editor->currentCharFormat();
            format.setFontStrikeOut(checked);
            _ui->TE_Editor->setCurrentCharFormat(format);
        }

        void Font(QFont font) {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->setCurrentFont(font);
        }

        void Font_Size(double size) {
            System::Logging(__FUNCTION__);

            _ui->TE_Editor->setFontPointSize(size);
        }

    public:
        virtual bool event(QEvent *event) override {
            // System::Logging(__FUNCTION__);

            if(event->type() == QEvent::Close) {
                Save();
                return true;
            }
            return QWidget::event(event);
        }
    };
};

#endif // Notebook_h
