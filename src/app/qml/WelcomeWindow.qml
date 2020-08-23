import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {

    width: 320
    height: 140
    flags: Qt.FramelessWindowHint

    /*function showAtPosition(xPos, yPos) {
        show();
        x = xPos;
        y = yPos;
    }*/

    signal exitSignal()
    signal onOpenMainWindowBtnClicked()

    Button {
       text: "open app"
       onClicked: {
           exitSignal()
       }
    }

}
