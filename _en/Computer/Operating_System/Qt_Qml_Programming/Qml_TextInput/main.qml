import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    visible: true
    width: 640
    height: 480

    Rectangle {
        id: rectangle_intValidator
        width: textinput_intValidator.contentWidth < 100 ? 100 : textinput_intValidator.contentWidth
        height: textinput_intValidator.contentHeight
        color: "lightblue"
        border.color: "blue"

        TextInput {
            id: textinput_intValidator
            anchors.fill: parent
            focus: true
            validator: IntValidator {
                bottom: 0
                top: 100
            }
            onEditingFinished: {
                text_intvalidator.text = text;
            }
        }
    }

    Text {
        id: text_intvalidator
        anchors.top: rectangle_intValidator.bottom
        color: "red"
    }

    Rectangle {
        id: rectangle_inputmask
        anchors.top: text_intvalidator.bottom
        width: textinput_inputMask.contentWidth
        height: textinput_inputMask.contentHeight
        color: "lightgrey"
        border.color: "grey"

        TextInput {
            id: textinput_inputMask
            font.pointSize: 15
            focus: true
            inputMask: ">AA_9_a"  // >表示全部大写字母

            onEditingFinished: {
                text_inputmask.text = text
            }
        }
    }

    Text {
        id: text_inputmask
        anchors.top: rectangle_inputmask.bottom
        color: "red"
    }

    Rectangle {
        id: rectangle_echomode
        anchors.top: text_inputmask.bottom
        width: 100
        height: textinput_echomode.contentHeight
        color: "lightgreen"
        border.color: "green"

        TextInput {
            id: textinput_echomode
            anchors.fill: parent
            focus: true
            echoMode: TextInput.PasswordEchoOnEdit

            onAccepted: {
                textinput_echomode.focus = false
                console.log(text)
            }
        }
    }

    Rectangle {
        id: rectangle_ontextedited
        anchors.top: rectangle_echomode.bottom
        width: 100
        height: textinput_ontextedited.contentHeight
        color: "lightyellow"
        border.color: "yellow"

        TextInput {
            id: textinput_ontextedited
            anchors.fill: parent
            focus: true

            onTextEdited: {
                console.log(text)
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                textinput_ontextedited.focus = true
                textinput_ontextedited.text = "hello"
            }
        }
    }

    Rectangle {
        id: rectangle_selectbymouse
        anchors.top: rectangle_ontextedited.bottom
        width: 100
        height: text_selectbymouse.contentHeight
        color: "lightgrey"
        border.color: "grey"

        TextInput {
            id: text_selectbymouse
            anchors.fill: parent
            text: "hello, world!"
            selectByMouse: true
            mouseSelectionMode: TextInput.SelectWords
            selectedTextColor: "red"
            selectionColor: "green"

            onAccepted: {
                console.log("start:end=" + selectionStart + ":" + selectionEnd + ", " + selectedText.toString())
                cut()
            }
        }
    }
}
