import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0         // Qt5
// import Qt5Compat.GraphicalEffects  // Qt6

Item {
    width: 600
    height: 800

    Grid {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin:10
        columnSpacing: 40
        rowSpacing: 40
        columns: 2

        DropShadow {
            width: 200
            height: 200
            horizontalOffset: 0
            verticalOffset: 0
            radius: 24
            samples: 24
            color: "#80000000"
            cached: true  // 注意不要使用cached，效果不好
            source: Rectangle {
                width: 200
                height: 200
                color: "#FFFFFF"
                radius: 8
            }
        }

        Rectangle {
            id: rectangle
            width: 200
            height: 200
            color: "#FFFFFF"
            radius: 8
            layer.enabled: true
            layer.effect: DropShadow {
                horizontalOffset: 0
                verticalOffset: 0
                radius: 24
                samples: 24
                color: "#80000000"
                cached: false  // 注意不要使用cached，效果不好
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('onClicked')
                }
            }
        }

        Image {
            id: image_dropshadow
            width: 200
            height: 200
            source: "images/down.png"
            smooth: true
            layer.enabled: true
            layer.effect: DropShadow {
                width: image_dropshadow.width
                height: image_dropshadow.height
                horizontalOffset: 5
                verticalOffset: 5
                radius: 10
                samples: 24
                color: "#50000000"
            }
        }

        Rectangle {
            id: rectangle_innershadow
            width: 200
            height: 200
            radius: 8
            layer.enabled: true
            layer.effect: InnerShadow {
                width: rectangle_innershadow.width
                height: rectangle_innershadow.height
                horizontalOffset: 0
                verticalOffset: 0
                radius: 24
                samples: 24
                color: "#80000000"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('onClicked')
                }
            }
        }

        Image {
            id: image_innershadow
            width: 200
            height: 200
            source: "images/down.png"
            smooth: true
            layer.enabled: true
            layer.effect: InnerShadow {
                width: image_innershadow.width
                height: image_innershadow.height
                horizontalOffset: 5
                verticalOffset: 5
                radius: 24
                samples: 24
                color: "#80000000"
            }
        }
    }
}

