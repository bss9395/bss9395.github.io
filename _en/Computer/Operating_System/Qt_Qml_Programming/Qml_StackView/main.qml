import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar {
        RowLayout {
            anchors.fill: parent

            ToolButton {
                text: "Push"

                onClicked: {
                    stack.push(rectangle_1, { color: "red" }, rectangle_2, { color: "green" }, rectangle_3, { color: "blue" })
                    console.debug("stack.depth = ", stack.depth)
                }
            }

            ToolButton {
                text: "Pop"

                onClicked: {
                    stack.pop()
                    console.debug("stack.depth = ", stack.depth)
                }
            }

            ToolButton {
                text: "Replace"

                onClicked: {
                    stack.replace(rectangle_2, [rectangle_1, rectangle_2, rectangle_3])
                    console.debug("stack.depth = ", stack.depth)
                }
            }

            ToolButton {
                text: "Find"

                onClicked: {
                    stack.find(function (item, index) {
                        console.debug("item.text = ", item.text, ", index = ", index)
                        // return item === rectangle_3
                        return null;
                    })
                }
            }

            ToolButton {
                text: "Clear"

                onClicked: {
                    stack.clear()
                    console.debug("stack.depth = ", stack.depth)
                }
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent

        Rectangle {
            id: rectangle_1
            visible: false
            property alias text: text_1.text

            Text {
                id: text_1
                text: "1"
            }
        }

        Rectangle {
            id: rectangle_2
            visible: false
            property alias text: text_2.text

            Text {
                id: text_2
                text: "2"
            }
        }

        Rectangle {
            id: rectangle_3
            visible: false
            property alias text: text_3.text

            Text {
                id: text_3
                text: "3"
            }
        }
    }
}
