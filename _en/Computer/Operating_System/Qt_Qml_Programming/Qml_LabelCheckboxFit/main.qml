import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    property var dpi: 1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        TextField {
            id: textfield0
            text: "textfield0"
        }

        // 记住账号
        LabelCheckboxFit {
            property var checkedCached: false
            id: label_remember
            font.pixelSize: 12 * dpi
            font.weight: Font.Normal
            checkboxBorderColor: "#FFD9D9D9"
            color: "#FF666666"
            text: "记住账号"
            checkboxActiveFocusOnTab: true

            onCheckboxClicked: {
                console.debug(`label_remember:onCheckboxClicked, label_remember.checkedCached = ${label_remember.checkedCached}`)
                label_remember.checkboxFocus   = true
                label_remember.checkedCached   = !label_remember.checkedCached
                label_remember.checkboxChecked =  label_remember.checkedCached
            }

            onCheckboxReturnPressed: {
                console.debug(`label_remember:onReturnPressed`)
                label_remember.checkedCached   = !label_remember.checkedCached
                label_remember.checkboxChecked =  label_remember.checkedCached
            }

            Component.onCompleted: {
                console.debug(`label_remember:onCompleted, checkedCached = ${checkedCached}`)
                label_remember.checkedCached = label_remember.checkboxChecked
            }
        }

        TextField {
            id: textfield1
            text: "textfield1"
        }
    }
}
