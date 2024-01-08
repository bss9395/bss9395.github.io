import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    property var dpi: 1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        property var displayText: "完成"
        id: label_done
        width: parent.width
        height: {
            var fitHeight = implicitHeight - (contentHeight / lineCount - fontmetrics.height)
            return (image_done.y + image_done.height < fitHeight) ? (image_done.y + image_done.height) : fitHeight
        }
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 0 * dpi
        leftPadding: image_done.anchors.leftMargin + image_done.width + fontmetrics.height / 5
        topPadding: {
            var offset = image_done.height / 2 - fontmetrics.height / 2
            return (0 <= offset) ? offset : 0
        }
        font.pixelSize: 12 * dpi
        font.weight: Text.Normal
        wrapMode: Text.WrapAnywhere
        lineHeightMode: Text.ProportionalHeight
        lineHeight: 1.2
        color: "#FF222222"
        text: label_done.displayText

        // 图标
        Image {
            id: image_done
            width: 20 * dpi
            height: 20 * dpi
            anchors.left: parent.left
            anchors.verticalCenter: parent.top
            anchors.verticalCenterOffset: parent.topPadding + fontmetrics.height / 2
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/icon_done.png"
        }

        FontMetrics {
            id: fontmetrics
            font: label_done.font
        }

        Rectangle {
            anchors.fill: parent
            color: "#60FF0000"
        }
    }
}
