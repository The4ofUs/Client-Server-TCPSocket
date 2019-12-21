#include "clientside.h"
#include "ui_clientside.h"
#include "socket.h"
#include <QString>
#include <QFileDialog>
ClientSide::ClientSide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientSide)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(createSocket()));

}



void ClientSide::createSocket(){
    newSocket=new socket();
    newSocket->createSocket();
    if (newSocket->isConnected()){
        ui->label_2->setText("Sending Random Image");
    }
    else {
        ui->label_2->setText("Connection refused");
    }

}

ClientSide::~ClientSide()
{
    delete ui;
}
