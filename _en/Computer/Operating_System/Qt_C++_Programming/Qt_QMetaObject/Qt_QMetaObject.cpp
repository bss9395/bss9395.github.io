/* Qt_QMetaObject.cpp
Author: BSS9395
Update: 2023-08-13T15:55:00+08@China-Guangdong-Zhanjiang+08
*/

#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QCheckBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton *pb_Button = new QPushButton();
    const QMetaObject *meta = pb_Button->metaObject();
    qDebug() << QString(meta->className());          // note: QPushButton

    ////////////////////////////////////

    qDebug() << pb_Button->inherits("QPushButton");  // note: true
    qDebug() << pb_Button->inherits("QObject");      // note: true
    qDebug() << pb_Button->inherits("QWidget");      // note: true
    qDebug() << pb_Button->inherits("QCheckBox");    // note: false

    ////////////////////////////////////


    const QMetaObject *metaSuper = pb_Button->metaObject()->superClass();
    qDebug() << QString(metaSuper->className());     // note: QAbstractButton

    ////////////////////////////////////

    QAbstractButton *pb_Push = qobject_cast<QAbstractButton *>(pb_Button);
    const QMetaObject *meta2 = pb_Push->metaObject();
    qDebug() << QString(meta2->className());         // note: QPushButton

    QCheckBox *cb_Checkbox = qobject_cast<QCheckBox *>(pb_Button);
    qDebug() << (cb_Checkbox == nullptr);            // note: nullptr

    return a.exec();
}
