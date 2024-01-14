#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>

class Config : public QObject {
    Q_OBJECT

public:
    static Config &instance();
    explicit Config(QObject *parent = nullptr);
    Config(const Config &config) = delete;
    Config(Config &&config) = delete;
    Config &operator=(const Config &config) = delete;
    Config &operator=(Config &&config) = delete;
    virtual ~Config();

public:
    Q_INVOKABLE void greeting();
};

#endif // CONFIG_H
