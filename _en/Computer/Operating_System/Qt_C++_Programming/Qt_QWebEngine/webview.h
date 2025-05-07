#pragma once

#include <QWebEngineView>
class MainWindow;

class WebView : public QWebEngineView {
	Q_OBJECT

public:
	MainWindow *_mainWindow;

public:
	WebView(QWidget *parent = nullptr);

	QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;
};
