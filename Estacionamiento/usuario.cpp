#include "usuario.h"
#include "ui_usuario.h"

Usuario::Usuario(Usua * ses,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usuario)
{
    ui->setupUi(this);
    sesionUsuario= ses;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setUserName("root");
    db.setDatabaseName("ParkingALot");

    QSqlQuery LugarOcupado;
    int id=ses->getid();
    qDebug()<< id;
    db.open();
    LugarOcupado.prepare("UPDATE ESPACIO INNER JOIN RESERVACIONUNICA ON ESPACIO.NoEspacio = RESERVACIONUNICA.NoEspacio SET ESTADO = 'OCUPADO' where RESERVACIONUNICA.IdUsuario=:noC;");
    LugarOcupado.bindValue(":noC",id);
    LugarOcupado.exec();
    db.close();

    // query para obtener las horas de entra y salida de la reservacion
    db.open();
    QSqlQuery Horas;
    Horas.prepare("select r.HoraEntrada, r.HoraSalida, e.idPiso,e.NoEspacio,t.Descripcion,t.Monto FROM Reservacionunica as r inner join espacio as e on r.NoEspacio=e.NoEspacio inner join Tarifa as t on r.idTarifa=t.idTarifa  where r.idUsuario=:noC;");

    Horas.bindValue(":noC",id);
    Horas.exec();
    while(Horas.next()){
    QString TipoTarifa = Horas.value(4).toString();
    int Piso= Horas.value(2).toInt();
    int espacio = Horas.value(3).toInt();
    QTime llegada = Horas.value(0).toTime();
    QTime salida = Horas.value(1).toTime();
    int monto = Horas.value(5).toInt();
// asignación de los valores obtenidos

    ui->TiempoLLegada->setTime(llegada);
    ui->TiempoSalida->setTime(salida);
    ui->Piso->setNum(Piso);
    ui->TipoTarifa->setText(TipoTarifa);
    ui->NumeroEspacio->setNum(espacio);
    ui->Pago->setNum(monto);
    }
    db.close();
}

Usuario::~Usuario()
{
    delete ui;
}


void Usuario::on_Aceptar_clicked()
{
    close();
}
