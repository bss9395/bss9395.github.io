import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    ListView {
        id: listview
        anchors.fill: parent
        model: listmodel
        delegate: component

        ListModel {
            id: listmodel

            ListElement {
                title: "Qt Quick Guidelines"
            }

            ListElement {
                title: "Pixmap and Threaded Image Support"
            }

            ListElement {
                title: "the C++ API provided by the Qt Quick module"
            }

            ListElement {
                title: "the C++ API provided by the Qt Quick module"
            }

            ListElement {
                title: "provides a particle system for Qt Quick"
            }
        }

        Component {
            id: component

            SwipeDelegate {
                id: swipedelegate
                width: listview.width
                text: index + " - " + title
                swipe.right: Label {
                    id: label
                    height: parent.height
                    anchors.right: parent.right
                    padding: 12
                    text: "Delete"
                    color: "white"
                    verticalAlignment: Label.AlignVCenter
                    background: Rectangle {
                        color: label.SwipeDelegate.pressed ? Qt.darker("tomato", 1.1) : "tomato"
                    }

                    SwipeDelegate.onClicked: {
                        listview.model.remove(index)
                    }
                }

                ListView.onRemove: {
                    sequentialanimation.start()
                }

                SequentialAnimation {
                    id: sequentialanimation

                    PropertyAction {
                        target: swipedelegate
                        property: "ListView.delayRemove"
                        value: true
                    }

                    NumberAnimation {
                        target: swipedelegate
                        property: "height"
                        to: 0
                        duration: 500
                        easing.type: Easing.InOutQuad
                    }

                    PropertyAction {
                        target: swipedelegate
                        property: "ListView.delayRemove"
                        value: false
                    }
                }
            }
        }
    }
}
