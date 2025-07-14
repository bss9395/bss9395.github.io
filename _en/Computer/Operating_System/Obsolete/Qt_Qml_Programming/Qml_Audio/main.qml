import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // Audio用于播放非低延迟的声音
    Audio {
        id: audio
        audioRole: Audio.MusicRole
        source: "qrc:/music/music.mp3"
        autoLoad: false
        autoPlay: false
        loops: 0
        playbackRate: 1.0
        volume: 1.0

        onErrorChanged: {
            console.debug(`error = ${audio.error}, errorString = ${audio.errorString}`)
        }

        onPlaybackStateChanged: {
            console.debug(`playbackState = ${audio.playbackState}`)
        }

        onStatusChanged: {
            console.debug(`status = ${audio.status}`)
        }

        Component.onCompleted: {
            console.debug(`playbackState: StoppedState==${Audio.StoppedState}, PlayingState==${Audio.PlayingState}, PausedState==${Audio.PausedState}`)
            console.debug(`status       : StoppedState==${Audio.StoppedState}, NoMedia==${Audio.NoMedia}, Loading==${Audio.Loading}, Loaded==${Audio.Loaded}, Buffering==${Audio.Buffering}, Stalled==${Audio.Stalled}, Buffered==${Audio.Buffered}, EndOfMedia==${Audio.EndOfMedia}, InvalidMedia==${Audio.InvalidMedia}`)
        }
    }

    Rectangle {
        id: rectangle
        width: 300
        height: 10
        anchors.centerIn: parent
        border.width: 1
        color: "#FFFFFFFF"

        Rectangle {
            id: rectangle_progress
            width: parent.width * audio.position / audio.duration
            height: parent.height
            color: "#FF00FF00"
        }
    }

    Label {
        id: label_play
        anchors.top: rectangle.bottom
        anchors.horizontalCenter: rectangle.horizontalCenter
        background: Rectangle {
            border.width: 1
        }
        text: (audio.playbackState === Audio.PlayingState)? "点击暂停" : "点击播放"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                if(audio.playbackState === Audio.PlayingState) {
                    audio.pause()
                } else {
                    audio.play()
                }
            }
        }
    }

    Label {
        id: label_muted
        anchors.top: label_play.bottom
        anchors.horizontalCenter: label_play.horizontalCenter
        background: Rectangle {
            border.width: 1
        }
        text: (audio.muted === false) ? "点击静音" : "取消静音"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                audio.muted = (audio.muted === false) ? true : false
            }
        }
    }
}
