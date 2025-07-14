import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    id: item_base

    Image {
        id: image_upload_base
        width: 20 * dpi
        height: 20 * dpi
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 0 * dpi
        fillMode: Image.PreserveAspectFit
        source: "images/icon_upload.png"

        Component.onCompleted: {
            console.debug(`image_upload_base:onCompleted`)
        }
    }

    Label {
        id: label_upload_base
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: image_upload_item.bottom
        anchors.topMargin: 6 * dpi
        font.pixelSize: 12 * dpi
        font.weight: Font.Normal
        color: "#FFFFFFFF"
        text: "点击上传头像"

        Component.onCompleted: {
            console.debug(`label_upload_base:onCompleted`)
        }
    }

    Component.onCompleted: {
        console.debug(`item_base:onCompleted`)
    }
}
