import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        spacing: 20

        CheckBox {
            text: "First"
        }

        Button {
            text: "Button"
        }

        BusyIndicator {
            running: true
        }

        ProgressBar {
            value: 0.5
        }

        Dial {
            value: 0.5
        }
    }
}
