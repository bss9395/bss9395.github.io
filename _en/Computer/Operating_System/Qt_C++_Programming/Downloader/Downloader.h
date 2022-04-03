/* Downloader.h
Author: BSS9395
Update: 2022-03-27T01:40:00+08@China-Shanghai+08
Design: Downloader
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Downloader_h
#define Downloader_h

#define Header_h
#include "Common.h"
#include "ui_Downloader.h"
#include "System.h"

class Downloader : public QMainWindow {
    Q_OBJECT

    typedef const char *State;
    static inline const State _Created = "Created";
    static inline const State _Running = "Running";
    static inline const State _Pending = "Pending";
    static inline const State _Stopped = "Stopped";

public:
    Ui::Downloader *_ui = nullptr;
    QNetworkAccessManager _manager = QNetworkAccessManager();
    QFile *_file = nullptr;
    QNetworkReply *_reply = nullptr;
    State _state = _Created;

public:
    explicit Downloader(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Downloader) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        Enable(true);
        _state = _Created;

        QObject::connect(_ui->PB_Terminate, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Terminate, &QPushButton::clicked, this, [this]() -> void {");

            _state = _Stopped;
            _reply->close();     // note: continue any upload until it is done.
            // _reply->abort();  // note: abort any upload immediately.
            _file->close();      // note: flush buffer to write into file.
        });

        _ui->LE_Link->setPlaceholderText("https://www.advancedinstaller.com/downloading.html");
        _ui->LE_Path->setPlaceholderText(QDir::currentPath() + "/temp/");
        QObject::connect(_ui->PB_Download, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Download, &QPushButton::clicked, this, [this]() -> void {");

            QString folder = _ui->LE_Path->text().trimmed();
            if(folder.size() <= 0) {
                folder = _ui->LE_Path->placeholderText();
                QDir().mkpath(folder);
            }

            QString url = _ui->LE_Link->text().trimmed();
            if(url.size() <= 0) {
                url = _ui->LE_Link->placeholderText();
            }

            QUrl uri = QUrl(url);
            if(uri.isValid() == false) {
                QString title = "无效的链接";
                QString caption = uri.errorString();
                QMessageBox::critical(this, title, caption, QMessageBox::Ok, QMessageBox::NoButton);
                return ;
            }

            QString filepath = folder + uri.fileName(QUrl::FullyDecoded);
            System::Logging("filepath = %ls", filepath.toStdWString().data());
            _file = new QFile(filepath);
            if(_file->open(QIODevice::WriteOnly) == false) {
                QString title = "创建文件错误";
                QString caption = "无法创建文件";
                QMessageBox::critical(this, title, caption, QMessageBox::Ok, QMessageBox::NoButton);
                return ;
            }
            Enable(false);

            _reply = _manager.get(QNetworkRequest(uri));
            QObject::connect(_reply, &QNetworkReply::downloadProgress, this, [this](qint64 received, qint64 total) -> void {
                System::Logging("QObject::connect(_reply, &QNetworkReply::downloadProgress, this, [this](qint64 received, qint64 total) -> void {");

                _ui->PB_Progress->setMaximum(total);
                _ui->PB_Progress->setValue(received);
                System::Logging("received = %td, total = %td", (iptr)received, (iptr)total);
            });

            QObject::connect(_reply, &QNetworkReply::readyRead, this, [this]() -> void {
                System::Logging("QObject::connect(_reply, &QNetworkReply::readyRead, this, [this]() -> void {");

                _file->write(_reply->readAll());
            });

            QObject::connect(_reply, &QNetworkReply::finished, this, [this]() -> void {
                System::Logging("QObject::connect(_reply, &QNetworkReply::finished, this, [this]() -> void {");

                if(_state != _Stopped) {
                    QFileInfo info = QFileInfo(_file->fileName());
                    _reply->close();
                    _reply->deleteLater();
                    _file->close();
                    delete _file;

                    if(_ui->CB_Trigger->isChecked() == true) {
                        QDesktopServices::openUrl(QUrl::fromLocalFile(info.absoluteFilePath()));
                    }
                    Enable(true);
                }
            });

            _state = _Running;
        });
    }

    virtual ~Downloader() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void Enable(bool enabled) {
        System::Logging(__FUNCTION__);

        _ui->PB_Download->setEnabled(enabled);
        _ui->PB_Terminate->setEnabled(!enabled);
    }
};

#endif // Downloader_h
