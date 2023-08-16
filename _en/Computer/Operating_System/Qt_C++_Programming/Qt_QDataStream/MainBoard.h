/* MainBoard.h
Author: BSS9395
Update: 2023-08-16T19:02:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef MainBoard_h
#define MainBoard_h

#include <QWidget>
#include "ui_MainBoard.h"
#include <QList>
#include <QVector>
#include <QToolButton>
#include <Dialog.h>

class MainBoard : public QWidget {
    Q_OBJECT

private:
    Ui::MainBoard         *_ui = nullptr;
    QVector<QToolButton *> _users;
    QVector<Dialog *>      _dialogs;

public:
    explicit MainBoard(QWidget *parent = nullptr)
        : QWidget(parent), _ui(new Ui::MainBoard) {
        _ui->setupUi(this);
        this->setWindowTitle("FQ");
        this->setWindowIcon(QIcon(":/images/qq.png"));

        QStringList usernames;
        usernames << "Maker";
        usernames << "水票奇缘";
        usernames << "忆梦如澜";
        usernames << "北京出版人";
        usernames << "Cherry";
        usernames << "淡然";
        usernames << "娇娇girl";
        usernames << "落水无痕";
        usernames << "青墨暖暖";

        QStringList icons;
        icons << "qt";
        icons << "spqy";
        icons << "ymrl";
        icons << "qq";
        icons << "Cherry";
        icons << "dr";
        icons << "jj";
        icons << "lswh";
        icons << "qmnn";

        for(int i = 0; i < 9; i += 1) {
            QToolButton *user = new QToolButton();
            user->setText(usernames[i]);
            QString icon = QString(":/images/%1.png").arg(icons[i]);
            user->setIcon(QIcon(icon));
            user->setIconSize(QPixmap(icon).size());
            user->setAutoRaise(true);
            user->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            _ui->FL_Users->addWidget(user);
            _users.append(user);
            _dialogs.append(nullptr);
        }

        for(int i = 0; i < 9; i += 1) {
            QObject::connect(_users[i], &QToolButton::clicked, this, [this, i]() -> void {
                if(_dialogs[i] == nullptr) {
                    _dialogs[i] = new Dialog(_users[i]->text());
                    QObject::connect(_dialogs[i], Dialog::_Closed, this, [this, i]() -> void{
                        delete _dialogs[i];
                        _dialogs[i] = nullptr;
                    });
                }
                _dialogs[i]->setWindowTitle(_users[i]->text());
                _dialogs[i]->setWindowIcon(_users[i]->icon());
                _dialogs[i]->show();
            });
        }
    }


    ~MainBoard() {
        delete _ui;
        for(int i = 0; i < 9; i += 1) {
            delete _users.at(i);
            delete _dialogs.at(i);
        }
    }
};

#endif // MainBoard_h
