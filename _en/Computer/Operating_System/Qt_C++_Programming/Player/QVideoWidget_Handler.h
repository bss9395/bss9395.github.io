/* QVideoWidget_Handler.h
Author: BSS9395
Update: 2022-07-14T01:54:00+08@China-Shanghai+08
Design: Player
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Displayer_h
#define Displayer_h

#define   Header_h
#include "Common.h"
#include "System.h"

class QVideoWidget_Handler : public QVideoWidget {
    Q_OBJECT

public:
    explicit QVideoWidget_Handler(QWidget *parent = nullptr)
        : QVideoWidget(parent) {
        System::Logging(__FUNCTION__);

    }

    virtual ~QVideoWidget_Handler() {
        System::Logging(__FUNCTION__);
    }

public:
    virtual void keyPressEvent(QKeyEvent *event) override {
        System::Logging(__FUNCTION__);

        if(event->key() == Qt::Key_Escape && this->isFullScreen() == true) {
            this->setFullScreen(false);
        }
        QVideoWidget::keyPressEvent(event);
    }

    virtual void mousePressEvent(QMouseEvent *event) override {
        System::Logging(__FUNCTION__);

        if(event->button() == Qt::LeftButton) {
            emit _Mouse_Press();
        }
        QVideoWidget::mousePressEvent(event);
    }

signals:
    void _Mouse_Press();
};

#endif // Displayer_h
