import QtQuick 2.0

Text {
    enum TextType {
        Normal,
        Heading
    }

    property int textType: MyText.Heading

    font.bold: textType === MyText.TextType.Heading
    font.pixelSize: textType === MyText.TextType.Heading ? 24 : 12
    text: "Hello"
}
