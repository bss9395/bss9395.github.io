import QtQuick 2.12
import QtQuick.Controls 2.12

Popup {
    signal signal_toastFinished(var identifier)
    property var father: undefined
    id: popup_toast
    visible: (1 <= listmodel.count)
    parent: Overlay.overlay
    width: column.width
    height: column.height
    x: (parent.width - width) / 2
    y: 0
    margins: 0
    padding: 0
    closePolicy: Popup.NoAutoClose
    modal: false
    dim: false
    background: Rectangle {
        color: "#00FFFFFF"
    }

    Column {
        property var heightLast: column.height
        id: column
        topPadding: 10
        spacing: 8

        Repeater {
            model: ListModel {
                id: listmodel
            }
            delegate: Label {
                property var innerPadding: fontmetrics.height / 2
                id: label_text
                visible: true
                width: 260
                height: {
                    var fitHeight = implicitHeight - (contentHeight / lineCount - fontmetrics.height)
                    return (image_icon.y + image_icon.height <= fitHeight) ? fitHeight : (image_icon.y + image_icon.height)
                }
                background: Rectangle {
                    radius: 6
                    border.width: 1
                    border.color: "#FFF5C6C6"
                    color: "#FFFFF3F3"
                }
                leftPadding  : {
                    var offset = innerPadding
                    offset += image_icon.width + innerPadding / 2
                    return offset
                }
                rightPadding : innerPadding
                topPadding   : {
                    var offset = innerPadding
                    offset += image_icon.height / 2 - fontmetrics.height / 2
                    return (0 <= offset) ? offset : 0
                }
                bottomPadding: innerPadding
                font.pixelSize: 12
                font.weight: Text.Normal
                wrapMode: Text.WrapAnywhere
                lineHeightMode: Text.ProportionalHeight
                lineHeight: 1.2
                color: "#FFFF0000"
                text: model["message"]

                Image {
                    id: image_icon
                    width: 24
                    height: 24
                    anchors.left: parent.left
                    anchors.leftMargin: parent.innerPadding
                    anchors.verticalCenter: parent.top
                    anchors.verticalCenterOffset: parent.topPadding + fontmetrics.height / 2
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/images/icon_warning.png"
                }

                FontMetrics {
                    id: fontmetrics
                    font: label_text.font
                }

                Timer {
                    id: timer
                    running: true
                    repeat: false
                    interval: model["duration"]  // 吐司与动画并行，吐司时间包含动画时间

                    onTriggered: {
                        console.debug(`timer:onTriggered, index = ${index}`)
                        var popup      = popup_toast
                        var identifier = model["identifier"]
                        listmodel.remove(index)  // 注意增删元素会导致高度值改变
                        popup.signal_toastFinished(identifier)
                    }
                }
            }
        }

        PropertyAnimation {
            id: animation_shift
            running: false
            loops: 1
            target: column
            property: "y"
            to: 0
            duration: 500
        }

        onHeightChanged: {
            console.debug(`column:onHeightChanged, count = ${listmodel.count}, column.height = ${column.height}`)
            if(column.heightLast < column.height) {  // 注意增删元素会改变高度值
                animation_shift.running = false      // 注意动画有时间延迟
                column.y               -= (column.height - column.heightLast)
                animation_shift.running = true       // 动画开始之前设置好属性
            }
            column.heightLast = column.height
        }
    }

    function toast(identifier, level, message, duration) {
        // 吐司与动画并行，吐司时间包含动画时间
        if(duration < animation_shift.duration) {
            duration = animation_shift.duration
        }
        var datum = {
            "identifier": identifier,
            "level"     : level,
            "message"   : message,
            "duration"  : duration
        }
        listmodel.insert(0, datum)  // 此处column.height未返回正确值
    }
}
