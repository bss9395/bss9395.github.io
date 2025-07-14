import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    property alias  font          : label_text.font
    property alias  lineHeightMode: label_text.lineHeightMode
    property alias  lineHeight    : label_text.lineHeight
    property alias  wrapMode      : label_text.wrapMode
    property alias  color         : label_text.color
    property int    maximumLine   : 3
    property string text          : ""
    property bool   completed     : false
    property string none_show_hide: "none"
    id: column_show_hide
    width: parent.width

    FontMetrics {
        id: fontmetrics
        font: column_show_hide.font
    }

    Label {
        id      : label_text
        visible : column_show_hide.none_show_hide === "none"
        width   : parent.width
        wrapMode: Text.WrapAnywhere
        color   : "#FF000000"
        text    : ""
        clip    : true
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

        label_text.text = column_show_hide.text
        if(label_text.lineCount <= maximumLine) {
            // 全文显示
            column_show_hide.none_show_hide = "none"
            return
        } else {
            column_show_hide.none_show_hide = "hide"
            // 隐藏文本
            for(var i = 1; i < column_show_hide.text.length; i += 1) {
                label_hide.text = column_show_hide.text.slice(0, i)
                if(label_hide.lineCount >= column_show_hide.maximumLine) {
                    var previousText = label_hide.text.slice(0, -1)
                    var lastLine = ""
                    var achar = ''
                    var j = previousText.length
                    while(true) {
                        if(fontmetrics.advanceWidth(lastLine + achar + "...") + fontmetrics.advanceWidth("   ") + label_showmore.width > label_hide.width) {
                            lastLine += "..."
                            break
                        }
                        lastLine += achar
                        if(j >= column_show_hide.text.length) {
                            lastLine += "..."
                            break
                        }
                        achar = column_show_hide.text.charAt(j)
                        j += 1
                    }
                    label_hide.text = previousText + lastLine
                    label_showmore.anchors.leftMargin = fontmetrics.advanceWidth(lastLine) + fontmetrics.advanceWidth("   ")
                    break
                }
            }

            ////////////////////////////
            // 显示文本
            var label_show_text = column_show_hide.text
            label_show.text = label_show_text
            var label_show_lineCount = label_show.lineCount
            var label_show_lastLine = ""
            if(label_show_lineCount <= 1) {
                label_show_lastLine = label_show_text
            } else {
                for(var k = label_show_text.length; 1 <= k; k -= 1) {
                    label_show.text = label_show_text.slice(0, k)
                    if(label_show.lineCount < label_show_lineCount) {
                        label_show_lastLine = label_show_text.slice(k, label_show_text.length)
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
