/* Qt_QCryptographicHash
Author: bss9395
Update: 2024-08-19T11:18:30+08@China-Beijing+08
*/

#include <QByteArray>
#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDebug>
#include <QFile>

void _Hash() {
    QFile file(QCoreApplication::applicationFilePath());
    file.open(QFile::ReadOnly);
    QCryptographicHash crypto(QCryptographicHash::Sha1);
    crypto.addData(&file);
    QByteArray sha1 = crypto.result();
    QByteArray sha1_hex = sha1.toHex();
    QByteArray sha1_base64 = sha1.toBase64();
    qDebug().noquote() << "sha1       : " << sha1;
    qDebug().noquote() << "sha1_hex   : " << sha1_hex;
    qDebug().noquote() << "sha1_base64: " << sha1_base64;
}

void _Hash_None_File() {
    QFile file("none");
    file.open(QFile::ReadOnly);
    QCryptographicHash crypto(QCryptographicHash::Sha1);
    crypto.addData(&file);
    QByteArray sha1 = crypto.result();
    QByteArray sha1_hex = sha1.toHex();
    QByteArray sha1_base64 = sha1.toBase64();
    qDebug().noquote() << "sha1       : " << sha1;
    qDebug().noquote() << "sha1_hex   : " << sha1_hex;
    qDebug().noquote() << "sha1_base64: " << sha1_base64;
}

void _Hash_None_QByteArray() {
    QByteArray buffer = "";
    QCryptographicHash crypto(QCryptographicHash::Sha1);
    crypto.addData(buffer);
    QByteArray sha1 = crypto.result();
    QByteArray sha1_hex = sha1.toHex();
    QByteArray sha1_base64 = sha1.toBase64();
    qDebug().noquote() << "sha1       : " << sha1;
    qDebug().noquote() << "sha1_hex   : " << sha1_hex;
    qDebug().noquote() << "sha1_base64: " << sha1_base64;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    _Hash();
    _Hash_None_File();
    _Hash_None_QByteArray();

    return a.exec();
}
