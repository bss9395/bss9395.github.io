import QtQuick 2.12
import QtQuick.Window 2.12
import Custom 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Aliase {
        id: groupedproperties
        inner.width: 100
        inner.height: 100
        inner {
            color: "green"
        }

        // inner.prop: "yellow"  // 注意在qml中定义的property不可用于属性组的初始化
        Component.onCompleted: {
            inner.prop = "blue"
        }
    }


    Config {
        id: attached
        attached: 10
        grouped.attached0: 20
        grouped.attached1: "30"
        grouped {
            attached0: 40
            attached1: "50"
        }
    }


    Rectangle {
        id: rectangle0
        Attached.attached: 10
        Attached.grouped.attached0: 20
        Attached.grouped.attached1: "30"
    }

    Rectangle {
        id: rectangle1
        Attached.attached: 20
        Attached.grouped.attached0: 20
        Attached.grouped.attached1: "30"
    }
}
