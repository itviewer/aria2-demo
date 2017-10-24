#include "widget.h"
#include "ui_widget.h"
#include "warpdrive.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    WarpDrive *drive = new WarpDrive(this);
    drive->setToken("myrpc");

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        if(drive->isConnected()){
            QVariantList params;
            QStringList url;
            url << "http://mirrors.ustc.edu.cn/centos/7.4.1708/isos/x86_64/CentOS-7-x86_64-Minimal-1708.iso";

//            url << "https://github.com/aria2/aria2/releases/download/release-1.33.0/aria2-1.33.0-win-64bit-build1.zip";
            params << url;

            drive->listMethods([](const QVariant &result){
                qDebug() << result ;
            });
        }
    });

//    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
//        if(drive->isConnected()){
//            drive->listMethods(std::bind(&Widget::test,this,std::placeholders::_1));
//        }
//    });

    drive->connectToServer(QUrl("ws://localhost:6800/jsonrpc"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::test(const QVariant &result)
{
    qDebug() << result ;
}
