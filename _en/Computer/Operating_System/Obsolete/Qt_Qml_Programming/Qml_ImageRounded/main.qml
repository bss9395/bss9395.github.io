import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    property var dpi: 1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ImageRounded {
        id: imagerounded_thumbnail
        width: 80 * dpi
        height: 80 * dpi
        radius: width / 2
        borderWidth: 1 * dpi
        borderColor: "#FFE6E6E6"
//        borderColor: "#FF000000"
        borderStyle: "SolidLine"
        fillMode: Image.PreserveAspectFit
        imageSource: "qrc:/images/avatar_greatwall.png"
    }
}
