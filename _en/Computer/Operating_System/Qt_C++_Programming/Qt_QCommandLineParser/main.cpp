#include <QDebug>
#include <QCommandLineParser>
#include <QApplication>

void _Print_Arguments(int argc, char *argv[], const QStringList &arguments) {
    qDebug().noquote() << "================================================================================";
    qDebug().noquote() << "argc = " << argc;

    for(int i = 0; i < argc; i += 1) {
        qDebug().noquote() << QString("argv[%1] = %2").arg(i).arg(argv[i]);
    }

    qDebug().noquote() << "arguments = " << arguments;
}

void _Parse_Options(const QStringList &arguments) {
    qDebug().noquote() << "================================================================================";
    QCommandLineParser parser;
    parser.setOptionsAfterPositionalArgumentsMode(QCommandLineParser::ParseAsOptions);
    parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
    parser.setApplicationDescription("QCommandLineParser example.");
    parser.addHelpOption();     // 添加选项-h --help
    parser.addVersionOption();  // 添加选项-v --version
    parser.addOption({{ "d", "debug"    }, "Enable Debug mode", "true" });
    parser.addOption({{ "p", "protocol" }, "MQTT protocol version.\n3: MQTT 3.1\n4: MQTT 3.1.1", "version", "3" });
    parser.addOption({{ "a", "address"  }, "Host to connect to, eg ws://broker.hivemq.com:8000/mqtt", "host" });
    parser.addOption({{ "t", "topic"    }, "Topic to subscribe to", "topic" });

    parser.parse(arguments);
    qDebug().noquote() << "parser.positionalArguments() = " << parser.positionalArguments();
    qDebug().noquote() << "parser.optionNames()         = " << parser.optionNames();
    if(parser.positionalArguments().length() == 0) {  // 无额外参数
        parser.process(arguments);
        QString debug    = parser.value("debug");
        qDebug().noquote() << "debug    = " << debug;
        QString protocol = parser.value("protocol");
        qDebug().noquote() << "protocol = " << protocol;
    } else {                                          // 有额外参数
        parser.showHelp();
        QCoreApplication::quit();
    }
}

// 命令行参数解析为子命令：[application routine --opt=opt -t=t] 等价于 [(application routine) --opt=opt -t=t]
void _Parse_Subroutine(const QStringList &arguments) {
    qDebug().noquote() << "================================================================================";
    QCommandLineParser parser;
    parser.setOptionsAfterPositionalArgumentsMode(QCommandLineParser::ParseAsOptions);
    parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
    parser.setApplicationDescription("QCommandLineParser example.");
    parser.addHelpOption();     // 添加选项-h --help
    parser.addVersionOption();  // 添加选项-v --version
    parser.addPositionalArgument("resize", "Resize the object to a new size.", "resize [resize_options]");

    if(2 <= arguments.length()) {
        if(arguments[1] == "resize") {
            parser.addOption({{ "s", "size"        }, "New size.", "[100, 100]" });
            parser.addOption({{ "o", "orientation" }, "Orientation", "Horizontal" });

            parser.parse(arguments);
            qDebug().noquote() << "parser.positionalArguments() = " << parser.positionalArguments();
            qDebug().noquote() << "parser.optionNames()         = " << parser.optionNames();
            if(parser.positionalArguments().length() == 1) {  // 无额外参数
                parser.process(arguments);
                QString size = parser.value("size");
                qDebug().noquote() << "size = " << size;
            } else {                                          // 有额外参数
                parser.showHelp();
                QCoreApplication::quit();
            }
        } else {
            _Parse_Options(arguments);
        }
    } else {
        parser.showHelp();
        QCoreApplication::quit();
    }
}

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    application.setApplicationVersion("1.1.1");

    _Print_Arguments(argc, argv, application.arguments());
    _Parse_Subroutine(application.arguments());

    return application.exec();
}
