import QtQuick
import QtQuick.Controls
import Qt.labs.qmlmodels

Window {
    width: 400
    height: 200
    visible: true

    TreeView {
        id: treeView
        anchors.fill: parent
        anchors.margins: 10
        clip: true

        selectionModel: ItemSelectionModel {}

        model: TableModel {
            TableModelColumn { display: "checked"    }
            TableModelColumn { display: "amount"     }
            TableModelColumn { display: "fruitType"  }
            TableModelColumn { display: "fruitName"  }
            TableModelColumn { display: "fruitPrice" }

            rows: [
                {
                    checked: false,
                    amount: 1,
                    fruitType: "Apple",
                    fruitName: "Granny Smith",
                    fruitPrice: 1.50
                },
                {
                    checked: true,
                    amount: 4,
                    fruitType: "Orange",
                    fruitName: "Navel",
                    fruitPrice: 2.50
                },
                {
                    checked: false,
                    amount: 1,
                    fruitType: "Banana",
                    fruitName: "Cavendish",
                    fruitPrice: 3.50
                }
            ]
        }

        delegate: Item {
            implicitWidth: padding + label.x + label.implicitWidth + padding
            implicitHeight: label.implicitHeight * 1.5

            readonly property real indentation: 20
            readonly property real padding: 5
            required property TreeView treeView
            required property bool isTreeNode
            required property bool expanded
            required property bool hasChildren
            required property int depth
            required property int row
            required property int column
            required property bool current

            Rectangle {
                id: background
                anchors.fill: parent
                color: row === treeView.currentRow ? palette.highlight : "black"
                opacity: (treeView.alternatingRows && row % 2 !== 0) ? 0.3 : 0.1
            }

            Label {
                id: label
                x: padding + (isTreeNode ? (depth + 1) * indentation : 0)
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width - padding - x
                clip: true
                text: model.display
            }
        }
    }
}
