import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    function readValues(anArray, anObject) {
        for(var i = 0; i < anArray.length; i += 1) {
            console.log("Array Item: ", anArray[i]);
        }

        for(var prop in anObject) {
            console.log("Object Item: ", prop, " = ", anObject[prop])
        }
    }

    width: 640
    height: 480
    visible: true

}
