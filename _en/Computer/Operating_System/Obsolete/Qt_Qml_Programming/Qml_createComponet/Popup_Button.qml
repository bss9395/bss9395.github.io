import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
import QtQml 2.12

Popup {
    property var father: undefined
    id: popup
    anchors.centerIn: Overlay.overlay
    closePolicy: Popup.NoAutoClose
    modal: false
    dim: false
    padding: 0
    margins: 0
    background: Rectangle {
        color: "#FFFFFFFF"
        radius: 8
        layer.enabled: true
        layer.effect: DropShadow {
            horizontalOffset: 0
            verticalOffset: 0
            radius: 8
            color: "#80000000"
            samples: 24
            cached: true
        }
    }

    Column {
        id: column

        Rectangle {
            width: 100
            height: 40
            radius: 16
            color: "blue"
        }

        Button {
            text: "关闭"

            onClicked: {
                popup.father.color = "yellow"
                popup.close()
            }
        }
    }

    Component.onCompleted: {
        popup.open()
    }
}
