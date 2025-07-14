import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        TextField {
            id: textfield1
            placeholderText: "请输入密码"

            onEditingFinished: {
                console.debug(`textfield1:onEditingFinished`)
            }
        }
        TextField {
            id: textfield2
            placeholderText: "请输入密码"

            onEditingFinished: {
                console.debug(`textfield2:onEditingFinished`)
            }
        }
        Image {
            id: image
            width: 80
            height: 32
            source: activeFocus === true ? "qrc:/images/icon_show.png" : "qrc:/images/icon_hide.png"
            activeFocusOnTab: true

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    image.focus = true

                    console.debug(`image:onClicked`)

                }
            }
        }

        Label {
            id: label
            width: 80
            height: 32
            text: "abc"
            background: Rectangle {
                color: label.activeFocus === true ? "#FF00FF00" : "#FFFF0000"
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            activeFocusOnTab: true

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug(`label:onClicked`)
                    label.focus = true
                }
            }

            Keys.onEnterPressed: {   // Enter键触发returnPressed
                console.debug(`label:onEnterPressed`)
            }
            Keys.onReturnPressed: {  // Enter键触发returnPressed
                console.debug(`label:onReturnPressed`)
            }
            Keys.onSpacePressed: {
                console.debug(`label:onSpacePressed`)
            }
        }
        Button {
            id: button
            text: "button"

            onClicked: {
                console.debug(`button:onClicked`)
            }

            Keys.onReturnPressed: {
                console.debug(`button:onReturnPressed`)
            }
        }
    }
}
