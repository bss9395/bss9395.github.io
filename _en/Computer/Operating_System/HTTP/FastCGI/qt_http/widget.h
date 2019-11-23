#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_getBaidu_clicked();
    void on_postEcho_clicked();

private:
    Ui::Widget *ui;

    QNetworkAccessManager *_networkAccessManager;
};
#endif // WIDGET_H
