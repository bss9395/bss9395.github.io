import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import Modu 1.0

Window {
    property real dpi: 1
    visible: true
    width: 200
    height: 200

    Label {
        font.pixelSize: 14
        font.weight: Font.Medium
        font.family: Config.font2
        wrapMode: Text.WrapAnywhere
        lineHeightMode: Text.ProportionalHeight
        lineHeight: 1.2
        color: "#FF000000"
        text: "手机号注册"

        Component.onCompleted: {
            console.debug(`height = ${height}`)
        }
    }
}
