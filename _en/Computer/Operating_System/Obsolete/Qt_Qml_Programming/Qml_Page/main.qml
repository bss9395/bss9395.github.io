import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: Label {
        horizontalAlignment: Text.AlignHCenter
        text: swipeview.currentItem.title
    }

    SwipeView {
        id: swipeview
        anchors.fill: parent

        Page {
            title: "页面1"
            header: ToolBar {
                RowLayout {
                    anchors.fill: parent

                    ToolButton {
                        text: "按钮1"
                    }

                    ToolButton {
                        text: "按钮2"
                    }
                }
            }
            footer: ToolBar {
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "工具栏"
                }
            }
        }

        Page {
            title: "页面2"
            header: TabBar {
                TabButton {
                    text: "选项1"
                }

                TabButton {
                    text: "选项2"
                }
            }
        }
    }

    PageIndicator {
        anchors.bottom: swipeview.bottom
        anchors.bottomMargin: 40
        anchors.horizontalCenter: swipeview.horizontalCenter
        count: swipeview.count
        currentIndex: swipeview.currentIndex
    }
}
