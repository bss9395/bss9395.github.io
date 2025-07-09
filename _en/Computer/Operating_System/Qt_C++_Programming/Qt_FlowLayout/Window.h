#pragma once

#include <QDebug>
#include <QLabel>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "FlowLayout.h"
#include "VWidget.h"
#include "FVWidget.h"
#include "HWidget.h"
#include "FHWidget.h"

class Window: public QWidget {
    Q_OBJECT
public:
    explicit Window(QWidget* parent = nullptr)
        : QWidget(parent) {
        // _Test_FlowLayout();
        // _Test_QLabel();
        // _Test_VWidget();
        // _Test_FVWidget();
        // _Test_HWidget();
        // _Test_FHWidget();
        _Test_VWidget_FHWidget();
    }

    virtual ~Window() {

    }

public:
    void _Test_FlowLayout() {
        this->resize(600, 400);
        FlowLayout *flowLayout = new FlowLayout(this);
        flowLayout->addWidget(new QPushButton("Short"));
        flowLayout->addWidget(new QPushButton("Even longer button text. Even longer button text. Even longer button text. Even longer button text."));
        flowLayout->addWidget(new QPushButton("Longer"));
        flowLayout->addWidget(new QPushButton("Different text"));
        flowLayout->addWidget(new QPushButton("More text"));
    }

    QLabel* _label = nullptr;
    void _Test_QLabel() {
        QString qss = R"!(
        [objectName = "_label"] {
            background-color: "red";
        }
        )!";
        this->setStyleSheet(qss);

        _label = new QLabel(this);
        _label->setObjectName("label");
        _label->installEventFilter(this);
        QString info = "Label Label Label Label Label Label Label Label Label Label Label Label Label Label Label Label Label Label Label Label";
        _label->setText(QString("<p style='line-height: %1'>").arg(1.5) + info.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        // _label->setText(info);
        _label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        _label->setWordWrap(true);
    }

    VWidget* _vwidget = nullptr;
    void _Test_VWidget() {
        QString qss = R"!(
        [objectName = "_vwidget"] {
            background-color: "red";
        }
        )!";
        this->setStyleSheet(qss);

        this->resize(500, 500);
        _vwidget = new VWidget(this);
        _vwidget->setObjectName("_vwidget");
        _vwidget->setSaturateH(VWidget::_esaturate_box);
        _vwidget->setAlignments({Qt::AlignHCenter | Qt::AlignVCenter, Qt::AlignRight | Qt::AlignVCenter});
        //_vwidget->setMargins({4, 5, 6, 7});
        //_vwidget->setSpacingV(8);

        QPushButton* button0 = new QPushButton(_vwidget);
        button0->setText("button0");
        QPushButton* button1 = new QPushButton(_vwidget);
        button1->setText("button1");
        QLabel* label0 = new QLabel(_vwidget);
        label0->setProperty("_lineHeightRatio", 1.5);
        QString info0 = "label0 label0 label0 label0 label0 label0 label0 label0 label0 label0";
        label0->setText(QString("<p style='line-height: %1'>").arg(1.5) + info0.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        label0->setWordWrap(true);
        QLabel* label1 = new QLabel(_vwidget);
        label1->setProperty("_lineHeightRatio", 1.5);
        QString info1 = "label1 label1 label1 label1 label1 label1 label1 label1 label1 label1";
        label1->setText(QString("<p style='line-height: %1'>").arg(1.5) + info1.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        // label1->setText(info1);
        label1->setWordWrap(this);

        button0->setMaximumWidth(100);
        _vwidget->addWidget(button0, 0.0);
        _vwidget->addWidget(button1, 0.0);
        _vwidget->addWidget(label0, 0.0);
        _vwidget->addWidget(label1, 0.0);
    }

    FVWidget* _fvwidget = nullptr;
    void _Test_FVWidget() {
        QString qss = R"!(
        [objectName = "_fvwidget"] {
            background-color: "red";
        }
        )!";
        this->setStyleSheet(qss);

        this->resize(500, 500);
        _fvwidget = new FVWidget(this);
        _fvwidget->setObjectName("_fvwidget");
        _fvwidget->setSaturateH(FVWidget::_esaturate_line);
        _fvwidget->setAlignments({Qt::AlignHCenter | Qt::AlignVCenter, Qt::AlignHCenter | Qt::AlignVCenter});
        _fvwidget->setMargins({0, 0, 0, 0});
        _fvwidget->setSpacings({0, 0});

        QPushButton* button0 = new QPushButton(_fvwidget);
        button0->setText("button0");
        QPushButton* button1 = new QPushButton(_fvwidget);
        button1->setText("button1");
        QLabel* label0 = new QLabel(_fvwidget);
        label0->setProperty("_lineHeightRatio", 1.5);
        QString info0 = "label0 label0 label0 label0 label0 label0 label0 label0 label0 label0";
        label0->setText(QString("<p style='line-height: %1'>").arg(1.5) + info0.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        label0->setWordWrap(true);
        QLabel* label1 = new QLabel(_fvwidget);
        label1->setProperty("_lineHeightRatio", 1.5);
        QString info1 = "label1 label1 label1 label1 label1 label1 label1 label1 label1 label1";
        label1->setText(QString("<p style='line-height: %1'>").arg(1.5) + info1.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        // label1->setText(info1);
        label1->setWordWrap(this);
        QPushButton* button2 = new QPushButton(_fvwidget);
        button2->setText("button2");
        QPushButton* button3 = new QPushButton(_fvwidget);
        button3->setText("button3");

        button0->setMinimumWidth(200);
        button3->setMinimumWidth(300);
        _fvwidget->addWidget(button0, 0.0);
        _fvwidget->addWidget(button1, 0.0);
        _fvwidget->addWidget(label0, 0.0);
        _fvwidget->addWidget(label1, 0.0);
        _fvwidget->addWidget(button2, 0.0);
        _fvwidget->addWidget(button3, 0.0);
    }

    HWidget* _hwidget = nullptr;
    void _Test_HWidget() {
        QString qss = R"!(
        [objectName = "_hwidget"] {
            background-color: "red";
        }
        )!";
        this->setStyleSheet(qss);

        this->resize(500, 500);
        _hwidget = new HWidget(this);
        _hwidget->setObjectName("_hwidget");
        _hwidget->setSaturateV(HWidget::_esaturate_box);
        _hwidget->setAlignments({Qt::AlignHCenter | Qt::AlignVCenter, Qt::AlignHCenter | Qt::AlignVCenter});
        _hwidget->setMargins({0, 0, 0, 0});
        _hwidget->setSpacingH(0);

        QPushButton* button0 = new QPushButton(_hwidget);
        button0->setText("button0");
        QPushButton* button1 = new QPushButton(_hwidget);
        button1->setText("button1");
        QLabel* label0 = new QLabel(_hwidget);
        label0->setProperty("_lineHeightRatio", 1.5);
        QString info0 = "label0 label0 label0 label0 label0 label0 label0 label0 label0 label0";
        label0->setText(QString("<p style='line-height: %1'>").arg(1.5) + info0.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        label0->setWordWrap(true);
        QLabel* label1 = new QLabel(_hwidget);
        label1->setProperty("_lineHeightRatio", 1.5);
        QString info1 = "label1 label1 label1 label1 label1 label1 label1 label1 label1 label1";
        label1->setText(QString("<p style='line-height: %1'>").arg(1.5) + info1.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        label1->setWordWrap(this);
        QPushButton* button2 = new QPushButton(_hwidget);
        button2->setText("button2");
        QPushButton* button3 = new QPushButton(_hwidget);
        button3->setText("button3");

        button0->setMaximumHeight(200);
        // button3->setMaximumHeight(300);
        _hwidget->addWidget(button0, 0.0);
        _hwidget->addWidget(button1, 0.0);
        _hwidget->addWidget(label0, 1.0);
        _hwidget->addWidget(label1, 1.0);
        _hwidget->addWidget(button2, 0.0);
        _hwidget->addWidget(button3, 0.0);
    }

    FHWidget* _fhwidget = nullptr;
    void _Test_FHWidget() {
        QString qss = R"!(
        [objectName = "_fhwidget"] {
            background-color: "red";
        }
        )!";
        this->setStyleSheet(qss);

        this->resize(500, 500);
        _fhwidget = new FHWidget(this);
        _fhwidget->setObjectName("_fhwidget");
        _fhwidget->setSaturateV(HWidget::_esaturate_none);
        _fhwidget->setAlignments({Qt::AlignHCenter | Qt::AlignVCenter, Qt::AlignHCenter | Qt::AlignVCenter});
        _fhwidget->setMargins({0, 0, 0, 0});
        _fhwidget->setSpacings({0, 0});

        QPushButton* button0 = new QPushButton(_fhwidget);
        button0->setText("button0");
        QPushButton* button1 = new QPushButton(_fhwidget);
        button1->setText("button1");
        QLabel* label0 = new QLabel(_fhwidget);
        label0->setProperty("_lineHeightRatio", 1.5);
        QString info0 = "label0 label0 label0 label0 label0 label0 label0 label0 label0 label0";
        label0->setText(QString("<p style='line-height: %1'>").arg(1.5) + info0.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        label0->setWordWrap(true);
        QLabel* label1 = new QLabel(_fhwidget);
        label1->setProperty("_lineHeightRatio", 1.5);
        QString info1 = "label1 label1 label1 label1 label1 label1 label1 label1 label1 label1";
        label1->setText(QString("<p style='line-height: %1'>").arg(1.5) + info1.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        label1->setWordWrap(this);
        QPushButton* button2 = new QPushButton(_fhwidget);
        button2->setText("button2");
        QPushButton* button3 = new QPushButton(_fhwidget);
        button3->setText("button3");

        // button0->setMaximumHeight(200);
        // button3->setMaximumHeight(300);
        _fhwidget->addWidget(button0, 0.0);
        _fhwidget->addWidget(button1, 0.0);
        _fhwidget->addWidget(label0, 0.0);
        _fhwidget->addWidget(label1, 0.0);
        _fhwidget->addWidget(button2, 0.0);
        _fhwidget->addWidget(button3, 0.0);
    }

    HWidget*  _hwidget_outer = nullptr;
    VWidget*  _vwidget_middle = nullptr;
    FHWidget* _fhwidget_inner = nullptr;

    void _Test_VWidget_FHWidget() {
        QString qss = R"!(
        [objectName = "_hwidget_outer"] {
            background-color: "red";
        }
        [objectName = "_vwidget_middle"] {
            background-color: "green";
        }
        [objectName = "_fhwidget_inner"] {
            background-color: "blue";
        }
        )!";
        this->setStyleSheet(qss);
        this->resize(200, 500);

        _hwidget_outer = new HWidget(this);
        _hwidget_outer->setObjectName("_hwidget_outer");
        _hwidget_outer->setSaturateV(HWidget::_esaturate_line);
        _hwidget_outer->setAlignments({Qt::AlignHCenter | Qt::AlignTop, Qt::AlignHCenter | Qt::AlignTop});
		_hwidget_outer->setMargins({ 4, 5, 6, 7 });

        QLabel* label = new QLabel(_hwidget_outer);
        _hwidget_outer->addWidget(label, 0.0);
        label->setObjectName("label");
        label->setText("label");
        label->setFixedSize(label->sizeHint());

        _vwidget_middle = new VWidget(this);
        _hwidget_outer->addWidget(_vwidget_middle, 1.0);
        _vwidget_middle->setObjectName("_vwidget_middle");
        _vwidget_middle->setSaturateH(VWidget::_esaturate_box);
        _vwidget_middle->setAlignments({Qt::AlignHCenter | Qt::AlignTop, Qt::AlignHCenter | Qt::AlignVCenter});

        QLabel* label0 = new QLabel(_vwidget_middle);
        _vwidget_middle->addWidget(label0, 0.0);
        label0->setWordWrap(true);
        QString info0 = "label0 label0 label0 label0 label0 label0 label0 label0 label0 label0";
        label0->setText(QString("<p style='line-height: %1'>").arg(1.5) + info0.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        label0->setProperty("_lineHeightRatio", 1.5);

        _fhwidget_inner = new FHWidget(_vwidget_middle);
        _vwidget_middle->addWidget(_fhwidget_inner, 0.0);
        _fhwidget_inner->setObjectName("_fhwidget_inner");
        _fhwidget_inner->setSaturateV(FHWidget::_esaturate_none);
        _fhwidget_inner->setAlignments({Qt::AlignHCenter | Qt::AlignVCenter, Qt::AlignHCenter | Qt::AlignVCenter});

        QPushButton* button0 = new QPushButton();
        _fhwidget_inner->addWidget(button0, 0.0);
        button0->setText("button0");
        QPushButton* button1 = new QPushButton();
        _fhwidget_inner->addWidget(button1, 0.0);
        button1->setText("button1");
        QPushButton* button2 = new QPushButton();
        _fhwidget_inner->addWidget(button2, 0.0);
        button2->setText("button2");
        QPushButton* button3 = new QPushButton();
        _fhwidget_inner->addWidget(button3, 0.0);
        button3->setText("button3");
        QPushButton* button4 = new QPushButton();
        _fhwidget_inner->addWidget(button4, 0.0);
        button4->setText("button4");
        QPushButton* button5 = new QPushButton();
        _fhwidget_inner->addWidget(button5, 0.0);
        button5->setText("button5");

        QLabel* label1 = new QLabel(_vwidget_middle);
        _vwidget_middle->addWidget(label1, 0.0);
        label1->setProperty("_lineHeightRatio", 1.5);
        label1->setWordWrap(true);
        QString info1 = "label1 label1 label1 label1 label1 label1 label1 label1 label1 label1";
        label1->setText(QString("<p style='line-height: %1'>").arg(1.5) + info1.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
		
        QObject::connect(_fhwidget_inner, &FHWidget::signalRelayout, _vwidget_middle, [this]() {
            qDebug().nospace() << "_fhwidget_inner->size() = " << _fhwidget_inner->size() << ", _fhwidget_inner->sizeHint() = " << _fhwidget_inner->sizeHint();
            _vwidget_middle->doLayout();
        });
        QObject::connect(_vwidget_middle, &VWidget::signalRelayout, _hwidget_outer, [this]() {
			qDebug().nospace() << "_vwidget_middle->size() = " << _vwidget_middle->size() << ", _vwidget_middle->sizeHint() = " << _vwidget_middle->sizeHint();
			_hwidget_outer->doLayout();
			_hwidget_outer->resize(_hwidget_outer->sizeHint());

			//static bool inited = false;
			//if (inited == false) {
			//	this->resize(_hwidget_outer->sizeHint());
			//	inited = true;
			//}
        });
    }
public:
    void resizeEvent(QResizeEvent *event) override {
        if(_label != nullptr) {
            qDebug().nospace() << __FUNCTION__ << ", label->hasHeightForWidth() = " << _label->hasHeightForWidth();
            _label->resize(this->width(), _label->heightForWidth(this->width()));
        }
        if(_vwidget != nullptr) {
            _vwidget->resize(this->width(), this->height());
        }
        if(_fvwidget != nullptr) {
            _fvwidget->resize(this->width(), this->height());
        }
        if(_hwidget != nullptr) {
            _hwidget->resize(this->width(), this->height());
        }
        if(_fhwidget != nullptr) {
            _fhwidget->resize(this->width(), this->height());
        }
        if(_hwidget_outer != nullptr) {
			_hwidget_outer->resize(this->width(), this->height());
        }
        return QWidget::resizeEvent(event);
    }
};
