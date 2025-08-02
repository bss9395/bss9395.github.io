
#include <QDebug>
#include <QString>
#include <QThread>
#include <iostream>
#include <string>


class StdinReader : public QThread {
	Q_OBJECT 

signals:
    void _Signal_ReadLine(const QString& buffer);

public:
    explicit StdinReader() {
		qDebug().nospace() << __FUNCTION__;
        this->start();
	}

public:
	void run() override {
		qDebug().nospace() << __FUNCTION__;
        std::string buffer = "";
        while(std::cin.eof() == false) {
            char ch = '\0';
            std::cin.read(&ch, 1);
            if(ch == '\n') {
                // std::cout << buffer << std::endl;
                emit this->_Signal_ReadLine(QString(buffer.c_str()));
                buffer.resize(0);
                continue;
            }
            buffer += ch;
        }
	}
};
