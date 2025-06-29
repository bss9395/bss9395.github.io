#pragma once

#include <QWidget>
#include <QPushButton>
#include "FlowLayout.h"
#include "HWidget.h"
#include "VWidget.h"
#include "FHWidget.h"
#include "FVWidget.h"

class Window : public QWidget {
    Q_OBJECT

public:
    explicit Window() {
		// _Test_FlowLayout();
        // _Test_HWidget();
        // _Test_VWidget();
        _Test_FHWidget();
		// _Test_FVWidget();
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

    void _Test_HWidget() {
        this->resize(600, 400);
        QString qss = R"!(
        [objectName = "hwidget"] {
            background-color: "#FF0000";
        }
        )!";
        this->setStyleSheet(qss);

        _hwidget = new HWidget(this);
        _hwidget->setObjectName("hwidget");
		_hwidget->setFit(true);
        _hwidget->setMargins({20, 3, 4, 5});
        _hwidget->setSpacingH(10);
        _hwidget->setAlignments({Qt::AlignHCenter | Qt::AlignTop, Qt::AlignRight | Qt::AlignBottom});
        QPushButton* button0 = new QPushButton(_hwidget);
        QPushButton* button1 = new QPushButton(_hwidget);
        button0->setText("ButtonButonButtonButton");
        button1->setText("ButtonButonButtonButtonButtonButonButtonButton");
        button0->setMinimumHeight(200);
        _hwidget->addWidget(button0, 1.0);
        _hwidget->addWidget(button1, 0);
    }

    void _Test_VWidget() {
        this->resize(600, 400);
        QString qss = R"!(
        [objectName = "vwidget"] {
            background-color: "#FF0000";
        }
        )!";
        this->setStyleSheet(qss);

        _vwidget = new VWidget(this);
        _vwidget->setObjectName("vwidget");
		// _vwidget->setFit(true);
		_vwidget->setMargins({ 5, 5, 5, 5 });
		_vwidget->setSpacingV(10);
		_vwidget->setAlignments({ Qt::AlignLeft | Qt::AlignTop, Qt::AlignHCenter | Qt::AlignVCenter });
		QPushButton* button0 = new QPushButton(_vwidget);
		QPushButton* button1 = new QPushButton(_vwidget);
		button0->setText("ButtonButonButtonButton");
		button1->setText("ButtonButonButtonButtonButtonButonButtonButton");
		button0->setMinimumHeight(200);
		_vwidget->addWidget(button0, 0);
		_vwidget->addWidget(button1, 0);
    }

    void _Test_FHWidget() {
        qDebug().nospace() << __FUNCTION__;
        this->resize(600, 400);
        QString qss = R"!(
        [objectName = "fhwidget"] {
            background-color: "#FF0000";
        }
        )!";
        this->setStyleSheet(qss);

        _fhwidget = new FHWidget(this);
        _fhwidget->setObjectName("fhwidget");
		_fhwidget->setWrap(true);
		_fhwidget->setMargins({ 4, 5, 6, 7 });
		_fhwidget->setSpacings({ 8, 0 });
        QPushButton* button0 = new QPushButton("Short");
        QPushButton* button1 = new QPushButton("Even longer button text.");
        QPushButton* button2 = new QPushButton("Longer");
        QPushButton* button3 = new QPushButton("Different text");
        QPushButton* button4 = new QPushButton("More text");
        _fhwidget->addWidget(button0, 1.0);
        _fhwidget->addWidget(button1, 1.0);
        _fhwidget->addWidget(button2);
        _fhwidget->addWidget(button3);
        _fhwidget->addWidget(button4);
    }

	void _Test_FVWidget() {
		qDebug().nospace() << __FUNCTION__;
		this->resize(600, 400);
		QString qss = R"!(
        [objectName = "fvwidget"] {
            background-color: "#FF0000";
        }
        )!";
		this->setStyleSheet(qss);

		_fvwidget = new FVWidget(this);
		_fvwidget->setObjectName("fvwidget");
		_fvwidget->setWrap(true);
		_fvwidget->setMargins({ 4, 5, 6, 7 });
		_fvwidget->setSpacings({ 8, 4 });
		QPushButton* button0 = new QPushButton("Short");
		QPushButton* button1 = new QPushButton("Even longer button text.");
		QPushButton* button2 = new QPushButton("Longer");
		QPushButton* button3 = new QPushButton("Different text");
		QPushButton* button4 = new QPushButton("More text");
		_fvwidget->addWidget(button0);
		_fvwidget->addWidget(button1, 1.0);
		_fvwidget->addWidget(button2);
		_fvwidget->addWidget(button3);
		_fvwidget->addWidget(button4);
	}

    HWidget* _hwidget = nullptr;
    VWidget* _vwidget = nullptr;
    FHWidget* _fhwidget = nullptr;
	FVWidget* _fvwidget = nullptr;

public:
    void resizeEvent(QResizeEvent* event) override {
        qDebug() << __FUNCTION__ << ", event = " << event;
        if(_hwidget != nullptr) {
            _hwidget->resize(this->size());
        }
        if(_vwidget != nullptr) {
            _vwidget->resize(this->size());
        }
        if(_fhwidget != nullptr) {
            _fhwidget->resize(this->size());
        }
		if (_fvwidget != nullptr) {
			_fvwidget->resize(this->size());
		}
    }
};
