/* Clipboard.h
Author: bss9395
Update: 2025/10/28T02:41:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#pragma once

#include <QObject>
#include <QApplication>
#include <QClipboard>

class Clipboard: public QObject {
    Q_OBJECT

public:
    Q_INVOKABLE QString getText() {
        return QApplication::clipboard()->text();
    }

    Q_INVOKABLE void setText(const QString &text) {
        QApplication::clipboard()->setText(text);
    }
};
