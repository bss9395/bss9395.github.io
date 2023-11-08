import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    Text {
        id: text_time
        text: Date().toString()
    }

    Timer {
        running: true
        repeat: true
        interval: 1000

        onTriggered: {
            text_time.text = Date().toString()
        }
    }
}
