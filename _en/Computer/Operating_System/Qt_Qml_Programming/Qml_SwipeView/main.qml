import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar {
        RowLayout {
            ToolButton {
                text: "Home"

                onClicked: {
                    swipeview.setCurrentIndex(0)
                }
            }

            ToolButton {
                enabled: swipeview.currentIndex > 0
                text: "<"

                onClicked: {
                    swipeview.decrementCurrentIndex()
                }
            }

            ToolButton {
                enabled: swipeview.currentIndex < swipeview.count - 1
                text: ">"

                onClicked: {
                    swipeview.currentIndex += 1;
                }
            }
        }
    }

    SwipeView {
        id: swipeview
        currentIndex: tabbar.currentIndex
        width: parent.width
        height: 100
        background: Rectangle {
            color: "lightblue"
        }

        Repeater {
            model: 5

            Loader {
                active: SwipeView.isCurrentItem || SwipeView.isNextItem || SwipeView.isPreviousItem
                sourceComponent: Text {
                    text: "页面" + (index + 1)

                    Component.onCompleted: {
                        console.debug("created " + index)
                    }

                    Component.onDestruction: {
                        console.debug("destroyed " + index)
                    }
                }
            }
        }
    }

    TabBar {
        id: tabbar
        width: parent.width
        anchors.top: swipeview.bottom
        currentIndex: swipeview.currentIndex

        Repeater {
            id: repeater
            model: ["First", "Second", "Third", "Fourth", "Fifth"]

            TabButton {
                text: modelData
                width: tabbar.width / repeater.model.length
            }
        }
    }

    Row {
        anchors.top: tabbar.bottom
        anchors.topMargin: 30
        width: parent.width

        TabBar {
            id: tabbar_button
            width: parent.width - button.width

            Component {
                id: component

                TabButton {
                    text: "TabButton"
                }
            }

            Component.onCompleted: {
                console.debug(button.width, ", ", tabbar_button.width)
            }
        }

        Button {
            id: button
            flat: true
            text: "+"

            onClicked: {
                tabbar_button.addItem(component.createObject(tabbar_button))
            }

            Component.onCompleted: {
                button.clicked()
            }
        }
    }
}
