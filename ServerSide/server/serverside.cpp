#include "serverside.h"
#include "ui_serverside.h"
#include "initiateServer.h"
#include <QFileDialog>
#include <threads.h>
serverSide::serverSide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverSide)
{
    server=new initiateServer();
    ui->setupUi(this);
    connect(ui->listenButton,SIGNAL(released()),this,SLOT(startServer()));
    //emitSignal is being emiited as long as the thread is Running
    connect(server,SIGNAL(emitSinal()),this,SLOT(displayImage()));
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
}

void serverSide::startServer(){
    server->StartServer();
    ui->listenButton->setEnabled(false);
    ui->listenButton->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->listenButton->setText("Listening..");
    // QImage image =server->sendImage();

}

serverSide::~serverSide()
{
    delete ui;
}
void serverSide::newConnection(){
    int Descriptor=server->sendDescriptor();
    ui->listWidget->addItem("The connected descriptor is"+ QString::number(Descriptor));
}

void serverSide::displayImage()
{
    //Function imagesending returs the Image that was sent by the Client
    QImage image=server->imagesending();
    qDebug("The Image is Received by the server, Ready to be displayed on the UI");
    //qDebug ()<< image;
    ui->label_2->setPixmap(QPixmap::fromImage(image));
    ui->label_2-> setScaledContents(true);

}


