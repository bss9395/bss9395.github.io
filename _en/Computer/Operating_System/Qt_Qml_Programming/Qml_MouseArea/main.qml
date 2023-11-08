import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    visible: true
    width: 640
    height: 480

    Column {
        anchors.fill: parent

        Row {
            width: parent.width
            height: parent.height / 2

            Rectangle {
                id: rectangle_left
                width: parent.width / 2
                height: parent.height

                Text {
                    id: text
                    anchors.centerIn: parent
                    text: "Qt"
                }

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton | Qt.RightButton

                    onWheel: (wheel) => {
                        console.debug('onWheel, wheel.angleDelta.x = ', wheel.angleDelta.x)
                        if(wheel.modifiers & Qt.ControlModifier) {
                            if(wheel.angleDelta.y > 0) {
                                text.font.pointSize += 1
                            } else {
                                text.font.pointSize -= 1
                            }
                        }
                    }

                    onClicked: {
                        console.debug('onClicked')
                        timer.count += 1
                        if(timer.count == 1) {
                            console.debug('clicked')
                            timer.start()
                        }
                        if(timer.count == 2) {
                            console.debug('double clicked')
                            timer.count = 0
                            timer.stop()
                            if(mouse.button === Qt.LeftButton && mouse.modifiers & Qt.ShiftModifier) {
                                console.debug('shift double cliced')
                            }
                        }
                    }
                }

                Timer {
                    id: timer
                    interval: 300

                    property int count: 0

                    onTriggered: {
                        timer.count = 0
                        timer.stop()
                    }
                }
            }

            Rectangle {
                id: rectangle_right
                width: parent.width / 2
                height: parent.height
                color: "green"

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton | Qt.RightButton

                    onClicked: {
                        console.debug('onClicked')

                        if(mouse.button === Qt.RightButton) {
                            rectangle_right.color = "blue"
                        } else {
                            rectangle_right.color = "red"
                        }
                    }

                    onDoubleClicked: (mouse) => {
                        console.debug('onDoubleClicked')
                        if(mouse.button === Qt.LeftButton && mouse.modifiers & Qt.ShiftModifier) {
                            rectangle_right.color = "green"
                        }
                    }
                }
            }
        }

        Row {
            width: parent.width
            height: parent.height / 2

            Rectangle {
                id: rectangle_parent
                width: parent.width / 2
                height: parent.height

                Rectangle {
                    id: rectangle
                    width: 50
                    height: 50
                    color: "red"
                    opacity: (parent.width - rectangle.x) / parent.width

                    MouseArea {
                        anchors.fill: parent
                        drag.target: rectangle
                        drag.axis: Drag.XAxis
                        drag.minimumX: 0
                        drag.maximumX: rectangle_parent.width - rectangle.width
                    }
                }
            }

            Rectangle {
                width: parent.width / 2
                height: parent.height

                Rectangle_Color {
                    x: 110
                    color: "blue"
                }

                Rectangle_Color {
                    x: 140
                    color: "red"
                }

                Rectangle_Color {
                    x: 170
                    color: "yellow"
                }

                Rectangle_Color {
                    x: 200
                    color: "black"
                }

                Rectangle_Color {
                    x: 230
                    color: "steelblue"
                }

                Rectangle_Color {
                    x: 260
                    color: "green"
                }

                DropArea {
                    width: 50
                    height: 50
                    anchors.centerIn: parent

                    Rectangle {
                        id: area
                        anchors.fill: parent
                        border.color: "black"
                    }

                    onEntered: {
                        area.color = drag.source.color
                    }
                }
            }
        }
    }
}
