/* Qt6_eventFilter.h
Author: BSS9395
Update: 2023-09-07T16:10:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_EVENTFILTER_H
#define QT6_EVENTFILTER_H

#include <QMainWindow>
#include "ui_Qt6_eventFilter.h"

class Qt6_eventFilter : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_eventFilter *_ui = nullptr;

public:
    Qt6_eventFilter(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_eventFilter) {
        _ui->setupUi(this);

        _ui->L_Click->installEventFilter(this);
        _ui->L_Double_Click->installEventFilter(this);
    }

    ~Qt6_eventFilter() {
        delete _ui;
    }

public:
    bool eventFilter(QObject *watched, QEvent *event) override {
        if(watched == _ui->L_Click) {
            if(event->type() == QEvent::Enter) {
                _ui->L_Click->setText("Enter");
            } else if(event->type() == QEvent::Leave) {
                _ui->L_Click->setText("Leave");
            } else if(event->type() == QEvent::MouseButtonPress) {
                _ui->L_Click->setText("MouseButtonPress");
            } else if(event->type() == QEvent::MouseButtonRelease) {
                _ui->L_Click->setText("MouseButtonRelease");
            }
        } else if(watched == _ui->L_Double_Click) {
            if(event->type() == QEvent::Enter) {
                _ui->L_Double_Click->setText("Enter");
            } else if(event->type() == QEvent::Leave) {
                _ui->L_Double_Click->setText("Leave");
            } else if(event->type() == QEvent::MouseButtonDblClick) {
                _ui->L_Double_Click->setText("MouseButtonDblClick");
            }
        }
        return QWidget::eventFilter(watched, event);
    }

};
#endif // QT6_EVENTFILTER_H
