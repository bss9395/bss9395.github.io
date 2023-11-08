
import QtQuick 2.12
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Rectangle {
    property real progress: 0.95
    width: 600
    height: 600
    // color: "red"

    Label {
        id: label_downloading
        width: 100
        height: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "下载中"
        background: Rectangle {
            id: rectangle
            width: parent.width
            height: parent.height
            border.color: "#4399F3"
            border.width: 1
            radius: 16
            layer.enabled: true
            layer.effect: OpacityMask {
                maskSource: Rectangle {
                    width: rectangle.width
                    height: rectangle.height
                    radius: rectangle.radius
                    color: "#FFFFFFFF"
                }
            }
            Rectangle {
                width: parent.width * progress
                height: parent.height
                radius: 0
                color: "#4399F3"
            }
        }
    }
}
