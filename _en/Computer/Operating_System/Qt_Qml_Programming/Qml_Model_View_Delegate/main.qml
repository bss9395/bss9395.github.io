import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Item {
    width: 480
    height: 480

    ListModel {
        id: listmodel_fruit

        ListElement {
            name: "Apple"
            cost: 2.45
            attributes: [
                ListElement {
                    description: "Core"
                },
                ListElement {
                    description: "Deciduous"
                }
            ]
        }

        ListElement {
            name: "Orange"
            cost: 3.25
            attributes: [
                ListElement {
                    description: "Citrus"
                }

            ]
        }

        ListElement {
            name: "Banana"
            cost: 1.95
            attributes: [
                ListElement {
                    description: "Tropical"
                },
                ListElement {
                    description: "Seedless"
                }
            ]
        }
    }

    Component {
        id: component_fruit

        Item {
            width: 200
            height: 50

            Text {
                id: text_name
                text: model.name
            }
            Text {
                text: "$" + model.cost
                anchors.left: text_name.right
            }
            Row {
                anchors.top: text_name.bottom
                spacing: 5
                Text {
                    text: "Attributes: "
                }
                Repeater {
                    model: attributes

                    Text {
                        text: model.description
                    }
                }
            }
        }
    }

    ListView {
        id: listview_fruit
        height: contentHeight
        model: listmodel_fruit
        delegate: component_fruit
    }

    ////////////////////////////////////

    Component {
        id: component_data

        Text {
            font.pointSize: 12
            // text: modelData["age"]
            text: modelData.age
        }
    }

    ListView {
        id: listview_data
        anchors.top: listview_fruit.bottom
        model: []
        delegate: component_data
    }

    Component.onCompleted: {
        var data = []
        var item = {}
        item.age = "30"
        data.push(item)
        listview_data.model = data
    }
}
