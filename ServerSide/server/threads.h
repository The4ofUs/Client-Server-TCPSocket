#ifndef THREADS_H
#define THREADS_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QtDebug>
#include <QWidget>

class threads : public QThread
{
    Q_OBJECT
public:
    explicit threads(int ID, QObject *parent = nullptr);
    void run();
    void sendData();
    QImage image;
    QImage sendImage();

signals:
    void error(QTcpSocket::SocketError socketerror);


public slots:
    void readyRead(); // from QIOObject
    void disconnected();
    void readData();
    void readArray();


private:
    QImage randomImage();

    QTcpSocket *socket;
    int socketDescriptor; // the underlying socket ID number from the operating system
    int dataSize;

};

#endif // THREADS_H
