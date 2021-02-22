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
        lugares.prepare("SELECT NoEspacio, idPiso, Estado FROM Espacio;");
        lugares.exec();
        while (lugares.next()) {
            int nEsp = lugares.value(0).toInt(),
                idP = lugares.value(1).toInt();
            QString est = lugares.value(2).toString();
            class lugares espacio(nEsp, idP, est);
            espacios.append(espacio);
        }

        QSqlQuery reser;
        reser.prepare("SELECT * FROM reservacionUnica;");
        reser.exec();
        while(reser.next()){
            int idRu = reser.value(0).toInt(),
                idT = reser.value(1).toInt(),
                idP = reser.value(2).toInt(),
                noE = reser.value(3).toInt(),
                idU = reser.value(4).toInt();
            QDate fech = reser.value(5).toDate();
            QTime hLl = reser.value(6).toTime(),
                  hSa = reser.value(7).toTime(),
                  hEnR = reser.value(8).toTime(),
                  hSalR = reser.value(9).toTime();
            bool over = reser.value(10).toBool();
            reservaciones fecha(idRu, idT, idP, noE, idU, fech, hLl, hSa, over);
            agenda.append(fecha);
        }
    }
    dbconexion.close();
}
void Estacionamiento::setpermiso(int per){
    permiso=per;
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

    QAbstractButton * btnvale = sinespacio.addButton("Vale", QMessageBox::YesRole);
    QAbstractButton * btnbucar = sinespacio.addButton("Buscar nuevo lugar", QMessageBox::NoRole);


    QTime horaAct = QTime::currentTime();
    QTime Prueba(horaAct.hour(),horaAct.minute());
    QDate diaAct = QDate::currentDate();

    bool encontrado = true;

    int numCliente= ui->txtNoCliente->text().toInt();
    QSqlQuery sesionCliente;
    dbconexion.open();
    sesionCliente.prepare("Select idUsuario FROM cliente where IdUsuario = :noC;");
    sesionCliente.bindValue(":noC",numCliente);
    sesionCliente.exec();
    while(sesionCliente.next()){
        if(sesionCliente.value(0).toInt() == numCliente){
            for(int i=0; i<agenda.length(); i++){
                qDebug() << "No. Cliente line edit: " << numCliente;
                qDebug() << "No. CLiente obtenido agenda: " << agenda[i].idUsuario;
                if(numCliente == 1003){
                    qDebug() << "Primera condicion";
                    if(agenda[i].fecha == diaAct){
                        qDebug() << "Segunda condicion";
                        if( Prueba == agenda[i].horallegada || Prueba <= agenda[i].horallegada.addSecs(900)){
                            qDebug()<< "Es en overbook?" << agenda[i].oB;
                            if(agenda[i].oB == true){
                                QSqlQuery buscaLugar;
                                buscaLugar.exec("SELECT NoEspacio, Estado FROM Espacio WHERE NoEspacio > 15;");
                                while(buscaLugar.next()) {
                                    qDebug() << "Estado del lugar: " << buscaLugar.value(1).toString();
                                    if(buscaLugar.value(1).toString() == "Libre"){
                                        qDebug() << "Lugar libre encontrado";
                                        QMessageBox foundIt;
                                        foundIt.setIcon(QMessageBox::Information);
                                        foundIt.setText("Se le ha asignado el lugar: " + QString::number(buscaLugar.value(0).toInt()));
                                        foundIt.setWindowTitle("Lugar encontrado");
                                        QAbstractButton * encontradito = foundIt.addButton("Aceptar", QMessageBox::AcceptRole);
                                        QSqlQuery reAsignacion;
                                        reAsignacion.prepare("UPDATE Reservacionunica SET NoEspacio = :noEsp, Overbooking = false WHERE idUsuario = :idU");
                                        reAsignacion.bindValue(":noEsp", buscaLugar.value(0).toInt());
                                        reAsignacion.bindValue(":idU", agenda[i].idUsuario);
                                        if(reAsignacion.exec()){
                                            qDebug() << "Lugar re asignado";
                                            foundIt.exec();
                                            if(foundIt.clickedButton() == encontradito){
                                                encontrado = true;
                                                break;
                                            }
                                        }

                                    }else{
                                        encontrado = false;
                                    }
                                }

                                if(encontrado == false){
                                    QMessageBox notFound;
                                    notFound.setText("Actualmente no se encuntra ningún lugar disponible para ser reasignado");
                                    QAbstractButton * noEn = notFound.addButton("Acptar", QMessageBox::AcceptRole);
                                    notFound.setIcon(QMessageBox::Information);
                                    notFound.exec();
                                    break;
                                }
                            }
                            QSqlQuery LugarOcupado;
                            LugarOcupado.prepare("SELECT ESPACIO.ESTADO FROM ESPACIO INNER JOIN RESERVACIONUNICA ON ESPACIO.NoEspacio = RESERVACIONUNICA.NoEspacio where RESERVACIONUNICA.IdUsuario=:noC;");
                            LugarOcupado.bindValue(":noC",numCliente);
                            LugarOcupado.exec();
                            LugarOcupado.next();
                            QString result=LugarOcupado.value(0).toString();
                            QSqlQuery hora;

                            hora.prepare("Select HoraEntradaReal from reservacionunica where idUsuario=:noC");
                            hora.bindValue(":noC",numCliente);
                            hora.exec();
                            hora.next();

                            QString Hora= hora.value(0).toString();
                            if(Hora==""){
                                permiso=false;
                            }
                            else{
                                permiso=true;
                            }

                            qDebug()<< "la hora es: "<<Hora;
                            qDebug()<<"El lugar está: "<<result;
                            qDebug()<<"El permiso es: "<< permiso;
                            if(result=="Libre" || permiso==true ){ //La primera vez permiso es false
                                Usua ses(sesionCliente.value(0).toInt());
                                Usuario ventana(&permiso,&ses);
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
                                            Usuario ventana(&permiso,&ses);
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
                        Usua sesC(sesionCliente.value(0).toInt());
                        segV = new Lugares(&sesC, this);
                        segV->exec();
                        break;
                    }else if (sinRes.clickedButton() == btnCanc) {
                        break;
                    }
                }
            }
        }
    }
}
