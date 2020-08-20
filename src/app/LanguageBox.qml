import QtQuick 2.9
import QtQuick.Controls 2.2

import Languages 1.0

    ComboBox {
        model: LangsListModel {
            id: cbItems
        }
        textRole: model.name

        //reduce size of drop-down (on default it has size of window)
        popup.contentItem.implicitHeight: Math.min(250, popup.contentItem.contentHeight);
    }


