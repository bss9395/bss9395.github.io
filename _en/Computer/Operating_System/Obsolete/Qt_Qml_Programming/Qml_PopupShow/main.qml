/// Record: main.qml
/// Author: bss9395
/// Update: 2025-12-06T22:22:00+08$08@China-BeiJing
/// Keepin: bss9395@yeah.net

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: button
        width: 100
        height: 100
        text: "button"
        property int idx: 0

        onClicked: {
            idx = (idx + 1) % 3;
            if(idx == 0) {
                popup.showPopup(true, false, false);
            }
            if(idx == 1) {
                popup.showPopup(true, true, false);
            }
            if(idx == 2) {
                popup.showPopup(true, true, true);
            }
        }
    }

    Popup {
        function showPopup(toReplace, toDelete, toPaste) {
            popup.maxWidth = 0;
            column.listModel.clear();
            if(toReplace === true) {
                column.listModel.append({
                    title: "替换片段"
                });
            }
            if(toDelete === true) {
                column.listModel.append({
                    title: "删除片段"
                });
            }
            if(toPaste === true) {
                column.listModel.append({
                    title: "粘贴关键帧"
                });
            }

            popup.x = 100;
            popup.y = 100;
            popup.open();
        }

        id: popup
        anchors.centerIn: Overlay.overlay
        closePolicy: Popup.NoAutoClose
        modal: false
        dim: false
        padding: 0
        margins: 0
        background: Rectangle {
            color: "#FF000000"
            radius: 4
        }
        width: popup.maxWidth + 4 * 2 + 8 * 2
        height: column.height + 4 * 2
        property int maxWidth: 0

        Column {
            id: column
            spacing: 4
            width: popup.width
            anchors.verticalCenter: parent.verticalCenter
            property ListModel listModel: ListModel{}

            Repeater {
                id: repeater
                model: column.listModel

                Rectangle {
                    id: rectangle
                    width: parent.width - 4 * 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    height: 28
                    radius: 4
                    color: "yellow"

                    Text {
                        id: text
                        anchors.left: parent.left
                        anchors.leftMargin: 8
                        anchors.verticalCenter: parent.verticalCenter
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: model.title

                        Component.onCompleted: {
                            console.debug("completed[text] index = ", model.index, ", popup.maxWidth = ", popup.maxWidth, ", text.width = ", text.width);
                            popup.maxWidth = Math.max(popup.maxWidth, text.width);
                        }
                        Component.onDestruction: {
                            console.debug("destruction[text] index = ", model.index, ", popup.maxWidth = ", popup.maxWidth, ", text.width = ", text.width);
                        }
                    }

                    MouseArea {
                        id: mousearea
                        anchors.fill: parent

                        onClicked: {
                            popup.close();
                        }
                    }
                }
            }
        }
    }
}
