#include "Depend.h"

Depend::Depend() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

Depend::~Depend() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

QString Depend::_Member_Routine(const QString& routine) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, routine);
    return routine;
}

QString Depend::_Virtual_Routine(const QString& routine) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, routine);
    return routine;
}
