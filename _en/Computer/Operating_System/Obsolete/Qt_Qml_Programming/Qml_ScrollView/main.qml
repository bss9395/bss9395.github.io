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
    ScrollView {
        width: 200
        height: 200
        clip: true

        ListView {
            width: 200
            height: 200
            id: listview
            model: 20

            delegate: ItemDelegate {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Item " + index
            }
        }
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
    }

    ScrollView {
        width: 200
        height: 200
        clip: true

        Label {
            font.pixelSize: 224
            text: "ABC"
        }

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
    }


    ScrollView {
        id: scrollview
        width: 200
        height: 200
        contentWidth: rect.width
        contentHeight: rect.height
        clip: true

        Rectangle {
            id: rect
            width: 1000
            height: 1000
            color: "lightblue"

            Label {
                id: label
                text: "label"
            }
        }

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOn
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
    }
    }
}
