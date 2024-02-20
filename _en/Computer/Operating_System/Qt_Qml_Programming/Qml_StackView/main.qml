import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button
        width: 100
        height: 32
        text: (1 <= stackview.depth) ? "卸载" : "加载"

        onClicked: {
            console.debug(`button:onClicked`)
            if(stackview.depth === 0) {
                var component = Qt.createComponent("Page.qml")
                if (component.status === Component.Ready){
                    var page = component.createObject(stackview)

                    page.closed.connect(function(userInfo) {
                        console.debug(`userInfo = ${JSON.stringify(userInfo)}`)
                    })

                    stackview.push(page)
                    console.debug(`stackview.depth = ${stackview.depth}`)
                }
            } else {
                var obj = stackview.currentItem
                if(obj){
                    obj.destroy()
                }

                // 注意stackview.depth===1时，stackview.pop()无效。
                if(1 < stackview.depth) {
                    stackview.pop()
                } else {
                    stackview.clear()
                }
                console.debug(`stackview.depth = ${stackview.depth}`)
            }
        }
    }

    StackView {
        id: stackview
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: button.bottom
        anchors.bottom: parent.bottom
    }
}
