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
            text: "目录对话框"

            onClicked: {
                folderDialog.open()
            }
        }

        Label {
            text: folderDialog.currentFolder
            // text: folderDialog.folder
        }

        FolderDialog {
            id: folderDialog
            currentFolder: StandardPaths.standardLocations(StandardPaths.ApplicationsLocation)[0]
            // currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]
        }
    }
}
