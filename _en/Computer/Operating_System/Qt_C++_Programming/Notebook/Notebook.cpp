#include "Common.h"

MW_Notebook::MW_Notebook(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MW_Notebook) {
    Logger(__FUNCTION__);

    ui->setupUi(this);


    connect(ui->A_Cut, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Cut, &QAction::triggered, [this]() -> void {");
        ui->TE_Notebook->cut();
        ui->PTE_Notebook->cut();
    });

    connect(ui->A_Copy, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Copy, &QAction::triggered, [this]() -> void {");
        ui->TE_Notebook->copy();
        ui->PTE_Notebook->copy();
    });

    connect(ui->A_Paste, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Paste, &QAction::triggered, [this]() -> void {");
        ui->TE_Notebook->paste();
        ui->PTE_Notebook->paste();
    });

    connect(ui->A_Close, &QAction::triggered, [this]() -> void {
        Logger("connect(ui->A_Close, &QAction::triggered, [this]() -> void {");
        this->close();
    });

    connect(ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {
        Logger("connect(ui->A_Bold, &QAction::triggered, [this](bool checked) -> void {");

        ui->TE_Notebook->setFontWeight((checked == true) ? QFont::Bold : QFont::Normal);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontWeight((checked == true) ? QFont::Bold : QFont::Normal);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    connect(ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {
        Logger("connect(ui->A_Italic, &QAction::triggered, [this](bool checked) -> void {");

        ui->TE_Notebook->setFontItalic(checked);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontItalic(checked);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    connect(ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {
        Logger("connect(ui->A_Underline, &QAction::triggered, [this](bool checked) -> void {");

        ui->TE_Notebook->setFontUnderline(checked);

        QTextCharFormat format = ui->PTE_Notebook->currentCharFormat();
        format.setFontUnderline(checked);
        ui->PTE_Notebook->setCurrentCharFormat(format);
    });

    connect(ui->TE_Notebook, &QTextEdit::copyAvailable, [this](bool available) -> void {
        Logger("connect(ui->TE_Notebook, &QTextEdit::copyAvailable, [this](bool available) -> void {");

        ui->A_Copy->setEnabled(available);
        ui->A_Cut->setEnabled(available);
        ui->A_Paste->setEnabled(ui->TE_Notebook->canPaste());
    });

    connect(ui->TE_Notebook, &QTextEdit::selectionChanged, [this]() -> void {
        Logger("connect(ui->TE_Notebook, &QTextEdit::selectionChanged, [this]() -> void {");

        QTextCharFormat format = ui->TE_Notebook->currentCharFormat();
        ui->A_Bold->setChecked(format.font().bold());
        ui->A_Italic->setChecked(format.font().italic());
        ui->A_Underline->setChecked(format.font().underline());
    });
}

MW_Notebook::~MW_Notebook() {
    Logger(__FUNCTION__);

    delete ui;
}
