import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        anchors.fill: parent
        spacing: 10

        Button {
            text: "普通按钮"
        }

        Button {
            text: "flat按钮"
            flat: true
        }

        Button {
            text: "高亮按钮"
            highlighted: true
        }

        RoundButton {
            text: "圆角按钮"
            radius: 5
        }

        RoundButton {
            text: "圆形按钮"
            implicitWidth: 60
            implicitHeight: 60
            radius: width / 2
        }
    }
}
