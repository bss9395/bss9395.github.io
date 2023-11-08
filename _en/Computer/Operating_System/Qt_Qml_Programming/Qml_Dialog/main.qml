import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button
        text: "Button"

//        ToolTip.visible: hovered
//        ToolTip.delay: 500
//        ToolTip.timeout: 1000
//        ToolTip.text: "打开对话框"

        ToolTip {
            visible: button.hovered
            delay: 500
            timeout: 1000
            text: "打开对话框"
        }

        Dialog {
            id: dialog
            width: 300
            height: 200
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            parent: Overlay.overlay
            dim: false
            modal: true
            standardButtons: Dialog.Ok | Dialog.Cancel

            Label {
                anchors.centerIn: parent
                text: "关闭对话框?"
            }

            onAccepted: {
                ApplicationWindow.window.close()
            }

            onRejected: {
                console.debug("Cancel")
            }
        }

        onClicked: {
            dialog.open()
        }
    }
}
