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

}

ClientSide::~ClientSide()
{
    delete ui;
}



