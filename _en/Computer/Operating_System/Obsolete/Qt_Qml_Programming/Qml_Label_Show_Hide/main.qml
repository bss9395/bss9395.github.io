import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    property real dpi: 1.0
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        Column {
            Label_Show_Hide_Count {
                width: 140
                font.pixelSize: 12
                font.bold: false
                lineHeightMode: Text.ProportionalHeight
                lineHeight: 1.4
                wrapMode: Text.WrapAnywhere
                color: "#666666"
                text: "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
                maximumCount: 25
            }

            Label {
                text: "abc"
            }
        }

        Column {
            Label_Show_Hide_Line {
                width: 140
                font.pixelSize: 12
                font.bold: false
                lineHeightMode: Text.ProportionalHeight
                lineHeight: 1.4
                wrapMode: Text.WrapAnywhere
                color: "#666666"
                text: "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
                maximumLine: 3
            }

            Label {
                text: "def"
            }
        }
    }
}
