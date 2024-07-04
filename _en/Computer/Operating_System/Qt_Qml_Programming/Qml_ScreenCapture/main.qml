import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtMultimedia
import Qt.labs.platform

Window {
    id: window
    width: 400
    height: 300
    visible: true
    title: qsTr("Hello World")
    // flags: Qt.Window | Qt.FramelessWindowHint | Qt.Tool | Qt.X11BypassWindowManagerHint
    opacity: 0.125

    ScreenCapture {
        id: screencapture
        active: true
    }

    VideoOutput {
        id: videooutput
        visible: false
        width: Screen.width
        height: Screen.height
        fillMode: VideoOutput.PreserveAspectFit
        orientation: 0
    }

    CaptureSession {
        id: capturesession
        screenCapture: screencapture
        videoOutput: videooutput
    }

    Component.onCompleted: {
        videooutput.grabToImage(function (result) {
            result.saveToFile("E:/Desktop/untitled.png")
        })
    }
}
