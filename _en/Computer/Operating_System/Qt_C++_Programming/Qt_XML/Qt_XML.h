/* Qt_XML.h
Author: BSS9395
Update: 2023-08-12@19:07:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT_XML_H
#define QT_XML_H

#include <QDialog>
#include "ui_Qt_XML.h"
#include <QDebug>
#include <QFile>
#include <qdom.h>
#include <QMessageBox>

class Qt_XML : public QDialog {
    Q_OBJECT

    // <?xml > must be at the first line of the document.
    QString _xml = R"(<?xml version='1.0' encoding='UTF-8'?>
<Account>
    <user id="1">
        <username>root</username>
        <password>123456</password>
    </user>
    <user id="2">
        <username>brilliant</username>
        <password>123456</password>
    </user>
</Account>
    )";

private:
    Ui::Qt_XML *_ui = nullptr;
    QDomDocument _document;

public:
    Qt_XML(QWidget *parent = nullptr)
        : QDialog(parent), _ui(new Ui::Qt_XML) {
        qDebug() << __FUNCTION__;
        _ui->setupUi(this);

        QObject::connect(_ui->PB_Login, &QPushButton::clicked, this, [this]() -> void {
            QFile::remove("login.xml");
            QFile file_xml("login.xml");
            file_xml.open(QFile::ReadWrite);
            file_xml.write(_xml.toUtf8());
            file_xml.close();

            QFile file("login.xml");
            _document.setContent(&file);
            QDomElement root = _document.documentElement();
            QDomNodeList user_list = root.childNodes();
            bool exist = false;
            for(int i = 0; i < user_list.count(); i += 1) {
                QDomNode user = user_list.at(i);
                QDomNodeList record = user.childNodes();
                QString username = record.at(0).toElement().text();
                QString password = record.at(1).toElement().text();
                if(username == _ui->LE_Username->text().trimmed()) {
                    exist = true;
                    if(password == _ui->LE_Password->text().trimmed()) {
                        this->accept();
                    } else {
                        QMessageBox::warning(this, "", "密码有误！", QMessageBox::Ok);
                    }
                }
            }
            if(exist == false) {
                 QMessageBox::warning(this, "", "用户不存在！", QMessageBox::Ok);
            }

        });
    }

    ~Qt_XML() {
        delete _ui;
    }


};
#endif // QT_XML_H
