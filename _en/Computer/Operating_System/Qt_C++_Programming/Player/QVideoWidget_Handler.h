/* QVideoWidget_Handler.h
Author: BSS9395
Update: 2022-07-20T02:00:00+08@China-Shanghai+08
Design: Player
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef QVideoWidget_Handler_h
#define QVideoWidget_Handler_h

#define   Header_h
#include "Common.h"
#include "System.h"

class QVideoWidget_Frame;
class QVideoWidget_Handler : public QVideoWidget {
    Q_OBJECT

public:
    QVideoWidget_Frame *_frame = nullptr;

public:
    explicit QVideoWidget_Handler(QWidget *parent = nullptr);
    virtual ~QVideoWidget_Handler();
    void _Setup(QVideoWidget_Frame *frame);

public:
    virtual bool event(QEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void showEvent(QShowEvent *event) override;
    virtual void hideEvent(QHideEvent *event) override;
};

#endif // QVideoWidget_Handler_h
