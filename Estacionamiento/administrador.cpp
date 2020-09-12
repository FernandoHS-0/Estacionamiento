#include "administrador.h"
#include "ui_administrador.h"

Administrador::Administrador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrador)
{
    ui->setupUi(this);
    QStringList titulos;
    ui->tablacomentarios->setColumnCount(3);
    titulos << "Folio" << "Descripcion" << "Fecha" ;
    ui->tablacomentarios->setHorizontalHeaderLabels(titulos);

    db = QSqlDatabase::addDatabase("QODBC");
    db.setUserName("root");
    db.setDatabaseName("ParkingALot");

    if(db.open()){
        QSqlQuery comentarios;
        QSqlQuery id;

        if(comentarios.exec("SELECT Folio, Descripcion, Fecha FROM comentarios;")){
            while(comentarios.next()){
                QString fol = comentarios.value(0).toString();
                QString des = comentarios.value(1).toString();
                QString fec = comentarios.value(2).toString();

            ui->tablacomentarios->insertRow(ui->tablacomentarios->rowCount());
            ui->tablacomentarios->setItem(ui->tablacomentarios->rowCount()-1,0,new QTableWidgetItem(fol));
             ui->tablacomentarios->setItem(ui->tablacomentarios->rowCount()-1,1,new QTableWidgetItem(des));
              ui->tablacomentarios->setItem(ui->tablacomentarios->rowCount()-1,2,new QTableWidgetItem(fec));

            }
        }
    }

     QSqlQuery Tarifas;
     if(Tarifas.exec("Select Descripcion , Monto from Tarifa where idTarifa = 1 ;")){
            while(Tarifas.next()){
         QString Descripcion=Tarifas.value(0).toString();
          QString monto =Tarifas.value(1).toString();

         ui->TarifaActual1->setText(monto);
         ui->TipoTarifa1->setText(Descripcion);
     }

            QSqlQuery Tarifas2;
            if(Tarifas2.exec("Select Descripcion , Monto from Tarifa where idTarifa = 2 ;")){
                   while(Tarifas2.next()){
                QString Descripcion2=Tarifas2.value(0).toString();
                 QString monto2 =Tarifas2.value(1).toString();

                ui->TarifaActual2->setText(monto2);
                ui->TipoTarifa2->setText(Descripcion2);
            }
     }


}
}

Administrador::~Administrador()
{
    delete ui;
}

void Administrador::on_btnTaridas_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Administrador::on_btnRegistros_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Administrador::on_btnComentarios_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void Administrador::on_btnSalir_clicked()
{
    close();
}



void Administrador::on_Acualizar1_clicked()
{
   db.open();
   float Nuevo= ui->NuevaTarifa1->value();
   QSqlQuery actu;
   actu.prepare("CALL CAMBIARTARIFAESTANDAR(1007,:NU);");
   actu.bindValue(":NU",Nuevo);
   actu.exec();

}

void Administrador::on_actualizar2_clicked()
{
    db.open();
    float Nuevo= ui->NuevaTarifa2->value();
    QSqlQuery actual;
    actual.prepare("CALL CAMBIATARIFAMENSUAL(1007,:NU);");
    actual.bindValue(":NU",Nuevo);
    actual.exec();
}
