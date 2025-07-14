import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        RectangleFit {
            Label {
                id: label_alpha
                width: 40
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                font.pixelSize: 14
                text: `A ${rectangleslider_alpha.value}`
                clip: true
            }

            RectangleSlider {
                id: rectangleslider_alpha
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: label_alpha.bottom
                angle: -90
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            Label {
                id: label_red
                width: 40
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                font.pixelSize: 14
                text: `R ${rectangleslider_red.value}`
            }

            RectangleSlider {
                id: rectangleslider_red
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: label_red.bottom
                angle: -90
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            Label {
                id: label_green
                width: 40
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                font.pixelSize: 14
                text: `G ${rectangleslider_green.value}`
            }

            RectangleSlider {
                id: rectangleslider_green
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: label_green.bottom
                angle: -90
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            Label {
                id: label_blue
                width: 40
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                font.pixelSize: 14
                text: `B ${rectangleslider_blue.value}`
            }

            RectangleSlider {
                id: rectangleslider_blue
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: label_blue.bottom
                angle: -90
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            Label {
                id: label_color
                width: 40
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                font.pixelSize: 14
                text: "ARGB"
            }

            TextField {
                id: textfield_color
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: label_color.bottom
                font.pixelSize: 14
                text: `${rectangle_color.color_snap}`
                selectByMouse: true
            }

            Rectangle {
                property var color_snap: app.colorLinearize("#00000000", "#FFFFFFFF", rectangleslider_alpha.snap, rectangleslider_red.snap, rectangleslider_green.snap, rectangleslider_blue.snap)
                id: rectangle_color
                width: 100
                height: 100
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: textfield_color.bottom
                border.width: 1
                border.color: "black"
                color: color_snap
            }
        }
    }
}
