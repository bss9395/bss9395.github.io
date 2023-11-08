import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    visible: true
    width: 640
    height: 480

    Column {
        anchors.centerIn: parent
        spacing: 15

        Rectangle_FocusScope {
            color: "lightblue"

            Component.onCompleted: {
                console.log('1')
            }
        }

        Rectangle_FocusScope {
            color: "palegreen"
            focus: true

            Component.onCompleted: {
                console.debug('2')
            }
        }

        Rectangle_FocusScope {
            color: "red"

            Component.onCompleted: {
                console.debug('3')
            }
        }
    }
}
