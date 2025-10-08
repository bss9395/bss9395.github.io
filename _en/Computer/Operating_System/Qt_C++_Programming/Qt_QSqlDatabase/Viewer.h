/* Viewer.h
Author: bss9395
Update: 2025/10/08T18:35:00+08@China-GuangDong-ZhanJiang+08
Keepin: bss9395@yeah.net
*/

#pragma once

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFontMetrics>
#include <QDateTime>
#include <QFile>
#include <QWidget>
#include <QLabel>

struct Viewer : public QWidget {
	Q_OBJECT

public:
	QLabel *_image = nullptr;
	bool _resize = false;

	Viewer(long width, long height)
		: QWidget(nullptr) {
		this->setObjectName("this");
		this->resize(width, height);

		_image = new QLabel(this);
		_image->setObjectName("_image");
		_image->resize(this->width(), this->height());
	}
	virtual ~Viewer() {
		qDebug().nospace() << __FUNCTION__;
	}

	void resizeEvent(QResizeEvent *event) override {
		// qDebug().nospace() << "[" << __FUNCTION__ << "] " << event;
		if (_resize == true) {
			_image->resize(this->width(), this->height());
		}
	}

	void _Display_Image(const QString &title, const QByteArray &image, bool resize = false) {
		this->setWindowTitle(title);
		QPixmap pixmap;
		pixmap.loadFromData(image);
		_image->setScaledContents(true);
		_image->setPixmap(pixmap);
		_image->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		_image->resize(pixmap.width(), pixmap.height());
		this->resize(_image->width(), _image->height());
		_resize = resize;
	}
};
