import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        TextField {
            id: textfield0
            text: "textfield0"
            activeFocusOnTab: true
            activeFocusOnPress: true
        }

        TextField {
            property var stating    : "none"  // "none", "pressed", "tabbed"
            property var shielding: false
            property var echo: ({})
            id: textfield_account
            height: 32
            font.pixelSize: 12
            font.weight: Font.Normal
            placeholderText: "请输入账号"
            text: ""
            activeFocusOnTab: true     // 键盘焦点自动触发
            activeFocusOnPress: false  // 鼠标焦点手动触发

            onPressed: {
                console.debug(`textfield_account:onPressed`)
                stating = "pressed"
                popup_accounts.open()
                textfield_account.forceActiveFocus()
            }

            // 鼠标或键盘或程序都可获取与失去焦点
            onFocusChanged: {
                console.debug(`textfield_account:onFocusChanged, focus = ${focus}`)
                if(focus === true) {
                    if(stating === "none") {               // 此状态为瞬态，触发随即丢弃
                        shielding = true
                        popup_accounts.open()
                        popup_accounts.forceActiveFocus()  // 焦点转移，函数阻塞递归调用
                    }
                } else {
                    if(stating !== "none") {
                        popup_accounts.close()
                    }
                    // 失去焦点则重置状态为基本状态none
                    stating = "none"
                }
            }

            // 校验函数也可手动调用
            onEditingFinished: {
                if(shielding === true) {
                    shielding = false
                    return
                }
                console.debug(`textfield_account:onEditingFinished`)
                if(textfield_account.text === "") {
                    textfield_account.echo = {
                        "code": 101,
                        "info": "请输入账号"
                    }
                } else {
                    textfield_account.echo = {
                        "code": 100,
                        "info": "账号校验成功"
                    }
                }
            }

            function func_forceActiveFocus() {
                console.debug(`function func_forceActiveFocus() {`)
                stating = "tabbed"
                textfield_account.forceActiveFocus()
            }

            // 账号下拉列表
            Popup {
                id: popup_accounts
                visible: false
                width: parent.width
                height: column_accounts.height
                x: parent.width - width
                y: parent.height
                margins: 0
                padding: 0
                background: Rectangle {
                    border.width: 1
                    border.color: "#FFE6E6E6"
                    color: "#FFFFFFFF"
                }
                closePolicy: Popup.CloseOnPressOutside
                modal: false
                dim: false

                // 弹窗组件打开以后，加载列表项，根组件获取焦点
                onOpened: {
                    console.debug(`popup_accounts:onOpened`)
                    listmodel_accounts.append({
                        "accountname": "13246759395"
                    })
                    listmodel_accounts.append({
                        "accountname": "bss9395@yeah.net"
                    })
                }

                // 弹窗组件关闭以后，清空列表项
                onClosed: {
                    console.debug(`popup_accounts:onClosed`)
                    listmodel_accounts.clear()
                }

                Column {
                    id: column_accounts
                    width: parent.width
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 0

                    Repeater {
                        model: ListModel {
                            id: listmodel_accounts
                        }
                        delegate: Label {
                            property var hovered: false
                            id: label_account
                            width: column_accounts.width
                            height: 32
                            background: Rectangle {
                                border.width: 1
                                // border.color: "#00FFFFFF"
                                border.color: "#01FFFFFF"
                                color: (label_account.hovered === true) ? "#FFF0F7FE" : "#FFFFFFFF"
                            }
                            leftPadding: height / 3
                            rightPadding: height / 3 + image_delete.width + image_delete.anchors.rightMargin
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            font.pixelSize: 12
                            font.weight: Font.Normal
                            maximumLineCount: 1
                            elide: Text.ElideRight
                            color: "#FF4F4E69"
                            text: model["accountname"]
                            activeFocusOnTab: true

                            onFocusChanged: {
                                // console.debug(`label_account:onFocusChanged, focus = ${focus}`)
                                label_account.hovered = focus
                            }

                            Keys.onReturnPressed: (event) => {
                                console.debug(`label_account:onReturnPressed`)
                                mousearea_account.clicked(null)
                            }

                            MouseArea {
                                id: mousearea_account
                                anchors.fill: parent
                                hoverEnabled: true

                                onPositionChanged: {
                                    // console.debug(`label_account:onPositionChanged`)
                                    label_account.hovered = true
                                }

                                onExited: {
                                    console.debug(`label_account:onExited`)
                                    label_account.hovered = false
                                }

                                onClicked: {
                                    console.debug(`label_account:onClicked`)
                                    label_account.focus = true
                                    textfield_account.text = label_account.text
                                    textfield_account.func_forceActiveFocus()
                                }
                            }

                            // 删除按钮
                            Image {
                                id: image_delete
                                width: parent.height / 5 * 2
                                height: parent.height / 5 * 2
                                anchors.right: parent.right
                                anchors.rightMargin: parent.height / 3
                                anchors.verticalCenter: parent.verticalCenter
                                fillMode: Image.PreserveAspectFit
                                source: "qrc:/images/icon_delete.png"
                                activeFocusOnTab: true

                                Keys.onTabPressed: (event) => {
                                    console.debug(`image_delete:onTabPressed`)
                                    if(listmodel_accounts.count - 1 <= model.index) {
                                        textfield_account.func_forceActiveFocus()
                                        event.accepted = true
                                    } else {
                                        event.accepted = false
                                    }
                                }

                                Keys.onReturnPressed: {
                                    console.debug(`image_delete:onReturnPressed`)
                                    mousearea_delete.clicked(null)
                                }

                                MouseArea {
                                    id: mousearea_delete
                                    anchors.fill: parent

                                    onClicked: {
                                        console.debug(`image_delete:onClicked`)
                                        image_deleta.focus = true
                                        listmodel_accounts.remove(model.index)
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        LabelFit {
            id: label_accounts_echo
            visible: false
            anchors.left: parent.left
            anchors.right: parent.right
            wrapMode: Text.WrapAnywhere
            lineHeightMode: Text.ProportionalHeight
            lineHeight: 1.2
            text: {
                if(textfield_account.echo["code"]) {
                    if(textfield_account.echo["code"] === 100 || textfield_account.echo["code"] === 200) {
                        label_accounts_echo.visible = false
                    } else {
                        label_accounts_echo.visible = true
                    }
                    return textfield_account.echo["info"]
                }
                return ""
            }
            color: "#FFFF0000"
        }

        TextField {
            id: textfield2
            text: "textfield2"
            activeFocusOnTab: true
            activeFocusOnPress: true
        }
    }
}
