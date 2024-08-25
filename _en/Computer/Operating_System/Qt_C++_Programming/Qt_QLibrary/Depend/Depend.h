#pragma once
#include <QDebug>
#include <QString>
#include <QtCore/qglobal.h>

#ifdef QLIBRARY_EXPORT
#  define QLIBRARY_EXTERN Q_DECL_EXPORT
#else
#  define QLIBRARY_EXTERN Q_DECL_IMPORT
#endif


class QLIBRARY_EXTERN Depend {
public:
    explicit Depend();
    virtual ~Depend();

public:
    QString _Member_Routine(const QString& routine);
    virtual QString _Virtual_Routine(const QString& routine);
};
