import QtQuick 2.9
import QtQuick.Controls 2.2

import Languages 1.0

    ComboBox {
        //model: ["English", "French", "Russian"]
        model: LangsListModel {
            id: cbItems
        }
        textRole: model.name
       // delegate: Text {
       //     text: model.name
       // }
       //activated: console.log("element was chosen")
    }


