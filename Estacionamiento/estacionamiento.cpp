#include "estacionamiento.h"
#include "ui_estacionamiento.h"
#include "administrador.h"
#include "usuario.h"
#include "objetos.h"
#include <ctime>
Estacionamiento::Estacionamiento(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estacionamiento)
{
    ui->setupUi(this);
    dbconexion = QSqlDatabase::addDatabase("QODBC");
    dbconexion.setUserName("root");
    dbconexion.setDatabaseName("ParkingALot");

    if(dbconexion.open()){
       /* QSqlQuery lugares;
        lugares.exec("SELECT NoEspacio, idPiso, Estado FROM Espacio;");
        while (lugares.next()) {
            int nEsp = lugares.value(0).toInt(),
                idP = lugares.value(1).toInt();
            QString est = lugares.value(2).toString();
            class lugares espacio(nEsp, idP, est);
            espacios.append(espacio);
        }*/

        QSqlQuery reser;
        reser.exec("SELECT * FROM reservacionUnica;");
        while(reser.next()){
            int idRu = reser.value(0).toInt(),
                idT = reser.value(1).toInt(),
                idP = reser.value(2).toInt(),
                noE = reser.value(3).toInt(),
                idU = reser.value(4).toInt();
            QDate fech = reser.value(5).toDate();
            QTime hLl = reser.value(6).toTime(),
                  hSa = reser.value(7).toTime();
            reservaciones fecha(idRu, idT, idP, noE, idU, fech, hLl, hSa);
            agenda.append(fecha);
        }
        dbconexion.close();
    }
}

Estacionamiento::~Estacionamiento()
{
    delete ui;
}

void Estacionamiento::on_btnIngresar_clicked()
{
    int noCliente = ui->txtAdmin->text().toInt();
    QString pass = ui->txtPswrd->text();
    QSqlQuery sesion;
    dbconexion.open();
    sesion.prepare("SELECT Contrasena, IdUsuario FROM Administrador WHERE IdUsuario = :noC AND Contrasena = :pswd;");
    sesion.bindValue(":noC", noCliente);
    sesion.bindValue(":pswd", pass);
    sesion.exec();
    while (sesion.next()) {
        if(sesion.value(0).toString() == pass && sesion.value(1).toInt() == noCliente){
            admin ses(sesion.value(1).toInt());
            Administrador vent(&ses);
            vent.setModal(true);
            vent.exec();
        }
    }
}

void Estacionamiento::on_btnAcceder_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Estacionamiento::on_accederEst_clicked()
{
    QTime horaAct = QTime::currentTime();
    QTime Prueba(horaAct.hour(),horaAct.minute());
    QDate diaAct = QDate::currentDate();
    int numCliente= ui->txtNoCliente->text().toInt();
        QSqlQuery sesionCliente;
        dbconexion.open();
        sesionCliente.prepare("Select idUsuario FROM cliente where IdUsuario = :noC;");
        sesionCliente.bindValue(":noC",numCliente);
        sesionCliente.exec();

        while(sesionCliente.next()){
            if(sesionCliente.value(0).toInt() == numCliente){
                for(int i=0; i<agenda.length(); i++){
                    if(numCliente == agenda[i].idUsuario){
                        qDebug() << "Reservacion encontrada";
                        if(agenda[i].fecha == diaAct){
                            qDebug() << "Fecha hoy encontrada";
                            if(agenda[i].horallegada == Prueba){
                                qDebug() << "Hora actual encontrada";
                                Usua ses(sesionCliente.value(0).toInt());
                                Usuario ventana(&ses);
                                ventana.setModal(true);
                                ventana.exec();
                            }
                        }
                    }
                }


            }
        }

}
