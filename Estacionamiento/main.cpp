#include "estacionamiento.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Estacionamiento w;
    w.show();

    return a.exec();
}
