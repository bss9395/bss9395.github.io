import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ScrollView {
        width: 200
        height: 200
        x: 10
        y: 10

        Label {
            font.pixelSize: 224
            text: "ABC"
        }
    }

    ScrollView {
        width: 200
        height: 200
        x: 240
        y: 10

        ListView {
            id: listview
            model: 20

            delegate: ItemDelegate {
                text: "Item " + index
            }
        }

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
    }
}
