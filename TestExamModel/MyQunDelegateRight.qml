import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
    Rectangle{
        id:rec
        height: win.height
        width: win.width-520;
        color: "blue"
        ColumnLayout{
            spacing: 5
            Label{
                id:lb1
                text:questions
            }
            RadioButton{
                id:rb1
                text:option1
            }
            RadioButton{
                id:rb2
                text:option2
            }
            RadioButton{
                id:rb3
                text:option3
            }
            RadioButton{
                id:rb4
                text:option4
            }
            Button{
                id:b1
                text: "Submit"
            }
        }
    }

