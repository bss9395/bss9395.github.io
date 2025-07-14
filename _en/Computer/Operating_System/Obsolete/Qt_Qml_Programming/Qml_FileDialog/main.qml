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

    ColumnLayout {
        spacing: 0

        Button {
            text: "选择图片"

            onClicked: {
                fileDialog.open()
            }
        }

        Image {
            Layout.preferredWidth: width
            Layout.preferredHeight: height
            id: image
            width: 100
            height: 100
            fillMode: Image.PreserveAspectCrop
            clip: true
        }

        FileDialog {
            id: fileDialog
            nameFilters: ["Image Files (*.png *.jpg)"]
            // folder: StandardPaths.writableLocation(StandardPaths.PicturesLocation)
            folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
            acceptLabel: "打开目录"

            onCurrentFileChanged: {
                console.debug(`${fileDialog.currentFile}`)  // bug，滞留在上一次的选择
            }

            onAccepted: {
                // console.debug(`${fileDialog.currentFile}`)
                // console.debug(`${fileDialog.file}`)

                image.source = fileDialog.file
            }
        }
    }
}
