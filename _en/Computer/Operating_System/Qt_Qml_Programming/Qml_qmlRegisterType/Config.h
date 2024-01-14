#ifndef Config_h
#define Config_h

#include <QDebug>
#include <QObject>
#include <QVariant>

class Config: public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void _Func(const int &value) {
        qDebug().noquote() << __FUNCTION__;
        qDebug().noquote() << "value = " << value;
    }
};

#endif // Config_h
