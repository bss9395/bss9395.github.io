/* Qt6_SoundEffect.h
Author: BS9395
Update: 2023-8-30T11:33:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_SOUNDEFFECT_H
#define QT6_SOUNDEFFECT_H

#include <QMainWindow>
#include "ui_Qt6_SoundEffect.h"
#include <QtMultimedia>
#include <QtMultimediaWidgets>

class Qt6_SoundEffect : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_SoundEffect *_ui = nullptr;
    QSoundEffect *_sound_defense = new QSoundEffect();
    QSoundEffect *_sound_attack  = new QSoundEffect();

public:
    Qt6_SoundEffect(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_SoundEffect) {
        _ui->setupUi(this);

        QObject::connect(_ui->PB_Defense_AK47, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/Ak7.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Defense_Gun, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/machinegun.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Defense_Attack, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/fire.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Defense_bullet, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/shell.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Defense_Explode1, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/blast.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Defense_Explode2, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/blast2.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Attack_AK47, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/Ak7.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Attack_Gun, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/machinegun.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Attack_Attack, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/fire2.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Attack_Landmine, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/mine.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Attack_Explode, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/blast.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        QObject::connect(_ui->PB_Attack_Tank, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl("file::/musics/tank.wav");
            _sound_defense->setSource(url);
            _sound_defense->play();
        });

        _sound_defense->setLoopCount(3);
        _sound_attack->setLoopCount(3);
    }

    ~Qt6_SoundEffect() {
        delete _ui;
    }

};
#endif // QT6_SOUNDEFFECT_H
