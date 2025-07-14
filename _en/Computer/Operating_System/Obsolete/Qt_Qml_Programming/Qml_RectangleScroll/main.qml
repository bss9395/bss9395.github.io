import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Timer {
        property var count: 0
        id: timer
        running: true
        repeat: true
        interval: 2000

        onTriggered: {
            // console.debug(`timer:onTriggered`)

            console.debug(`=====================================================`)
            // textarea.insert(0, `\n${count}`)
            textarea.append(`${count}`)

//            rectanglescroll.locationHeight = 0.0                                  // 滚动条起点居上
//            rectanglescroll.locationHeight = 1.0 - rectanglescroll.ratioHeight    // 滚动条终点居下
//            rectanglescroll.locationHeight = 0.5                                  // 滚动条起点居中
//            rectanglescroll.locationHeight = (1.0 - rectanglescroll.ratioHeight)  // 滚动条中点居中

            count += 1
        }
    }

    RectangleScroll {
        id: rectanglescroll
        width : 200
        height: 200
        background: Rectangle {
            color: "yellow"
        }
        scrollType: enum_scrollPane
        scrollDrag: true

        TextArea {
            id: textarea
            width: 400
            background: Rectangle {
                color: "red"
            }
            padding: 0
            wrapMode: Text.WrapAnywhere
            text: ""
        }
    }
}
