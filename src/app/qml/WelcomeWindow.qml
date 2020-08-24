import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {

    width: 50
    height: 50
    flags: Qt.FramelessWindowHint

    signal exitSignal()
    signal onWelcomeWindowBtnClicked()

    /*Button {
       text: "open app"
       onClicked: {
           exitSignal()
       }
    }*/

    Image {
        source: "qrc:/qml/resources/google-translate-icon.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                exitSignal()
            }
        }
    }

}
