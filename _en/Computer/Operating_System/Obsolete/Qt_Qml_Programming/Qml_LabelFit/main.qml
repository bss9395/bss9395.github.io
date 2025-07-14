import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    property var dpi:1
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button
        text: "button"

        onClicked: {
            console.debug(`button:onClicked`)
            var popup_prompt = component_prompt.createObject(mainWindow)
            popup_prompt.open()
        }
    }


    Component {
        id: component_prompt

        Popup {
            property var father     : undefined
            property var dpi        : mainWindow.dpi
            id: popup_prompt
            width: 24 * dpi + rectangle_content.width + 24 * dpi
            height: 24 * dpi + rectangle_content.height + 24 * dpi
            margins: 0 * dpi
            padding: 0 * dpi
            anchors.centerIn: Overlay.overlay
            closePolicy: Popup.NoAutoClose
            modal: true
            dim: false

            onClosed: {
                console.debug(`popup_prompt:onClosed`)
                popup_prompt.destroy()
            }

            // 主体内容
            RectangleFit {
                id: rectangle_content
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                // 销毁在前
                Rectangle {
                    property var name: "rectangle_wider"

                    onVisibleChanged: {
                        console.debug(`rectangle_wider:onVisibleChanged, visible = ${visible}`)
                    }

                    Component.onCompleted: {
                        console.debug(`rectangle_wider:onCompleted`)
                    }

                    Component.onDestruction: {
                        console.debug(`rectangle_wider:onDestruction`)
                    }

                    id: rectangle_wider
                    width: 200 * dpi
                    height: 100 * dpi
                    color: "red"
                }

                // 销毁在后
                LabelFit {
                    property var name: "label_confirm"

                    onVisibleChanged: {
                        console.debug(`label_confirm:onVisibleChanged, visible = ${visible}`)
                    }

                    Component.onCompleted: {
                        console.debug(`label_confirm:onCompleted`)
                    }

                    Component.onDestruction: {
                        console.debug(`label_confirm:onDestruction`)
                    }

                    id: label_confirm
                    width: 180 * dpi
                    height: 32 * dpi
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: rectangle_wider.bottom
                    anchors.topMargin: 12 * dpi
                    background: Rectangle {
                        radius: 40 * dpi
                        color: "#FF4399F3"
                    }
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12 * dpi
                    font.weight: Font.Normal
                    color: "#FFFFFFFF"
                    text: "确定"

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            console.debug(`label_confirm:onClicked`)
                            popup_prompt.close()
                        }
                    }
                }
            }
        }
    }
}
