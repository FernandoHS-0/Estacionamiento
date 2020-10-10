#include "usuario.h"
#include "ui_usuario.h"

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
        //query para sacar el id de la reservacion
    QTime EntradaR = QTime::currentTime();
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

    //haciendo mamadas pt1  (si funciono pero salio maupome de mamador)
    QStringList titulos;
    QString HoraEntrada;
    QString HoraSalida;

    HoraEntrada = llegada.toString();
    HoraSalida = salida.toString();


    ui->TablaComentarios->setColumnCount(2);
    titulos << "Hora Entrada" << "Hora Salida";
    ui->TablaComentarios->setHorizontalHeaderLabels(titulos);

    ui->TablaComentarios->insertRow(ui->TablaComentarios->rowCount());
    ui->TablaComentarios->setItem(ui->TablaComentarios->rowCount()-1,0,new QTableWidgetItem(HoraEntrada));
    ui->TablaComentarios->setItem(ui->TablaComentarios->rowCount()-1,1,new QTableWidgetItem(HoraSalida));


    }
    db.close();

    //a partir de aqui va el codigo para meter las notificaciones (jalo pero mas arriba)

/*
    QStringList titulos;
    QString HoraEntrada;
    QString HoraSalida;


    ui->TablaComentarios->setColumnCount(2);
    titulos << "Hora Entrada" << "Hora Salida";
    ui->TablaComentarios->setHorizontalHeaderLabels(titulos);

*/
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
    Salida.prepare("UPDATE reservacionunica SET HoraSalidaReal=:HSR WHERE  idUsuario=:noC && Fecha=:Fe;");
    Salida.bindValue(":noC",id);
    Salida.bindValue(":HSR",SalidaR);
    Salida.bindValue(":Fe",Hoy);
    Salida.exec();
    db.close();
    close();

}

void Usuario::on_pushButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}
