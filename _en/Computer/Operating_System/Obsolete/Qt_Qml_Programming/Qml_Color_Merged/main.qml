import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    visible: true
    width: 1200
    height: 400
    title: qsTr("Hello World")


    Label {
        property var color_back: app.colorReal(rectangle_back.color_snap)
        id: label_back
        anchors.left: parent.left
        anchors.top: parent.top
        text: `Back: ${color_back}`
    }

    RectangleFit {
        id: rectanglefit_back
        anchors.left: parent.left
        anchors.top: label_back.bottom

        RectangleFit {
            id: rectanglefit_back_alpha
            anchors.left: parent.left
            anchors.top: parent.top

            Label {
                id: label_back_alpha
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `A ${rectangleslider_back_alpha.value}`
            }

            RectangleSlider {
                id: rectangleslider_back_alpha
                anchors.left: label_back_alpha.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            id: rectanglefit_back_red
            anchors.left: parent.left
            anchors.top: rectanglefit_back_alpha.bottom

            Label {
                id: label_back_red
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `R ${rectangleslider_back_red.value}`
            }

            RectangleSlider {
                id: rectangleslider_back_red
                anchors.left: label_back_red.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            id: rectanglefit_back_green
            anchors.left: parent.left
            anchors.top: rectanglefit_back_red.bottom

            Label {
                id: label_back_green
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `G ${rectangleslider_back_green.value}`
            }

            RectangleSlider {
                id: rectangleslider_back_green
                anchors.left: label_back_green.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            id: rectanglefit_back_blue
            anchors.left: parent.left
            anchors.top: rectanglefit_back_green.bottom

            Label {
                id: label_back_blue
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `R ${rectangleslider_back_blue.value}`
            }

            RectangleSlider {
                id: rectangleslider_back_blue
                anchors.left: label_back_blue.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }
    }

    Rectangle {
        property var color_snap: app.colorLinearize("#00000000", "#FFFFFFFF", rectangleslider_back_alpha.snap, rectangleslider_back_red.snap, rectangleslider_back_green.snap, rectangleslider_back_blue.snap)
        id: rectangle_back
        width: height
        anchors.left: rectanglefit_back.right
        anchors.top: rectanglefit_back.top
        anchors.bottom: rectanglefit_back.bottom
        border.width: 1
        border.color: "black"
        color: color_snap
    }

    Label {
        property var color_front: app.colorReal(rectangle_front.color_snap)
        id: label_front
        anchors.left: parent.left
        anchors.top: rectanglefit_back.bottom
        text: `Front: ${color_front}`
    }

    RectangleFit {
        id: rectanglefit_front
        anchors.left: parent.left
        anchors.top: label_front.bottom

        RectangleFit {
            id: rectanglefit_front_alpha
            anchors.left: parent.left
            anchors.top: parent.top

            Label {
                id: label_front_alpha
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `A ${rectangleslider_front_alpha.value}`
            }

            RectangleSlider {
                id: rectangleslider_front_alpha
                anchors.left: label_front_alpha.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            id: rectanglefit_front_red
            anchors.left: parent.left
            anchors.top: rectanglefit_front_alpha.bottom

            Label {
                id: label_front_red
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `R ${rectangleslider_front_red.value}`
            }

            RectangleSlider {
                id: rectangleslider_front_red
                anchors.left: label_front_red.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            id: rectanglefit_front_green
            anchors.left: parent.left
            anchors.top: rectanglefit_front_red.bottom

            Label {
                id: label_front_green
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `G ${rectangleslider_front_green.value}`
            }

            RectangleSlider {
                id: rectangleslider_front_green
                anchors.left: label_front_green.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }

        RectangleFit {
            id: rectanglefit_front_blue
            anchors.left: parent.left
            anchors.top: rectanglefit_front_green.bottom

            Label {
                id: label_front_blue
                width: 40
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                text: `B ${rectangleslider_front_blue.value}`
            }

            RectangleSlider {
                id: rectangleslider_front_blue
                anchors.left: label_front_blue.right
                anchors.verticalCenter: parent.verticalCenter
                angle: 0
                from: 0
                into: 255
                value: 127
                step: 1.0
            }
        }
    }

    Rectangle {
        property var color_snap: app.colorLinearize("#00000000", "#FFFFFFFF", rectangleslider_front_alpha.snap, rectangleslider_front_red.snap, rectangleslider_front_green.snap, rectangleslider_front_blue.snap)
        id: rectangle_front
        width: height
        anchors.left: rectanglefit_front.right
        anchors.top: rectanglefit_front.top
        anchors.bottom: rectanglefit_front.bottom
        border.width: 1
        border.color: "black"
        color: color_snap
    }

    Label {
        property var formula_alpha: `A_merged = A_front + A_back * (1 - A_front)`
        property var formula_color: `C_merged = C_front * A_front + C_back * A_back * (1 - A_front) = C_front * A_front + C_back * A_back - C_back * A_front * A_back`
        id:label_merged_equation
        anchors.left: label_merged.left
        anchors.bottom: label_merged.top
        text:`${formula_alpha}\n${formula_color}`
    }

    Label {
        property var color_merged: app.colorReal(rectangle_merged.color_merged)
        id: label_merged
        anchors.left: rectangle_merged.left
        anchors.bottom: rectangle_merged.top
        text: `Merged: ${color_merged}`
    }

    Rectangle {
        property var color_merged: app.colorMerge(rectangle_back.color_snap, rectangle_front.color_snap)
        id: rectangle_merged
        width: height
        anchors.left: rectangle_back.right
        anchors.leftMargin: 5
        anchors.top: rectangle_back.verticalCenter
        anchors.bottom: rectangle_front.verticalCenter
        border.width: 1
        border.color: "black"
        color: color_merged
    }
}
