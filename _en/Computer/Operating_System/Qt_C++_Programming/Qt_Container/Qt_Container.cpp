/* Qt_Container.cpp
Author: BSS9395
Update: 2023-08-11T10:28:00+08@China-Guangdong-Zhanjiang+08
Design: Qt Container
*/

#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QList>
#include <QMap>
#include <QVariant>
#include <QColor>
#include <QStringList>

class Qt_Container {
public:
    static void _QMutableListIterator_QListIterator() {
        QList<QString> list;
        list.append("C");
        list.append("C++");
        list.append("C#");
        list.append("Java");
        list.append("Python");

        QMutableListIterator<QString> iter(list);
        iter.toBack();
        while(iter.hasPrevious()) {
            QString value = iter.previous();
            if(value.compare("C#") == 0) {
                iter.remove();
            }
            else if(value.startsWith("C")) {
                iter.setValue("C" + iter.peekNext());
            }
        }

        for(QListIterator<QString> iter(list); iter.hasNext(); ) {
            fwprintf(stdout, L"%ls\n", iter.next().toStdWString().c_str());
        }
    }

    static void _QList_iterator_const_iterator() {
        QList<QString> list;
        list.insert(list.end(), "C");
        list.insert(list.end(), "C++");
        list.insert(list.end(), "C#");
        list.insert(list.end(), "Java");
        list.insert(list.end(), "Python");

        for(QList<QString>::iterator iter = list.begin(); iter != list.end(); ++iter) {
            if((*iter).compare("C#") == 0) {
                (*iter) = "C" + (*iter);
            }
        }

        for(QList<QString>::const_iterator iter = list.constBegin(); iter != list.constEnd(); ++iter) {
            qDebug() << (*iter);
        }
    }

    static void _QMutableMapIterator_QMapIterator() {
        QMap<QString, QString> map;
        map.insert("C", "C");
        map.insert("C++", "C++");
        map.insert("C#", "C#");
        map.insert("Java", "Java");
        map.insert("Python", "Python");

        QMutableMapIterator<QString, QString> iter(map);
        if(iter.findNext("C#")) {
            iter.setValue("CC#");
        }

        for(QMapIterator<QString, QString> iter(map); iter.hasNext(); ) {
            QMapIterator<QString, QString>::Item item = iter.next();
            qDebug().nospace() << item.key() << ", " << item.value();
        }
    }

    static void _QMap_iterator_const_iterator() {
        QMap<QString, QString> map;
        map.insert("C", "C");
        map.insert("C++", "C++");
        map.insert("C#", "C#");
        map.insert("Java", "Java");
        map.insert("Python", "Python");

        QMap<QString, QString>::iterator iter = map.find("C#");
        if(iter != map.end()) {
            iter.value() = "C" + iter.value();
        }

        for(QMap<QString, QString>::const_iterator iter = map.constBegin(); iter != map.constEnd(); ++iter) {
            qDebug().nospace() << iter.key() << ", " << iter.value();
        }
    }

public:
    static void _QVariant() {
        QStringList list;
        list << "A" << "B" << "C" << "D" << "E";

        QMap<QString, QVariant> map;
        map["C"] = 123456;
        map["C++"] = 123.456;
        map["C#"] = "C#";
        map["Java"] = QColor(255, 0, 0);
        map["Python"] = list;

        qDebug().nospace() << map["C"] << ", " <<map["C"].toInt();
        qDebug().nospace() << map["C++"] << ", " << map["C++"].toDouble();
        qDebug().nospace() << map["C#"] << ", " << map["C#"].toString();
        qDebug().nospace() << map["Java"] << ", " << map["Java"].value<QColor>();
        qDebug().nospace() << map["Python"] << ", " << map["Python"].toStringList();

        if(map["Python"].type() == QVariant::StringList) {
            QStringList list = map["Python"].toStringList();
            for(int i = 0; i < list.size(); i += 1) {
                qDebug() << list[i];
            }
        }
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);

    // Qt_Container::_QMutableListIterator_QListIterator();
    // Qt_Container::_QList_iterator_const_iterator();
    // Qt_Container::_QMutableMapIterator_QMapIterator();
    // Qt_Container::_QMap_iterator_const_iterator();

    Qt_Container::_QVariant();

    return application.exec();
}
