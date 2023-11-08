import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    ComboBox {
        id: combobox
        editable: true
        model: ListModel {
            ListElement {
                atext: "Banana"
            }

            ListElement {
                atext: "Apple"
            }

            ListElement {
                atext: "Coconut"
            }
        }

        // model: ["Banana", "Apple", "Coconut"]

        onAccepted: {
            console.debug(combobox.currentIndex, combobox.currentText)
            if(find(combobox.editText) === -1) {
                combobox.model.append({ text: combobox.editText })
            }
        }

        onCurrentIndexChanged: {
            console.debug(combobox.currentIndex)
        }

        onCurrentTextChanged: {
            console.debug(combobox.currentText)
        }
    }
}
