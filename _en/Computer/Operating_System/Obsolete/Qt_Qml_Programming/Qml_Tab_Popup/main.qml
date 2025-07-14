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
        property var tabChain: ([])
        id: column

        Keys.onTabPressed: (event) => {
            console.debug(`column:onTabPressed`)
            func_tabChain()
        }

        Component.onCompleted: {
            tabChain.push(textfield0)
            tabChain.push(textfield_account)
            tabChain.push(textfield2)
            column.focus = true  // 根组件获取初始焦点
        }

        function func_tabChain() {
            console.debug(`column:function func_tabChain() {`)
            if((1 <= tabChain.length) === false) {
                return
            }

            var i = 0
            var hitted = false
            for(; i < tabChain.length; i += 1) {
                if(tabChain[i].focus === true) {
                    console.debug(`if(tabChain[${i}].focus === true) {`)
                    hitted = true
                    break
                }
            }
            if(hitted === true) {
                if(0 <= i + 1 && i + 1 < tabChain.length && tabChain[i + 1] === textfield_account) {
                    popup_accounts.open()   // 遇见输入框前打开弹窗组件
                    return
                } else if(tabChain[i] === textfield_account) {
                    popup_accounts.close()  // 离开输入框时关闭弹窗组件
                }
                i = (i + 1) % tabChain.length
            } else {
                i = 0
            }
            tabChain[i].focus = true
        }


        TextField {
            id: textfield0
            text: "textfield0"
            activeFocusOnTab: false
            activeFocusOnPress: true
        }

        TextField {
            property var echo: ({})
            id: textfield_account
            placeholderText: "请输入账号"
            text: ""
            activeFocusOnTab: false
            activeFocusOnPress: true

            onPressed: (event) => {
                console.debug(`textfield_account:onPressed`)
                popup_accounts.open()
                // 点击输入框后自动获取焦点
            }

            onEditingFinished: {
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

            onTextChanged: {
                console.debug(`textfield_account:onTextChanged`)
                label_account_echo.visible = false
            }

            // 下拉账号列表
            RectanglePopup {
                id: popup_accounts
                visible: false
                height: column_accounts.height
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.bottom
                background: Rectangle {
                    border.width: 1
                    border.color: "#FFE6E6E6"
                    color: "#FFFFFFFF"
                }
                strategy: enum_closeOutsideEscape
                modal: false
                dim: false
                draggable: false

                // 弹窗组件打开以后，加载列表项，根组件获取焦点
                onOpened: {
                    console.debug(`popup_accounts:onOpened`)
                    listmodel_accounts.append({
                        "accountname": "13246759395"
                    })
                    listmodel_accounts.append({
                        "accountname": "bss9395@yeah.net"
                    })
                    column_accounts.focus = true
                }

                // 弹窗组件关闭以后，清空列表项
                onClosed: {
                    console.debug(`popup_accounts:onClosed`)
                    listmodel_accounts.clear()
                }

                Column {
                    property var tabChain: ([])
                    id: column_accounts
                    width: parent.width
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 0

                    Keys.onTabPressed: (event) => {
                        console.debug(`popup_accounts:onTabPressed`)
                        func_tabChain()
                    }

                    function func_tabChain() {
                        console.debug(`popup_accounts:function func_tabChain() {`)
                        if((1 <= tabChain.length) === false) {
                            return
                        }
                        var i = 0
                        var hitted = false
                        for(; i < tabChain.length; i += 1) {
                            if(tabChain[i].focus === true) {
                                console.debug(`if(tabChain[${i}].focus === true) {`)
                                hitted = true
                                break
                            }
                        }
                        if(hitted === true) {
                            if(i === tabChain.length - 1) {
                                textfield_account.focus = true  // Tab键导航到末项，原组件获取焦点
                                return
                            }
                             i = (i + 1) % tabChain.length
                        } else {
                            i = 0
                        }
                        tabChain[i].focus = true
                    }

                    function func_tabAppend(item) {
                        console.debug(`function func_tabAppend(item) {`)
                        tabChain.push(item)
                    }

                    function func_tabRemove(item) {
                        console.debug(`function func_tabRemove(item) {`)
                        var i = 0
                        var hitted = false
                        for(; i < tabChain.length; i += 1) {
                            if(tabChain[i] === item) {
                                console.debug(`if(tabChain[${i}] === item) {`)
                                hitted = true
                                break
                            }
                        }
                        if(hitted === true) {
                            tabChain.splice(i, 1)
                        }
                    }

                    Repeater {
                        model: ListModel {
                            id: listmodel_accounts
                        }
                        delegate: Label {
                            property var inited : false
                            property var hovered: false
                            id: label_account
                            width: column_accounts.width
                            height: 32
                            background: Rectangle {
                                border.width: 1
                                // border.color: "#00FFFFFF"  // 此处完全透明无效果
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
                            activeFocusOnTab: false

                            onFocusChanged: {
                                // console.debug(`label_account:onFocusChanged, focus = ${focus}`)
                                label_account.hovered = focus
                            }

                            Keys.onReturnPressed: {
                                console.debug(`label_account:onReturnPressed`)
                                mousearea_account.clicked(null)
                            }

                            Component.onCompleted: {
                                column_accounts.func_tabAppend(label_account)
                                column_accounts.func_tabAppend(image_delete)
                            }

                            Component.onDestruction: {
                                column_accounts.func_tabRemove(label_account)
                                column_accounts.func_tabRemove(image_delete)
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
                                    var textfield = textfield_account
                                    label_account.focus = true
                                    textfield_account.text = label_account.text
                                    popup_accounts.close()
                                    textfield.focus = true
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
                                activeFocusOnTab: false

                                Keys.onReturnPressed: {
                                    console.debug(`image_delete:onReturnPressed`)
                                    mousearea_delete.clicked(null)
                                }

                                MouseArea {
                                    id: mousearea_delete
                                    anchors.fill: parent

                                    onClicked: {
                                        console.debug(`image_delete:onClicked`)
                                        image_delete.focus = true
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
            id: label_account_echo
            visible: false
            anchors.left: parent.left
            anchors.right: parent.right
            font.pixelSize: 12
            font.weight: Font.Normal
            wrapMode: Text.WrapAnywhere
            lineHeightMode: Text.ProportionalHeight
            lineHeight: 1.2
            text: {
                console.debug(`label_account_echo:text`)
                if(textfield_account.echo["code"]) {
                    if(textfield_account.echo["code"] === 100 || textfield_account.echo["code"] === 200) {
                        label_account_echo.visible = false
                    } else {
                        label_account_echo.visible = true
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
            activeFocusOnTab: false
            activeFocusOnPress: true
        }
    }
}
