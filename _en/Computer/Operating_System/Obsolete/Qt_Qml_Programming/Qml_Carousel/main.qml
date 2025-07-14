import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
//import QtQml 2.12


Control {
    property bool carousel_entered: false
    width: 640
    height: 480
    visible: true

    Rectangle {
        width: parent.width
        height: mousearea.height + 16 * 2
        anchors.horizontalCenter: parent.horizontalCenter
        color: "red"

        MouseArea {
            id: mousearea
            width: parent.width
            height: 225
            anchors.centerIn: parent
            hoverEnabled: true

            onPositionChanged: {
                console.debug('onHovered')
                carousel_entered = true
            }

            onExited: {
                console.debug('onExited')
                carousel_entered = false
            }

            Label {
                id: label_navigation_left
                visible: (carousel_entered === true) && (0 < swipeview_carousel.currentIndex)
                width: 16
                height: parent.height
                anchors.right: swipeview_carousel.left
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "<"

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.debug('<:onClicked')
                        if(0 <= swipeview_carousel.currentIndex - 1) {
                            swipeview_carousel.currentIndex = swipeview_carousel.currentIndex - 1
                        }
                    }
                }
            }

            SwipeView {
                id: swipeview_carousel
                width: parent.width - label_navigation_left.width - label_navigation_right.width
                height: parent.height
                anchors.horizontalCenter: parent.horizontalCenter
                clip: true
                spacing: 0

                Repeater {
                    model: 2

                    Row {
                        id: row_carousel
                        spacing: 10

                        Image {
                            horizontalAlignment: Image.AlignHCenter
                            verticalAlignment: Image.AlignVCenter
                            fillMode: Image.PreserveAspectFit
                            width: (swipeview_carousel.width - row_carousel.spacing) / 2
                            height: swipeview_carousel.height
                            source: "images/" + (index * 2 + 0) + ".jpg"

                            MouseArea {
                                anchors.fill: parent
                                propagateComposedEvents: true
                                onClicked: (mouse) => {
                                    console.debug('Image:onClicked')
                                    mouse.accepted = false
                                }
                            }
                        }

                        Image {
                            horizontalAlignment: Image.AlignHCenter
                            verticalAlignment: Image.AlignVCenter
                            fillMode: Image.PreserveAspectFit
                            width: (swipeview_carousel.width - row_carousel.spacing) / 2
                            height: swipeview_carousel.height
                            source: "images/" + (index * 2 + 1) + ".jpg"
                        }

                        // 应变方案
                        MouseArea {
                            width: parent.width
                            height: parent.height
                            hoverEnabled: true

                            onPositionChanged: {
                                console.debug('Row:onPositionChanged')
                                carousel_entered = true
                            }

                            onClicked: {
                                console.debug('Row:onClicked')
                            }
                        }
                    }
                }

                Timer {
                    id: timer_carousel
                    running: (swipeview_carousel.count > 1) && (carousel_entered === false)
                    interval: 2000
                    repeat: true

                    onTriggered: {
                        if(swipeview_carousel.currentIndex + 1 < swipeview_carousel.count) {
                            swipeview_carousel.currentIndex = swipeview_carousel.currentIndex + 1
                        } else {
                            swipeview_carousel.currentIndex = 0
                        }
                    }
                }
            }

            Label {
                id: label_navigation_right
                visible: (carousel_entered === true) && (swipeview_carousel.currentIndex < swipeview_carousel.count - 1)
                width: 16
                height: parent.height
                anchors.left: swipeview_carousel.right
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: ">"

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.debug('>:onClicked')
                        if(swipeview_carousel.currentIndex + 1 < swipeview_carousel.count) {
                            swipeview_carousel.currentIndex = swipeview_carousel.currentIndex + 1
                        }
                    }
                }
            }
        }
    }
}
