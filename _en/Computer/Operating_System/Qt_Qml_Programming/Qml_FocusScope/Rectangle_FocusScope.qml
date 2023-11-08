import QtQuick 2.0

FocusScope {
    id: focusscope
    x: rectangle.x
    y: rectangle.y
    width: rectangle.width
    height: rectangle.height

    property alias color: rectangle.color

    Rectangle {
        id: rectangle
        width: 175
        height: 25
        radius: 10
        antialiasing: true
        focus: true

        Text {
            id: text_label
            anchors.centerIn: parent
        }

        Keys.onPressed: (event) => {
            if(event.key === Qt.Key_A) {
                text_label.text = 'Key A pressed'
            } else if(event.key === Qt.Key_B) {
                text_label.text = 'Key B pressed'
            } else if(event.key === Qt.Key_C) {
                text_label.text = 'Key C pressed'
            }
        }
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            focusscope.focus = true
        }
    }
}
