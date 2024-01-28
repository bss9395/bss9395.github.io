import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    property var dpi: 1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Column {
        Button {
            id: button
            text: "button"

            onClicked: {
                console.debug(`button:onClicked`)
            }

            onFocusChanged: {
                if(focus === true) {
                    text = "focus === true"
                } else {
                    text = "focus === false"
                }
            }
        }


        // 账号输入框
        TextField {
            // 此处tab键popup弹窗不正常返回
            property var tabbed: "none"  // "none", "pressed", "tabbed"
            id: textfield_account
            width: parent.width
            height: 32 * dpi
            background: Rectangle {
                radius: 6 * dpi
                border.width: 1 * dpi
                border.color: "#FFE6E6E6"
                color: "#FFFFFFFF"
            }
            leftPadding: height / 3
            rightPadding: height / 3
            font.pixelSize: 12 * dpi
            font.weight: Font.Normal
            placeholderTextColor: "#FFCCCCCC"
            placeholderText: "请输入您的邮箱/手机号"
            color: "#FF222222"
            text: ""
            selectByMouse: true
            activeFocusOnTab: true

            onTextChanged: {
                label_account_failed.visible = false
            }

            onEditingFinished: {
                if(textfield_account.tabbed !== "pressed" && textfield_account.tabbed !== "tabbed") {
                    return
                }
                console.debug(`textfield_account:onEditingFinished`)
            }

            onPressed: {
                console.debug(`textfield_account:onPressed`)
                textfield_account.tabbed = "pressed"
                popup_accounts.open()
                textfield_account.forceActiveFocus()  // 注意onPressed()=>onFocusChanged()
            }

            onFocusChanged: {
                console.debug(`textfield_account:onFocusChanged`)
                if(focus === true) {
                    if(textfield_account.tabbed === "none") {
                        console.debug(`if(textfield_account.tabbed === "none") {`)
                        popup_accounts.open()
                        popup_accounts.forceActiveFocusFirst()  // textfield失去焦点，popup获取焦点
                    }
                } else if(focus === false) {
                    console.debug(`} else if(focus === false) {, textfield_account.tabbed = ${textfield_account.tabbed}`)
                    // 失去焦点还原为状态none
                    if(textfield_account.tabbed !== "none") {
                        popup_accounts.close()
                    }
                    textfield_account.tabbed = "none"
                }
            }

            function forceActiveFocusTab() {
                console.debug(`function forceActiveFocusTab() {`)
                textfield_account.tabbed = "tabbed"
                textfield_account.forceActiveFocus()  // 注意forceActiveFocusTab()=>onFocusChanged()
            }

            // 账号下拉列表
            Popup {
                id: popup_accounts
                visible: false
                width: parent.width
                height: column_accounts.height
                x: parent.width - width
                y: parent.height
                margins: 0 * dpi
                padding: 0 * dpi
                closePolicy: Popup.CloseOnPressOutside
                modal: true
                dim: false
                background: Rectangle {
                    border.width: 1 * dpi
                    border.color: "#FFE6E6E6"
                    color: "#FFFFFFFF"
                }

                onVisibleChanged: {
                    // console.debug(`popup_accounts:onVisibleChanged`)
                    if(visible === true) {
                        var accounts = [
                            {
                                "accountname": "13246759395"
                            },
                            {
                                "accountname": "bss9395@yeah.net"
                            }
                        ]

                        listmodel_accounts.clear()
                        for(var i = 0; i < accounts.length; i += 1) {
                            listmodel_accounts.append(accounts[i])
                        }
                    }
                    console.debug(`popup_accounts:onVisibleChanged`)
                }

                function forceActiveFocusFirst() {
                    console.debug(`function forceActiveFocusFirst() {`)
                    // 此处需考虑popup_accounts:onVisibleChanged=>forceActiveFocusFirst()
                    if(0 < listmodel_accounts.count) {
                        console.debug(`if(0 < listmodel_accounts.count) {, listmodel_accounts.count = ${listmodel_accounts.count}, column_accounts.children.length = ${column_accounts.children.length}`)
                        column_accounts.children[0].forceActiveFocus()
                    } else {
                        popup_accounts.close()
                        textfield_account.forceActiveFocusTab()
                    }
                }

                Column {
                    id: column_accounts
                    width: parent.width
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 0 * dpi

                    Repeater {
                        id: repeater_accounts
                        model: ListModel {
                            id: listmodel_accounts
                        }
                        delegate: Label {
                            property var inited : false
                            property var hovered: false
                            id: label_item
                            width: column_accounts.width
                            height: 32 * dpi
                            background: Rectangle {
                                border.width: 1 * dpi
                                // border.color: "#00FFFFFF"  // 此处完全透明无效果
                                border.color: "#01FFFFFF"
                                color: (label_item.hovered === true) ? "#FFF0F7FE" : "#FFFFFFFF"
                            }
                            leftPadding: height / 3
                            rightPadding: height / 3 + image_delete.width + image_delete.anchors.rightMargin
                            verticalAlignment: Text.AlignVCenter
                            font.pixelSize: 12 * dpi
                            font.weight: Font.Normal
                            elide: Text.ElideRight
                            maximumLineCount: 1
                            color: "#FF4F4E69"
                            text: model["accountname"]
                            activeFocusOnTab: true

                            onFocusChanged: {
                                label_item.hovered = focus
                            }

                            Keys.onReturnPressed: {
                                console.debug(`label_item:onReturnPressed`)
                                mousearea_item.clicked(null)
                            }

                            MouseArea {
                                id: mousearea_item
                                anchors.fill: parent
                                hoverEnabled: true

                                onPositionChanged: {
                                    // console.debug(`label_item:onPositionChanged`)
                                    label_item.hovered = true
                                }

                                onExited: {
                                    console.debug(`label_item:onExited`)
                                    label_item.hovered = false
                                }

                                onClicked: {
                                    console.debug(`label_item:onClicked`)
                                    label_item.focus = true
                                    textfield_account.text = label_item.text
                                    popup_accounts.close()
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

                                Keys.onReturnPressed: {
                                    console.debug(`image_delete:onReturnPressed`)
                                    mousearea_delete.clicked(null)
                                }

                                // Tab键导航到Popup页面末项则返回
                                Keys.onTabPressed: (event) => {
                                    console.debug(`image_delete:onTabPressed`)
                                    if(listmodel_accounts.count - 1 <= model.index) {
                                        popup_accounts.close()
                                        textfield_account.forceActiveFocusTab()
                                    } else {
                                        console.debug(`event.accepted = false`)
                                        event.accepted = false
                                    }
                                }

                                MouseArea {
                                    id: mousearea_delete
                                    anchors.fill: parent

                                    onClicked: {
                                        console.debug(`image_delete:onClicked`)
                                        image_delete.focus = true
                                        softwarecenter.removeAccount(label_item.text)
                                        listmodel_accounts.remove(index)
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


        TextField {
            id: textfield
            text: ""
            activeFocusOnTab: true
        }
    }
}

