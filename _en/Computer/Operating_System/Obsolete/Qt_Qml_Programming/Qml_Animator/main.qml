import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        width: 50
        height: 50
        scale: 1.0

        ParallelAnimation {
            id: parallelanimation

            PropertyAnimation {
                target: rectangle
                property: "color"
                from: "forestgreen"
                to: "lightsteelblue"
                duration: 1000
            }

            ScaleAnimator {
                target: rectangle
                from: 1.0
                to: 2.0
                duration: 1000
            }
        }

        onColorChanged: {
            console.debug(`color = ${color}`)
        }

        onScaleChanged: {
            console.debug(`scale = ${scale}`)
        }
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            parallelanimation.start()
        }
    }
}
