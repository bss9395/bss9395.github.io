import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    Dial {
        id: dial
        from: 1
        to: 10
        stepSize: 1
        wrap: false
    }

    Label {
        anchors.top: dial.bottom
        text: dial.value
    }
}
