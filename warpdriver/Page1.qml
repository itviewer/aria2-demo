import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Item {

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: textField1
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button1
            text: qsTr("开始")
            onClicked: {
//                drive.addUri([["http://mirrors.163.com/centos/7/isos/x86_64/CentOS-7-x86_64-Minimal-1708.iso"]],function(r){
//                    console.log(r)
//                })
                drive.unpause(["d0dfa318be6ecc59"],function(r){
                    console.log(JSON.stringify(r))
                })
            }
        }

        Button {
            id: button2
            text: qsTr("暂停")
            onClicked: {
//                drive.addUri([["http://mirrors.163.com/centos/7/isos/x86_64/CentOS-7-x86_64-Minimal-1708.iso"]],function(r){
//                    console.log(r)
//                })
                drive.pause("d0dfa318be6ecc59",function(r){
                    console.log(JSON.stringify(r))
                })
            }
        }
    }
}
