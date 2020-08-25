
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import "."

Window {

    id: mainWindow
    visible: false
    width: 30
    height: 30
    title: qsTr("")
    flags: Qt.FramelessWindowHint

    signal translateBtnClicked()
    signal welcomeButtonClicked()
    signal expandBtnClicked()
    signal fullWindowClosed()

    onClosing: {
        stackView.clear()
    }

    function showBusyIndicator() {
        busyIndicator.running = true
    }

    function hideBusyIndicator() {
        busyIndicator.running = false
    }


    StackView {
        id: stackView
        objectName: "stackView"
        width: 30
        height: 30
        //initialItem: "qrc:/qml/WelcomeButtonItem.qml"
    }

    function getCurrentItemName() {
        var currentItemName = stackView.currentItem.objectName;
        //console.log("current item name: " + currentItemName);
        return currentItemName;
    }

    function onClipboardDataChanged() {
        //console.log("calling onClipboardDataChanged")
        var currItem = stackView.currentItem
        console.log("curr item: " + currItem)
        if (currItem !== null && currItem.objectName == "fullLayoutItem") {
            return;
        }
        mainWindow.width = 30
        mainWindow.height = 30
        mainWindow.color = "#FFFFFF"
        mainWindow.x = cursorPosProvider.cursorPos().x
        mainWindow.y = cursorPosProvider.cursorPos().y
        mainWindow.flags = Qt.FramelessWindowHint
        currItem = stackView.replace("qrc:/qml/WelcomeButtonItem.qml")
        currItem.width = 30
        currItem.height = 30
        mainWindow.visible = true
        mainWindow.requestActivate()
    }

    function replaceAndShowItemAtPosition(itemUrl, xPos, yPos) {
        stackView.replace(itemUrl);
        var currItem = stackView.currentItem;
        currItem.x = xPos;
        currItem.y = yPos;
    }

}


