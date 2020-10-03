#include "estacionamiento.h"
#include "ui_estacionamiento.h"
#include "administrador.h"
#include "usuario.h"
#include "objetos.h"
#include <ctime>
#include <QMessageBox>
#include <QPrinter>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
Estacionamiento::Estacionamiento(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Estacionamiento)
{
    ui->setupUi(this);
    dbconexion = QSqlDatabase::addDatabase("QODBC");
    dbconexion.setUserName("root");
    dbconexion.setDatabaseName("ParkingALot");

    if(dbconexion.open()){
        QSqlQuery lugares;
        lugares.exec("SELECT NoEspacio, idPiso, Estado FROM Espacio;");
        while (lugares.next()) {
            int nEsp = lugares.value(0).toInt(),
                idP = lugares.value(1).toInt();
            QString est = lugares.value(2).toString();
            class lugares espacio(nEsp, idP, est);
            espacios.append(espacio);
        }

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
    QMessageBox preg;
    preg.setText("Su tiempo de tolerancia ha sido excedido ¿Desea que se le asigne otro lugar disponible?");
    QMessageBox sinespacio;
    sinespacio.setText("Lamentamos los inconvenientes pero su lugar está ocupado ¿Qué desea hacer?");

    preg.setIcon(QMessageBox::Warning);
    preg.setWindowTitle("Advertencia");
    sinespacio.setIcon(QMessageBox::Warning);

    QAbstractButton * btnSi = preg.addButton("Si", QMessageBox::YesRole);
    QAbstractButton * btnNo = preg.addButton("No", QMessageBox::NoRole);

    QAbstractButton * btnvale = sinespacio.addButton("VALE", QMessageBox::YesRole);
    QAbstractButton * btnbucar = sinespacio.addButton("BUSCAR NUEVO LUGAR", QMessageBox::NoRole);


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
                    if(agenda[i].fecha == diaAct){
                        if( Prueba == agenda[i].horallegada || Prueba <= agenda[i].horallegada.addSecs(900)){
                            QSqlQuery LugarOcupado;
                            LugarOcupado.prepare("SELECT ESPACIO.ESTADO FROM ESPACIO INNER JOIN RESERVACIONUNICA ON ESPACIO.NoEspacio = RESERVACIONUNICA.NoEspacio where RESERVACIONUNICA.IdUsuario=:noC;");
                            LugarOcupado.bindValue(":noC",numCliente);
                            LugarOcupado.exec();
                            LugarOcupado.next();
                            QString result=LugarOcupado.value(0).toString();
                            qDebug()<<result;
                            if(result=="Libre"){
                                Usua ses(sesionCliente.value(0).toInt());
                                Usuario ventana(&ses);
                                ventana.setModal(true);
                                ventana.exec();
                            }else{
                                sinespacio.exec();
                                if(sinespacio.clickedButton()==btnvale){
                                    QSqlQuery nombre;
                                    nombre.prepare("SELECT NOMBRE,ApellidoP,ApellidoM FROM USUARIO WHERE IdUsuario=:noC;");
                                    nombre.bindValue(":noC",numCliente);
                                    nombre.exec();
                                    nombre.next();
                                    QString Nombre=nombre.value(0).toString();
                                    QString ApellidoP=nombre.value(1).toString();
                                    QString ApellidoM=nombre.value(2).toString();
                                    QString html =
                                    "<img class='imageLeft' src='C:/Users/luisd/Desktop/universidad/QT/Estacionamiento/Estacionamiento/img/park_b.png' alt='Ed' width='100' height='100'/><strong>"
                                    "<h1 style='text-align: center';>VALE</h1>"
                                    "<hr />"
                                    "<h4 style='text-align: left';>A la orden de: "+ApellidoP+" "+ApellidoM+" "+Nombre+"</h4>"
                                    "<h4>Por la suma de: La devolución de su dinero</h4>"
                                    "<h4>Por concepto de: Inconvenientes en la reservación </h4>"
                                    "<blockquote>"
                                    "<p>PUEBLA,"+QDate::currentDate().toString() +"</p>"
                                    "</blockquote>"
                                    "<p style='text-align: right';>&nbsp; &nbsp; &nbsp;<img class='imageLeft' src='C:/Users/luisd/Desktop/universidad/QT/Estacionamiento/Estacionamiento/img/firma.png' alt='Ed' width='50' height='50'/>&nbsp; &nbsp; &nbsp;</p>"
                                    "<p style='text-align: right';>_________________</p>"
                                    "<p style='text-align: right';>PARK -A- LOT&nbsp; &nbsp; &nbsp; &nbsp;</p>"
                                    "<hr />"
                                    "<p style='text-align: left';></p>";

                                    QTextDocument document;
                                    document.setHtml(html);

                                    QPrinter printer(QPrinter::PrinterResolution);
                                    printer.setOutputFormat(QPrinter::PdfFormat);
                                    printer.setPaperSize(QPrinter::A4);
                                    printer.setOutputFileName("/tmp/vale.pdf");
                                    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                                    document.print(&printer);
                                    QDesktopServices::openUrl(QUrl::fromLocalFile("/tmp/vale.pdf"));

                                }
                            }
                        }else{
                            preg.exec();
                            if(preg.clickedButton() == btnSi){
                                for (int j=15; j<espacios.length(); j++){
                                    if(espacios[j].estado == "Libre"){
                                        QSqlQuery actualizar;
                                        actualizar.prepare("UPDATE ReservacionUnica SET NoEspacio = :newNo WHERE IdReservacionUnica = :idRu");
                                        actualizar.bindValue(":newNo", espacios[j].noEspacio);
                                        actualizar.bindValue(":idRu", agenda[i].noReservacion);
                                        if(actualizar.exec()){
                                            Usua ses(sesionCliente.value(0).toInt());
                                            Usuario ventana(&ses);
                                            ventana.setModal(true);
                                            ventana.exec();
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }else{
                    QMessageBox sinRes;
                    sinRes.setText("Usted no cuenta con ninguna reservación ¿Desea buscar un lugar en el primer piso?");
                    sinRes.setIcon(QMessageBox::Warning);
                    sinRes.setWindowTitle("Atención");
                    QAbstractButton * btnAcept = sinRes.addButton("Si", QMessageBox::YesRole);
                    QAbstractButton * btnCanc = sinRes.addButton("No", QMessageBox::NoRole);
                    sinRes.exec();
                    if(sinRes.clickedButton() == btnAcept){
                        //Llamar a ventana para seleccionar lugar
                        //Usua sesC(sesionCliente.value(0).toInt());
                        Usua sesC(sesionCliente.value(0).toInt());
                        segV = new Lugares(&sesC, this);
                        segV->exec();
                        break;
                    }
                }
            }
        }
    }
}
