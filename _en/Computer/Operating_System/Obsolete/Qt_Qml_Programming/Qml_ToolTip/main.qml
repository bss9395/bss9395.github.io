import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 100

        Label {
            property bool hovered: false
            id: label1
            width: 80
            height: 32
            background: Rectangle {
                radius: 8
                border.width: 1
                border.color: "#FF4399F3"
                color: "#FFFFFFFF"
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            font.weight: Font.Normal
            color: "#FF4399F3"
            text: "确定"

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                onPositionChanged: {
                    // console.debug(`label1:onPositionChanged`)
                    label1.hovered = true
                }

                onExited: {
                    console.debug(`label1:onExited`)
                    label1.hovered = false
                }
            }

            ToolTip.visible: hovered === true
            ToolTip.text: "label1"
            ToolTip.delay: 0
            ToolTip.timeout: 0
        }

        Label {
            property bool hovered: false
            id: label2
            width: 80
            height: 32
            background: Rectangle {
                radius: 8
                border.width: 1
                border.color: "#FF4399F3"
                color: "#FFFFFFFF"
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            font.weight: Font.Normal
            color: "#FF4399F3"
            text: "确定"

            ToolTip {
                id: tooltip
                visible: label2.hovered === true
                delay: 0
                timeout: 0
                background: Rectangle {
                    radius: 8
                    border.width: 1
                    border.color: "#FF4399F3"
                    color: "#FFFFFFFF"
                }
                contentItem: Label {
                    font.pixelSize: 12
                    font.weight: Font.Normal
                    color: "#FF666666"
                    text: "label2"
                }
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true

                onPositionChanged: {
                    // console.debug(`label2:onPositionChanged`)
                    label2.hovered = true
                }

                onExited: {
                    console.debug(`label2:onExited`)
                    label2.hovered = false
                }

                onClicked: {
                    console.debug(`label2:onClicked`)
                    dialog.open()
                }
            }
        }
    }

    Dialog {
        id: dialog
        parent: Overlay.overlay
        width: 300
        height: 300
        anchors.centerIn: parent
        modal: true
        title: "Dialog"
        standardButtons: Dialog.Ok | Dialog.Cancel

        Label {
            anchors.centerIn: parent
            text: "关闭对话框?"
        }

        onRejected: {
            console.debug("dialog:onRejected")
        }

        onAccepted: {
            window.close()
        }
    }
}
