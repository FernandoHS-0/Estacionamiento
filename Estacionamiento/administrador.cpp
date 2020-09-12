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
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setUserName("root");
    db.setDatabaseName("Parking-A-Lot");

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
        }else{
            qDebug() << "Comentarios no cargados";
        }

    }
        ui->stackedWidget->setCurrentIndex(2);
}

void Administrador::on_btnSalir_clicked()
{
    close();
}


