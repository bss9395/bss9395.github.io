/* Notebook.cpp
Author: BSS9395
Update: 2022-02-05T00:05:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.15.2
Notice: Bug on Visual Studio 2017
*/

#include "Common.h"

bool Notebook::event(QEvent *event) {
    // Logging(__FUNCTION__);

    if(event->type() == QEvent::KeyPress && ((QKeyEvent *)event)->key() == Qt::Key_S && ((QKeyEvent *)event)->modifiers() == Qt::ControlModifier) {
        emit _ui->A_Save->triggered();
        return true;
    } else if (event->type() == QEvent::Close || event->type() == QEvent::Quit) {
        if(_modified == true){
            QString caption = "文件未保存";
            QString label = "文件已被修改，是否保存修改？";
            iptr button = QMessageBox::question(this, caption, label, "是", "否", "取消", 0);
            if(button == 0) {
                emit _ui->A_Save->triggered();
            } else if(button == 1) {
                // no operation.
            } else if(button == 2) {
                // no operation.
            }
        }
        return true;
    }
    return QWidget::event(event);
}

Notebook::Notebook(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::Notebook) {
    Logging(__FUNCTION__);

    _ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/view_in_ar.png"));
    this->setWindowTitle(QString("Notebook[*]"));
    Update_Theme();

    ////////////////////////////////////

    _ui->FCB_Font_Family->setFixedSize(126, 26);
    _ui->CB_Font_Size->setCurrentText(QString::asprintf("%d", _ui->TE_Notebook->font().pointSize()));
    _ui->TB_Major->addWidget(_ui->GB_Font);
    _ui->SB_Status_Bar->addWidget(_ui->GB_Status_Bar);

    ////////////////////////////////////


    QObject::connect(_ui->PB_Ending, &QPushButton::clicked, [this]() -> void {
        Ending *ending = new Ending(_ui->PB_Ending->text(), _ui->PB_Ending);
        QObject::connect(ending, &Ending::Update_Ending, [this](QString platform) -> void {
            _ui->PB_Ending->setText(platform);
        });
        ending->show();
    });

    QObject::connect(_ui->A_Save, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Save, &QAction::triggered, [this]() -> void {");

        // QString buffer = _ui->TE_Notebook->toHtml();
        // QString buffer = _ui->TE_Notebook->toMarkdown();
        QString buffer = _ui->TE_Notebook->toPlainText();
        QFile file(_filename);
        if(file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream << buffer;
        }
        _modified = false;
        this->setWindowModified(false);
    });

    QObject::connect(_ui->A_Cut, &QAction::triggered, [this]() -> void {
        Logging("connect(ui->A_Cut, &QAction::triggered, [this]() -> void {");

        _ui->TE_Notebook->cut();
        _ui->PTE_Notebook->cut();
    });

    QObject::connect(_ui->A_Copy, &QAction::triggered, [this]() -> void {
        Logging("connect(ui->A_Copy, &QAction::triggered, [this]() -> void {");

        _ui->TE_Notebook->copy();
        _ui->PTE_Notebook->copy();
    });

    QObject::connect(_ui->A_Paste, &QAction::triggered, [this]() -> void {
        Logging("connect(ui->A_Paste, &QAction::triggered, [this]() -> void {");

        _ui->TE_Notebook->paste();
        _ui->PTE_Notebook->paste();
    });

    QObject::connect(_ui->A_Close, &QAction::triggered, [this]() -> void {
        Logging("connect(ui->A_Close, &QAction::triggered, [this]() -> void {");
        this->close();
    });

    QObject::connect(_ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {
        Logging("connect(ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {");

        _ui->TE_Notebook->setFontWeight((checked == true) ? QFont::Bold : QFont::Normal);

        QTextCharFormat format = _ui->PTE_Notebook->currentCharFormat();
        format.setFontWeight((checked == true) ? QFont::Bold : QFont::Normal);
        _ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(_ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {
        Logging("connect(ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {");

        _ui->TE_Notebook->setFontItalic(checked);

        QTextCharFormat format = _ui->PTE_Notebook->currentCharFormat();
        format.setFontItalic(checked);
        _ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(_ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {
        Logging("connect(ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {");

        _ui->TE_Notebook->setFontUnderline(checked);

        QTextCharFormat format = _ui->PTE_Notebook->currentCharFormat();
        format.setFontUnderline(checked);
        _ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(_ui->TE_Notebook, &QTextEdit::copyAvailable, [this](bool available) -> void {
        Logging("connect(ui->TE_Notebook, &QTextEdit::copyAvailable, [this](bool available) -> void {");

        _ui->A_Copy->setEnabled(available);
        _ui->A_Cut->setEnabled(available);
        _ui->A_Paste->setEnabled(_ui->TE_Notebook->canPaste());
    });

    QObject::connect(_ui->TE_Notebook, &QTextEdit::selectionChanged, [this]() -> void {
        Logging("connect(ui->TE_Notebook, &QTextEdit::selectionChanged, [this]() -> void {");

        QTextCharFormat format = _ui->TE_Notebook->currentCharFormat();
        _ui->A_Bold->setChecked(format.font().bold());
        _ui->A_Italic->setChecked(format.font().italic());
        _ui->A_Underline->setChecked(format.font().underline());
    });

    QObject::connect(_ui->CB_Font_Size, &QComboBox::currentTextChanged, [this](QString text) -> void {
        Logging("QObject::connect(_ui->CB_Font_Size, &QComboBox::currentTextChanged, [this](QString text) -> void {");

        iptr font_size = text.toLongLong();
        _ui->TE_Notebook->setFontPointSize(font_size);

        QTextCharFormat format = _ui->PTE_Notebook->currentCharFormat();
        format.setFontPointSize(font_size);
        _ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(_ui->FCB_Font_Family, &QFontComboBox::currentTextChanged, [this](QString text) -> void {
        Logging("QObject::connect(ui->CB_Font_Name, &QComboBox::currentTextChanged, [this](QString text) -> void {");

        _ui->TE_Notebook->setFontFamily(text);

        QTextCharFormat format = _ui->PTE_Notebook->currentCharFormat();
        format.setFontFamily(text);
        _ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(_ui->A_Open, (void (QAction::*)())&QAction::triggered, [this]() -> void {
        Logging("QObject::connect(ui->A_Open, (void (QAction::*)())&QAction::triggered, [this]() -> void {");

        QString filename = QFileDialog::getOpenFileName(this, "打开文件", QDir::currentPath(), "文本文件(*.txt);;Markdown(*.md);;所有文件(*.*)");
        if (0 < filename.size()) {
            QFile file(filename);
            if (file.open(QFile::ReadWrite)) {
                QTextStream stream(&file);
                stream.setCodec("UTF-8");
                _ui->TE_Notebook->append(stream.readAll());

                Update_Status_Bar(filename);
            }
        }
    });

    QObject::connect(_ui->A_Font, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(ui->A_Font, &QAction::triggered, [this]() -> void {");

        bool ok = false;
        QFont font = QFontDialog::getFont(&ok, _ui->TE_Notebook->font());
        if (ok == true) {
            _ui->TE_Notebook->setCurrentFont(font); // note: predefined text, bug on QTextEdit::setFont().
            _ui->PTE_Notebook->setFont(font);
        } else {
            // application font, QApplication::font()
        }
    });

    QObject::connect(_ui->A_New, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(ui->A_New, &QAction::triggered, [this]() -> void {");

        _ui->TE_Notebook->clear();
        _ui->PTE_Notebook->clear();
        Update_Status_Bar("");
    });

    QObject::connect(_ui->A_Show_Label, &QAction::triggered, [this](bool checked) -> void {
        Logging("QObject::connect(ui->A_Show_Label, &QAction::triggered, [this](bool checked) -> void {");

        (checked == true)
            ? _ui->TB_Major->setToolButtonStyle(Qt::ToolButtonTextUnderIcon)
            : _ui->TB_Major->setToolButtonStyle(Qt::ToolButtonIconOnly);
    });

    _ui->TE_Notebook->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(_ui->TE_Notebook, &QTextEdit::customContextMenuRequested, [this](QPoint point) -> void {
        Logging("QObject::connect(_ui->TE_Notebook, &QTextEdit::customContextMenuRequested, [this](QPoint point) -> void {");

        (void)point;
        QMenu *menu = _ui->TE_Notebook->createStandardContextMenu();
        menu->exec(QCursor::pos());
        delete menu;
    });

    _ui->PTE_Notebook->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(_ui->PTE_Notebook, &QPlainTextEdit::customContextMenuRequested, [this](QPoint point) -> void {
        Logging("QObject::connect(_ui->PTE_Notebook, &QPlainTextEdit::customContextMenuRequested, [this](QPoint point) -> void {");

        (void)point;
        QMenu *menu = _ui->PTE_Notebook->createStandardContextMenu();
        menu->exec(QCursor::pos());
        delete menu;
    });

    QObject::connect(_ui->PB_Filename, &QPushButton::clicked, [this]() -> void {
        Logging("QObject::connect(_ui->PB_Filename, &QPushButton::clicked, [this]() -> void {");

        QString caption = QString("更改文件名");
        QString label = QString("输入文件名");
        bool ok = false;
        QString filename = QInputDialog::getText(this, caption, label, QLineEdit::Normal, _filename, &ok);
        if(ok == true && 0 < filename.size()){
            _filename = filename;
            Update_Status_Bar(_filename);
        }
    });

    QObject::connect(_ui->TE_Notebook, &QTextEdit::textChanged, [this]() -> void {
        Logging("QObject::connect(_ui->TE_Notebook, &QTextEdit::textChanged, [this]() -> void {");

        _modified = true;
        this->setWindowModified(true);

        emit _ui->TE_Notebook->cursorPositionChanged();
    });

    QObject::connect(_ui->TE_Notebook, &QTextEdit::cursorPositionChanged, [this]() -> void {
        Logging("QObject::connect(_ui->TE_Notebook, &QTextEdit::cursorPositionChanged, [this]() -> void {");

        QTextCursor cursor = _ui->TE_Notebook->textCursor();
        iptr line = cursor.blockNumber();
        // iptr column = cursor.columnNumber();  // note: position in line.
        iptr column = cursor.positionInBlock();  // note: position in paragraph.
        _ui->SB_Line->setValue(line);
        _ui->SB_Column->setValue(column);
        _ui->SB_Line->setRange(0, _ui->TE_Notebook->document()->blockCount() - 1);
    });

    QObject::connect(_ui->SB_Line, &QSpinBox::editingFinished, [this]() -> void {
        Logging("QObject::connect(_ui->SB_Line, &QSpinBox::editingFinished, [this]() -> void {");

        emit _ui->SB_Column->editingFinished();
    });

    QObject::connect(_ui->SB_Column, &QSpinBox::editingFinished, [this]() -> void {
        Logging("QObject::connect(_ui->SB_Column, &QSpinBox::editingFinished, [this]() -> void {");

        QTextCursor cursor = _ui->TE_Notebook->textCursor();
        QTextBlock block = _ui->TE_Notebook->document()->findBlockByNumber(_ui->SB_Line->value());
        _ui->SB_Column->setRange(0, block.length() - 1);

        cursor.setPosition(block.position() + _ui->SB_Column->value());
        _ui->TE_Notebook->setTextCursor(cursor);
        _ui->TE_Notebook->setFocus();
    });


}

Notebook::~Notebook() {
    Logging(__FUNCTION__);

    delete _ui;
}


void Notebook::Update_Status_Bar(const QString &filename) {
    Logging(__FUNCTION__);

    _ui->PB_Filename->setText(filename);
}

void Notebook::Update_Theme() {
    Logging(__FUNCTION__);

    iptr RGBA = 255;
    float red = 0.5 * RGBA;
    float green = 0.5 * RGBA;
    float blue = 0.5 * RGBA;
    float alpha = 0.5;

    QString css = QString::asprintf("QTextEdit {\n    background-color: rgba(%td, %td, %td, %lf); \n}", (iptr)red, (iptr)green, (iptr)blue, alpha);
    _ui->TE_Notebook->setStyleSheet(css);

    QColor color = QColor((int)red, (int)green, (int)blue, (int)(alpha * RGBA));
    QPalette palette = _ui->PTE_Notebook->palette();
    palette.setColor(QPalette::Base, color);
    _ui->PTE_Notebook->setPalette(palette);
}
