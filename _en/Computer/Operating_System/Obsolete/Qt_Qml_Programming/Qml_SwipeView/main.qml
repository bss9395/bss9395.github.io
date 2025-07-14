import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQml 2.12

Rectangle {
    property bool carousel_entered: false
    id: window
    width: 800
    height: 480
    visible: true
    color: "red"

    Control {
        width: parent.width
        height: swipeview.height

        MouseArea {
            id: mousearea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                console.debug('mousearea:onEntered')
                carousel_entered = true
            }

            onExited: {
                console.debug('mousearea:onExited')
                carousel_entered = false
            }

            onPositionChanged: {
                console.debug('mousearea:onPositionChanged')
                carousel_entered = true
            }
        }

        Label {
            id: label_navigation_left
            visible: (carousel_entered === true) && (0 < swipeview.currentIndex)
            width: 24
            height: swipeview.height
            anchors.right: swipeview.left
            anchors.verticalCenter: swipeview.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "<"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('label_navigation_left:onClicked')
                    if(0 <= swipeview.currentIndex - 1) {
                        swipeview.currentIndex = swipeview.currentIndex - 1
                    }
                }
            }
        }

        SwipeView {
            id: swipeview
            width: 618
            x: (window.width - width) / 2
            orientation: Qt.Horizontal
            clip: true
            hoverEnabled: false
            currentIndex: 0

            Repeater {
                model: 5

                Row {
                    height: 135
                    spacing: 16
                    rightPadding: 16

                    Image {
                        width: 220
                        height: parent.height
                        source: "images/Frame.jpg"
                        // fillMode: Image.PreserveAspectFit
                    }

                    Image {
                        width: 220
                        height: parent.height
                        source: "images/Frame.jpg"
                        // fillMode: Image.PreserveAspectFit
                    }
                }
            }

            Timer {
                running: (1 < swipeview.count) && (carousel_entered === false)
                interval: 5000
                repeat: true

                onTriggered: {
                    if(swipeview.currentIndex + 1 < swipeview.count) {
                        swipeview.currentIndex = swipeview.currentIndex + 1
                    } else {
                        swipeview.currentIndex = 0
                    }
                }
            }
        }

        Label {
            id: label_navigation_right
            visible: (carousel_entered === true) && (swipeview.currentIndex < swipeview.count - 1)
            width: 24
            height: swipeview.height
            anchors.left: swipeview.right
            anchors.verticalCenter: swipeview.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: ">"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('label_navigation_right:onClicked')
                    if(swipeview.currentIndex + 1 < swipeview.count) {
                        swipeview.currentIndex = swipeview.currentIndex + 1
                    }
                }
            }
        }
    }
}
