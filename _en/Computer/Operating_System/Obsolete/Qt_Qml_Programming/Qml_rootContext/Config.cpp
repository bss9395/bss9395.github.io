#include "Config.h"

Config &Config::instance() {
    qDebug().noquote() << __FUNCTION__;
    static Config config = Config();  // C++17
    return config;
}

Config::Config(QObject *parent)
    : QObject(parent) {
    qDebug().noquote() << __FUNCTION__;
}

Config::~Config() {
    qDebug().noquote() << __FUNCTION__;

}

Q_INVOKABLE void Config::greeting() {
    qDebug().noquote() << __FUNCTION__;
    qDebug().noquote() << "hello, world!";
}
