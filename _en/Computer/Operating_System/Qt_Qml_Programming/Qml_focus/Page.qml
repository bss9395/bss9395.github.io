import QtQuick 2.0

Item {
    Rectangle {
        width: 50
        height: 50
        color: "red"
        focus: true

        Keys.onPressed: (event) => {
            console.log("Loader onPressed: " + event.text)
            event.accepted = false;
        }
    }
}
