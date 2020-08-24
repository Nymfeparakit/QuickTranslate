import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    //width: 320
    //height: 140
    flags: Qt.FramelessWindowHint
    color: "#333333"

    TranslateTextRect {
        id: translatedText
        objectName: "translatedTextRect"
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
        source: "qrc:/qml/resources/expand-more-icon.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                exitSignal()
            }
        }
    }
}
