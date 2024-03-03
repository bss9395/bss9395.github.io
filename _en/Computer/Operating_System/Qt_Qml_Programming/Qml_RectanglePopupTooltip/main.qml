import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        width: 320
        height: 240
        x: (window.width  - width) / 2
        y: (window.height - height) / 2
        color: "#FF00FF00"
        clip: false


        RectanglePopupTooltip {
            id: rectanglepopuptooltip
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.bottom
            orientation: enum_left_top
            heightPeak : 10
            offsetPeak: 20
            offsetInner: 0
            widthLabelMaxi: 150
            radius: 10
            tooltip: "你好，世界！你好，世界！你好，世界！你好，世界！你好，世界！"
        }
    }
}
