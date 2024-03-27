import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Contain {
        id: contain
        width: 200
        height: 200
        x: 0
        y: 0
        color: "yellow"
        background: Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            color: "red"
        }
        clip: true

        Rectangle {
            id: rectangle_children
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            color: "green"
        }
    }

    Control {
        id: control
        width: 200
        height: 200
        x: 200
        y: 200
        background: Rectangle {
            color: "red"
        }
        leftInset: 20     // inset影响background
        topInset: -20
        leftPadding: -10  // padding影响contentItem
        topPadding: 10
        clip: false       // clip剪裁background和contentItem

        // 前缀contentItem，受padding影响，修正size
        contentItem: Rectangle {
            id: rectangle_contentItem
            width: 100
            height: 100
            color: "blue"
        }

        // 普通children，不受padding影响，不修正size
        Rectangle {
            id: rectangle
            width: 100
            height: 100
            color: "green"
        }
    }
}
