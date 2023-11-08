import QtQuick 2.0

Rectangle {
    default property alias items: column.children
    property alias title: title.text

    Text {
        id: title
    }

    Column {
        id: column
        spacing: 10
        anchors.top: title.bottom
    }
}
