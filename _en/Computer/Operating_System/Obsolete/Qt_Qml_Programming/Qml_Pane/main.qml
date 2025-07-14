import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    RowLayout {
        x: 50
        y: 50
        spacing: 20

        Pane {
            ColumnLayout {
                anchors.fill: parent

                CheckBox {
                    text: "E-mail"
                }

                CheckBox {
                    text: "Calendar"
                }

                CheckBox {
                    text: "Contacts"
                }
            }
        }

        Frame {
            ColumnLayout {
                anchors.fill: parent

                CheckBox {
                    text: "E-mail"
                }

                CheckBox {
                    text: "Calendar"
                }

                CheckBox {
                    text: "Contacts"
                }
            }
        }

        GroupBox {
            title: "GroupBox"

            ColumnLayout {
                anchors.fill: parent

                CheckBox {
                    text: "E-mail"
                }

                CheckBox {
                    text: "Calendar"
                }

                CheckBox {
                    text: "Contacts"
                }
            }
        }


        GroupBox {
            title: "GroupBox"
            label: CheckBox {
                id: checkbox
                checked: true
            }

            ColumnLayout {
                anchors.fill: parent
                enabled: checkbox.checked

                CheckBox {
                    text: "E-mail"
                }

                CheckBox {
                    text: "Calendar"
                }

                CheckBox {
                    text: "Contacts"
                }
            }
        }
    }
}
