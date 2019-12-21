#include "clientside.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientSide w;
    w.show();

    return a.exec();
}
