/* Qt6_dropEvent.h
Author: BSS9395
Update: 2023-09-07T16:52:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_DROPEVENT_H
#define QT6_DROPEVENT_H

#include <QMainWindow>
#include "ui_Qt6_dropEvent.h"
#include <QFileInfo>
#include <QMimeData>

class Qt6_dropEvent : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_dropEvent *_ui = nullptr;

public:
    Qt6_dropEvent(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_dropEvent) {
        _ui->setupUi(this);

        this->setAcceptDrops(true);
        _ui->PTE_Message->setAcceptDrops(false);
        _ui->L_Image->setAcceptDrops(false);
        // _ui->L_Image->setScaledContents(true);
    }

    ~Qt6_dropEvent() {
        delete _ui;
    }

public:
    void dragEnterEvent(QDragEnterEvent *event) {
        _ui->PTE_Message->appendPlainText("");
        _ui->PTE_Message->clear();
        for(int i = 0; i < event->mimeData()->formats().size(); i += 1) {
            _ui->PTE_Message->appendPlainText(event->mimeData()->formats().at(i));
        }

        _ui->PTE_Message->appendPlainText("");
        for(int i = 0; i < event->mimeData()->urls().size(); i += 1) {
            QUrl url = event->mimeData()->urls().at(i);
            _ui->PTE_Message->appendPlainText(url.path());
        }

        if(event->mimeData()->hasUrls() == true) {
            QString filename = event->mimeData()->urls().at(0).fileName();
            QFileInfo fileinfo(filename);
            QString extension = fileinfo.suffix().toUpper();
            if(extension == "JPG" || extension == "PNG" || extension == "GIF") {
                event->acceptProposedAction();
            } else{
                event->ignore();
            }
        } else{
            event->ignore();
        }
    }

    void dropEvent(QDropEvent *event) {
        QString filename = event->mimeData()->urls().at(0).path();  // note: full filename
        filename = filename.mid(1);
        QPixmap pixmap(filename);
        _ui->L_Image->setPixmap(pixmap);
        return QMainWindow::dropEvent(event);
    }

};
#endif // QT6_DROPEVENT_H
