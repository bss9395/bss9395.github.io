import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: rectangle
    width: parent.width
    height: 40
    color: "red"

    MouseArea {
        property var mouse_pressed: ({})
        id: mousearea
        anchors.fill: parent
        hoverEnabled: false  // note: close hover feature

        onPressed: (mouse) => {
            console.debug('mousearea:onPressed')
            mousearea.mouse_pressed.x = cursorPos.pos().x - window.x
            mousearea.mouse_pressed.y = cursorPos.pos().y - window.y
            console.debug(`mousearea.mouse_pressed = (${mousearea.mouse_pressed.x}, ${mousearea.mouse_pressed.y})`)
        }

        onClicked: {
            console.debug('mousearea:onClicked')
        }



        onPositionChanged: (mouse) => {
            console.debug('mousearea:onPositionChanged')
            console.debug(`hoverEnabled = ${hoverEnabled}, cursorPos.pos() = (${cursorPos.pos().x}, ${cursorPos.pos().y}), mousearea.mouse_pressed = (${mousearea.mouse_pressed.x}, ${mousearea.mouse_pressed.y})`)
            window.x = cursorPos.pos().x - mousearea.mouse_pressed.x
            window.y = cursorPos.pos().y - mousearea.mouse_pressed.y
        }

        onHoveredChanged: {
            console.debug('mousearea:onHoveredChanged')
        }

        onEntered: {
            console.debug('mousearea:onEntered')
        }

        onExited: {
            console.debug('mousearea:onExited')
        }
    }

    Button {
        id: button_minimize
        width: 40
        height: parent.height
        anchors.right: text_close.left
        text: "-"
        hoverEnabled: true

        onPressed: {
            console.debug('button_minimize:onPressed')
        }

        onClicked: {
            console.debug('button_minimize:onClicked')
        }

        onHoveredChanged: {
            console.debug('button_minimize:onHoveredChanged')
        }
    }

    Text {
        id: text_close
        width: height
        height: parent.height
        anchors.right: parent.right
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "×"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onPressed: {
                console.debug('text_close:onPressed')
            }

            onClicked: {
                console.debug('text_close:onClicked')
            }



            onPositionChanged: {
                console.debug('text_close:onPositionChanged')
            }

            onHoveredChanged: {
                console.debug('text_close:onHoveredChanged')
            }

            onEntered: {
                console.debug('text_close:onEntered')
            }

            onExited: {
                console.debug('text_close:onExited')
            }
        }
    }
}
