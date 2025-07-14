import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12

Popup {
    property var father
    id: popup
    anchors.centerIn: Overlay.overlay
    modal: true
    closePolicy: Popup.CloseOnPressOutside
    dim: false
    width: 100
    padding: 0
    margins: 0

    Column {
        Rectangle {
            width: 100
            height: 40
            radius: 16
            color: "red"
        }

        Button {
            text: "关闭"
            onClicked: {
                popup.father.color = "red"
                popup.close()
            }
        }
    }

    Component.onCompleted: {
        popup.open()
        console.debug(parent.width)
    }
}


