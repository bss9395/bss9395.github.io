import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window_root
    property bool closed: false

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Window {
        id: window_dialog
        width: 300
        height: 200
        flags: Qt.Dialog
        modality: Qt.WindowModal

        Label {
            text: "确定要退出吗？"
            x: 120
            y: 50
        }

        Row {
            spacing: 10
            x: 120
            y: 80

            Button {
                text: "确定"

                onClicked: {
                    window_dialog.close()
                    window_root.closed = true
                    window_root.close()
                }
            }

            Button {
                text: "取消"

                onClicked: {
                    window_dialog.close()
                    window_root.closed = false
                }
            }
        }
    }

    onClosing: (event) => {
        if(closed == true) {
            event.accepted = true
        } else {
            event.accepted = false
            window_dialog.show()
        }
    }
}
