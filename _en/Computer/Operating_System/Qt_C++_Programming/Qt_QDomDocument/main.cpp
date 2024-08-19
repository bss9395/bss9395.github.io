/* main.cpp
Author: bss9395
Update: 2024-08-19T11:08:12+08@China-Beijing+08
*/

#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QDebug>

/* DOM类最常用的是QDomNode、QDomDocument、QDomElement、QDomText。
*/
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QDomDocument domDocument("config_xml");
    QFile file("../Qt_QDomDocument/config.xml");
    if(file.open(QIODevice::ReadOnly) == false) {
        qDebug().noquote() << "if(file.open(QIODevice::ReadOnly) == false) {";
        exit(EXIT_FAILURE);
    }
    if(domDocument.setContent(&file) == false) {
        file.close();
        exit(EXIT_FAILURE);
    }
    file.close();

    QDomProcessingInstruction domProcessingInstruction = domDocument.firstChild().toProcessingInstruction();
    qDebug().noquote() << domProcessingInstruction.nodeName() << domProcessingInstruction.nodeValue();

    QDomElement domElement = domDocument.documentElement();
    qDebug().noquote() << domElement.nodeName() << domElement.attribute("desc");

    domElement = domElement.firstChildElement();
    while(domElement.isNull() == false) {
        qDebug().noquote() << "    " << domElement.tagName() << domElement.text();

        QDomElement element = domElement.firstChildElement();
        while(element.isNull() == false) {
            qDebug().noquote() << "        " << element.tagName() << element.text();
            element = element.nextSiblingElement();
        }
        domElement = domElement.nextSiblingElement();
    }

    return a.exec();
}
