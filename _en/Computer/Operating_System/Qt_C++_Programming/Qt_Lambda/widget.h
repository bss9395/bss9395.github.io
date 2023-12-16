#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"
#include <QDebug>
#include <string>
#include <functional>
#include <thread>

class Widget : public QWidget {
    Q_OBJECT

public:
    Ui::Widget *ui;

public:
    static void _Lambda_Reference() {
        fprintf(stdout, "%s\n", __FUNCTION__);
        static std::function<void(void)> lambda1;
        static std::function<void(void)> lambda2;
        static bool inited = false;
        if(inited == false) {
            inited = true;

            std::string *button = new std::string("按钮");
            fprintf(stdout, "button = %p\n", button);
            fflush(stdout);

            auto lamb1 = [button]() -> void {
                // fprintf(stdout, "%s\n", "auto lamb1 = [button]() -> void {");
                fprintf(stdout, "lamb1 = %p\n", button);
                fflush(stdout);
            };

            auto lamb2 = [&button]() -> void {
                // fprintf(stdout, "%s\n", "auto lamb2 = [&button]() -> void {");
                fprintf(stdout, "lamb2 = %p\n", button);
                fflush(stdout);
            };

            lambda1 = lamb1;
            lambda2 = lamb2;
        }

        lambda1();
        lambda2();
    }

    void _Qt_EventLoop() {
        fprintf(stdout, "%s\n", __FUNCTION__);

        QString *button = new QString("按钮");
        fprintf(stdout, "button = %p\n", button);
        fflush(stdout);

        auto lambda1 = [this, button]() -> void {
            // fprintf(stdout, "%s\n", "auto lambda1 = [this, button]() -> void {");
            fprintf(stdout, "lambda1 = %p\n", button);
            fflush(stdout);
        };

        auto lambda2 = [this, &button]() -> void {
            // fprintf(stdout, "%s\n", "auto lambda2 = [this, &button]() -> void {");
            fprintf(stdout, "lambda2 = %p\n", button);
            fflush(stdout);
        };

        // 相同线程
        lambda1();
        lambda2();

        // 相同线程
        QObject::connect(this, &Widget::signal_clickLambda1, this, lambda1);
        QObject::connect(this, &Widget::signal_clickLambda2, this, lambda2);
        emit this->signal_clickLambda1();
        emit this->signal_clickLambda2();

        // 不同线程
        QObject::connect(ui->PB_Button1, &QPushButton::clicked, this, lambda1);
        QObject::connect(ui->PB_Button2, &QPushButton::clicked, this, lambda2);
    }

public:
    explicit Widget(QWidget *parent = nullptr)
        : QWidget(parent), ui(new Ui::Widget) {
        ui->setupUi(this);

        _Lambda_Reference();                    // 相同线程
        std::thread(_Lambda_Reference).join();  // 不同线程

        ////////////////////////////////////////////////////////////////////////

        _Qt_EventLoop();
    }

    virtual ~Widget() {
        delete ui;
    }

signals:
    void signal_clickLambda1();
    void signal_clickLambda2();
};
#endif // WIDGET_H
