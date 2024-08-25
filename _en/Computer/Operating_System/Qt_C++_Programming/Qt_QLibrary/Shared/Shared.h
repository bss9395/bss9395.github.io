#pragma once
#include <QDebug>
#include <QString>
#include <QtCore/qglobal.h>
#include "Depend.h"
#include "Common.h"

#ifdef QLIBRARY_EXPORT
#  define QLIBRARY_EXTERN Q_DECL_EXPORT
#else
#  define QLIBRARY_EXTERN Q_DECL_IMPORT
#endif


class QLIBRARY_EXTERN Shared : public Common {            // 采用隐式链接可以直接创建类对象并调用类的函数
public:
    explicit Shared();
    virtual ~Shared();

public:
    QString _Member_Greeting(const QString& greeting);
    virtual QString _Virtual_Greeting(const QString& greeting);  // 采用显式链接只能动态调用类的虚函数

public:
    virtual void _Virtual_Dependence();
};


extern "C" {
QLIBRARY_EXTERN Common *_Instance();
}
