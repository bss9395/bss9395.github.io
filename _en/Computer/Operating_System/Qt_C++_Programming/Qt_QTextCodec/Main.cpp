/* Cpp_BitField.cpp
Author: bss9395
Update: 2024-09-05T22:06:45:00+08@China-Beijing+08
*/

#define _CRT_SECURE_NO_WARNINGS
#include <QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <QLocale>
#include <QFile>
#include <iostream>
#include <cstdlib>
#include <string>
#include <clocale>
#include <fstream>
#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>

struct Locale {
    static const char* _Platform(const char* windows, const char *linux) {
        (void)linux;
        return windows;
    }

    inline static const char* _System     = _Platform(""      , ""                );
    inline static const char* _UTF_8      = _Platform(".UTF-8", "en_GB.UTF-8"     );
    inline static const char* _ISO_8859_1 = _Platform(".28591", "en_GB.ISO-8859-1");
    inline static const char* _GBK        = _Platform(".936"  , "zh_CN.GBK"       );
};

void _AvailableCodecs() {
    QLocale system = QLocale::system();
    qDebug().noquote() << "system.name() = " << system.name();

    QList<QByteArray> codecs = QTextCodec::availableCodecs();
    qDebug().noquote() << "codecs = " << codecs;

    char *locale_current = nullptr;
    locale_current = setlocale(LC_ALL, NULL);  // 程序启动时默认locale为C
    qDebug().noquote() << "locale_current = " << locale_current;
    setlocale(LC_ALL, Locale::_GBK);           // win32-mingw编译器可能不可用
    locale_current = setlocale(LC_ALL, NULL);  // 采用setlocale(LC_ALL, NULL)查询当前locale
    qDebug().noquote() << "locale_current = " << locale_current;
    setlocale(LC_ALL, Locale::_UTF_8);         // win32-mingw编译器可能不可用
    locale_current = setlocale(LC_ALL, NULL);  // 采用setlocale(LC_ALL, NULL)查询当前locale
    qDebug().noquote() << "locale_current = " << locale_current;

    QTextCodec* codec_current = nullptr;
    codec_current = QTextCodec::codecForLocale();
    qDebug().noquote() << "codec_current->name() = " << codec_current->name();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    codec_current = QTextCodec::codecForLocale();
    qDebug().noquote() << "codec_current->name() = " << codec_current->name();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    codec_current = QTextCodec::codecForLocale();
    qDebug().noquote() << "codec_current->name() = " << codec_current->name();
}

void _Transcode_C() {
    std::string  text_utf8    = "你好，世界！";
    std::wstring text_unicode = std::wstring(1024, '\0');
    std::string  text_gbk     = std::string(1024, '\0');

    char *locale_current = nullptr;
    setlocale(LC_ALL, Locale::_UTF_8);
    locale_current = setlocale(LC_ALL, NULL);  // win32-mingw编译器可能不可用
    fprintf(stdout, "locale_current = %s\n", locale_current);
    int   numb = mbstowcs((wchar_t*)text_unicode.data(), text_utf8.data(), text_unicode.size());
    setlocale(LC_ALL, Locale::_GBK);
    int length = wcstombs((char*)text_gbk.data(), text_unicode.data(), text_gbk.size());
    fprintf(stdout, "numb = %d, length = %d\n", numb, length);

    std::wstring text_unicode_ = std::wstring(1024, '\0');
    std::string  text_gbk_     = std::string(1024, '\0');
    setlocale(LC_ALL, Locale::_UTF_8);
    int   numb_ = mbstowcs((wchar_t*)text_unicode_.data(), text_gbk.data(), text_unicode_.size());  // 二次转码无效
    setlocale(LC_ALL, Locale::_GBK);
    int length_ = wcstombs((char*)text_gbk_.data(), text_unicode_.data(), text_gbk_.size());
    fprintf(stdout, "numb_ = %d, length_ = %d\n", numb_, length_);

    FILE *file = fopen("text.txt", "wb");  // 若文件存在则截断，若文件不存在则创建
    fwrite(text_utf8.data(), sizeof(char), text_utf8.size(), file);
    fwrite("\n", sizeof(char), strlen("\n"), file);
    fflush(file);
    fwrite(text_gbk.data(), sizeof(char), length, file);
    fwrite("\n", sizeof(char), strlen("\n"), file);
    fflush(file);
    fwrite(text_gbk_.data(), sizeof(char), length_, file);
    fwrite("\n", sizeof(char), strlen("\n"), file);
    fflush(file);
    fclose(file);
}

void _Transcode_Qt() {
    QTextCodec *codec_utf8   = QTextCodec::codecForName("UTF-8");
    QTextCodec *codec_gbk    = QTextCodec::codecForName("GBK");

    QByteArray  text_utf8    = "你好，世界！";
    QString     text_unicode = codec_utf8->toUnicode(text_utf8);
    QByteArray  text_gbk     = codec_gbk->fromUnicode(text_unicode);
    qDebug().noquote() << QString("text_unicode.size() = %1, text_gbk.size() = %2").arg(text_unicode.size()).arg(text_gbk.size());

    QString     text_unicode_ = codec_utf8->toUnicode(text_gbk);       // 二次转码无效
    QByteArray  text_gbk_     = codec_gbk->fromUnicode(text_unicode_);
    qDebug().noquote() << QString("text_unicode_.size() = %1, text_gbk_.size() = %2").arg(text_unicode_.size()).arg(text_gbk_.size());

    QFile file("text.txt");
    file.open(QFile::WriteOnly | QFile::Truncate);  // 若文件存在则截断，若文件不存在则创建
    file.write(text_utf8.data(), text_utf8.size());
    file.write("\n");
    file.flush();
    file.write(text_gbk.data(), text_gbk.size());
    file.write("\n");
    file.flush();
    file.write(text_gbk_.data(), text_gbk_.size());
    file.write("\n");
    file.flush();
    file.close();
}

// MSVC编译选项/source-charset:utf-8指定文件输入为UTF-8，/execution-charset:utf-8指定文本输出为UTF-8
// MSVC编译选项在输入时将文件编码转码为文本编码，file.FromInto()     => text
// QString    在构造时将文本编码转码为内部编码，text.FromUTF8()     => unicode
// qDebug()   在输出时将内部编码转码为本地编码，unicode.IntoLocal() => multibyte
// std::cout()在输出时无转码操作            ，multibyte           => multibyte
// 指定MCVS采用UTF-8编码处理源文件并且关闭转码操作，指定编译选项/utf-8 == /source-charset:utf-8 + /execution-charset:utf-8
void _Print() {
    auto _ToLocal = [](const QString& text_utf8) -> std::string {
        // return QTextCodec::codecForLocale()->fromUnicode(text_utf8).toStdString();
        return text_utf8.toLocal8Bit().toStdString();
    };

    Poco::AutoPtr<Poco::ConsoleChannel> console_channel(new Poco::ConsoleChannel());
    Poco::Logger::root().setChannel(console_channel);
    Poco::Logger::root().setLevel(Poco::Message::PRIO_TRACE);

    // QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));  // 仅改变Qt的输入与输出的LocalCodec，不改变C/C++的setlocale()，采用系统默认，非必要设置
    qDebug().noquote() << QString::fromLocal8Bit("你好，世界！");
    qDebug().noquote() << QString::fromUtf8("你好，世界！");
    qDebug().noquote() << "你好，世界！";
    qDebug().noquote() << QString("你好，世界！");
    std::cout << "你好，世界！" << std::endl;
    std::cout << _ToLocal("你好，世界！") << std::endl;
    Poco::Logger::root().information("你好，世界！");            // 相当于调用std::cout
    Poco::Logger::root().information(_ToLocal("你好，世界！"));  // 相当于调用std::cout
}

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);

    // _AvailableCodecs();
    // _Transcode_C();
    // _Transcode_Qt();
    _Print();

    return application.exec();
}
