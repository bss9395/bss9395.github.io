import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    visible: true
    width: 640
    height: 480

    RowLayout {
        SpinBox {
            property var items: ["Small", "Medium", "Large"]

            id: spinbox_string
            from: 0
            to: items.length - 1
            value: 0
            validator: RegExpValidator {
                regExp: new RegExp("Small|Medium|Large", "i")
            }
            textFromValue: function(value) {
                return items[value]
            }
            valueFromText: function(text) {
                for(var i = 0; i < items.length; i += 1) {
                    if(items[i].toLowerCase().indexOf(text.toLowerCase()) === 0) {
                        return i
                    }
                }
                return spinbox_string.value
            }
        }

        SpinBox {
            id: spinbox_double
            from: 0
            to: 100
            value: 0
            stepSize: 1
            validator: DoubleValidator {
                bottom: spinbox_double.from
                top: spinbox_double.to
            }
            textFromValue: function(value) {
                return (spinbox_double.value / (spinbox_double.to - spinbox_double.from)).toFixed(2)
            }
            valueFromText: function(text) {
                return Number(text) * (spinbox_double.to - spinbox_double.from)
            }
        }
    }
}
