#pragma once
#include <QDebug>
#include <QString>
#include <QtCore/qglobal.h>

#ifdef QLIBRARY_EXPORT
#  define QLIBRARY_EXTERN Q_DECL_EXPORT
#else
#  define QLIBRARY_EXTERN Q_DECL_IMPORT
#endif


class QLIBRARY_EXTERN Common {
public:
    QString _name = "";

public:
    explicit Common();
    virtual ~Common();

public:
    QString _Member_Operate(const QString& operate);
    virtual QString _Virtual_Operate(const QString& operate);
};
