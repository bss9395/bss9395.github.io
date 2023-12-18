import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480


    Label {
        id: label
        leftPadding: checkbox.width + checkbox.width / 4
        text: "checkbox"

        CheckBox {
            id: checkbox
            width: 14
            height: 14
            anchors.verticalCenter: parent.verticalCenter

            indicator: Rectangle {
                width: parent.width
                height: parent.height
                border.width: 1
                border.color: "#FF000000"

                Canvas {
                    visible: parent.parent.checked
                    anchors.fill: parent

                    onPaint: {
                        var ctx = getContext("2d")
                        ctx.beginPath()
                        ctx.moveTo(width / 5 * 1, height / 4 * 2)
                        ctx.lineTo(width / 5 * 2, height / 4 * 3)
                        ctx.lineTo(width / 5 * 4, height / 4 * 1)
                        ctx.lineWidth = width / 10
                        ctx.strokeStyle = "#FF000000"
                        ctx.stroke()
                    }
                }
            }
        }
    }
}
