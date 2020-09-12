#ifndef ESTACIONAMIENTO_H
#define ESTACIONAMIENTO_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <QDebug>
#include "administrador.h"

namespace Ui {
class Estacionamiento;
}

class Estacionamiento : public QMainWindow
{
    Q_OBJECT

public:
    explicit Estacionamiento(QWidget *parent = nullptr);
    ~Estacionamiento();
    QSqlDatabase dbconexion;

private slots:
    void on_btnIngresar_clicked();

    void on_btnAcceder_clicked();

private:
    Ui::Estacionamiento *ui;
};

#endif // ESTACIONAMIENTO_H
