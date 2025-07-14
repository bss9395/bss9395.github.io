import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle_drop
        width: 200
        height: 200
        x: 100
        y: 100
        border.width: 1
        border.color: "#FF000000"
        color: "#FFFFFFFF"

        DropArea {
            id: droparea
            anchors.fill: parent

            onEntered: (event) => {
                console.debug(`rectangle_drop:onEntered`)
                console.debug(`Qt.IgnoreAction = ${Qt.IgnoreAction}, Qt.CopyAction = ${Qt.CopyAction}, Qt.MoveAction = ${Qt.MoveAction}, Qt.LinkAction = ${Qt.LinkAction}`)
                console.debug(`event.proposedAction = ${event.proposedAction}, event.supportedActions = ${event.supportedActions}, event.action = ${event.action}`)
            }

            onDropped: (event) => {
                console.debug(`rectangle_drop:onDropped`)
                console.debug(`Qt.IgnoreAction = ${Qt.IgnoreAction}, Qt.CopyAction = ${Qt.CopyAction}, Qt.MoveAction = ${Qt.MoveAction}, Qt.LinkAction = ${Qt.LinkAction}`)
                console.debug(`event.proposedAction = ${event.proposedAction}, event.supportedActions = ${event.supportedActions}, event.action = ${event.action}`)

                if(event.source) {  // 拖拽源来自qml内部
                    console.debug(`event.source.Drag = ${JSON.stringify(event.source.Drag)}`)
                    var mimeData = event.source.Drag.mimeData
                    console.debug(`mimeData = ${JSON.stringify(mimeData)}`)
                    for(var i = 0; i < mimeData["text/uri-list"].length; i += 1) {
                        console.debug(`mimeData["text/uri-list"][${i}] = ${mimeData["text/uri-list"][i]}`)
                    }
                } else {            // 拖拽源来自qml外部
                    console.debug(`event.formats = ${event.formats}`)
                    console.debug(`event.hasColor = ${event.hasColor}, event.colorData = ${event.colorData}`)
                    console.debug(`event.hasHtml = ${event.hasHtml}, event.html = ${event.html}`)
                    console.debug(`event.hasText = ${event.hasText}, event.text = ${event.text}`)
                    console.debug(`event.hasUrls = ${event.hasUrls}, event.urls = ${event.urls}`)
                }
            }
        }
    }

    Rectangle {
        id: rectangle_drag
        width: 50
        height: 50
        color: "#FFFF0000"
        x: 10
        y: 10

        Drag.hotSpot.x: rectangle_drag.width / 2
        Drag.hotSpot.y: rectangle_drag.height / 2
        Drag.imageSource: "file:///home/lenovo/avatar.png"
        Drag.mimeData: {
            "text/plain": "Copied text.",
            "text/uri-list": [
                "https://doc.qt.io/qt-6/qmimedata.html",
                "https://www.baidu.com/",
                "https://cn.bing.com/"
            ],
            "text/html": "https://doc.qt.io/qt-6/qmimedata.html"
        }
        Drag.proposedAction: Qt.MoveAction                                    // Qt.CopyAction, Qt.MoveAction, Qt.LinkAction, Qt.IgnoreAction
        Drag.supportedActions: Qt.CopyAction | Qt.MoveAction | Qt.LinkAction  // Qt.CopyAction, Qt.MoveAction, Qt.LinkAction, Qt.IgnoreAction

        MouseArea {
            property var mouse_pressed: ({})
            id: mousearea_drag
            anchors.fill: parent

            onPressed: {
                console.debug(`rectangle_drag:onPressed`)
                var mouse_global = app.pos()
                mouse_pressed.start_x = rectangle_drag.x
                mouse_pressed.start_y = rectangle_drag.y
                mouse_pressed.x = mouse_global.x
                mouse_pressed.y = mouse_global.y
                rectangle_drag.Drag.start()
            }

            onPositionChanged: {
                // console.debug(`rectangle_drag:onPositionChanged`)
                var mouse_global = app.pos()
                rectangle_drag.x = mouse_pressed.start_x + (mouse_global.x - mouse_pressed.x)
                rectangle_drag.y = mouse_pressed.start_y + (mouse_global.y - mouse_pressed.y)
            }

            onReleased: {
                console.debug(`rectangle_drag.onReleased`)
                rectangle_drag.Drag.drop()
            }
        }
    }
}
