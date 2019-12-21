#ifndef CLIENTSIDE_H
#define CLIENTSIDE_H

#include <QMainWindow>
#include "socket.h"
namespace Ui {
class ClientSide;
}

class ClientSide : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientSide(QWidget *parent = 0);
    ~ClientSide();

private slots:
    void createSocket();
    void on_pushButton_2_clicked();
    void receiveImage();
private:
    Ui::ClientSide *ui;
    socket* newSocket;

};

#endif // CLIENTSIDE_H
