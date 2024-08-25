#pragma once
#include <QDebug>
#include <QString>
#include <QtCore/qglobal.h>

#ifdef QLIBRARY_EXPORT
#  define QLIBRARY_EXTERN Q_DECL_EXPORT
#else
#  define QLIBRARY_EXTERN Q_DECL_IMPORT
#endif

class QLIBRARY_EXTERN Section {
public:
    explicit Section();
    virtual ~Section();

public:
    QString _Member_Pofile(const QString& profile);
    virtual QString _Virtual_Profile(const QString& profile);
};
