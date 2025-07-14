#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>
#include <QObject>
#include <QQmlEngine>

class Grouped: public QObject {
    Q_OBJECT
    Q_PROPERTY(int     attached0 READ getAttached0 WRITE setAttached0 NOTIFY attached0Changed)
    Q_PROPERTY(QString attached1 READ getAttached1 WRITE setAttached1 NOTIFY attached1Changed)

public:
    int     _attached0 = 0;
    QString _attached1 = "";

public:
    explicit Grouped(QObject *parent = nullptr)
        : QObject(parent) {
        qDebug().noquote() << __FUNCTION__;
    }

    Grouped(const Grouped &grouped)
        : QObject(grouped.parent()) {
        _attached0 = grouped._attached0;
        _attached1 = grouped._attached1;
    }

    Grouped &operator=(const Grouped &grouped) {
        if(this != &grouped) {
            _attached0 = grouped._attached0;
            _attached1 = grouped._attached1;
        }
        return (*this);
    }

public:
    int  getAttached0() {
        qDebug().noquote() << __FUNCTION__;
        return _attached0;
    }

    void setAttached0(int attached0) {
        qDebug().noquote() << __FUNCTION__;
        if(_attached0 != attached0) {
            _attached0 = attached0;
            emit attached0Changed();
        }
    }

    QString getAttached1() {
        qDebug().noquote() << __FUNCTION__;
        return _attached1;
    }

    void setAttached1(const QString &attached1) {
        qDebug().noquote() << __FUNCTION__;
        if(_attached1 != attached1) {
            _attached1 = attached1;
            emit attached1Changed();
        }
    }

signals:
    void attached0Changed();
    void attached1Changed();
};


class Config : public QObject {
    Q_OBJECT
    Q_PROPERTY(int      attached READ getAttached WRITE setAttached NOTIFY attachedChanged)
    Q_PROPERTY(Grouped *grouped  READ getGrouped  WRITE setGrouped  NOTIFY groupedChanged)

public:
    int      _attached = 0;
    Grouped *_grouped  = new Grouped(this);

public:
    explicit Config(QObject *parent = nullptr)
        : QObject(parent) {
        qDebug().noquote() << __FUNCTION__;
    }

public:
    int  getAttached() {
        qDebug().noquote() << __FUNCTION__;
        return _attached;
    }

    void setAttached(int attached) {
        qDebug().noquote() << __FUNCTION__;
        if(_attached != attached) {
            _attached = attached;
            emit attachedChanged();
        }
    }

    Grouped *getGrouped() {
        qDebug().noquote() << __FUNCTION__;
        return _grouped;
    }

    void     setGrouped(Grouped *grouped) {
        qDebug().noquote() << __FUNCTION__;
        if(_grouped != grouped) {
            _grouped = grouped;
            emit groupedChanged();
        }
    }

signals:
    void attachedChanged();
    void groupedChanged();
};


class Attached : public QObject {
    Q_OBJECT

public:
    static Config *qmlAttachedProperties(QObject *object) {
        return new Config(object);
    }
};
QML_DECLARE_TYPEINFO(Attached, QML_HAS_ATTACHED_PROPERTIES)

#endif // CONFIG_H
