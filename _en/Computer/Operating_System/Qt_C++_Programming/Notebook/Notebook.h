/* Notebook.h
Author: BSS9395
Update: 2022-02-11T02:10:00+08@China-Guangdong-Zhanjiang+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Notebook_h
#define Notebook_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "Toolkit.h"
#include "Custom.h"
#include "ui_Notebook.h"
#include "ui_Editor.h"
#include "ui_Ending.h"

class Notebook : public QMainWindow {
    Q_OBJECT

public:
    class Editor : public QWidget {
    public:
        Notebook *_notebook = nullptr;
        Ui::Editor *_ui = nullptr;
        QToolButton *_button = new QToolButton(this);

        QFileInfo _fileinfo = QFileInfo();
        bool _once = false;
        Property<Bool> _saved = Property<Bool>(_None, [this]() {
            // System::Logging("Property<Bool> _saved = Property<Bool>(_None, [this]() {");

            if(_saved == _Posi) {
                _button->setStyleSheet(Style::_Close_Saved);
                _ui->TE_Editor->document()->setModified(false);
            } else {
                _button->setStyleSheet(Style::_Close_Unsaved);
            }
        });

    public:
        explicit Editor(Notebook *notebook, const Bool &saved)
            : QWidget(nullptr), _ui(new Ui::Editor) {
            System::Logging(__FUNCTION__);
            _notebook = notebook;
            _ui->setupUi(this);
            this->setAttribute(Qt::WA_DeleteOnClose);

            _saved = saved;
            if(Open(), _saved == _Nega) {
                this->close();
                return ;
            }

            QMdiSubWindow *window = _notebook->_ui->MA_Editor->addSubWindow(this); // note: this->parent() shifts to window.
            window->setAttribute(Qt::WA_DeleteOnClose);
            window->setWindowIcon(QIcon());
            window->setWindowTitle(_fileinfo.fileName());
            QObject::connect(_button, &QToolButton::clicked, window, &QMdiSubWindow::close);
            _notebook->_tabbar->setTabButton(Index_SubWindow(window), QTabBar::RightSide, _button);
            this->show();

            ////////////////////////////////

            QObject::connect(_ui->TE_Editor, &QTextEdit::undoAvailable, [this](bool can_undo) -> void {
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::undoAvailable, [this](bool can_undo) -> void {");

                _notebook->Update_Undo(can_undo);
            });

            QObject::connect(_ui->TE_Editor, &QTextEdit::redoAvailable, [this](bool can_redo) -> void {
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::redoAvailable, [this](bool can_redo) -> void {");

                _notebook->Update_Redo(can_redo);
            });

            QObject::connect(_ui->TE_Editor, &QTextEdit::copyAvailable, [this](bool can_copy) -> void {
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::copyAvailable, [this](bool available) -> void {");

                _notebook->Update_Copy_Cut_Paste(can_copy, _ui->TE_Editor->canPaste());
            });

            QObject::connect(_ui->TE_Editor, &QTextEdit::currentCharFormatChanged, [this](QTextCharFormat format) -> void {
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::currentCharFormatChanged, [this](QTextCharFormat format) -> void {");

                _notebook->Update_Format(format);
            });

            QObject::connect(_ui->TE_Editor->document(), &QTextDocument::modificationChanged, [this](bool changed) -> void {
                System::Logging("QObject::connect(_ui->TE_Editor->document(), &QTextDocument::modificationChanged, [this](bool changed) -> void {");

                if(changed == true && _saved == _Posi) {
                    System::Logging("if(changed == true && _saved == _Posi) {");
                    _saved = _Nega;
                }
            });

            QObject::connect(_ui->TE_Editor, &QTextEdit::cursorPositionChanged, [this]() -> void {
                if(_once == true) {
                    _once = false;
                    return;
                }
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::cursorPositionChanged, [this]() -> void {");
                QTextCursor cursor = _ui->TE_Editor->textCursor();
                _notebook->Update_Text_Cursor(_ui->TE_Editor->document()->blockCount() - 1, cursor.block().length() - 1, cursor.blockNumber(), cursor.positionInBlock());
            });

            ////////////////////////////

            QObject::connect(_ui->TE_Editor, &QTextEdit::customContextMenuRequested, [this]() -> void {
                System::Logging("QObject::connect(_ui->TE_Editor, &QTextEdit::customContextMenuRequested, [this](QPoint point) -> void {");

                QMenu *menu = _ui->TE_Editor->createStandardContextMenu();
                menu->exec(QCursor::pos());
                delete menu;
            });
        }

        virtual ~Editor() override {
            System::Logging(__FUNCTION__);
            delete _ui;
        }

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
                if(!file.open(QFile::ReadWrite | QFile::Truncate) && System::Checking(true, System::_Error, "!file.open(QFile::ReadWrite | QFile::Truncate)", NULL)) {
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
        void Update_Text_Cursor(QSpinBox *sb_line, QSpinBox *sb_column) {
            System::Logging(__FUNCTION__);

            _once = true;
            QTextCursor cursor = _ui->TE_Editor->textCursor();
            QTextBlock block = _ui->TE_Editor->document()->findBlockByNumber(sb_line->value());
            sb_column->setRange(0, block.length() - 1);
            cursor.setPosition(block.position() + sb_column->value());
            _ui->TE_Editor->setTextCursor(cursor);
            _ui->TE_Editor->setFocus();
        }

    public:
        virtual bool event(QEvent *event) override {
            // System::Logging(__FUNCTION__);

            if(event->type() == QEvent::Close) {
                if(_ui->TE_Editor->document()->isModified() == true) {
                    QString caption = "文件未保存";
                    QString label = "文件已被修改，是否保存修改？";
                    iptr button = QMessageBox::question(this, caption, label, "是", "否", "取消", 0);
                    if(button == 0) {
                        Save();
                    } else if(button == 2) {
                        event->ignore();
                    }
                }
                return true;
            }
            else if((event->type() == QEvent::KeyPress && ((QKeyEvent *)event)->key() == Qt::Key_S && ((QKeyEvent *)event)->modifiers() == Qt::ControlModifier)) {
                Save();
                return true;
            }
            return QWidget::event(event);
        }
    };

    ////////////////////////////////////////////////////////////////////////////

public:
    class Ending : public QDialog {
    public:
        Notebook *_notebook = nullptr;
        Ui::Ending *_ui = nullptr;

    public:
        explicit Ending(Notebook *notebook, QPushButton *parent, const QString &form)
            : QDialog(parent), _ui(new Ui::Ending) {
            System::Logging(__FUNCTION__);
            _notebook = notebook;
            _ui->setupUi(this);
            this->setAttribute(Qt::WA_DeleteOnClose);

            if(form == "LF") {
                _ui->RB_Unix->setChecked(true);
            } else if(form == "CRLF") {
                _ui->RB_Windows->setChecked(true);
            } else if(form == "CR") {
                _ui->RB_Mac->setChecked(true);
            }

            this->setWindowFlag(Qt::FramelessWindowHint, true);
            this->setWindowFlag(Qt::WindowStaysOnTopHint, true);
            this->resize(_ui->GB_Ending->sizeHint().width(), _ui->GB_Ending->sizeHint().height());

            QPoint pos = (parent == nullptr) ? QCursor::pos() : parent->parentWidget()->mapToGlobal(parent->pos());
            QScreen *screen = QGuiApplication::screenAt(pos);
            if(screen->geometry().width() < pos.x() + this->size().width()) {
                pos.setX(screen->geometry().width() - this->size().width());  // note: ensure right border in screen range.
            }
            if(pos.setY(pos.y() - this->size().height()), pos.y() < 0) {
                pos.setY(0);                                                  // note: ensure top border in screen range.
            }
            // this->setParent(parent->parentWidget());  // note: global absolute position, no parent widget.
            this->move(pos);                             // note: move to global absolute position.
            this->show();

            ////////////////////////////////

            QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this](bool checked) -> void {
                System::Logging("QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this]() -> void {");
                (void) checked;
                _notebook->Update_Ending("LF");
                this->close();
            });

            QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this](bool checked) -> void {
                System::Logging("QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this]() -> void {");
                (void) checked;
                _notebook->Update_Ending("CRLF");
                this->close();
            });

            QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {
                System::Logging("QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {");
                (void) checked;
                _notebook->Update_Ending("CR");
                this->close();
            });
        }

        virtual ~Ending() override {
            System::Logging(__FUNCTION__);
            delete _ui;
        }

    public:
        virtual bool event(QEvent *event) override {
            // Logging(__FUNCTION__);

            if(event->type() == QEvent::FocusIn || event->type() == QEvent::Leave) {
                // System::Logging("if(event->type() == QEvent::FocusIn) {");
                this->grabMouse();
                return true;
            } else if(event->type() == QEvent::Enter) {
                // System::Logging("} else if(event->type() == QEvent::Enter) {");
                this->releaseMouse();
                return true;
            } else if(event->type() == QEvent::MouseButtonPress) {
                // System::Logging("} else if(event->type() == QEvent::MouseButtonPress) {");
                this->releaseMouse();
                this->close();        // note: mouse button press outside this widget.
                return true;
            }
            return QWidget::event(event);
        }
    };

    ////////////////////////////////////////////////////////////////////////////

public:
    static inline QStringList _supported = {
        "*.txt", "*.text",
        "*.md",  "*.markdown",
        "*.html",
        "*.*"
    };

public:
    Ui::Notebook *_ui = nullptr;
    QTabBar *_tabbar = nullptr;
    Editor *_editor = nullptr;

public:
    explicit Notebook(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Notebook) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _ui->TB_Minor->addWidget(_ui->GB_Font);
        _ui->SB_Status->addPermanentWidget(_ui->GB_Status);
        _tabbar = _ui->MA_Editor->findChild<QTabBar *>();  // use QMdiArea::TabbedView with special caution.
        _tabbar->setExpanding(false);

        this->setWindowIcon(QIcon(":/images/view_in_ar.png"));
        this->setWindowTitle(QString("记事本"));
        Update_Can(false);
        _ui->SB_Status->showMessage("记事本", 2000);

        QObject::connect(_ui->MA_Editor, &QMdiArea::subWindowActivated, [this](QMdiSubWindow *window) -> void {
            System::Logging("QObject::connect(_ui->MA_Editor, &QMdiArea::subWindowActivated, [this](QMdiSubWindow *window) -> void {");
            _editor = (window != nullptr) ? (Editor *)window->widget() : nullptr;
        });

        ////////////////////////////////////

        QObject::connect(_ui->A_New, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_New, &QAction::triggered, [this]() -> void {");

            new Editor(this, _None);
        });

        QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {");

            new Editor(this, _Posi);
        });

        QObject::connect(_ui->A_Save, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Save, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Save();
            }
        });

        QObject::connect(_ui->A_Save_As, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Save_As, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Save_As();
            }
        });

        QObject::connect(_ui->A_Undo, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Undo, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Undo();
            }
        });

        QObject::connect(_ui->A_Redo, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Redo, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Redo();
            }
        });

        QObject::connect(_ui->A_Clear, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Clear();
            }
        });

        QObject::connect(_ui->A_Cut, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Cut, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Cut();
            }
        });

        QObject::connect(_ui->A_Copy, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Copy, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Copy();
            }
        });

        QObject::connect(_ui->A_Paste, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Paste, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Paste();
            }
        });

        QObject::connect(_ui->A_Scheme, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Scheme, &QAction::triggered, [this](bool checked) -> void {");

            _ui->MA_Editor->setStyleSheet(checked == true ? Style::_Gray_Background : Style::_Light_Background);
        });

        QObject::connect(_ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Bold, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->Bold(checked);
            }
        });

        QObject::connect(_ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {");

            if(_editor != nullptr) {
                _editor->Italic(checked);
            }
        });

        QObject::connect(_ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {");

            if (_editor != nullptr) {
                _editor->Underline(checked);
            }
        });

        QObject::connect(_ui->A_Strikeout, &QAction::triggered, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->A_Strikeout, &QAction::triggered, [this](bool checked) -> void {");

            if (_editor != nullptr) {
                _editor->Strikeout(checked);
            }
        });

        QObject::connect(_ui->FCB_Font, &QFontComboBox::currentFontChanged, [this](QFont font) -> void {
            System::Logging("QObject::connect(_ui->FCB_Font, &QFontComboBox::currentFontChanged, [this](QFont font) -> void {");

            if (_editor != nullptr) {
                _editor->Font(font);
            }
        });

        _ui->CB_Font_Size->setValidator(new QDoubleValidator());
        QObject::connect(_ui->CB_Font_Size, &QComboBox::editTextChanged, [this](QString size) -> void {
            System::Logging("QObject::connect(_ui->CB_Font_Size, &QComboBox::currentTextChanged, [this](QString size) -> void {");

            if (_editor != nullptr) {
                _editor->Font_Size(size.toDouble());
            }
        });

        ////////////////////////////////

        QObject::connect(_ui->A_Cascade, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Cascade, &QAction::triggered, [this]() -> void {");

            _ui->A_Tile_Grid->setChecked(false);
            _ui->A_Tile_Vertically->setChecked(false);
            _ui->A_Tile_Horizontally->setChecked(false);
            _ui->MA_Editor->setViewMode(QMdiArea::TabbedView); // note: use QMdiArea::SubWindowView with special caution, QMdiArea constructs TabBar at requests.
            _ui->MA_Editor->cascadeSubWindows();
        });

        QObject::connect(_ui->A_Tile_Grid, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Tile, &QAction::triggered, [this]() -> void {");

            _ui->A_Cascade->setChecked(false);
            _ui->A_Tile_Vertically->setChecked(false);
            _ui->A_Tile_Horizontally->setChecked(false);
            _ui->MA_Editor->setViewMode(QMdiArea::TabbedView); // note: use QMdiArea::SubWindowView with special caution, QMdiArea constructs TabBar at requests.
            _ui->MA_Editor->tileSubWindows();
        });

        QObject::connect(_ui->A_Tile_Vertically, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Tile, &QAction::triggered, [this]() -> void {");

            _ui->A_Cascade->setChecked(false);
            _ui->A_Tile_Grid->setChecked(false);
            _ui->A_Tile_Horizontally->setChecked(false);
            _ui->MA_Editor->setViewMode(QMdiArea::TabbedView); // note: use QMdiArea::SubWindowView with special caution, QMdiArea constructs TabBar at requests.
            _ui->MA_Editor->tileSubWindows();
            QList<QMdiSubWindow *> windows = _ui->MA_Editor->subWindowList();
            iptr width = _ui->MA_Editor->width(), height = (_ui->MA_Editor->height() - _tabbar->height()) / windows.size();
            iptr top = 0;
            for(iptr i = 0, numb = windows.size(); i < numb; i += 1) {
                windows[i]->resize(width, height);  // note: use resize() not setFixedSize().
                windows[i]->move(0, top);
                top += height;
            }
        });

        QObject::connect(_ui->A_Tile_Horizontally, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Tile, &QAction::triggered, [this]() -> void {");

            _ui->A_Cascade->setChecked(false);
            _ui->A_Tile_Grid->setChecked(false);
            _ui->A_Tile_Vertically->setChecked(false);
            _ui->MA_Editor->setViewMode(QMdiArea::TabbedView); // note: use QMdiArea::SubWindowView with special caution, QMdiArea constructs TabBar at requests.
            _ui->MA_Editor->tileSubWindows();
            QList<QMdiSubWindow *> windows = _ui->MA_Editor->subWindowList();
            iptr width = _ui->MA_Editor->width() / windows.size(), height = _ui->MA_Editor->height() - _tabbar->height();
            iptr left = 0;
            for(iptr i = 0, numb = windows.size(); i < numb; i += 1) {
                windows[i]->resize(width, height);  // note: use resize() not setFixedSize().
                windows[i]->move(left, 0);
                left += width;
            }
        });

        QObject::connect(_ui->A_Close, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Close, &QAction::triggered, [this]() -> void {");

            if(_editor != nullptr) {
                _editor->close();
            }
        });

        QObject::connect(_ui->A_Close_All, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Close_All, &QAction::triggered, [this]() -> void {");

            _ui->MA_Editor->closeAllSubWindows();
        });

        ////////////////////////////////////

        QObject::connect(_ui->SB_Line, &SpinBox::Value_Changed, _ui->SB_Column, &SpinBox::Value_Changed);
        QObject::connect(_ui->SB_Column, &SpinBox::Value_Changed, [this]() -> void {
            System::Logging("QObject::connect(_ui->SB_Column, &SpinBox::Value_Changed, [this](iptr column) -> void {");

            if(_editor != nullptr) {
                _editor->Update_Text_Cursor(_ui->SB_Line, _ui->SB_Column);
            }
        });

        QObject::connect(_ui->PB_Ending, &QPushButton::clicked, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Ending, &QPushButton::clicked, [this]() -> void {");

            new Ending(this, _ui->PB_Ending, _ui->PB_Ending->text());
        });
    }

    virtual ~Notebook() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void Update_Can(bool can) {
        System::Logging(__FUNCTION__);

        _ui->A_Undo->setEnabled(can);
        _ui->A_Redo->setEnabled(can);
        _ui->A_Cut->setEnabled(can);
        _ui->A_Copy->setEnabled(can);
        // _ui->TB_Minor->setEnabled(can);
    }

    void Update_Undo(bool can_undo) {
        System::Logging(__FUNCTION__);

        _ui->A_Undo->setEnabled(can_undo);
    }

    void Update_Redo(bool can_redo) {
        System::Logging(__FUNCTION__);

        _ui->A_Redo->setEnabled(can_redo);
    }

    void Update_Copy_Cut_Paste(bool can_copy, bool can_paste) {
        System::Logging(__FUNCTION__);

        _ui->A_Copy->setEnabled(can_copy);
        _ui->A_Cut->setEnabled(can_copy);
        _ui->A_Paste->setEnabled(can_paste);
    }

    void Update_Format(const QTextCharFormat &format) {
        System::Logging(__FUNCTION__);

        _ui->A_Bold->setChecked(format.fontWeight() >= QFont::DemiBold);
        _ui->A_Italic->setChecked(format.fontItalic());
        _ui->A_Underline->setChecked(format.fontUnderline());
        _ui->A_Strikeout->setChecked(format.fontStrikeOut());
    }

    void Update_Ending(const QString &form) {
        System::Logging(__FUNCTION__);

        _ui->PB_Ending->setText(form);
    }

    void Update_Text_Cursor(iptr line_range, iptr column_range, iptr line, iptr column) {
        System::Logging(__FUNCTION__);

        _ui->SB_Line->setRange(0, line_range);
        _ui->SB_Column->setRange(0, column_range);
        _ui->SB_Line->setValue(line);
        _ui->SB_Column->setValue(column);
    }
};

#endif // Notebook_h
