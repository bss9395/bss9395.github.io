import QtQuick.Window 2.12
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        Rectangle {
            width: 200
            height: 200
            radius: 40
            border.width: 1
            border.color: "red"
            color: "#00FFFFFF"
        }

        ShapeRounded {
            width: 200
            height: 200
            radiusCorner: [40, 40, 40, 40]
            borderWidth: 1
            borderColor: "red"
            borderStyle: "SolidLine"
            borderPattern: [1.0, 3.0]
            color: "#00FFFFFF"
        }

        ShapeRoundedCorner {
            width: 200
            height: 200
            radiusCorner: [40, 40, 40, 40]
            borderWidth: 1
            borderColor: "red"
            borderStyle: "SolidLine"
            borderPattern: [1.0, 3.0]
            color: "#00FFFFFF"
        }
    }
}
