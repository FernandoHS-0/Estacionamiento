#include "usuario.h"
#include "ui_usuario.h"
#include <QMessageBox>

Usuario::Usuario(bool *perm,Usua * ses, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usuario)
{

    ui->setupUi(this);
    sesionUsuario= ses;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setUserName("root");
    db.setDatabaseName("ParkingALot");
    bool * p= new bool{true};
    perm=p;
    QSqlQuery LugarOcupado;
    QSqlQuery LugarOcupado2;
    QSqlQuery Entrada;
    int id=ses->getid();
    qDebug()<< id;
    db.open();

    QTime EntradaR = QTime::currentTime();


    LugarOcupado2.prepare("SELECT ESPACIO.ESTADO FROM ESPACIO INNER JOIN RESERVACIONUNICA ON ESPACIO.NoEspacio = RESERVACIONUNICA.NoEspacio where RESERVACIONUNICA.IdUsuario=:noC;");
    LugarOcupado2.bindValue(":noC",id);
    LugarOcupado2.exec();
    LugarOcupado2.next();
    QString Permiso=LugarOcupado2.value(0).toString();
    qDebug()<<Permiso;
        if(Permiso=="Libre"){  
            ui->Aceptar->setVisible(true);
            ui->pushButton_3->setVisible(false);
        }
            else{
            ui->Aceptar->setVisible(false);
            ui->pushButton_3->setVisible(true);
}
        //query para sacar el id de la res.

    Entrada.prepare("UPDATE reservacionunica SET HoraEntradaReal=:HER WHERE IdUsuario=:noC");
    Entrada.bindValue(":noC",id);
    Entrada.bindValue(":HER",EntradaR);
    Entrada.exec();

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

void Usuario::on_pushButton_3_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setUserName("root");
    db.setDatabaseName("ParkingALot");
    db.open();
    int id=sesionUsuario->getid();
    QSqlQuery Salida;
    QSqlQuery LugarLibre;
    QTime SalidaR = QTime::currentTime();
    QDate Hoy = QDate::currentDate();
    qDebug() << SalidaR;
    qDebug() << Hoy;
    QTime EntradaR = QTime::currentTime();
    QSqlQuery HoraEntrada;
    HoraEntrada.prepare("select r.HoraEntrada, r.HoraSalida, e.idPiso,e.NoEspacio,t.Descripcion,t.Monto FROM Reservacionunica as r inner join espacio as e on r.NoEspacio=e.NoEspacio inner join Tarifa as t on r.idTarifa=t.idTarifa  where r.idUsuario=:noC;");
    HoraEntrada.bindValue(":noC",id);
    HoraEntrada.exec();
    QTime EntradaS = HoraEntrada.value(2).toTime();
    int Monto=HoraEntrada.value(6).toInt();

    if(EntradaR>EntradaS){
        qDebug() << "Sientroalcondicional";
        int TiempoExtra= EntradaS.secsTo(EntradaR);
        int CobroExtra=(TiempoExtra/60)*10;
        int NuevoMonto=CobroExtra+Monto;

        QSqlQuery NuevoCobro;
        NuevoCobro.prepare("UPDATE Tarifa SET Monto=:NM WHERE  idUsuario=:noC && Fecha=:Fe;");
        NuevoCobro.bindValue(":noC",id);
        NuevoCobro.bindValue(":NM",NuevoMonto);
        NuevoCobro.bindValue(":Fe",Hoy);
        NuevoCobro.exec();


        QMessageBox SalidaExcedida;
        SalidaExcedida.setText("Ha excedido su tiempo de estancia en el estacionamiento, se le cobrará una multade $");
        SalidaExcedida.setIcon(QMessageBox::Warning);
        QAbstractButton * btnSi = SalidaExcedida.addButton(tr("Confirmar"), QMessageBox::YesRole);
        SalidaExcedida.exec();
    }
    Salida.prepare("UPDATE reservacionunica SET HoraSalidaReal=:HSR WHERE  idUsuario=:noC && Fecha=:Fe;");
    Salida.bindValue(":noC",id);
    Salida.bindValue(":HSR",SalidaR);
    Salida.bindValue(":Fe",Hoy);
    Salida.exec();
    db.close();
    close();

}
