import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Window {
    id:win
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property var obj;
    Text {
        id: wintx
        font.pixelSize: 15
        anchors.right: parent.right
        anchors.rightMargin: 170
        anchors.verticalCenter: parent.verticalCenter
    }
    Timer{
        interval: 500
        repeat: false
        running: true
        onTriggered: {
            list.enabled=true
        }
    }

    Summary{
        visible: false
        id:sum
    }

    RowLayout{
        ListView{
            id:list1
            height: win.height
            width: win.width-520;
            spacing: 2
            model:ExModel
            delegate:ExamDelegate{
                id:sd
                onObjectofSub:{
                    list.visible=true
                    obj = ExModel.getQues(value)
                    console.log("Index: "+value)
                    list.name=subNm
                }
                onSubjectName:{
                    console.log("--------------"+sub)
                    sum.t14="Subject Name :"+subject
                }
            }
        }
        ListView{
            id:list
            property string name;
            height: win.height
            width: win.width-520;
            spacing: 2
            model:obj
            enabled: false
            visible: false
            delegate:QunDelegateModel{
                id:lw
                onClickMe:{
                    lw.visible=true
                    lb1.text = questions
                    rb1.text = option1
                    rb1.checked=false
                    rb2.text = option2
                    rb2.checked=false
                    rb3.text = option3
                    rb3.checked=false
                    rb4.text = option4
                    rb4.checked=false
                    r1.visible=true
                    b1.ind=index
                }
            }
            function checkMe (value){
                if(rb1.checked==true){
                    obj.userAns(value,"A")
                }
                if(rb2.checked==true){
                    obj.userAns(value,"B")
                }
                if(rb3.checked==true){
                    obj.userAns(value,"C")
                }
                if(rb4.checked==true){
                    obj.userAns(value,"D")
                }
            }
            function finish(){
                var Right=obj.right()
                var Wrong=obj.wrong()
                console.log("right"+Right)
                console.log("wrong"+Wrong)
                sum.t11="Right Answer :"+Right+"\nWrong Answer :"+Wrong
                sum.visible=true
                r1.visible=false
                list.visible=false
            }
        }
        Rectangle{
            id:r1
            visible: false
            width: win.width-120;
            height: win.height
            gradient: Gradient {
                GradientStop { position: 0.0; color: "pink" }
                GradientStop { position: 0.33; color: "lime" }
                GradientStop { position: 1.0; color: "red" }
            }
            ColumnLayout{
                spacing: 5
                Label{
                    id:lb1
                }
                RadioButton{
                    id:rb1
                }
                RadioButton{
                    id:rb2
                }
                RadioButton{
                    id:rb3
                }
                RadioButton{
                    id:rb4
                }
                RowLayout{
                    Button{
                        id:b1
                        text: "Submit"
                        property var ind;
                        onClicked: {
                            list.checkMe(ind)
                            rb1.checked=false
                            rb2.checked=false
                            rb3.checked=false
                            rb4.checked=false
                        }
                    }
                    Button{
                        id:b2
                        text: "Close All"
                        property  var right1;
                        property  var wrong1;
                        onClicked: {
                            list.finish()
                        }
                    }
                }
            }
        }
    }
}
