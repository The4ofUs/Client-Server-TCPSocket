#ifndef INITIATESERVER_H
#define INITIATESERVER_H

#include <QObject>
#include <QTcpServer>
#include<QDebug>
#include "threads.h"

class initiateServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit initiateServer(QObject *parent = nullptr);
    void StartServer();
    QImage imagee;
    QImage imagesending();
    int Descriptor;
    int sendDescriptor();

signals:
    void emitSinal();
public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

};

#endif // INITIATESERVER_H
