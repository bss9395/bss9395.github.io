import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "lightgrey"
        state: "Warning"
        states: [
            State {
                name: "Warning"
                when: mouseArea.pressed === false

                PropertyChanges {
                    target: rectangle
                    color: "lightgrey"
                }

                PropertyChanges {
                    target: image
                    source: "qrc:/images/warning.png"
                }
            },
            State {
                name: "Critical"
                when: mouseArea.pressed === true

                PropertyChanges {
                    target: rectangle
                    color: "red"
                }

                PropertyChanges {
                    target: image
                    source: "qrc:/images/critical.png"
                }
            }
        ]

        Image {
            width: 24
            height: 24
            source: "qrc:/images/switch.png"

            MouseArea {
                id: mouseArea
                anchors.fill: parent

//                onClicked: {
//                    if(rectangle.state === "Warning") {
//                        rectangle.state = "Critical"
//                    } else if(rectangle.state === "Critical") {
//                        rectangle.state = "Warning"
//                    }
//                }
            }
        }

        Image {
            id: image
            anchors.centerIn: parent
            source: "qrc:/images/warning.png"
        }
    }
}
