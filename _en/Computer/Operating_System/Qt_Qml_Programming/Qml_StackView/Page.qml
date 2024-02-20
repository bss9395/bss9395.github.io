import QtQuick 2.0
import QtQuick.Controls 2.12


Rectangle {
    signal closed(var userInfo)
    property var userInfo: ({
        name: "bss9395"
    })
    id: rectangle
    width: 200
    height: 200
    color: "#FFFF0000"

    onClosed: {
        console.debug(`rectangle:onClosed`)
    }

    onVisibleChanged: {
        console.debug(`rectangle:onVisibleChanged, visible = ${visible}`)
    }

    Component.onCompleted: {
        console.debug(`rectangle:onCompleted`)
    }

    Component.onDestruction: {
        console.debug(`rectangle:onDestruction`)
        closed(rectangle.userInfo)  // 发射关闭信号
    }
}
