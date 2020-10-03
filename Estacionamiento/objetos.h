#ifndef OBJETOS_H
#define OBJETOS_H
#include <QString>
#include <QDate>
#include <QTime>


class objetos
{
public:
    objetos();
};

class admin{
public:
    admin();
    admin(int);
    int idAdmin;
};

class Usua{
public:
    Usua();
    Usua(int);
    int getid();
    int idUsuario;
};

class lugares{
public:
    int noEspacio, idPiso;
    QString estado;
    lugares();
    lugares(int, int, QString);
};

class reservaciones{
public:
    int noReservacion, idTarifa, idPago, NoEspacio, idUsuario;
    QDate fecha;
    QTime horallegada, horaSalida;
    reservaciones();
    reservaciones(int, int, int, int, int, QDate, QTime, QTime);
};

#endif // OBJETOS_H
