import QtQuick
import Qt.labs.qmlmodels
import QtQuick.Controls

Window {
    width: 200
    height: 150
    visible: true

    TableView {
        id: tableView
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        model: TableModel {
            TableModelColumn { display: "name"  }
            TableModelColumn { display: "color" }

            rows: [
                { "name": "cat"   , "color": "black" },
                { "name": "dog"   , "color": "brown" },
                { "name": "bird"  , "color": "white" },
                { "name": "fish"  , "color": "blue" },
                { "name": "cattle", "color": "yellow" }
            ]
        }

        delegate: tableViewDelegate

        selectionModel: ItemSelectionModel {  }

        Component {
            id: tableViewDelegate

            Rectangle {
                implicitWidth: 100
                implicitHeight: 50
                border.width: 2
                required property bool current

                color: model.current ? "blue" : "white"

                TableView.onPooled: rotationAnimation.pause()    // onPooled信号通常和TableView中单元格的复用机制相关，该信号会在一个委托项delegate被放入复用池时触发
                TableView.onReused: rotationAnimation.resume()   // onReused信号在一个之前被放入复用池的委托项delegate被重新取出并再次使用时触发。这一机制是为了提高性能，避免在滚动表格视图时频繁创建和销毁委托项，而是复用已经存在的委托项。

                Text {
                    id: txt
                    text: model.display
                    anchors.centerIn: parent
                }

                RotationAnimation {
                    id: rotationAnimation
                    target: txt
                    duration: (Math.random() * 5000) + 2000
                    from: 0
                    to: 359
                    running: true
                    loops: Animation.Infinite
                }
            }
        }

        property var columnWidths: [100, 50]
        columnWidthProvider: function (column) {
            return columnWidths[column]
        }

        Timer {
            running: true
            interval: 2000

            onTriggered: {
                tableView.columnWidths[1] = 100
                tableView.forceLayout();
            }
        }
    }
}
