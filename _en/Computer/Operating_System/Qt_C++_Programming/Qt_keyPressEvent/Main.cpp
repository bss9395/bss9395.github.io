/// Record: Main.cpp
/// Author: bss9395
/// Update: 2025-12-06T21:15:00+08$08@China-BeiJing
/// Keepin: bss9395@yeah.net

#include <QApplication>
#include <QClipboard>
#include <QKeyEvent>
#include <QLineEdit>
#include <QTextEdit>

class CustomLineEdit : public QLineEdit {
public:
    CustomLineEdit(QWidget *parent = nullptr)
        : QLineEdit(parent) {

    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->modifiers() & Qt::ControlModifier) {
            if (event->key() == Qt::Key_C) {
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(selectedText());
                return;
            } else if (event->key() == Qt::Key_V) {
                QClipboard *clipboard = QApplication::clipboard();
                insert(clipboard->text());
                return;
            }
        }
        QLineEdit::keyPressEvent(event);
    }
};

class CustomTextEdit : public QTextEdit {
public:
    CustomTextEdit(QWidget *parent = nullptr)
        : QTextEdit(parent) {

    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->modifiers() & Qt::ControlModifier) {
            if (event->key() == Qt::Key_C) {
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(textCursor().selectedText());
                return;
            } else if (event->key() == Qt::Key_V) {
                QClipboard *clipboard = QApplication::clipboard();
                textCursor().insertText(clipboard->text());
                return;
            }
        }
        QTextEdit::keyPressEvent(event);
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CustomTextEdit textEdit;
    textEdit.show();

    CustomLineEdit lineEdit;
    lineEdit.show();

    return a.exec();
}
