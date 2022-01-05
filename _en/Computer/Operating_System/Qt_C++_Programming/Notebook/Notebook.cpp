/* Notebook
Author: BSS9395
Update: 2022-01-05T23:10:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
*/

#include "Common.h"

MW_Notebook::MW_Notebook(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MW_Notebook) {
    Logger(__FUNCTION__);

    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/view_in_ar.png"));

    ui->FCB_Font_Family->setFixedSize(126, 26);
    ui->SB_Font_Size->setRange(1, 127);
    ui->SB_Font_Size->setValue(ui->TE_Notebook->font().pointSize());
    ui->TB_Major->addWidget(ui->GB_Font);

    ui->PB_Font_Size->setRange(1, 127);
    ui->PB_Font_Size->setValue(ui->SB_Font_Size->font().pointSize());
    ui->SB_Status_Bar->addWidget(ui->GB_Status_Bar);

    ////////////////////////////////////

    QObject::connect(ui->A_Cut, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Cut, &QAction::triggered, [this]() -> void {");
        ui->TE_Notebook->cut();
        ui->PTE_Notebook->cut();
    });

    QObject::connect(ui->A_Copy, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Copy, &QAction::triggered, [this]() -> void {");
        ui->TE_Notebook->copy();
        ui->PTE_Notebook->copy();
    });

    QObject::connect(ui->A_Paste, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Paste, &QAction::triggered, [this]() -> void {");
        ui->TE_Notebook->paste();
        ui->PTE_Notebook->paste();
    });

    QObject::connect(ui->A_Close, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Close, &QAction::triggered, [this]() -> void {");
        this->close();
    });

    QObject::connect(ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {
        Logger("connect(ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {");

        ui->TE_Notebook->setFontWeight((checked == true) ? QFont::Bold : QFont::Normal);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontWeight((checked == true) ? QFont::Bold : QFont::Normal);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {
        Logger("connect(ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {");

        ui->TE_Notebook->setFontItalic(checked);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontItalic(checked);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {
        Logger("connect(ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {");

        ui->TE_Notebook->setFontUnderline(checked);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontUnderline(checked);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(ui->TE_Notebook, &QTextEdit::copyAvailable, [this](bool available) -> void {
        Logger("connect(ui->TE_Notebook, &QTextEdit::copyAvailable, [this](bool available) -> void {");

        ui->A_Copy->setEnabled(available);
        ui->A_Cut->setEnabled(available);
        ui->A_Paste->setEnabled(ui->TE_Notebook->canPaste());
    });

    QObject::connect(ui->TE_Notebook, &QTextEdit::selectionChanged, [this]() -> void {
        Logger("connect(ui->TE_Notebook, &QTextEdit::selectionChanged, [this]() -> void {");

        QTextCharFormat format = ui->TE_Notebook->currentCharFormat();
        ui->A_Bold->setChecked(format.font().bold());
        ui->A_Italic->setChecked(format.font().italic());
        ui->A_Underline->setChecked(format.font().underline());
    });

    QObject::connect(ui->SB_Font_Size, (void (QSpinBox::*)(int))&QSpinBox::valueChanged, [this](int value) -> void {
        Logger("connect(ui->SB_Font_Size, &QSpinBox::valueChanged, [this](int value) -> void {");

        ui->TE_Notebook->setFontPointSize(value);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontPointSize(value);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(ui->FCB_Font_Family, &QFontComboBox::currentTextChanged, [this](const QString &text) -> void {
        Logger("QObject::connect(ui->CB_Font_Name, &QComboBox::currentTextChanged, [this](const QString &text) -> void {");

        ui->TE_Notebook->setFontFamily(text);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontFamily(text);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    QObject::connect(ui->A_Open, (void (QAction::*)())&QAction::triggered, [this]() -> void {
        Logger("QObject::connect(ui->A_Open, (void (QAction::*)())&QAction::triggered, [this]() -> void {");

        QString &codecs = Format::Print<QString>(QTextCodec::availableCodecs());
        Logger("QTextCodec::availableCodecs() = \n{ %s }", codecs.toStdString().data());

        QString directory = QCoreApplication::applicationDirPath();
        QString filename = QFileDialog::getOpenFileName(this, "打开文件", directory, "文本文件(*.txt);;Markdown(*.md);;所有文件(*.*)");
        if (0 < filename.size()) {
            QFile file(filename);
            if (file.open(QFile::ReadWrite | QFile::Text)) {
                QTextStream stream(&file);
                stream.setCodec("UTF-8");
                ui->TE_Notebook->append(stream.readAll());

                Update_Status_Bar(filename);
            }
        }
    });

    QObject::connect(ui->A_Font, &QAction::triggered, [this]() -> void {
        Logger("QObject::connect(ui->A_Font, &QAction::triggered, [this]() -> void {");

        bool ok = false;
        QFont font = QFontDialog::getFont(&ok, this);
        if (ok == true) {
            ui->TE_Notebook->setCurrentFont(font); // note: predefined text, bug on QTextEdit::setFont().
            ui->PTE_Notebook->setFont(font);
        } else {
            // application font, QApplication::font()
        }
    });

    QObject::connect(ui->A_New, &QAction::triggered, [this]() -> void {
        Logger("QObject::connect(ui->A_New, &QAction::triggered, [this]() -> void {");

        ui->TE_Notebook->clear();
        ui->PTE_Notebook->clear();
        Update_Status_Bar("");
    });

    QObject::connect(ui->A_Show_Label, &QAction::triggered, [this](bool checked) -> void {
        Logger("QObject::connect(ui->A_Show_Label, &QAction::triggered, [this](bool checked) -> void {");

        (checked == true)
            ? ui->TB_Major->setToolButtonStyle(Qt::ToolButtonTextUnderIcon)
            : ui->TB_Major->setToolButtonStyle(Qt::ToolButtonIconOnly);
    });
}

MW_Notebook::~MW_Notebook() {
    Logger(__FUNCTION__);

    delete ui;
}

void MW_Notebook::Update_Status_Bar(const QString &filename) {
    ui->L_Filename->setText(filename);
}
