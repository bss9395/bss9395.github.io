import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Item {
    width: 480
    height: 370

    Component {
        id: component

        Rectangle {
            id: rectangle_wrapper
            width: 50
            height: 50
            color: rectangle_wrapper.ListView.isCurrentItem ? "white" : "lightGreen"

            Text {
                anchors.centerIn: parent
                font.pixelSize: 15
                text: index
                color: rectangle_wrapper.ListView.isCurrentItem ? "blue" : "white"
            }
        }
    }

    Row {
        ListView {
            id: listview_highlight
            width: 100
            height: contentHeight
            spacing: 5
            highlightMoveDuration: 1000
            highlightMoveVelocity: -1
            keyNavigationWraps: true
            highlightFollowsCurrentItem: true
            clip: true
            snapMode: ListView.SnapToItem
            focus: true
            model: 20
            delegate: component
            header: Rectangle {
                width: 50
                height: 20
                color: "#b4d34e"

                Text {
                    anchors.centerIn: parent
                    text: "header"
                }
            }
            footer: Rectangle {
                width: 50
                height: 20
                color: "#797e65"

                Text {
                    anchors.centerIn: parent
                    text: "footer"
                }
            }
            highlight: Rectangle {
                color: "black"
                width: 100
                height: 50
                radius: 5
                opacity: 0.3
                z: 2
                y: listview_highlight.currentItem.y
            }
        }

        ListView {
            id: listview_highlightrangemode
            width: 180
            height: contentHeight
            clip: true
            spacing: 5
            focus: false
            highlightFollowsCurrentItem: false
            preferredHighlightBegin: 100
            preferredHighlightEnd: 150
            highlightRangeMode: ListView.StrictlyEnforceRange

            model: 100
            delegate: component
            highlight: Rectangle {
                width: 100
                height: 50
                color: "lightsteelblue"
                radius: 5
                y: listview_highlightrangemode.currentItem.y
                z: 2
                opacity: 0.3

                Behavior on y {
                    SpringAnimation {
                        spring: 3
                        damping: 0.2
                    }
                }
            }
        }
    }

    MouseArea {
        anchors.fill: parent

        property int highlighted: 0

        onClicked: {
            if(highlighted == 0) {
                highlighted = 1
                listview_highlight.focus = false
                listview_highlightrangemode.focus = true
            } else {
                highlighted = 0
                listview_highlight.focus = true
                listview_highlightrangemode.focus = false
            }
        }
    }
}
