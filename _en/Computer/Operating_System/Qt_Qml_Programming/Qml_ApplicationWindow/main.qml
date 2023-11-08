import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    id: applicationwindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        id: menubar

        Menu {
            id: menu_file
            title: "文件"

            MenuItem {
                text: "关闭"
                icon.source: "images/close.png"

                onTriggered: {
                    applicationwindow.close()
                }
            }

            MenuSeparator {

            }

            MenuItem {
                text: "关于"
                icon.source: "images/about.png"

                onTriggered: {
                    popup.open()
                }
            }
        }
    }

    header: ToolBar {
        RowLayout {
            anchors.fill: parent

            ToolButton {
                visible: tabbar_footer.currentIndex === 0
                enabled: stackview.depth > 1
                text: "<"

                onClicked: {
                    stackview.pop()
                }
            }

            ToolButton {
                visible: tabbar_footer.currentIndex == 0
                enabled: stackview.depth < 3
                text: ">"

                onClicked: {
                    stackview.push(component)
                }
            }

            PageIndicator {
                id: pageindicator
                visible: tabbar_footer.currentIndex == 0
                count: stackview.depth
                currentIndex: stackview.depth
            }

            Label {
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                text: "工具栏"
                elide: Label.ElideRight
                Layout.fillWidth: true
            }

            ToolButton {
                text: ":"

                onClicked: {
                    popup.open()
                }
            }
        }
    }

    footer: TabBar {
        id: tabbar_footer
        width: parent.width

        TabButton {
            text: "图片"
        }

        TabButton {
            text: "音乐"
        }

        TabButton {
            text: "视频"
        }
    }

    StackLayout {
        id: stacklayout
        anchors.fill: parent
        currentIndex: tabbar_footer.currentIndex

        StackView {
            id: stackview
            initialItem: component

            Component {
                id: component

                Item {
                    Rectangle {
                        anchors.fill: parent

                        Image {
                            anchors.fill: parent
                            source: "images/" + stackview.depth + ".png"
                        }

                        Text {
                            text: "页面" + stackview.depth
                        }
                    }
                }
            }
        }

        Rectangle {
            id: rectangle_second
            color: "lightyellow"
        }

        Rectangle {
            id: rectangle_third
            color: "lightblue"
        }
    }

    Popup {
        id: popup
        parent: Overlay.overlay
        width: 250
        height: 150
        x: Math.round(parent.width - width) / 2
        y: Math.round(parent.height - height) / 2
        modal: true
        focus: true

        Label {
            id: label
            font.pixelSize: 15
            font.italic: true
            x: Math.round(parent.width - width) / 2
            y: Math.round(parent.height - height) / 2
            text: "这是个Popup"
        }

        Button {
            anchors.top: label.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: label.horizontalCenter
            text: "Ok"

            onClicked: {
                popup.close()
            }
        }
    }
}
