import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    RowLayout {
        Button {
            text: "字体对话框"

            onClicked: fontDialog.open()
        }

        Label {
            id: label
            text: "字体展示"
            // font: fontDialog.font
            font: fontDialog.currentFont
        }

        FontDialog {
            id: fontDialog

            onAccepted: {
                console.debug(`fontDialog.font = ${fontDialog.font}`)
                // label.font = fontDialog.font
            }

            onFontChanged: {
                console.debug(`onFontChanged = ${fontDialog.font}`)
            }

            onCurrentFontChanged: {
                console.debug(`onCurrentFontChanged = ${fontDialog.currentFont}`)
            }
        }
    }
}
