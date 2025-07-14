import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
// import QtQuick.Dialogs 1.2
import Qt.labs.platform 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        text: "消息对话框"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                messageDialog.open()
            }
        }
    }

    MessageDialog {
        id: messageDialog
        modality: Qt.WindowModal
        title: "title"
        // icon: StandardIcon.Information
        text: "text"
        informativeText: "informativeText"
        // detailedText: "detailedText"
        // standardButtons: StandardButton.No | StandardButton.Yes | StandardButton.Ok

        onAccepted: {
            console.debug('onAccepted')
        }
    }
}
