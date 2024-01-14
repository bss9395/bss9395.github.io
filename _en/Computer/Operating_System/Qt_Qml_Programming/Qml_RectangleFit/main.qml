import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "CusConfig.js" as CusConfig

Window {
    property real dpi: 1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // 登录栏
    RectangleFit {  // 此处子组件visible属性在加载完成后未正确设置
        id: rectangle_login
        // anchors.left: label_title.right
        anchors.left: parent.left
        anchors.leftMargin: 30 * dpi
        //anchors.verticalCenter: label_title.verticalCenter

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`rectangle_login:onClicked`)
            }

            Component.onCompleted: {
                console.debug(`mousearea.visible = ${visible}`)
            }
        }

        // 登录头像
        Image {
            id: image_avatar
            width: 20 * dpi
            height: 20 * dpi
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/icon_avatar.png"

            Component.onCompleted: {
                console.debug(`image_avatar:onCompleted, visible = ${visible}`)
            }
        }

        // 登录昵称
        Label {
            id: label_avatar
            anchors.left: image_avatar.right
            anchors.leftMargin: 0 * dpi
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12 * dpi
            font.weight: Font.Normal
            font.family: CusConfig.fontCNFamily
            color: "#FF000000"
            text: "登录开天软件中心"

            Component.onCompleted: {
                console.debug(`label_avatar:onCompleted, visible = ${visible}`)
            }
        }
    }
}
