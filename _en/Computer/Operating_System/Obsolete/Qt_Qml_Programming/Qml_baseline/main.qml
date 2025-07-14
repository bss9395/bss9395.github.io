import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    property var dpi: 1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        property var currentIndex   : 0
        property var currentBaseline: null
        id: row_title
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 0 * dpi
        spacing: 24 * dpi

        Repeater {
            id: repeater_title
            model: ["手机号注册", "邮箱注册"]
            delegate: Label {
                property var currentBaseline: row_title.currentBaseline
                id: label_title
                font.pixelSize: (row_title.currentIndex === index) ? 14 * dpi  : 12 * dpi
                font.weight: Font.Medium
                color: (row_title.currentIndex === index) ? "#FF222222" : "#FF999999"
                text: modelData

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        console.debug(`label_title:onClicked`)
                        row_title.currentIndex = index
                        func_currentBaselineChanged()
                    }
                }

                Component.onCompleted: {
                    console.debug(`label_title:onCompleted`)
                    if(row_title.currentIndex === index) {
                        func_currentBaselineChanged()
                    }
                }

                onCurrentBaselineChanged: {
                    console.debug(`label_title:onCurrentBaselineChanged`)
                    if(row_title.currentIndex !== index) {
                        anchors.top      = undefined
                        anchors.baseline = currentBaseline
                    }
                }

                function func_currentBaselineChanged() {
                    console.debug(`function changeCurrentBaseline() {`)
                    label_title.anchors.baseline = undefined
                    label_title.anchors.top      = label_title.parent.top
                    row_title.currentBaseline    = label_title.baseline
                }
            }
        }
    }
}
