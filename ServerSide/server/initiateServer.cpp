#include "initiateServer.h"
initiateServer::initiateServer(QObject *parent) :  QTcpServer(parent)
{
}


void initiateServer::StartServer()
{

    if(!this->listen(QHostAddress::Any, 4567))
    {
        qDebug() << "Couldn't Start Server";

    }
    else
    {
        qDebug() << "Listening .....";

    }

}

// Incoming Connection is a  Function, which gets invoked each time a new Connection comes
void initiateServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << "connecting ...";
    /*initiate a new thread every time a new connection is here, and by then
      all of the threads signals, run for e.g, are being invoked
     */
    threads *thread = new threads(socketDescriptor,this);
    //when the thread is no longer used, it will be deleted
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
    qDebug()<<socketDescriptor;
    Descriptor= socketDescriptor;
    /*As long as  the thread is Running the emitSignal will be emitted to notify the UI,
     that there is an upcoming Data need to be displayed*/
    while (thread->isRunning()){
        qDebug("Thread is Running");
        imagee=thread->sendImage();
        emitSinal();
    }
}


int initiateServer::sendDescriptor(){
    return Descriptor;
}
QImage initiateServer::imagesending(){

    return imagee;
}


