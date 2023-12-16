import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

Rectangle {
    id: rectangle
    width: 680
    height: childrenRect.height
    color: "lightblue"

    Column {
        Rectangle {
            width: grid.width
            height: grid.height
            anchors.left: parent.left
            anchors.leftMargin: 10

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug(`grid:onClicked`)
                }
            }

            // Grid设置宽度不影响子元素，Grid可以添加特效，Grid可以设置padding
            Grid {
                id: grid
                // width: rectangle.width                 // 注意Grid设置宽度不会影响子元素
                padding: 10
                columns: 3
                columnSpacing: 0
                rowSpacing: 0
                horizontalItemAlignment: Grid.AlignHCenter
                verticalItemAlignment: Grid.AlignVCenter  // 注意Grid的verticalItemAlignment对于所有子元素适用

                Repeater {
                    model: 7
                    delegate: Control {
                        id: control_grid
                        width: 20 * (index + 1)
                        height: 20 * (index + 1)
                        background: DropShadow {
                            horizontalOffset: 0
                            verticalOffset: 0
                            radius: 8
                            samples: 24
                            color: "#80000000"
                            cached: false
                            source: Rectangle {
                                width: control_grid.width
                                height: control_grid.height
                                color: "#FFFFFFFF"
                                radius: 8
                            }
                        }
                    }
                }

                Image {
                    width: 48
                    height: 48
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/images/Sunny.jpg"
                }
            }
        }

        Rectangle {
            width: gridlayout.width
            height: gridlayout.height
            anchors.left: parent.left
            anchors.leftMargin: 10

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug(`gridlayout:onClicked`)
                }
            }

            // GridLayout设置宽度会影响子元素，GridLayout不具有特效，子元素可以对齐，子元素可以跨行列
            GridLayout {
                id: gridlayout
                width: rectangle.width                    // 注意GridLayout设置宽度会影响子元素
                columns: 3
                columnSpacing: 0                          // 注意GridLayout设置宽度会影响子元素，columnSpacing设置最小padding
                rowSpacing: 0

                Repeater {
                    model: 7
                    delegate: Control {
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Layout.margins: 10

                        id: control_gridlayout
                        width: 20 * (index + 1)
                        height: 20 * (index + 1)
                        background: DropShadow {
                            horizontalOffset: 0
                            verticalOffset: 0
                            radius: 8
                            samples: 24
                            color: "#80000000"
                            cached: false
                            source: Rectangle {
                                width: control_gridlayout.width
                                height: control_gridlayout.height
                                color: "#FFFFFFFF"
                                radius: 8
                            }
                        }
                    }
                }

                Image {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.preferredWidth: width
                    Layout.preferredHeight: height

                    width: 48
                    height: 48
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/images/Sunny.jpg"
                }
            }
        }
    }
}
