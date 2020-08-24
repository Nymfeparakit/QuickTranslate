import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    width: 368
    height: 188
    flags: Qt.FramelessWindowHint
    color: "#333333"

    TranslateTextRect {
        id: translatedText
        objectName: "translatedTextRect"
        color: "#333333"

        width: 320
        height: 140
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    signal exitSignal()
    signal onExpandBtnClicked()

    /*Button {
       anchors.top: translatedText.bottom
       anchors.right: parent.right
       text: "expand"
       onClicked: {
           exitSignal()
       }
    }*/

    Image {
        anchors.top: translatedText.bottom
        anchors.right: parent.right
        //width: 24
        //height: 24

        source: "qrc:/qml/resources/expand-more-icon.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                exitSignal()
            }
        }
    }
}
