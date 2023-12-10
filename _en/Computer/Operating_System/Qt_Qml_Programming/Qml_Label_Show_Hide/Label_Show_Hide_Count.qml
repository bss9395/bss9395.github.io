import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    property alias  font          : label_text.font
    property alias  lineHeightMode: label_text.lineHeightMode
    property alias  lineHeight    : label_text.lineHeight
    property alias  wrapMode      : label_text.wrapMode
    property alias  color         : label_text.color
    property int    maximumCount  : 317
    property string text          : ""
    property bool   completed     : false
    property string none_show_hide: "none"
    id: column_show_hide
    width: parent.width
    clip: true

    FontMetrics {
        id: fontmetrics
        font: column_show_hide.font
    }

    Label {
        id            : label_text
        visible       : column_show_hide.none_show_hide === "none"
        width         : parent.width
        wrapMode      : Text.WrapAnywhere
        color         : "#FF000000"
        text          : ""
        clip          : true
    }

    Label {
        id            : label_hide
        visible       : column_show_hide.none_show_hide === "hide"
        width         : parent.width
        font          : column_show_hide.font
        lineHeightMode: column_show_hide.lineHeightMode
        lineHeight    : column_show_hide.lineHeight
        wrapMode      : column_show_hide.wrapMode
        color         : column_show_hide.color
        text          : ""
        clip          : true

        Label {
            id            : label_showmore
            anchors.left  : parent.left
            anchors.bottom: parent.bottom
            font          : column_show_hide.font
            lineHeightMode: column_show_hide.lineHeightMode
            lineHeight    : column_show_hide.lineHeight
            color         : "#4399F3"
            text          : "显示更多"
            clip          : true

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('label_showmore:onClicked')
                    column_show_hide.none_show_hide = "show"
                }
            }
        }
    }

    Label {
        id            : label_show
        visible       : column_show_hide.none_show_hide === "show"
        width         : parent.width
        font          : column_show_hide.font
        lineHeightMode: column_show_hide.lineHeightMode
        lineHeight    : column_show_hide.lineHeight
        wrapMode      : column_show_hide.wrapMode
        color         : column_show_hide.color
        text          : ""
        clip          : true

        Label {
            id            : label_hideless
            anchors.left  : parent.left
            anchors.bottom: parent.bottom
            font          : column_show_hide.font
            lineHeightMode: column_show_hide.lineHeightMode
            lineHeight    : column_show_hide.lineHeight
            color         : "#4399F3"
            text          : "折叠显示"
            clip          : true

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('label_hideless:onClicked')
                    column_show_hide.none_show_hide = "hide"
                }
            }
        }
    }


    onTextChanged: {
        if(column_show_hide.completed === false) {
            return
        }
        console.debug('column_show_hide:onTextChanged')

        if(column_show_hide.text.length <= column_show_hide.maximumCount) {
            // 全文显示
            column_show_hide.none_show_hide = "none"
            label_text.text = column_show_hide.text
            return
        } else {
            column_show_hide.none_show_hide = "hide"
            // 隐藏文本
            var label_hide_text = column_show_hide.text.slice(0, maximumCount) + "..."
            label_hide.text = label_hide_text
            var label_hide_lineCount = label_hide.lineCount
            var label_hide_lastLine = ""
            if(label_hide_lineCount <= 1) {
                label_hide_lastLine = label_hide_text
            } else {
                for(var i = label_hide_text.length; 1 <= i; i -= 1) {
                    label_hide.text = label_hide_text.slice(0, i)
                    if(label_hide.lineCount < label_hide_lineCount) {
                        label_hide_lastLine = label_hide_text.slice(i, label_hide_text.length)
                        break
                    }
                }
            }

            label_hide.text = label_hide_text
            var label_hide_lastLine_width = fontmetrics.advanceWidth(label_hide_lastLine) + fontmetrics.advanceWidth("   ")
            if(label_hide_lastLine_width + label_showmore.width <= label_hide.width) {
                label_showmore.anchors.leftMargin = label_hide_lastLine_width
            } else {
                label_hide.height += label_showmore.height
                label_showmore.anchors.leftMargin = 0
            }

            //////////////////////////
            // 显示文本
            var label_show_text = column_show_hide.text
            label_show.text = label_show_text
            var label_show_lineCount = label_show.lineCount
            var label_show_lastLine = ""
            if(label_show_lineCount <= 1) {
                label_show_lastLine = label_show_text
            } else {
                for(var j = label_show_text.length; 1 <= j; j -= 1) {
                    label_show.text = label_show_text.slice(0, j)
                    if(label_show.lineCount < label_show_lineCount) {
                        label_show_lastLine = label_show_text.slice(j, label_show_text.length)
                        break
                    }
                }
            }

            label_show.text = label_show_text
            var label_show_lastLine_width = fontmetrics.advanceWidth(label_show_lastLine) + fontmetrics.advanceWidth("   ")
            if(label_show_lastLine_width + label_hideless.width <= label_show.width) {
                label_hideless.anchors.leftMargin = label_show_lastLine_width
            } else {
                label_show.height += label_hideless.height
                label_hideless.anchors.leftMargin = 0
            }
        }
    }

    Component.onCompleted: {
        console.debug('column_show_hide:onCompleted')

        column_show_hide.completed = true
        textChanged()
    }
}
