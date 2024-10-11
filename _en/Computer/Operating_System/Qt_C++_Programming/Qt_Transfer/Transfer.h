#pragma once

#include <QByteArray>
#include <QCryptographicHash>
#include <QDataStream>
#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QElapsedTimer>
#include <QException>
#include <QFile>
#include <QFileInfo>
#include <QHostAddress>
#include <QMap>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QVector>

class Thread : public QThread {
    Q_OBJECT
public:
    qint64 _refer = 0;

public:
    void _Increase() {
        _refer += 1;
        qDebug().noquote() << QString("%1:%2").arg(__FUNCTION__).arg(_refer);
    }
    void _Decrease() {
        _refer -= 1;
        qDebug().noquote() << QString("%1:%2").arg(__FUNCTION__).arg(_refer);
        if (_refer <= 0) {
            emit _Signal_Thread_Idle();
        }
    }

signals:
    void _Signal_Thread_Idle();
};

class Transfer : public QObject {
    Q_OBJECT

public:
    inline static const QCryptographicHash::Algorithm _hash_algorithm = QCryptographicHash::Sha1;
    inline static const QDataStream::ByteOrder _datastream_byteorder = QDataStream::LittleEndian;
    inline static const QDataStream::Version _datastream_version = QDataStream::Qt_5_12;
    inline static const char* _filebuffer_extension = ".buffer";
    inline static const char* _foldermeta_filename = "foldermeta.cache";
    inline static const qint32 _nega = -1;
    inline static const qint32 _none = 0;
    inline static const qint32 _posi = +1;
    inline static const quint16 _server_port = 9395;
    inline static const quint32 _code_client_error = 0x0302;
    inline static const quint32 _code_client_none = 0x0300;
    inline static const quint32 _code_client_right = 0x0301;
    inline static const quint32 _code_native_error = 0x0102;
    inline static const quint32 _code_native_none = 0x0100;
    inline static const quint32 _code_native_right = 0x0101;
    inline static const quint32 _code_none = 0x0000;
    inline static const quint32 _code_server_error = 0x0202;
    inline static const quint32 _code_server_none = 0x0200;
    inline static const quint32 _code_server_right = 0x0201;
    inline static const quint32 _magic_c2s = 0x5939;
    inline static const quint32 _magic_none = 0x0000;
    inline static const quint32 _magic_s2c = 0x9395;
    inline static const quint32 _oper_c2s_push = 0x0002;
    inline static const quint32 _oper_c2s_sync = 0x0003;
    inline static const quint32 _oper_none = 0x0000;
    inline static const quint32 _oper_p2p_echo = 0x0001;
    inline static const quint32 _oper_s2c_sync = 0x0004;
    inline static const quint64 _dataslice_length = 4096;

public:
    struct Exception : public QException {
        mutable QString _message = "";
        mutable std::string _what = "";

        explicit Exception(const QString& message) {
            _message = message;
        }

        virtual QString _What() const noexcept {
            return _message;
        }

        virtual const char* what() const noexcept override {
            _what = _message.toStdString();
            return _what.data();
        }
    };

    struct DataStream : public QDataStream {
        explicit DataStream(QByteArray* buffer)
            : QDataStream(buffer, QIODevice::ReadWrite) {
            this->setByteOrder(Transfer::_datastream_byteorder);
            this->setVersion(Transfer::_datastream_version);
        }

        explicit DataStream(QIODevice* device)
            : QDataStream(device) {
            this->setByteOrder(Transfer::_datastream_byteorder);
            this->setVersion(Transfer::_datastream_version);
        }
    };

    struct Filemeta {
        QString _filename = "";
        quint64 _filesize = 0;
        QByteArray _hash_sha1 = "";
        qint64 _modified_local = 0;

        friend QDataStream& operator<<(QDataStream& os, const Filemeta& data) {
            os << data._filename;
            os << data._filesize;
            os << data._hash_sha1;
            os << data._modified_local;
            return os;
        }

        friend QDataStream& operator>>(QDataStream& is, Filemeta& data) {
            is >> data._filename;
            is >> data._filesize;
            is >> data._hash_sha1;
            is >> data._modified_local;
            return is;
        }
    };

    struct Meta_Header {
        virtual ~Meta_Header() {

        }

        friend QDataStream& operator<<(QDataStream& os, const Meta_Header& data) {
            (void)data;
            return os;
        }

        friend QDataStream& operator>>(QDataStream& is, Meta_Header& data) {
            (void)data;
            return is;
        }
    };

    struct Meta_P2P_Echo : public Meta_Header {
        inline static const quint32 _opertype = Transfer::_oper_p2p_echo;
        QVector<QPair<quint32, QString>> _codes;
        QString _timestamp_utc = "";

        friend QDataStream& operator<<(QDataStream& os, const Meta_P2P_Echo& data) {
            os << (Meta_Header&)data;
            os << data._codes;
            os << data._timestamp_utc;
            return os;
        }

        friend QDataStream& operator>>(QDataStream& is, Meta_P2P_Echo& data) {
            is >> (Meta_Header&)data;
            is >> data._codes;
            is >> data._timestamp_utc;
            return is;
        }
    };

    struct Meta_C2S_Push : public Meta_Header {
        inline static const quint32 _opertype = Transfer::_oper_c2s_push;
        Filemeta _filemeta;

        friend QDataStream& operator<<(QDataStream& os, const Meta_C2S_Push& data) {
            os << (Meta_Header&)data;
            os << data._filemeta;
            return os;
        }

        friend QDataStream& operator>>(QDataStream& is, Meta_C2S_Push& data) {
            is >> (Meta_Header&)data;
            is >> data._filemeta;
            return is;
        }
    };

    struct Meta_C2S_Sync : public Meta_Header {
        inline static const quint32 _opertype = Transfer::_oper_c2s_sync;
        QMap<QString, Filemeta> _foldermeta;

        friend QDataStream& operator<<(QDataStream& os, const Meta_C2S_Sync& data) {
            os << (Meta_Header&)data;
            os << data._foldermeta;
            return os;
        }

        friend QDataStream& operator>>(QDataStream& is, Meta_C2S_Sync& data) {
            is >> (Meta_Header&)data;
            is >> data._foldermeta;
            return is;
        }
    };

    struct Meta_S2C_Sync : public Meta_Header {
        inline static const quint32 _opertype = Transfer::_oper_s2c_sync;
        QVector<Filemeta> _foldermeta;

        friend QDataStream& operator<<(QDataStream& os, const Meta_S2C_Sync& data) {
            os << (Meta_Header&)data;
            os << data._foldermeta;
            return os;
        }

        friend QDataStream& operator>>(QDataStream& is, Meta_S2C_Sync& data) {
            is >> (Meta_Header&)data;
            is >> data._foldermeta;
            return is;
        }
    };

    struct Handle : public QObject {
        Meta_P2P_Echo _echo_host;
        QTcpSocket* _tcp_client = nullptr;
        QByteArray _buffer = "";
        QFile* _file = nullptr;
        quint64 _bytes_total = 0;
        quint64 _bytes_ready = 0;
        QElapsedTimer _elapsed;

        quint32 _magic = Transfer::_magic_none;
        quint32 _opertype = Transfer::_oper_none;
        quint32 _metasize = 0;
        Meta_Header* _meta = nullptr;

        virtual ~Handle() {
            if (_tcp_client != nullptr) {
                _tcp_client->deleteLater(), _tcp_client = nullptr;
            }
            if (_file != nullptr) {
                _file->deleteLater(), _file = nullptr;
            }
            if (_meta != nullptr) {
                delete _meta, _meta = nullptr;
            }
        }

        void _Reset() {
            _echo_host = Meta_P2P_Echo();
            if (_file != nullptr) {
                _file->deleteLater(), _file = nullptr;
            }
            _bytes_total = 0;
            _bytes_ready = 0;
            _elapsed = QElapsedTimer();

            _magic = Transfer::_magic_none;
            _opertype = Transfer::_oper_none;
            _metasize = 0;
            if (_meta != nullptr) {
                delete _meta, _meta = nullptr;
            }
        }
    };

public:
    static QString _Reduce_Filesize(double filesize) {
        static QVector<QString> suffixes = {
            "B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"
        };
        int i = 0;
        for (; i < suffixes.size() && 1024 <= filesize; i += 1) {
            filesize /= 1024;
        }
        return (i == 0) ? QString("%1 %2").arg((quint64)filesize).arg(suffixes[i]) : QString("%1 %2").arg((double)filesize, 0, 'f', 2, ' ').arg(suffixes[i]);
    }

    static QByteArray _Hash_Data(const QString& filepath) {
        QFile file(filepath);
        if (file.open(QFile::ReadOnly) == false) {
            throw Exception(QString("[文件读取失败] %1").arg(file.fileName()));
        }
        QCryptographicHash crypto(Transfer::_hash_algorithm);
        crypto.addData(&file);
        file.close();
        return crypto.result();
    }

public:
    template<typename Meta>
    static QByteArray _Dump_Head_Meta(const quint32 magic, const Meta& meta) {
        QByteArray buffer_meta;
        DataStream stream_meta(&buffer_meta);
        stream_meta << meta;

        QByteArray buffer_head;
        DataStream stream_head(&buffer_head);
        stream_head << (quint32)magic;
        stream_head << (quint32)Meta::_opertype;
        stream_head << (quint32)buffer_meta.size();

        return (buffer_head + buffer_meta);
    }

    static qint32 _Load_Head_Meta(Handle* handle, const quint32 magic) {
        static const quint64 head_size = sizeof(handle->_magic) + sizeof(handle->_opertype) + sizeof(handle->_metasize);
        if (handle->_magic == Transfer::_magic_none) {
            if ((quint64)handle->_tcp_client->bytesAvailable() < head_size) {
                return Transfer::_nega;
            }
            handle->_buffer.resize(head_size);
            quint64 length = handle->_tcp_client->read(handle->_buffer.data(), head_size);
            (void)length;
            DataStream stream(&handle->_buffer);
            stream >> handle->_magic;
            stream >> handle->_opertype;
            stream >> handle->_metasize;
            if (handle->_magic != magic) {
                qDebug().noquote() << QString("[不明数据头] %1:%2").arg(handle->_magic).arg(magic);
                handle->_tcp_client->close();
                return Transfer::_nega;
            }
        }

        if (handle->_meta == nullptr) {
            if ((quint64)handle->_tcp_client->bytesAvailable() < handle->_metasize) {
                return Transfer::_nega;
            }
            handle->_buffer.resize(handle->_metasize);
            quint64 length = handle->_tcp_client->read(handle->_buffer.data(), handle->_metasize);
            (void)length;
            DataStream stream(&handle->_buffer);
            if (handle->_opertype == Transfer::_oper_p2p_echo) {
                handle->_meta = new Meta_P2P_Echo();
                stream >> *(Meta_P2P_Echo*)(handle->_meta);
            } else if (handle->_opertype == Transfer::_oper_c2s_push) {
                handle->_meta = new Meta_C2S_Push();
                stream >> *(Meta_C2S_Push*)(handle->_meta);
            } else if (handle->_opertype == Transfer::_oper_c2s_sync) {
                handle->_meta = new Meta_C2S_Sync();
                stream >> *(Meta_C2S_Sync*)(handle->_meta);
            } else if (handle->_opertype == Transfer::_oper_s2c_sync) {
                handle->_meta = new Meta_S2C_Sync();
                stream >> *(Meta_S2C_Sync*)(handle->_meta);
            } else {
                qDebug().noquote() << QString("[不明数据体] %1").arg(handle->_opertype);
                handle->_tcp_client->close();
                return Transfer::_nega;
            }
            return Transfer::_none;  // 首次解析数据体
        }
        return Transfer::_posi;
    }

    static void _Foldermeta_Update(QMap<QString, Filemeta>& foldermeta_update, const QString& folderpath, const QStringList& include) {
        foldermeta_update.clear();

        // 创建目录
        if (QDir().mkpath(folderpath) == false) {  // 目录若不存在则创建
            throw Exception(QString("[目录创建失败] %1").arg(folderpath));
        }

        // 读取缓存文件
        QString filepath = folderpath + QString("/") + Transfer::_foldermeta_filename;
        QFile file_read(filepath);
        if (file_read.open(QFile::ReadWrite) == false) {  // 文件若存在则读取，若不存在则创建
            throw Exception(QString("[文件读写失败] %1").arg(file_read.fileName()));
        }
        QMap<QString, Filemeta> foldermeta_cache;
        DataStream stream_read(&file_read);
        stream_read >> foldermeta_cache;
        file_read.close();

        // 筛选文件
        static QStringList exclude = {
            Transfer::_foldermeta_filename
        };
        QFileInfoList folderinfo = QDir(folderpath).entryInfoList(include, QDir::Files, QDir::Name);
        for (auto iter_exclude = exclude.begin(); iter_exclude != exclude.end(); iter_exclude += 1) {
            for (auto iter = folderinfo.begin(); iter != folderinfo.end(); ) {
                if ((*iter_exclude) == iter->fileName()) {
                    iter = folderinfo.erase(iter);
                    continue;
                }
                iter += 1;
            }
        }

        // 更新缓存
        for (auto iter = folderinfo.begin(); iter != folderinfo.end(); iter += 1) {
            QFileInfo& fileinfo = (*iter);
            Filemeta filemeta = foldermeta_cache.value(fileinfo.fileName());
            if (filemeta._modified_local != fileinfo.lastModified().toMSecsSinceEpoch()) {
                filemeta._filename = "";
                filemeta._filesize = (quint64)fileinfo.size();
                filemeta._hash_sha1 = Transfer::_Hash_Data(fileinfo.filePath());
                filemeta._modified_local = fileinfo.lastModified().toMSecsSinceEpoch();
            }
            foldermeta_update[fileinfo.fileName()] = filemeta;
        }

        // 写入缓存文件
        QFile file_write(filepath);
        if (file_write.open(QFile::WriteOnly | QFile::Truncate) == false) {  // 文件若存在则截断，若不存在则创建
            throw Exception(QString("[文件写入失败] %1").arg(file_write.fileName()));
        }
        QByteArray buffer = "";
        DataStream stream_write(&buffer);
        stream_write << foldermeta_update;
        file_write.write(buffer.data(), buffer.size());
        file_write.flush();
        file_write.close();
    }

    static void _Foldermeta_Checkout(QVector<Filemeta>& foldermeta_checkout, QMap<QString, Filemeta>& foldermeta_server, const QMap<QString, Filemeta>& foldermeta_client) {
        foldermeta_checkout.clear();

        for (auto iter = foldermeta_server.begin(); iter != foldermeta_server.end(); iter += 1) {
            const QString& filename = iter.key();
            Filemeta& filemeta_server = iter.value();
            const Filemeta& filemeta_client = foldermeta_client.value(filename);
            if (filemeta_server._hash_sha1 != filemeta_client._hash_sha1) {
                filemeta_server._filename = filename;
                foldermeta_checkout.push_back(filemeta_server);
            }
        }
    }

public:
    // ToDo: 树形目录结构
    // ToDo: 服务端超时关闭连接
    static Transfer* _Server_Listening(const QString& folderpath) {
        qDebug().noquote() << QString("[enter] %1:%2").arg(__FUNCTION__).arg((quint64)QThread::currentThread(), 16, 16, QChar('0'));
        Thread* thread = new Thread();
        Transfer* transfer = new Transfer();
        QObject::connect(thread, &Thread::_Signal_Thread_Idle, thread, [thread]() mutable -> void {
            qDebug().noquote() << "QObject::connect(thread, &Thread::_Signal_Thread_Idle, thread, [thread]() mutable -> void {";
            thread->terminate();
            thread->deleteLater(), thread = nullptr;
        });

        thread->start();
        transfer->moveToThread(thread);
        QMetaObject::invokeMethod(transfer, [thread, transfer, folderpath]() -> void {
            qDebug().noquote() << QString("[enter] %1:%2").arg("QMetaObject::invokeMethod(transfer, [thread, transfer, folderpath]() -> void {").arg((quint64)QThread::currentThread, 16, 16, QChar('0'));
            QTcpServer* tcp_server = nullptr;
            try {
                tcp_server = new QTcpServer();
                thread->_Increase();

                QObject::connect(transfer, &QObject::destroyed, tcp_server, [thread, tcp_server]() mutable -> void {
                    qDebug().noquote() << "QObject::connect(transfer, &QObject::destroyed, tcp_server, [thread, tcp_server]() mutable -> void {";
                    tcp_server->close();
                    tcp_server->deleteLater(), tcp_server = nullptr;
                    thread->_Decrease();
                });

                if (tcp_server->listen(QHostAddress::Any, (quint16)Transfer::_server_port) == false) {
                    throw Exception(QString("[服务端监听失败] %1").arg(tcp_server->errorString()));
                }

                QObject::connect(tcp_server, &QTcpServer::newConnection, tcp_server, [thread, transfer, tcp_server, folderpath]() -> void {
                    qDebug().noquote() << "QObject::connect(tcp_server, &QTcpServer::newConnection, tcp_server, [thread, transfer, tcp_server, folderpath]() -> void {";
                    Handle* handle = new Handle();
                    thread->_Increase();

                    handle->_tcp_client = tcp_server->nextPendingConnection();
                    QObject::connect(tcp_server, &QObject::destroyed, handle, [handle]() -> void {
                        qDebug().noquote() << "QObject::connect(tcp_server, &QObject::destroyed, handle, [handle]() -> void {";
                        handle->_tcp_client->close();
                    });

                    QObject::connect(handle->_tcp_client, &QTcpSocket::connected, handle, [handle]() -> void {
                        qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::connected, handle, [handle]() -> void {";
                        // NoOp
                    });

                    QObject::connect(handle->_tcp_client, &QTcpSocket::readyRead, handle, [transfer, handle, folderpath]() -> void {
                        qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::readyRead, handle, [transfer, handle, folderpath]() -> void {";
                        try {
                            // 注意清空缓冲区
                            for (handle->_buffer.reserve((quint64)handle->_tcp_client->bytesAvailable()); 0 < (quint64)handle->_tcp_client->bytesAvailable(); ) {
                                // 加载数据头体
                                if (_Load_Head_Meta(handle, Transfer::_magic_c2s) == Transfer::_nega) {
                                    return;
                                }

                                if (handle->_opertype == Transfer::_oper_p2p_echo) {
                                    // 解析数据体，此操作无附加数据块
                                    // NoOp
                                    handle->_Reset();  // 解析完毕，重置把柄
                                } else if (handle->_opertype == Transfer::_oper_c2s_push) {
                                    // 解析数据体，此操作有附加数据块
                                    qDebug().noquote() << QString("[%1] bytesAvailable() = %2").arg("else if (handle->_opertype == Transfer::_oper_c2s_push) {").arg(Transfer::_Reduce_Filesize(handle->_tcp_client->bytesAvailable()));
                                    Meta_C2S_Push* meta_c2s_push = (Meta_C2S_Push*)handle->_meta;

                                    if (handle->_file == nullptr) {
                                        if (QDir().mkpath(folderpath) == false) {
                                            throw Exception(QString("[创建目录失败] %1").arg(folderpath));
                                        }
                                        QString filepath = folderpath + QString("/") + meta_c2s_push->_filemeta._filename;
                                        handle->_file = new QFile(filepath + Transfer::_filebuffer_extension);
                                        handle->_file->setProperty("_filepath", filepath);
                                        if (handle->_file->open(QFile::WriteOnly | QFile::Truncate) == false) {
                                            throw Exception(QString("[创建文件失败] %1").arg(handle->_file->fileName()));
                                        }
                                    }
                                    handle->_buffer.resize(handle->_tcp_client->bytesAvailable());
                                    quint64 toread = meta_c2s_push->_filemeta._filesize - handle->_file->size();
                                    quint64 length = handle->_tcp_client->read(handle->_buffer.data(), toread);
                                    handle->_file->write(handle->_buffer.data(), length);
                                    handle->_file->flush();  // 冲刷并更新文件大小

                                    // 校验数据块
                                    if (meta_c2s_push->_filemeta._filesize == (quint64)handle->_file->size()) {
                                        QByteArray hash_sha1 = Transfer::_Hash_Data(handle->_file->fileName());
                                        if (meta_c2s_push->_filemeta._hash_sha1 != hash_sha1) {
                                            throw Exception(QString("[文件签名不匹配] %1:%2").arg(QString(meta_c2s_push->_filemeta._hash_sha1.toHex()), QString(hash_sha1.toHex())));
                                        }
                                        QString filepath = handle->_file->property("_filepath").toString();
                                        bool removed = (QFile::exists(filepath) == false || QFile::remove(filepath) == true);
                                        bool renamed = handle->_file->rename(filepath);
                                        if (removed == false || renamed == false) {
                                            throw Exception(QString("[文件重命名失败] %1:%2").arg(filepath).arg(handle->_file->fileName()));
                                        }
                                        handle->_file->close();
                                        handle->_file->deleteLater(), handle->_file = nullptr;

                                        // 应答客户端
                                        handle->_echo_host._codes.append({ Transfer::_code_server_right, "_code_server_right" });
                                        handle->_echo_host._timestamp_utc = QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs);
                                        QByteArray buffer_echo = Transfer::_Dump_Head_Meta(Transfer::_magic_s2c, handle->_echo_host);
                                        handle->_tcp_client->write(buffer_echo.data(), buffer_echo.size());
                                        handle->_tcp_client->flush();
                                        handle->_Reset();  // 解析完毕，重置把柄
                                    }
                                } else if (handle->_opertype == Transfer::_oper_c2s_sync) {
                                    // 解析数据体，此操作类型无附加数据块
                                    Meta_C2S_Sync* meta_c2s_sync = (Meta_C2S_Sync*)handle->_meta;

                                    // 处理数据体
                                    QMap<QString, Filemeta> foldermeta_server;
                                    Transfer::_Foldermeta_Update(foldermeta_server, folderpath, QStringList());
                                    Meta_S2C_Sync meta_s2c_sync;
                                    Transfer::_Foldermeta_Checkout(meta_s2c_sync._foldermeta, foldermeta_server, meta_c2s_sync->_foldermeta);

                                    // 发送数据头体
                                    QByteArray buffer_head_meta = Transfer::_Dump_Head_Meta(Transfer::_magic_s2c, meta_s2c_sync);
                                    handle->_tcp_client->write(buffer_head_meta.data(), buffer_head_meta.size());
                                    handle->_tcp_client->flush();

                                    // 发送数据块，连续发送文件
                                    for (auto iter = meta_s2c_sync._foldermeta.begin(); iter != meta_s2c_sync._foldermeta.end(); iter += 1) {
                                        const Filemeta& filemeta = (*iter);
                                        QString filepath = folderpath + QString("/") + filemeta._filename;
                                        QFile file(filepath);
                                        if (file.open(QFile::ReadOnly) == false) {
                                            throw Exception(QString("[文件读取失败] %1").arg(file.fileName()));
                                        }
                                        for (QByteArray buffer_file(Transfer::_dataslice_length, '\0'); file.atEnd() == false; ) {
                                            quint64 length = file.read(buffer_file.data(), buffer_file.size());
                                            handle->_tcp_client->write(buffer_file.data(), length);
                                            handle->_tcp_client->flush();
                                        }
                                        file.close();
                                    }

                                    // 应答客户端
                                    handle->_echo_host._codes.append({ Transfer::_code_server_right, "_code_server_right" });
                                    handle->_echo_host._timestamp_utc = QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs);
                                    QByteArray buffer_echo = Transfer::_Dump_Head_Meta(Transfer::_magic_s2c, handle->_echo_host);
                                    handle->_tcp_client->write(buffer_echo.data(), buffer_echo.size());
                                    handle->_tcp_client->flush();
                                    handle->_Reset();  // 解析完毕，重置把柄
                                } else {
                                    handle->_tcp_client->close();  // 不明操作类型
                                }
                            }
                        } catch (const Exception& exception) {
                            qDebug().noquote() << exception.what();
                            handle->_tcp_client->close();
                            emit transfer->_Signal_Server_Listening(QVector<QPair<quint32, QString>> {
                                { Transfer::_code_native_error, "_code_native_error" }
                            });
                        }
                    });

                    QObject::connect(handle->_tcp_client, &QTcpSocket::stateChanged, handle, [thread, handle](const QAbstractSocket::SocketState& state) mutable -> void {
                        qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::stateChanged, handle, [thread, handle](const QAbstractSocket::SocketState& state) mutable -> void {";
                        if (state == QAbstractSocket::UnconnectedState) {
                            qDebug().noquote() << "[UnconnectedState]";
                            delete handle, handle = nullptr;
                            thread->_Decrease();
                        } else if (state == QAbstractSocket::HostLookupState) {
                            qDebug().noquote() << "[HostLookupState]";
                        } else if (state == QAbstractSocket::ConnectingState) {
                            qDebug().noquote() << "[ConnectingState]";
                        } else if (state == QAbstractSocket::ConnectedState) {
                            qDebug().noquote() << "[ConnectedState]";
                        } else if (state == QAbstractSocket::BoundState) {
                            qDebug().noquote() << "[BoundState]";
                        } else if (state == QAbstractSocket::ClosingState) {
                            qDebug().noquote() << "[ClosingState]";
                        } else if (state == QAbstractSocket::ListeningState) {
                            qDebug().noquote() << "[ListeningState]";
                        }
                    });
                });
            } catch (const std::exception& exception) {
                qDebug().noquote() << exception.what();
                tcp_server->close();
                tcp_server->deleteLater(), tcp_server = nullptr;
                thread->_Decrease();
                emit transfer->_Signal_Server_Listening(QVector<QPair<quint32, QString>> {
                    { Transfer::_code_native_error, "_code_native_error" }
                });
            }
        });
        return transfer;
    }

    static Transfer* _Client_PushFile(const QString& server_ipv4, const QString& filepath) {
        qDebug().noquote() << QString("[enter] %1:%2").arg(__FUNCTION__).arg((quint64)QThread::currentThread(), 16, 16, QChar('0'));
        Thread* thread = new Thread();
        Transfer* transfer = new Transfer();
        QObject::connect(thread, &Thread::_Signal_Thread_Idle, thread, [thread]() mutable -> void {
            qDebug().noquote() << "QObject::connect(thread, &Thread::_Signal_Thread_Idle, thread, [thread]() mutable -> void {";
            thread->quit();  // use thread->quit(), instead of thread->terminate()
            thread->wait();
            thread->deleteLater(), thread = nullptr;
        });

        thread->start();
        transfer->moveToThread(thread);
        QMetaObject::invokeMethod(transfer, [thread, transfer, server_ipv4, filepath]() -> void {
            qDebug().noquote() << QString("[enter] %1:%2").arg("QMetaObject::invokeMethod(transfer, [thread, transfer, server_ipv4, filepath]() -> void {").arg((quint64)QThread::currentThread, 16, 16, QChar('0'));
            Handle* handle = nullptr;
            try {
                handle = new Handle();
                thread->_Increase();

                handle->_tcp_client = new QTcpSocket();
                QObject::connect(transfer, &QObject::destroyed, handle, [handle]() -> void {
                    qDebug().noquote() << "QObject::connect(transfer, &QObject::destroyed, handle, [handle]() -> void {";
                    handle->_tcp_client->close();
                });

                QObject::connect(handle->_tcp_client, &QTcpSocket::connected, handle, [transfer, handle, filepath]() -> void {
                    qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::connected, handle, [transfer, handle, filepath]() -> void {";
                    try {
                        QFileInfo fileinfo(filepath);
                        if (fileinfo.isFile() == false || fileinfo.exists() == false) {
                            throw Exception(QString("[文件不存在] %1").arg(fileinfo.filePath()));
                        }
                        Meta_C2S_Push meta_c2s_push;
                        meta_c2s_push._filemeta._filename = fileinfo.fileName();
                        meta_c2s_push._filemeta._filesize = (quint64)fileinfo.size();
                        meta_c2s_push._filemeta._hash_sha1 = Transfer::_Hash_Data(fileinfo.filePath());
                        meta_c2s_push._filemeta._modified_local = fileinfo.lastModified().toMSecsSinceEpoch();

                        // 发送数据头体
                        QByteArray buffer_head_meta = Transfer::_Dump_Head_Meta(Transfer::_magic_c2s, meta_c2s_push);
                        handle->_tcp_client->write(buffer_head_meta.data(), buffer_head_meta.size());
                        handle->_tcp_client->flush();

                        // 发送数据块
                        QFile file(filepath);
                        if (file.open(QFile::ReadOnly) == false) {
                            throw Exception(QString("[文件读取失败] %1").arg(file.fileName()));
                        }
                        for (QByteArray buffer_file(Transfer::_dataslice_length, '\0'); file.atEnd() == false; ) {
                            quint64 length = file.read(buffer_file.data(), buffer_file.size());
                            handle->_tcp_client->write(buffer_file.data(), length);
                            handle->_tcp_client->flush();
                        }
                        file.close();
                    } catch (const std::exception& exception) {
                        qDebug().noquote() << exception.what();
                        handle->_tcp_client->close();
                        emit transfer->_Signal_Client_PushFile(QVector<QPair<quint32, QString>> {
                            { Transfer::_code_native_error, "_code_native_error" }
                        });
                    }
                });

                QObject::connect(handle->_tcp_client, &QTcpSocket::readyRead, handle, [transfer, handle]() -> void {
                    qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::readyRead, handle, [transfer, handle]() -> void {";
                    try {
                        // 注意清空缓存
                        for (handle->_buffer.reserve(handle->_tcp_client->bytesAvailable()); 0 < (quint64)handle->_tcp_client->bytesAvailable(); ) {
                            // 解析数据头体
                            if (Transfer::_Load_Head_Meta(handle, Transfer::_magic_s2c) == Transfer::_nega) {
                                return;
                            }

                            // 解析数据块
                            if (handle->_opertype == Transfer::_oper_p2p_echo) {
                                Meta_P2P_Echo* meta_p2p_echo = (Meta_P2P_Echo*)handle->_meta;
                                emit transfer->_Signal_Client_PushFile(meta_p2p_echo->_codes);
                                handle->_Reset();  // 解析完毕，重置把柄
                                handle->_tcp_client->close();
                                break;  // 注意已经销毁handle
                            } else {
                                handle->_tcp_client->close();  // 不明操作类型
                            }
                        }
                    } catch (const std::exception& exception) {
                        qDebug().noquote() << exception.what();
                        handle->_tcp_client->close();
                        emit transfer->_Signal_Client_PushFile(QVector<QPair<quint32, QString>> {
                            { Transfer::_code_native_error, "_code_native_error" }
                        });
                    }
                });

                QObject::connect(handle->_tcp_client, &QTcpSocket::stateChanged, handle, [thread, transfer, handle](const QAbstractSocket::SocketState& state) mutable -> void {
                    qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::stateChanged, handle, [thread, transfer, handle](const QAbstractSocket::SocketState& state) mutable -> void {";
                    if (state == QAbstractSocket::UnconnectedState) {
                        qDebug().noquote() << "[UnconnectedState]";
                        delete handle, handle = nullptr;
                        thread->_Decrease();
                    } else if (state == QAbstractSocket::HostLookupState) {
                        qDebug().noquote() << "[HostLookupState]";
                    } else if (state == QAbstractSocket::ConnectingState) {
                        qDebug().noquote() << "[ConnectingState]";
                    } else if (state == QAbstractSocket::ConnectedState) {
                        qDebug().noquote() << "[ConnectedState]";
                    } else if (state == QAbstractSocket::BoundState) {
                        qDebug().noquote() << "[BoundState]";
                    } else if (state == QAbstractSocket::ClosingState) {
                        qDebug().noquote() << "[ClosingState]";
                    } else if (state == QAbstractSocket::ListeningState) {
                        qDebug().noquote() << "[ListeningState]";
                    }
                });

                handle->_tcp_client->connectToHost(server_ipv4, Transfer::_server_port);
            } catch (const std::exception& exception) {
                qDebug().noquote() << exception.what();
                handle->_tcp_client->close();
                emit transfer->_Signal_Client_PushFile(QVector<QPair<quint32, QString>> {
                    { Transfer::_code_native_error, "_code_native_error" }
                });
            }
        });
        return transfer;
    }

    // ToDo: 树形目录结构
    static Transfer* _Client_SyncFolder(const QString& server_ipv4, const QString& folderpath) {
        qDebug().noquote() << QString("[enter] %1:%2").arg(__FUNCTION__).arg((quint64)QThread::currentThread(), 16, 16, QChar('0'));
        Thread* thread = new Thread();
        Transfer* transfer = new Transfer();
        QObject::connect(thread, &Thread::_Signal_Thread_Idle, thread, [thread]() mutable -> void {
            qDebug().noquote() << "QObject::connect(thread, &Thread::_Signal_Thread_Idle, thread, [thread]() mutable -> void {";
            thread->quit();  // use thread->quit(), instead of thread->terminate()
            thread->wait();
            thread->deleteLater(), thread = nullptr;
        });

        thread->start();
        transfer->moveToThread(thread);
        QMetaObject::invokeMethod(transfer, [thread, transfer, server_ipv4, folderpath]() -> void {
            qDebug().noquote() << QString("[enter] %1:%2").arg("QMetaObject::invokeMethod(transfer, [thread, transfer, server_ipv4, folderpath]() -> void {").arg((quint64)QThread::currentThread, 16, 16, QChar('0'));
            Handle* handle = nullptr;
            try {
                handle = new Handle();
                thread->_Increase();

                handle->_tcp_client = new QTcpSocket();
                QObject::connect(transfer, &QObject::destroyed, handle, [handle]() -> void {
                    qDebug().noquote() << "QObject::connect(transfer, &QObject::destroyed, handle, [handle]() -> void {";
                    handle->_tcp_client->close();
                });

                QObject::connect(handle->_tcp_client, &QTcpSocket::connected, handle, [transfer, handle, folderpath]() -> void {
                    qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::connected, handle, [transfer, handle, folderpath]() -> void {";
                    try {
                        Meta_C2S_Sync meta_c2s_sync;
                        Transfer::_Foldermeta_Update(meta_c2s_sync._foldermeta, folderpath, QStringList());

                        QByteArray buffer_head_meta = Transfer::_Dump_Head_Meta(Transfer::_magic_c2s, meta_c2s_sync);
                        handle->_tcp_client->write(buffer_head_meta.data(), buffer_head_meta.size());
                        handle->_tcp_client->flush();
                    } catch (const std::exception& exception) {
                        qDebug().noquote() << exception.what();
                        handle->_tcp_client->close();
                        emit transfer->_Signal_Client_SyncFolder(QVector<QPair<quint32, QString>> {
                            { Transfer::_code_native_error, "_code_native_error" }
                        });
                    }
                });

                QVector<Filemeta>::iterator iter = nullptr;
                QObject::connect(handle->_tcp_client, &QTcpSocket::readyRead, handle, [transfer, handle, folderpath, iter]() mutable -> void {
                    qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::readyRead, handle, [transfer, handle, folderpath, iter]() mutable -> void {";
                    try {
                        // 注意清空缓存
                        for (handle->_buffer.reserve(handle->_tcp_client->bytesAvailable()); 0 < (quint64)handle->_tcp_client->bytesAvailable(); ) {
                            // 解析数据头体
                            qint32 loaded = Transfer::_Load_Head_Meta(handle, Transfer::_magic_s2c);
                            if (loaded == Transfer::_nega) {
                                return;
                            }

                            if (handle->_opertype == Transfer::_oper_p2p_echo) {
                                Meta_P2P_Echo* meta_p2p_echo = (Meta_P2P_Echo*)handle->_meta;
                                emit transfer->_Signal_Client_SyncFolder(meta_p2p_echo->_codes);
                                handle->_Reset();  // 解析完毕，重置把柄
                                handle->_tcp_client->close();
                                break;  // 注意已经销毁handle
                            } else if (handle->_opertype == Transfer::_oper_s2c_sync) {
                                // 解析数据体，此操作有附加数据块
                                qDebug().noquote() << QString("[%1] bytesAvailable() = %2").arg("if (handle->_opertype == Transfer::_oper_s2c_sync) {").arg(Transfer::_Reduce_Filesize(handle->_tcp_client->bytesAvailable()));
                                Meta_S2C_Sync* meta_s2c_sync = (Meta_S2C_Sync*)handle->_meta;
                                if (loaded == Transfer::_none) {  // 首次解析数据体
                                    iter = meta_s2c_sync->_foldermeta.begin();
                                }

                                if (iter != meta_s2c_sync->_foldermeta.end()) {
                                    const Filemeta& filemeta = (*iter);
                                    if (handle->_file == nullptr) {
                                        QString filepath = folderpath + QString("/") + filemeta._filename;
                                        handle->_file = new QFile(filepath + Transfer::_filebuffer_extension);
                                        handle->_file->setProperty("_filepath", filepath);
                                        if (handle->_file->open(QFile::WriteOnly | QFile::Truncate) == false) {
                                            throw Exception(QString("[文件读写失败] %1").arg(handle->_file->fileName()));
                                        }
                                    }
                                    handle->_buffer.resize(handle->_tcp_client->bytesAvailable());
                                    quint64 toread = filemeta._filesize - handle->_file->size();
                                    quint64 length = handle->_tcp_client->read(handle->_buffer.data(), toread);
                                    handle->_file->write(handle->_buffer.data(), length);
                                    handle->_file->flush();  // 冲刷并更新文件大小
                                    if (filemeta._filesize == (quint64)handle->_file->size()) {
                                        QByteArray hash_sha1 = Transfer::_Hash_Data(handle->_file->fileName());
                                        if (filemeta._hash_sha1 != hash_sha1) {
                                            throw Exception(QString("[文件签名不匹配] %1:%2").arg(QString(filemeta._hash_sha1.toHex()), QString(hash_sha1.toHex())));
                                        }
                                        QString filepath = handle->_file->property("_filepath").toString();
                                        bool removed = (QFile::exists(filepath) == false || QFile::remove(filepath) == true);
                                        bool renamed = handle->_file->rename(filepath);
                                        if (removed == false || renamed == false) {
                                            throw Exception(QString("[文件重命名失败] %1:%2").arg(filepath, handle->_file->fileName()));
                                        }

                                        handle->_file->close();
                                        handle->_file->deleteLater(), handle->_file = nullptr;
                                        iter += 1;
                                        if (iter == meta_s2c_sync->_foldermeta.end()) {
                                            handle->_echo_host._codes.append({ Transfer::_code_client_right, "_code_client_right" });
                                            handle->_echo_host._timestamp_utc = QDateTime::currentDateTimeUtc().toString(Qt::ISODateWithMs);
                                            emit transfer->_Signal_Client_SyncFolder(handle->_echo_host._codes);
                                            handle->_Reset();  // 解析完毕，重置把柄
                                        }
                                    }
                                }
                            } else {
                                handle->_tcp_client->close();  // 不明操作类型
                            }
                        }
                    } catch (const std::exception& exception) {
                        qDebug().noquote() << exception.what();
                        handle->_tcp_client->close();
                        emit transfer->_Signal_Client_SyncFolder(QVector<QPair<quint32, QString>> {
                            { Transfer::_code_native_error, "_code_native_error" }
                        });
                    }
                });

                QObject::connect(handle->_tcp_client, &QTcpSocket::stateChanged, handle, [thread, transfer, handle](const QAbstractSocket::SocketState& state) mutable -> void {
                    qDebug().noquote() << "QObject::connect(handle->_tcp_client, &QTcpSocket::stateChanged, handle, [thread, transfer, handle](const QAbstractSocket::SocketState& state) mutable -> void {";
                    if (state == QAbstractSocket::UnconnectedState) {
                        qDebug().noquote() << "[UnconnectedState]";
                        delete handle, handle = nullptr;
                        thread->_Decrease();
                    } else if (state == QAbstractSocket::HostLookupState) {
                        qDebug().noquote() << "[HostLookupState]";
                    } else if (state == QAbstractSocket::ConnectingState) {
                        qDebug().noquote() << "[ConnectingState]";
                    } else if (state == QAbstractSocket::ConnectedState) {
                        qDebug().noquote() << "[ConnectedState]";
                    } else if (state == QAbstractSocket::BoundState) {
                        qDebug().noquote() << "[BoundState]";
                    } else if (state == QAbstractSocket::ClosingState) {
                        qDebug().noquote() << "[ClosingState]";
                    } else if (state == QAbstractSocket::ListeningState) {
                        qDebug().noquote() << "[ListeningState]";
                    }
                });

                handle->_tcp_client->connectToHost(server_ipv4, Transfer::_server_port);
            } catch (const std::exception& exception) {
                qDebug().noquote() << exception.what();
                handle->_tcp_client->close();
                emit transfer->_Signal_Client_SyncFolder(QVector<QPair<quint32, QString>> {
                    { Transfer::_code_native_error, "_code_native_error" }
                });
            }
        });
        return transfer;
    }

signals:
    void _Signal_Server_Listening(const QVector<QPair<quint32, QString>>& echo);
    void _Signal_Client_PushFile(const QVector<QPair<quint32, QString>>& echo);
    void _Signal_Client_SyncFolder(const QVector<QPair<quint32, QString>>& echo);
};
