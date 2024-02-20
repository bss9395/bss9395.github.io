#ifndef CONFIG_H
#define CONFIG_H

#include <QGuiApplication>
#include <QMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QStandardPaths>
#include <QFileDialog>
#include <QRegularExpression>
#include <QRegularExpressionMatch>


class Config: public QGuiApplication {
    Q_OBJECT
public:
    explicit Config(int &argc, char *argv[])
        : QGuiApplication(argc, argv) {
        qDebug().noquote() << __FUNCTION__;
    }

public:
    Q_INVOKABLE QPointF cursorPos() {
        // qDebug().noquote() << __FUNCTION__;
        return QCursor::pos();
    }

    Q_INVOKABLE QStringList fileinfo(const QString &fileurl) {
        qDebug().noquote() << __FUNCTION__;
        QString fileuri  = fileurl;
        fileuri = fileuri.replace(R"!(\)!", "/");

        QString filepath = fileuri;
        filepath = filepath.replace(QRegularExpression("^[a-zA-Z]{1,}://", QRegularExpression::DotMatchesEverythingOption), "");

        int index = filepath.lastIndexOf("/");
        QString filename = filepath.mid(index + 1);

        QStringList fileinfolist = QStringList({
            fileuri,
            filepath,
            filename
        });
        return fileinfolist;
    }

    Q_INVOKABLE void filepath(const QStringList &fileinfo) {
        qDebug().noquote() << __FUNCTION__;
        QString filepath = fileinfo[1];
        qDebug().noquote() << "filepath = " << filepath;
    }

    Q_INVOKABLE void filename(const QVariantList &fileinfo) {
        qDebug().noquote() << __FUNCTION__;
        QString filename = fileinfo[2].toString();
        qDebug().noquote() << "filename = " << filename;
    }
};

#endif // CONFIG_H
