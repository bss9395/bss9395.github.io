#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QListWidget>
#include <QWebEngineHistory>
#include "ui_mainwindow.h"
#include "webview.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	Ui::MainWindow *_ui = nullptr;
	WebView *_view = nullptr;
	QLineEdit *_urlEdit = nullptr;
	int _progress = 0;
	QNetworkAccessManager *_manager = nullptr;
	QListWidget *_history = nullptr;
	QLineEdit *_find = nullptr;


public:
	MainWindow(QWidget *parent = nullptr)
		: QMainWindow(parent), _ui(new Ui::MainWindow) {
		qDebug() << "sslLibraryBuildVersionString = " << QSslSocket::sslLibraryBuildVersionString();
		qDebug() << "supportsSsl                  = " << QSslSocket::supportsSsl();

		_ui->setupUi(this);
		_view = new WebView(this);
		_urlEdit = new QLineEdit(this);
		_manager = new QNetworkAccessManager(this);
		_history = new QListWidget();
		_find = new QLineEdit();
		this->setCentralWidget(_view);
		this->resize(1200, 600);

		_ui->toolBar->addAction(_view->pageAction(QWebEnginePage::Back));
		_ui->toolBar->addAction(_view->pageAction(QWebEnginePage::Forward));
		_ui->toolBar->addAction(_view->pageAction(QWebEnginePage::Reload));
		_ui->toolBar->addAction(_view->pageAction(QWebEnginePage::Stop));

		QObject::connect(_urlEdit, &QLineEdit::returnPressed, this, [this]() {
			_view->load(QUrl(_urlEdit->text()));
			_view->setFocus();
		});
		_urlEdit->setText("http://www.baidu.com");
		_ui->toolBar->addWidget(_urlEdit);

		QObject::connect(_view, &QWebEngineView::loadProgress, this, [this](int progress) {
			qDebug() << "progress = " << progress;
			_progress = progress;
		});

		QObject::connect(_view, &QWebEngineView::titleChanged, this, [this](const QString& title) {
			qDebug() << "QObject::connect(_view, &QWebEngineView::titleChanged, this, [this](const QString& title){";
			(void)title;
			if (_progress <= 0 || 100 <= _progress) {
				this->setWindowTitle(_view->title());
			} else {
				this->setWindowTitle(QString("%1 (%2)").arg(_view->title()).arg(_progress));
			}
		});

		QObject::connect(_view, &QWebEngineView::loadFinished, this, [this](bool finished) {
			if (finished == true) {
				_progress = 100;
				this->setWindowTitle(_view->title());
			} else {
				this->setWindowTitle("web page loading error.");
			}
		});

		QObject::connect(_view, &QWebEngineView::iconUrlChanged, this, [this](const QUrl& url) {
			QNetworkRequest request(url);
			QSslConfiguration config = QSslConfiguration::defaultConfiguration();
			config.setPeerVerifyMode(QSslSocket::AutoVerifyPeer);
			request.setSslConfiguration(config);
			QNetworkReply *reply = _manager->get(request);
			reply->setParent(this);
			QObject::connect(reply, &QNetworkReply::finished, this, [this, reply]() {
				QIcon icon;
				if (reply->error() == QNetworkReply::NoError) {
					QByteArray data = reply->readAll();
					QPixmap pixmap;
					pixmap.loadFromData(data);
					icon.addPixmap(pixmap);
					reply->deleteLater();
				} else {
					icon = QIcon(":/defaulticon.png");
				}
				this->setWindowIcon(icon);
			});
		});
		_view->load(_urlEdit->text());

		QAction *zoomIn = new QAction("放大");
		zoomIn->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Equal));
		QObject::connect(zoomIn, &QAction::triggered, this, [this]() {
			_view->setZoomFactor(_view->zoomFactor() + 0.1);
			_ui->statusbar->showMessage(QString("缩放%1%").arg(_view->zoomFactor() * 100));
		});
		_ui->toolBar->addAction(zoomIn);

		QAction *zoomOut = new QAction("缩小");
		zoomOut->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Minus));
		QObject::connect(zoomOut, &QAction::triggered, this, [this]() {
			_view->setZoomFactor(_view->zoomFactor() - 0.1);
			_ui->statusbar->showMessage(QString("缩放%1%").arg(_view->zoomFactor() * 100));
		});
		_ui->toolBar->addAction(zoomOut);

		QAction *zoomReset = new QAction("重置");
		zoomReset->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_0));
		QObject::connect(zoomReset, &QAction::triggered, this, [this]() {
			_view->setZoomFactor(1.0);
			_ui->statusbar->showMessage(QString("缩放%1%").arg(_view->zoomFactor() * 100));
		});
		_ui->toolBar->addAction(zoomReset);


		QAction *history = new QAction("历史");
		QObject::connect(history, &QAction::triggered, this, [this]() {
			_history->clear();
			QList<QWebEngineHistoryItem> list = _view->history()->items();
			for (auto beg = list.begin(); beg != list.end(); beg += 1) {
				QListWidgetItem *history = new QListWidgetItem(beg->title());
				_history->addItem(history);
			}
			_history->show();
			_history->activateWindow();
		});
		_ui->toolBar->addAction(history);

		
		QObject::connect(_history, &QListWidget::clicked, this, [this](const QModelIndex &index) {
			QWebEngineHistoryItem item = _view->history()->itemAt(index.row());
			_view->history()->goToItem(item);
		});
		_history->setWindowTitle("历史记录");
		_history->setMinimumWidth(300);
						
		QAction *find = new QAction("查找");
		QObject::connect(find, &QAction::triggered, this, [this]() {
			_view->findText(_find->text(), QWebEnginePage::FindBackward | QWebEnginePage::FindCaseSensitively);
		});
		_find->setMaximumWidth(150);
		_ui->toolBar->addWidget(_find);
		_ui->toolBar->addAction(find);
	}

	~MainWindow() {
		delete _ui;
	}
};
#endif // MAINWINDOW_H
