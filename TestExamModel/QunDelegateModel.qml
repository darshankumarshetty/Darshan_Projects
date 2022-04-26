import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

    Rectangle{
        id:r1
        signal clickMe();
        width: 120;
        height:120;
        gradient: Gradient {
            GradientStop { position: 0.0; color: "Blue" }
            GradientStop { position: 0.33; color: "Light blue" }
            GradientStop { position: 1.0; color: "purple" }
        }

        ColumnLayout{
            Text {
                id: tx1
                text:list.name+"Question"+(index+1)
            }
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                clickMe();
            }
        }
    }
