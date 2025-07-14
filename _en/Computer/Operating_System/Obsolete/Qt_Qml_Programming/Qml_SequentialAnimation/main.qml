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
        border.width: 1

        Column {
            Text {
                id: text_line1
                text: "Code less."
                opacity: 0.0
            }

            Text {
                id: text_line2
                text: "Create more."
                opacity: 0.0
            }

            Text {
                id: text_line3
                text: "Deploy everywhere."
                opacity: 0.0
            }
        }
    }

    SequentialAnimation {
        id: sequentialanimation
        running: false

        PropertyAnimation {
            target: text_line1
            property: "opacity"
            from: 0.0
            to: 1.0
            duration: 2000
        }

        PropertyAnimation {
            target: text_line2
            property: "opacity"
            from: 0.0
            to: 1.0
            duration: 2000
        }

        PropertyAnimation {
            target: text_line3
            property: "opacity"
            from: 0.0
            to: 1.0
            duration: 2000
        }
    }

    MouseArea {
        anchors.fill: parent

        onPressed: {
            sequentialanimation.start()
        }
    }
}
