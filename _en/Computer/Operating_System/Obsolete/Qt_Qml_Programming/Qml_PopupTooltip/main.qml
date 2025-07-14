import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Window {
    property var dpi: 1
    visible: true
    width: 640
    height: 480
    property var extraData: { "filename": "CusConfig.fontCNFamily" }

    // 打开按钮
    Label {
        property var hovered: false
        id: label_open
        visible: true
        width: 80 * dpi
        height: 28 * dpi
        anchors.right: parent.right
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12 * dpi
        font.bold: false
        color: "#FF4399F3"
        text: "打开目录"
        background: Rectangle {
            border.color: "#FF4399F3"
            radius: 16 * dpi
        }

        // 打开按钮提示
        Popup {
            id: popup_open_tip
            visible: (label_open.hovered === true)
            width: rectangle_content.width
            height: rectangle_content.height
            x: label_open.width - width
            y: label_open.height + 2 * dpi
            margins: 0 * dpi
            padding: 0 * dpi
            closePolicy: Popup.CloseOnPressOutside
            modal: false
            dim: false
            background: Rectangle {
                color: "#00FFFFFF"
            }

            // 主体内容
            RectangleFit {
                id: rectangle_content
                layer.enabled: true
                layer.effect: DropShadow {
                    horizontalOffset: 0 * dpi
                    verticalOffset: 0 * dpi
                    radius: 8 * dpi
                    samples: 24
                    color: "#60000000"
                }

                // 小三角
                Rectangle {
                    id: rectangle_open_tip
                    width: 10 * dpi
                    height: 10 * dpi
                    anchors.right: label_open_tip.right
                    anchors.rightMargin: label_open.width / 2 - width / 2
                    anchors.verticalCenter: parent.top
                    anchors.verticalCenterOffset: width / 2 * Math.sqrt(2) * Math.sin((rotation + 45) / 180.0 * Math.PI)
                    color: "#FFFFFFFF"
                    rotation: 45  // 顺时针旋转角度
                }

                // 提示文字
                Label {
                    id: label_open_tip
                    anchors.left: parent.left
                    anchors.top: rectangle_open_tip.verticalCenter
                    anchors.topMargin: 0 * dpi
                    background: Rectangle {
                        radius: 6 * dpi
                        color: "#FFFFFFFF"
                    }
                    leftPadding: fontmetrics_open_tip.height / 3 * 2
                    rightPadding: fontmetrics_open_tip.height / 3 * 2
                    topPadding: fontmetrics_open_tip.height / 3 * 2
                    bottomPadding: fontmetrics_open_tip.height / 3 * 2
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12 * dpi
                    font.weight: Font.Normal
                    color: "#FF000000"
                    text: (popup_open_tip.visible === true && extraData["filename"]) ? extraData["filename"] : ""  // 动态加载

                    FontMetrics {
                        id: fontmetrics_open_tip
                        font: label_open_tip.font
                    }
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onPositionChanged: {
                // console.debug(`label_open:onPositionChanged`)
                label_open.hovered = true
            }

            onExited: {
                console.debug(`label_open:onExited`)
                label_open.hovered = false
            }

            onClicked: {
                console.debug('Driver_Item_OS.qml:label_open:onClicked')
                softwarecenter.openFileFolder(softwareData["uuid"], extraData["filepath"])
            }
        }
    }
}
