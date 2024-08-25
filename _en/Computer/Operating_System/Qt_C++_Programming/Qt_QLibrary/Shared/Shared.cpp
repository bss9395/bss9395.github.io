#include "Shared.h"

Shared::Shared() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
    Common::_name = "Shared";
}

Shared::~Shared() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

QString Shared::_Member_Greeting(const QString& greeting) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, greeting);
    return greeting;
}

QString Shared::_Virtual_Greeting(const QString& greeting) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, greeting);
    return greeting;
}

void Shared::_Virtual_Dependence() {
    Depend depend;
    depend._Member_Routine("Routine");
    depend._Virtual_Routine("Routine");
}

Common *_Instance() {
    qDebug().noquote() << QString("[%1] ").arg("Common *_Instance() {");
    return (Common *)(new Shared());
}
