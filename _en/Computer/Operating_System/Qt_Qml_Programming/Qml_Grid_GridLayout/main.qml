import QtQuick 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: rectangle
    // width: 680
    width: childrenRect.width
    height: childrenRect.height
    color: "lightblue"

    Column {
        // Grid设置宽度不影响子元素，Grid可以添加特效，Grid可以设置padding
        Grid {
            // width: rectangle.width                 // 注意Grid设置宽度不会影响子元素
            topPadding: 10
            columns: 3
            columnSpacing: 0
            horizontalItemAlignment: Grid.AlignHCenter
            verticalItemAlignment: Grid.AlignVCenter  // 注意Grid的verticalItemAlignment对于所有子元素适用

            Rectangle {
                // Layout.alignment: Qt.AlignBottom   // 注意Grid的Layout子项目没有效果
                width: 100
                height: 100
                color: "red"
            }

            Rectangle {
                width: 200
                height: 200
                color: "green"
            }

            Rectangle {
                width: 300
                height: 300
                color: "blue"
            }
        }

        // GridLayout设置宽度会影响子元素，GridLayout不具有特效，子元素可以对齐，子元素可以跨行列
        GridLayout {
            // width: rectangle.width                 // 注意GridLayout设置宽度会影响子元素
            // topPadding: 10                         // 注意GridLayout没有padding
            columns: 3
            columnSpacing: 10                         // 注意GridLayout设置宽度会影响子元素，columnSpacing设置最小padding

            Rectangle {
                Layout.alignment: Qt.AlignBottom
                width: 100
                height: 100
                color: "red"
            }

            Rectangle {
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                width: 200
                height: 200
                color: "green"
            }

            Rectangle {
                Layout.topMargin: 10
                width: 300
                height: 300
                color: "blue"
            }
        }
    }
}
