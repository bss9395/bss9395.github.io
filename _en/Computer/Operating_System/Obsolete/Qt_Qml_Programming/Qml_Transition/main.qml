import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        width: 75
        height: 75
        state: "Release"
        states: [
            State {
                name: "Release"

                PropertyChanges {
                    target: rectangle
                    color: "red"
                }
            },
            State {
                name: "Pressed"

                PropertyChanges {
                    target: rectangle
                    color: "green"
                }
            }
        ]
        transitions: [
            Transition {
                from: "Release"
                to: "Pressed"

                PropertyAnimation {
                    property: "color"
                    duration: 2000
                }
            },
            Transition {
                from: "Pressed"
                to: "Release"

                PropertyAnimation {
                    property: "color"
                    duration: 2000
                }
            }
        ]

        MouseArea {
            anchors.fill: parent

            onPressed: {
                rectangle.state = "Pressed"
            }

            onReleased: {
                rectangle.state = "Release"
            }
        }
    }
}
