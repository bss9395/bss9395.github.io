import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Module 1.0

Window {
    property var multithread: MultiThread {}
    property var mutexlock  : MutexLock {}
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        console.debug(`window:onCompleted`)
//        timer.running = true

        // 注意：信号接收发生在接收者线程，qml代码层是单线程运行，qml渲染层可能是多线程运行。
        multithread.signal_thread.connect(function () {
            column.func_mergeList(multithread)
        })
    }

    TextField {
        id: textfield0
        anchors.top: parent.top
        text: "textfield0"
    }

    TextField {
        id: textfield1
        anchors.top: textfield0.bottom
        text: "textfield1"
    }

    Column {
        property var pool: ["2", "3", "4", "5", "6", "7", "8", "9"]
        property var index_head: 0
        property var index_tail: 2
        id: column
        anchors.top: textfield1.bottom
        spacing: 4

        // 注意：信号接收发生在接收者线程，qml代码层是单线程运行，qml渲染层可能是多线程运行。
        function func_mergeList(caller) {
            console.debug(`function func_mergeList() {`)
            var data = (index_head <= index_tail) ? pool.slice(index_head, index_tail) : pool.slice(index_tail, index_head)
            index_head = (index_head + 1) % pool.length
            index_tail = (index_tail + 1) % pool.length

            caller._Sleep(1)  // 阻塞线程
            for(var i = 0; i < data.length; i += 1) {
                var hitted = false
                for(var j = 0; j < listmodel.count; j += 1) {
                    if(listmodel.get(j)["value"] === data[i]) {
                        hitted = true
                        break
                    }
                }
                if(hitted === false) {
                    listmodel.append({"value": data[i], "color": "#FFFF0000"})
                }
            }
        }

        Timer {
            id: timer
            running: false
            repeat: true
            interval: 3000

            // 注意：信号接收发生在接收者线程，qml代码层是单线程运行，qml渲染层可能是多线程运行。
            onTriggered: {
                console.debug(`timer:onTriggered`)
                column.func_mergeList(mutexlock)
            }
        }

        Repeater {
            model: ListModel {
                id: listmodel

                Component.onCompleted: {
                    console.debug(`column:onCompleted`)
                    listmodel.append({"value": "0", "color": "#FF00FF00"})
                    listmodel.append({"value": "1", "color": "#FF00FF00"})
                    listmodel.append({"value": "2", "color": "#FF00FF00"})
                }
            }

            Label {
                id: label
                width: 100
                height: 32
                background: Rectangle {
                    color: model["color"]
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment  : Text.AlignVCenter
                text: model["value"]
            }
        }
    }
}
