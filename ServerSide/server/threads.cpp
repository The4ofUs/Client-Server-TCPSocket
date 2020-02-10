#include "threads.h"
#include <QTime>
#include <QDir>
#include <QtWidgets>
#include "serverside.h"
threads::threads(int ID, QObject *parent):
    QThread(parent)
{  //the Descriptor is an index of that socket in an array of sockets from the underlying OS (more or less).
    this->socketDescriptor = ID;
    dataSize=0;
}

void  threads::run()
{
    // thread starts here
    /*As long as a new connection is here, a new thread is created for that connection,
      and by starting that thread, using thread->start, run function will be invoked,
      which is nothing but a virtual function that calls exec and provide us with further
      management*/
    qDebug() << socketDescriptor << " Starting Thread";
    socket = new QTcpSocket();

    if (!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }
   // connect(socket, SIGNAL(readyRead()),this, SLOT(readData()),Qt::DirectConnection);
    connect(socket, SIGNAL(readyRead()),this, SLOT(readArray()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()),Qt::DirectConnection);
    qDebug() << socketDescriptor << " Client Connected!";
    //creates a message loop which will make thread alive until we terminate it
    exec();

}



void threads::readyRead()
{
    /*ReadyRead signal is emitted when the thread had received some data and Now it's
    Ready to Read it, then we handle Reading this data using readyReady slot*/
    QByteArray Data = socket->readAll();
    qDebug() << socketDescriptor << "Data in: " << Data;
    //Handling the incoming Data
    //readData();
    readArray();
}

void threads::readArray(){
    if( dataSize == 0 )
    {

        QDataStream stream( socket );
        stream.setVersion( QDataStream::Qt_5_9 );

        if( socket->bytesAvailable() < sizeof(qint32) )
            return;
        qDebug()<<socket->bytesAvailable();
        stream >> dataSize;
    }

    if( dataSize > socket->bytesAvailable() )
        return;

    QByteArray array = socket->read( dataSize );
    qDebug("I am reading");
    qDebug()<<array.size();

    float x;
    x=array.toFloat();
    qDebug("x");
    qDebug()<<x;
    float y=array.at(1);
    qDebug()<<y;
/*
    for(int i=0; i<=array.size();i++){
        y=(float)array.at(i);
        qDebug()<<x;

    }*/
    //P.S. to construct a vector of vectors, we create a small vector then push the results to the 2D vector

   // vector<vector<int>> v;

    //QBuffer buffer(&array);
    //buffer.open( QIODevice::ReadOnly );


}
void threads::readData(){
    qDebug("Ready Read is Ready");
    if( dataSize == 0 )
    {

        QDataStream stream( socket );
        stream.setVersion( QDataStream::Qt_5_9 );

        if( socket->bytesAvailable() < sizeof(qint32) )
            return;
        qDebug("bytes avialble");
        qDebug()<<socket->bytesAvailable();
        stream >> dataSize;
    }

    if( dataSize > socket->bytesAvailable() )
        return;

    QByteArray array = socket->read( dataSize );
    QBuffer buffer(&array);
    buffer.open( QIODevice::ReadOnly );

    QImageReader reader(&buffer, "PNG");
    image = reader.read();

    if( !image.isNull() )
    {
        qDebug("Image is received by the thread");
    }

}


QImage threads::sendImage()
{
    return image;
}


void threads::disconnected()
{

    qDebug() << socketDescriptor << "Disconnected";
    socket->deleteLater();
    // closing thread
    exit(0);
}


