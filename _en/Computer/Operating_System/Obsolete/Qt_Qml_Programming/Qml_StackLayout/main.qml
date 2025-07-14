import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

Item {
    width: 640
    height: 480

    StackLayout {
        id: stacklayout
        anchors.fill: parent
        currentIndex: 1

        Rectangle {
            color: "teal"
        }

        Rectangle {
            color: "plum"
        }
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            if(stacklayout.currentIndex == 0) {
                stacklayout.currentIndex = 1
            } else if(stacklayout.currentIndex == 1) {
                stacklayout.currentIndex = 0
            }
        }
    }
}
