/* Qt_QClipboard.cpp
Author: bss9395
Update: 2025/10/28T01:13:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#include <QApplication>
#include <QClipboard>
#include <QJsonDocument>
#include <QJsonObject>
#include <QKeyEvent>
#include <QLineEdit>
#include <QTextEdit>

class CustomLineEdit : public QLineEdit {
public:
    CustomLineEdit(QWidget *parent = nullptr)
        : QLineEdit(parent) {
        this->setWindowTitle("CustomLineEdit");
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->modifiers() & Qt::ControlModifier) {
            if (event->key() == Qt::Key_C) {
                qDebug().nospace() << "[CustomLineEdit] Key_C";
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(this->selectedText());

                QJsonObject object = QJsonObject();
                object["nickname"] = "璀璨星辰";
                object["birthday"] = "1993/09/05";
                QByteArray json = QJsonDocument(object).toJson(QJsonDocument::Indented);
                clipboard->setText(QString(json));
                return;
            } else if (event->key() == Qt::Key_V) {
                qDebug().nospace() << "[CustomLineEdit] Key_V";
                QClipboard *clipboard = QApplication::clipboard();
                this->insert(clipboard->text());
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
        this->setWindowTitle("CustomTextEdit");
    }

protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->modifiers() & Qt::ControlModifier) {
            if (event->key() == Qt::Key_C) {
                qDebug().nospace() << "[CustomTextEdit] Key_C";
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(this->textCursor().selectedText());
                return;
            } else if (event->key() == Qt::Key_V) {
                qDebug().nospace() << "[CustomTextEdit] Key_V";
                QClipboard *clipboard = QApplication::clipboard();
                this->textCursor().insertText(clipboard->text());
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
