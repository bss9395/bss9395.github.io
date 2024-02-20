import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        ScrollView {
            id: scrollview
            width: 100
            height: 60
            background: Rectangle {
                radius: 6
                border.width: 1
                border.color: "#FFE6E6E6"
                color: "#FFFFFFFF"
            }
            contentWidth: textarea.contentWidth
            contentHeight: textarea.contentHeight
            clip: true

            ScrollBar.vertical.policy: ScrollBar.AsNeeded
			ScrollBar.horizontal.policy: ScrollBar.AsNeeded

            TextArea {
                property var countLast: 0
                property var countMaxi: 100
                id: textarea
                font.pixelSize: 12
                font.weight: Font.Normal
                color: "#FF666666"
                text: ""
                wrapMode: Text.WrapAnywhere
                selectByMouse: true

                onTextChanged: {
                    console.debug(`textarea:onTextChanged`)
                    // 注意textarea.length <= textarea.text.length
                    if((textarea.length <= textarea.countMaxi) === false) {
                        textarea.text = textarea.text.slice(0, textarea.countLast)
                        textarea.cursorPosition = textarea.text.length
                    }
                    textarea.countLast = textarea.text.length
                }
            }
        }

        Label {
            id: label
            text: `${textarea.length}/${textarea.countMaxi}`
        }
    }
}
