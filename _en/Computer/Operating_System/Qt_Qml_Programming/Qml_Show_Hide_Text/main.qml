import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    property int maxLineCount: 3
    property bool done_show_text: false
    property bool done_hide_text: false
    property string none_show_hide: "none"
    id: item_root
    width: 600
    height: 600

    Column {
        width: 300

        FontMetrics {
            id: fontmetrics
            font: label_text.font
        }

        Label {
            id: label_text
            visible: none_show_hide === "none"
            width: parent.width
            wrapMode: Text.WrapAnywhere
            clip: true
            text: "This is a long textqqqqqqqqqqqqqaaaaaaaaaaaaaaaaaaaaqaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaqqqqqqqqqqqqqqqqqqqqqaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbq"

            onTextChanged: {
                console.debug('column_show_hide:onTextChanged')
                if(lineCount <= maxLineCount) {
                    none_show_hide = "none"
                    return
                } else{
                    none_show_hide = "hide"

                    for(var i = text.length; 1 <= i && done_show_text === false; i -= 1) {
                        label_show.text = text.slice(0, i)
                    }

                    for(var i = 1; i <= label_text.text.length && done_hide_text === false; i += 1) {
                        label_hide.text = label_text.text.slice(0, i)
                    }
                }
            }
        }

        Label {
            id: label_show
            visible: none_show_hide === "show"
            width: parent.width
            wrapMode: Text.WrapAnywhere
            clip: true
            text: ""

            onTextChanged: {
                console.debug('text_show:onTextChanged')
                if(done_show_text === false && lineCount < label_text.lineCount) {
                    done_show_text = true
                    var lastLine = label_text.text.slice(text.length, label_text.text.length)
                    if(fontmetrics.advanceWidth(lastLine) + label_hideless.width <= width) {
                        label_hideless.x = fontmetrics.advanceWidth(lastLine)
                        label_hideless.anchors.bottom = label_show.bottom
                    } else{
                        label_hideless.x = 0
                        label_hideless.anchors.top = label_show.bottom
                    }
                    label_show.text = label_text.text
                }
            }

            Label {
                id: label_hideless
                anchors.bottom: label_show.bottom
                text: " 折叠显示"
                color: "blue"
                maximumLineCount: 1
                clip: true

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        none_show_hide = "hide"
                    }
                }
            }
        }

        Label {
            id: label_hide
            visible: none_show_hide === "hide"
            width: parent.width
            wrapMode: Text.WrapAnywhere
            clip: true
            text: ""

            onTextChanged: {
                if(done_hide_text === false && label_hide.lineCount >= maxLineCount) {
                    done_hide_text = true
                    var previousText = label_hide.text.slice(0, -1)
                    var lastLine = ""
                    var achar = ''
                    var i = previousText.length
                    while(true) {
                        if(fontmetrics.advanceWidth(lastLine + achar + "...") >= width - label_showmore.width) {
                            lastLine += "..."
                            break
                        }
                        lastLine += achar
                        if(i < label_show.text.length === false) {
                            lastLine += "..."
                            break
                        }
                        achar = label_show.text.charAt(i)
                        i += 1
                    }
                    label_hide.text = previousText + lastLine
                    label_showmore.x = fontmetrics.advanceWidth(lastLine)
                }
            }

            Label {
                id: label_showmore
                anchors.bottom: label_hide.bottom
                text: " 显示更多"
                color: "blue"
                maximumLineCount: 1
                clip: true

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        none_show_hide = "show"
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        label_text.onTextChanged(label_text.text)
    }
}
