import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    RowLayout {
        spacing: 20

        ColumnLayout {
            CheckBox {
                text: "First"
                checked: true
            }

            CheckBox {
                text: "Second"
            }

            CheckBox {
                text: "Third"
                checked: true
            }
        }

        ColumnLayout {
            RadioButton {
                text: "First"
                checked: true
            }

            RadioButton {
                text: "Second"
            }

            RadioButton {
                text: "Third"
            }
        }

        ColumnLayout {
            ButtonGroup {
                id: buttongroup
                exclusive: false
                checkState: checkbox_group.checkState
            }

            CheckBox {
                id: checkbox_group
                text: "Parent"
                checkState: buttongroup.checkState
            }

            CheckBox {
                //leftPadding: indicator.width
                text: "Child 1"
                checked: true

                ButtonGroup.group: buttongroup
            }

            CheckBox {
                leftPadding: indicator.width
                text: "Child 2"

                ButtonGroup.group: buttongroup
            }
        }

        ButtonGroup {
            id: buttongroup_group
        }

        ColumnLayout {
            Label {
                text: "组1"
            }

            RadioButton {
                text: "选项1"
                checked: true

                ButtonGroup.group: buttongroup_group
            }

            RadioButton {
                text: "选项2"

                ButtonGroup.group: buttongroup_group
            }
        }

        ColumnLayout {
            Label {
                text: "组2"
            }

            RadioButton {
                text: "选项3"

                ButtonGroup.group: buttongroup_group
            }

            RadioButton {
                text: "选项4"

                ButtonGroup.group: buttongroup_group
            }
        }
    }
}
