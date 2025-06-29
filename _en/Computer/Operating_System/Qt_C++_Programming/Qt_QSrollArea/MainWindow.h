#include <QApplication>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollBar>
#include <QWidget>
#include <QStyle>
#include <QPainter>
#include <QStyleOptionSlider>

class CustomScrollBar : public QScrollBar {
    Q_OBJECT

public:
    CustomScrollBar(QWidget *parent)
        : QScrollBar(parent) {
        static QString qss = R"!(
        QScrollBar:horizontal {
            background-color: #00FFFFFF;
            height: 10px;
            margin: 0px 0px 0px 0px;
        }

        QScrollBar::handle:horizontal {
            background-color: #FFC0C0C0;
            min-width: 20px;
            border-radius: 6px;
        }

        QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
            background: none;
        }

        QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {
            background: none;
        }

        /***********************************/

        QScrollBar:vertical {
            background-color: #00FFFFFF;
            width: 10px;
            margin: 0px 0px 0px 0px;
        }

        QScrollBar::handle:vertical {
            background-color: #FFC0C0C0;
            min-height: 20px;
            border-radius: 6px;
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            background: none;
        }

        QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
            background: none;
        }
        )!";
        this->setStyleSheet(qss);
    }
};

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // this
        this->setObjectName("this");
        QVBoxLayout* this_layout = new QVBoxLayout(this);

        // scrollarea
        QScrollArea* scrollarea = new QScrollArea(this);
        scrollarea->setObjectName("scrollarea");
        this_layout->addWidget(scrollarea);
        scrollarea->setWidgetResizable(true);    // 由QSrollArea动态调整其内部Frame的大小
        scrollarea->setVerticalScrollBar(new CustomScrollBar(scrollarea));

        // scrollarea_frame
        QWidget *scrollarea_frame = new QWidget;
        scrollarea->setWidget(scrollarea_frame);
        QVBoxLayout *contentLayout = new QVBoxLayout(scrollarea_frame);
        for (int i = 0; i < 20; i += 1) {
            QPushButton *button = new QPushButton(scrollarea_frame);
            contentLayout->addWidget(button);
            button->setText(QString("Button%1").arg(i));
        }
    }
};
