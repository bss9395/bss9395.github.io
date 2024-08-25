#include "Section.h"

Section::Section(){
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

Section::~Section() {
    qDebug().noquote() << QString("[%1] ").arg(__FUNCTION__);
}

QString Section::_Member_Pofile(const QString& profile) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, profile);
    return profile;
}

QString Section::_Virtual_Profile(const QString& profile) {
    qDebug().noquote() << QString("[%1] %2").arg(__FUNCTION__, profile);
    return profile;
}
