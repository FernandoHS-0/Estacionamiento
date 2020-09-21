#include "estacionamiento.h"
#include "ui_estacionamiento.h"
#include "administrador.h"
#include "objetos.h"
#include "usuario.h"
Estacionamiento::Estacionamiento(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estacionamiento)
{
    ui->setupUi(this);
    dbconexion = QSqlDatabase::addDatabase("QODBC");
    dbconexion.setUserName("root");
    dbconexion.setDatabaseName("ParkingALot");
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
    int numCliente= ui->txtNoCliente->text().toInt();
        QSqlQuery sesionCliente;
        dbconexion.open();
        sesionCliente.prepare("Select idUsuario FROM cliente where IdUsuario = :noC;");
        sesionCliente.bindValue(":noC",numCliente);
        sesionCliente.exec();
        while(sesionCliente.next())
        {
        if(sesionCliente.value(0).toInt() ==numCliente)
            {
            Usua ses(sesionCliente.value(0).toInt());
            Usuario ventana(&ses);
            ventana.setModal(true);
            ventana.exec();

            }
        }

}
