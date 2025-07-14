import QtQuick
import QtQuick.Window
import QtMultimedia
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // 模糊图片
    FastBlur {
        id: fastblur
        width : videooutput.contentRect.width  * 2
        height: videooutput.contentRect.height * 2
        x: -(width - parent.width) / 2
        y: -(height - parent.height) / 2
        source: image
        radius: 32
        cached: false
    }

    // 背景图片
    Image {
        id: image
        visible: false
        anchors.fill: videooutput
    }

    // 视频输出
    VideoOutput {
        id: videooutput
        visible: true
        anchors.fill: parent
        fillMode: VideoOutput.PreserveAspectFit
        orientation: 0  // [0, 90, 180, 270]

        onContentRectChanged: {
            console.debug(`contentRect = ${videooutput.contentRect}`)
        }

        onSourceRectChanged: {
            console.debug(`sourceRect  = ${videooutput.sourceRect}`)
        }
    }

    // 媒体播放器
    MediaPlayer {
        id: mediaplayer
        videoOutput: videooutput
        audioOutput: AudioOutput {}
        source: "qrc:/music/music.mp3"
        // source: "qrc:/video/video.mp4"
        loops: 1
        playbackRate: 1.0

        property bool once: false
        onPositionChanged: {
            if(once === false) {
                once = true
                videooutput.grabToImage(function (result) {
                    image.source = result.url
                })
            }
        }

        onErrorChanged: {
            console.debug(`error = ${mediaplayer.error}, errorString = ${mediaplayer.errorString}`)
        }

        Component.onCompleted: {
            console.debug(`error        : ResourceError==${MediaPlayer.ResourceError}, FormatError==${MediaPlayer.FormatError}, NetworkError==${MediaPlayer.NetworkError}, AccessDeniedError==${MediaPlayer.AccessDeniedError}`)
            console.debug(`mediaStatus  : NoMedia==${MediaPlayer.NoMedia}, LoadingMedia==${MediaPlayer.LoadingMedia}, LoadedMedia==${MediaPlayer.LoadedMedia}, BufferingMedia==${MediaPlayer.BufferingMedia}, StalledMedia==${MediaPlayer.StalledMedia}, BufferedMedia==${MediaPlayer.BufferedMedia}, EndOfMedia==${MediaPlayer.EndOfMedia}, InvalidMedia=${MediaPlayer.InvalidMedia}`)
            console.debug(`playbackState: StoppedState==${MediaPlayer.StoppedState}, PlayingState==${MediaPlayer.PlayingState}, PauseState==${MediaPlayer.PausedState}`)
        }
    }

    // 播放按钮
    Label {
        id: label_play
        anchors.left: videooutput.left
        anchors.verticalCenter: rectangle.verticalCenter
        background: Rectangle {
            border.width: 1
        }
        text: (mediaplayer.playbackState === MediaPlayer.PlayingState) ? "点击暂停" : "点击播放"
        focus: true

        MouseArea {
            anchors.fill: parent

            onClicked: {
                if (mediaplayer.playbackState === MediaPlayer.PlayingState) {
                   mediaplayer.pause()
                } else {
                    mediaplayer.play()
                    mediaplayer.activeAudioTrack = 0
                    mediaplayer.activeSubtitleTrack = 0
                    mediaplayer.activeVideoTrack = 0
                }
            }
        }

        Keys.onLeftPressed: {
            mediaplayer.position = mediaplayer.position - 3000
        }

        Keys.onRightPressed: {
            mediaplayer.position = mediaplayer.position + 3000
        }
    }

    // 进度条
    Rectangle {
        id: rectangle
        height: 10
        anchors.left: videooutput.left
        anchors.right: videooutput.right
        anchors.bottom: videooutput.bottom
        anchors.leftMargin: label_play.width
        border.width: 1

        Rectangle {
            id: rectangle_progress
            width: parent.width * mediaplayer.position / mediaplayer.duration
            height: parent.height
            color: "#FF00FF00"
        }
    }
}
