#include "lugares.h"
#include "ui_lugares.h"
#include <QMessageBox>

Lugares::Lugares(Usua *sC, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lugares)
{
    ui->setupUi(this);
    //sesCliente = sC;
    sesCliente = sC;
    dbconexion = QSqlDatabase::addDatabase("QODBC");
    dbconexion.setUserName("root");
    dbconexion.setDatabaseName("ParkingALot");
    QTime horaR = QTime::currentTime();
    QTime horaTr(horaR.hour(), horaR.minute());
    ui->timeLlegada->setTime(horaTr);
}

Lugares::~Lugares()
{
    delete ui;
}

void Lugares::on_espacio01_clicked()
{
    QMessageBox confirm;
    confirm.setText("Confirmar su lugar de reservaciÃ³n");
    confirm.setIcon(QMessageBox::Information);
    QAbstractButton * btnConf = confirm.addButton("Confirmar", QMessageBox::YesRole);
    QAbstractButton * btnCanc = confirm.addButton("Cancelar", QMessageBox::NoRole);

    QMessageBox succ;
    succ.setText("ReserverciÃ³n completada");
    QAbstractButton * btnAccept = succ.addButton("Aceptar", QMessageBox::AcceptRole);
    succ.setIcon(QMessageBox::Information);
    succ.setWindowTitle("Confirmado");
    ui->espacio01->setStyleSheet("QPushButton{border-top: 2px solid #ff2747;border-right: 2px solid #ff2747;border-left: 2px solid #ff2747;border-bottom: none;background-color: white;}");
    confirm.exec();
    if(confirm.clickedButton()==btnConf){
        dbconexion.open();
        QSqlQuery reservar;
        reservar.prepare("INSERT INTO LugarSinReservacion SET idTarifa = (SELECT idTarifa FROM tarifa WHERE idTarifa = 1), NoEspacio = (SELECT NoEspacio FROM Espacio WHERE NoEspacio = 1), idPago = null, idUsuario = (SELECT idUsuario FROM cliente WHERE idUsuario = :idU), Horallegada = :HLL, HoraSalida = :HSal, Fecha = :DTE;");
        reservar.bindValue(":idU", sesCliente->idUsuario);
        reservar.bindValue(":HLL", ui->timeLlegada->time());
        reservar.bindValue(":HSal", ui->timeSalida->time());
        reservar.bindValue(":DTE", QDate::currentDate());
        if(reservar.exec()){
            succ.exec();
        }
    }else if(confirm.clickedButton()==btnCanc){
        ui->espacio01->setStyleSheet("QPushButton{border-top: 2px solid #A1C1E6;border-right: 2px solid #A1C1E6;border-left: 2px solid #A1C1E6;border-bottom: none;background-color: white;}");
    }
}

/*QPushButton{
    border-top: 2px solid #A1C1E6;
    border-right: 2px solid #A1C1E6;
    border-left: 2px solid #A1C1E6;
    border-bottom: none;
    background-color: white;
}*/

void Lugares::on_btnCancelar_clicked()
{
    this->close();

}
