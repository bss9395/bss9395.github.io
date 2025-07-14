import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: 200
        height: 200
        color: "green"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                var fileurl = "file:///home/brilliant/documents/filename.txt"
                var fileinfo = app.fileinfo(fileurl)
                console.debug(`fileinfo[0] = ${fileinfo[0]}, fileinfo[1] = ${fileinfo[1]}, fileinfo[2] = ${fileinfo[2]}`)

                app.filepath(fileinfo)
                app.filename(fileinfo)
            }
        }
    }
}
