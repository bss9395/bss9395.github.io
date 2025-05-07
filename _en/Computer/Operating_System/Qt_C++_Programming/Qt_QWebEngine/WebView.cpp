#include "WebView.h"
#include <mainwindow.h>

WebView::WebView(QWidget *parent)
	: QWebEngineView(parent) {

}

QWebEngineView *WebView::createWindow(QWebEnginePage::WebWindowType type) {
	qDebug() << "QWebEnginePage::WebWindowType = " << type;
	_mainWindow = new MainWindow(this);
	_mainWindow->show();
	return _mainWindow->_view;
}
