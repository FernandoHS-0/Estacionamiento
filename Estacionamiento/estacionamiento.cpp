#include "estacionamiento.h"
#include "ui_estacionamiento.h"

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
    Administrador vent;
    vent.setModal(true);
    vent.exec();
}

void Estacionamiento::on_btnAcceder_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Estacionamiento::on_accederEst_clicked()
{
    int numCliente= ui->txtNoCliente->text().toInt();
    dbconexion.open();
    QSqlQuery sesionCliente;
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
    dbconexion.close();
}
