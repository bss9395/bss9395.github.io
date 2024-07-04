import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // SoundEffect用于播放低延迟的声音
    SoundEffect {
        id: soundeffect
        source: "qrc:/music/soundeffect.wav"  // 资源路径的加载方式解析正常
        loops: 1
        muted: false
        volume: 1.0

        onStatusChanged: {
            console.debug(`status=${soundeffect.status}`)
        }

        Component.onCompleted: {
            console.debug(`status: Null==${SoundEffect.Null}, Loading==${SoundEffect.Loading}, Ready==${SoundEffect.Ready}, Error==${SoundEffect.Error}`)
        }
    }

    Label {
        id: label
        anchors.centerIn: parent
        background: Rectangle {
            border.width: 1
        }
        text: "点击播放"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                soundeffect.play()
            }
        }
    }
}
