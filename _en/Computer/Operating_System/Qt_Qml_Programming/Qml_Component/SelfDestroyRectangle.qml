import QtQuick 2.0

Rectangle {
    id: rectangle
    width: 100
    height: 80
    color: "red"

    NumberAnimation on opacity {
        to: 0
        duration: 1000

        onRunningChanged: {
            if(!running) {
                console.log("Destroying...")
                rectangle.destroy()
            }
        }
    }
}
