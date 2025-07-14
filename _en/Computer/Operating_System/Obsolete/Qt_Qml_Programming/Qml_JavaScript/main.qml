import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import "Button.js"   as ButtonJs
import "Function.js" as FunctionJs

Rectangle {
    visible: true
    width: 640
    height: 480
    color: "lightblue"

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        onClicked: {
            console.log(FunctionJs.factorial(10))
        }
    }

    Row {
        Rectangle {
            id: rectangle_red
            width: 200
            height: 100
            color: "red"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    ButtonJs.onClicked(rectangle_red)
                }
            }
        }

        Rectangle {
            id: rectangle_green
            width: 200
            height: 100
            color: "green"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    ButtonJs.onClicked(rectangle_green)
                }
            }
        }

        Rectangle {
            id: rectangle_blue
            width: 200
            height: 100
            color: "blue"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    ButtonJs.onClicked(rectangle_blue)
                }
            }
        }
    }

    Component.onCompleted: {
        var numerator   = 100
        var denominator = 256
        console.debug(`numerator / denominator = ${numerator / denominator}`)

        var numerator_string   = "100"
        var denominator_string = "256"
        console.debug(`numerator_string / denominatro_string = ${numerator_string / denominator_string}`)
    }
}
