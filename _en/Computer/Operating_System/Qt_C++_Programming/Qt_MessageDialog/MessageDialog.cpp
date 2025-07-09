#include "MessageDialog.h"

MessageDialog::CustomScrollBar::CustomScrollBar(QWidget *parent)
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

MessageDialog::CustomScrollBar::~CustomScrollBar() {

}

MessageDialog::LabelFit::LabelFit(QWidget* parent)
	: QLabel(parent) {

}

MessageDialog::LabelFit::~LabelFit() {

}

void MessageDialog::LabelFit::adjustSizeFit(double lineHeightRatio) {
	this->adjustSize();
	this->style()->unpolish(this);
	this->style()->polish(this);
	QFontMetrics fontMetrics = this->fontMetrics();
	if (1.0 < lineHeightRatio) {
		this->resize(this->width(), this->height() - fontMetrics.height() * (lineHeightRatio - 1.0));
	}
}

MessageDialog::MessageDialog(QWidget* parent, const QString& title, EIcon eicon, const QString& info, const QPair<QString, QVector<QString>>& checks, const QPair<QString, QVector<QString>>& radios, const QVector<QString>& buttons)
	: QDialog(parent) {
	// _Fonts_Avaliable();
	_Dpi_Change();
	_Dpi_Auto();

	// this
	this->setObjectName("this");
    this->setWindowFlag(Qt::FramelessWindowHint, true);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setMouseTracking(true);

	// _this
    _this = new QWidget(this);
	_this->setObjectName("_this");
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(_this);
    shadowEffect->setColor(QColor("#28000000"));
    shadowEffect->setBlurRadius(20);
    shadowEffect->setOffset(0, 0);
    _this->setGraphicsEffect(shadowEffect);

	// _titlebar
    _titlebar = new QWidget(_this);
	_titlebar->setObjectName("_titlebar");

	// _titlebar_logo
	_titlebar_logo = new QLabel(_titlebar);
	_titlebar_logo->setObjectName("_titlebar_logo");
	_titlebar_logo->setPixmap(QPixmap(":/images/weixin.svg"));
	_titlebar_logo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	_titlebar_logo->setScaledContents(true);

	// _titlebar_title
	QString title_replaced = title;
	_titlebar_title = new LabelFit(_titlebar);
	_titlebar_title->setObjectName("_titlebar_title");
	_titlebar_title->setAttribute(Qt::WA_TransparentForMouseEvents, true);
	_titlebar_title->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + title_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
	// _titlebar_title->setText(title);
	_titlebar_title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	_titlebar_title->setWordWrap(true);

	// _titlebar_close
	_titlebar_close = new QLabel(_titlebar);
	_titlebar_close->setObjectName("_titlebar_close");
	_titlebar_close->installEventFilter(this);
	_titlebar_close->setPixmap(QPixmap(":/images/close.svg"));
	_titlebar_close->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	_titlebar_close->setScaledContents(true);

	// _mainbody
    _mainbody = new QWidget(_this);
	_mainbody->setObjectName("_mainbody");

	// _mainbody_scrollarea
	_mainbody_scrollarea = new QScrollArea(_mainbody);
	_mainbody_scrollarea->setObjectName("_mainbody_scrollarea");
    _mainbody_scrollarea->setFrameShape(QFrame::NoFrame);
	_mainbody_scrollarea->setWidgetResizable(false);  // 设置内部frame手动调整大小
    _mainbody_scrollarea->setHorizontalScrollBar(new CustomScrollBar(_mainbody_scrollarea));
    _mainbody_scrollarea->setVerticalScrollBar(new CustomScrollBar(_mainbody_scrollarea));
	_mainbody_scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_mainbody_scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

	// _mainbody_scrollarea_frame
    _mainbody_scrollarea_frame = new QWidget(_mainbody_scrollarea_frame);
    _mainbody_scrollarea->setWidget(_mainbody_scrollarea_frame);
	_mainbody_scrollarea_frame->setObjectName("_mainbody_scrollarea_frame");

	// _mainbody_scrollarea_frame_icon
	QString icon_path = "";
	if (eicon == MessageDialog::_eicon_information) {
		icon_path = ":/images/information.svg";
	} else if (eicon == MessageDialog::_eicon_question) {
		icon_path = ":/images/question.svg";
	} else if (eicon == MessageDialog::_eicon_warning) {
		icon_path = ":/images/warning.svg";
	} else if (eicon == MessageDialog::_eicon_correct) {
		icon_path = ":/images/correct.svg";
	} else if (eicon == MessageDialog::_eicon_error) {
		icon_path = ":/images/error.svg";
	}
	_mainbody_scrollarea_frame_icon = new QLabel(_mainbody_scrollarea_frame);
	_mainbody_scrollarea_frame_icon->setObjectName("_mainbody_scrollarea_frame_icon");
	_mainbody_scrollarea_frame_icon->setPixmap(QPixmap(icon_path));
	_mainbody_scrollarea_frame_icon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	_mainbody_scrollarea_frame_icon->setScaledContents(true);

	// _mainbody_scrollarea_frame_content
    _mainbody_scrollarea_frame_content = new QWidget(_mainbody_scrollarea_frame);
	_mainbody_scrollarea_frame_content->setObjectName("_mainbody_scrollarea_frame_content");

	// _mainbody_scrollarea_frame_content_info
	if (info.isEmpty() == false) {
		QString info_replaced = info;
		_mainbody_scrollarea_frame_content_info = new LabelFit(_mainbody_scrollarea_frame_content);
		_mainbody_scrollarea_frame_content_info->setObjectName("_mainbody_scrollarea_frame_content_info");
		_mainbody_scrollarea_frame_content_info->setAttribute(Qt::WA_TransparentForMouseEvents, true);
		_mainbody_scrollarea_frame_content_info->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + info_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
		_mainbody_scrollarea_frame_content_info->setAlignment(Qt::AlignLeft | Qt::AlignTop);
		_mainbody_scrollarea_frame_content_info->setWordWrap(true);
	}

	// _mainbody_scrollarea_frame_content_checktip
	if (checks.first.isEmpty() == false) {
		QString checktip_replaced = checks.first;
		_mainbody_scrollarea_frame_content_checktip = new LabelFit(_mainbody_scrollarea_frame_content);
		_mainbody_scrollarea_frame_content_checktip->setObjectName("_mainbody_scrollarea_frame_content_checktip");
		_mainbody_scrollarea_frame_content_checktip->setAttribute(Qt::WA_TransparentForMouseEvents, true);
		_mainbody_scrollarea_frame_content_checktip->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + checktip_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
		_mainbody_scrollarea_frame_content_checktip->setAlignment(Qt::AlignLeft | Qt::AlignTop);
		_mainbody_scrollarea_frame_content_checktip->setWordWrap(true);
	}

	// _mainbody_scrollarea_frame_content_checkbox
	for (int i = 0; i < checks.second.size(); i += 1) {
		QCheckBox* checkbox = new QCheckBox(_mainbody_scrollarea_frame_content);
		checkbox->setObjectName(QString("_mainbody_scrollarea_frame_content_checkbox%1").arg(i));
		checkbox->installEventFilter(this);
		checkbox->setText(checks.second[i]);
		_mainbody_scrollarea_frame_content_checkboxs.push_back(checkbox);
	}

	// _mainbody_scrollarea_frame_content_radiotip
	if (radios.first.isEmpty() == false) {
		QString radiotip_replaced = radios.first;
		_mainbody_scrollarea_frame_content_radiotip = new LabelFit(_mainbody_scrollarea_frame_content);
		_mainbody_scrollarea_frame_content_radiotip->setObjectName("_mainbody_scrollarea_frame_content_radiotip");
		_mainbody_scrollarea_frame_content_radiotip->setAttribute(Qt::WA_TransparentForMouseEvents, true);
		_mainbody_scrollarea_frame_content_radiotip->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + radiotip_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
		_mainbody_scrollarea_frame_content_radiotip->setAlignment(Qt::AlignLeft | Qt::AlignTop);
		_mainbody_scrollarea_frame_content_radiotip->setWordWrap(true);
	}

	// _mainbody_scrollarea_frame_content_radiobutton
	QButtonGroup *radiobuttonGroup = new QButtonGroup(_mainbody_scrollarea_frame_content);
	radiobuttonGroup->setObjectName("_mainbody_scrollarea_frame_content_radiobuttongroup");
	for (int i = 0; i < radios.second.size(); i += 1) {
		QRadioButton* radiobutton = new QRadioButton(_mainbody_scrollarea_frame_content);
		radiobuttonGroup->addButton(radiobutton);
		radiobutton->setObjectName(QString("_mainbody_scrollarea_frame_content_radiobutton%1").arg(i));
		radiobutton->installEventFilter(this);
		radiobutton->setText(radios.second[i]);
		_mainbody_scrollarea_frame_content_radiobuttons.push_back(radiobutton);
	}

	// mainbody_buttonbox
    _mainbody_buttonbox = new QWidget(_mainbody);
	_mainbody_buttonbox->setObjectName("_mainbody_buttonbox");

	// mainbody_buttonbox_button
    for (int i = 0; i < buttons.size(); i += 1) {
		QLabel* button = new QLabel(_mainbody_buttonbox);
		button->setObjectName(QString("_mainbody_buttonbox_button%1").arg(i));
		button->installEventFilter(this);
        button->setText(buttons[i]);
		button->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        _mainbody_buttonbox_buttons.push_back(button);
	}
}

MessageDialog::~MessageDialog() {

}

void MessageDialog::_Fonts_Avaliable() {
	qDebug() << "Application font: " << QGuiApplication::font().family();

	QStringList fontFamilies = QFontDatabase().families();
	qDebug() << "Available font families: ";
	for (int i = 0; i < fontFamilies.size(); i += 1) {
		qDebug() << fontFamilies[i];
	}
}

QString MessageDialog::_Format(const QString& format, const QVector<QPair<QString, QVariant>>& values) {
    QString result = format;
    for (int i = 0; i < values.size(); i += 1) {
        QRegularExpression expression = QRegularExpression("[{]{1,1}[ ]{0,}" + values[i].first + "[ ]{0,}[}]{1,1}", QRegularExpression::DotMatchesEverythingOption);
        result.replace(expression, values[i].second.toString());
    }
    return result;
}

void MessageDialog::_Dpi_Change() {
    QList<QScreen*> screens = QApplication::screens();
    for (int i = 0; i < screens.size(); i += 1) {
        QScreen* screen = screens[i];
        QObject::connect(screen, &QScreen::logicalDotsPerInchChanged, [this, i, screen](qreal dpi_logical) {
            // qDebug().nospace() << "Screen[" << i << "]" << "  dpi logical = " << dpi_logical;
            (void)dpi_logical;
            update();
        });
    }
}

void MessageDialog::_Dpi_Auto() {
	// 加载json变量表
    static const QJsonObject this_json = [](const QString& json_file) -> QJsonObject {
		QJsonObject this_json;
		QFile file(json_file);
		bool retu = file.open(QFile::ReadOnly | QFile::Text);
		if (retu == false) {
			// qDebug() << "加载json变量表失败！";
			return this_json;
		}
		QString json_string = file.readAll();
		file.close();
		// qDebug().noquote() << "json_string = " << json_string;
		QJsonDocument json_document = QJsonDocument::fromJson(json_string.toUtf8());
		if (json_document.isObject() == false) {
			qDebug() << "加载json变量表失败！";
			return this_json;
		}
		this_json = json_document.object();
		return this_json;
	}(":/styles/this.json");

	// 加载qss样式表
    static const QString this_qss = [](const QString& qss_file) -> QString {
		QString this_qss = "";
		QFile file(qss_file);
		bool retu = file.open(QFile::ReadOnly | QFile::Text);
		if (retu == false) {
			// qDebug() << "加载qss样式表失败！";
			return this_qss;
		}
		this_qss = file.readAll();
		file.close();
		// qDebug().noquote() << "this_qss = " << this_qss;
		return this_qss;
	}(":/styles/this.qss");

	// 加载json变量值
	static const int edge_length = this_json["_edge_length"].toInt(0);
	static const int this_minWidth = this_json["_this_minWidth"].toInt(0);
	static const int this_minHeight = this_json["_this_minHeight"].toInt(0);
	static const int titlebar_height = this_json["_titlebar_height"].toInt(0);
	static const int titlebar_paddingL = this_json["_titlebar_paddingL"].toInt(0);
	static const int titlebar_paddingR = this_json["_titlebar_paddingR"].toInt(0);
	static const int titlebar_logo_width = this_json["_titlebar_logo_width"].toInt(0);
	static const int titlebar_logo_height = this_json["_titlebar_logo_height"].toInt(0);
	static const int titlebar_title_marginL = this_json["_titlebar_title_marginL"].toInt(0);
	static const int titlebar_close_width = this_json["_titlebar_close_width"].toInt(0);
	static const int titlebar_close_height = this_json["_titlebar_close_height"].toInt(0);
	static const int titlebar_close_marginL = this_json["_titlebar_close_marginL"].toInt(0);
	static const int mainbody_scrollarea_frame_paddingL = this_json["_mainbody_scrollarea_frame_paddingL"].toInt(0);
	static const int mainbody_scrollarea_frame_paddingT = this_json["_mainbody_scrollarea_frame_paddingT"].toInt(0);
	static const int mainbody_scrollarea_frame_paddingR = this_json["_mainbody_scrollarea_frame_paddingR"].toInt(0);
	static const int mainbody_scrollarea_frame_paddingB_inited = this_json["_mainbody_scrollarea_frame_paddingB_inited"].toInt(0);
	static const int mainbody_scrollarea_frame_spacing = this_json["_mainbody_scrollarea_frame_spacing"].toInt(0);
	static const int mainbody_scrollarea_frame_icon_width = this_json["_mainbody_scrollarea_frame_icon_width"].toInt(0);
	static const int mainbody_scrollarea_frame_icon_height = this_json["_mainbody_scrollarea_frame_icon_height"].toInt(0);
	static const int mainbody_scrollarea_frame_content_marginL = this_json["_mainbody_scrollarea_frame_content_marginL"].toInt(0);
	static const int mainbody_scrollarea_frame_content_checkbox_spacing = this_json["_mainbody_scrollarea_frame_content_checkbox_spacing"].toInt(0);
	static const int mainbody_scrollarea_frame_content_radiobutton_spacing = this_json["_mainbody_scrollarea_frame_content_radiobutton_spacing"].toInt(0);
	static const int mainbody_buttonbox_height = this_json["_mainbody_buttonbox_height"].toInt(0);
	static const int mainbody_buttonbox_paddingL = this_json["_mainbody_buttonbox_paddingL"].toInt(0);
	static const int mainbody_buttonbox_paddingR = this_json["_mainbody_buttonbox_paddingR"].toInt(0);
	static const int mainbody_buttonbox_button_width = this_json["_mainbody_buttonbox_button_width"].toInt(0);
	static const int mainbody_buttonbox_button_height = this_json["_mainbody_buttonbox_button_height"].toInt(0);
	static const int mainbody_buttonbox_button_spacing = this_json["_mainbody_buttonbox_button_spacing"].toInt(0);
	static const double line_height_ratio = this_json["_line_height_ratio"].toDouble(0.0);
	static const int titlebar_title_fontsize = this_json["_titlebar_title_fontsize"].toInt(0);
	static const int mainbody_scrollarea_frame_content_info_fontsize = this_json["_mainbody_scrollarea_frame_content_info_fontsize"].toInt(0);
	static const int mainbody_scrollarea_frame_content_checktip_fontsize = this_json["_mainbody_scrollarea_frame_content_checktip_fontsize"].toInt(0);
	static const int mainbody_scrollarea_frame_content_checkbox_fontsize = this_json["_mainbody_scrollarea_frame_content_checkbox_fontsize"].toInt(0);
	static const int mainbody_scrollarea_frame_content_radiotip_fontsize = this_json["_mainbody_scrollarea_frame_content_radiotip_fontsize"].toInt(0);
	static const int mainbody_scrollarea_frame_content_radiobutton_fontsize = this_json["_mainbody_scrollarea_frame_content_radiobutton_fontsize"].toInt(0);
	static const int mainbody_buttonbox_button_fontsize = this_json["_mainbody_buttonbox_button_fontsize"].toInt(0);

	// 获取屏幕dpi
	QWindow* window = this->windowHandle();
	if (window != nullptr) {
		double dpi_logical = window->screen()->logicalDotsPerInch();
		_scale = dpi_logical / 96.0;
		// qDebug() << "_scale = " << _scale;

		// 设置变量值
		_edge_length = edge_length * _scale;
		_this_minWidth = this_minWidth * _scale;     // 建议宽度
		_this_minHeight = this_minHeight * _scale;   // 建议高度
		_titlebar_height = titlebar_height * _scale;
		_titlebar_paddingL = titlebar_paddingL * _scale;
		_titlebar_paddingR = titlebar_paddingR * _scale;
		_titlebar_logo_width = titlebar_logo_width * _scale;
		_titlebar_logo_height = titlebar_logo_height * _scale;
		_titlebar_title_marginL = titlebar_title_marginL * _scale;
		_titlebar_close_width = titlebar_close_width * _scale;
		_titlebar_close_height = titlebar_close_height * _scale;
		_titlebar_close_marginL = titlebar_close_marginL * _scale;
		_mainbody_scrollarea_frame_paddingL = mainbody_scrollarea_frame_paddingL * _scale;
		_mainbody_scrollarea_frame_paddingT = mainbody_scrollarea_frame_paddingT * _scale;
		_mainbody_scrollarea_frame_paddingR = mainbody_scrollarea_frame_paddingR * _scale;
		_mainbody_scrollarea_frame_paddingB_inited = mainbody_scrollarea_frame_paddingB_inited * _scale;
		_mainbody_scrollarea_frame_spacing = mainbody_scrollarea_frame_spacing * _scale;
		_mainbody_scrollarea_frame_icon_width = mainbody_scrollarea_frame_icon_width * _scale;
		_mainbody_scrollarea_frame_icon_height = mainbody_scrollarea_frame_icon_height * _scale;
		_mainbody_scrollarea_frame_content_marginL = mainbody_scrollarea_frame_content_marginL * _scale;
		_mainbody_scrollarea_frame_content_checkbox_spacing = mainbody_scrollarea_frame_content_checkbox_spacing * _scale;
		_mainbody_scrollarea_frame_content_radiobutton_spacing = mainbody_scrollarea_frame_content_radiobutton_spacing * _scale;
		_mainbody_buttonbox_height = mainbody_buttonbox_height * _scale;
		_mainbody_buttonbox_paddingL = mainbody_buttonbox_paddingL * _scale;
		_mainbody_buttonbox_paddingR = mainbody_buttonbox_paddingR * _scale;
		_mainbody_buttonbox_button_width = mainbody_buttonbox_button_width * _scale;
		_mainbody_buttonbox_button_height = mainbody_buttonbox_button_height * _scale;
		_mainbody_buttonbox_button_spacing = mainbody_buttonbox_button_spacing * _scale;

		// 设置qss样式
		_this_qss = _Format(this_qss, {
			{ "_titlebar_title_fontsize", (int)(titlebar_title_fontsize * _scale) },
			{ "_mainbody_scrollarea_frame_content_info_fontsize", (int)(mainbody_scrollarea_frame_content_info_fontsize * _scale) },
			{ "_mainbody_scrollarea_frame_content_checktip_fontsize", (int)(mainbody_scrollarea_frame_content_checktip_fontsize * _scale) },
			{ "_mainbody_scrollarea_frame_content_checkbox_fontsize", (int)(mainbody_scrollarea_frame_content_checkbox_fontsize * _scale) },
			{ "_mainbody_scrollarea_frame_content_radiotip_fontsize", (int)(mainbody_scrollarea_frame_content_radiotip_fontsize * _scale) },
			{ "_mainbody_scrollarea_frame_content_radiobutton_fontsize", (int)(mainbody_scrollarea_frame_content_radiobutton_fontsize * _scale) },
			{ "_mainbody_buttonbox_button_fontsize", (int)(mainbody_buttonbox_button_fontsize * _scale) }
			});
	}
	_line_height_ratio = line_height_ratio;
}

int MessageDialog::_OffsetFore(int boxLen, int selfLen) {
	int offset = (boxLen - selfLen) / 2;
	return offset;
}

int MessageDialog::_Resizing_Enable(const QPoint& local) {
	int resizing = _edge_none;
    if (this->width() - _edge_length <= local.x() && local.x() < this->width()) {
		resizing |= _edge_right;
    } else if (0 <= local.x() && local.x() < _edge_length) {
		resizing |= _edge_left;
	}
    if (this->height() - _edge_length <= local.y() && local.y() < this->height()) {
		resizing |= _edge_bottom;
    } else if (0 <= local.y() && local.y() < _edge_length) {
		resizing |= _edge_top;
	}
	return resizing;
}

bool MessageDialog::_Dragging_Enable(const QPoint& local) {
	bool dragging = false;
    QPoint topLeft = _titlebar->mapTo(this, _titlebar->rect().topLeft());
    QPoint bottomRight = _titlebar->mapTo(this, _titlebar->rect().bottomRight());
    if(topLeft.x() <= local.x() && local.x() < bottomRight.x() && topLeft.y() <= local.y() && local.y() < bottomRight.y()) {
		dragging = true;
	}
	return dragging;
}

bool MessageDialog::eventFilter(QObject *watched, QEvent *event) {
	if (event->type() == QEvent::MouseButtonRelease) {
		if (watched == _titlebar_close) {
			emit this->_Signal_Close();
		} else if (watched->objectName().startsWith("_mainbody_scrollarea_frame_content_checkbox")) {
			QCheckBox* checkbox = qobject_cast<QCheckBox*>(watched);
            bool checked = !checkbox->isChecked();       // checkbox还未更新其checked状态
            emit this->_Signal_Checkbox(checkbox->text(), checked);
		} else if (watched->objectName().startsWith("_mainbody_scrollarea_frame_content_radiobutton")) {
			QRadioButton* radiobutton = qobject_cast<QRadioButton*>(watched);
            bool checked = !radiobutton->isChecked();    // radiobutton还未更新其checked状态
            emit this->_Signal_Radiobutton(radiobutton->text(), checked);
		} else if (watched->objectName().startsWith("_mainbody_buttonbox_button")) {
			QLabel* button = qobject_cast<QLabel*>(watched);
			emit this->_Signal_Button(button->text());
		}
	}
	return QDialog::eventFilter(watched, event);
}

void MessageDialog::resizeEvent(QResizeEvent *event) {
    qDebug() << __FUNCTION__ << ", event = " << event;
	(void)event;

	_Dpi_Auto();  // 根据dpi动态调整
	this->setStyleSheet(_this_qss);
	this->setMinimumWidth(_edge_length + _this_minWidth + _edge_length);
	this->setMinimumHeight(_edge_length + _this_minHeight + _edge_length);

	// _this
	_this->setFixedWidth(this->width() - _edge_length - _edge_length);
	_this->setFixedHeight(this->height() - _edge_length - _edge_length);
	_this->move(_edge_length, _edge_length);

	// _titlebar
	_titlebar->setFixedWidth(_this->width());
	_titlebar->setFixedHeight(_titlebar_height);
	_titlebar->move(0, 0);

	// _titlebar_logo
	_titlebar_logo->setFixedWidth(_titlebar_logo_width);
	_titlebar_logo->setFixedHeight(_titlebar_logo_height);
	_titlebar_logo->move(_titlebar_paddingL, _OffsetFore(_titlebar->height(), _titlebar_logo->height()));

	// _titlebar_close
	_titlebar_close->setFixedWidth(_titlebar_close_width);
	_titlebar_close->setFixedHeight(_titlebar_close_height);
	_titlebar_close->move(_titlebar->width() - _titlebar_close->width() - _titlebar_paddingR, _OffsetFore(_titlebar->height(), _titlebar_close->height()));

	// _titlebar_title
	_titlebar_title->setFixedWidth(_titlebar->width() - _titlebar_paddingL - _titlebar_logo->width() - _titlebar_title_marginL - (_titlebar_close_marginL + _titlebar_close->width()) - _titlebar_paddingR);
	_titlebar_title->adjustSizeFit(_line_height_ratio);
	_titlebar_title->move(_titlebar_paddingL + _titlebar_logo->width() + _titlebar_title_marginL, _OffsetFore(_titlebar->height(), _titlebar_title->height()));

	// _mainbody
	_mainbody->setFixedWidth(_this->width());
	_mainbody->setFixedHeight(_this->height() - _titlebar_height);
	_mainbody->move(0, _titlebar_height);

	// _mainbody_buttonbox
	_mainbody_buttonbox->setFixedWidth(_mainbody->width());
	_mainbody_buttonbox->setFixedHeight(_mainbody_buttonbox_height);
	_mainbody_buttonbox->move(0, _mainbody->height() - _mainbody_buttonbox->height());

	// _mainbody_buttonbox_button
	int mainbody_buttonbox_button_lastL = _mainbody_buttonbox->width() - _mainbody_buttonbox_paddingR;
	for (int i = _mainbody_buttonbox_buttons.size() - 1; 0 <= i; i -= 1) {
		QLabel* button = _mainbody_buttonbox_buttons[i];
		button->setFixedWidth(_mainbody_buttonbox_button_width);
		button->setFixedHeight(_mainbody_buttonbox_button_height);
		button->move(mainbody_buttonbox_button_lastL - button->width(), _OffsetFore(_mainbody_buttonbox->height(), button->height()));
		mainbody_buttonbox_button_lastL -= (_mainbody_buttonbox_button_spacing + button->width());
	}

	// _mainbody_scrollarea
	_mainbody_scrollarea->setFixedWidth(_mainbody->width());
	_mainbody_scrollarea->setFixedHeight(_mainbody->height() - _mainbody_buttonbox->height());
	_mainbody_scrollarea->move(0, 0);

	// _mainbody_scrollarea_frame_icon
	_mainbody_scrollarea_frame_icon->setFixedWidth(_mainbody_scrollarea_frame_icon_width);
	_mainbody_scrollarea_frame_icon->setFixedHeight(_mainbody_scrollarea_frame_icon_height);
	_mainbody_scrollarea_frame_icon->move(_mainbody_scrollarea_frame_paddingL, _mainbody_scrollarea_frame_paddingT);

	// _mainbody_scrollarea_frame_content
	_mainbody_scrollarea_frame_content->setFixedWidth(_mainbody_scrollarea->width() - _mainbody_scrollarea_frame_paddingL - _mainbody_scrollarea_frame_icon->width() - _mainbody_scrollarea_frame_content_marginL - _mainbody_scrollarea_frame_paddingR);
	_mainbody_scrollarea_frame_content->adjustSize();
	_mainbody_scrollarea_frame_content->move(_mainbody_scrollarea_frame_paddingL + _mainbody_scrollarea_frame_icon->width() + _mainbody_scrollarea_frame_content_marginL, _mainbody_scrollarea_frame_paddingT);

	QWidget* firstLabel = nullptr;
	QWidget* prevWidget = nullptr;
	int lastHeight = 0;
	// _mainbody_scrollarea_frame_content_info
	if (_mainbody_scrollarea_frame_content_info != nullptr) {
		_mainbody_scrollarea_frame_content_info->setFixedWidth(_mainbody_scrollarea_frame_content->width());
		_mainbody_scrollarea_frame_content_info->adjustSizeFit(_line_height_ratio);
		_mainbody_scrollarea_frame_content_info->move(0, 0);
		if (firstLabel == nullptr) {
			firstLabel = _mainbody_scrollarea_frame_content_info;
		}
		lastHeight = _mainbody_scrollarea_frame_content_info->geometry().bottom() + _mainbody_scrollarea_frame_spacing;
	}

	// _mainbody_scrollarea_frame_content_checktip
	if (_mainbody_scrollarea_frame_content_checktip != nullptr) {
		_mainbody_scrollarea_frame_content_checktip->setFixedWidth(_mainbody_scrollarea_frame_content->width());
		_mainbody_scrollarea_frame_content_checktip->adjustSizeFit(_line_height_ratio);
		_mainbody_scrollarea_frame_content_checktip->move(0, lastHeight);
		if (firstLabel == nullptr) {
			firstLabel = _mainbody_scrollarea_frame_content_checktip;
		}
		lastHeight = _mainbody_scrollarea_frame_content_checktip->geometry().bottom() + _mainbody_scrollarea_frame_spacing;
	}

	// _mainbody_scrollarea_frame_content_checkbox
	prevWidget = nullptr;
	int mainbody_scrollarea_frame_content_checkbox_lastL = 0;
	for (int i = 0; i < _mainbody_scrollarea_frame_content_checkboxs.size(); i += 1) {
		QCheckBox* checkbox = _mainbody_scrollarea_frame_content_checkboxs[i];
		checkbox->adjustSize();
		if (mainbody_scrollarea_frame_content_checkbox_lastL + checkbox->width() <= _mainbody_scrollarea_frame_content->width()) {
			checkbox->move(mainbody_scrollarea_frame_content_checkbox_lastL, lastHeight);
			mainbody_scrollarea_frame_content_checkbox_lastL += checkbox->width() + _mainbody_scrollarea_frame_content_checkbox_spacing;
		} else {
			if (prevWidget != nullptr) {
				lastHeight = prevWidget->geometry().bottom() + _mainbody_scrollarea_frame_spacing;
			}
			mainbody_scrollarea_frame_content_checkbox_lastL = 0;
			checkbox->move(mainbody_scrollarea_frame_content_checkbox_lastL, lastHeight);
			mainbody_scrollarea_frame_content_checkbox_lastL += checkbox->width() + _mainbody_scrollarea_frame_content_checkbox_spacing;
		}
		if (firstLabel == nullptr) {
			firstLabel = checkbox;
		}
		prevWidget = checkbox;
	}
	if (prevWidget != nullptr) {
		lastHeight = prevWidget->geometry().bottom() + _mainbody_scrollarea_frame_spacing;
	}

	// _mainbody_scrollarea_frame_content_radiotip
	if (_mainbody_scrollarea_frame_content_radiotip != nullptr) {
		_mainbody_scrollarea_frame_content_radiotip->setFixedWidth(_mainbody_scrollarea_frame_content->width());
		_mainbody_scrollarea_frame_content_radiotip->adjustSizeFit(_line_height_ratio);
		_mainbody_scrollarea_frame_content_radiotip->move(0, lastHeight);
		if (firstLabel == nullptr) {
			firstLabel = _mainbody_scrollarea_frame_content_radiotip;
		}
		lastHeight = _mainbody_scrollarea_frame_content_radiotip->geometry().bottom() + _mainbody_scrollarea_frame_spacing;
	}

	// _mainbody_scrollarea_frame_content_radiobutton
	prevWidget = nullptr;
	int mainbody_scrollarea_frame_content_radiobutton_lastL = 0;
	for (int j = 0; j < _mainbody_scrollarea_frame_content_radiobuttons.size(); j += 1) {
		QRadioButton* radiobutton = _mainbody_scrollarea_frame_content_radiobuttons[j];
		radiobutton->adjustSize();
		if (mainbody_scrollarea_frame_content_radiobutton_lastL + radiobutton->width() <= _mainbody_scrollarea_frame_content->width()) {
			radiobutton->move(mainbody_scrollarea_frame_content_radiobutton_lastL, lastHeight);
			mainbody_scrollarea_frame_content_radiobutton_lastL += radiobutton->width() + _mainbody_scrollarea_frame_content_radiobutton_spacing;
		} else {
			if (prevWidget != nullptr) {
				lastHeight = prevWidget->geometry().bottom() + _mainbody_scrollarea_frame_spacing;
			}
			mainbody_scrollarea_frame_content_radiobutton_lastL = 0;
			radiobutton->move(mainbody_scrollarea_frame_content_radiobutton_lastL, lastHeight);
			mainbody_scrollarea_frame_content_radiobutton_lastL += radiobutton->width() + _mainbody_scrollarea_frame_content_radiobutton_spacing;
		}
		if (firstLabel == nullptr) {
			firstLabel = prevWidget;
		}
		prevWidget = radiobutton;
	}
	if (prevWidget != nullptr) {
		lastHeight = prevWidget->geometry().bottom();
		(void)lastHeight;
	}

	// _mainbody_scrollarea_frame_icon & _mainbody_scrollarea_frame_content
	if (firstLabel != nullptr) {
		int mainbody_scrollarea_frame_iconContent_offsetY = 0;
		if (firstLabel->inherits("QLabel") == true) {
			firstLabel->style()->unpolish(firstLabel);
			firstLabel->style()->polish(firstLabel);
			QFontMetrics firstLabel_fontMetrics = firstLabel->fontMetrics();
			mainbody_scrollarea_frame_iconContent_offsetY = _OffsetFore(_mainbody_scrollarea_frame_icon->height(), firstLabel_fontMetrics.height());
		} else {
			mainbody_scrollarea_frame_iconContent_offsetY = _OffsetFore(_mainbody_scrollarea_frame_icon->height(), firstLabel->height());
		}

		if (0 <= mainbody_scrollarea_frame_iconContent_offsetY) {
			_mainbody_scrollarea_frame_content->move(_mainbody_scrollarea_frame_content->x(), _mainbody_scrollarea_frame_content->y() + mainbody_scrollarea_frame_iconContent_offsetY);
		} else {
			_mainbody_scrollarea_frame_icon->move(_mainbody_scrollarea_frame_icon->x(), _mainbody_scrollarea_frame_icon->y() - mainbody_scrollarea_frame_iconContent_offsetY);
		}
	}

	// _mainbody_scrollarea_frame
	_mainbody_scrollarea_frame_content->adjustSize();
	_mainbody_scrollarea_frame->setMinimumWidth(0);
	_mainbody_scrollarea_frame->setMinimumHeight(0);
	// _mainbody_scrollarea_frame->adjustSize();    // QSrollArea->setWidgetResizable(false);
	_mainbody_scrollarea_frame->setFixedWidth(_mainbody_scrollarea_frame_content->geometry().right());    // adjustSize()不准确
	_mainbody_scrollarea_frame->setFixedHeight(_mainbody_scrollarea_frame_content->geometry().bottom());  // adjustSize()不准确
	_mainbody_scrollarea_frame->setMinimumWidth(_mainbody_scrollarea_frame->width());
	_mainbody_scrollarea_frame->setMinimumHeight(_mainbody_scrollarea_frame->height());
	if (_first_inited == false) {
		_mainbody_scrollarea_frame->setFixedHeight(_mainbody_scrollarea_frame->height() + +_mainbody_scrollarea_frame_paddingB_inited);
		_mainbody_scrollarea_frame->setMinimumWidth(_mainbody_scrollarea_frame->width());
		_mainbody_scrollarea_frame->setMinimumHeight(_mainbody_scrollarea_frame->height());
		_mainbody_scrollarea->setFixedHeight(_mainbody_scrollarea_frame->height());
		_mainbody_buttonbox->move(0, _mainbody_scrollarea->y() + _mainbody_scrollarea->height());
		_mainbody->setFixedHeight(_mainbody_buttonbox->y() + _mainbody_buttonbox->height());
		_this->setFixedHeight(_titlebar->height() + _mainbody->height());
		this->setFixedHeight(_edge_length + _this->height() + _edge_length);

        // 居中对齐在父级顶层控件中央
        QWidget *parentWidget = this->parentWidget();
        QRect toplevelGeometry = (parentWidget == nullptr)? this->screen()->geometry() : parentWidget->topLevelWidget()->frameGeometry();
        this->move(toplevelGeometry.x() + (toplevelGeometry.width() - this->width()) / 2, toplevelGeometry.y() + (toplevelGeometry.height() - this->height()) / 2);
	}

	_first_inited = true;
}

void MessageDialog::paintEvent(QPaintEvent *event) {
    qDebug() << __FUNCTION__ << ", event = " << event;
    (void)event;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    brush.setColor("#01FFFFFF");
    painter.setBrush(brush);
    painter.setPen(QPen(Qt::NoPen));
    painter.drawRoundedRect(this->rect(), 2, 2);  // 绘制透明背景，无边框

    QPen pen;
    pen.setWidth(2);
    pen.setStyle(Qt::PenStyle::SolidLine);
    pen.setColor(QColor("#FFC7CDD5"));
    painter.setBrush(QBrush(Qt::NoBrush));
    painter.setPen(pen);
    painter.drawRect(_this->geometry());  // 绘制边框线，无填充
}

void MessageDialog::mousePressEvent(QMouseEvent *event) {
    qDebug().noquote() << __FUNCTION__ << ", event = " << event;
	if (event->button() == Qt::LeftButton) {
		_resizing = _edge_none;    // 重置缩放状态
		_dragging = false;         // 重置拖拽状态
		if ((_resizing = _Resizing_Enable(event->pos())) != _edge_none ||
			(_dragging = _Dragging_Enable(event->pos()) == true)) {
			_press_global = event->globalPos();
			_press_geometry = this->geometry();
		}
	}
}

void MessageDialog::mouseMoveEvent(QMouseEvent *event) {
    qDebug().nospace() << __FUNCTION__ << ", event = " << event;
	if (event->buttons() & Qt::LeftButton) {
		if (_resizing != _edge_none) {
			QPoint move_global = event->globalPos();
			int driftX = move_global.x() - _press_global.x();
			int driftY = move_global.y() - _press_global.y();
			int x = _press_geometry.x();
			int y = _press_geometry.y();
			int width = _press_geometry.width();
			int height = _press_geometry.height();
			if (_resizing & _edge_right) {
				width = width + driftX;
				if (width < _edge_length + _this_minWidth + _edge_length) {
					width = _edge_length + _this_minWidth + _edge_length;
				}
			} else if (_resizing & _edge_left) {
				width = width - driftX;
				if (width < _edge_length + _this_minWidth + _edge_length) {
					width = _edge_length + _this_minWidth + _edge_length;
				}
				x = x + _press_geometry.width() - width;
			}
			if (_resizing & _edge_bottom) {
				height = height + driftY;
				if (height < _edge_length + _this_minHeight + _edge_length) {
					height = _edge_length + _this_minHeight + _edge_length;
				}
			} else if (_resizing & _edge_top) {
				height = height - driftY;
				if (height < _edge_length + _this_minHeight + _edge_length) {
					height = _edge_length + _this_minHeight + _edge_length;
				}
				y = y + _press_geometry.height() - height;
			}
			this->setFixedWidth(width);
			this->setFixedHeight(height);
			this->move(x, y);
		} else if (_dragging == true) {
			QPoint move_global = event->globalPos();
			int driftX = move_global.x() - _press_global.x();
			int driftY = move_global.y() - _press_global.y();
			this->move(_press_geometry.x() + driftX, _press_geometry.y() + driftY);
		}
	}

	// 更改鼠标样式
	if (_resizing == _edge_none) {
        this->grabMouse();
		int resizing = _Resizing_Enable(event->pos());
        qDebug() << "resizing = " << resizing;
		if (resizing == _edge_left || resizing == _edge_right) {
			this->setCursor(Qt::SizeHorCursor);
		} else if (resizing == _edge_top || resizing == _edge_bottom) {
			this->setCursor(Qt::SizeVerCursor);
		} else if (resizing == (_edge_left | _edge_top) || resizing == (_edge_right | _edge_bottom)) {
			this->setCursor(Qt::SizeFDiagCursor);
		} else if (resizing == (_edge_left | _edge_bottom) || resizing == (_edge_right | _edge_top)) {
			this->setCursor(Qt::SizeBDiagCursor);
		} else {
            this->releaseMouse();
			this->setCursor(Qt::ArrowCursor);
		}
	}
}

void MessageDialog::mouseReleaseEvent(QMouseEvent *event) {
    qDebug().noquote() << __FUNCTION__ << ", event = " << event;
	if (event->button() == Qt::LeftButton) {
		_resizing = _edge_none;
		_dragging = false;
		this->setCursor(Qt::ArrowCursor);
	}
}

////////////////////////////////////////////////////////////////////////////////

void MessageDialog::_InformationDialog(QWidget* parent, const QString& title, MessageDialog::EIcon eicon, const QString& info, const QString& button) {
	QPair<QString, QVector<QString>> checks;
	QPair<QString, QVector<QString>> radios;
    MessageDialog* messageDialog = new MessageDialog(parent, title, eicon, info, checks, radios, { button });

    QObject::connect(messageDialog, &MessageDialog::_Signal_Close, [messageDialog]() {
        messageDialog->close();
	});
    QObject::connect(messageDialog, &MessageDialog::_Signal_Button, [messageDialog](const QString& button) {
		(void)button;
        messageDialog->close();
	});

    messageDialog->exec();
    messageDialog->deleteLater();
}

QVector<QString> MessageDialog::_OptionCheckDialog(QWidget* parent, const QString& title, const QString& checktip, const QVector<QString>& checkboxs, const QPair<QString, QString>& buttons) {
	MessageDialog::EIcon eicon = MessageDialog::_eicon_question;
	QString info = "";
	QPair<QString, QVector<QString>> radios;
    MessageDialog* messageDialog = new MessageDialog(parent, title, eicon, info, { checktip, checkboxs }, radios, { buttons.first, buttons.second });

	QVector<QString> options;
    QObject::connect(messageDialog, &MessageDialog::_Signal_Close, [messageDialog, &options]() {
		options.clear();
        messageDialog->close();
	});
    QObject::connect(messageDialog, &MessageDialog::_Signal_Checkbox, [messageDialog, &options](const QString& checkbox, bool checked) {
		// qDebug() << checkbox << ": " << checked;
		if (checked == true) {
			bool hit = false;
			for (int i = 0; i < options.size(); i += 1) {
				if (options[i] == checkbox) {
					hit = true;
					break;
				}
			}
			if (hit == false) {
				options.push_back(checkbox);
			}
		} else {
			for (auto iter = options.begin(); iter != options.end();) {
				if (*iter == checkbox) {
					iter = options.erase(iter);
					continue;
				}
				++iter;
			}
		}
	});
    QObject::connect(messageDialog, &MessageDialog::_Signal_Button, [messageDialog, &buttons, &options](const QString& button) {
		if (buttons.second == button) {
			options.clear();
		}
        messageDialog->close();
	});
    messageDialog->exec();
    messageDialog->deleteLater();
	return options;
}

QString MessageDialog::_OptionRadioDialog(QWidget* parent, const QString& title, const QString& radiotip, const QVector<QString>& radiobuttons, const QPair<QString, QString>& buttons) {
	MessageDialog::EIcon eicon = MessageDialog::_eicon_question;
	QString info = "";
	QPair<QString, QVector<QString>> checks;
    MessageDialog* messageDialog = new MessageDialog(parent, title, eicon, info, checks, { radiotip, radiobuttons }, { buttons.first, buttons.second });

	QString option;
    QObject::connect(messageDialog, &MessageDialog::_Signal_Close, [messageDialog, &option]() {
		option = "";
        messageDialog->close();
	});
    QObject::connect(messageDialog, &MessageDialog::_Signal_Radiobutton, [messageDialog, &option](const QString& radiobutton, bool checked) {
		// qDebug() << radiobutton << ": " << checked;
		if (checked == true) {
			option = radiobutton;
		}
	});
    QObject::connect(messageDialog, &MessageDialog::_Signal_Button, [messageDialog, &buttons, &option](const QString& button) {
		if (buttons.second == button) {
			option = "";
		}
        messageDialog->close();
	});
    messageDialog->exec();
    messageDialog->deleteLater();
	return option;
}

void MessageDialog::_Test_MessageDialog(QWidget* parent) {
	QString title = "Title";
	MessageDialog::EIcon eicon = MessageDialog::_eicon_information;
	QString info = "This large piece of text may be too long, so use a 425px Size Model. \nThis large piece of text may be too long, so use a 425px Size Model.";
	QPair<QString, QVector<QString>> checks = {
		"Do you want to save project changes?",
		{ "Check1", "Check2", "Check3", "Check4", "Check5", "Check6", "Check7" }
	};
	QPair<QString, QVector<QString>> radios = {
		"Please Select: ",
		{ "Radio1", "Radio2", "Radio3", "Radio4", "Radio5", "Radio6", "Radio7" }
	};
	QVector<QString> buttons = { "Ok", "Cancel" };
    MessageDialog *messagedialog = new MessageDialog(parent, title, eicon, info, checks, radios, buttons);

    QObject::connect(messagedialog, &MessageDialog::_Signal_Close, [messagedialog]() {
		qDebug() << "Close";
        messagedialog->close();
	});
    QObject::connect(messagedialog, &MessageDialog::_Signal_Checkbox, [messagedialog](const QString& checkbox, bool checked) {
		qDebug() << checkbox << ": " << checked;
	});
    QObject::connect(messagedialog, &MessageDialog::_Signal_Radiobutton, [messagedialog](const QString& radiobutton, bool checked) {
		qDebug() << radiobutton << ": " << checked;
	});
    QObject::connect(messagedialog, &MessageDialog::_Signal_Button, [messagedialog](const QString& button) {
		qDebug() << button;
        messagedialog->close();
	});
    messagedialog->exec();
    messagedialog->deleteLater();
}

void MessageDialog::_Test_InformationDialog(QWidget* parent) {
    MessageDialog::_InformationDialog(parent, "Title", MessageDialog::_eicon_information, "This large piece of text may be too long, so use a 425px Size Model. ", { "Ok" });
}

void MessageDialog::_Test_OptionCheckDialog(QWidget* parent) {
    QVector<QString> options = MessageDialog::_OptionCheckDialog(parent, "Title", "Do you want to save project changes? ", { "Option1", "Option2", "Option3", "Option4", "Option5", "Option6", "Option7" }, { "Ok", "Cancel" });
	qDebug() << options;
}

void MessageDialog::_Test_OptionRadioDialog(QWidget* parent) {
    QString option = MessageDialog::_OptionRadioDialog(parent, "Title", "Please select: ", { "Option1", "Option2", "Option3", "Option4", "Option5", "Option6", "Option7" }, { "Ok", "Cancel" });
	qDebug() << option;
}
