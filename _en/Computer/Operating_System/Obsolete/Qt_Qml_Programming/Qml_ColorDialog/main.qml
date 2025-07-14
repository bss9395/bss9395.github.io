import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
// import QtQuick.Dialogs 1.2
import Qt.labs.platform 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    RowLayout {
        Button {
            text: "颜色对话框"

            onClicked: {
                colorDialog.open()
            }
        }

        Label {
            id: label
            color: colorDialog.currentColor
            text: "颜色展示"
        }

        ColorDialog {
            id: colorDialog
            currentColor: label.color
            options: colorDialog.showAlphaChannel

            onAccepted: {
                label.color = colorDialog.currentColor
            }
        }
    }
}
