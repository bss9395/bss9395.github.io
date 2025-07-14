import QtQuick 2.12
import QtQuick.Controls 2.12

Label {
    signal checkboxClicked(var event)
    signal checkboxReturnPressed(var event)
    property alias checkboxChecked         : checkbox.checked
    property alias checkboxActiveFocusOnTab: checkbox.activeFocusOnTab
    property alias checkboxFocus           : checkbox.focus
    property var   checkboxBorderColor     : "#FF000000"
    id: label
    width: implicitWidth
    height: implicitHeight - (contentHeight / lineCount - fontmetrics.height)
    leftPadding: checkbox.anchors.leftMargin + checkbox.width + checkbox.width / 4
    topPadding: {
        var offset = checkbox.height / 2 - fontmetrics.height / 2
        return (0 <= offset) ? offset : 0
    }

    CheckBox {
        id: checkbox
        width: fontmetrics.height
        height: fontmetrics.height
        anchors.left: parent.left
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: parent.topPadding + fontmetrics.height / 2
        indicator: Rectangle {
            width: parent.width
            height: parent.height
            border.width: 1 * dpi
            border.color: label.checkboxBorderColor

            Canvas {
                visible: checkbox.checked
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

        onCheckedChanged: {
            console.debug(`checkbox:onCheckedChanged, checked = ${checked}`)
        }

        onClicked: (event) => {
            console.debug(`checkbox:onClicked`)
            label.checkboxClicked(event)
        }

        Keys.onReturnPressed: (event) => {
            console.debug(`checkbox:onReturnPressed`)
            label.checkboxReturnPressed(event)
        }
    }

    FontMetrics {
        id: fontmetrics
        font: label.font
    }
}
