#include "Plugin.h"

Plugin::Plugin() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
    Common::_name = "Plugin";
}

Plugin::~Plugin() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

QString Plugin::_Member_Greeting(const QString& greeting) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, greeting);
    return greeting;
}

QString Plugin::_Virtual_Greeting(const QString& greeting) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, greeting);
    return greeting;
}

Common *_Instance() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
    return (Common *)(new Plugin());
}

