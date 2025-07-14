import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Rectangle {
    property real dpi:1
    visible: true
    width: 200
    height: 100
    color: "red"

    RectangleFit {
        id: rectangle_upload
        anchors.centerIn: parent
        color: "green"

        Image {
            id: image_upload
            width: 20 * dpi
            height: 20 * dpi
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 0 * dpi
            fillMode: Image.PreserveAspectFit
            source: "images/icon_upload.png"

            Component.onCompleted: {
                console.debug(`image_upload:onCompleted`)
            }
        }

        Label {
            id: label_upload
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: image_upload.bottom
            anchors.topMargin: 6 * dpi
            font.pixelSize: 12 * dpi
            font.weight: Font.Normal
            color: "#FFFFFFFF"
            text: "点击上传头像"

            Component.onCompleted: {
                console.debug(`label_upload:onCompleted`)
            }
        }

        Component.onCompleted: {
            console.debug(`rectangle_upload:onCompleted`)
        }
    }



    ItemBase {
        id: item_upload_item

        Image {
            id: image_upload_item
            width: 20 * dpi
            height: 20 * dpi
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 0 * dpi
            fillMode: Image.PreserveAspectFit
            source: "images/icon_upload.png"

            Component.onCompleted: {
                console.debug(`image_upload_item:onCompleted`)
            }
        }

        Label {
            id: label_upload_item
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: image_upload_item.bottom
            anchors.topMargin: 6 * dpi
            font.pixelSize: 12 * dpi
            font.weight: Font.Normal
            color: "#FFFFFFFF"
            text: "点击上传头像"

            Component.onCompleted: {
                console.debug(`label_upload_item:onCompleted`)
            }
        }

        Component.onCompleted: {
            console.debug(`item_upload_item:onCompleted`)
            width = childrenRect.width
            height = childrenRect.height
        }
    }
}
