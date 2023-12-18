import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: childrenRect.width
        height: childrenRect.height
        color: "lightblue"

        AnimatedImage {
            id: animatedImage
            source: "qrc:/images/animation.gif"
            speed: 1.0
        }

        Rectangle {
            width: 4
            height: 8
            anchors.left: animatedImage.left
            anchors.leftMargin: (animatedImage.width - width) * animatedImage.currentFrame / animatedImage.frameCount
            anchors.top: animatedImage.bottom
            color: "red"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                animatedImage.paused = !animatedImage.paused
            }
        }
    }
}
