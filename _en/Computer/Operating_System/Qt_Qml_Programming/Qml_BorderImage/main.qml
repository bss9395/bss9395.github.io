import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 180
    height: 180
    title: qsTr("Hello World")

    BorderImage {
        id: borderImage
        width: parent.width
        height: parent.height
        border.left: 30
        border.right: 30
        border.top: 30
        border.bottom: 30
        horizontalTileMode: BorderImage.Repeat
        verticalTileMode: BorderImage.Round
        source: "qrc:/images/colors.png"
    }
}
