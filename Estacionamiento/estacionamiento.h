#ifndef ESTACIONAMIENTO_H
#define ESTACIONAMIENTO_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <QDebug>
#include <QList>
#include "objetos.h"
#include "lugares.h"


namespace Ui {
class Estacionamiento;
}

class Estacionamiento : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estacionamiento(QWidget *parent = nullptr);
    ~Estacionamiento();
    void setpermiso(int);
    QSqlDatabase dbconexion;
    bool permiso;


private slots:
    void on_btnIngresar_clicked();

    void on_btnAcceder_clicked();

    void on_accederEst_clicked();

private:
    Ui::Estacionamiento *ui;
    QList<lugares> espacios;
    QList<reservaciones> agenda;
    Lugares *segV;
};

#endif // ESTACIONAMIENTO_H
