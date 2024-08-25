#include "Common.h"

Common::Common() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

Common::~Common() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

QString Common::_Member_Operate(const QString& operate) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, operate);
    return operate;
}

QString Common::_Virtual_Operate(const QString& operate) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, operate);
    return operate;
}
