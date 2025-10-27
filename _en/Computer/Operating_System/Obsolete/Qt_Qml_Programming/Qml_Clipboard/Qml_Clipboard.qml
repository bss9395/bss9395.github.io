/* Qml_Clipboard.qml
Author: bss9395
Update: 2025/10/28T02:41:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import Custom 1.0

Window {
    visible: true
    width: 600
    height: 600

    property Clipboard clipboard: Clipboard{}

    Rectangle {
        id: rectangle_copy
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 200
        border.width: 1
        clip: true

        TextEdit {
            id: textedit_copy
            visible: true
            anchors.fill: parent
            selectByMouse: true
            wrapMode: Text.Wrap
            Keys.onPressed: {
                if (event.modifiers & Qt.ControlModifier && event.key === Qt.Key_C) {
                    event.accepted = true;
                    console.log("[rectangle_copy] Ctrl + C is blocked.");
                    clipboard.setText(textedit_copy.selectedText);
                    // context_clipboard.setText(textedit_copy.selectedText);
                }
                if (event.modifiers & Qt.ControlModifier && event.key === Qt.Key_V) {
                    event.accepted = true;
                    console.log("[rectangle_copy] Ctrl + V is blocked.");
                }
            }

//            Shortcut {
//                sequence: StandardKey.Copy
//                onActivated: {
//                    console.debug("textedit_copy")
//                    clipboard.setText(textedit_copy.selectedText);
//                }
//            }
        }
    }

    Rectangle {
        id: rectangle_paste
        anchors.top: rectangle_copy.bottom
        anchors.horizontalCenter: rectangle_copy.horizontalCenter
        width: 200
        height: 200
        border.width: 1
        clip: true

        TextEdit {
            id: textedit_paste
            visible: true
            anchors.fill: parent
            selectByMouse: true
            wrapMode: Text.Wrap
            Keys.onPressed: {
                if (event.modifiers & Qt.ControlModifier && event.key === Qt.Key_C) {
                    event.accepted = true;
                    console.log("[rectangle_paste] Ctrl + C is blocked.");
                }
                if (event.modifiers & Qt.ControlModifier && event.key === Qt.Key_V) {
                    event.accepted = true;
                    console.log("[rectangle_paste] Ctrl + V is blocked.");
                    textedit_paste.insert(textedit_paste.cursorPosition, clipboard.getText());
                    // textedit_paste.insert(textedit_paste.cursorPosition, context_clipboard.getText());
                }
            }

//            Shortcut {
//                sequence: StandardKey.Paste
//                onActivated: {
//                    console.debug("textedit_paste")
//                    textedit_paste.clear()
//                    textedit_paste.insert(textedit_paste.cursorPosition, clipboard.getText());
//                }
//            }
        }
    }


}
