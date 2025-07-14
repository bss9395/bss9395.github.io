import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12
import QtQuick.Window 2.12
import Module_Config 1.0

Item {
    property var config: Type_Config {}
    width: 200
    height: 200

    Component.onCompleted: {
        config._Func(123);
    }
}
