import QtQuick 2.0

    Rectangle {
        color: "#4e4e4e"
        //radius: 10

        StyledTextEditItem {
            objectName: "textArea"
            anchors.fill: parent
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            text: "some text"
            //wrapMode: TextEdit.WordWrap
        }

    }
