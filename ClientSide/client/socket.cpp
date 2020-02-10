#include "socket.h"
#include <QBuffer>
#include <QDataStream>
#include <QTcpSocket>
#include <QImageReader>
#include <QWidget>
#include <QImageWriter>
#include <QTime>
#include <QDir>
#include <iostream>   // std::cout
#include <string>
socket::socket(QObject *parent) : QObject(parent)
{

}

void socket::createSocket()
{

    newSocket = new QTcpSocket(this);
    connect(newSocket,SIGNAL(connected()),this,SLOT(connected()));
    connect(newSocket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(newSocket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(newSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));
    qDebug ()<< "Connecting .....";
    //establish connection
    newSocket->abort();
    newSocket->connectToHost(QHostAddress::LocalHost, 4567);
    //check if it's really connected
    if(!newSocket->waitForConnected(1000))
    {
        qDebug() <<"Error: " << newSocket->errorString();
    }
    dataSize=0;


}
void socket::connected()
{
    qDebug() <<"Connected!";
    //sendData();
    sendArray();
    state=true;
}
bool socket::isConnected(){
    return state;
}

void socket::sendArray(){
    //Creating a Buffer to hold my data
    //creating a Buffer to hold my array
    QByteArray array;
    QBuffer buffer(&array);
    buffer.open(QIODevice::WriteOnly);
    qint32 x=17.36;

    //y=x;
    // buffer.write((char *)&x,sizeof(qint32));
    // array.append((char *)&x,sizeof(qint32));
    //array.append((char *)&y,sizeof(double));
    //array.append((char *)&y,sizeof(double));
    array.append("50.45");
    qDebug()<<"Buffer bytes "<<buffer.bytesAvailable();
    std::string temp=array.toStdString();
    float y=std::stof(temp);
    qDebug()<<"y"<<y;
    qDebug()<<"array size"<< array.size();
    qDebug()<<"array at"<<array.at(0);

    qDebug()<<"buffer size"<<buffer.size();
    buffer.close();

    QByteArray data;
    QDataStream stream( &data, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );
    stream << (quint32)buffer.data().size();
    data.append( buffer.data() );
    newSocket->write( data );
    qDebug() <<"data;;"<< data;
    newSocket->disconnectFromHost();
    newSocket->waitForDisconnected();

}


void socket::sendData(){
    //new Buffer to carry the image to the
    QBuffer buffer;
    QImageWriter writer(&buffer, "PNG");
    writer.write( randomImage() );
    //the data been sent has to be a byteArray, so na "BA7ml" el data mn el buffer lel stream ele hwa data no3ha byteArray
    QByteArray data;
    QDataStream stream( &data, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );
    stream << (quint32)buffer.data().size();
    qDebug()<<(quint32)buffer.data().size();
    data.append( buffer.data() );

    newSocket->write( data );
    //qDebug() <<"data;;"<< data;
    newSocket->disconnectFromHost();
    newSocket->waitForDisconnected();
}
void socket::disconnected()
{
    qDebug() <<"Disconnected!";

}
void socket::readyRead()
{
    qDebug() << "Reading ...";
}



void socket::bytesWritten(qint64 bytes)
{
    qDebug() <<"We wrote" << bytes; // tells number of bites we wrote

}

//Returns a Random Image
QImage socket::randomImage()
{

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QDir dir("/home/eman/Client-Server-C-/GP/ServerSide/server/images");
    if(dir.exists()){
        qDebug("dir is found");
    }
    else
    {
        qDebug("dir is not found");

    }
    dir.setFilter( QDir::Files );
    QFileInfoList entries = dir.entryInfoList();

    if( entries.size() == 0 )
    {
        qDebug( "No images to show!" );
        return QImage();
    }
    else{
        qDebug("there is image");
    }

    return QImage( entries.at( qrand() % entries.size() ).absoluteFilePath() );

}
